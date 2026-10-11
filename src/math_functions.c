#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "runtime.h"
#include "classes.h"
#include "convert.h"

#include "zend_exceptions.h"

#include <stdint.h>

static zend_result box2d_read_b2Vec2(zval *zv, b2Vec2 *out)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = box2d_b2Vec2_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_b2Rot(zval *zv, b2Rot *out)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = box2d_b2Rot_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_b2Transform(zval *zv, b2Transform *out)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = box2d_b2Transform_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_b2Mat22(zval *zv, b2Mat22 *out)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = box2d_b2Mat22_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_b2AABB(zval *zv, b2AABB *out)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = box2d_b2AABB_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_b2Plane(zval *zv, b2Plane *out)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = box2d_b2Plane_from_zval(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_read_i32(zend_long value, int *out, const char *where)
{
	if (value < INT32_MIN || value > INT32_MAX) {
		zend_value_error("%s %lld is outside %lld..%lld", where, (long long) value, (long long) INT32_MIN, (long long) INT32_MAX);
		return FAILURE;
	}
	*out = (int) value;
	return SUCCESS;
}

static zend_result box2d_finish_float(float value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	ZVAL_DOUBLE(return_value, (double) value);
	return SUCCESS;
}

static zend_result box2d_finish_bool(bool value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	ZVAL_BOOL(return_value, value);
	return SUCCESS;
}

static zend_result box2d_finish_long(zend_long value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	ZVAL_LONG(return_value, value);
	return SUCCESS;
}

static zend_result box2d_finish_vec2(const b2Vec2 *value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return box2d_b2Vec2_to_zval(value, return_value);
}

static zend_result box2d_finish_rot(const b2Rot *value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return box2d_b2Rot_to_zval(value, return_value);
}

static zend_result box2d_finish_transform(const b2Transform *value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return box2d_b2Transform_to_zval(value, return_value);
}

static zend_result box2d_finish_mat22(const b2Mat22 *value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return box2d_b2Mat22_to_zval(value, return_value);
}

static zend_result box2d_finish_aabb(const b2AABB *value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return box2d_b2AABB_to_zval(value, return_value);
}

static zend_result box2d_finish_cossin(const b2CosSin *value, zval *return_value)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return box2d_b2CosSin_to_zval(value, return_value);
}

