#include "convert.h"
#include "classes.h"

#include "../stubs/id_arginfo.h"

zend_class_entry *box2d_ce_b2WorldId;
zend_class_entry *box2d_ce_b2BodyId;
zend_class_entry *box2d_ce_b2ShapeId;
zend_class_entry *box2d_ce_b2ChainId;
zend_class_entry *box2d_ce_b2JointId;

ZEND_METHOD(b2WorldId, __construct)
{
	zend_long index1 = 0;
	zend_long generation = 0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(index1)
		Z_PARAM_LONG(generation)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2WorldId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("index1"), index1);

	zend_update_property_long(box2d_ce_b2WorldId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("generation"), generation);

	b2WorldId native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2WorldId_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2BodyId, __construct)
{
	zend_long index1 = 0;
	zend_long world0 = 0;
	zend_long generation = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(index1)
		Z_PARAM_LONG(world0)
		Z_PARAM_LONG(generation)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2BodyId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("index1"), index1);

	zend_update_property_long(box2d_ce_b2BodyId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("world0"), world0);

	zend_update_property_long(box2d_ce_b2BodyId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("generation"), generation);

	b2BodyId native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2BodyId_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ShapeId, __construct)
{
	zend_long index1 = 0;
	zend_long world0 = 0;
	zend_long generation = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(index1)
		Z_PARAM_LONG(world0)
		Z_PARAM_LONG(generation)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2ShapeId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("index1"), index1);

	zend_update_property_long(box2d_ce_b2ShapeId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("world0"), world0);

	zend_update_property_long(box2d_ce_b2ShapeId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("generation"), generation);

	b2ShapeId native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ShapeId_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ChainId, __construct)
{
	zend_long index1 = 0;
	zend_long world0 = 0;
	zend_long generation = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(index1)
		Z_PARAM_LONG(world0)
		Z_PARAM_LONG(generation)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2ChainId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("index1"), index1);

	zend_update_property_long(box2d_ce_b2ChainId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("world0"), world0);

	zend_update_property_long(box2d_ce_b2ChainId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("generation"), generation);

	b2ChainId native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ChainId_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2JointId, __construct)
{
	zend_long index1 = 0;
	zend_long world0 = 0;
	zend_long generation = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(index1)
		Z_PARAM_LONG(world0)
		Z_PARAM_LONG(generation)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2JointId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("index1"), index1);

	zend_update_property_long(box2d_ce_b2JointId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("world0"), world0);

	zend_update_property_long(box2d_ce_b2JointId, Z_OBJ_P(ZEND_THIS), ZEND_STRL("generation"), generation);

	b2JointId native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2JointId_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

void box2d_register_ids(void)
{
	box2d_ce_b2WorldId = register_class_b2WorldId();
	box2d_class_is_value(box2d_ce_b2WorldId);
	box2d_ce_b2BodyId = register_class_b2BodyId();
	box2d_class_is_value(box2d_ce_b2BodyId);
	box2d_ce_b2ShapeId = register_class_b2ShapeId();
	box2d_class_is_value(box2d_ce_b2ShapeId);
	box2d_ce_b2ChainId = register_class_b2ChainId();
	box2d_class_is_value(box2d_ce_b2ChainId);
	box2d_ce_b2JointId = register_class_b2JointId();
	box2d_class_is_value(box2d_ce_b2JointId);
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
}
