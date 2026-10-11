#include "classes.h"

#include "box2d/collision.h"

#include <stdbool.h>
#include <string.h>

static zend_object_handlers box2d_value_handlers;
static zend_object_handlers box2d_tree_handlers;

typedef struct box2d_tree_object {
	b2DynamicTree tree;
	bool live;
	zend_object std;
} box2d_tree_object;

static box2d_tree_object *box2d_tree_from(zend_object *object)
{
	return (box2d_tree_object *)((char *)object - XtOffsetOf(box2d_tree_object, std));
}

static void box2d_deepen_zval(zval *value);

static void box2d_deepen_object(zend_object *object)
{
	zend_property_info *info;

	ZEND_HASH_FOREACH_PTR(&object->ce->properties_info, info) {
		if (info->flags & (ZEND_ACC_STATIC | ZEND_ACC_VIRTUAL)) {
			continue;
		}
		box2d_deepen_zval(OBJ_PROP(object, info->offset));
		if (EG(exception)) {
			return;
		}
	} ZEND_HASH_FOREACH_END();
}

static void box2d_deepen_zval(zval *value)
{
	if (Z_TYPE_P(value) == IS_INDIRECT) {
		value = Z_INDIRECT_P(value);
	}
	if (Z_ISREF_P(value)) {
		value = Z_REFVAL_P(value);
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		zend_object *child = Z_OBJ_P(value);
		if (child->handlers == NULL || child->handlers->clone_obj == NULL) {
			return;
		}
		zend_object *cloned = child->handlers->clone_obj(child);
		if (cloned == NULL || EG(exception)) {
			return;
		}
		zval_ptr_dtor(value);
		ZVAL_OBJ(value, cloned);
		return;
	}
	if (Z_TYPE_P(value) != IS_ARRAY) {
		return;
	}

	zend_array *copy = zend_array_dup(Z_ARRVAL_P(value));
	zval_ptr_dtor(value);
	ZVAL_ARR(value, copy);

	zval *element;
	ZEND_HASH_FOREACH_VAL(copy, element) {
		box2d_deepen_zval(element);
		if (EG(exception)) {
			return;
		}
	} ZEND_HASH_FOREACH_END();
}

static zend_object *box2d_value_clone(zend_object *old)
{
	zend_object *clone = zend_objects_new(old->ce);
	object_properties_init(clone, old->ce);
	zend_objects_clone_members(clone, old);
	if (!EG(exception)) {
		box2d_deepen_object(clone);
	}
	return clone;
}

void box2d_class_is_value(zend_class_entry *ce)
{
	ce->default_object_handlers = &box2d_value_handlers;
}

static void box2d_tree_free(zend_object *object)
{
	box2d_tree_object *tree = box2d_tree_from(object);
	if (tree->live) {
		b2DynamicTree_Destroy(&tree->tree);
		tree->live = false;
	}
	zend_object_std_dtor(object);
}

static zend_object *box2d_tree_create(zend_class_entry *ce)
{
	box2d_tree_object *tree = zend_object_alloc(sizeof(box2d_tree_object), ce);
	zend_object_std_init(&tree->std, ce);
	object_properties_init(&tree->std, ce);
	tree->std.handlers = &box2d_tree_handlers;
	tree->live = false;
	memset(&tree->tree, 0, sizeof(tree->tree));
	return &tree->std;
}

void box2d_class_is_tree(zend_class_entry *ce)
{
	memcpy(&box2d_tree_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	box2d_tree_handlers.free_obj = box2d_tree_free;
	box2d_tree_handlers.offset = XtOffsetOf(box2d_tree_object, std);
	box2d_tree_handlers.clone_obj = NULL;
	ce->create_object = box2d_tree_create;
	ce->default_object_handlers = &box2d_tree_handlers;
}

b2DynamicTree *box2d_tree_native(zend_object *object)
{
	return &box2d_tree_from(object)->tree;
}

bool box2d_tree_is_live(zend_object *object)
{
	return box2d_tree_from(object)->live;
}

void box2d_tree_set_live(zend_object *object, bool live)
{
	box2d_tree_from(object)->live = live;
}

void box2d_register_structs(int module_number)
{
	memcpy(&box2d_value_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	box2d_value_handlers.clone_obj = box2d_value_clone;
	box2d_register_math(module_number);
	box2d_register_collision(module_number);
	box2d_register_types(module_number);
}
