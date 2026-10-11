#include "convert.h"

#include <stdlib.h>
#include <string.h>

void box2d_frame_init(box2d_frame *frame)
{
	frame->blocks = NULL;
	frame->count = 0;
	frame->capacity = 0;
}

void *box2d_frame_alloc(box2d_frame *frame, size_t size)
{
	if (frame->count == frame->capacity) {
		uint32_t next = frame->capacity == 0 ? 4 : frame->capacity * 2;
		frame->blocks = erealloc(frame->blocks, next * sizeof(void *));
		frame->capacity = next;
	}

	void *block = emalloc(size);
	frame->blocks[frame->count++] = block;
	return block;
}

void box2d_frame_free(box2d_frame *frame)
{
	for (uint32_t i = 0; i < frame->count; i++) {
		efree(frame->blocks[i]);
	}
	if (frame->blocks != NULL) {
		efree(frame->blocks);
	}
	frame->blocks = NULL;
	frame->count = 0;
	frame->capacity = 0;
}

zend_result box2d_new_default(zend_class_entry *ce, zval *out)
{
	object_init_ex(out, ce);
	if (ce->constructor == NULL) {
		return SUCCESS;
	}

	zend_call_known_instance_method_with_0_params(ce->constructor, Z_OBJ_P(out), NULL);
	if (EG(exception)) {
		zval_ptr_dtor(out);
		ZVAL_UNDEF(out);
		return FAILURE;
	}

	return SUCCESS;
}

void box2d_set_long_list(zend_object *object, const char *name, size_t name_len, int length)
{
	zval list;
	array_init_size(&list, (uint32_t)length);
	for (int i = 0; i < length; i++) {
		add_next_index_long(&list, 0);
	}
	zend_update_property(object->ce, object, name, name_len, &list);
	zval_ptr_dtor(&list);
}

static zval *box2d_prop(zend_object *object, const char *name, size_t name_len)
{
	return zend_read_property(object->ce, object, name, name_len, 0, NULL);
}

