#ifndef BOX2D_RUNTIME_H
#define BOX2D_RUNTIME_H

#include "php.h"
#include "box2d/box2d.h"

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * Worlds created by this request live on this list. Module globals are
 * per PHP thread under ZTS, so the list is the set of worlds that thread owns.
 * A pool is joined before b2DestroyWorld. pool_dead is set in a forked child.
 */
#define BOX2D_POOL_LIMIT 64

struct box2d_task_range;
struct box2d_callback_wait;
struct box2d_world_ctx;

typedef struct box2d_worker_slot {
	struct box2d_world_ctx *ctx;
	uint32_t index;
} box2d_worker_slot;

typedef struct box2d_world_ctx {
	b2WorldId id;
	bool stepping;
	pthread_t owner;
	/* PHP closures for the serial friction and restitution trampolines. UNDEF when unset. */
	zval friction;
	zval restitution;
	/* Custom filter and pre-solve closures plus the context handed to them. UNDEF when unset. */
	zval custom_filter;
	zval custom_filter_context;
	zval pre_solve;
	zval pre_solve_context;
	int worker_count;
	bool pool_started;
	bool pool_stop;
	bool pool_dead;
	bool assert_pending;
	const char *assert_condition;
	const char *assert_file;
	int assert_line;
	pthread_mutex_t mu;
	pthread_cond_t work_cv;
	pthread_cond_t step_cv;
	struct box2d_task_range *tasks_head;
	struct box2d_task_range *tasks_tail;
	struct box2d_callback_wait *callbacks_head;
	struct box2d_callback_wait *callbacks_tail;
	pthread_t threads[BOX2D_POOL_LIMIT];
	box2d_worker_slot worker_slot[BOX2D_POOL_LIMIT];
	struct box2d_world_ctx *next;
} box2d_world_ctx;

enum {
	BOX2D_CB_FRICTION = 1,
	BOX2D_CB_RESTITUTION,
	BOX2D_CB_FILTER,
	BOX2D_CB_PRESOLVE
};

/*
 * One PHP callback posted by a Box2D trampoline. Result pointers are written
 * by the stepping thread. manifold is the pre-solve contact, updated in place
 * when the callable returns. fallback_* is what the step uses when PHP does
 * not return a value.
 */
typedef struct box2d_callback_request {
	int kind;
	float scalar_a;
	float scalar_b;
	int material_a;
	int material_b;
	b2ShapeId shape_a;
	b2ShapeId shape_b;
	b2Manifold *manifold;
	float *float_result;
	bool *bool_result;
	float fallback_float;
	bool fallback_bool;
} box2d_callback_request;

ZEND_BEGIN_MODULE_GLOBALS(box2d)
	box2d_world_ctx *worlds;
ZEND_END_MODULE_GLOBALS(box2d)

ZEND_EXTERN_MODULE_GLOBALS(box2d)

#ifdef ZTS
#define BOX2D_G(v) TSRMG(box2d_globals_id, zend_box2d_globals *, v)
#else
#define BOX2D_G(v) (box2d_globals.v)
#endif

/* First assert on this thread. condition and file point at Box2D string literals. */
typedef struct box2d_assert_slot {
	const char *condition;
	const char *file;
	int line;
	bool pending;
} box2d_assert_slot;

extern _Thread_local box2d_assert_slot box2d_assert_tls;

/*
 * World whose Box2D call is on this thread's stack. Friction and restitution
 * trampolines read it because those C callbacks carry no context. Nested calls
 * save and restore the previous pointer.
 */
extern _Thread_local box2d_world_ctx *box2d_step_world;

/* Set for the life of a pool thread. NULL on the PHP thread until phase 8 starts a pool. */
extern _Thread_local box2d_world_ctx *box2d_pool_world;

/* Matches B2_SECRET_COOKIE in lib/box2d/src/core.h. */
#define BOX2D_SECRET_COOKIE 1152023

enum {
	BOX2D_ID_WORLD = 1,
	BOX2D_ID_BODY,
	BOX2D_ID_SHAPE,
	BOX2D_ID_CHAIN,
	BOX2D_ID_JOINT
};

/*
 * Ops the stepping thread may call on the world currently inside b2World_Step.
 * Any other op fails box2d_guard_step. The names are the Box2D functions.
 */
