#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

#include "../stubs/box2d_arginfo.h"

#include <math.h>
#include <string.h>

static void box2d_dtor_args(zval *args, uint32_t count)
{
	for (uint32_t i = 0; i < count; i++) {
		zval_ptr_dtor(&args[i]);
	}
}

static void box2d_release_retval(zval *retval)
{
	if (Z_TYPE_P(retval) != IS_UNDEF) {
		zval_ptr_dtor(retval);
	}
}

static void box2d_assign_zval(zval *slot, zval *incoming)
{
	if (Z_TYPE_P(slot) != IS_UNDEF) {
		zval_ptr_dtor(slot);
		ZVAL_UNDEF(slot);
	}
	if (incoming != NULL && Z_TYPE_P(incoming) != IS_UNDEF && Z_TYPE_P(incoming) != IS_NULL) {
		ZVAL_COPY(slot, incoming);
	}
}

static bool box2d_slot_live(zval *slot)
{
	return slot != NULL && Z_TYPE_P(slot) != IS_UNDEF && Z_TYPE_P(slot) != IS_NULL;
}

static const char *box2d_callback_where(int kind)
{
	switch (kind) {
	case BOX2D_CB_FRICTION:
		return "friction";
	case BOX2D_CB_RESTITUTION:
		return "restitution";
	case BOX2D_CB_FILTER:
		return "custom filter";
	case BOX2D_CB_PRESOLVE:
		return "pre-solve";
	default:
		return "box2d";
	}
}

static zval *box2d_callback_slot(box2d_world_ctx *world, int kind)
{
	switch (kind) {
	case BOX2D_CB_FRICTION:
		return &world->friction;
	case BOX2D_CB_RESTITUTION:
		return &world->restitution;
	case BOX2D_CB_FILTER:
		return &world->custom_filter;
	case BOX2D_CB_PRESOLVE:
		return &world->pre_solve;
	default:
		return NULL;
	}
}

static zval *box2d_callback_context(box2d_world_ctx *world, int kind)
{
	switch (kind) {
	case BOX2D_CB_FILTER:
		return &world->custom_filter_context;
	case BOX2D_CB_PRESOLVE:
		return &world->pre_solve_context;
	default:
		return NULL;
	}
}

static bool box2d_read_float(zval *retval, float fallback, const char *where, float *out)
{
	ZVAL_DEREF(retval);
	switch (Z_TYPE_P(retval)) {
	case IS_TRUE:
	case IS_FALSE:
	case IS_LONG:
	case IS_DOUBLE:
		*out = (float) zval_get_double(retval);
		return true;
	case IS_NULL:
		*out = 0.0f;
		return true;
	case IS_STRING:
		if (!is_numeric_string(Z_STRVAL_P(retval), Z_STRLEN_P(retval), NULL, NULL, 0)) {
			zend_type_error("%s callback must return float", where);
			*out = fallback;
			return false;
		}
		*out = (float) zval_get_double(retval);
		return true;
	default:
		zend_type_error("%s callback must return float", where);
		*out = fallback;
		return false;
	}
}

static bool box2d_read_bool(zval *retval, bool fallback, const char *where, bool *out)
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
		return true;
	default:
		zend_type_error("%s callback must return bool", where);
		*out = fallback;
		return false;
	}
}

static bool box2d_call_slot(zval *slot, zval *args, uint32_t argc, zval *retval, const char *where)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;

	ZVAL_UNDEF(retval);
	memset(&fci, 0, sizeof(fci));
	if (zend_fcall_info_init(slot, 0, &fci, &fcc, NULL, NULL) == FAILURE) {
		if (!EG(exception)) {
			zend_type_error("%s callback is not callable", where);
		}
		return false;
	}

	fci.param_count = argc;
	fci.params = args;
	fci.retval = retval;
	fci.named_params = NULL;
	if (zend_call_function(&fci, &fcc) == FAILURE && !EG(exception)) {
		zend_throw_error(NULL, "%s callback failed", where);
	}
	return EG(exception) == NULL;
}

