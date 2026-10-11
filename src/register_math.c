#include "convert.h"
#include "classes.h"

#include "../stubs/math_functions_arginfo.h"

zend_class_entry *box2d_ce_b2Vec2;
zend_class_entry *box2d_ce_b2CosSin;
zend_class_entry *box2d_ce_b2Rot;
zend_class_entry *box2d_ce_b2Transform;
zend_class_entry *box2d_ce_b2Mat22;
zend_class_entry *box2d_ce_b2AABB;
zend_class_entry *box2d_ce_b2Plane;

ZEND_METHOD(b2Vec2, __construct)
{
	double x = 0.0;
	double y = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_double(box2d_ce_b2Vec2, Z_OBJ_P(ZEND_THIS), ZEND_STRL("x"), x);

	zend_update_property_double(box2d_ce_b2Vec2, Z_OBJ_P(ZEND_THIS), ZEND_STRL("y"), y);

	b2Vec2 native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Vec2_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2CosSin, __construct)
{
	double cosine = 0.0;
	double sine = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(cosine)
		Z_PARAM_DOUBLE(sine)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_double(box2d_ce_b2CosSin, Z_OBJ_P(ZEND_THIS), ZEND_STRL("cosine"), cosine);

	zend_update_property_double(box2d_ce_b2CosSin, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sine"), sine);

	b2CosSin native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2CosSin_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Rot, __construct)
{
	double c = 0.0;
	double s = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(c)
		Z_PARAM_DOUBLE(s)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_double(box2d_ce_b2Rot, Z_OBJ_P(ZEND_THIS), ZEND_STRL("c"), c);

	zend_update_property_double(box2d_ce_b2Rot, Z_OBJ_P(ZEND_THIS), ZEND_STRL("s"), s);

	b2Rot native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Rot_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Transform, __construct)
{
	zval *p = NULL;
	zval *q = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(p, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(q, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	if (p == NULL) {
		zval created_p;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_p) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Transform, Z_OBJ_P(ZEND_THIS), ZEND_STRL("p"), &created_p);
		zval_ptr_dtor(&created_p);
	} else {
		zend_update_property(box2d_ce_b2Transform, Z_OBJ_P(ZEND_THIS), ZEND_STRL("p"), p);
	}

	if (q == NULL) {
		zval created_q;
		if (box2d_new_default(box2d_ce_b2Rot, &created_q) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Transform, Z_OBJ_P(ZEND_THIS), ZEND_STRL("q"), &created_q);
		zval_ptr_dtor(&created_q);
	} else {
		zend_update_property(box2d_ce_b2Transform, Z_OBJ_P(ZEND_THIS), ZEND_STRL("q"), q);
	}

	b2Transform native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Transform_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Mat22, __construct)
{
	zval *cx = NULL;
	zval *cy = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(cx, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(cy, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	if (cx == NULL) {
		zval created_cx;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_cx) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Mat22, Z_OBJ_P(ZEND_THIS), ZEND_STRL("cx"), &created_cx);
		zval_ptr_dtor(&created_cx);
	} else {
		zend_update_property(box2d_ce_b2Mat22, Z_OBJ_P(ZEND_THIS), ZEND_STRL("cx"), cx);
	}

	if (cy == NULL) {
		zval created_cy;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_cy) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Mat22, Z_OBJ_P(ZEND_THIS), ZEND_STRL("cy"), &created_cy);
		zval_ptr_dtor(&created_cy);
	} else {
		zend_update_property(box2d_ce_b2Mat22, Z_OBJ_P(ZEND_THIS), ZEND_STRL("cy"), cy);
	}

	b2Mat22 native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Mat22_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2AABB, __construct)
{
	zval *lowerBound = NULL;
	zval *upperBound = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(lowerBound, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(upperBound, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	if (lowerBound == NULL) {
		zval created_lowerBound;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_lowerBound) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2AABB, Z_OBJ_P(ZEND_THIS), ZEND_STRL("lowerBound"), &created_lowerBound);
		zval_ptr_dtor(&created_lowerBound);
	} else {
		zend_update_property(box2d_ce_b2AABB, Z_OBJ_P(ZEND_THIS), ZEND_STRL("lowerBound"), lowerBound);
	}

	if (upperBound == NULL) {
		zval created_upperBound;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_upperBound) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2AABB, Z_OBJ_P(ZEND_THIS), ZEND_STRL("upperBound"), &created_upperBound);
		zval_ptr_dtor(&created_upperBound);
	} else {
		zend_update_property(box2d_ce_b2AABB, Z_OBJ_P(ZEND_THIS), ZEND_STRL("upperBound"), upperBound);
	}

	b2AABB native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2AABB_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Plane, __construct)
{
	zval *normal = NULL;
	double offset = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(normal, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(offset)
	ZEND_PARSE_PARAMETERS_END();

	if (normal == NULL) {
		zval created_normal;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_normal) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Plane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), &created_normal);
		zval_ptr_dtor(&created_normal);
	} else {
		zend_update_property(box2d_ce_b2Plane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), normal);
	}

	zend_update_property_double(box2d_ce_b2Plane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("offset"), offset);

	b2Plane native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Plane_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

void box2d_register_math(int module_number)
{
	box2d_ce_b2Vec2 = register_class_b2Vec2();
	box2d_class_is_value(box2d_ce_b2Vec2);
	box2d_ce_b2CosSin = register_class_b2CosSin();
	box2d_class_is_value(box2d_ce_b2CosSin);
	box2d_ce_b2Rot = register_class_b2Rot();
	box2d_class_is_value(box2d_ce_b2Rot);
	box2d_ce_b2Transform = register_class_b2Transform();
	box2d_class_is_value(box2d_ce_b2Transform);
	box2d_ce_b2Mat22 = register_class_b2Mat22();
	box2d_class_is_value(box2d_ce_b2Mat22);
	box2d_ce_b2AABB = register_class_b2AABB();
	box2d_class_is_value(box2d_ce_b2AABB);
	box2d_ce_b2Plane = register_class_b2Plane();
	box2d_class_is_value(box2d_ce_b2Plane);
	register_math_functions_symbols(module_number);
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
}
