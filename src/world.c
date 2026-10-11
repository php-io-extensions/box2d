#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

#include "../stubs/box2d_arginfo.h"

static pthread_mutex_t box2d_world_table_mu = PTHREAD_MUTEX_INITIALIZER;

void box2d_world_table_lock(void)
{
	pthread_mutex_lock(&box2d_world_table_mu);
}

void box2d_world_table_unlock(void)
{
	pthread_mutex_unlock(&box2d_world_table_mu);
}

static void box2d_assign_closure(zval *slot, zval *incoming)
{
	if (Z_TYPE_P(slot) != IS_UNDEF) {
		zval_ptr_dtor(slot);
		ZVAL_UNDEF(slot);
	}
	if (incoming != NULL) {
		ZVAL_COPY(slot, incoming);
	}
}

static bool box2d_closure_set(zval *value)
{
	return value != NULL && Z_TYPE_P(value) == IS_OBJECT;
}

ZEND_FUNCTION(b2CreateWorld)
{
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2WorldDef)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2WorldDef def;
	if (box2d_bind_read(def_zv, &def, box2d_from_slot_b2WorldDef) == FAILURE) {
		RETURN_THROWS();
	}

	zval *friction = zend_read_property(Z_OBJCE_P(def_zv), Z_OBJ_P(def_zv), ZEND_STRL("frictionCallback"), 0, NULL);
	zval *restitution = zend_read_property(Z_OBJCE_P(def_zv), Z_OBJ_P(def_zv), ZEND_STRL("restitutionCallback"), 0, NULL);
	if (friction != NULL) {
		ZVAL_DEREF(friction);
	}
	if (restitution != NULL) {
		ZVAL_DEREF(restitution);
	}
	bool has_friction = box2d_closure_set(friction);
	bool has_restitution = box2d_closure_set(restitution);
	def.frictionCallback = has_friction ? box2d_friction_trampoline : NULL;
	def.restitutionCallback = has_restitution ? box2d_restitution_trampoline : NULL;

	zval *worker_zv = zend_read_property(Z_OBJCE_P(def_zv), Z_OBJ_P(def_zv), ZEND_STRL("workerCount"), 0, NULL);
	zend_long requested_workers = 0;
	if (worker_zv != NULL) {
		ZVAL_DEREF(worker_zv);
		if (Z_TYPE_P(worker_zv) == IS_LONG) {
			requested_workers = Z_LVAL_P(worker_zv);
		}
	}
	if (requested_workers < 0) {
		zend_value_error("workerCount %ld is below 0", (long) requested_workers);
		RETURN_THROWS();
	}

	box2d_world_ctx *prepared = NULL;
	def.enqueueTask = NULL;
	def.finishTask = NULL;
	def.userTaskContext = NULL;
	if (requested_workers > 1) {
		int pool = requested_workers > BOX2D_POOL_LIMIT ? BOX2D_POOL_LIMIT : (int) requested_workers;
		prepared = box2d_world_alloc();
		if (box2d_pool_start(prepared, pool) == FAILURE) {
			efree(prepared);
			zend_throw_error(NULL, "worker pool did not start");
			RETURN_THROWS();
		}
		def.enqueueTask = box2d_enqueue_task;
		def.finishTask = box2d_finish_task;
		def.userTaskContext = prepared;
		def.workerCount = (int) requested_workers;
	}

	box2d_world_table_lock();
	b2WorldId id = b2CreateWorld(&def);
	if (box2d_assert_tls.pending) {
		if (b2World_IsValid(id)) {
			b2DestroyWorld(id);
		}
		box2d_world_table_unlock();
		if (prepared != NULL) {
			box2d_pool_stop(prepared);
			efree(prepared);
		}
		box2d_assert_check();
		RETURN_THROWS();
	}
	box2d_world_table_unlock();

	if (!b2World_IsValid(id)) {
		if (prepared != NULL) {
			box2d_pool_stop(prepared);
			efree(prepared);
		}
		zend_value_error("b2CreateWorld did not return a live world");
		RETURN_THROWS();
	}

	box2d_world_ctx *ctx;
	if (prepared != NULL) {
		box2d_world_attach(prepared, id);
		ctx = prepared;
	} else {
		ctx = box2d_world_track(id);
	}
	if (has_friction) {
		ZVAL_COPY(&ctx->friction, friction);
	}
	if (has_restitution) {
		ZVAL_COPY(&ctx->restitution, restitution);
	}

	if (box2d_b2WorldId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DestroyWorld)
{
	zval *world_id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(world_id, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2WorldId id;
	if (box2d_bind_read(world_id, &id, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_guard_step(id, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	box2d_world_ctx *live = box2d_world_lookup(id);
	if (live != NULL) {
		box2d_pool_stop(live);
	}

	box2d_world_table_lock();
	b2DestroyWorld(id);
	bool asserted = box2d_assert_tls.pending;
	box2d_world_table_unlock();
	if (!asserted) {
		box2d_world_untrack(id);
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_Step)
{
	zval *world_id;
	double time_step;
	zend_long sub_step_count;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_DOUBLE(time_step)
		Z_PARAM_LONG(sub_step_count)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(world_id, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2WorldId id;
	if (box2d_bind_read(world_id, &id, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_guard_step(id, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	box2d_world_ctx *step_ctx = box2d_world_lookup(id);
	if (step_ctx != NULL && step_ctx->pool_dead) {
		zend_throw_error(NULL, "world's worker pool did not survive fork");
		RETURN_THROWS();
	}

	int sub_steps;
	if (box2d_bind_i32(sub_step_count, &sub_steps, "subStepCount") == FAILURE) {
		RETURN_THROWS();
	}

	box2d_world_ctx *previous = box2d_world_push(id);
	box2d_world_set_stepping(id, true);
	b2World_Step(id, (float) time_step, sub_steps);
	box2d_world_set_stepping(id, false);
	box2d_world_pop(previous);
	box2d_pool_assert_check(step_ctx);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

static void box2d_set_material_callback(b2WorldId id, zval *callback, zval *slot, b2FrictionCallback *trampoline, bool restitution)
{
	box2d_world_ctx *ctx = box2d_world_lookup(id);
	if (ctx == NULL) {
		zend_throw_error(NULL, "world belongs to another thread");
		return;
	}

	box2d_world_ctx *previous = box2d_world_push(id);
	if (callback == NULL) {
		box2d_assign_closure(slot, NULL);
		if (restitution) {
			b2World_SetRestitutionCallback(id, NULL);
		} else {
			b2World_SetFrictionCallback(id, NULL);
		}
	} else {
		box2d_assign_closure(slot, callback);
		if (restitution) {
			b2World_SetRestitutionCallback(id, (b2RestitutionCallback *) trampoline);
		} else {
			b2World_SetFrictionCallback(id, trampoline);
		}
	}
	box2d_world_pop(previous);
	box2d_assert_check();
}

ZEND_FUNCTION(b2World_SetFrictionCallback)
{
	zval *world_id;
	zval *callback;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(world_id, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2WorldId id;
	if (box2d_bind_read(world_id, &id, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_guard_step(id, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	box2d_world_ctx *ctx = box2d_world_lookup(id);
	if (ctx == NULL) {
		zend_throw_error(NULL, "world belongs to another thread");
		RETURN_THROWS();
	}
	box2d_set_material_callback(id, callback, &ctx->friction, box2d_friction_trampoline, false);
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_SetRestitutionCallback)
{
	zval *world_id;
	zval *callback;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(world_id, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2WorldId id;
	if (box2d_bind_read(world_id, &id, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_guard_step(id, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	box2d_world_ctx *ctx = box2d_world_lookup(id);
	if (ctx == NULL) {
		zend_throw_error(NULL, "world belongs to another thread");
		RETURN_THROWS();
	}
	box2d_set_material_callback(id, callback, &ctx->restitution, (b2FrictionCallback *) box2d_restitution_trampoline, true);
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

void box2d_register_api(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
}
