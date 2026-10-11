#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "runtime.h"
#include "classes.h"
#include "convert.h"

#include "zend_exceptions.h"

#include <stdint.h>
#include <string.h>

static zend_result box2d_read(zval *zv, void *out, box2d_from_fn from)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = from(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static zend_result box2d_finish(void)
{
	if (EG(exception)) {
		return FAILURE;
	}
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return SUCCESS;
}

static zend_result box2d_i32_arg(zend_long value, int *out, const char *where)
{
	if (value < INT32_MIN || value > INT32_MAX) {
		zend_value_error("%s %lld is outside %lld..%lld", where, (long long) value, (long long) INT32_MIN, (long long) INT32_MAX);
		return FAILURE;
	}
	*out = (int) value;
	return SUCCESS;
}

static zend_result box2d_read_points(HashTable *list, zend_long count, const char *what, b2Vec2 **out)
{
	if (!zend_array_is_list(list)) {
		zend_value_error("%s must be a list", what);
		return FAILURE;
	}

	zend_long available = (zend_long) zend_hash_num_elements(list);
	if (count < 0 || count > available || count > INT32_MAX) {
		zend_value_error("%s count %lld is outside 0..%lld", what, (long long) count, (long long) available);
		return FAILURE;
	}

	b2Vec2 *points = NULL;
	if (count > 0) {
		points = safe_emalloc((size_t) count, sizeof(b2Vec2), 0);
		for (zend_long index = 0; index < count; index++) {
			zval *item = zend_hash_index_find(list, (zend_ulong) index);
			if (item == NULL || box2d_read(item, &points[index], box2d_from_slot_b2Vec2) == FAILURE) {
				efree(points);
				if (!EG(exception)) {
					zend_value_error("%s is shorter than count", what);
				}
				return FAILURE;
			}
		}
	}

	*out = points;
	return SUCCESS;
}

static zend_result box2d_read_planes(HashTable *list, zend_long count, b2CollisionPlane **out)
{
	if (!zend_array_is_list(list)) {
		zend_value_error("b2CollisionPlane list must be a list");
		return FAILURE;
	}

	zend_long available = (zend_long) zend_hash_num_elements(list);
	if (count < 0 || count > available || count > INT32_MAX) {
		zend_value_error("b2CollisionPlane count %lld is outside 0..%lld", (long long) count, (long long) available);
		return FAILURE;
	}

	b2CollisionPlane *planes = NULL;
	if (count > 0) {
		planes = safe_emalloc((size_t) count, sizeof(b2CollisionPlane), 0);
		for (zend_long index = 0; index < count; index++) {
			zval *item = zend_hash_index_find(list, (zend_ulong) index);
			if (item == NULL) {
				efree(planes);
				zend_value_error("b2CollisionPlane list is shorter than count");
				return FAILURE;
			}
			ZVAL_DEREF(item);
			if (box2d_read(item, &planes[index], box2d_from_slot_b2CollisionPlane) == FAILURE) {
				efree(planes);
				return FAILURE;
			}
		}
	}

	*out = planes;
	return SUCCESS;
}

static void box2d_store_pushes(HashTable *list, const b2CollisionPlane *planes, zend_long count)
{
	for (zend_long index = 0; index < count; index++) {
		zval *item = zend_hash_index_find(list, (zend_ulong) index);
		ZVAL_DEREF(item);
		box2d_put_f32(Z_OBJ_P(item), ZEND_STRL("push"), planes[index].push);
	}
}

static void box2d_store_cache(zval *zv, const b2SimplexCache *cache)
{
	zend_object *object = Z_OBJ_P(zv);
	box2d_put_i32(object, ZEND_STRL("count"), (int) cache->count);
	box2d_put_u8_list(object, ZEND_STRL("indexA"), 3, cache->indexA);
	box2d_put_u8_list(object, ZEND_STRL("indexB"), 3, cache->indexB);
}

static zend_result box2d_store_simplexes(zval *dest, const b2Simplex *simplexes, int count)
{
	zval list;

	array_init_size(&list, count > 0 ? (uint32_t) count : 0);
	for (int index = 0; index < count; index++) {
		zval item;
		if (box2d_b2Simplex_to_zval(&simplexes[index], &item) == FAILURE) {
			zval_ptr_dtor(&list);
			return FAILURE;
		}
		add_next_index_zval(&list, &item);
	}

	ZVAL_DEREF(dest);
	zval_ptr_dtor(dest);
	ZVAL_COPY_VALUE(dest, &list);
	return SUCCESS;
}

static zend_result box2d_live_tree(zval *zv, b2DynamicTree **out)
{
	if (!box2d_tree_is_live(Z_OBJ_P(zv))) {
		zend_value_error("b2DynamicTree is not live");
		return FAILURE;
	}
	*out = box2d_tree_native(Z_OBJ_P(zv));
	return SUCCESS;
}

typedef struct box2d_tree_call {
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	bool failed;
} box2d_tree_call;

static bool box2d_call_user(box2d_tree_call *call, zval *args, uint32_t argc, zval *retval)
{
	if (EG(exception) || call->failed) {
		return false;
	}

	ZVAL_UNDEF(retval);
	call->fci.retval = retval;
	call->fci.params = args;
	call->fci.param_count = argc;
	call->fci.named_params = NULL;
	if (zend_call_function(&call->fci, &call->fcc) == FAILURE) {
		call->failed = true;
		if (!EG(exception)) {
			zend_throw_error(NULL, "dynamic tree callback failed");
		}
		return false;
	}
	if (EG(exception)) {
		call->failed = true;
		return false;
	}
	return true;
}

static zend_result box2d_callback_bool(zval *retval, bool *out)
{
	ZVAL_DEREF(retval);
	switch (Z_TYPE_P(retval)) {
		case IS_TRUE:
		case IS_FALSE:
		case IS_LONG:
		case IS_DOUBLE:
		case IS_NULL:
		case IS_STRING:
			*out = zend_is_true(retval);
			return SUCCESS;
		default:
			zend_type_error("b2DynamicTree_Query callback must return bool");
			return FAILURE;
	}
}

static zend_result box2d_callback_float(zval *retval, float *out, const char *where)
{
	ZVAL_DEREF(retval);
	switch (Z_TYPE_P(retval)) {
		case IS_TRUE:
		case IS_FALSE:
		case IS_LONG:
		case IS_DOUBLE:
			*out = (float) zval_get_double(retval);
			return SUCCESS;
		case IS_NULL:
			*out = 0.0f;
			return SUCCESS;
		case IS_STRING:
			if (!is_numeric_string(Z_STRVAL_P(retval), Z_STRLEN_P(retval), NULL, NULL, 0)) {
				zend_type_error("%s callback must return float", where);
				return FAILURE;
			}
			*out = (float) zval_get_double(retval);
			return SUCCESS;
		default:
			zend_type_error("%s callback must return float", where);
			return FAILURE;
	}
}

static void box2d_release_retval(zval *retval)
{
	if (Z_TYPE_P(retval) != IS_UNDEF) {
		zval_ptr_dtor(retval);
	}
}

static bool box2d_tree_query_cb(int proxy_id, uint64_t user_data, void *context)
{
	box2d_tree_call *call = context;
	zval args[3];
	zval retval;
	bool keep = false;

	if (EG(exception) || call->failed) {
		return false;
	}

	ZVAL_LONG(&args[0], proxy_id);
	ZVAL_LONG(&args[1], (zend_long) user_data);
	ZVAL_COPY(&args[2], call->context);
	ZVAL_UNDEF(&retval);
	if (!box2d_call_user(call, args, 3, &retval)) {
		box2d_release_retval(&retval);
		zval_ptr_dtor(&args[2]);
		return false;
	}
	if (box2d_callback_bool(&retval, &keep) == FAILURE) {
		call->failed = true;
		keep = false;
	}
	zval_ptr_dtor(&retval);
	zval_ptr_dtor(&args[2]);
	return keep;
}

static float box2d_tree_ray_cb(const b2RayCastInput *input, int proxy_id, uint64_t user_data, void *context)
{
	box2d_tree_call *call = context;
	zval args[4];
	zval retval;
	float fraction = 0.0f;

	if (EG(exception) || call->failed) {
		return 0.0f;
	}
	if (box2d_b2RayCastInput_to_zval(input, &args[0]) == FAILURE) {
		call->failed = true;
		return 0.0f;
	}

	ZVAL_LONG(&args[1], proxy_id);
	ZVAL_LONG(&args[2], (zend_long) user_data);
	ZVAL_COPY(&args[3], call->context);
	ZVAL_UNDEF(&retval);
	if (box2d_call_user(call, args, 4, &retval)) {
		if (box2d_callback_float(&retval, &fraction, "b2DynamicTree_RayCast") == FAILURE) {
			call->failed = true;
			fraction = 0.0f;
		}
		zval_ptr_dtor(&retval);
	} else {
		box2d_release_retval(&retval);
	}
	zval_ptr_dtor(&args[0]);
	zval_ptr_dtor(&args[3]);
	return fraction;
}

static float box2d_tree_shape_cb(const b2ShapeCastInput *input, int proxy_id, uint64_t user_data, void *context)
{
	box2d_tree_call *call = context;
	zval args[4];
	zval retval;
	float fraction = 0.0f;

	if (EG(exception) || call->failed) {
		return 0.0f;
	}
	if (box2d_b2ShapeCastInput_to_zval(input, &args[0]) == FAILURE) {
		call->failed = true;
		return 0.0f;
	}

	ZVAL_LONG(&args[1], proxy_id);
	ZVAL_LONG(&args[2], (zend_long) user_data);
	ZVAL_COPY(&args[3], call->context);
	ZVAL_UNDEF(&retval);
	if (box2d_call_user(call, args, 4, &retval)) {
		if (box2d_callback_float(&retval, &fraction, "b2DynamicTree_ShapeCast") == FAILURE) {
			call->failed = true;
			fraction = 0.0f;
		}
		zval_ptr_dtor(&retval);
	} else {
		box2d_release_retval(&retval);
	}
	zval_ptr_dtor(&args[0]);
	zval_ptr_dtor(&args[3]);
	return fraction;
}

static void box2d_prepare_tree_call(box2d_tree_call *call, zend_fcall_info *fci, zend_fcall_info_cache *fcc, zval *context)
{
	ZVAL_DEREF(context);
	call->fci = *fci;
	call->fcc = *fcc;
	call->context = context;
	call->failed = false;
}

#define BOX2D_READ(zv, dest, from) \
	do { \
		if (box2d_read((zv), &(dest), (from)) == FAILURE) { \
			RETURN_THROWS(); \
		} \
	} while (0)

#define BOX2D_I32(value, dest, where) \
	do { \
		if (box2d_i32_arg((value), &(dest), (where)) == FAILURE) { \
			RETURN_THROWS(); \
		} \
	} while (0)

#define BOX2D_RETURN_CALL(to_zval, value) \
	do { \
		if (box2d_finish() == FAILURE || (to_zval)(&(value), return_value) == FAILURE) { \
			RETURN_THROWS(); \
		} \
	} while (0)

#define BOX2D_RETURN_BOOL(value) \
	do { \
		if (box2d_finish() == FAILURE) { \
			RETURN_THROWS(); \
		} \
		RETURN_BOOL(value); \
	} while (0)

#define BOX2D_RETURN_LONG(value) \
	do { \
		if (box2d_finish() == FAILURE) { \
			RETURN_THROWS(); \
		} \
		RETURN_LONG(value); \
	} while (0)

#define BOX2D_RETURN_DOUBLE(value) \
	do { \
		if (box2d_finish() == FAILURE) { \
			RETURN_THROWS(); \
		} \
		RETURN_DOUBLE(value); \
	} while (0)

#define BOX2D_RETURN_VOID() \
	do { \
		if (box2d_finish() == FAILURE) { \
			RETURN_THROWS(); \
		} \
	} while (0)

#define BOX2D_TREE(zv, dest) \
	do { \
		if (box2d_live_tree((zv), &(dest)) == FAILURE) { \
			RETURN_THROWS(); \
		} \
	} while (0)

ZEND_FUNCTION(b2_emptySimplexCache)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2SimplexCache cache = b2_emptySimplexCache;
	BOX2D_RETURN_CALL(box2d_b2SimplexCache_to_zval, cache);
}

