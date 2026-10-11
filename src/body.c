#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

ZEND_FUNCTION(b2CreateBody)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2BodyDef)
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
	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2BodyDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2BodyId box2d_result = b2CreateBody(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2BodyId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DestroyBody)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DestroyBody(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_IsValid)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(id_zv, BOX2D_ID_BODY, 1);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId id_c;
	if (box2d_bind_read(id_zv, &id_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(id_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_BODY_IS_VALID);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Body_IsValid(id_c);
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


ZEND_FUNCTION(b2Body_GetType)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_BODY_GET_TYPE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetType(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetType)
{
	zval *bodyId_zv;
	zend_long type_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_LONG(type_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	int type_i;
	if (box2d_bind_i32(type_l, &type_i, "type") == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetType(bodyId_c, type_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_SetUserData)
{
	zval *bodyId_zv;
	zend_long userData_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_LONG(userData_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetUserData(bodyId_c, (void *) (uintptr_t) (uint64_t) userData_l);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetUserData)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_BODY_GET_USER_DATA);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	void *box2d_result = b2Body_GetUserData(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetPosition)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetPosition(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetRotation)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Rot box2d_result = b2Body_GetRotation(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Rot_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetTransform)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Transform box2d_result = b2Body_GetTransform(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Transform_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_SetTransform)
{
	zval *bodyId_zv;
	zval *position_zv;
	zval *rotation_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(position_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 position_c;
	if (box2d_bind_read(position_zv, &position_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	b2Rot rotation_c;
	if (box2d_bind_read(rotation_zv, &rotation_c, box2d_from_slot_b2Rot) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetTransform(bodyId_c, position_c, rotation_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetLocalPoint)
{
	zval *bodyId_zv;
	zval *worldPoint_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(worldPoint_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 worldPoint_c;
	if (box2d_bind_read(worldPoint_zv, &worldPoint_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetLocalPoint(bodyId_c, worldPoint_c);
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


ZEND_FUNCTION(b2Body_GetWorldPoint)
{
	zval *bodyId_zv;
	zval *localPoint_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localPoint_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 localPoint_c;
	if (box2d_bind_read(localPoint_zv, &localPoint_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetWorldPoint(bodyId_c, localPoint_c);
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


ZEND_FUNCTION(b2Body_GetLocalVector)
{
	zval *bodyId_zv;
	zval *worldVector_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(worldVector_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 worldVector_c;
	if (box2d_bind_read(worldVector_zv, &worldVector_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetLocalVector(bodyId_c, worldVector_c);
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


ZEND_FUNCTION(b2Body_GetWorldVector)
{
	zval *bodyId_zv;
	zval *localVector_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localVector_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 localVector_c;
	if (box2d_bind_read(localVector_zv, &localVector_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetWorldVector(bodyId_c, localVector_c);
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


ZEND_FUNCTION(b2Body_GetLinearVelocity)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetLinearVelocity(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetAngularVelocity)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetAngularVelocity(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetLinearVelocity)
{
	zval *bodyId_zv;
	zval *linearVelocity_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(linearVelocity_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 linearVelocity_c;
	if (box2d_bind_read(linearVelocity_zv, &linearVelocity_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetLinearVelocity(bodyId_c, linearVelocity_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_SetAngularVelocity)
{
	zval *bodyId_zv;
	double angularVelocity_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(angularVelocity_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetAngularVelocity(bodyId_c, (float) angularVelocity_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_SetTargetTransform)
{
	zval *bodyId_zv;
	zval *target_zv;
	double timeStep_d;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(target_zv, box2d_ce_b2Transform)
		Z_PARAM_DOUBLE(timeStep_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Transform target_c;
	if (box2d_bind_read(target_zv, &target_c, box2d_from_slot_b2Transform) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetTargetTransform(bodyId_c, target_c, (float) timeStep_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetLocalPointVelocity)
{
	zval *bodyId_zv;
	zval *localPoint_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localPoint_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 localPoint_c;
	if (box2d_bind_read(localPoint_zv, &localPoint_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetLocalPointVelocity(bodyId_c, localPoint_c);
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


ZEND_FUNCTION(b2Body_GetWorldPointVelocity)
{
	zval *bodyId_zv;
	zval *worldPoint_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(worldPoint_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 worldPoint_c;
	if (box2d_bind_read(worldPoint_zv, &worldPoint_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetWorldPointVelocity(bodyId_c, worldPoint_c);
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


ZEND_FUNCTION(b2Body_ApplyForce)
{
	zval *bodyId_zv;
	zval *force_zv;
	zval *point_zv;
	bool wake_b;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(force_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
		Z_PARAM_BOOL(wake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 force_c;
	if (box2d_bind_read(force_zv, &force_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	b2Vec2 point_c;
	if (box2d_bind_read(point_zv, &point_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyForce(bodyId_c, force_c, point_c, wake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_ApplyForceToCenter)
{
	zval *bodyId_zv;
	zval *force_zv;
	bool wake_b;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(force_zv, box2d_ce_b2Vec2)
		Z_PARAM_BOOL(wake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 force_c;
	if (box2d_bind_read(force_zv, &force_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyForceToCenter(bodyId_c, force_c, wake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_ApplyTorque)
{
	zval *bodyId_zv;
	double torque_d;
	bool wake_b;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(torque_d)
		Z_PARAM_BOOL(wake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyTorque(bodyId_c, (float) torque_d, wake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_ApplyLinearImpulse)
{
	zval *bodyId_zv;
	zval *impulse_zv;
	zval *point_zv;
	bool wake_b;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(impulse_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
		Z_PARAM_BOOL(wake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 impulse_c;
	if (box2d_bind_read(impulse_zv, &impulse_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	b2Vec2 point_c;
	if (box2d_bind_read(point_zv, &point_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyLinearImpulse(bodyId_c, impulse_c, point_c, wake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_ApplyLinearImpulseToCenter)
{
	zval *bodyId_zv;
	zval *impulse_zv;
	bool wake_b;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(impulse_zv, box2d_ce_b2Vec2)
		Z_PARAM_BOOL(wake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 impulse_c;
	if (box2d_bind_read(impulse_zv, &impulse_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyLinearImpulseToCenter(bodyId_c, impulse_c, wake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_ApplyAngularImpulse)
{
	zval *bodyId_zv;
	double impulse_d;
	bool wake_b;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(impulse_d)
		Z_PARAM_BOOL(wake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyAngularImpulse(bodyId_c, (float) impulse_d, wake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetMass)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetMass(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetRotationalInertia)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetRotationalInertia(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetLocalCenterOfMass)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetLocalCenterOfMass(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetWorldCenterOfMass)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Body_GetWorldCenterOfMass(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetMassData)
{
	zval *bodyId_zv;
	zval *massData_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(massData_zv, box2d_ce_b2MassData)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2MassData massData_c;
	if (box2d_bind_read(massData_zv, &massData_c, box2d_from_slot_b2MassData) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetMassData(bodyId_c, massData_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetMassData)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MassData box2d_result = b2Body_GetMassData(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2MassData_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_ApplyMassFromShapes)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_ApplyMassFromShapes(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_SetLinearDamping)
{
	zval *bodyId_zv;
	double linearDamping_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(linearDamping_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetLinearDamping(bodyId_c, (float) linearDamping_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetLinearDamping)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetLinearDamping(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetAngularDamping)
{
	zval *bodyId_zv;
	double angularDamping_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(angularDamping_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetAngularDamping(bodyId_c, (float) angularDamping_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetAngularDamping)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetAngularDamping(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetGravityScale)
{
	zval *bodyId_zv;
	double gravityScale_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(gravityScale_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetGravityScale(bodyId_c, (float) gravityScale_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetGravityScale)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetGravityScale(bodyId_c);
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


ZEND_FUNCTION(b2Body_IsAwake)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Body_IsAwake(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetAwake)
{
	zval *bodyId_zv;
	bool awake_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_BOOL(awake_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetAwake(bodyId_c, awake_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_EnableSleep)
{
	zval *bodyId_zv;
	bool enableSleep_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_BOOL(enableSleep_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_EnableSleep(bodyId_c, enableSleep_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_IsSleepEnabled)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Body_IsSleepEnabled(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetSleepThreshold)
{
	zval *bodyId_zv;
	double sleepThreshold_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_DOUBLE(sleepThreshold_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetSleepThreshold(bodyId_c, (float) sleepThreshold_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetSleepThreshold)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Body_GetSleepThreshold(bodyId_c);
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


ZEND_FUNCTION(b2Body_IsEnabled)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Body_IsEnabled(bodyId_c);
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


ZEND_FUNCTION(b2Body_Disable)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_Disable(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_Enable)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_Enable(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_SetFixedRotation)
{
	zval *bodyId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetFixedRotation(bodyId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_IsFixedRotation)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Body_IsFixedRotation(bodyId_c);
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


ZEND_FUNCTION(b2Body_SetBullet)
{
	zval *bodyId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_SetBullet(bodyId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_IsBullet)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Body_IsBullet(bodyId_c);
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


ZEND_FUNCTION(b2Body_EnableContactEvents)
{
	zval *bodyId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_EnableContactEvents(bodyId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_EnableHitEvents)
{
	zval *bodyId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Body_EnableHitEvents(bodyId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetWorld)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_BODY_GET_WORLD);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WorldId box2d_result = b2Body_GetWorld(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2WorldId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Body_GetShapeCount)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetShapeCount(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetShapes)
{
	zval *bodyId_zv;
	zval *shapeArray_zv;
	zend_long capacity_l;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_ZVAL(shapeArray_zv)
		Z_PARAM_LONG(capacity_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (capacity_l < 0) {
		zend_value_error("capacity %lld is negative", (long long) capacity_l);
		RETURN_THROWS();
	}
	int capacity_i;
	if (box2d_bind_i32(capacity_l, &capacity_i, "capacity") == FAILURE) {
		RETURN_THROWS();
	}
	b2ShapeId *shapeArray_buf = NULL;
	if (capacity_i > 0) {
		shapeArray_buf = safe_emalloc((size_t) capacity_i, sizeof(b2ShapeId), 0);
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetShapes(bodyId_c, shapeArray_buf, capacity_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		if (shapeArray_buf != NULL) {
			efree(shapeArray_buf);
		}
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		if (shapeArray_buf != NULL) {
			efree(shapeArray_buf);
		}
		RETURN_THROWS();
	}
	if (box2d_result < 0 || box2d_result > capacity_i) {
		if (shapeArray_buf != NULL) {
			efree(shapeArray_buf);
		}
		zend_value_error("capacity %d cannot hold %d results", capacity_i, box2d_result);
		RETURN_THROWS();
	}
	if (box2d_store_list(shapeArray_zv, box2d_result, shapeArray_buf, sizeof(b2ShapeId), box2d_to_slot_b2ShapeId) == FAILURE) {
		if (shapeArray_buf != NULL) {
			efree(shapeArray_buf);
		}
		RETURN_THROWS();
	}
	if (shapeArray_buf != NULL) {
		efree(shapeArray_buf);
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Body_GetJointCount)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetJointCount(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetJoints)
{
	zval *bodyId_zv;
	zval *jointArray_zv;
	zend_long capacity_l;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_ZVAL(jointArray_zv)
		Z_PARAM_LONG(capacity_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (capacity_l < 0) {
		zend_value_error("capacity %lld is negative", (long long) capacity_l);
		RETURN_THROWS();
	}
	int capacity_i;
	if (box2d_bind_i32(capacity_l, &capacity_i, "capacity") == FAILURE) {
		RETURN_THROWS();
	}
	b2JointId *jointArray_buf = NULL;
	if (capacity_i > 0) {
		jointArray_buf = safe_emalloc((size_t) capacity_i, sizeof(b2JointId), 0);
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetJoints(bodyId_c, jointArray_buf, capacity_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		if (jointArray_buf != NULL) {
			efree(jointArray_buf);
		}
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		if (jointArray_buf != NULL) {
			efree(jointArray_buf);
		}
		RETURN_THROWS();
	}
	if (box2d_result < 0 || box2d_result > capacity_i) {
		if (jointArray_buf != NULL) {
			efree(jointArray_buf);
		}
		zend_value_error("capacity %d cannot hold %d results", capacity_i, box2d_result);
		RETURN_THROWS();
	}
	if (box2d_store_list(jointArray_zv, box2d_result, jointArray_buf, sizeof(b2JointId), box2d_to_slot_b2JointId) == FAILURE) {
		if (jointArray_buf != NULL) {
			efree(jointArray_buf);
		}
		RETURN_THROWS();
	}
	if (jointArray_buf != NULL) {
		efree(jointArray_buf);
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Body_GetContactCapacity)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetContactCapacity(bodyId_c);
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


ZEND_FUNCTION(b2Body_GetContactData)
{
	zval *bodyId_zv;
	zval *contactData_zv;
	zend_long capacity_l;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_ZVAL(contactData_zv)
		Z_PARAM_LONG(capacity_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (capacity_l < 0) {
		zend_value_error("capacity %lld is negative", (long long) capacity_l);
		RETURN_THROWS();
	}
	int capacity_i;
	if (box2d_bind_i32(capacity_l, &capacity_i, "capacity") == FAILURE) {
		RETURN_THROWS();
	}
	b2ContactData *contactData_buf = NULL;
	if (capacity_i > 0) {
		contactData_buf = safe_emalloc((size_t) capacity_i, sizeof(b2ContactData), 0);
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Body_GetContactData(bodyId_c, contactData_buf, capacity_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		if (contactData_buf != NULL) {
			efree(contactData_buf);
		}
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		if (contactData_buf != NULL) {
			efree(contactData_buf);
		}
		RETURN_THROWS();
	}
	if (box2d_result < 0 || box2d_result > capacity_i) {
		if (contactData_buf != NULL) {
			efree(contactData_buf);
		}
		zend_value_error("capacity %d cannot hold %d results", capacity_i, box2d_result);
		RETURN_THROWS();
	}
	if (box2d_store_list(contactData_zv, box2d_result, contactData_buf, sizeof(b2ContactData), box2d_to_slot_b2ContactData) == FAILURE) {
		if (contactData_buf != NULL) {
			efree(contactData_buf);
		}
		RETURN_THROWS();
	}
	if (contactData_buf != NULL) {
		efree(contactData_buf);
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Body_ComputeAABB)
{
	zval *bodyId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2AABB box2d_result = b2Body_ComputeAABB(bodyId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2AABB_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