static void box2d_write_manifold(zval *manifold_zv, b2Manifold *dest)
{
	b2Manifold edited;
	box2d_frame frame;

	if (dest == NULL) {
		return;
	}
	box2d_frame_init(&frame);
	if (box2d_b2Manifold_from_zval(manifold_zv, &edited, &frame) == SUCCESS) {
		*dest = edited;
	}
	box2d_frame_free(&frame);
}

void box2d_run_callback(box2d_world_ctx *world, const box2d_callback_request *req)
{
	zval *slot = box2d_callback_slot(world, req->kind);
	const char *where = box2d_callback_where(req->kind);
	zval args[4];
	zval retval;
	uint32_t argc = 0;

	if (!box2d_slot_live(slot) || EG(exception)) {
		return;
	}

	if (req->kind == BOX2D_CB_FRICTION || req->kind == BOX2D_CB_RESTITUTION) {
		ZVAL_DOUBLE(&args[0], (double) req->scalar_a);
		ZVAL_LONG(&args[1], (zend_long) req->material_a);
		ZVAL_DOUBLE(&args[2], (double) req->scalar_b);
		ZVAL_LONG(&args[3], (zend_long) req->material_b);
		argc = 4;
	} else {
		if (box2d_b2ShapeId_to_zval(&req->shape_a, &args[0]) == FAILURE) {
			return;
		}
		if (box2d_b2ShapeId_to_zval(&req->shape_b, &args[1]) == FAILURE) {
			zval_ptr_dtor(&args[0]);
			return;
		}
		argc = 2;
		if (req->kind == BOX2D_CB_PRESOLVE) {
			if (req->manifold == NULL || box2d_b2Manifold_to_zval(req->manifold, &args[2]) == FAILURE) {
				box2d_dtor_args(args, 2);
				return;
			}
			argc = 3;
		}
		zval *context = box2d_callback_context(world, req->kind);
		if (box2d_slot_live(context)) {
			ZVAL_COPY(&args[argc], context);
		} else {
			ZVAL_NULL(&args[argc]);
		}
		argc++;
	}

	if (!box2d_call_slot(slot, args, argc, &retval, where)) {
		box2d_release_retval(&retval);
		box2d_dtor_args(args, argc);
		return;
	}

	if (req->kind == BOX2D_CB_FRICTION || req->kind == BOX2D_CB_RESTITUTION) {
		float value = req->fallback_float;
		if (box2d_read_float(&retval, req->fallback_float, where, &value) && req->float_result != NULL) {
			*req->float_result = value;
		}
	} else {
		bool value = req->fallback_bool;
		if (box2d_read_bool(&retval, req->fallback_bool, where, &value)) {
			if (req->kind == BOX2D_CB_PRESOLVE) {
				box2d_write_manifold(&args[2], req->manifold);
			}
			if (!EG(exception) && req->bool_result != NULL) {
				*req->bool_result = value;
			}
		}
	}

	zval_ptr_dtor(&retval);
	box2d_dtor_args(args, argc);
}

void box2d_invoke_callback(box2d_world_ctx *world, const box2d_callback_request *req)
{
	if (req->float_result != NULL) {
		*req->float_result = req->fallback_float;
	}
	if (req->bool_result != NULL) {
		*req->bool_result = req->fallback_bool;
	}
	if (world == NULL) {
		return;
	}

	/*
	 * Pool threads have no executor globals. Queue before any EG() read.
	 * The stepping thread, which owns the world, runs the callable.
	 */
	if (world->worker_count > 1 && !pthread_equal(pthread_self(), world->owner)) {
		box2d_queue_callback(world, req);
		return;
	}
	if (EG(exception)) {
		return;
	}
	box2d_run_callback(world, req);
}

static box2d_world_ctx *box2d_callback_world(void *context)
{
	if (context != NULL) {
		return context;
	}
	if (box2d_step_world != NULL) {
		return box2d_step_world;
	}
	return box2d_pool_world;
}

float box2d_friction_trampoline(float friction_a, int material_a, float friction_b, int material_b)
{
	float result = sqrtf(friction_a * friction_b);
	box2d_callback_request req;

	memset(&req, 0, sizeof(req));
	req.kind = BOX2D_CB_FRICTION;
	req.scalar_a = friction_a;
	req.material_a = material_a;
	req.scalar_b = friction_b;
	req.material_b = material_b;
	req.float_result = &result;
	req.fallback_float = result;
	box2d_invoke_callback(box2d_callback_world(NULL), &req);
	return result;
}