ZEND_FUNCTION(b2IsValidRay)
{
	zval *input_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
	ZEND_PARSE_PARAMETERS_END();

	b2RayCastInput input;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2RayCastInput);
	BOX2D_RETURN_BOOL(b2IsValidRay(&input));
}

ZEND_FUNCTION(b2MakePolygon)
{
	zval *hull_zv;
	double radius;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hull_zv, box2d_ce_b2Hull)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	b2Hull hull;
	BOX2D_READ(hull_zv, hull, box2d_from_slot_b2Hull);
	b2Polygon shape = b2MakePolygon(&hull, (float) radius);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeOffsetPolygon)
{
	zval *hull_zv;
	zval *position_zv;
	zval *rotation_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(hull_zv, box2d_ce_b2Hull)
		Z_PARAM_OBJECT_OF_CLASS(position_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Hull hull;
	b2Vec2 position;
	b2Rot rotation;
	BOX2D_READ(hull_zv, hull, box2d_from_slot_b2Hull);
	BOX2D_READ(position_zv, position, box2d_from_slot_b2Vec2);
	BOX2D_READ(rotation_zv, rotation, box2d_from_slot_b2Rot);
	b2Polygon shape = b2MakeOffsetPolygon(&hull, position, rotation);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeOffsetRoundedPolygon)
{
	zval *hull_zv;
	zval *position_zv;
	zval *rotation_zv;
	double radius;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(hull_zv, box2d_ce_b2Hull)
		Z_PARAM_OBJECT_OF_CLASS(position_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation_zv, box2d_ce_b2Rot)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	b2Hull hull;
	b2Vec2 position;
	b2Rot rotation;
	BOX2D_READ(hull_zv, hull, box2d_from_slot_b2Hull);
	BOX2D_READ(position_zv, position, box2d_from_slot_b2Vec2);
	BOX2D_READ(rotation_zv, rotation, box2d_from_slot_b2Rot);
	b2Polygon shape = b2MakeOffsetRoundedPolygon(&hull, position, rotation, (float) radius);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeSquare)
{
	double half_width;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(half_width)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon shape = b2MakeSquare((float) half_width);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeBox)
{
	double half_width;
	double half_height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(half_width)
		Z_PARAM_DOUBLE(half_height)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon shape = b2MakeBox((float) half_width, (float) half_height);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeRoundedBox)
{
	double half_width;
	double half_height;
	double radius;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(half_width)
		Z_PARAM_DOUBLE(half_height)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon shape = b2MakeRoundedBox((float) half_width, (float) half_height, (float) radius);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeOffsetBox)
{
	double half_width;
	double half_height;
	zval *center_zv;
	zval *rotation_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_DOUBLE(half_width)
		Z_PARAM_DOUBLE(half_height)
		Z_PARAM_OBJECT_OF_CLASS(center_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 center;
	b2Rot rotation;
	BOX2D_READ(center_zv, center, box2d_from_slot_b2Vec2);
	BOX2D_READ(rotation_zv, rotation, box2d_from_slot_b2Rot);
	b2Polygon shape = b2MakeOffsetBox((float) half_width, (float) half_height, center, rotation);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2MakeOffsetRoundedBox)
{
	double half_width;
	double half_height;
	zval *center_zv;
	zval *rotation_zv;
	double radius;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_DOUBLE(half_width)
		Z_PARAM_DOUBLE(half_height)
		Z_PARAM_OBJECT_OF_CLASS(center_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation_zv, box2d_ce_b2Rot)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 center;
	b2Rot rotation;
	BOX2D_READ(center_zv, center, box2d_from_slot_b2Vec2);
	BOX2D_READ(rotation_zv, rotation, box2d_from_slot_b2Rot);
	b2Polygon shape = b2MakeOffsetRoundedBox((float) half_width, (float) half_height, center, rotation, (float) radius);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2TransformPolygon)
{
	zval *transform_zv;
	zval *polygon_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(transform_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
	ZEND_PARSE_PARAMETERS_END();

	b2Transform transform;
	b2Polygon polygon;
	BOX2D_READ(transform_zv, transform, box2d_from_slot_b2Transform);
	BOX2D_READ(polygon_zv, polygon, box2d_from_slot_b2Polygon);
	b2Polygon shape = b2TransformPolygon(transform, &polygon);
	BOX2D_RETURN_CALL(box2d_b2Polygon_to_zval, shape);
}

ZEND_FUNCTION(b2ComputeCircleMass)
{
	zval *shape_zv;
	double density;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Circle)
		Z_PARAM_DOUBLE(density)
	ZEND_PARSE_PARAMETERS_END();

	b2Circle shape;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Circle);
	b2MassData mass = b2ComputeCircleMass(&shape, (float) density);
	BOX2D_RETURN_CALL(box2d_b2MassData_to_zval, mass);
}

ZEND_FUNCTION(b2ComputeCapsuleMass)
{
	zval *shape_zv;
	double density;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Capsule)
		Z_PARAM_DOUBLE(density)
	ZEND_PARSE_PARAMETERS_END();

	b2Capsule shape;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Capsule);
	b2MassData mass = b2ComputeCapsuleMass(&shape, (float) density);
	BOX2D_RETURN_CALL(box2d_b2MassData_to_zval, mass);
}

