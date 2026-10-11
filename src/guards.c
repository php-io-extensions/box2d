#include "runtime.h"

#include "classes.h"
#include "convert.h"

#include "zend_exceptions.h"

#include <string.h>

_Thread_local box2d_world_ctx *box2d_step_world;
_Thread_local box2d_world_ctx *box2d_pool_world;

static box2d_world_ctx *box2d_world_find_index(uint16_t index1);

static void box2d_zval_clear(zval *zv)
{
	if (Z_TYPE_P(zv) != IS_UNDEF) {
		zval_ptr_dtor(zv);
		ZVAL_UNDEF(zv);
	}
}

void box2d_world_release_callbacks(box2d_world_ctx *ctx)
{
	box2d_zval_clear(&ctx->friction);
	box2d_zval_clear(&ctx->restitution);
	box2d_zval_clear(&ctx->custom_filter);
	box2d_zval_clear(&ctx->custom_filter_context);
	box2d_zval_clear(&ctx->pre_solve);
	box2d_zval_clear(&ctx->pre_solve_context);
}

box2d_world_ctx *box2d_world_push(b2WorldId world)
{
	box2d_world_ctx *previous = box2d_step_world;
	box2d_world_ctx *ctx = box2d_world_find_index(world.index1);
	if (ctx != NULL && ctx->id.generation == world.generation) {
		box2d_step_world = ctx;
	}
	return previous;
}

void box2d_world_pop(box2d_world_ctx *previous)
{
	box2d_step_world = previous;
}

box2d_world_ctx *box2d_world_lookup(b2WorldId world)
{
	box2d_world_ctx *ctx = box2d_world_find_index(world.index1);
	if (ctx == NULL || ctx->id.generation != world.generation) {
		return NULL;
	}
	return ctx;
}

static const char *box2d_id_class(int kind)
{
	switch (kind) {
	case BOX2D_ID_WORLD:
		return "b2WorldId";
	case BOX2D_ID_BODY:
		return "b2BodyId";
	case BOX2D_ID_SHAPE:
		return "b2ShapeId";
	case BOX2D_ID_CHAIN:
		return "b2ChainId";
	case BOX2D_ID_JOINT:
		return "b2JointId";
	default:
		return "id";
	}
}

static const char *box2d_id_noun(int kind)
{
	switch (kind) {
	case BOX2D_ID_WORLD:
		return "world";
	case BOX2D_ID_BODY:
		return "body";
	case BOX2D_ID_SHAPE:
		return "shape";
	case BOX2D_ID_CHAIN:
		return "chain";
	case BOX2D_ID_JOINT:
		return "joint";
	default:
		return "id";
	}
}

static box2d_world_ctx *box2d_world_find_index(uint16_t index1)
{
	for (box2d_world_ctx *ctx = BOX2D_G(worlds); ctx != NULL; ctx = ctx->next) {
		if (ctx->id.index1 == index1) {
			return ctx;
		}
	}
	return NULL;
}

void box2d_assert_check(void)
{
	if (!box2d_assert_tls.pending) {
		return;
	}

	const char *condition = box2d_assert_tls.condition != NULL ? box2d_assert_tls.condition : "";
	const char *file = box2d_assert_tls.file != NULL ? box2d_assert_tls.file : "";
	int line = box2d_assert_tls.line;
	box2d_assert_tls.pending = false;
	box2d_assert_tls.condition = NULL;
	box2d_assert_tls.file = NULL;
	box2d_assert_tls.line = 0;

	zend_throw_exception_ex(box2d_ce_b2AssertionError, 0, "%s at %s:%d", condition, file, line);
}

