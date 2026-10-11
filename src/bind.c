#include "bind.h"

zend_result box2d_store_list(zval *dest, int count, const void *src, size_t stride, zend_result (*to_zval)(const void *in, zval *out))
{
	zval list;

	array_init_size(&list, count > 0 ? (uint32_t) count : 0);
	for (int index = 0; index < count; index++) {
		zval item;
		if (to_zval((const char *) src + (size_t) index * stride, &item) == FAILURE) {
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

void box2d_store_double(zval *dest, double value)
{
	ZVAL_DEREF(dest);
	zval_ptr_dtor(dest);
	ZVAL_DOUBLE(dest, value);
}
