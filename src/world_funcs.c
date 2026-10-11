#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

ZEND_FUNCTION(b2World_IsValid)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(id_zv, BOX2D_ID_WORLD, 1);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId id_c;
	if (box2d_bind_read(id_zv, &id_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = id_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_WORLD_IS_VALID);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2World_IsValid(id_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(box2d_result);
}


ZEND_FUNCTION(b2World_EnableSleeping)
{
	zval *worldId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_EnableSleeping(worldId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_IsSleepingEnabled)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2World_IsSleepingEnabled(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(box2d_result);
}


ZEND_FUNCTION(b2World_EnableContinuous)
{
	zval *worldId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_EnableContinuous(worldId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_IsContinuousEnabled)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2World_IsContinuousEnabled(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(box2d_result);
}


ZEND_FUNCTION(b2World_SetRestitutionThreshold)
{
	zval *worldId_zv;
	double value_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_DOUBLE(value_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_SetRestitutionThreshold(worldId_c, (float) value_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_GetRestitutionThreshold)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2World_GetRestitutionThreshold(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(box2d_result);
}


ZEND_FUNCTION(b2World_SetHitEventThreshold)
{
	zval *worldId_zv;
	double value_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_DOUBLE(value_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_SetHitEventThreshold(worldId_c, (float) value_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_GetHitEventThreshold)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2World_GetHitEventThreshold(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(box2d_result);
}


ZEND_FUNCTION(b2World_SetGravity)
{
	zval *worldId_zv;
	zval *gravity_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(gravity_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 gravity_c;
	if (box2d_bind_read(gravity_zv, &gravity_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_SetGravity(worldId_c, gravity_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_GetGravity)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2World_GetGravity(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Vec2_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_Explode)
{
	zval *worldId_zv;
	zval *explosionDef_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(explosionDef_zv, box2d_ce_b2ExplosionDef)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ExplosionDef explosionDef_c;
	if (box2d_bind_read(explosionDef_zv, &explosionDef_c, box2d_from_slot_b2ExplosionDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_Explode(worldId_c, &explosionDef_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_SetContactTuning)
{
	zval *worldId_zv;
	double hertz_d;
	double dampingRatio_d;
	double pushSpeed_d;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_DOUBLE(hertz_d)
		Z_PARAM_DOUBLE(dampingRatio_d)
		Z_PARAM_DOUBLE(pushSpeed_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_SetContactTuning(worldId_c, (float) hertz_d, (float) dampingRatio_d, (float) pushSpeed_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_SetMaximumLinearSpeed)
{
	zval *worldId_zv;
	double maximumLinearSpeed_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_DOUBLE(maximumLinearSpeed_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_SetMaximumLinearSpeed(worldId_c, (float) maximumLinearSpeed_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_GetMaximumLinearSpeed)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2World_GetMaximumLinearSpeed(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(box2d_result);
}


ZEND_FUNCTION(b2World_EnableWarmStarting)
{
	zval *worldId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_EnableWarmStarting(worldId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_IsWarmStartingEnabled)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2World_IsWarmStartingEnabled(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(box2d_result);
}


ZEND_FUNCTION(b2World_GetAwakeBodyCount)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2World_GetAwakeBodyCount(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2World_GetProfile)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Profile box2d_result = b2World_GetProfile(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Profile_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_GetCounters)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Counters box2d_result = b2World_GetCounters(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Counters_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_SetUserData)
{
	zval *worldId_zv;
	zend_long userData_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_LONG(userData_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_SetUserData(worldId_c, (void *) (uintptr_t) (uint64_t) userData_l);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_GetUserData)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_WORLD_GET_USER_DATA);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	void *box2d_result = b2World_GetUserData(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) (uintptr_t) box2d_result);
}


ZEND_FUNCTION(b2World_DumpMemoryStats)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_DumpMemoryStats(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_RebuildStaticTree)
{
	zval *worldId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_RebuildStaticTree(worldId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2World_EnableSpeculative)
{
	zval *worldId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(worldId_zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WorldId worldId_c;
	if (box2d_bind_read(worldId_zv, &worldId_c, box2d_from_slot_b2WorldId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = worldId_c;
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2World_EnableSpeculative(worldId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