void box2d_guard_id(zval *id, int kind, int skip_live)
{
	box2d_frame frame;
	bool live = false;
	uint16_t world_index = 0;

	box2d_frame_init(&frame);

	switch (kind) {
	case BOX2D_ID_WORLD: {
		b2WorldId parsed;
		if (box2d_b2WorldId_from_zval(id, &parsed, &frame) == FAILURE) {
			box2d_frame_free(&frame);
			return;
		}
		live = b2World_IsValid(parsed);
		world_index = parsed.index1;
		break;
	}
	case BOX2D_ID_BODY: {
		b2BodyId parsed;
		if (box2d_b2BodyId_from_zval(id, &parsed, &frame) == FAILURE) {
			box2d_frame_free(&frame);
			return;
		}
		live = b2Body_IsValid(parsed);
		world_index = box2d_world_index_from_world0(parsed.world0);
		break;
	}
	case BOX2D_ID_SHAPE: {
		b2ShapeId parsed;
		if (box2d_b2ShapeId_from_zval(id, &parsed, &frame) == FAILURE) {
			box2d_frame_free(&frame);
			return;
		}
		live = b2Shape_IsValid(parsed);
		world_index = box2d_world_index_from_world0(parsed.world0);
		break;
	}
	case BOX2D_ID_CHAIN: {
		b2ChainId parsed;
		if (box2d_b2ChainId_from_zval(id, &parsed, &frame) == FAILURE) {
			box2d_frame_free(&frame);
			return;
		}
		live = b2Chain_IsValid(parsed);
		world_index = box2d_world_index_from_world0(parsed.world0);
		break;
	}
	case BOX2D_ID_JOINT: {
		b2JointId parsed;
		if (box2d_b2JointId_from_zval(id, &parsed, &frame) == FAILURE) {
			box2d_frame_free(&frame);
			return;
		}
		live = b2Joint_IsValid(parsed);
		world_index = box2d_world_index_from_world0(parsed.world0);
		break;
	}
	default:
		zend_value_error("unknown id kind");
		box2d_frame_free(&frame);
		return;
	}

	box2d_frame_free(&frame);

	if (!live) {
		if (skip_live) {
			return;
		}
		zend_value_error("%s is not a live %s", box2d_id_class(kind), box2d_id_noun(kind));
		return;
	}

	box2d_world_ctx *ctx = box2d_world_find_index(world_index);
	if (ctx == NULL || !pthread_equal(ctx->owner, pthread_self())) {
		zend_throw_error(NULL, "world belongs to another thread");
	}
}

static bool box2d_step_op_allowed(int op)
{
	switch (op) {
	case BOX2D_OP_WORLD_IS_VALID:
	case BOX2D_OP_BODY_IS_VALID:
	case BOX2D_OP_SHAPE_IS_VALID:
	case BOX2D_OP_CHAIN_IS_VALID:
	case BOX2D_OP_JOINT_IS_VALID:
	case BOX2D_OP_SHAPE_GET_BODY:
	case BOX2D_OP_SHAPE_GET_WORLD:
	case BOX2D_OP_SHAPE_GET_TYPE:
	case BOX2D_OP_SHAPE_IS_SENSOR:
	case BOX2D_OP_SHAPE_GET_USER_DATA:
	case BOX2D_OP_SHAPE_GET_FILTER:
	case BOX2D_OP_SHAPE_GET_DENSITY:
	case BOX2D_OP_SHAPE_GET_FRICTION:
	case BOX2D_OP_SHAPE_GET_RESTITUTION:
	case BOX2D_OP_SHAPE_GET_MATERIAL:
	case BOX2D_OP_SHAPE_GET_SURFACE_MATERIAL:
	case BOX2D_OP_SHAPE_GET_PARENT_CHAIN:
	case BOX2D_OP_BODY_GET_TYPE:
	case BOX2D_OP_BODY_GET_USER_DATA:
	case BOX2D_OP_BODY_GET_NAME:
	case BOX2D_OP_BODY_GET_WORLD:
	case BOX2D_OP_WORLD_GET_USER_DATA:
		return true;
	default:
		return false;
	}
}

void box2d_guard_step(b2WorldId world, int op)
{
	box2d_world_ctx *ctx = box2d_world_find_index(world.index1);
	if (ctx == NULL || !ctx->stepping) {
		return;
	}
	if (ctx->id.generation != world.generation) {
		return;
	}
	if (!box2d_step_op_allowed(op)) {
		zend_throw_error(NULL, "world is stepping");
	}
}

b2WorldId box2d_tracked_world(uint16_t index1)
{
	box2d_world_ctx *ctx = box2d_world_find_index(index1);
	if (ctx == NULL) {
		b2WorldId null_id = {0, 0};
		return null_id;
	}
	return ctx->id;
}

box2d_world_ctx *box2d_world_alloc(void)
{
	box2d_world_ctx *ctx = ecalloc(1, sizeof(box2d_world_ctx));
	ZVAL_UNDEF(&ctx->friction);
	ZVAL_UNDEF(&ctx->restitution);
	ZVAL_UNDEF(&ctx->custom_filter);
	ZVAL_UNDEF(&ctx->custom_filter_context);
	ZVAL_UNDEF(&ctx->pre_solve);
	ZVAL_UNDEF(&ctx->pre_solve_context);
	return ctx;
}

void box2d_world_attach(box2d_world_ctx *ctx, b2WorldId id)
{
	ctx->id = id;
	ctx->stepping = false;
	ctx->owner = pthread_self();
	ctx->next = BOX2D_G(worlds);
	BOX2D_G(worlds) = ctx;
}

