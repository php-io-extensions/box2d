#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

ZEND_FUNCTION(b2DestroyJoint)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DestroyJoint(jointId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_IsValid)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(id_zv, BOX2D_ID_JOINT, 1);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId id_c;
	if (box2d_bind_read(id_zv, &id_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(id_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_JOINT_IS_VALID);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Joint_IsValid(id_c);
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


ZEND_FUNCTION(b2Joint_GetType)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Joint_GetType(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetBodyA)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2BodyId box2d_result = b2Joint_GetBodyA(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetBodyB)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2BodyId box2d_result = b2Joint_GetBodyB(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetWorld)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WorldId box2d_result = b2Joint_GetWorld(jointId_c);
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


ZEND_FUNCTION(b2Joint_SetLocalAnchorA)
{
	zval *jointId_zv;
	zval *localAnchor_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchor_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 localAnchor_c;
	if (box2d_bind_read(localAnchor_zv, &localAnchor_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetLocalAnchorA(jointId_c, localAnchor_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_GetLocalAnchorA)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Joint_GetLocalAnchorA(jointId_c);
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


ZEND_FUNCTION(b2Joint_SetLocalAnchorB)
{
	zval *jointId_zv;
	zval *localAnchor_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchor_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 localAnchor_c;
	if (box2d_bind_read(localAnchor_zv, &localAnchor_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetLocalAnchorB(jointId_c, localAnchor_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_GetLocalAnchorB)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Joint_GetLocalAnchorB(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetReferenceAngle)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Joint_GetReferenceAngle(jointId_c);
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


ZEND_FUNCTION(b2Joint_SetReferenceAngle)
{
	zval *jointId_zv;
	double angleInRadians_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(angleInRadians_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetReferenceAngle(jointId_c, (float) angleInRadians_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_SetLocalAxisA)
{
	zval *jointId_zv;
	zval *localAxis_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_OBJECT_OF_CLASS(localAxis_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 localAxis_c;
	if (box2d_bind_read(localAxis_zv, &localAxis_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetLocalAxisA(jointId_c, localAxis_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_GetLocalAxisA)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Joint_GetLocalAxisA(jointId_c);
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


ZEND_FUNCTION(b2Joint_SetCollideConnected)
{
	zval *jointId_zv;
	bool shouldCollide_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(shouldCollide_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetCollideConnected(jointId_c, shouldCollide_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_GetCollideConnected)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Joint_GetCollideConnected(jointId_c);
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


ZEND_FUNCTION(b2Joint_SetUserData)
{
	zval *jointId_zv;
	zend_long userData_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_LONG(userData_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetUserData(jointId_c, (void *) (uintptr_t) (uint64_t) userData_l);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_GetUserData)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	void *box2d_result = b2Joint_GetUserData(jointId_c);
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


ZEND_FUNCTION(b2Joint_WakeBodies)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_WakeBodies(jointId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Joint_GetConstraintForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Joint_GetConstraintForce(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetConstraintTorque)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Joint_GetConstraintTorque(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetLinearSeparation)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Joint_GetLinearSeparation(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetAngularSeparation)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Joint_GetAngularSeparation(jointId_c);
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


ZEND_FUNCTION(b2Joint_GetConstraintTuning)
{
	zval *jointId_zv;
	zval *hertz_zv;
	zval *dampingRatio_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_ZVAL(hertz_zv)
		Z_PARAM_ZVAL(dampingRatio_zv)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	float hertz_c = 0.0f;
	float dampingRatio_c = 0.0f;
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_GetConstraintTuning(jointId_c, &hertz_c, &dampingRatio_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_store_double(hertz_zv, (double) hertz_c);
	box2d_store_double(dampingRatio_zv, (double) dampingRatio_c);
}


ZEND_FUNCTION(b2Joint_SetConstraintTuning)
{
	zval *jointId_zv;
	double hertz_d;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Joint_SetConstraintTuning(jointId_c, (float) hertz_d, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2CreateDistanceJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2DistanceJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2DistanceJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2DistanceJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateDistanceJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_SetLength)
{
	zval *jointId_zv;
	double length_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(length_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_SetLength(jointId_c, (float) length_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_GetLength)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetLength(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_EnableSpring)
{
	zval *jointId_zv;
	bool enableSpring_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableSpring_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_EnableSpring(jointId_c, enableSpring_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_IsSpringEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2DistanceJoint_IsSpringEnabled(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_SetSpringHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_SetSpringHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_SetSpringDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_SetSpringDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_GetSpringHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetSpringHertz(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_GetSpringDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetSpringDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_EnableLimit)
{
	zval *jointId_zv;
	bool enableLimit_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableLimit_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_EnableLimit(jointId_c, enableLimit_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_IsLimitEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2DistanceJoint_IsLimitEnabled(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_SetLengthRange)
{
	zval *jointId_zv;
	double minLength_d;
	double maxLength_d;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(minLength_d)
		Z_PARAM_DOUBLE(maxLength_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_SetLengthRange(jointId_c, (float) minLength_d, (float) maxLength_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_GetMinLength)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetMinLength(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_GetMaxLength)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetMaxLength(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_GetCurrentLength)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetCurrentLength(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_EnableMotor)
{
	zval *jointId_zv;
	bool enableMotor_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableMotor_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_EnableMotor(jointId_c, enableMotor_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_IsMotorEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2DistanceJoint_IsMotorEnabled(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_SetMotorSpeed)
{
	zval *jointId_zv;
	double motorSpeed_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(motorSpeed_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_SetMotorSpeed(jointId_c, (float) motorSpeed_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_GetMotorSpeed)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetMotorSpeed(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_SetMaxMotorForce)
{
	zval *jointId_zv;
	double force_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(force_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DistanceJoint_SetMaxMotorForce(jointId_c, (float) force_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DistanceJoint_GetMaxMotorForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetMaxMotorForce(jointId_c);
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


ZEND_FUNCTION(b2DistanceJoint_GetMotorForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2DistanceJoint_GetMotorForce(jointId_c);
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


ZEND_FUNCTION(b2CreateMotorJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2MotorJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2MotorJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2MotorJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateMotorJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MotorJoint_SetLinearOffset)
{
	zval *jointId_zv;
	zval *linearOffset_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_OBJECT_OF_CLASS(linearOffset_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 linearOffset_c;
	if (box2d_bind_read(linearOffset_zv, &linearOffset_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MotorJoint_SetLinearOffset(jointId_c, linearOffset_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MotorJoint_GetLinearOffset)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2MotorJoint_GetLinearOffset(jointId_c);
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


ZEND_FUNCTION(b2MotorJoint_SetAngularOffset)
{
	zval *jointId_zv;
	double angularOffset_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(angularOffset_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MotorJoint_SetAngularOffset(jointId_c, (float) angularOffset_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MotorJoint_GetAngularOffset)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MotorJoint_GetAngularOffset(jointId_c);
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


ZEND_FUNCTION(b2MotorJoint_SetMaxForce)
{
	zval *jointId_zv;
	double maxForce_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(maxForce_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MotorJoint_SetMaxForce(jointId_c, (float) maxForce_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MotorJoint_GetMaxForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MotorJoint_GetMaxForce(jointId_c);
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


ZEND_FUNCTION(b2MotorJoint_SetMaxTorque)
{
	zval *jointId_zv;
	double maxTorque_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(maxTorque_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MotorJoint_SetMaxTorque(jointId_c, (float) maxTorque_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MotorJoint_GetMaxTorque)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MotorJoint_GetMaxTorque(jointId_c);
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


ZEND_FUNCTION(b2MotorJoint_SetCorrectionFactor)
{
	zval *jointId_zv;
	double correctionFactor_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(correctionFactor_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MotorJoint_SetCorrectionFactor(jointId_c, (float) correctionFactor_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MotorJoint_GetCorrectionFactor)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MotorJoint_GetCorrectionFactor(jointId_c);
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


ZEND_FUNCTION(b2CreateMouseJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2MouseJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2MouseJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2MouseJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateMouseJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MouseJoint_SetTarget)
{
	zval *jointId_zv;
	zval *target_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_OBJECT_OF_CLASS(target_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 target_c;
	if (box2d_bind_read(target_zv, &target_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MouseJoint_SetTarget(jointId_c, target_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MouseJoint_GetTarget)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2MouseJoint_GetTarget(jointId_c);
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


ZEND_FUNCTION(b2MouseJoint_SetSpringHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MouseJoint_SetSpringHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MouseJoint_GetSpringHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MouseJoint_GetSpringHertz(jointId_c);
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


ZEND_FUNCTION(b2MouseJoint_SetSpringDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MouseJoint_SetSpringDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MouseJoint_GetSpringDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MouseJoint_GetSpringDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2MouseJoint_SetMaxForce)
{
	zval *jointId_zv;
	double maxForce_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(maxForce_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MouseJoint_SetMaxForce(jointId_c, (float) maxForce_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2MouseJoint_GetMaxForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2MouseJoint_GetMaxForce(jointId_c);
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


ZEND_FUNCTION(b2CreateFilterJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2FilterJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2FilterJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2FilterJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateFilterJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2CreatePrismaticJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2PrismaticJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2PrismaticJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2PrismaticJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreatePrismaticJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_EnableSpring)
{
	zval *jointId_zv;
	bool enableSpring_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableSpring_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_EnableSpring(jointId_c, enableSpring_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_IsSpringEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2PrismaticJoint_IsSpringEnabled(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_SetSpringHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_SetSpringHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_GetSpringHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetSpringHertz(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_SetSpringDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_SetSpringDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_GetSpringDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetSpringDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_SetTargetTranslation)
{
	zval *jointId_zv;
	double translation_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(translation_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_SetTargetTranslation(jointId_c, (float) translation_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_GetTargetTranslation)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetTargetTranslation(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_EnableLimit)
{
	zval *jointId_zv;
	bool enableLimit_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableLimit_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_EnableLimit(jointId_c, enableLimit_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_IsLimitEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2PrismaticJoint_IsLimitEnabled(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_GetLowerLimit)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetLowerLimit(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_GetUpperLimit)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetUpperLimit(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_SetLimits)
{
	zval *jointId_zv;
	double lower_d;
	double upper_d;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(lower_d)
		Z_PARAM_DOUBLE(upper_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_SetLimits(jointId_c, (float) lower_d, (float) upper_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_EnableMotor)
{
	zval *jointId_zv;
	bool enableMotor_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableMotor_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_EnableMotor(jointId_c, enableMotor_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_IsMotorEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2PrismaticJoint_IsMotorEnabled(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_SetMotorSpeed)
{
	zval *jointId_zv;
	double motorSpeed_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(motorSpeed_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_SetMotorSpeed(jointId_c, (float) motorSpeed_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_GetMotorSpeed)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetMotorSpeed(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_SetMaxMotorForce)
{
	zval *jointId_zv;
	double force_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(force_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2PrismaticJoint_SetMaxMotorForce(jointId_c, (float) force_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2PrismaticJoint_GetMaxMotorForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetMaxMotorForce(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_GetMotorForce)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetMotorForce(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_GetTranslation)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetTranslation(jointId_c);
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


ZEND_FUNCTION(b2PrismaticJoint_GetSpeed)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2PrismaticJoint_GetSpeed(jointId_c);
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


ZEND_FUNCTION(b2CreateRevoluteJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2RevoluteJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2RevoluteJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2RevoluteJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateRevoluteJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_EnableSpring)
{
	zval *jointId_zv;
	bool enableSpring_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableSpring_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_EnableSpring(jointId_c, enableSpring_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_IsSpringEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2RevoluteJoint_IsSpringEnabled(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_SetSpringHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_SetSpringHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_GetSpringHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetSpringHertz(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_SetSpringDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_SetSpringDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_GetSpringDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetSpringDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_SetTargetAngle)
{
	zval *jointId_zv;
	double angle_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(angle_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_SetTargetAngle(jointId_c, (float) angle_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_GetTargetAngle)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetTargetAngle(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_GetAngle)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetAngle(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_EnableLimit)
{
	zval *jointId_zv;
	bool enableLimit_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableLimit_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_EnableLimit(jointId_c, enableLimit_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_IsLimitEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2RevoluteJoint_IsLimitEnabled(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_GetLowerLimit)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetLowerLimit(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_GetUpperLimit)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetUpperLimit(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_SetLimits)
{
	zval *jointId_zv;
	double lower_d;
	double upper_d;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(lower_d)
		Z_PARAM_DOUBLE(upper_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_SetLimits(jointId_c, (float) lower_d, (float) upper_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_EnableMotor)
{
	zval *jointId_zv;
	bool enableMotor_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableMotor_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_EnableMotor(jointId_c, enableMotor_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_IsMotorEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2RevoluteJoint_IsMotorEnabled(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_SetMotorSpeed)
{
	zval *jointId_zv;
	double motorSpeed_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(motorSpeed_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_SetMotorSpeed(jointId_c, (float) motorSpeed_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_GetMotorSpeed)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetMotorSpeed(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_GetMotorTorque)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetMotorTorque(jointId_c);
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


ZEND_FUNCTION(b2RevoluteJoint_SetMaxMotorTorque)
{
	zval *jointId_zv;
	double torque_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(torque_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2RevoluteJoint_SetMaxMotorTorque(jointId_c, (float) torque_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2RevoluteJoint_GetMaxMotorTorque)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2RevoluteJoint_GetMaxMotorTorque(jointId_c);
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


ZEND_FUNCTION(b2CreateWeldJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2WeldJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WeldJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2WeldJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateWeldJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WeldJoint_SetLinearHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WeldJoint_SetLinearHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WeldJoint_GetLinearHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WeldJoint_GetLinearHertz(jointId_c);
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


ZEND_FUNCTION(b2WeldJoint_SetLinearDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WeldJoint_SetLinearDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WeldJoint_GetLinearDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WeldJoint_GetLinearDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2WeldJoint_SetAngularHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WeldJoint_SetAngularHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WeldJoint_GetAngularHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WeldJoint_GetAngularHertz(jointId_c);
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


ZEND_FUNCTION(b2WeldJoint_SetAngularDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WeldJoint_SetAngularDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WeldJoint_GetAngularDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WeldJoint_GetAngularDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2CreateWheelJoint)
{
	zval *worldId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(worldId_zv, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2WheelJointDef)
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
	box2d_guard_joint_bodies(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2WheelJointDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2WheelJointDef) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2JointId box2d_result = b2CreateWheelJoint(worldId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_EnableSpring)
{
	zval *jointId_zv;
	bool enableSpring_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableSpring_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_EnableSpring(jointId_c, enableSpring_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_IsSpringEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2WheelJoint_IsSpringEnabled(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_SetSpringHertz)
{
	zval *jointId_zv;
	double hertz_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(hertz_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_SetSpringHertz(jointId_c, (float) hertz_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_GetSpringHertz)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetSpringHertz(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_SetSpringDampingRatio)
{
	zval *jointId_zv;
	double dampingRatio_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(dampingRatio_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_SetSpringDampingRatio(jointId_c, (float) dampingRatio_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_GetSpringDampingRatio)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetSpringDampingRatio(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_EnableLimit)
{
	zval *jointId_zv;
	bool enableLimit_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableLimit_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_EnableLimit(jointId_c, enableLimit_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_IsLimitEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2WheelJoint_IsLimitEnabled(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_GetLowerLimit)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetLowerLimit(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_GetUpperLimit)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetUpperLimit(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_SetLimits)
{
	zval *jointId_zv;
	double lower_d;
	double upper_d;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(lower_d)
		Z_PARAM_DOUBLE(upper_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_SetLimits(jointId_c, (float) lower_d, (float) upper_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_EnableMotor)
{
	zval *jointId_zv;
	bool enableMotor_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_BOOL(enableMotor_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_EnableMotor(jointId_c, enableMotor_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_IsMotorEnabled)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2WheelJoint_IsMotorEnabled(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_SetMotorSpeed)
{
	zval *jointId_zv;
	double motorSpeed_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(motorSpeed_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_SetMotorSpeed(jointId_c, (float) motorSpeed_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_GetMotorSpeed)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetMotorSpeed(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_SetMaxMotorTorque)
{
	zval *jointId_zv;
	double torque_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
		Z_PARAM_DOUBLE(torque_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WheelJoint_SetMaxMotorTorque(jointId_c, (float) torque_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2WheelJoint_GetMaxMotorTorque)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetMaxMotorTorque(jointId_c);
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


ZEND_FUNCTION(b2WheelJoint_GetMotorTorque)
{
	zval *jointId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(jointId_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(jointId_zv, BOX2D_ID_JOINT, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2JointId jointId_c;
	if (box2d_bind_read(jointId_zv, &jointId_c, box2d_from_slot_b2JointId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(jointId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2WheelJoint_GetMotorTorque(jointId_c);
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