ZEND_FUNCTION(b2ComputePolygonMass)
{
	zval *shape_zv;
	double density;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Polygon)
		Z_PARAM_DOUBLE(density)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon shape;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Polygon);
	b2MassData mass = b2ComputePolygonMass(&shape, (float) density);
	BOX2D_RETURN_CALL(box2d_b2MassData_to_zval, mass);
}

ZEND_FUNCTION(b2ComputeCircleAABB)
{
	zval *shape_zv;
	zval *transform_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(transform_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Circle shape;
	b2Transform transform;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Circle);
	BOX2D_READ(transform_zv, transform, box2d_from_slot_b2Transform);
	b2AABB box = b2ComputeCircleAABB(&shape, transform);
	BOX2D_RETURN_CALL(box2d_b2AABB_to_zval, box);
}

ZEND_FUNCTION(b2ComputeCapsuleAABB)
{
	zval *shape_zv;
	zval *transform_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(transform_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Capsule shape;
	b2Transform transform;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Capsule);
	BOX2D_READ(transform_zv, transform, box2d_from_slot_b2Transform);
	b2AABB box = b2ComputeCapsuleAABB(&shape, transform);
	BOX2D_RETURN_CALL(box2d_b2AABB_to_zval, box);
}

ZEND_FUNCTION(b2ComputePolygonAABB)
{
	zval *shape_zv;
	zval *transform_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(transform_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon shape;
	b2Transform transform;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Polygon);
	BOX2D_READ(transform_zv, transform, box2d_from_slot_b2Transform);
	b2AABB box = b2ComputePolygonAABB(&shape, transform);
	BOX2D_RETURN_CALL(box2d_b2AABB_to_zval, box);
}

