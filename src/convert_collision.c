#include "convert.h"
#include "classes.h"

#include <string.h>

zend_result box2d_b2RayCastInput_from_zval(zval *zv, b2RayCastInput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2RayCastInput) {
		zend_type_error("b2RayCastInput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("origin"), box2d_from_slot_b2Vec2, &out->origin, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("translation"), box2d_from_slot_b2Vec2, &out->translation, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxFraction"), &out->maxFraction) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2RayCastInput_to_zval(const b2RayCastInput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2RayCastInput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("origin"), box2d_to_slot_b2Vec2, &in->origin) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("translation"), box2d_to_slot_b2Vec2, &in->translation) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("maxFraction"), in->maxFraction);
	return SUCCESS;
}

zend_result box2d_from_slot_b2RayCastInput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2RayCastInput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2RayCastInput(const void *in, zval *out)
{
	return box2d_b2RayCastInput_to_zval(in, out);
}


zend_result box2d_b2ShapeProxy_from_zval(zval *zv, b2ShapeProxy *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ShapeProxy) {
		zend_type_error("b2ShapeProxy expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int count_value;
	if (box2d_prop_i32(object, ZEND_STRL("count"), &count_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(count_value, 8, "b2ShapeProxy::$count") == FAILURE) {
		return FAILURE;
	}
	if (box2d_list_embedded(object, ZEND_STRL("points"), count_value, out->points, sizeof(b2Vec2), box2d_from_slot_b2Vec2, frame) == FAILURE) return FAILURE;
	out->count = count_value;
	if (box2d_prop_f32(object, ZEND_STRL("radius"), &out->radius) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ShapeProxy_to_zval(const b2ShapeProxy *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ShapeProxy);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct_list(object, ZEND_STRL("points"), in->count, in->points, sizeof(b2Vec2), box2d_to_slot_b2Vec2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("count"), in->count);
	box2d_put_f32(object, ZEND_STRL("radius"), in->radius);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ShapeProxy(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ShapeProxy_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ShapeProxy(const void *in, zval *out)
{
	return box2d_b2ShapeProxy_to_zval(in, out);
}


zend_result box2d_b2ShapeCastInput_from_zval(zval *zv, b2ShapeCastInput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ShapeCastInput) {
		zend_type_error("b2ShapeCastInput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("proxy"), box2d_from_slot_b2ShapeProxy, &out->proxy, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("translation"), box2d_from_slot_b2Vec2, &out->translation, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxFraction"), &out->maxFraction) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("canEncroach"), &out->canEncroach) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ShapeCastInput_to_zval(const b2ShapeCastInput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ShapeCastInput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("proxy"), box2d_to_slot_b2ShapeProxy, &in->proxy) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("translation"), box2d_to_slot_b2Vec2, &in->translation) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("maxFraction"), in->maxFraction);
	box2d_put_bool(object, ZEND_STRL("canEncroach"), in->canEncroach);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ShapeCastInput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ShapeCastInput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ShapeCastInput(const void *in, zval *out)
{
	return box2d_b2ShapeCastInput_to_zval(in, out);
}


zend_result box2d_b2CastOutput_from_zval(zval *zv, b2CastOutput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2CastOutput) {
		zend_type_error("b2CastOutput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("normal"), box2d_from_slot_b2Vec2, &out->normal, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("point"), box2d_from_slot_b2Vec2, &out->point, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("fraction"), &out->fraction) == FAILURE) return FAILURE;
	int iterations_bits;
	if (box2d_prop_i32(object, ZEND_STRL("iterations"), &iterations_bits) == FAILURE) return FAILURE;
	out->iterations = iterations_bits;
	if (box2d_prop_bool(object, ZEND_STRL("hit"), &out->hit) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2CastOutput_to_zval(const b2CastOutput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2CastOutput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("normal"), box2d_to_slot_b2Vec2, &in->normal) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("point"), box2d_to_slot_b2Vec2, &in->point) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("fraction"), in->fraction);
	box2d_put_i32(object, ZEND_STRL("iterations"), in->iterations);
	box2d_put_bool(object, ZEND_STRL("hit"), in->hit);
	return SUCCESS;
}

zend_result box2d_from_slot_b2CastOutput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2CastOutput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2CastOutput(const void *in, zval *out)
{
	return box2d_b2CastOutput_to_zval(in, out);
}


zend_result box2d_b2MassData_from_zval(zval *zv, b2MassData *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2MassData) {
		zend_type_error("b2MassData expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_f32(object, ZEND_STRL("mass"), &out->mass) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("center"), box2d_from_slot_b2Vec2, &out->center, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("rotationalInertia"), &out->rotationalInertia) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2MassData_to_zval(const b2MassData *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2MassData);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_f32(object, ZEND_STRL("mass"), in->mass);
	if (box2d_put_struct(object, ZEND_STRL("center"), box2d_to_slot_b2Vec2, &in->center) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("rotationalInertia"), in->rotationalInertia);
	return SUCCESS;
}

zend_result box2d_from_slot_b2MassData(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2MassData_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2MassData(const void *in, zval *out)
{
	return box2d_b2MassData_to_zval(in, out);
}


zend_result box2d_b2Circle_from_zval(zval *zv, b2Circle *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Circle) {
		zend_type_error("b2Circle expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("center"), box2d_from_slot_b2Vec2, &out->center, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("radius"), &out->radius) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Circle_to_zval(const b2Circle *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Circle);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("center"), box2d_to_slot_b2Vec2, &in->center) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("radius"), in->radius);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Circle(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Circle_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Circle(const void *in, zval *out)
{
	return box2d_b2Circle_to_zval(in, out);
}


zend_result box2d_b2Capsule_from_zval(zval *zv, b2Capsule *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Capsule) {
		zend_type_error("b2Capsule expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("center1"), box2d_from_slot_b2Vec2, &out->center1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("center2"), box2d_from_slot_b2Vec2, &out->center2, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("radius"), &out->radius) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Capsule_to_zval(const b2Capsule *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Capsule);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("center1"), box2d_to_slot_b2Vec2, &in->center1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("center2"), box2d_to_slot_b2Vec2, &in->center2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("radius"), in->radius);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Capsule(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Capsule_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Capsule(const void *in, zval *out)
{
	return box2d_b2Capsule_to_zval(in, out);
}


zend_result box2d_b2Polygon_from_zval(zval *zv, b2Polygon *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Polygon) {
		zend_type_error("b2Polygon expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int count_value;
	if (box2d_prop_i32(object, ZEND_STRL("count"), &count_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(count_value, 8, "b2Polygon::$count") == FAILURE) {
		return FAILURE;
	}
	if (box2d_list_embedded(object, ZEND_STRL("vertices"), count_value, out->vertices, sizeof(b2Vec2), box2d_from_slot_b2Vec2, frame) == FAILURE) return FAILURE;
	if (box2d_list_embedded(object, ZEND_STRL("normals"), count_value, out->normals, sizeof(b2Vec2), box2d_from_slot_b2Vec2, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("centroid"), box2d_from_slot_b2Vec2, &out->centroid, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("radius"), &out->radius) == FAILURE) return FAILURE;
	out->count = count_value;
	return SUCCESS;
}

zend_result box2d_b2Polygon_to_zval(const b2Polygon *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Polygon);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct_list(object, ZEND_STRL("vertices"), in->count, in->vertices, sizeof(b2Vec2), box2d_to_slot_b2Vec2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct_list(object, ZEND_STRL("normals"), in->count, in->normals, sizeof(b2Vec2), box2d_to_slot_b2Vec2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("centroid"), box2d_to_slot_b2Vec2, &in->centroid) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("radius"), in->radius);
	box2d_put_i32(object, ZEND_STRL("count"), in->count);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Polygon(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Polygon_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Polygon(const void *in, zval *out)
{
	return box2d_b2Polygon_to_zval(in, out);
}


zend_result box2d_b2Segment_from_zval(zval *zv, b2Segment *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Segment) {
		zend_type_error("b2Segment expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("point1"), box2d_from_slot_b2Vec2, &out->point1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("point2"), box2d_from_slot_b2Vec2, &out->point2, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Segment_to_zval(const b2Segment *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Segment);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("point1"), box2d_to_slot_b2Vec2, &in->point1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("point2"), box2d_to_slot_b2Vec2, &in->point2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2Segment(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Segment_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Segment(const void *in, zval *out)
{
	return box2d_b2Segment_to_zval(in, out);
}


zend_result box2d_b2ChainSegment_from_zval(zval *zv, b2ChainSegment *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ChainSegment) {
		zend_type_error("b2ChainSegment expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("ghost1"), box2d_from_slot_b2Vec2, &out->ghost1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("segment"), box2d_from_slot_b2Segment, &out->segment, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("ghost2"), box2d_from_slot_b2Vec2, &out->ghost2, frame) == FAILURE) return FAILURE;
	int chainId_bits;
	if (box2d_prop_i32(object, ZEND_STRL("chainId"), &chainId_bits) == FAILURE) return FAILURE;
	out->chainId = chainId_bits;
	return SUCCESS;
}

zend_result box2d_b2ChainSegment_to_zval(const b2ChainSegment *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ChainSegment);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("ghost1"), box2d_to_slot_b2Vec2, &in->ghost1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("segment"), box2d_to_slot_b2Segment, &in->segment) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("ghost2"), box2d_to_slot_b2Vec2, &in->ghost2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("chainId"), in->chainId);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ChainSegment(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ChainSegment_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ChainSegment(const void *in, zval *out)
{
	return box2d_b2ChainSegment_to_zval(in, out);
}


zend_result box2d_b2Hull_from_zval(zval *zv, b2Hull *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Hull) {
		zend_type_error("b2Hull expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int count_value;
	if (box2d_prop_i32(object, ZEND_STRL("count"), &count_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(count_value, 8, "b2Hull::$count") == FAILURE) {
		return FAILURE;
	}
	if (box2d_list_embedded(object, ZEND_STRL("points"), count_value, out->points, sizeof(b2Vec2), box2d_from_slot_b2Vec2, frame) == FAILURE) return FAILURE;
	out->count = count_value;
	return SUCCESS;
}

zend_result box2d_b2Hull_to_zval(const b2Hull *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Hull);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct_list(object, ZEND_STRL("points"), in->count, in->points, sizeof(b2Vec2), box2d_to_slot_b2Vec2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("count"), in->count);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Hull(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Hull_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Hull(const void *in, zval *out)
{
	return box2d_b2Hull_to_zval(in, out);
}


zend_result box2d_b2SegmentDistanceResult_from_zval(zval *zv, b2SegmentDistanceResult *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SegmentDistanceResult) {
		zend_type_error("b2SegmentDistanceResult expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("closest1"), box2d_from_slot_b2Vec2, &out->closest1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("closest2"), box2d_from_slot_b2Vec2, &out->closest2, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("fraction1"), &out->fraction1) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("fraction2"), &out->fraction2) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("distanceSquared"), &out->distanceSquared) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2SegmentDistanceResult_to_zval(const b2SegmentDistanceResult *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SegmentDistanceResult);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("closest1"), box2d_to_slot_b2Vec2, &in->closest1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("closest2"), box2d_to_slot_b2Vec2, &in->closest2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("fraction1"), in->fraction1);
	box2d_put_f32(object, ZEND_STRL("fraction2"), in->fraction2);
	box2d_put_f32(object, ZEND_STRL("distanceSquared"), in->distanceSquared);
	return SUCCESS;
}

zend_result box2d_from_slot_b2SegmentDistanceResult(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SegmentDistanceResult_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SegmentDistanceResult(const void *in, zval *out)
{
	return box2d_b2SegmentDistanceResult_to_zval(in, out);
}


zend_result box2d_b2SimplexCache_from_zval(zval *zv, b2SimplexCache *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SimplexCache) {
		zend_type_error("b2SimplexCache expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_u16(object, ZEND_STRL("count"), &out->count) == FAILURE) return FAILURE;
	if (box2d_list_u8(object, ZEND_STRL("indexA"), 3, out->indexA) == FAILURE) return FAILURE;
	if (box2d_list_u8(object, ZEND_STRL("indexB"), 3, out->indexB) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2SimplexCache_to_zval(const b2SimplexCache *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SimplexCache);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("count"), in->count);
	box2d_put_u8_list(object, ZEND_STRL("indexA"), 3, in->indexA);
	box2d_put_u8_list(object, ZEND_STRL("indexB"), 3, in->indexB);
	return SUCCESS;
}

zend_result box2d_from_slot_b2SimplexCache(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SimplexCache_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SimplexCache(const void *in, zval *out)
{
	return box2d_b2SimplexCache_to_zval(in, out);
}


zend_result box2d_b2DistanceInput_from_zval(zval *zv, b2DistanceInput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2DistanceInput) {
		zend_type_error("b2DistanceInput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("proxyA"), box2d_from_slot_b2ShapeProxy, &out->proxyA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("proxyB"), box2d_from_slot_b2ShapeProxy, &out->proxyB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("transformA"), box2d_from_slot_b2Transform, &out->transformA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("transformB"), box2d_from_slot_b2Transform, &out->transformB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("useRadii"), &out->useRadii) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2DistanceInput_to_zval(const b2DistanceInput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2DistanceInput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("proxyA"), box2d_to_slot_b2ShapeProxy, &in->proxyA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("proxyB"), box2d_to_slot_b2ShapeProxy, &in->proxyB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("transformA"), box2d_to_slot_b2Transform, &in->transformA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("transformB"), box2d_to_slot_b2Transform, &in->transformB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_bool(object, ZEND_STRL("useRadii"), in->useRadii);
	return SUCCESS;
}

zend_result box2d_from_slot_b2DistanceInput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2DistanceInput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2DistanceInput(const void *in, zval *out)
{
	return box2d_b2DistanceInput_to_zval(in, out);
}


zend_result box2d_b2DistanceOutput_from_zval(zval *zv, b2DistanceOutput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2DistanceOutput) {
		zend_type_error("b2DistanceOutput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("pointA"), box2d_from_slot_b2Vec2, &out->pointA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("pointB"), box2d_from_slot_b2Vec2, &out->pointB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("normal"), box2d_from_slot_b2Vec2, &out->normal, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("distance"), &out->distance) == FAILURE) return FAILURE;
	int iterations_bits;
	if (box2d_prop_i32(object, ZEND_STRL("iterations"), &iterations_bits) == FAILURE) return FAILURE;
	out->iterations = iterations_bits;
	int simplexCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("simplexCount"), &simplexCount_bits) == FAILURE) return FAILURE;
	out->simplexCount = simplexCount_bits;
	return SUCCESS;
}

zend_result box2d_b2DistanceOutput_to_zval(const b2DistanceOutput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2DistanceOutput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("pointA"), box2d_to_slot_b2Vec2, &in->pointA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("pointB"), box2d_to_slot_b2Vec2, &in->pointB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("normal"), box2d_to_slot_b2Vec2, &in->normal) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("distance"), in->distance);
	box2d_put_i32(object, ZEND_STRL("iterations"), in->iterations);
	box2d_put_i32(object, ZEND_STRL("simplexCount"), in->simplexCount);
	return SUCCESS;
}

zend_result box2d_from_slot_b2DistanceOutput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2DistanceOutput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2DistanceOutput(const void *in, zval *out)
{
	return box2d_b2DistanceOutput_to_zval(in, out);
}


zend_result box2d_b2SimplexVertex_from_zval(zval *zv, b2SimplexVertex *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SimplexVertex) {
		zend_type_error("b2SimplexVertex expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("wA"), box2d_from_slot_b2Vec2, &out->wA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("wB"), box2d_from_slot_b2Vec2, &out->wB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("w"), box2d_from_slot_b2Vec2, &out->w, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("a"), &out->a) == FAILURE) return FAILURE;
	int indexA_bits;
	if (box2d_prop_i32(object, ZEND_STRL("indexA"), &indexA_bits) == FAILURE) return FAILURE;
	out->indexA = indexA_bits;
	int indexB_bits;
	if (box2d_prop_i32(object, ZEND_STRL("indexB"), &indexB_bits) == FAILURE) return FAILURE;
	out->indexB = indexB_bits;
	return SUCCESS;
}

zend_result box2d_b2SimplexVertex_to_zval(const b2SimplexVertex *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SimplexVertex);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("wA"), box2d_to_slot_b2Vec2, &in->wA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("wB"), box2d_to_slot_b2Vec2, &in->wB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("w"), box2d_to_slot_b2Vec2, &in->w) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("a"), in->a);
	box2d_put_i32(object, ZEND_STRL("indexA"), in->indexA);
	box2d_put_i32(object, ZEND_STRL("indexB"), in->indexB);
	return SUCCESS;
}

zend_result box2d_from_slot_b2SimplexVertex(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SimplexVertex_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SimplexVertex(const void *in, zval *out)
{
	return box2d_b2SimplexVertex_to_zval(in, out);
}


zend_result box2d_b2Simplex_from_zval(zval *zv, b2Simplex *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Simplex) {
		zend_type_error("b2Simplex expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("v1"), box2d_from_slot_b2SimplexVertex, &out->v1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("v2"), box2d_from_slot_b2SimplexVertex, &out->v2, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("v3"), box2d_from_slot_b2SimplexVertex, &out->v3, frame) == FAILURE) return FAILURE;
	int count_bits;
	if (box2d_prop_i32(object, ZEND_STRL("count"), &count_bits) == FAILURE) return FAILURE;
	out->count = count_bits;
	return SUCCESS;
}

zend_result box2d_b2Simplex_to_zval(const b2Simplex *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Simplex);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("v1"), box2d_to_slot_b2SimplexVertex, &in->v1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("v2"), box2d_to_slot_b2SimplexVertex, &in->v2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("v3"), box2d_to_slot_b2SimplexVertex, &in->v3) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("count"), in->count);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Simplex(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Simplex_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Simplex(const void *in, zval *out)
{
	return box2d_b2Simplex_to_zval(in, out);
}


zend_result box2d_b2ShapeCastPairInput_from_zval(zval *zv, b2ShapeCastPairInput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ShapeCastPairInput) {
		zend_type_error("b2ShapeCastPairInput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("proxyA"), box2d_from_slot_b2ShapeProxy, &out->proxyA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("proxyB"), box2d_from_slot_b2ShapeProxy, &out->proxyB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("transformA"), box2d_from_slot_b2Transform, &out->transformA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("transformB"), box2d_from_slot_b2Transform, &out->transformB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("translationB"), box2d_from_slot_b2Vec2, &out->translationB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxFraction"), &out->maxFraction) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("canEncroach"), &out->canEncroach) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ShapeCastPairInput_to_zval(const b2ShapeCastPairInput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ShapeCastPairInput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("proxyA"), box2d_to_slot_b2ShapeProxy, &in->proxyA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("proxyB"), box2d_to_slot_b2ShapeProxy, &in->proxyB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("transformA"), box2d_to_slot_b2Transform, &in->transformA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("transformB"), box2d_to_slot_b2Transform, &in->transformB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("translationB"), box2d_to_slot_b2Vec2, &in->translationB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("maxFraction"), in->maxFraction);
	box2d_put_bool(object, ZEND_STRL("canEncroach"), in->canEncroach);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ShapeCastPairInput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ShapeCastPairInput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ShapeCastPairInput(const void *in, zval *out)
{
	return box2d_b2ShapeCastPairInput_to_zval(in, out);
}


zend_result box2d_b2Sweep_from_zval(zval *zv, b2Sweep *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Sweep) {
		zend_type_error("b2Sweep expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("localCenter"), box2d_from_slot_b2Vec2, &out->localCenter, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("c1"), box2d_from_slot_b2Vec2, &out->c1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("c2"), box2d_from_slot_b2Vec2, &out->c2, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("q1"), box2d_from_slot_b2Rot, &out->q1, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("q2"), box2d_from_slot_b2Rot, &out->q2, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Sweep_to_zval(const b2Sweep *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Sweep);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("localCenter"), box2d_to_slot_b2Vec2, &in->localCenter) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("c1"), box2d_to_slot_b2Vec2, &in->c1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("c2"), box2d_to_slot_b2Vec2, &in->c2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("q1"), box2d_to_slot_b2Rot, &in->q1) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("q2"), box2d_to_slot_b2Rot, &in->q2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2Sweep(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Sweep_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Sweep(const void *in, zval *out)
{
	return box2d_b2Sweep_to_zval(in, out);
}


zend_result box2d_b2TOIInput_from_zval(zval *zv, b2TOIInput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2TOIInput) {
		zend_type_error("b2TOIInput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("proxyA"), box2d_from_slot_b2ShapeProxy, &out->proxyA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("proxyB"), box2d_from_slot_b2ShapeProxy, &out->proxyB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("sweepA"), box2d_from_slot_b2Sweep, &out->sweepA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("sweepB"), box2d_from_slot_b2Sweep, &out->sweepB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxFraction"), &out->maxFraction) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2TOIInput_to_zval(const b2TOIInput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2TOIInput);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("proxyA"), box2d_to_slot_b2ShapeProxy, &in->proxyA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("proxyB"), box2d_to_slot_b2ShapeProxy, &in->proxyB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("sweepA"), box2d_to_slot_b2Sweep, &in->sweepA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("sweepB"), box2d_to_slot_b2Sweep, &in->sweepB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("maxFraction"), in->maxFraction);
	return SUCCESS;
}

zend_result box2d_from_slot_b2TOIInput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2TOIInput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2TOIInput(const void *in, zval *out)
{
	return box2d_b2TOIInput_to_zval(in, out);
}


zend_result box2d_b2TOIOutput_from_zval(zval *zv, b2TOIOutput *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2TOIOutput) {
		zend_type_error("b2TOIOutput expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int state_bits;
	if (box2d_prop_i32(object, ZEND_STRL("state"), &state_bits) == FAILURE) return FAILURE;
	out->state = state_bits;
	if (box2d_prop_f32(object, ZEND_STRL("fraction"), &out->fraction) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2TOIOutput_to_zval(const b2TOIOutput *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2TOIOutput);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("state"), in->state);
	box2d_put_f32(object, ZEND_STRL("fraction"), in->fraction);
	return SUCCESS;
}

zend_result box2d_from_slot_b2TOIOutput(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2TOIOutput_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2TOIOutput(const void *in, zval *out)
{
	return box2d_b2TOIOutput_to_zval(in, out);
}


zend_result box2d_b2ManifoldPoint_from_zval(zval *zv, b2ManifoldPoint *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ManifoldPoint) {
		zend_type_error("b2ManifoldPoint expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("point"), box2d_from_slot_b2Vec2, &out->point, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("anchorA"), box2d_from_slot_b2Vec2, &out->anchorA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("anchorB"), box2d_from_slot_b2Vec2, &out->anchorB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("separation"), &out->separation) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("normalImpulse"), &out->normalImpulse) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("tangentImpulse"), &out->tangentImpulse) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("totalNormalImpulse"), &out->totalNormalImpulse) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("normalVelocity"), &out->normalVelocity) == FAILURE) return FAILURE;
	if (box2d_prop_u16(object, ZEND_STRL("id"), &out->id) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("persisted"), &out->persisted) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ManifoldPoint_to_zval(const b2ManifoldPoint *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ManifoldPoint);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("point"), box2d_to_slot_b2Vec2, &in->point) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("anchorA"), box2d_to_slot_b2Vec2, &in->anchorA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("anchorB"), box2d_to_slot_b2Vec2, &in->anchorB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("separation"), in->separation);
	box2d_put_f32(object, ZEND_STRL("normalImpulse"), in->normalImpulse);
	box2d_put_f32(object, ZEND_STRL("tangentImpulse"), in->tangentImpulse);
	box2d_put_f32(object, ZEND_STRL("totalNormalImpulse"), in->totalNormalImpulse);
	box2d_put_f32(object, ZEND_STRL("normalVelocity"), in->normalVelocity);
	box2d_put_i32(object, ZEND_STRL("id"), in->id);
	box2d_put_bool(object, ZEND_STRL("persisted"), in->persisted);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ManifoldPoint(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ManifoldPoint_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ManifoldPoint(const void *in, zval *out)
{
	return box2d_b2ManifoldPoint_to_zval(in, out);
}


zend_result box2d_b2Manifold_from_zval(zval *zv, b2Manifold *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Manifold) {
		zend_type_error("b2Manifold expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int pointCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("pointCount"), &pointCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(pointCount_value, 2, "b2Manifold::$pointCount") == FAILURE) {
		return FAILURE;
	}
	if (box2d_prop_struct(object, ZEND_STRL("normal"), box2d_from_slot_b2Vec2, &out->normal, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("rollingImpulse"), &out->rollingImpulse) == FAILURE) return FAILURE;
	if (box2d_list_embedded(object, ZEND_STRL("points"), pointCount_value, out->points, sizeof(b2ManifoldPoint), box2d_from_slot_b2ManifoldPoint, frame) == FAILURE) return FAILURE;
	out->pointCount = pointCount_value;
	return SUCCESS;
}

zend_result box2d_b2Manifold_to_zval(const b2Manifold *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Manifold);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("normal"), box2d_to_slot_b2Vec2, &in->normal) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("rollingImpulse"), in->rollingImpulse);
	if (box2d_put_struct_list(object, ZEND_STRL("points"), in->pointCount, in->points, sizeof(b2ManifoldPoint), box2d_to_slot_b2ManifoldPoint) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("pointCount"), in->pointCount);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Manifold(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Manifold_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Manifold(const void *in, zval *out)
{
	return box2d_b2Manifold_to_zval(in, out);
}


zend_result box2d_b2TreeStats_from_zval(zval *zv, b2TreeStats *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2TreeStats) {
		zend_type_error("b2TreeStats expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int nodeVisits_bits;
	if (box2d_prop_i32(object, ZEND_STRL("nodeVisits"), &nodeVisits_bits) == FAILURE) return FAILURE;
	out->nodeVisits = nodeVisits_bits;
	int leafVisits_bits;
	if (box2d_prop_i32(object, ZEND_STRL("leafVisits"), &leafVisits_bits) == FAILURE) return FAILURE;
	out->leafVisits = leafVisits_bits;
	return SUCCESS;
}

zend_result box2d_b2TreeStats_to_zval(const b2TreeStats *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2TreeStats);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("nodeVisits"), in->nodeVisits);
	box2d_put_i32(object, ZEND_STRL("leafVisits"), in->leafVisits);
	return SUCCESS;
}

zend_result box2d_from_slot_b2TreeStats(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2TreeStats_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2TreeStats(const void *in, zval *out)
{
	return box2d_b2TreeStats_to_zval(in, out);
}


zend_result box2d_b2PlaneResult_from_zval(zval *zv, b2PlaneResult *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2PlaneResult) {
		zend_type_error("b2PlaneResult expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("plane"), box2d_from_slot_b2Plane, &out->plane, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("point"), box2d_from_slot_b2Vec2, &out->point, frame) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("hit"), &out->hit) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2PlaneResult_to_zval(const b2PlaneResult *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2PlaneResult);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("plane"), box2d_to_slot_b2Plane, &in->plane) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("point"), box2d_to_slot_b2Vec2, &in->point) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_bool(object, ZEND_STRL("hit"), in->hit);
	return SUCCESS;
}

zend_result box2d_from_slot_b2PlaneResult(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2PlaneResult_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2PlaneResult(const void *in, zval *out)
{
	return box2d_b2PlaneResult_to_zval(in, out);
}


zend_result box2d_b2CollisionPlane_from_zval(zval *zv, b2CollisionPlane *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2CollisionPlane) {
		zend_type_error("b2CollisionPlane expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("plane"), box2d_from_slot_b2Plane, &out->plane, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("pushLimit"), &out->pushLimit) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("push"), &out->push) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("clipVelocity"), &out->clipVelocity) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2CollisionPlane_to_zval(const b2CollisionPlane *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2CollisionPlane);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("plane"), box2d_to_slot_b2Plane, &in->plane) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("pushLimit"), in->pushLimit);
	box2d_put_f32(object, ZEND_STRL("push"), in->push);
	box2d_put_bool(object, ZEND_STRL("clipVelocity"), in->clipVelocity);
	return SUCCESS;
}

zend_result box2d_from_slot_b2CollisionPlane(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2CollisionPlane_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2CollisionPlane(const void *in, zval *out)
{
	return box2d_b2CollisionPlane_to_zval(in, out);
}


zend_result box2d_b2PlaneSolverResult_from_zval(zval *zv, b2PlaneSolverResult *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2PlaneSolverResult) {
		zend_type_error("b2PlaneSolverResult expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("translation"), box2d_from_slot_b2Vec2, &out->translation, frame) == FAILURE) return FAILURE;
	int iterationCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("iterationCount"), &iterationCount_bits) == FAILURE) return FAILURE;
	out->iterationCount = iterationCount_bits;
	return SUCCESS;
}

zend_result box2d_b2PlaneSolverResult_to_zval(const b2PlaneSolverResult *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2PlaneSolverResult);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("translation"), box2d_to_slot_b2Vec2, &in->translation) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("iterationCount"), in->iterationCount);
	return SUCCESS;
}

zend_result box2d_from_slot_b2PlaneSolverResult(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2PlaneSolverResult_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2PlaneSolverResult(const void *in, zval *out)
{
	return box2d_b2PlaneSolverResult_to_zval(in, out);
}

