#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "runtime.h"
#include "classes.h"

#include "zend_exceptions.h"

#include <stdlib.h>
#include <string.h>

typedef struct box2d_task_handle {
	int outstanding;
} box2d_task_handle;

typedef struct box2d_task_range {
	b2TaskCallback *task;
	int start;
	int end;
	void *task_context;
	box2d_task_handle *handle;
	struct box2d_task_range *next;
} box2d_task_range;

typedef struct box2d_callback_wait {
	box2d_callback_request request;
	bool complete;
	pthread_cond_t done;
	struct box2d_callback_wait *next;
} box2d_callback_wait;

static void *box2d_worker_main(void *argument)
{
	box2d_worker_slot *slot = argument;
	box2d_world_ctx *ctx = slot->ctx;
	uint32_t index = slot->index;

	box2d_pool_world = ctx;

	pthread_mutex_lock(&ctx->mu);
	while (!ctx->pool_stop) {
		box2d_task_range *range = ctx->tasks_head;
		if (range == NULL) {
			pthread_cond_wait(&ctx->work_cv, &ctx->mu);
			continue;
		}
		ctx->tasks_head = range->next;
		if (ctx->tasks_head == NULL) {
			ctx->tasks_tail = NULL;
		}
		pthread_mutex_unlock(&ctx->mu);

		range->task(range->start, range->end, index, range->task_context);

		pthread_mutex_lock(&ctx->mu);
		if (box2d_assert_tls.pending && !ctx->assert_pending) {
			ctx->assert_condition = box2d_assert_tls.condition;
			ctx->assert_file = box2d_assert_tls.file;
			ctx->assert_line = box2d_assert_tls.line;
			ctx->assert_pending = true;
		}
		box2d_assert_tls.pending = false;
		box2d_assert_tls.condition = NULL;
		box2d_assert_tls.file = NULL;
		box2d_assert_tls.line = 0;
		range->handle->outstanding--;
		if (range->handle->outstanding == 0) {
			pthread_cond_signal(&ctx->step_cv);
		}
		free(range);
	}
	pthread_mutex_unlock(&ctx->mu);
	box2d_pool_world = NULL;
	return NULL;
}

zend_result box2d_pool_start(box2d_world_ctx *ctx, int workers)
{
	if (workers < 2) {
		workers = 2;
	}
	if (workers > BOX2D_POOL_LIMIT) {
		workers = BOX2D_POOL_LIMIT;
	}

	ctx->worker_count = workers;
	ctx->pool_stop = false;
	ctx->pool_dead = false;
	ctx->owner = pthread_self();
	if (pthread_mutex_init(&ctx->mu, NULL) != 0) {
		ctx->worker_count = 0;
		return FAILURE;
	}
	if (pthread_cond_init(&ctx->work_cv, NULL) != 0 || pthread_cond_init(&ctx->step_cv, NULL) != 0) {
		pthread_mutex_destroy(&ctx->mu);
		ctx->worker_count = 0;
		return FAILURE;
	}
	ctx->pool_started = true;

	for (int i = 0; i < workers; i++) {
		ctx->worker_slot[i].ctx = ctx;
		ctx->worker_slot[i].index = (uint32_t) i;
		if (pthread_create(&ctx->threads[i], NULL, box2d_worker_main, &ctx->worker_slot[i]) != 0) {
			ctx->worker_count = i;
			box2d_pool_stop(ctx);
			return FAILURE;
		}
	}
	return SUCCESS;
}

void box2d_pool_stop(box2d_world_ctx *ctx)
{
	if (ctx == NULL || !ctx->pool_started) {
		return;
	}
	if (ctx->pool_dead) {
		ctx->pool_started = false;
		return;
	}

	pthread_mutex_lock(&ctx->mu);
	ctx->pool_stop = true;
	pthread_cond_broadcast(&ctx->work_cv);
	pthread_mutex_unlock(&ctx->mu);
	for (int i = 0; i < ctx->worker_count; i++) {
		pthread_join(ctx->threads[i], NULL);
	}
	pthread_mutex_destroy(&ctx->mu);
	pthread_cond_destroy(&ctx->work_cv);
	pthread_cond_destroy(&ctx->step_cv);
	ctx->pool_started = false;
	ctx->worker_count = 0;
}

static void box2d_queue_range(box2d_world_ctx *ctx, box2d_task_range *range)
{
	range->next = NULL;
	if (ctx->tasks_tail == NULL) {
		ctx->tasks_head = range;
		ctx->tasks_tail = range;
		return;
	}
	ctx->tasks_tail->next = range;
	ctx->tasks_tail = range;
}