float box2d_restitution_trampoline(float restitution_a, int material_a, float restitution_b, int material_b)
{
	float result = fmaxf(restitution_a, restitution_b);
	box2d_callback_request req;

	memset(&req, 0, sizeof(req));
	req.kind = BOX2D_CB_RESTITUTION;
	req.scalar_a = restitution_a;
	req.material_a = material_a;
	req.scalar_b = restitution_b;
	req.material_b = material_b;
	req.float_result = &result;
	req.fallback_float = result;
	box2d_invoke_callback(box2d_callback_world(NULL), &req);
	return result;
}

static bool box2d_filter_trampoline(b2ShapeId shape_a, b2ShapeId shape_b, void *context)
{
	bool result = true;
	box2d_callback_request req;

	memset(&req, 0, sizeof(req));
	req.kind = BOX2D_CB_FILTER;
	req.shape_a = shape_a;
	req.shape_b = shape_b;
	req.bool_result = &result;
	req.fallback_bool = true;
	box2d_invoke_callback(box2d_callback_world(context), &req);
	return result;
}

static bool box2d_presolve_trampoline(b2ShapeId shape_a, b2ShapeId shape_b, b2Manifold *manifold, void *context)
{
	bool result = true;
	box2d_callback_request req;

	memset(&req, 0, sizeof(req));
	req.kind = BOX2D_CB_PRESOLVE;
	req.shape_a = shape_a;
	req.shape_b = shape_b;
	req.manifold = manifold;
	req.bool_result = &result;
	req.fallback_bool = true;
	box2d_invoke_callback(box2d_callback_world(context), &req);
	return result;
}

static bool box2d_enter_world(zval *zv, b2WorldId *id, int op)
{
	box2d_guard_id(zv, BOX2D_ID_WORLD, 0);
	if (EG(exception)) {
		return false;
	}
	if (box2d_bind_read(zv, id, box2d_from_slot_b2WorldId) == FAILURE) {
		return false;
	}
	box2d_guard_step(*id, op);
	return EG(exception) == NULL;
}

typedef struct box2d_query {
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	bool failed;
} box2d_query;

static bool box2d_query_call(box2d_query *query, zval *args, uint32_t argc, zval *retval)
{
	if (query->failed || EG(exception)) {
		query->failed = true;
		return false;
	}

	ZVAL_UNDEF(retval);
	query->fci.retval = retval;
	query->fci.params = args;
	query->fci.param_count = argc;
	query->fci.named_params = NULL;
	if (zend_call_function(&query->fci, &query->fcc) == FAILURE) {
		query->failed = true;
		if (!EG(exception)) {
			zend_throw_error(NULL, "query callback failed");
		}
		return false;
	}
	if (EG(exception)) {
		query->failed = true;
		return false;
	}
	return true;
}

static bool box2d_overlap_cb(b2ShapeId shape_id, void *context)
{
	box2d_query *query = context;
	zval args[2];
	zval retval;
	bool keep = false;

	if (query->failed || EG(exception)) {
		query->failed = true;
		return false;
	}
	if (box2d_b2ShapeId_to_zval(&shape_id, &args[0]) == FAILURE) {
		query->failed = true;
		return false;
	}
	ZVAL_COPY(&args[1], query->context);
	if (!box2d_query_call(query, args, 2, &retval)) {
		box2d_release_retval(&retval);
		box2d_dtor_args(args, 2);
		return false;
	}
	if (!box2d_read_bool(&retval, false, "overlap", &keep)) {
		query->failed = true;
		keep = false;
	}
	zval_ptr_dtor(&retval);
	box2d_dtor_args(args, 2);
	return keep;
}

