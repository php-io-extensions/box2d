#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"


ZEND_FUNCTION(b2DefaultWorldDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2WorldDef box2d_result = b2DefaultWorldDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2WorldDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultBodyDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2BodyDef box2d_result = b2DefaultBodyDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2BodyDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultFilter)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2Filter box2d_result = b2DefaultFilter();
	box2d_assert_check();
	if (EG(exception) || box2d_b2Filter_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultQueryFilter)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2QueryFilter box2d_result = b2DefaultQueryFilter();
	box2d_assert_check();
	if (EG(exception) || box2d_b2QueryFilter_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultSurfaceMaterial)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2SurfaceMaterial box2d_result = b2DefaultSurfaceMaterial();
	box2d_assert_check();
	if (EG(exception) || box2d_b2SurfaceMaterial_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultShapeDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2ShapeDef box2d_result = b2DefaultShapeDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2ShapeDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultChainDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2ChainDef box2d_result = b2DefaultChainDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2ChainDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultDistanceJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2DistanceJointDef box2d_result = b2DefaultDistanceJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2DistanceJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultMotorJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2MotorJointDef box2d_result = b2DefaultMotorJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2MotorJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultMouseJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2MouseJointDef box2d_result = b2DefaultMouseJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2MouseJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultFilterJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2FilterJointDef box2d_result = b2DefaultFilterJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2FilterJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultPrismaticJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2PrismaticJointDef box2d_result = b2DefaultPrismaticJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2PrismaticJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultRevoluteJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2RevoluteJointDef box2d_result = b2DefaultRevoluteJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2RevoluteJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultWeldJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2WeldJointDef box2d_result = b2DefaultWeldJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2WeldJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultWheelJointDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2WheelJointDef box2d_result = b2DefaultWheelJointDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2WheelJointDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultExplosionDef)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2ExplosionDef box2d_result = b2DefaultExplosionDef();
	box2d_assert_check();
	if (EG(exception) || box2d_b2ExplosionDef_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2DefaultDebugDraw)
{
	ZEND_PARSE_PARAMETERS_NONE();

	b2DebugDraw box2d_result = b2DefaultDebugDraw();
	box2d_assert_check();
	if (EG(exception) || box2d_b2DebugDraw_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}