static zend_result box2d_prop_long(zend_object *object, const char *name, size_t name_len, zend_long *out)
{
	zval *value = box2d_prop(object, name, name_len);
	if (value == NULL || Z_TYPE_P(value) != IS_LONG) {
		zend_type_error("%s::$%s must be an int", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	*out = Z_LVAL_P(value);
	return SUCCESS;
}

static zend_result box2d_narrow(zend_object *object, const char *name, size_t name_len, zend_long value, zend_long min, zend_long max, const char *width, zend_long *out)
{
	if (value < min || value > max) {
		zend_value_error("%s::$%s does not fit in %s", ZSTR_VAL(object->ce->name), name, width);
		return FAILURE;
	}
	*out = value;
	return SUCCESS;
}

zend_result box2d_prop_f32(zend_object *object, const char *name, size_t name_len, float *out)
{
	zval *value = box2d_prop(object, name, name_len);
	if (value == NULL || Z_TYPE_P(value) != IS_DOUBLE) {
		zend_type_error("%s::$%s must be a float", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	*out = (float)Z_DVAL_P(value);
	return SUCCESS;
}

zend_result box2d_prop_i32(zend_object *object, const char *name, size_t name_len, int *out)
{
	zend_long value;
	zend_long narrowed;
	if (box2d_prop_long(object, name, name_len, &value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_narrow(object, name, name_len, value, INT32_MIN, INT32_MAX, "int32", &narrowed) == FAILURE) {
		return FAILURE;
	}
	*out = (int)narrowed;
	return SUCCESS;
}

zend_result box2d_prop_u8(zend_object *object, const char *name, size_t name_len, uint8_t *out)
{
	zend_long value;
	zend_long narrowed;
	if (box2d_prop_long(object, name, name_len, &value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_narrow(object, name, name_len, value, 0, 255, "uint8", &narrowed) == FAILURE) {
		return FAILURE;
	}
	*out = (uint8_t)narrowed;
	return SUCCESS;
}

zend_result box2d_prop_u16(zend_object *object, const char *name, size_t name_len, uint16_t *out)
{
	zend_long value;
	zend_long narrowed;
	if (box2d_prop_long(object, name, name_len, &value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_narrow(object, name, name_len, value, 0, UINT16_MAX, "uint16", &narrowed) == FAILURE) {
		return FAILURE;
	}
	*out = (uint16_t)narrowed;
	return SUCCESS;
}

zend_result box2d_prop_u32(zend_object *object, const char *name, size_t name_len, uint32_t *out)
{
	zend_long value;
	zend_long narrowed;
	if (box2d_prop_long(object, name, name_len, &value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_narrow(object, name, name_len, value, 0, (zend_long)UINT32_MAX, "uint32", &narrowed) == FAILURE) {
		return FAILURE;
	}
	*out = (uint32_t)narrowed;
	return SUCCESS;
}

zend_result box2d_prop_u64(zend_object *object, const char *name, size_t name_len, uint64_t *out)
{
	zend_long value;
	if (box2d_prop_long(object, name, name_len, &value) == FAILURE) {
		return FAILURE;
	}
	*out = (uint64_t)(uintptr_t)value;
	return SUCCESS;
}

zend_result box2d_prop_bool(zend_object *object, const char *name, size_t name_len, bool *out)
{
	zval *value = box2d_prop(object, name, name_len);
	if (value == NULL || (Z_TYPE_P(value) != IS_TRUE && Z_TYPE_P(value) != IS_FALSE)) {
		zend_type_error("%s::$%s must be a bool", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	*out = Z_TYPE_P(value) == IS_TRUE;
	return SUCCESS;
}

zend_result box2d_prop_string(zend_object *object, const char *name, size_t name_len, const char **out)
{
	zval *value = box2d_prop(object, name, name_len);
	if (value == NULL || Z_TYPE_P(value) == IS_NULL || Z_TYPE_P(value) == IS_UNDEF) {
		*out = NULL;
		return SUCCESS;
	}
	if (Z_TYPE_P(value) != IS_STRING) {
		zend_type_error("%s::$%s must be a string or null", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	*out = Z_STRVAL_P(value);
	return SUCCESS;
}

zend_result box2d_prop_userdata(zend_object *object, const char *name, size_t name_len, void **out)
{
	uint64_t bits;
	if (box2d_prop_u64(object, name, name_len, &bits) == FAILURE) {
		return FAILURE;
	}
	*out = (void *)(uintptr_t)bits;
	return SUCCESS;
}

zend_result box2d_check_count(int count, int capacity, const char *where)
{
	if (count < 0 || (capacity >= 0 && count > capacity)) {
		if (capacity >= 0) {
			zend_value_error("%s %d is outside 0..%d", where, count, capacity);
		} else {
			zend_value_error("%s %d is negative", where, count);
		}
		return FAILURE;
	}
	return SUCCESS;
}

static zend_result box2d_array_slot(zend_object *object, const char *name, size_t name_len, int count, zval **list_out)
{
	zval *value = box2d_prop(object, name, name_len);
	if (value == NULL || Z_TYPE_P(value) != IS_ARRAY) {
		zend_type_error("%s::$%s must be an array", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	if ((zend_long)zend_hash_num_elements(Z_ARRVAL_P(value)) < count) {
		zend_value_error("%s::$%s is shorter than count", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	*list_out = value;
	return SUCCESS;
}

zend_result box2d_prop_struct(zend_object *object, const char *name, size_t name_len, box2d_from_fn from, void *dest, box2d_frame *frame)
{
	zval *value = box2d_prop(object, name, name_len);
	if (value == NULL || Z_TYPE_P(value) == IS_UNDEF) {
		zend_value_error("%s::$%s is uninitialized", ZSTR_VAL(object->ce->name), name);
		return FAILURE;
	}
	return from(value, dest, frame);
}

static zend_result box2d_fill_list(zval *list, zend_object *object, const char *name, int count, void *dest, size_t stride, box2d_from_fn from, box2d_frame *frame)
{
	for (int i = 0; i < count; i++) {
		zval *element = zend_hash_index_find(Z_ARRVAL_P(list), (zend_ulong)i);
		if (element == NULL) {
			zend_value_error("%s::$%s is shorter than count", ZSTR_VAL(object->ce->name), name);
			return FAILURE;
		}
		if (from(element, (char *)dest + (size_t)i * stride, frame) == FAILURE) {
			return FAILURE;
		}
	}
	return SUCCESS;
}

zend_result box2d_list_embedded(zend_object *object, const char *name, size_t name_len, int count, void *dest, size_t stride, box2d_from_fn from, box2d_frame *frame)
{
	zval *list;
	if (box2d_array_slot(object, name, name_len, count, &list) == FAILURE) {
		return FAILURE;
	}
	return box2d_fill_list(list, object, name, count, dest, stride, from, frame);
}

zend_result box2d_list_alloc(zend_object *object, const char *name, size_t name_len, int count, void **dest, size_t stride, box2d_from_fn from, box2d_frame *frame)
{
	zval *list;
	if (box2d_array_slot(object, name, name_len, count, &list) == FAILURE) {
		return FAILURE;
	}
	if (count == 0) {
		*dest = NULL;
		return SUCCESS;
	}
	void *block = box2d_frame_alloc(frame, (size_t)count * stride);
	if (box2d_fill_list(list, object, name, count, block, stride, from, frame) == FAILURE) {
		return FAILURE;
	}
	*dest = block;
	return SUCCESS;
}

zend_result box2d_list_u8(zend_object *object, const char *name, size_t name_len, int length, uint8_t *dest)
{
	zval *list;
	if (box2d_array_slot(object, name, name_len, length, &list) == FAILURE) {
		return FAILURE;
	}
	for (int i = 0; i < length; i++) {
		zval *element = zend_hash_index_find(Z_ARRVAL_P(list), (zend_ulong)i);
		if (element == NULL || Z_TYPE_P(element) != IS_LONG) {
			zend_type_error("%s::$%s[%d] must be an int", ZSTR_VAL(object->ce->name), name, i);
			return FAILURE;
		}
		zend_long value = Z_LVAL_P(element);
		if (value < 0 || value > 255) {
			zend_value_error("%s::$%s[%d] does not fit in uint8", ZSTR_VAL(object->ce->name), name, i);
			return FAILURE;
		}
		dest[i] = (uint8_t)value;
	}
	return SUCCESS;
}

zend_result box2d_list_i32(zend_object *object, const char *name, size_t name_len, int length, int *dest)
{
	zval *list;
	if (box2d_array_slot(object, name, name_len, length, &list) == FAILURE) {
		return FAILURE;
	}
	for (int i = 0; i < length; i++) {
		zval *element = zend_hash_index_find(Z_ARRVAL_P(list), (zend_ulong)i);
		if (element == NULL || Z_TYPE_P(element) != IS_LONG) {
			zend_type_error("%s::$%s[%d] must be an int", ZSTR_VAL(object->ce->name), name, i);
			return FAILURE;
		}
		zend_long value = Z_LVAL_P(element);
		if (value < INT32_MIN || value > INT32_MAX) {
			zend_value_error("%s::$%s[%d] does not fit in int32", ZSTR_VAL(object->ce->name), name, i);
			return FAILURE;
		}
		dest[i] = (int)value;
	}
	return SUCCESS;
}

void box2d_put_f32(zend_object *object, const char *name, size_t name_len, float value)
{
	zend_update_property_double(object->ce, object, name, name_len, (double)value);
}

void box2d_put_i32(zend_object *object, const char *name, size_t name_len, int value)
{
	zend_update_property_long(object->ce, object, name, name_len, value);
}

void box2d_put_u32(zend_object *object, const char *name, size_t name_len, uint32_t value)
{
	zend_update_property_long(object->ce, object, name, name_len, (zend_long)value);
}

void box2d_put_u64(zend_object *object, const char *name, size_t name_len, uint64_t value)
{
	zend_update_property_long(object->ce, object, name, name_len, (zend_long)(uintptr_t)value);
}

void box2d_put_bool(zend_object *object, const char *name, size_t name_len, bool value)
{
	zend_update_property_bool(object->ce, object, name, name_len, value);
}

void box2d_put_string(zend_object *object, const char *name, size_t name_len, const char *value)
{
	if (value == NULL) {
		zend_update_property_null(object->ce, object, name, name_len);
		return;
	}
	zend_update_property_string(object->ce, object, name, name_len, value);
}

void box2d_put_userdata(zend_object *object, const char *name, size_t name_len, void *value)
{
	box2d_put_u64(object, name, name_len, (uint64_t)(uintptr_t)value);
}

zend_result box2d_put_struct(zend_object *object, const char *name, size_t name_len, zend_result (*to_zval)(const void *in, zval *out), const void *value)
{
	zval child;
	if (to_zval(value, &child) == FAILURE) {
		return FAILURE;
	}
	zend_update_property(object->ce, object, name, name_len, &child);
	zval_ptr_dtor(&child);
	return SUCCESS;
}

zend_result box2d_put_struct_list(zend_object *object, const char *name, size_t name_len, int count, const void *src, size_t stride, zend_result (*to_zval)(const void *in, zval *out))
{
	zval list;
	array_init_size(&list, count < 0 ? 0 : (uint32_t)count);
	for (int i = 0; i < count; i++) {
		zval child;
		if (to_zval((const char *)src + (size_t)i * stride, &child) == FAILURE) {
			zval_ptr_dtor(&list);
			return FAILURE;
		}
		add_next_index_zval(&list, &child);
	}
	zend_update_property(object->ce, object, name, name_len, &list);
	zval_ptr_dtor(&list);
	return SUCCESS;
}

void box2d_put_u8_list(zend_object *object, const char *name, size_t name_len, int length, const uint8_t *src)
{
	zval list;
	array_init_size(&list, (uint32_t)length);
	for (int i = 0; i < length; i++) {
		add_next_index_long(&list, src[i]);
	}
	zend_update_property(object->ce, object, name, name_len, &list);
	zval_ptr_dtor(&list);
}

void box2d_put_i32_list(zend_object *object, const char *name, size_t name_len, int length, const int *src)
{
	zval list;
	array_init_size(&list, (uint32_t)length);
	for (int i = 0; i < length; i++) {
		add_next_index_long(&list, src[i]);
	}
	zend_update_property(object->ce, object, name, name_len, &list);
	zval_ptr_dtor(&list);
}