ZEND_FUNCTION(b2ComputeSegmentAABB)
{
	zval *shape_zv;
	zval *transform_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Segment)
		Z_PARAM_OBJECT_OF_CLASS(transform_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Segment shape;
	b2Transform transform;
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Segment);
	BOX2D_READ(transform_zv, transform, box2d_from_slot_b2Transform);
	b2AABB box = b2ComputeSegmentAABB(&shape, transform);
	BOX2D_RETURN_CALL(box2d_b2AABB_to_zval, box);
}

ZEND_FUNCTION(b2PointInCircle)
{
	zval *point_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Circle)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 point;
	b2Circle shape;
	BOX2D_READ(point_zv, point, box2d_from_slot_b2Vec2);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Circle);
	BOX2D_RETURN_BOOL(b2PointInCircle(point, &shape));
}

ZEND_FUNCTION(b2PointInCapsule)
{
	zval *point_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Capsule)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 point;
	b2Capsule shape;
	BOX2D_READ(point_zv, point, box2d_from_slot_b2Vec2);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Capsule);
	BOX2D_RETURN_BOOL(b2PointInCapsule(point, &shape));
}

ZEND_FUNCTION(b2PointInPolygon)
{
	zval *point_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(point_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Polygon)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 point;
	b2Polygon shape;
	BOX2D_READ(point_zv, point, box2d_from_slot_b2Vec2);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Polygon);
	BOX2D_RETURN_BOOL(b2PointInPolygon(point, &shape));
}

ZEND_FUNCTION(b2RayCastCircle)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Circle)
	ZEND_PARSE_PARAMETERS_END();

	b2RayCastInput input;
	b2Circle shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2RayCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Circle);
	b2CastOutput hit = b2RayCastCircle(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2RayCastCapsule)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Capsule)
	ZEND_PARSE_PARAMETERS_END();

	b2RayCastInput input;
	b2Capsule shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2RayCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Capsule);
	b2CastOutput hit = b2RayCastCapsule(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2RayCastSegment)
{
	zval *input_zv;
	zval *shape_zv;
	bool one_sided;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Segment)
		Z_PARAM_BOOL(one_sided)
	ZEND_PARSE_PARAMETERS_END();

	b2RayCastInput input;
	b2Segment shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2RayCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Segment);
	b2CastOutput hit = b2RayCastSegment(&input, &shape, one_sided);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2RayCastPolygon)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Polygon)
	ZEND_PARSE_PARAMETERS_END();

	b2RayCastInput input;
	b2Polygon shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2RayCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Polygon);
	b2CastOutput hit = b2RayCastPolygon(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2ShapeCastCircle)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2ShapeCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Circle)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeCastInput input;
	b2Circle shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2ShapeCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Circle);
	b2CastOutput hit = b2ShapeCastCircle(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2ShapeCastCapsule)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2ShapeCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Capsule)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeCastInput input;
	b2Capsule shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2ShapeCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Capsule);
	b2CastOutput hit = b2ShapeCastCapsule(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2ShapeCastSegment)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2ShapeCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Segment)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeCastInput input;
	b2Segment shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2ShapeCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Segment);
	b2CastOutput hit = b2ShapeCastSegment(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2ShapeCastPolygon)
{
	zval *input_zv;
	zval *shape_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2ShapeCastInput)
		Z_PARAM_OBJECT_OF_CLASS(shape_zv, box2d_ce_b2Polygon)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeCastInput input;
	b2Polygon shape;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2ShapeCastInput);
	BOX2D_READ(shape_zv, shape, box2d_from_slot_b2Polygon);
	b2CastOutput hit = b2ShapeCastPolygon(&input, &shape);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2ComputeHull)
{
	HashTable *points_ht;
	zend_long count;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY_HT(points_ht)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 *points = NULL;
	if (box2d_read_points(points_ht, count, "b2ComputeHull points", &points) == FAILURE) {
		RETURN_THROWS();
	}
	b2Hull hull = b2ComputeHull(points, (int) count);
	if (points != NULL) {
		efree(points);
	}
	BOX2D_RETURN_CALL(box2d_b2Hull_to_zval, hull);
}

ZEND_FUNCTION(b2ValidateHull)
{
	zval *hull_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(hull_zv, box2d_ce_b2Hull)
	ZEND_PARSE_PARAMETERS_END();

	b2Hull hull;
	BOX2D_READ(hull_zv, hull, box2d_from_slot_b2Hull);
	BOX2D_RETURN_BOOL(b2ValidateHull(&hull));
}