static float box2d_cast_cb(b2ShapeId shape_id, b2Vec2 point, b2Vec2 normal, float fraction, void *context)
{
	box2d_query *query = context;
	zval args[5];
	zval retval;
	float result = 0.0f;

	if (query->failed || EG(exception)) {
		query->failed = true;
		return 0.0f;
	}
	ZVAL_UNDEF(&args[0]);
	ZVAL_UNDEF(&args[1]);
	ZVAL_UNDEF(&args[2]);
	if (box2d_b2ShapeId_to_zval(&shape_id, &args[0]) == FAILURE
		|| box2d_b2Vec2_to_zval(&point, &args[1]) == FAILURE
		|| box2d_b2Vec2_to_zval(&normal, &args[2]) == FAILURE) {
		query->failed = true;
		box2d_dtor_args(args, 3);
		return 0.0f;
	}
	ZVAL_DOUBLE(&args[3], (double) fraction);
	ZVAL_COPY(&args[4], query->context);
	if (box2d_query_call(query, args, 5, &retval)) {
		if (!box2d_read_float(&retval, 0.0f, "cast", &result)) {
			query->failed = true;
			result = 0.0f;
		}
		zval_ptr_dtor(&retval);
	} else {
		box2d_release_retval(&retval);
	}
	box2d_dtor_args(args, 5);
	return result;
}

static bool box2d_plane_cb(b2ShapeId shape_id, const b2PlaneResult *plane, void *context)
{
	box2d_query *query = context;
	zval args[3];
	zval retval;
	bool keep = false;

	if (query->failed || EG(exception)) {
		query->failed = true;
		return false;
	}
	ZVAL_UNDEF(&args[0]);
	ZVAL_UNDEF(&args[1]);
	if (box2d_b2ShapeId_to_zval(&shape_id, &args[0]) == FAILURE || box2d_b2PlaneResult_to_zval(plane, &args[1]) == FAILURE) {
		query->failed = true;
		box2d_dtor_args(args, 2);
		return false;
	}
	ZVAL_COPY(&args[2], query->context);
	if (!box2d_query_call(query, args, 3, &retval)) {
		box2d_release_retval(&retval);
		box2d_dtor_args(args, 3);
		return false;
	}
	if (!box2d_read_bool(&retval, false, "mover", &keep)) {
		query->failed = true;
		keep = false;
	}
	zval_ptr_dtor(&retval);
	box2d_dtor_args(args, 3);
	return keep;
}

static void box2d_prepare_query(box2d_query *query, zend_fcall_info *fci, zend_fcall_info_cache *fcc, zval *context)
{
	ZVAL_DEREF(context);
	query->fci = *fci;
	query->fcc = *fcc;
	query->context = context;
	query->failed = false;
}

typedef struct box2d_draw_frame {
	zval *draw;
	zval context;
	bool failed;
} box2d_draw_frame;

static _Thread_local box2d_draw_frame *box2d_draw_current;

static zval *box2d_draw_fn(const char *name, size_t name_len)
{
	zval *fn;

	if (box2d_draw_current == NULL) {
		return NULL;
	}
	if (box2d_draw_current->failed || EG(exception)) {
		box2d_draw_current->failed = true;
		return NULL;
	}
	fn = zend_read_property(Z_OBJCE_P(box2d_draw_current->draw), Z_OBJ_P(box2d_draw_current->draw), name, name_len, 0, NULL);
	if (fn == NULL) {
		return NULL;
	}
	ZVAL_DEREF(fn);
	if (Z_TYPE_P(fn) == IS_NULL || Z_TYPE_P(fn) == IS_UNDEF) {
		return NULL;
	}
	return fn;
}

static zend_result box2d_vec_list(const b2Vec2 *vertices, int count, zval *out)
{
	if (count < 0) {
		count = 0;
	}
	array_init_size(out, (uint32_t) count);
	for (int i = 0; i < count; i++) {
		zval item;
		if (vertices == NULL || box2d_b2Vec2_to_zval(&vertices[i], &item) == FAILURE) {
			zval_ptr_dtor(out);
			ZVAL_UNDEF(out);
			return FAILURE;
		}
		add_next_index_zval(out, &item);
	}
	return SUCCESS;
}

