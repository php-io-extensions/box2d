#include "classes.h"
#include "convert.h"

#include <stdint.h>

static zend_long box2d_id_field(zend_object *object, const char *name, size_t name_len)
{
	zval *value = zend_read_property(object->ce, object, name, name_len, 0, NULL);
	if (value == NULL || Z_TYPE_P(value) != IS_LONG) {
		return 0;
	}
	return Z_LVAL_P(value);
}

ZEND_FUNCTION(B2_IS_NULL)
{
	zval *id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(id)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(box2d_id_field(Z_OBJ_P(id), ZEND_STRL("index1")) == 0);
}

ZEND_FUNCTION(B2_IS_NON_NULL)
{
	zval *id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(id)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(box2d_id_field(Z_OBJ_P(id), ZEND_STRL("index1")) != 0);
}

ZEND_FUNCTION(B2_ID_EQUALS)
{
	zval *left;
	zval *right;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(left)
		Z_PARAM_OBJECT(right)
	ZEND_PARSE_PARAMETERS_END();

	zend_class_entry *left_ce = Z_OBJCE_P(left);
	zend_class_entry *right_ce = Z_OBJCE_P(right);
	if (left_ce == box2d_ce_b2WorldId || right_ce == box2d_ce_b2WorldId) {
		zend_value_error("B2_ID_EQUALS does not work for b2WorldId");
		RETURN_THROWS();
	}
	if (left_ce != right_ce) {
		zend_value_error("B2_ID_EQUALS requires two ids of the same type");
		RETURN_THROWS();
	}

	zend_object *left_object = Z_OBJ_P(left);
	zend_object *right_object = Z_OBJ_P(right);
	bool same = box2d_id_field(left_object, ZEND_STRL("index1")) == box2d_id_field(right_object, ZEND_STRL("index1"))
		&& box2d_id_field(left_object, ZEND_STRL("world0")) == box2d_id_field(right_object, ZEND_STRL("world0"))
		&& box2d_id_field(left_object, ZEND_STRL("generation")) == box2d_id_field(right_object, ZEND_STRL("generation"));
	RETURN_BOOL(same);
}

static zend_result box2d_read_world_id(zval *zv, b2WorldId *out)
{
	box2d_frame frame;
	box2d_frame_init(&frame);
	zend_result result = box2d_b2WorldId_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_body_id(zval *zv, b2BodyId *out)
{
	box2d_frame frame;
	box2d_frame_init(&frame);
	zend_result result = box2d_b2BodyId_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_shape_id(zval *zv, b2ShapeId *out)
{
	box2d_frame frame;
	box2d_frame_init(&frame);
	zend_result result = box2d_b2ShapeId_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_chain_id(zval *zv, b2ChainId *out)
{
	box2d_frame frame;
	box2d_frame_init(&frame);
	zend_result result = box2d_b2ChainId_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_joint_id(zval *zv, b2JointId *out)
{
	box2d_frame frame;
	box2d_frame_init(&frame);
	zend_result result = box2d_b2JointId_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_finish_id_call(void)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return SUCCESS;
}

ZEND_FUNCTION(b2StoreWorldId)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	b2WorldId id;
	if (box2d_read_world_id(id_zv, &id) == FAILURE) {
		RETURN_THROWS();
	}

	uint32_t stored = b2StoreWorldId(id);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG(stored);
}

ZEND_FUNCTION(b2LoadWorldId)
{
	zend_long bits;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bits)
	ZEND_PARSE_PARAMETERS_END();

	if (bits < 0 || bits > (zend_long) UINT32_MAX) {
		zend_value_error("b2LoadWorldId value %lld is outside 0..%u", (long long) bits, UINT32_MAX);
		RETURN_THROWS();
	}

	b2WorldId id = b2LoadWorldId((uint32_t) bits);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	if (box2d_b2WorldId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2StoreBodyId)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	b2BodyId id;
	if (box2d_read_body_id(id_zv, &id) == FAILURE) {
		RETURN_THROWS();
	}

	uint64_t stored = b2StoreBodyId(id);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) stored);
}

ZEND_FUNCTION(b2LoadBodyId)
{
	zend_long bits;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bits)
	ZEND_PARSE_PARAMETERS_END();

	b2BodyId id = b2LoadBodyId((uint64_t) bits);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	if (box2d_b2BodyId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2StoreShapeId)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeId id;
	if (box2d_read_shape_id(id_zv, &id) == FAILURE) {
		RETURN_THROWS();
	}

	uint64_t stored = b2StoreShapeId(id);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) stored);
}

ZEND_FUNCTION(b2LoadShapeId)
{
	zend_long bits;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bits)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeId id = b2LoadShapeId((uint64_t) bits);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	if (box2d_b2ShapeId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2StoreChainId)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	b2ChainId id;
	if (box2d_read_chain_id(id_zv, &id) == FAILURE) {
		RETURN_THROWS();
	}

	uint64_t stored = b2StoreChainId(id);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) stored);
}

ZEND_FUNCTION(b2LoadChainId)
{
	zend_long bits;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bits)
	ZEND_PARSE_PARAMETERS_END();

	b2ChainId id = b2LoadChainId((uint64_t) bits);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	if (box2d_b2ChainId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2StoreJointId)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2JointId)
	ZEND_PARSE_PARAMETERS_END();

	b2JointId id;
	if (box2d_read_joint_id(id_zv, &id) == FAILURE) {
		RETURN_THROWS();
	}

	uint64_t stored = b2StoreJointId(id);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) stored);
}

ZEND_FUNCTION(b2LoadJointId)
{
	zend_long bits;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bits)
	ZEND_PARSE_PARAMETERS_END();

	b2JointId id = b2LoadJointId((uint64_t) bits);
	if (box2d_finish_id_call() == FAILURE) {
		RETURN_THROWS();
	}
	if (box2d_b2JointId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2_nullWorldId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2WorldId id = b2_nullWorldId;
	if (box2d_b2WorldId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2_nullBodyId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2BodyId id = b2_nullBodyId;
	if (box2d_b2BodyId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2_nullShapeId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2ShapeId id = b2_nullShapeId;
	if (box2d_b2ShapeId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2_nullChainId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2ChainId id = b2_nullChainId;
	if (box2d_b2ChainId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2_nullJointId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2JointId id = b2_nullJointId;
	if (box2d_b2JointId_to_zval(&id, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}