ZEND_FUNCTION(b2SegmentDistance)
{
	zval *p1_zv;
	zval *q1_zv;
	zval *p2_zv;
	zval *q2_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(p1_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(q1_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(p2_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(q2_zv, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 p1;
	b2Vec2 q1;
	b2Vec2 p2;
	b2Vec2 q2;
	BOX2D_READ(p1_zv, p1, box2d_from_slot_b2Vec2);
	BOX2D_READ(q1_zv, q1, box2d_from_slot_b2Vec2);
	BOX2D_READ(p2_zv, p2, box2d_from_slot_b2Vec2);
	BOX2D_READ(q2_zv, q2, box2d_from_slot_b2Vec2);
	b2SegmentDistanceResult result = b2SegmentDistance(p1, q1, p2, q2);
	BOX2D_RETURN_CALL(box2d_b2SegmentDistanceResult_to_zval, result);
}

ZEND_FUNCTION(b2ShapeDistance)
{
	zval *input_zv;
	zval *cache_zv;
	zval *simplexes_zv;
	zend_long capacity_in;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2DistanceInput)
		Z_PARAM_OBJECT_OF_CLASS(cache_zv, box2d_ce_b2SimplexCache)
		Z_PARAM_ZVAL(simplexes_zv)
		Z_PARAM_LONG(capacity_in)
	ZEND_PARSE_PARAMETERS_END();

	if (capacity_in < 0 || capacity_in > INT32_MAX) {
		zend_value_error("b2ShapeDistance simplexCapacity %lld is outside 0..%lld", (long long) capacity_in, (long long) INT32_MAX);
		RETURN_THROWS();
	}

	b2DistanceInput input;
	b2SimplexCache cache;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2DistanceInput);
	BOX2D_READ(cache_zv, cache, box2d_from_slot_b2SimplexCache);

	int capacity = (int) capacity_in;
	b2Simplex *simplexes = NULL;
	if (capacity > 0) {
		simplexes = safe_emalloc((size_t) capacity, sizeof(b2Simplex), 0);
		memset(simplexes, 0, (size_t) capacity * sizeof(b2Simplex));
	}

	b2DistanceOutput output = b2ShapeDistance(&input, &cache, simplexes, capacity);
	if (box2d_finish() == FAILURE) {
		if (simplexes != NULL) {
			efree(simplexes);
		}
		RETURN_THROWS();
	}

	box2d_store_cache(cache_zv, &cache);
	int written = output.simplexCount;
	if (written < 0) {
		written = 0;
	}
	if (simplexes == NULL || written > capacity) {
		written = simplexes == NULL ? 0 : capacity;
	}
	if (box2d_store_simplexes(simplexes_zv, simplexes, written) == FAILURE) {
		if (simplexes != NULL) {
			efree(simplexes);
		}
		RETURN_THROWS();
	}
	if (simplexes != NULL) {
		efree(simplexes);
	}
	if (box2d_b2DistanceOutput_to_zval(&output, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ShapeCast)
{
	zval *input_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2ShapeCastPairInput)
	ZEND_PARSE_PARAMETERS_END();

	b2ShapeCastPairInput input;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2ShapeCastPairInput);
	b2CastOutput hit = b2ShapeCast(&input);
	BOX2D_RETURN_CALL(box2d_b2CastOutput_to_zval, hit);
}

ZEND_FUNCTION(b2MakeProxy)
{
	HashTable *points_ht;
	zend_long count;
	double radius;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY_HT(points_ht)
		Z_PARAM_LONG(count)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 *points = NULL;
	if (box2d_read_points(points_ht, count, "b2MakeProxy points", &points) == FAILURE) {
		RETURN_THROWS();
	}
	b2ShapeProxy proxy = b2MakeProxy(points, (int) count, (float) radius);
	if (points != NULL) {
		efree(points);
	}
	BOX2D_RETURN_CALL(box2d_b2ShapeProxy_to_zval, proxy);
}

ZEND_FUNCTION(b2MakeOffsetProxy)
{
	HashTable *points_ht;
	zend_long count;
	double radius;
	zval *position_zv;
	zval *rotation_zv;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ARRAY_HT(points_ht)
		Z_PARAM_LONG(count)
		Z_PARAM_DOUBLE(radius)
		Z_PARAM_OBJECT_OF_CLASS(position_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation_zv, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 *points = NULL;
	if (box2d_read_points(points_ht, count, "b2MakeOffsetProxy points", &points) == FAILURE) {
		RETURN_THROWS();
	}
	b2Vec2 position;
	b2Rot rotation;
	if (box2d_read(position_zv, &position, box2d_from_slot_b2Vec2) == FAILURE || box2d_read(rotation_zv, &rotation, box2d_from_slot_b2Rot) == FAILURE) {
		if (points != NULL) {
			efree(points);
		}
		RETURN_THROWS();
	}
	b2ShapeProxy proxy = b2MakeOffsetProxy(points, (int) count, (float) radius, position, rotation);
	if (points != NULL) {
		efree(points);
	}
	BOX2D_RETURN_CALL(box2d_b2ShapeProxy_to_zval, proxy);
}

ZEND_FUNCTION(b2GetSweepTransform)
{
	zval *sweep_zv;
	double time;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(sweep_zv, box2d_ce_b2Sweep)
		Z_PARAM_DOUBLE(time)
	ZEND_PARSE_PARAMETERS_END();

	b2Sweep sweep;
	BOX2D_READ(sweep_zv, sweep, box2d_from_slot_b2Sweep);
	b2Transform transform = b2GetSweepTransform(&sweep, (float) time);
	BOX2D_RETURN_CALL(box2d_b2Transform_to_zval, transform);
}

ZEND_FUNCTION(b2TimeOfImpact)
{
	zval *input_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2TOIInput)
	ZEND_PARSE_PARAMETERS_END();

	b2TOIInput input;
	BOX2D_READ(input_zv, input, box2d_from_slot_b2TOIInput);
	b2TOIOutput output = b2TimeOfImpact(&input);
	BOX2D_RETURN_CALL(box2d_b2TOIOutput_to_zval, output);
}

ZEND_FUNCTION(b2CollideCircles)
{
	zval *circle_a_zv;
	zval *xf_a_zv;
	zval *circle_b_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(circle_a_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(circle_b_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Circle circle_a;
	b2Transform xf_a;
	b2Circle circle_b;
	b2Transform xf_b;
	BOX2D_READ(circle_a_zv, circle_a, box2d_from_slot_b2Circle);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(circle_b_zv, circle_b, box2d_from_slot_b2Circle);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideCircles(&circle_a, xf_a, &circle_b, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideCapsuleAndCircle)
{
	zval *capsule_zv;
	zval *xf_a_zv;
	zval *circle_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(capsule_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(circle_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Capsule capsule;
	b2Transform xf_a;
	b2Circle circle;
	b2Transform xf_b;
	BOX2D_READ(capsule_zv, capsule, box2d_from_slot_b2Capsule);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(circle_zv, circle, box2d_from_slot_b2Circle);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideCapsuleAndCircle(&capsule, xf_a, &circle, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideSegmentAndCircle)
{
	zval *segment_zv;
	zval *xf_a_zv;
	zval *circle_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2Segment)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(circle_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Segment segment;
	b2Transform xf_a;
	b2Circle circle;
	b2Transform xf_b;
	BOX2D_READ(segment_zv, segment, box2d_from_slot_b2Segment);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(circle_zv, circle, box2d_from_slot_b2Circle);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideSegmentAndCircle(&segment, xf_a, &circle, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollidePolygonAndCircle)
{
	zval *polygon_zv;
	zval *xf_a_zv;
	zval *circle_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(circle_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon polygon;
	b2Transform xf_a;
	b2Circle circle;
	b2Transform xf_b;
	BOX2D_READ(polygon_zv, polygon, box2d_from_slot_b2Polygon);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(circle_zv, circle, box2d_from_slot_b2Circle);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollidePolygonAndCircle(&polygon, xf_a, &circle, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideCapsules)
{
	zval *capsule_a_zv;
	zval *xf_a_zv;
	zval *capsule_b_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(capsule_a_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(capsule_b_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Capsule capsule_a;
	b2Transform xf_a;
	b2Capsule capsule_b;
	b2Transform xf_b;
	BOX2D_READ(capsule_a_zv, capsule_a, box2d_from_slot_b2Capsule);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(capsule_b_zv, capsule_b, box2d_from_slot_b2Capsule);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideCapsules(&capsule_a, xf_a, &capsule_b, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideSegmentAndCapsule)
{
	zval *segment_zv;
	zval *xf_a_zv;
	zval *capsule_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2Segment)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(capsule_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Segment segment;
	b2Transform xf_a;
	b2Capsule capsule;
	b2Transform xf_b;
	BOX2D_READ(segment_zv, segment, box2d_from_slot_b2Segment);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(capsule_zv, capsule, box2d_from_slot_b2Capsule);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideSegmentAndCapsule(&segment, xf_a, &capsule, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollidePolygonAndCapsule)
{
	zval *polygon_zv;
	zval *xf_a_zv;
	zval *capsule_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(capsule_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon polygon;
	b2Transform xf_a;
	b2Capsule capsule;
	b2Transform xf_b;
	BOX2D_READ(polygon_zv, polygon, box2d_from_slot_b2Polygon);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(capsule_zv, capsule, box2d_from_slot_b2Capsule);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollidePolygonAndCapsule(&polygon, xf_a, &capsule, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollidePolygons)
{
	zval *polygon_a_zv;
	zval *xf_a_zv;
	zval *polygon_b_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(polygon_a_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(polygon_b_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Polygon polygon_a;
	b2Transform xf_a;
	b2Polygon polygon_b;
	b2Transform xf_b;
	BOX2D_READ(polygon_a_zv, polygon_a, box2d_from_slot_b2Polygon);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(polygon_b_zv, polygon_b, box2d_from_slot_b2Polygon);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollidePolygons(&polygon_a, xf_a, &polygon_b, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideSegmentAndPolygon)
{
	zval *segment_zv;
	zval *xf_a_zv;
	zval *polygon_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2Segment)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2Segment segment;
	b2Transform xf_a;
	b2Polygon polygon;
	b2Transform xf_b;
	BOX2D_READ(segment_zv, segment, box2d_from_slot_b2Segment);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(polygon_zv, polygon, box2d_from_slot_b2Polygon);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideSegmentAndPolygon(&segment, xf_a, &polygon, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideChainSegmentAndCircle)
{
	zval *segment_zv;
	zval *xf_a_zv;
	zval *circle_zv;
	zval *xf_b_zv;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2ChainSegment)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(circle_zv, box2d_ce_b2Circle)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
	ZEND_PARSE_PARAMETERS_END();

	b2ChainSegment segment;
	b2Transform xf_a;
	b2Circle circle;
	b2Transform xf_b;
	BOX2D_READ(segment_zv, segment, box2d_from_slot_b2ChainSegment);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(circle_zv, circle, box2d_from_slot_b2Circle);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	b2Manifold manifold = b2CollideChainSegmentAndCircle(&segment, xf_a, &circle, xf_b);
	BOX2D_RETURN_CALL(box2d_b2Manifold_to_zval, manifold);
}

ZEND_FUNCTION(b2CollideChainSegmentAndCapsule)
{
	zval *segment_zv;
	zval *xf_a_zv;
	zval *capsule_zv;
	zval *xf_b_zv;
	zval *cache_zv;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2ChainSegment)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(capsule_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(cache_zv, box2d_ce_b2SimplexCache)
	ZEND_PARSE_PARAMETERS_END();

	b2ChainSegment segment;
	b2Transform xf_a;
	b2Capsule capsule;
	b2Transform xf_b;
	b2SimplexCache cache;
	BOX2D_READ(segment_zv, segment, box2d_from_slot_b2ChainSegment);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(capsule_zv, capsule, box2d_from_slot_b2Capsule);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	BOX2D_READ(cache_zv, cache, box2d_from_slot_b2SimplexCache);
	b2Manifold manifold = b2CollideChainSegmentAndCapsule(&segment, xf_a, &capsule, xf_b, &cache);
	if (box2d_finish() == FAILURE) {
		RETURN_THROWS();
	}
	box2d_store_cache(cache_zv, &cache);
	if (box2d_b2Manifold_to_zval(&manifold, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2CollideChainSegmentAndPolygon)
{
	zval *segment_zv;
	zval *xf_a_zv;
	zval *polygon_zv;
	zval *xf_b_zv;
	zval *cache_zv;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(segment_zv, box2d_ce_b2ChainSegment)
		Z_PARAM_OBJECT_OF_CLASS(xf_a_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(polygon_zv, box2d_ce_b2Polygon)
		Z_PARAM_OBJECT_OF_CLASS(xf_b_zv, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(cache_zv, box2d_ce_b2SimplexCache)
	ZEND_PARSE_PARAMETERS_END();

	b2ChainSegment segment;
	b2Transform xf_a;
	b2Polygon polygon;
	b2Transform xf_b;
	b2SimplexCache cache;
	BOX2D_READ(segment_zv, segment, box2d_from_slot_b2ChainSegment);
	BOX2D_READ(xf_a_zv, xf_a, box2d_from_slot_b2Transform);
	BOX2D_READ(polygon_zv, polygon, box2d_from_slot_b2Polygon);
	BOX2D_READ(xf_b_zv, xf_b, box2d_from_slot_b2Transform);
	BOX2D_READ(cache_zv, cache, box2d_from_slot_b2SimplexCache);
	b2Manifold manifold = b2CollideChainSegmentAndPolygon(&segment, xf_a, &polygon, xf_b, &cache);
	if (box2d_finish() == FAILURE) {
		RETURN_THROWS();
	}
	box2d_store_cache(cache_zv, &cache);
	if (box2d_b2Manifold_to_zval(&manifold, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DynamicTree_Create)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2DynamicTree created = b2DynamicTree_Create();
	if (box2d_finish() == FAILURE) {
		b2DynamicTree_Destroy(&created);
		RETURN_THROWS();
	}

	object_init_ex(return_value, box2d_ce_b2DynamicTree);
	if (EG(exception)) {
		b2DynamicTree_Destroy(&created);
		RETURN_THROWS();
	}
	*box2d_tree_native(Z_OBJ_P(return_value)) = created;
	box2d_tree_set_live(Z_OBJ_P(return_value), true);
}

ZEND_FUNCTION(b2DynamicTree_Destroy)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	b2DynamicTree_Destroy(tree);
	box2d_tree_set_live(Z_OBJ_P(tree_zv), false);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2DynamicTree_CreateProxy)
{
	zval *tree_zv;
	zval *aabb_zv;
	zend_long category_bits;
	zend_long user_data;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_OBJECT_OF_CLASS(aabb_zv, box2d_ce_b2AABB)
		Z_PARAM_LONG(category_bits)
		Z_PARAM_LONG(user_data)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	b2AABB aabb;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_READ(aabb_zv, aabb, box2d_from_slot_b2AABB);
	int proxy_id = b2DynamicTree_CreateProxy(tree, aabb, (uint64_t) category_bits, (uint64_t) user_data);
	BOX2D_RETURN_LONG(proxy_id);
}

ZEND_FUNCTION(b2DynamicTree_DestroyProxy)
{
	zval *tree_zv;
	zend_long proxy_in;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_DestroyProxy proxyId");
	b2DynamicTree_DestroyProxy(tree, proxy_id);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2DynamicTree_MoveProxy)
{
	zval *tree_zv;
	zend_long proxy_in;
	zval *aabb_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
		Z_PARAM_OBJECT_OF_CLASS(aabb_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	b2AABB aabb;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_MoveProxy proxyId");
	BOX2D_READ(aabb_zv, aabb, box2d_from_slot_b2AABB);
	b2DynamicTree_MoveProxy(tree, proxy_id, aabb);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2DynamicTree_EnlargeProxy)
{
	zval *tree_zv;
	zend_long proxy_in;
	zval *aabb_zv;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
		Z_PARAM_OBJECT_OF_CLASS(aabb_zv, box2d_ce_b2AABB)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	b2AABB aabb;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_EnlargeProxy proxyId");
	BOX2D_READ(aabb_zv, aabb, box2d_from_slot_b2AABB);
	b2DynamicTree_EnlargeProxy(tree, proxy_id, aabb);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2DynamicTree_SetCategoryBits)
{
	zval *tree_zv;
	zend_long proxy_in;
	zend_long category_bits;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
		Z_PARAM_LONG(category_bits)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_SetCategoryBits proxyId");
	b2DynamicTree_SetCategoryBits(tree, proxy_id, (uint64_t) category_bits);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2DynamicTree_GetCategoryBits)
{
	zval *tree_zv;
	zend_long proxy_in;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_GetCategoryBits proxyId");
	uint64_t bits = b2DynamicTree_GetCategoryBits(tree, proxy_id);
	BOX2D_RETURN_LONG((zend_long) bits);
}

ZEND_FUNCTION(b2DynamicTree_Query)
{
	zval *tree_zv;
	zval *aabb_zv;
	zend_long mask_bits;
	zend_fcall_info fci = empty_fcall_info;
	zend_fcall_info_cache fcc = empty_fcall_info_cache;
	zval *context_zv;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_OBJECT_OF_CLASS(aabb_zv, box2d_ce_b2AABB)
		Z_PARAM_LONG(mask_bits)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context_zv)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	b2AABB aabb;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_READ(aabb_zv, aabb, box2d_from_slot_b2AABB);

	box2d_tree_call call;
	box2d_prepare_tree_call(&call, &fci, &fcc, context_zv);
	b2TreeStats stats = b2DynamicTree_Query(tree, aabb, (uint64_t) mask_bits, box2d_tree_query_cb, &call);
	if (box2d_finish() == FAILURE || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DynamicTree_RayCast)
{
	zval *tree_zv;
	zval *input_zv;
	zend_long mask_bits;
	zend_fcall_info fci = empty_fcall_info;
	zend_fcall_info_cache fcc = empty_fcall_info_cache;
	zval *context_zv;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2RayCastInput)
		Z_PARAM_LONG(mask_bits)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context_zv)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	b2RayCastInput input;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_READ(input_zv, input, box2d_from_slot_b2RayCastInput);

	box2d_tree_call call;
	box2d_prepare_tree_call(&call, &fci, &fcc, context_zv);
	b2TreeStats stats = b2DynamicTree_RayCast(tree, &input, (uint64_t) mask_bits, box2d_tree_ray_cb, &call);
	if (box2d_finish() == FAILURE || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DynamicTree_ShapeCast)
{
	zval *tree_zv;
	zval *input_zv;
	zend_long mask_bits;
	zend_fcall_info fci = empty_fcall_info;
	zend_fcall_info_cache fcc = empty_fcall_info_cache;
	zval *context_zv;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_OBJECT_OF_CLASS(input_zv, box2d_ce_b2ShapeCastInput)
		Z_PARAM_LONG(mask_bits)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context_zv)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	b2ShapeCastInput input;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_READ(input_zv, input, box2d_from_slot_b2ShapeCastInput);

	box2d_tree_call call;
	box2d_prepare_tree_call(&call, &fci, &fcc, context_zv);
	b2TreeStats stats = b2DynamicTree_ShapeCast(tree, &input, (uint64_t) mask_bits, box2d_tree_shape_cb, &call);
	if (box2d_finish() == FAILURE || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DynamicTree_GetHeight)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_RETURN_LONG(b2DynamicTree_GetHeight(tree));
}

ZEND_FUNCTION(b2DynamicTree_GetAreaRatio)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_RETURN_DOUBLE(b2DynamicTree_GetAreaRatio(tree));
}

ZEND_FUNCTION(b2DynamicTree_GetRootBounds)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	b2AABB box = b2DynamicTree_GetRootBounds(tree);
	BOX2D_RETURN_CALL(box2d_b2AABB_to_zval, box);
}

ZEND_FUNCTION(b2DynamicTree_GetProxyCount)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_RETURN_LONG(b2DynamicTree_GetProxyCount(tree));
}

ZEND_FUNCTION(b2DynamicTree_Rebuild)
{
	zval *tree_zv;
	bool full_build;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_BOOL(full_build)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_RETURN_LONG(b2DynamicTree_Rebuild(tree, full_build));
}

ZEND_FUNCTION(b2DynamicTree_GetByteCount)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_RETURN_LONG(b2DynamicTree_GetByteCount(tree));
}

ZEND_FUNCTION(b2DynamicTree_GetUserData)
{
	zval *tree_zv;
	zend_long proxy_in;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_GetUserData proxyId");
	uint64_t user_data = b2DynamicTree_GetUserData(tree, proxy_id);
	BOX2D_RETURN_LONG((zend_long) user_data);
}

ZEND_FUNCTION(b2DynamicTree_GetAABB)
{
	zval *tree_zv;
	zend_long proxy_in;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
		Z_PARAM_LONG(proxy_in)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	int proxy_id;
	BOX2D_TREE(tree_zv, tree);
	BOX2D_I32(proxy_in, proxy_id, "b2DynamicTree_GetAABB proxyId");
	b2AABB box = b2DynamicTree_GetAABB(tree, proxy_id);
	BOX2D_RETURN_CALL(box2d_b2AABB_to_zval, box);
}

ZEND_FUNCTION(b2DynamicTree_Validate)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	b2DynamicTree_Validate(tree);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2DynamicTree_ValidateNoEnlarged)
{
	zval *tree_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tree_zv, box2d_ce_b2DynamicTree)
	ZEND_PARSE_PARAMETERS_END();

	b2DynamicTree *tree;
	BOX2D_TREE(tree_zv, tree);
	b2DynamicTree_ValidateNoEnlarged(tree);
	BOX2D_RETURN_VOID();
}

ZEND_FUNCTION(b2SolvePlanes)
{
	zval *target_zv;
	HashTable *planes_ht;
	zend_long count;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(target_zv, box2d_ce_b2Vec2)
		Z_PARAM_ARRAY_HT(planes_ht)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 target;
	BOX2D_READ(target_zv, target, box2d_from_slot_b2Vec2);

	b2CollisionPlane *planes = NULL;
	if (box2d_read_planes(planes_ht, count, &planes) == FAILURE) {
		RETURN_THROWS();
	}

	b2PlaneSolverResult result = b2SolvePlanes(target, planes, (int) count);
	if (box2d_finish() == FAILURE) {
		if (planes != NULL) {
			efree(planes);
		}
		RETURN_THROWS();
	}
	box2d_store_pushes(planes_ht, planes, count);
	if (planes != NULL) {
		efree(planes);
	}
	if (box2d_b2PlaneSolverResult_to_zval(&result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2ClipVector)
{
	zval *vector_zv;
	HashTable *planes_ht;
	zend_long count;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(vector_zv, box2d_ce_b2Vec2)
		Z_PARAM_ARRAY_HT(planes_ht)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	b2Vec2 vector;
	BOX2D_READ(vector_zv, vector, box2d_from_slot_b2Vec2);

	b2CollisionPlane *planes = NULL;
	if (box2d_read_planes(planes_ht, count, &planes) == FAILURE) {
		RETURN_THROWS();
	}
	b2Vec2 clipped = b2ClipVector(vector, planes, (int) count);
	if (planes != NULL) {
		efree(planes);
	}
	BOX2D_RETURN_CALL(box2d_b2Vec2_to_zval, clipped);
}
