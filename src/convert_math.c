#include "convert.h"
#include "classes.h"

#include <string.h>

zend_result box2d_b2Vec2_from_zval(zval *zv, b2Vec2 *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Vec2) {
		zend_type_error("b2Vec2 expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_f32(object, ZEND_STRL("x"), &out->x) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("y"), &out->y) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Vec2_to_zval(const b2Vec2 *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Vec2);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_f32(object, ZEND_STRL("x"), in->x);
	box2d_put_f32(object, ZEND_STRL("y"), in->y);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Vec2(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Vec2_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Vec2(const void *in, zval *out)
{
	return box2d_b2Vec2_to_zval(in, out);
}


zend_result box2d_b2CosSin_from_zval(zval *zv, b2CosSin *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2CosSin) {
		zend_type_error("b2CosSin expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_f32(object, ZEND_STRL("cosine"), &out->cosine) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("sine"), &out->sine) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2CosSin_to_zval(const b2CosSin *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2CosSin);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_f32(object, ZEND_STRL("cosine"), in->cosine);
	box2d_put_f32(object, ZEND_STRL("sine"), in->sine);
	return SUCCESS;
}

zend_result box2d_from_slot_b2CosSin(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2CosSin_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2CosSin(const void *in, zval *out)
{
	return box2d_b2CosSin_to_zval(in, out);
}


zend_result box2d_b2Rot_from_zval(zval *zv, b2Rot *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Rot) {
		zend_type_error("b2Rot expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_f32(object, ZEND_STRL("c"), &out->c) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("s"), &out->s) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Rot_to_zval(const b2Rot *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Rot);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_f32(object, ZEND_STRL("c"), in->c);
	box2d_put_f32(object, ZEND_STRL("s"), in->s);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Rot(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Rot_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Rot(const void *in, zval *out)
{
	return box2d_b2Rot_to_zval(in, out);
}


zend_result box2d_b2Transform_from_zval(zval *zv, b2Transform *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Transform) {
		zend_type_error("b2Transform expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("p"), box2d_from_slot_b2Vec2, &out->p, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("q"), box2d_from_slot_b2Rot, &out->q, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Transform_to_zval(const b2Transform *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Transform);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("p"), box2d_to_slot_b2Vec2, &in->p) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("q"), box2d_to_slot_b2Rot, &in->q) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2Transform(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Transform_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Transform(const void *in, zval *out)
{
	return box2d_b2Transform_to_zval(in, out);
}


zend_result box2d_b2Mat22_from_zval(zval *zv, b2Mat22 *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Mat22) {
		zend_type_error("b2Mat22 expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("cx"), box2d_from_slot_b2Vec2, &out->cx, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("cy"), box2d_from_slot_b2Vec2, &out->cy, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Mat22_to_zval(const b2Mat22 *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Mat22);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("cx"), box2d_to_slot_b2Vec2, &in->cx) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("cy"), box2d_to_slot_b2Vec2, &in->cy) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2Mat22(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Mat22_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Mat22(const void *in, zval *out)
{
	return box2d_b2Mat22_to_zval(in, out);
}


zend_result box2d_b2AABB_from_zval(zval *zv, b2AABB *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2AABB) {
		zend_type_error("b2AABB expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("lowerBound"), box2d_from_slot_b2Vec2, &out->lowerBound, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("upperBound"), box2d_from_slot_b2Vec2, &out->upperBound, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2AABB_to_zval(const b2AABB *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2AABB);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("lowerBound"), box2d_to_slot_b2Vec2, &in->lowerBound) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("upperBound"), box2d_to_slot_b2Vec2, &in->upperBound) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2AABB(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2AABB_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2AABB(const void *in, zval *out)
{
	return box2d_b2AABB_to_zval(in, out);
}


zend_result box2d_b2Plane_from_zval(zval *zv, b2Plane *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Plane) {
		zend_type_error("b2Plane expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("normal"), box2d_from_slot_b2Vec2, &out->normal, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("offset"), &out->offset) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Plane_to_zval(const b2Plane *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Plane);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("normal"), box2d_to_slot_b2Vec2, &in->normal) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("offset"), in->offset);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Plane(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Plane_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Plane(const void *in, zval *out)
{
	return box2d_b2Plane_to_zval(in, out);
}


zend_result box2d_b2Version_from_zval(zval *zv, b2Version *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Version) {
		zend_type_error("b2Version expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int major_bits;
	if (box2d_prop_i32(object, ZEND_STRL("major"), &major_bits) == FAILURE) return FAILURE;
	out->major = major_bits;
	int minor_bits;
	if (box2d_prop_i32(object, ZEND_STRL("minor"), &minor_bits) == FAILURE) return FAILURE;
	out->minor = minor_bits;
	int revision_bits;
	if (box2d_prop_i32(object, ZEND_STRL("revision"), &revision_bits) == FAILURE) return FAILURE;
	out->revision = revision_bits;
	return SUCCESS;
}

zend_result box2d_b2Version_to_zval(const b2Version *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Version);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("major"), in->major);
	box2d_put_i32(object, ZEND_STRL("minor"), in->minor);
	box2d_put_i32(object, ZEND_STRL("revision"), in->revision);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Version(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Version_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Version(const void *in, zval *out)
{
	return box2d_b2Version_to_zval(in, out);
}


zend_result box2d_b2WorldId_from_zval(zval *zv, b2WorldId *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2WorldId) {
		zend_type_error("b2WorldId expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_u16(object, ZEND_STRL("index1"), &out->index1) == FAILURE) return FAILURE;
	if (box2d_prop_u16(object, ZEND_STRL("generation"), &out->generation) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2WorldId_to_zval(const b2WorldId *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2WorldId);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("index1"), in->index1);
	box2d_put_i32(object, ZEND_STRL("generation"), in->generation);
	return SUCCESS;
}

zend_result box2d_from_slot_b2WorldId(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2WorldId_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2WorldId(const void *in, zval *out)
{
	return box2d_b2WorldId_to_zval(in, out);
}


zend_result box2d_b2BodyId_from_zval(zval *zv, b2BodyId *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2BodyId) {
		zend_type_error("b2BodyId expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int index1_bits;
	if (box2d_prop_i32(object, ZEND_STRL("index1"), &index1_bits) == FAILURE) return FAILURE;
	out->index1 = index1_bits;
	if (box2d_prop_u16(object, ZEND_STRL("world0"), &out->world0) == FAILURE) return FAILURE;
	if (box2d_prop_u16(object, ZEND_STRL("generation"), &out->generation) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2BodyId_to_zval(const b2BodyId *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2BodyId);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("index1"), in->index1);
	box2d_put_i32(object, ZEND_STRL("world0"), in->world0);
	box2d_put_i32(object, ZEND_STRL("generation"), in->generation);
	return SUCCESS;
}

zend_result box2d_from_slot_b2BodyId(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2BodyId_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2BodyId(const void *in, zval *out)
{
	return box2d_b2BodyId_to_zval(in, out);
}


zend_result box2d_b2ShapeId_from_zval(zval *zv, b2ShapeId *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ShapeId) {
		zend_type_error("b2ShapeId expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int index1_bits;
	if (box2d_prop_i32(object, ZEND_STRL("index1"), &index1_bits) == FAILURE) return FAILURE;
	out->index1 = index1_bits;
	if (box2d_prop_u16(object, ZEND_STRL("world0"), &out->world0) == FAILURE) return FAILURE;
	if (box2d_prop_u16(object, ZEND_STRL("generation"), &out->generation) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ShapeId_to_zval(const b2ShapeId *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ShapeId);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("index1"), in->index1);
	box2d_put_i32(object, ZEND_STRL("world0"), in->world0);
	box2d_put_i32(object, ZEND_STRL("generation"), in->generation);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ShapeId(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ShapeId_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ShapeId(const void *in, zval *out)
{
	return box2d_b2ShapeId_to_zval(in, out);
}


zend_result box2d_b2ChainId_from_zval(zval *zv, b2ChainId *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ChainId) {
		zend_type_error("b2ChainId expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int index1_bits;
	if (box2d_prop_i32(object, ZEND_STRL("index1"), &index1_bits) == FAILURE) return FAILURE;
	out->index1 = index1_bits;
	if (box2d_prop_u16(object, ZEND_STRL("world0"), &out->world0) == FAILURE) return FAILURE;
	if (box2d_prop_u16(object, ZEND_STRL("generation"), &out->generation) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ChainId_to_zval(const b2ChainId *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ChainId);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("index1"), in->index1);
	box2d_put_i32(object, ZEND_STRL("world0"), in->world0);
	box2d_put_i32(object, ZEND_STRL("generation"), in->generation);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ChainId(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ChainId_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ChainId(const void *in, zval *out)
{
	return box2d_b2ChainId_to_zval(in, out);
}


zend_result box2d_b2JointId_from_zval(zval *zv, b2JointId *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2JointId) {
		zend_type_error("b2JointId expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int index1_bits;
	if (box2d_prop_i32(object, ZEND_STRL("index1"), &index1_bits) == FAILURE) return FAILURE;
	out->index1 = index1_bits;
	if (box2d_prop_u16(object, ZEND_STRL("world0"), &out->world0) == FAILURE) return FAILURE;
	if (box2d_prop_u16(object, ZEND_STRL("generation"), &out->generation) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2JointId_to_zval(const b2JointId *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2JointId);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("index1"), in->index1);
	box2d_put_i32(object, ZEND_STRL("world0"), in->world0);
	box2d_put_i32(object, ZEND_STRL("generation"), in->generation);
	return SUCCESS;
}

zend_result box2d_from_slot_b2JointId(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2JointId_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2JointId(const void *in, zval *out)
{
	return box2d_b2JointId_to_zval(in, out);
}