enum {
	BOX2D_OP_NONE = 0,
	BOX2D_OP_WORLD_IS_VALID,
	BOX2D_OP_BODY_IS_VALID,
	BOX2D_OP_SHAPE_IS_VALID,
	BOX2D_OP_CHAIN_IS_VALID,
	BOX2D_OP_JOINT_IS_VALID,
	BOX2D_OP_SHAPE_GET_BODY,
	BOX2D_OP_SHAPE_GET_WORLD,
	BOX2D_OP_SHAPE_GET_TYPE,
	BOX2D_OP_SHAPE_IS_SENSOR,
	BOX2D_OP_SHAPE_GET_USER_DATA,
	BOX2D_OP_SHAPE_GET_FILTER,
	BOX2D_OP_SHAPE_GET_DENSITY,
	BOX2D_OP_SHAPE_GET_FRICTION,
	BOX2D_OP_SHAPE_GET_RESTITUTION,
	BOX2D_OP_SHAPE_GET_MATERIAL,
	BOX2D_OP_SHAPE_GET_SURFACE_MATERIAL,
	BOX2D_OP_SHAPE_GET_PARENT_CHAIN,
	BOX2D_OP_BODY_GET_TYPE,
	BOX2D_OP_BODY_GET_USER_DATA,
	BOX2D_OP_BODY_GET_NAME,
	BOX2D_OP_BODY_GET_WORLD,
	BOX2D_OP_WORLD_GET_USER_DATA
};

void box2d_assert_check(void);

/* kind is BOX2D_ID_*. skip_live is 1 for the matching b2*_IsValid function. */
void box2d_guard_id(zval *id, int kind, int skip_live);

/*
 * No-op when world is not the world currently inside b2World_Step.
 * Call it after box2d_guard_id. Pass the id from box2d_tracked_world(), which
 * carries the generation stored at b2CreateWorld. A body id's world0 is not a
 * world generation; using it here would miss the world that is stepping.
 */
void box2d_guard_step(b2WorldId world, int op);

/* index1 of the tracked world, or a null id when this thread does not own it. */
b2WorldId box2d_tracked_world(uint16_t index1);

box2d_world_ctx *box2d_world_alloc(void);
void box2d_world_attach(box2d_world_ctx *ctx, b2WorldId id);
box2d_world_ctx *box2d_world_track(b2WorldId id);
void box2d_world_untrack(b2WorldId id);
void box2d_worlds_shutdown(void);

/* worker_count is already clamped to 1..BOX2D_POOL_LIMIT. FAILURE joins any threads that started. */
zend_result box2d_pool_start(box2d_world_ctx *ctx, int workers);
void box2d_pool_stop(box2d_world_ctx *ctx);
void *box2d_enqueue_task(b2TaskCallback *task, int item_count, int min_range, void *task_context, void *user_context);
void box2d_finish_task(void *user_task, void *user_context);
void box2d_queue_callback(box2d_world_ctx *world, const box2d_callback_request *req);
void box2d_run_callback(box2d_world_ctx *world, const box2d_callback_request *req);
void box2d_pool_assert_check(box2d_world_ctx *ctx);
void box2d_atfork_install(void);
void box2d_world_set_stepping(b2WorldId world, bool stepping);
void box2d_world_release_callbacks(box2d_world_ctx *ctx);

/* Direct on the stepping thread. Pool threads block until the stepping thread runs it. */
void box2d_invoke_callback(box2d_world_ctx *world, const box2d_callback_request *req);

float box2d_friction_trampoline(float friction_a, int material_a, float friction_b, int material_b);
float box2d_restitution_trampoline(float restitution_a, int material_a, float restitution_b, int material_b);

/* Save the current step-world pointer and install this world for the call. */
box2d_world_ctx *box2d_world_push(b2WorldId world);
void box2d_world_pop(box2d_world_ctx *previous);
box2d_world_ctx *box2d_world_lookup(b2WorldId world);

/* Process mutex around Box2D's world table. NTS builds leave it unlocked. */
void box2d_world_table_lock(void);
void box2d_world_table_unlock(void);

/* internalValue must be BOX2D_SECRET_COOKIE. */
void box2d_guard_cookie(zval *def);

/* Live-body and stepping checks for a joint def's bodyIdA and bodyIdB. */
void box2d_guard_joint_bodies(zval *def);

/* count must sit in 0..length. */
void box2d_guard_count(zend_long count, zend_long length, const char *what);

/*
 * NULL when name is null. Otherwise a thread-local buffer of 32 bytes.
 * The pointer is valid until the next call on this thread. b2Body_SetName
 * reads 31 bytes without stopping at a null, so the buffer is always that wide.
 * Longer than 31 characters throws ValueError and returns NULL.
 */
const char *box2d_body_name(zval *name);

static inline uint16_t box2d_world_index_from_world0(uint16_t world0)
{
	return (uint16_t)(world0 + 1u);
}

#endif