static zend_result box2d_finish_void(void)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return SUCCESS;
}
ZEND_FUNCTION(b2Vec2_zero)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2Vec2 value = b2Vec2_zero;
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Rot_identity)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2Rot value = b2Rot_identity;
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Transform_identity)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2Transform value = b2Transform_identity;
	if (box2d_finish_transform(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Mat22_zero)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2Mat22 value = b2Mat22_zero;
	if (box2d_finish_mat22(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsValidFloat)
{
	double a;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(a)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_bool(b2IsValidFloat((float) a), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsValidVec2)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2IsValidVec2(v), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsValidRotation)
{
	zval *q_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2IsValidRotation(q), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsValidAABB)
{
	zval *a_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2AABB a;
	if (box2d_read_b2AABB(a_zv, &a) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2IsValidAABB(a), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsValidPlane)
{
	zval *a_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Plane)
	ZEND_PARSE_PARAMETERS_END();

	b2Plane a;
	if (box2d_read_b2Plane(a_zv, &a) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2IsValidPlane(a), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MinInt)
{
	zend_long a_in;
	zend_long b_in;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(a_in)
		Z_PARAM_LONG(b_in)
	ZEND_PARSE_PARAMETERS_END();

	int a;
	int b;
	if (box2d_read_i32(a_in, &a, "b2MinInt a") == FAILURE || box2d_read_i32(b_in, &b, "b2MinInt b") == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_long(b2MinInt(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MaxInt)
{
	zend_long a_in;
	zend_long b_in;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(a_in)
		Z_PARAM_LONG(b_in)
	ZEND_PARSE_PARAMETERS_END();

	int a;
	int b;
	if (box2d_read_i32(a_in, &a, "b2MaxInt a") == FAILURE || box2d_read_i32(b_in, &b, "b2MaxInt b") == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_long(b2MaxInt(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AbsInt)
{
	zend_long a_in;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(a_in)
	ZEND_PARSE_PARAMETERS_END();

	int a;
	if (box2d_read_i32(a_in, &a, "b2AbsInt a") == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_long(b2AbsInt(a), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ClampInt)
{
	zend_long a_in;
	zend_long lower_in;
	zend_long upper_in;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(a_in)
		Z_PARAM_LONG(lower_in)
		Z_PARAM_LONG(upper_in)
	ZEND_PARSE_PARAMETERS_END();

	int a;
	int lower;
	int upper;
	if (box2d_read_i32(a_in, &a, "b2ClampInt a") == FAILURE
		|| box2d_read_i32(lower_in, &lower, "b2ClampInt lower") == FAILURE
		|| box2d_read_i32(upper_in, &upper, "b2ClampInt upper") == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_long(b2ClampInt(a, lower, upper), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MinFloat)
{
	double a;
	double b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(a)
		Z_PARAM_DOUBLE(b)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2MinFloat((float) a, (float) b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MaxFloat)
{
	double a;
	double b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(a)
		Z_PARAM_DOUBLE(b)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2MaxFloat((float) a, (float) b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AbsFloat)
{
	double a;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(a)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2AbsFloat((float) a), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ClampFloat)
{
	double a;
	double lower;
	double upper;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(a)
		Z_PARAM_DOUBLE(lower)
		Z_PARAM_DOUBLE(upper)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2ClampFloat((float) a, (float) lower, (float) upper), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Atan2)
{
	double y;
	double x;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2Atan2((float) y, (float) x), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ComputeCosSin)
{
	double radians;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(radians)
	ZEND_PARSE_PARAMETERS_END();

	b2CosSin value = b2ComputeCosSin((float) radians);
	if (box2d_finish_cossin(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Dot)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2Dot(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Cross)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2Cross(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2CrossVS)
{
	zval *v_zv;
	double s;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(s)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2CrossVS(v, (float) s);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2CrossSV)
{
	double s;
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(s)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2CrossSV((float) s, v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2LeftPerp)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2LeftPerp(v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2RightPerp)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2RightPerp(v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Neg)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Neg(v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Abs)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Abs(v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Normalize)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Normalize(v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Add)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Add(a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Sub)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Sub(a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Lerp)
{
	zval *a_zv;
	zval *b_zv;
	double t;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(t)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Lerp(a, b, (float) t);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Mul)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Mul(a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MulSV)
{
	double s;
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(s)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2MulSV((float) s, v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MulAdd)
{
	zval *a_zv;
	double s;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(s)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2MulAdd(a, (float) s, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MulSub)
{
	zval *a_zv;
	double s;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(s)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2MulSub(a, (float) s, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Min)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Min(a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Max)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Max(a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Clamp)
{
	zval *v_zv;
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE || box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Clamp(v, a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Length)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2Length(v), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Distance)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2Distance(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsNormalized)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2IsNormalized(v), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2GetLengthAndNormalize)
{
	zval *length_zv;
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(length_zv)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	float length = 0.0f;
	b2Vec2 unit = b2GetLengthAndNormalize(&length, v);
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}

	ZVAL_DEREF(length_zv);
	ZVAL_DOUBLE(length_zv, (double) length);
	if (box2d_b2Vec2_to_zval(&unit, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2NormalizeRot)
{
	zval *q_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE) {
		RETURN_THROWS();
	}

	b2Rot value = b2NormalizeRot(q);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IntegrateRotation)
{
	zval *q1_zv;
	double delta_angle;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(q1_zv, box2d_ce_b2Rot)
		Z_PARAM_DOUBLE(delta_angle)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q1;
	if (box2d_read_b2Rot(q1_zv, &q1) == FAILURE) {
		RETURN_THROWS();
	}

	b2Rot value = b2IntegrateRotation(q1, (float) delta_angle);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2LengthSquared)
{
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v;
	if (box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2LengthSquared(v), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DistanceSquared)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 a;
	b2Vec2 b;
	if (box2d_read_b2Vec2(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2DistanceSquared(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2UnwindAngle)
{
	double radians;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(radians)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2UnwindAngle((float) radians), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MakeRot)
{
	double radians;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(radians)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot value = b2MakeRot((float) radians);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ComputeRotationBetweenUnitVectors)
{
	zval *v1_zv;
	zval *v2_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(v1_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(v2_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 v1;
	b2Vec2 v2;
	if (box2d_read_b2Vec2(v1_zv, &v1) == FAILURE || box2d_read_b2Vec2(v2_zv, &v2) == FAILURE) {
		RETURN_THROWS();
	}

	b2Rot value = b2ComputeRotationBetweenUnitVectors(v1, v2);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2IsNormalizedRot)
{
	zval *q_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2IsNormalizedRot(q), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2NLerp)
{
	zval *q1_zv;
	zval *q2_zv;
	double t;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(q1_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(q2_zv, box2d_ce_b2Rot)
		Z_PARAM_DOUBLE(t)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q1;
	b2Rot q2;
	if (box2d_read_b2Rot(q1_zv, &q1) == FAILURE || box2d_read_b2Rot(q2_zv, &q2) == FAILURE) {
		RETURN_THROWS();
	}

	b2Rot value = b2NLerp(q1, q2, (float) t);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ComputeAngularVelocity)
{
	zval *q1_zv;
	zval *q2_zv;
	double inv_h;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(q1_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(q2_zv, box2d_ce_b2Rot)
		Z_PARAM_DOUBLE(inv_h)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q1;
	b2Rot q2;
	if (box2d_read_b2Rot(q1_zv, &q1) == FAILURE || box2d_read_b2Rot(q2_zv, &q2) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2ComputeAngularVelocity(q1, q2, (float) inv_h), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Rot_GetAngle)
{
	zval *q_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2Rot_GetAngle(q), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Rot_GetXAxis)
{
	zval *q_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Rot_GetXAxis(q);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Rot_GetYAxis)
{
	zval *q_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Rot_GetYAxis(q);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MulRot)
{
	zval *q_zv;
	zval *r_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(r_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	b2Rot r;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE || box2d_read_b2Rot(r_zv, &r) == FAILURE) {
		RETURN_THROWS();
	}

	b2Rot value = b2MulRot(q, r);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2InvMulRot)
{
	zval *q_zv;
	zval *r_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(r_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	b2Rot r;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE || box2d_read_b2Rot(r_zv, &r) == FAILURE) {
		RETURN_THROWS();
	}

	b2Rot value = b2InvMulRot(q, r);
	if (box2d_finish_rot(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2RelativeAngle)
{
	zval *b_zv;
	zval *a_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot b;
	b2Rot a;
	if (box2d_read_b2Rot(b_zv, &b) == FAILURE || box2d_read_b2Rot(a_zv, &a) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2RelativeAngle(b, a), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2RotateVector)
{
	zval *q_zv;
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	b2Vec2 v;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE || box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2RotateVector(q, v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2InvRotateVector)
{
	zval *q_zv;
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(q_zv, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Rot q;
	b2Vec2 v;
	if (box2d_read_b2Rot(q_zv, &q) == FAILURE || box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2InvRotateVector(q, v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2TransformPoint)
{
	zval *t_zv;
	zval *p_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(t_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(p_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Transform t;
	b2Vec2 p;
	if (box2d_read_b2Transform(t_zv, &t) == FAILURE || box2d_read_b2Vec2(p_zv, &p) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2TransformPoint(t, p);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2InvTransformPoint)
{
	zval *t_zv;
	zval *p_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(t_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(p_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Transform t;
	b2Vec2 p;
	if (box2d_read_b2Transform(t_zv, &t) == FAILURE || box2d_read_b2Vec2(p_zv, &p) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2InvTransformPoint(t, p);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MulTransforms)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Transform a;
	b2Transform b;
	if (box2d_read_b2Transform(a_zv, &a) == FAILURE || box2d_read_b2Transform(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Transform value = b2MulTransforms(a, b);
	if (box2d_finish_transform(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2InvMulTransforms)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Transform a;
	b2Transform b;
	if (box2d_read_b2Transform(a_zv, &a) == FAILURE || box2d_read_b2Transform(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Transform value = b2InvMulTransforms(a, b);
	if (box2d_finish_transform(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MulMV)
{
	zval *a_zv;
	zval *v_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Mat22)
		Z_PARAM_OBJECT_OF_CLASS(v_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Mat22 a;
	b2Vec2 v;
	if (box2d_read_b2Mat22(a_zv, &a) == FAILURE || box2d_read_b2Vec2(v_zv, &v) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2MulMV(a, v);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2GetInverse22)
{
	zval *a_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Mat22)
	ZEND_PARSE_PARAMETERS_END();

	b2Mat22 a;
	if (box2d_read_b2Mat22(a_zv, &a) == FAILURE) {
		RETURN_THROWS();
	}

	b2Mat22 value = b2GetInverse22(a);
	if (box2d_finish_mat22(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Solve22)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2Mat22)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Mat22 a;
	b2Vec2 b;
	if (box2d_read_b2Mat22(a_zv, &a) == FAILURE || box2d_read_b2Vec2(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2Solve22(a, b);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AABB_Contains)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2AABB)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2AABB a;
	b2AABB b;
	if (box2d_read_b2AABB(a_zv, &a) == FAILURE || box2d_read_b2AABB(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2AABB_Contains(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AABB_Center)
{
	zval *a_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2AABB a;
	if (box2d_read_b2AABB(a_zv, &a) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2AABB_Center(a);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AABB_Extents)
{
	zval *a_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2AABB a;
	if (box2d_read_b2AABB(a_zv, &a) == FAILURE) {
		RETURN_THROWS();
	}

	b2Vec2 value = b2AABB_Extents(a);
	if (box2d_finish_vec2(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AABB_Union)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2AABB)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2AABB a;
	b2AABB b;
	if (box2d_read_b2AABB(a_zv, &a) == FAILURE || box2d_read_b2AABB(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	b2AABB value = b2AABB_Union(a, b);
	if (box2d_finish_aabb(&value, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2AABB_Overlaps)
{
	zval *a_zv;
	zval *b_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(a_zv, box2d_ce_b2AABB)
		Z_PARAM_OBJECT_OF_CLASS(b_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2AABB a;
	b2AABB b;
	if (box2d_read_b2AABB(a_zv, &a) == FAILURE || box2d_read_b2AABB(b_zv, &b) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_bool(b2AABB_Overlaps(a, b), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2MakeAABB)
{
	HashTable *points;
	zend_long count_in;
	double radius;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY_HT(points)
		Z_PARAM_LONG(count_in)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	if (!zend_array_is_list(points)) {
		zend_value_error("b2MakeAABB points must be a list");
		RETURN_THROWS();
	}

	zend_long available = (zend_long) zend_hash_num_elements(points);
	if (count_in < 1 || count_in > available || count_in > INT32_MAX) {
		zend_value_error("b2MakeAABB count %lld is outside 1..%lld", (long long) count_in, (long long) available);
		RETURN_THROWS();
	}

	b2Vec2 *native = safe_emalloc((size_t) count_in, sizeof(b2Vec2), 0);
	for (zend_long index = 0; index < count_in; index++) {
		zval *item = zend_hash_index_find(points, (zend_ulong) index);
		if (item == NULL || box2d_read_b2Vec2(item, &native[index]) == FAILURE) {
			efree(native);
			if (!EG(exception)) {
				zend_value_error("b2MakeAABB points is shorter than count");
			}
			RETURN_THROWS();
		}
	}

	b2AABB box = b2MakeAABB(native, (int) count_in, (float) radius);
	efree(native);
	if (box2d_finish_aabb(&box, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2PlaneSeparation)
{
	zval *plane_zv;
	zval *point_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(plane_zv, box2d_ce_b2Plane)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Plane plane;
	b2Vec2 point;
	if (box2d_read_b2Plane(plane_zv, &plane) == FAILURE || box2d_read_b2Vec2(point_zv, &point) == FAILURE) {
		RETURN_THROWS();
	}

	if (box2d_finish_float(b2PlaneSeparation(plane, point), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2SpringDamper)
{
	double hertz;
	double damping_ratio;
	double position;
	double velocity;
	double time_step;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_DOUBLE(hertz)
		Z_PARAM_DOUBLE(damping_ratio)
		Z_PARAM_DOUBLE(position)
		Z_PARAM_DOUBLE(velocity)
		Z_PARAM_DOUBLE(time_step)
	ZEND_PARSE_PARAMETERS_END();

	if (box2d_finish_float(b2SpringDamper((float) hertz, (float) damping_ratio, (float) position, (float) velocity, (float) time_step), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2SetLengthUnitsPerMeter)
{
	double length_units;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(length_units)
	ZEND_PARSE_PARAMETERS_END();

	b2SetLengthUnitsPerMeter((float) length_units);
	if (box2d_finish_void() == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2GetLengthUnitsPerMeter)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if (box2d_finish_float(b2GetLengthUnitsPerMeter(), return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

