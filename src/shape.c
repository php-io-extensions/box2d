#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

ZEND_FUNCTION(b2CreateCircleShape)
{
	zval *bodyId_zv;
	zval *def_zv;
	zval *circle_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2ShapeDef)
		Z_PARAM_OBJECT_OF_CLASS(circle_zv, box2d_ce_b2Circle)
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
	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2ShapeDef) == FAILURE) {
		RETURN_THROWS();
	}
	b2Circle circle_c;
	if (box2d_bind_read(circle_zv, &circle_c, box2d_from_slot_b2Circle) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ShapeId box2d_result = b2CreateCircleShape(bodyId_c, &def_c, &circle_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2ShapeId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2CreateSegmentShape)
{
	zval *bodyId_zv;
	zval *def_zv;
	zval *segment_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2ShapeDef)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2Segment)
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
	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2ShapeDef) == FAILURE) {
		RETURN_THROWS();
	}
	b2Segment segment_c;
	if (box2d_bind_read(segment_zv, &segment_c, box2d_from_slot_b2Segment) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ShapeId box2d_result = b2CreateSegmentShape(bodyId_c, &def_c, &segment_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2ShapeId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2CreateCapsuleShape)
{
	zval *bodyId_zv;
	zval *def_zv;
	zval *capsule_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2ShapeDef)
		Z_PARAM_OBJECT_OF_CLASS(capsule_zv, box2d_ce_b2Capsule)
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
	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2ShapeDef) == FAILURE) {
		RETURN_THROWS();
	}
	b2Capsule capsule_c;
	if (box2d_bind_read(capsule_zv, &capsule_c, box2d_from_slot_b2Capsule) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ShapeId box2d_result = b2CreateCapsuleShape(bodyId_c, &def_c, &capsule_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2ShapeId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2CreatePolygonShape)
{
	zval *bodyId_zv;
	zval *def_zv;
	zval *polygon_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2ShapeDef)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
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
	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeDef def_c;
	if (box2d_bind_read(def_zv, &def_c, box2d_from_slot_b2ShapeDef) == FAILURE) {
		RETURN_THROWS();
	}
	b2Polygon polygon_c;
	if (box2d_bind_read(polygon_zv, &polygon_c, box2d_from_slot_b2Polygon) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ShapeId box2d_result = b2CreatePolygonShape(bodyId_c, &def_c, &polygon_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2ShapeId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DestroyShape)
{
	zval *shapeId_zv;
	bool updateBodyMass_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_BOOL(updateBodyMass_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DestroyShape(shapeId_c, updateBodyMass_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_IsValid)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(id_zv, BOX2D_ID_SHAPE, 1);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId id_c;
	if (box2d_bind_read(id_zv, &id_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(id_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_IS_VALID);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_IsValid(id_c);
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


ZEND_FUNCTION(b2Shape_GetType)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_TYPE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Shape_GetType(shapeId_c);
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


ZEND_FUNCTION(b2Shape_GetBody)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_BODY);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2BodyId box2d_result = b2Shape_GetBody(shapeId_c);
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


ZEND_FUNCTION(b2Shape_GetWorld)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_WORLD);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WorldId box2d_result = b2Shape_GetWorld(shapeId_c);
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


ZEND_FUNCTION(b2Shape_IsSensor)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_IS_SENSOR);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_IsSensor(shapeId_c);
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


ZEND_FUNCTION(b2Shape_SetUserData)
{
	zval *shapeId_zv;
	zend_long userData_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_LONG(userData_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetUserData(shapeId_c, (void *) (uintptr_t) (uint64_t) userData_l);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetUserData)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_USER_DATA);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	void *box2d_result = b2Shape_GetUserData(shapeId_c);
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


ZEND_FUNCTION(b2Shape_SetDensity)
{
	zval *shapeId_zv;
	double density_d;
	bool updateBodyMass_b;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_DOUBLE(density_d)
		Z_PARAM_BOOL(updateBodyMass_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetDensity(shapeId_c, (float) density_d, updateBodyMass_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetDensity)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_DENSITY);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Shape_GetDensity(shapeId_c);
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


ZEND_FUNCTION(b2Shape_SetFriction)
{
	zval *shapeId_zv;
	double friction_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_DOUBLE(friction_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetFriction(shapeId_c, (float) friction_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetFriction)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_FRICTION);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Shape_GetFriction(shapeId_c);
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


ZEND_FUNCTION(b2Shape_SetRestitution)
{
	zval *shapeId_zv;
	double restitution_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_DOUBLE(restitution_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetRestitution(shapeId_c, (float) restitution_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetRestitution)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_RESTITUTION);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Shape_GetRestitution(shapeId_c);
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


ZEND_FUNCTION(b2Shape_SetMaterial)
{
	zval *shapeId_zv;
	zend_long material_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_LONG(material_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	int material_i;
	if (box2d_bind_i32(material_l, &material_i, "material") == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetMaterial(shapeId_c, material_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetMaterial)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_MATERIAL);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Shape_GetMaterial(shapeId_c);
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


ZEND_FUNCTION(b2Shape_SetSurfaceMaterial)
{
	zval *shapeId_zv;
	zval *surfaceMaterial_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(surfaceMaterial_zv, box2d_ce_b2SurfaceMaterial)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2SurfaceMaterial surfaceMaterial_c;
	if (box2d_bind_read(surfaceMaterial_zv, &surfaceMaterial_c, box2d_from_slot_b2SurfaceMaterial) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetSurfaceMaterial(shapeId_c, surfaceMaterial_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetSurfaceMaterial)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_SURFACE_MATERIAL);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2SurfaceMaterial box2d_result = b2Shape_GetSurfaceMaterial(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2SurfaceMaterial_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetFilter)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_FILTER);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Filter box2d_result = b2Shape_GetFilter(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Filter_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_SetFilter)
{
	zval *shapeId_zv;
	zval *filter_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2Filter)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Filter filter_c;
	if (box2d_bind_read(filter_zv, &filter_c, box2d_from_slot_b2Filter) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetFilter(shapeId_c, filter_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_EnableSensorEvents)
{
	zval *shapeId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_EnableSensorEvents(shapeId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_AreSensorEventsEnabled)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_AreSensorEventsEnabled(shapeId_c);
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


ZEND_FUNCTION(b2Shape_EnableContactEvents)
{
	zval *shapeId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_EnableContactEvents(shapeId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_AreContactEventsEnabled)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_AreContactEventsEnabled(shapeId_c);
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


ZEND_FUNCTION(b2Shape_EnablePreSolveEvents)
{
	zval *shapeId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_EnablePreSolveEvents(shapeId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_ArePreSolveEventsEnabled)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_ArePreSolveEventsEnabled(shapeId_c);
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


ZEND_FUNCTION(b2Shape_EnableHitEvents)
{
	zval *shapeId_zv;
	bool flag_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_BOOL(flag_b)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_EnableHitEvents(shapeId_c, flag_b);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_AreHitEventsEnabled)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_AreHitEventsEnabled(shapeId_c);
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


ZEND_FUNCTION(b2Shape_TestPoint)
{
	zval *shapeId_zv;
	zval *point_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 point_c;
	if (box2d_bind_read(point_zv, &point_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Shape_TestPoint(shapeId_c, point_c);
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


ZEND_FUNCTION(b2Shape_RayCast)
{
	zval *shapeId_zv;
	zval *input_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2RayCastInput input_c;
	if (box2d_bind_read(input_zv, &input_c, box2d_from_slot_b2RayCastInput) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2CastOutput box2d_result = b2Shape_RayCast(shapeId_c, &input_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2CastOutput_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetCircle)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Circle box2d_result = b2Shape_GetCircle(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Circle_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetSegment)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Segment box2d_result = b2Shape_GetSegment(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Segment_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetChainSegment)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ChainSegment box2d_result = b2Shape_GetChainSegment(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2ChainSegment_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetCapsule)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Capsule box2d_result = b2Shape_GetCapsule(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Capsule_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetPolygon)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Polygon box2d_result = b2Shape_GetPolygon(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2Polygon_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_SetCircle)
{
	zval *shapeId_zv;
	zval *circle_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(circle_zv, box2d_ce_b2Circle)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Circle circle_c;
	if (box2d_bind_read(circle_zv, &circle_c, box2d_from_slot_b2Circle) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetCircle(shapeId_c, &circle_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_SetCapsule)
{
	zval *shapeId_zv;
	zval *capsule_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(capsule_zv, box2d_ce_b2Capsule)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Capsule capsule_c;
	if (box2d_bind_read(capsule_zv, &capsule_c, box2d_from_slot_b2Capsule) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetCapsule(shapeId_c, &capsule_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_SetSegment)
{
	zval *shapeId_zv;
	zval *segment_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2Segment)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Segment segment_c;
	if (box2d_bind_read(segment_zv, &segment_c, box2d_from_slot_b2Segment) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetSegment(shapeId_c, &segment_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_SetPolygon)
{
	zval *shapeId_zv;
	zval *polygon_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Polygon polygon_c;
	if (box2d_bind_read(polygon_zv, &polygon_c, box2d_from_slot_b2Polygon) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Shape_SetPolygon(shapeId_c, &polygon_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetParentChain)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_SHAPE_GET_PARENT_CHAIN);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ChainId box2d_result = b2Shape_GetParentChain(shapeId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2ChainId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Shape_GetContactCapacity)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Shape_GetContactCapacity(shapeId_c);
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


ZEND_FUNCTION(b2Shape_GetContactData)
{
	zval *shapeId_zv;
	zval *contactData_zv;
	zend_long capacity_l;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_ZVAL(contactData_zv)
		Z_PARAM_LONG(capacity_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
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
	int box2d_result = b2Shape_GetContactData(shapeId_c, contactData_buf, capacity_i);
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


ZEND_FUNCTION(b2Shape_GetSensorCapacity)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Shape_GetSensorCapacity(shapeId_c);
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


ZEND_FUNCTION(b2Shape_GetSensorOverlaps)
{
	zval *shapeId_zv;
	zval *overlaps_zv;
	zend_long capacity_l;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_ZVAL(overlaps_zv)
		Z_PARAM_LONG(capacity_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
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
	b2ShapeId *overlaps_buf = NULL;
	if (capacity_i > 0) {
		overlaps_buf = safe_emalloc((size_t) capacity_i, sizeof(b2ShapeId), 0);
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Shape_GetSensorOverlaps(shapeId_c, overlaps_buf, capacity_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		if (overlaps_buf != NULL) {
			efree(overlaps_buf);
		}
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		if (overlaps_buf != NULL) {
			efree(overlaps_buf);
		}
		RETURN_THROWS();
	}
	if (box2d_result < 0 || box2d_result > capacity_i) {
		if (overlaps_buf != NULL) {
			efree(overlaps_buf);
		}
		zend_value_error("capacity %d cannot hold %d results", capacity_i, box2d_result);
		RETURN_THROWS();
	}
	if (box2d_store_list(overlaps_zv, box2d_result, overlaps_buf, sizeof(b2ShapeId), box2d_to_slot_b2ShapeId) == FAILURE) {
		if (overlaps_buf != NULL) {
			efree(overlaps_buf);
		}
		RETURN_THROWS();
	}
	if (overlaps_buf != NULL) {
		efree(overlaps_buf);
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Shape_GetAABB)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2AABB box2d_result = b2Shape_GetAABB(shapeId_c);
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


ZEND_FUNCTION(b2Shape_GetMassData)
{
	zval *shapeId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2MassData box2d_result = b2Shape_GetMassData(shapeId_c);
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


ZEND_FUNCTION(b2Shape_GetClosestPoint)
{
	zval *shapeId_zv;
	zval *target_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shapeId_zv, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(target_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(shapeId_zv, BOX2D_ID_SHAPE, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ShapeId shapeId_c;
	if (box2d_bind_read(shapeId_zv, &shapeId_c, box2d_from_slot_b2ShapeId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(shapeId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2Vec2 target_c;
	if (box2d_bind_read(target_zv, &target_c, box2d_from_slot_b2Vec2) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Vec2 box2d_result = b2Shape_GetClosestPoint(shapeId_c, target_c);
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