static void box2d_draw_void(zval *fn, zval *args, uint32_t argc)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval retval;

	if (fn == NULL || box2d_draw_current == NULL) {
		box2d_dtor_args(args, argc);
		return;
	}
	memset(&fci, 0, sizeof(fci));
	if (zend_fcall_info_init(fn, 0, &fci, &fcc, NULL, NULL) == FAILURE) {
		box2d_draw_current->failed = true;
		if (!EG(exception)) {
			zend_type_error("debug draw callback is not callable");
		}
		box2d_dtor_args(args, argc);
		return;
	}
	ZVAL_UNDEF(&retval);
	fci.param_count = argc;
	fci.params = args;
	fci.retval = &retval;
	fci.named_params = NULL;
	if (zend_call_function(&fci, &fcc) == FAILURE && !EG(exception)) {
		zend_throw_error(NULL, "debug draw callback failed");
	}
	if (EG(exception)) {
		box2d_draw_current->failed = true;
	}
	box2d_release_retval(&retval);
	box2d_dtor_args(args, argc);
}

static void box2d_draw_context_arg(zval *dest)
{
	ZVAL_COPY(dest, &box2d_draw_current->context);
}

static void box2d_draw_polygon(const b2Vec2 *vertices, int vertex_count, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawPolygonFcn"));
	zval args[4];

	(void) context;
	if (fn == NULL) {
		return;
	}
	if (box2d_vec_list(vertices, vertex_count, &args[0]) == FAILURE) {
		box2d_draw_current->failed = true;
		return;
	}
	ZVAL_LONG(&args[1], vertex_count);
	ZVAL_LONG(&args[2], (zend_long) color);
	box2d_draw_context_arg(&args[3]);
	box2d_draw_void(fn, args, 4);
}

static void box2d_draw_solid_polygon(b2Transform transform, const b2Vec2 *vertices, int vertex_count, float radius, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawSolidPolygonFcn"));
	zval args[6];

	(void) context;
	if (fn == NULL) {
		return;
	}
	ZVAL_UNDEF(&args[0]);
	ZVAL_UNDEF(&args[1]);
	if (box2d_b2Transform_to_zval(&transform, &args[0]) == FAILURE || box2d_vec_list(vertices, vertex_count, &args[1]) == FAILURE) {
		box2d_draw_current->failed = true;
		box2d_dtor_args(args, 2);
		return;
	}
	ZVAL_LONG(&args[2], vertex_count);
	ZVAL_DOUBLE(&args[3], (double) radius);
	ZVAL_LONG(&args[4], (zend_long) color);
	box2d_draw_context_arg(&args[5]);
	box2d_draw_void(fn, args, 6);
}

static void box2d_draw_circle(b2Vec2 center, float radius, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawCircleFcn"));
	zval args[4];

	(void) context;
	if (fn == NULL) {
		return;
	}
	if (box2d_b2Vec2_to_zval(&center, &args[0]) == FAILURE) {
		box2d_draw_current->failed = true;
		return;
	}
	ZVAL_DOUBLE(&args[1], (double) radius);
	ZVAL_LONG(&args[2], (zend_long) color);
	box2d_draw_context_arg(&args[3]);
	box2d_draw_void(fn, args, 4);
}

static void box2d_draw_solid_circle(b2Transform transform, float radius, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawSolidCircleFcn"));
	zval args[4];

	(void) context;
	if (fn == NULL) {
		return;
	}
	if (box2d_b2Transform_to_zval(&transform, &args[0]) == FAILURE) {
		box2d_draw_current->failed = true;
		return;
	}
	ZVAL_DOUBLE(&args[1], (double) radius);
	ZVAL_LONG(&args[2], (zend_long) color);
	box2d_draw_context_arg(&args[3]);
	box2d_draw_void(fn, args, 4);
}

static void box2d_draw_capsule(b2Vec2 p1, b2Vec2 p2, float radius, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawSolidCapsuleFcn"));
	zval args[5];

	(void) context;
	if (fn == NULL) {
		return;
	}
	ZVAL_UNDEF(&args[0]);
	ZVAL_UNDEF(&args[1]);
	if (box2d_b2Vec2_to_zval(&p1, &args[0]) == FAILURE || box2d_b2Vec2_to_zval(&p2, &args[1]) == FAILURE) {
		box2d_draw_current->failed = true;
		box2d_dtor_args(args, 2);
		return;
	}
	ZVAL_DOUBLE(&args[2], (double) radius);
	ZVAL_LONG(&args[3], (zend_long) color);
	box2d_draw_context_arg(&args[4]);
	box2d_draw_void(fn, args, 5);
}

