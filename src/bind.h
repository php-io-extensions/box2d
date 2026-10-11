#ifndef BOX2D_BIND_H
#define BOX2D_BIND_H

#include "runtime.h"
#include "convert.h"

#include "zend_exceptions.h"

#include <stdint.h>

static inline zend_result box2d_bind_read(zval *zv, void *out, box2d_from_fn from)
{
	box2d_frame frame;

	box2d_frame_init(&frame);
	zend_result result = from(zv, out, &frame);
	box2d_frame_free(&frame);
	return result;
}

static inline zend_result box2d_bind_i32(zend_long value, int *out, const char *where)
{
	if (value < INT32_MIN || value > INT32_MAX) {
		zend_value_error("%s %lld is outside %lld..%lld", where, (long long) value, (long long) INT32_MIN, (long long) INT32_MAX);
		return FAILURE;
	}
	*out = (int) value;
	return SUCCESS;
}

zend_result box2d_store_list(zval *dest, int count, const void *src, size_t stride, zend_result (*to_zval)(const void *in, zval *out));

void box2d_store_double(zval *dest, double value);

#endif
