#ifndef BOX2D_CONVERT_H
#define BOX2D_CONVERT_H

#include "runtime.h"

#include "zend_closures.h"
#include "zend_exceptions.h"

/*
 * Heap blocks a from_zval call allocated for pointer arrays (chain points,
 * event lists). Free the frame after the Box2D call that used the struct.
 * const char* fields are not copied: they point at the PHP string and stay
 * valid while that zval is alive. Callback function pointers are left NULL.
 * b2CreateWorld and b2World_Draw install their trampolines from the PHP
 * object; the C def does not own a Closure.
 */
typedef struct box2d_frame {
	void **blocks;
	uint32_t count;
	uint32_t capacity;
} box2d_frame;

typedef zend_result (*box2d_from_fn)(zval *zv, void *out, box2d_frame *frame);

void box2d_frame_init(box2d_frame *frame);
void *box2d_frame_alloc(box2d_frame *frame, size_t size);
void box2d_frame_free(box2d_frame *frame);

zend_result box2d_new_default(zend_class_entry *ce, zval *out);
void box2d_set_long_list(zend_object *object, const char *name, size_t name_len, int length);

zend_result box2d_prop_f32(zend_object *object, const char *name, size_t name_len, float *out);
zend_result box2d_prop_i32(zend_object *object, const char *name, size_t name_len, int *out);
zend_result box2d_prop_u8(zend_object *object, const char *name, size_t name_len, uint8_t *out);
zend_result box2d_prop_u16(zend_object *object, const char *name, size_t name_len, uint16_t *out);
zend_result box2d_prop_u32(zend_object *object, const char *name, size_t name_len, uint32_t *out);
zend_result box2d_prop_u64(zend_object *object, const char *name, size_t name_len, uint64_t *out);
zend_result box2d_prop_bool(zend_object *object, const char *name, size_t name_len, bool *out);
zend_result box2d_prop_string(zend_object *object, const char *name, size_t name_len, const char **out);
zend_result box2d_prop_userdata(zend_object *object, const char *name, size_t name_len, void **out);

zend_result box2d_check_count(int count, int capacity, const char *where);
zend_result box2d_prop_struct(zend_object *object, const char *name, size_t name_len, box2d_from_fn from, void *dest, box2d_frame *frame);
zend_result box2d_list_embedded(zend_object *object, const char *name, size_t name_len, int count, void *dest, size_t stride, box2d_from_fn from, box2d_frame *frame);
zend_result box2d_list_alloc(zend_object *object, const char *name, size_t name_len, int count, void **dest, size_t stride, box2d_from_fn from, box2d_frame *frame);
zend_result box2d_list_u8(zend_object *object, const char *name, size_t name_len, int length, uint8_t *dest);
zend_result box2d_list_i32(zend_object *object, const char *name, size_t name_len, int length, int *dest);

void box2d_put_f32(zend_object *object, const char *name, size_t name_len, float value);
void box2d_put_i32(zend_object *object, const char *name, size_t name_len, int value);
void box2d_put_u32(zend_object *object, const char *name, size_t name_len, uint32_t value);
void box2d_put_u64(zend_object *object, const char *name, size_t name_len, uint64_t value);
void box2d_put_bool(zend_object *object, const char *name, size_t name_len, bool value);
void box2d_put_string(zend_object *object, const char *name, size_t name_len, const char *value);
void box2d_put_userdata(zend_object *object, const char *name, size_t name_len, void *value);
zend_result box2d_put_struct(zend_object *object, const char *name, size_t name_len, zend_result (*to_zval)(const void *in, zval *out), const void *value);
zend_result box2d_put_struct_list(zend_object *object, const char *name, size_t name_len, int count, const void *src, size_t stride, zend_result (*to_zval)(const void *in, zval *out));
void box2d_put_u8_list(zend_object *object, const char *name, size_t name_len, int length, const uint8_t *src);
void box2d_put_i32_list(zend_object *object, const char *name, size_t name_len, int length, const int *src);

#include "convert_protos.h"

#endif