static void box2d_draw_segment(b2Vec2 p1, b2Vec2 p2, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawSegmentFcn"));
	zval args[4];

	(void) context;
	if (fn == NULL) {
		return;
	}
	ZVAL_UNDEF(&args[0]);
	ZVAL_UNDEF(&args[1]);
	if (box2d_b2Vec2_to_zval(&p1, &args[0]) == FAILURE || box2d_b2Vec2_to_zval(&p2, &args[1]) == FAILURE) {
		box2d_draw_current->failed = true;
		box2d_dtor_args(args, 2);
		return;
	}
	ZVAL_LONG(&args[2], (zend_long) color);
	box2d_draw_context_arg(&args[3]);
	box2d_draw_void(fn, args, 4);
}

static void box2d_draw_transform(b2Transform transform, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawTransformFcn"));
	zval args[2];

	(void) context;
	if (fn == NULL) {
		return;
	}
	if (box2d_b2Transform_to_zval(&transform, &args[0]) == FAILURE) {
		box2d_draw_current->failed = true;
		return;
	}
	box2d_draw_context_arg(&args[1]);
	box2d_draw_void(fn, args, 2);
}

static void box2d_draw_point(b2Vec2 point, float size, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawPointFcn"));
	zval args[4];

	(void) context;
	if (fn == NULL) {
		return;
	}
	if (box2d_b2Vec2_to_zval(&point, &args[0]) == FAILURE) {
		box2d_draw_current->failed = true;
		return;
	}
	ZVAL_DOUBLE(&args[1], (double) size);
	ZVAL_LONG(&args[2], (zend_long) color);
	box2d_draw_context_arg(&args[3]);
	box2d_draw_void(fn, args, 4);
}

static void box2d_draw_string(b2Vec2 point, const char *text, b2HexColor color, void *context)
{
	zval *fn = box2d_draw_fn(ZEND_STRL("DrawStringFcn"));
	zval args[4];

	(void) context;
	if (fn == NULL) {
		return;
	}
	if (box2d_b2Vec2_to_zval(&point, &args[0]) == FAILURE) {
		box2d_draw_current->failed = true;
		return;
	}
	ZVAL_STRING(&args[1], text != NULL ? text : "");
	ZVAL_LONG(&args[2], (zend_long) color);
	box2d_draw_context_arg(&args[3]);
	box2d_draw_void(fn, args, 4);
}

static void box2d_install_draw(b2DebugDraw *draw)
{
	draw->DrawPolygonFcn = box2d_draw_polygon;
	draw->DrawSolidPolygonFcn = box2d_draw_solid_polygon;
	draw->DrawCircleFcn = box2d_draw_circle;
	draw->DrawSolidCircleFcn = box2d_draw_solid_circle;
	draw->DrawSolidCapsuleFcn = box2d_draw_capsule;
	draw->DrawSegmentFcn = box2d_draw_segment;
	draw->DrawTransformFcn = box2d_draw_transform;
	draw->DrawPointFcn = box2d_draw_point;
	draw->DrawStringFcn = box2d_draw_string;
}

static void box2d_set_pair_callback(b2WorldId id, zval *callback, zval *context, zval *callback_slot, zval *context_slot, bool presolve)
{
	box2d_world_ctx *previous = box2d_world_push(id);

	if (callback == NULL) {
		box2d_assign_zval(callback_slot, NULL);
		box2d_assign_zval(context_slot, NULL);
		if (presolve) {
			b2World_SetPreSolveCallback(id, NULL, NULL);
		} else {
			b2World_SetCustomFilterCallback(id, NULL, NULL);
		}
	} else {
		box2d_world_ctx *ctx = box2d_world_lookup(id);
		box2d_assign_zval(callback_slot, callback);
		box2d_assign_zval(context_slot, context);
		if (presolve) {
			b2World_SetPreSolveCallback(id, box2d_presolve_trampoline, ctx);
		} else {
			b2World_SetCustomFilterCallback(id, box2d_filter_trampoline, ctx);
		}
	}
	box2d_world_pop(previous);
	box2d_assert_check();
}