void *box2d_enqueue_task(b2TaskCallback *task, int item_count, int min_range, void *task_context, void *user_context)
{
	box2d_world_ctx *ctx = user_context;
	box2d_task_handle *handle = calloc(1, sizeof(*handle));
	int span = min_range < 1 ? 1 : min_range;
	int parts = 0;

	if (handle == NULL) {
		abort();
	}
	if (item_count > 0) {
		if (item_count < span) {
			parts = 1;
		} else {
			parts = item_count / span;
			if (parts < 1) {
				parts = 1;
			}
			if (parts > ctx->worker_count) {
				parts = ctx->worker_count;
			}
		}
	}
	handle->outstanding = parts;
	if (parts == 0) {
		return handle;
	}

	int base = item_count / parts;
	int remainder = item_count % parts;
	int cursor = 0;
	box2d_task_range *ranges = NULL;
	box2d_task_range *tail = NULL;

	for (int i = 0; i < parts; i++) {
		int length = base + (i < remainder ? 1 : 0);
		box2d_task_range *range = calloc(1, sizeof(*range));
		if (range == NULL) {
			abort();
		}
		range->task = task;
		range->start = cursor;
		range->end = cursor + length;
		range->task_context = task_context;
		range->handle = handle;
		cursor += length;
		if (tail == NULL) {
			ranges = range;
		} else {
			tail->next = range;
		}
		tail = range;
	}

	pthread_mutex_lock(&ctx->mu);
	for (box2d_task_range *range = ranges; range != NULL; ) {
		box2d_task_range *next = range->next;
		box2d_queue_range(ctx, range);
		range = next;
	}
	pthread_cond_broadcast(&ctx->work_cv);
	pthread_mutex_unlock(&ctx->mu);
	return handle;
}

void box2d_finish_task(void *user_task, void *user_context)
{
	box2d_world_ctx *ctx = user_context;
	box2d_task_handle *handle = user_task;

	if (handle == NULL || ctx == NULL) {
		return;
	}

	pthread_mutex_lock(&ctx->mu);
	while (handle->outstanding > 0 || ctx->callbacks_head != NULL) {
		box2d_callback_wait *wait = ctx->callbacks_head;
		if (wait != NULL) {
			ctx->callbacks_head = wait->next;
			if (ctx->callbacks_head == NULL) {
				ctx->callbacks_tail = NULL;
			}
			pthread_mutex_unlock(&ctx->mu);
			box2d_run_callback(ctx, &wait->request);
			pthread_mutex_lock(&ctx->mu);
			wait->complete = true;
			pthread_cond_signal(&wait->done);
			continue;
		}
		if (handle->outstanding > 0) {
			pthread_cond_wait(&ctx->step_cv, &ctx->mu);
		}
	}
	pthread_mutex_unlock(&ctx->mu);
	free(handle);
}

void box2d_queue_callback(box2d_world_ctx *world, const box2d_callback_request *req)
{
	box2d_callback_wait *wait = calloc(1, sizeof(*wait));

	if (wait == NULL) {
		abort();
	}
	wait->request = *req;
	pthread_cond_init(&wait->done, NULL);
	pthread_mutex_lock(&world->mu);
	if (world->callbacks_tail == NULL) {
		world->callbacks_head = wait;
	} else {
		world->callbacks_tail->next = wait;
	}
	world->callbacks_tail = wait;
	pthread_cond_signal(&world->step_cv);
	while (!wait->complete) {
		pthread_cond_wait(&wait->done, &world->mu);
	}
	pthread_mutex_unlock(&world->mu);
	pthread_cond_destroy(&wait->done);
	free(wait);
}

void box2d_pool_assert_check(box2d_world_ctx *ctx)
{
	const char *condition;
	const char *file;
	int line;
	bool pending;

	if (ctx == NULL || !ctx->pool_started || ctx->pool_dead || EG(exception)) {
		return;
	}
	pthread_mutex_lock(&ctx->mu);
	pending = ctx->assert_pending;
	condition = ctx->assert_condition != NULL ? ctx->assert_condition : "";
	file = ctx->assert_file != NULL ? ctx->assert_file : "";
	line = ctx->assert_line;
	ctx->assert_pending = false;
	ctx->assert_condition = NULL;
	ctx->assert_file = NULL;
	ctx->assert_line = 0;
	pthread_mutex_unlock(&ctx->mu);
	if (pending) {
		zend_throw_exception_ex(box2d_ce_b2AssertionError, 0, "%s at %s:%d", condition, file, line);
	}
}

static void box2d_atfork_child(void)
{
#ifdef ZTS
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	for (box2d_world_ctx *ctx = BOX2D_G(worlds); ctx != NULL; ctx = ctx->next) {
		if (ctx->pool_started && ctx->worker_count > 1) {
			ctx->pool_dead = true;
		}
	}
}

void box2d_atfork_install(void)
{
	pthread_atfork(NULL, NULL, box2d_atfork_child);
}