box2d_world_ctx *box2d_world_track(b2WorldId id)
{
	box2d_world_ctx *ctx = box2d_world_alloc();
	box2d_world_attach(ctx, id);
	return ctx;
}

void box2d_world_untrack(b2WorldId id)
{
	box2d_world_ctx **link = &BOX2D_G(worlds);
	while (*link != NULL) {
		box2d_world_ctx *ctx = *link;
		if (ctx->id.index1 == id.index1 && ctx->id.generation == id.generation) {
			*link = ctx->next;
			box2d_pool_stop(ctx);
			box2d_world_release_callbacks(ctx);
			efree(ctx);
			return;
		}
		link = &ctx->next;
	}
}

void box2d_worlds_shutdown(void)
{
	box2d_world_ctx *ctx = BOX2D_G(worlds);
	BOX2D_G(worlds) = NULL;
	while (ctx != NULL) {
		box2d_world_ctx *next = ctx->next;
		box2d_pool_stop(ctx);
		box2d_world_table_lock();
		if (b2World_IsValid(ctx->id)) {
			b2DestroyWorld(ctx->id);
		}
		box2d_world_table_unlock();
		box2d_world_release_callbacks(ctx);
		efree(ctx);
		ctx = next;
	}
}

void box2d_world_set_stepping(b2WorldId world, bool stepping)
{
	box2d_world_ctx *ctx = box2d_world_find_index(world.index1);
	if (ctx == NULL || ctx->id.generation != world.generation) {
		return;
	}
	ctx->stepping = stepping;
}

void box2d_guard_cookie(zval *def)
{
	if (Z_TYPE_P(def) != IS_OBJECT) {
		zend_type_error("definition must be an object");
		return;
	}

	zend_object *object = Z_OBJ_P(def);
	zval *cookie = zend_read_property(object->ce, object, ZEND_STRL("internalValue"), 0, NULL);
	if (cookie == NULL || Z_TYPE_P(cookie) != IS_LONG || Z_LVAL_P(cookie) != BOX2D_SECRET_COOKIE) {
		zend_value_error("%s internalValue is not the Box2D definition cookie", ZSTR_VAL(object->ce->name));
	}
}

void box2d_guard_count(zend_long count, zend_long length, const char *what)
{
	if (count < 0 || count > length) {
		zend_value_error("%s count %ld is outside 0..%ld", what, (long)count, (long)length);
	}
}

void box2d_guard_joint_bodies(zval *def)
{
	if (Z_TYPE_P(def) != IS_OBJECT) {
		zend_type_error("joint definition must be an object");
		return;
	}

	zend_object *object = Z_OBJ_P(def);
	zval *body_a = zend_read_property(object->ce, object, ZEND_STRL("bodyIdA"), 0, NULL);
	zval *body_b = zend_read_property(object->ce, object, ZEND_STRL("bodyIdB"), 0, NULL);
	if (body_a == NULL || body_b == NULL) {
		zend_value_error("%s is missing a body id", ZSTR_VAL(object->ce->name));
		return;
	}
	ZVAL_DEREF(body_a);
	ZVAL_DEREF(body_b);

	box2d_guard_id(body_a, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		return;
	}
	box2d_guard_id(body_b, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		return;
	}

	b2BodyId id_a;
	b2BodyId id_b;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2BodyId_from_zval(body_a, &id_a, &frame) == FAILURE
		|| box2d_b2BodyId_from_zval(body_b, &id_b, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);

	box2d_guard_step(box2d_tracked_world(box2d_world_index_from_world0(id_a.world0)), BOX2D_OP_NONE);
	if (EG(exception)) {
		return;
	}
	box2d_guard_step(box2d_tracked_world(box2d_world_index_from_world0(id_b.world0)), BOX2D_OP_NONE);
}

const char *box2d_body_name(zval *name)
{
	static _Thread_local char buffer[32];

	if (Z_TYPE_P(name) == IS_NULL) {
		return NULL;
	}
	if (Z_TYPE_P(name) != IS_STRING) {
		zend_type_error("name must be a string or null");
		return NULL;
	}
	if (Z_STRLEN_P(name) > 31) {
		zend_value_error("body name is longer than 31 characters");
		return NULL;
	}

	memset(buffer, 0, sizeof(buffer));
	if (Z_STRLEN_P(name) > 0) {
		memcpy(buffer, Z_STRVAL_P(name), Z_STRLEN_P(name));
	}
	return buffer;
}