ZEND_FUNCTION(b2World_GetBodyEvents)
{
	zval *world_id;
	b2WorldId id;
	b2BodyEvents events;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	previous = box2d_world_push(id);
	events = b2World_GetBodyEvents(id);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2BodyEvents_to_zval(&events, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_GetSensorEvents)
{
	zval *world_id;
	b2WorldId id;
	b2SensorEvents events;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	previous = box2d_world_push(id);
	events = b2World_GetSensorEvents(id);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2SensorEvents_to_zval(&events, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_GetContactEvents)
{
	zval *world_id;
	b2WorldId id;
	b2ContactEvents events;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	previous = box2d_world_push(id);
	events = b2World_GetContactEvents(id);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2ContactEvents_to_zval(&events, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_OverlapAABB)
{
	zval *world_id;
	zval *aabb_zv;
	zval *filter_zv;
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	b2WorldId id;
	b2AABB aabb;
	b2QueryFilter filter;
	box2d_query query;
	b2TreeStats stats;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(aabb_zv, box2d_ce_b2AABB)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(aabb_zv, &aabb, box2d_from_slot_b2AABB) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_prepare_query(&query, &fci, &fcc, context);
	previous = box2d_world_push(id);
	stats = b2World_OverlapAABB(id, aabb, filter, box2d_overlap_cb, &query);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_OverlapShape)
{
	zval *world_id;
	zval *proxy_zv;
	zval *filter_zv;
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	b2WorldId id;
	b2ShapeProxy proxy;
	b2QueryFilter filter;
	box2d_query query;
	b2TreeStats stats;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(proxy_zv, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(proxy_zv, &proxy, box2d_from_slot_b2ShapeProxy) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_prepare_query(&query, &fci, &fcc, context);
	previous = box2d_world_push(id);
	stats = b2World_OverlapShape(id, &proxy, filter, box2d_overlap_cb, &query);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_CastRay)
{
	zval *world_id;
	zval *origin_zv;
	zval *translation_zv;
	zval *filter_zv;
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	b2WorldId id;
	b2Vec2 origin;
	b2Vec2 translation;
	b2QueryFilter filter;
	box2d_query query;
	b2TreeStats stats;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(origin_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(translation_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(origin_zv, &origin, box2d_from_slot_b2Vec2) == FAILURE
		|| box2d_bind_read(translation_zv, &translation, box2d_from_slot_b2Vec2) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_prepare_query(&query, &fci, &fcc, context);
	previous = box2d_world_push(id);
	stats = b2World_CastRay(id, origin, translation, filter, box2d_cast_cb, &query);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_CastRayClosest)
{
	zval *world_id;
	zval *origin_zv;
	zval *translation_zv;
	zval *filter_zv;
	b2WorldId id;
	b2Vec2 origin;
	b2Vec2 translation;
	b2QueryFilter filter;
	b2RayResult result;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(origin_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(translation_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(origin_zv, &origin, box2d_from_slot_b2Vec2) == FAILURE
		|| box2d_bind_read(translation_zv, &translation, box2d_from_slot_b2Vec2) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	previous = box2d_world_push(id);
	result = b2World_CastRayClosest(id, origin, translation, filter);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2RayResult_to_zval(&result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_CastShape)
{
	zval *world_id;
	zval *proxy_zv;
	zval *translation_zv;
	zval *filter_zv;
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	b2WorldId id;
	b2ShapeProxy proxy;
	b2Vec2 translation;
	b2QueryFilter filter;
	box2d_query query;
	b2TreeStats stats;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(proxy_zv, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(translation_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(proxy_zv, &proxy, box2d_from_slot_b2ShapeProxy) == FAILURE
		|| box2d_bind_read(translation_zv, &translation, box2d_from_slot_b2Vec2) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_prepare_query(&query, &fci, &fcc, context);
	previous = box2d_world_push(id);
	stats = b2World_CastShape(id, &proxy, translation, filter, box2d_cast_cb, &query);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception) || box2d_b2TreeStats_to_zval(&stats, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_CastMover)
{
	zval *world_id;
	zval *mover_zv;
	zval *translation_zv;
	zval *filter_zv;
	b2WorldId id;
	b2Capsule mover;
	b2Vec2 translation;
	b2QueryFilter filter;
	float fraction;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(mover_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(translation_zv, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(mover_zv, &mover, box2d_from_slot_b2Capsule) == FAILURE
		|| box2d_bind_read(translation_zv, &translation, box2d_from_slot_b2Vec2) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	previous = box2d_world_push(id);
	fraction = b2World_CastMover(id, &mover, translation, filter);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE((double) fraction);
}

ZEND_FUNCTION(b2World_CollideMover)
{
	zval *world_id;
	zval *mover_zv;
	zval *filter_zv;
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zval *context;
	b2WorldId id;
	b2Capsule mover;
	b2QueryFilter filter;
	box2d_query query;
	box2d_world_ctx *previous;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(mover_zv, box2d_ce_b2Capsule)
		Z_PARAM_OBJECT_OF_CLASS(filter_zv, box2d_ce_b2QueryFilter)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(mover_zv, &mover, box2d_from_slot_b2Capsule) == FAILURE
		|| box2d_bind_read(filter_zv, &filter, box2d_from_slot_b2QueryFilter) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_prepare_query(&query, &fci, &fcc, context);
	previous = box2d_world_push(id);
	b2World_CollideMover(id, &mover, filter, box2d_plane_cb, &query);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_SetCustomFilterCallback)
{
	zval *world_id;
	zval *callback;
	zval *context;
	b2WorldId id;
	box2d_world_ctx *ctx;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(callback, zend_ce_closure)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	ctx = box2d_world_lookup(id);
	if (ctx == NULL) {
		zend_throw_error(NULL, "world belongs to another thread");
		RETURN_THROWS();
	}
	ZVAL_DEREF(context);
	box2d_set_pair_callback(id, callback, context, &ctx->custom_filter, &ctx->custom_filter_context, false);
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_SetPreSolveCallback)
{
	zval *world_id;
	zval *callback;
	zval *context;
	b2WorldId id;
	box2d_world_ctx *ctx;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(callback, zend_ce_closure)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	ctx = box2d_world_lookup(id);
	if (ctx == NULL) {
		zend_throw_error(NULL, "world belongs to another thread");
		RETURN_THROWS();
	}
	ZVAL_DEREF(context);
	box2d_set_pair_callback(id, callback, context, &ctx->pre_solve, &ctx->pre_solve_context, true);
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2World_Draw)
{
	zval *world_id;
	zval *draw_zv;
	b2WorldId id;
	b2DebugDraw draw;
	box2d_draw_frame frame;
	box2d_draw_frame *previous_frame;
	box2d_world_ctx *previous;
	zval *context;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(world_id, box2d_ce_b2WorldId)
		Z_PARAM_OBJECT_OF_CLASS(draw_zv, box2d_ce_b2DebugDraw)
	ZEND_PARSE_PARAMETERS_END();

	if (!box2d_enter_world(world_id, &id, BOX2D_OP_NONE)) {
		RETURN_THROWS();
	}
	if (box2d_bind_read(draw_zv, &draw, box2d_from_slot_b2DebugDraw) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_install_draw(&draw);
	frame.draw = draw_zv;
	frame.failed = false;
	context = zend_read_property(Z_OBJCE_P(draw_zv), Z_OBJ_P(draw_zv), ZEND_STRL("context"), 0, NULL);
	if (context == NULL || Z_TYPE_P(context) == IS_UNDEF) {
		ZVAL_NULL(&frame.context);
	} else {
		ZVAL_COPY(&frame.context, context);
	}
	previous_frame = box2d_draw_current;
	box2d_draw_current = &frame;
	previous = box2d_world_push(id);
	b2World_Draw(id, &draw);
	box2d_world_pop(previous);
	box2d_draw_current = previous_frame;
	zval_ptr_dtor(&frame.context);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}
