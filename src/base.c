#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "runtime.h"
#include "convert.h"

#include "zend_exceptions.h"

#include <stdint.h>

static zend_result box2d_u32_arg(zend_long value, uint32_t *out, const char *where)
{
	if (value < 0 || value > (zend_long) UINT32_MAX) {
		zend_value_error("%s %lld is outside 0..%u", where, (long long) value, UINT32_MAX);
		return FAILURE;
	}
	*out = (uint32_t) value;
	return SUCCESS;
}

static zend_result box2d_finish_call(void)
{
	box2d_assert_check();
	if (EG(exception)) {
		return FAILURE;
	}
	return SUCCESS;
}

ZEND_FUNCTION(b2GetByteCount)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int count = b2GetByteCount();
	if (box2d_finish_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG(count);
}

ZEND_FUNCTION(b2GetTicks)
{
	ZEND_PARSE_PARAMETERS_NONE();

	uint64_t ticks = b2GetTicks();
	if (box2d_finish_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) ticks);
}

ZEND_FUNCTION(b2GetMilliseconds)
{
	zend_long ticks;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ticks)
	ZEND_PARSE_PARAMETERS_END();

	float milliseconds = b2GetMilliseconds((uint64_t) ticks);
	if (box2d_finish_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(milliseconds);
}

ZEND_FUNCTION(b2GetMillisecondsAndReset)
{
	zval *ticks_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(ticks_zv)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_DEREF(ticks_zv);
	uint64_t ticks = (uint64_t) zval_get_long(ticks_zv);
	float milliseconds = b2GetMillisecondsAndReset(&ticks);
	if (box2d_finish_call() == FAILURE) {
		RETURN_THROWS();
	}
	ZVAL_LONG(ticks_zv, (zend_long) ticks);
	RETURN_DOUBLE(milliseconds);
}

ZEND_FUNCTION(b2Yield)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2Yield();
	if (box2d_finish_call() == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Hash)
{
	zend_long hash_in;
	zend_string *data;
	zend_long count_in;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(hash_in)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(count_in)
	ZEND_PARSE_PARAMETERS_END();

	uint32_t hash;
	if (box2d_u32_arg(hash_in, &hash, "b2Hash hash") == FAILURE) {
		RETURN_THROWS();
	}
	if (count_in < 0 || (uint64_t) count_in > ZSTR_LEN(data)) {
		zend_value_error("b2Hash count %lld is outside 0..%zu", (long long) count_in, ZSTR_LEN(data));
		RETURN_THROWS();
	}

	uint32_t result = b2Hash(hash, (const uint8_t *) ZSTR_VAL(data), (int) count_in);
	if (box2d_finish_call() == FAILURE) {
		RETURN_THROWS();
	}
	RETURN_LONG(result);
}
