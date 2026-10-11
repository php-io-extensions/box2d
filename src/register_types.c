#include "convert.h"
#include "classes.h"

#include "../stubs/types_arginfo.h"

zend_class_entry *box2d_ce_b2RayResult;
zend_class_entry *box2d_ce_b2WorldDef;
zend_class_entry *box2d_ce_b2BodyDef;
zend_class_entry *box2d_ce_b2Filter;
zend_class_entry *box2d_ce_b2QueryFilter;
zend_class_entry *box2d_ce_b2SurfaceMaterial;
zend_class_entry *box2d_ce_b2ShapeDef;
zend_class_entry *box2d_ce_b2ChainDef;
zend_class_entry *box2d_ce_b2Profile;
zend_class_entry *box2d_ce_b2Counters;
zend_class_entry *box2d_ce_b2DistanceJointDef;
zend_class_entry *box2d_ce_b2MotorJointDef;
zend_class_entry *box2d_ce_b2MouseJointDef;
zend_class_entry *box2d_ce_b2FilterJointDef;
zend_class_entry *box2d_ce_b2PrismaticJointDef;
zend_class_entry *box2d_ce_b2RevoluteJointDef;
zend_class_entry *box2d_ce_b2WeldJointDef;
zend_class_entry *box2d_ce_b2WheelJointDef;
zend_class_entry *box2d_ce_b2ExplosionDef;
zend_class_entry *box2d_ce_b2SensorBeginTouchEvent;
zend_class_entry *box2d_ce_b2SensorEndTouchEvent;
zend_class_entry *box2d_ce_b2SensorEvents;
zend_class_entry *box2d_ce_b2ContactBeginTouchEvent;
zend_class_entry *box2d_ce_b2ContactEndTouchEvent;
zend_class_entry *box2d_ce_b2ContactHitEvent;
zend_class_entry *box2d_ce_b2ContactEvents;
zend_class_entry *box2d_ce_b2BodyMoveEvent;
zend_class_entry *box2d_ce_b2BodyEvents;
zend_class_entry *box2d_ce_b2ContactData;
zend_class_entry *box2d_ce_b2DebugDraw;

ZEND_METHOD(b2RayResult, __construct)
{
	zval *shapeId = NULL;
	zval *point = NULL;
	zval *normal = NULL;
	double fraction = 0.0;
	zend_long nodeVisits = 0;
	zend_long leafVisits = 0;
	bool hit = false;

	ZEND_PARSE_PARAMETERS_START(0, 7)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(shapeId, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(point, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(normal, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(fraction)
		Z_PARAM_LONG(nodeVisits)
		Z_PARAM_LONG(leafVisits)
		Z_PARAM_BOOL(hit)
	ZEND_PARSE_PARAMETERS_END();

	if (shapeId == NULL) {
		zval created_shapeId;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeId) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeId"), &created_shapeId);
		zval_ptr_dtor(&created_shapeId);
	} else {
		zend_update_property(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeId"), shapeId);
	}

	if (point == NULL) {
		zval created_point;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), &created_point);
		zval_ptr_dtor(&created_point);
	} else {
		zend_update_property(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), point);
	}

	if (normal == NULL) {
		zval created_normal;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_normal) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), &created_normal);
		zval_ptr_dtor(&created_normal);
	} else {
		zend_update_property(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), normal);
	}

	zend_update_property_double(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fraction"), fraction);

	zend_update_property_long(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("nodeVisits"), nodeVisits);

	zend_update_property_long(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("leafVisits"), leafVisits);

	zend_update_property_bool(box2d_ce_b2RayResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hit"), hit);

	b2RayResult native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2RayResult_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2WorldDef, __construct)
{
	zval *gravity = NULL;
	double restitutionThreshold = 0.0;
	double hitEventThreshold = 0.0;
	double contactHertz = 0.0;
	double contactDampingRatio = 0.0;
	double maxContactPushSpeed = 0.0;
	double maximumLinearSpeed = 0.0;
	zval *frictionCallback = NULL;
	zval *restitutionCallback = NULL;
	bool enableSleep = false;
	bool enableContinuous = false;
	zend_long workerCount = 0;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 14)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(gravity, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(restitutionThreshold)
		Z_PARAM_DOUBLE(hitEventThreshold)
		Z_PARAM_DOUBLE(contactHertz)
		Z_PARAM_DOUBLE(contactDampingRatio)
		Z_PARAM_DOUBLE(maxContactPushSpeed)
		Z_PARAM_DOUBLE(maximumLinearSpeed)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(frictionCallback, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(restitutionCallback, zend_ce_closure)
		Z_PARAM_BOOL(enableSleep)
		Z_PARAM_BOOL(enableContinuous)
		Z_PARAM_LONG(workerCount)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (gravity == NULL) {
		zval created_gravity;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_gravity) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("gravity"), &created_gravity);
		zval_ptr_dtor(&created_gravity);
	} else {
		zend_update_property(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("gravity"), gravity);
	}

	zend_update_property_double(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("restitutionThreshold"), restitutionThreshold);

	zend_update_property_double(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hitEventThreshold"), hitEventThreshold);

	zend_update_property_double(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("contactHertz"), contactHertz);

	zend_update_property_double(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("contactDampingRatio"), contactDampingRatio);

	zend_update_property_double(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxContactPushSpeed"), maxContactPushSpeed);

	zend_update_property_double(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maximumLinearSpeed"), maximumLinearSpeed);

	if (frictionCallback == NULL || Z_TYPE_P(frictionCallback) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("frictionCallback"));
	} else {
		zend_update_property(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("frictionCallback"), frictionCallback);
	}

	if (restitutionCallback == NULL || Z_TYPE_P(restitutionCallback) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("restitutionCallback"));
	} else {
		zend_update_property(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("restitutionCallback"), restitutionCallback);
	}

	zend_update_property_bool(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSleep"), enableSleep);

	zend_update_property_bool(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableContinuous"), enableContinuous);

	zend_update_property_long(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("workerCount"), workerCount);

	zend_update_property_long(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2WorldDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2WorldDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2WorldDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2BodyDef, __construct)
{
	zend_long type = 0;
	zval *position = NULL;
	zval *rotation = NULL;
	zval *linearVelocity = NULL;
	double angularVelocity = 0.0;
	double linearDamping = 0.0;
	double angularDamping = 0.0;
	double gravityScale = 0.0;
	double sleepThreshold = 0.0;
	zend_string *name = NULL;
	zend_long userData = 0;
	bool enableSleep = false;
	bool isAwake = false;
	bool fixedRotation = false;
	bool isBullet = false;
	bool isEnabled = false;
	bool allowFastRotation = false;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 18)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(type)
		Z_PARAM_OBJECT_OF_CLASS(position, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(rotation, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(linearVelocity, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(angularVelocity)
		Z_PARAM_DOUBLE(linearDamping)
		Z_PARAM_DOUBLE(angularDamping)
		Z_PARAM_DOUBLE(gravityScale)
		Z_PARAM_DOUBLE(sleepThreshold)
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_LONG(userData)
		Z_PARAM_BOOL(enableSleep)
		Z_PARAM_BOOL(isAwake)
		Z_PARAM_BOOL(fixedRotation)
		Z_PARAM_BOOL(isBullet)
		Z_PARAM_BOOL(isEnabled)
		Z_PARAM_BOOL(allowFastRotation)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("type"), type);

	if (position == NULL) {
		zval created_position;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_position) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("position"), &created_position);
		zval_ptr_dtor(&created_position);
	} else {
		zend_update_property(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("position"), position);
	}

	if (rotation == NULL) {
		zval created_rotation;
		if (box2d_new_default(box2d_ce_b2Rot, &created_rotation) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("rotation"), &created_rotation);
		zval_ptr_dtor(&created_rotation);
	} else {
		zend_update_property(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("rotation"), rotation);
	}

	if (linearVelocity == NULL) {
		zval created_linearVelocity;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_linearVelocity) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearVelocity"), &created_linearVelocity);
		zval_ptr_dtor(&created_linearVelocity);
	} else {
		zend_update_property(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearVelocity"), linearVelocity);
	}

	zend_update_property_double(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("angularVelocity"), angularVelocity);

	zend_update_property_double(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearDamping"), linearDamping);

	zend_update_property_double(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("angularDamping"), angularDamping);

	zend_update_property_double(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("gravityScale"), gravityScale);

	zend_update_property_double(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sleepThreshold"), sleepThreshold);

	if (name == NULL) {
		zend_update_property_null(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("name"));
	} else {
		zend_update_property_str(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("name"), name);
	}

	zend_update_property_long(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_bool(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSleep"), enableSleep);

	zend_update_property_bool(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("isAwake"), isAwake);

	zend_update_property_bool(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fixedRotation"), fixedRotation);

	zend_update_property_bool(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("isBullet"), isBullet);

	zend_update_property_bool(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("isEnabled"), isEnabled);

	zend_update_property_bool(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("allowFastRotation"), allowFastRotation);

	zend_update_property_long(box2d_ce_b2BodyDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2BodyDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2BodyDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Filter, __construct)
{
	zend_long categoryBits = 0;
	zend_long maskBits = 0;
	zend_long groupIndex = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(categoryBits)
		Z_PARAM_LONG(maskBits)
		Z_PARAM_LONG(groupIndex)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2Filter, Z_OBJ_P(ZEND_THIS), ZEND_STRL("categoryBits"), categoryBits);

	zend_update_property_long(box2d_ce_b2Filter, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maskBits"), maskBits);

	zend_update_property_long(box2d_ce_b2Filter, Z_OBJ_P(ZEND_THIS), ZEND_STRL("groupIndex"), groupIndex);

	b2Filter native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Filter_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2QueryFilter, __construct)
{
	zend_long categoryBits = 0;
	zend_long maskBits = 0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(categoryBits)
		Z_PARAM_LONG(maskBits)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2QueryFilter, Z_OBJ_P(ZEND_THIS), ZEND_STRL("categoryBits"), categoryBits);

	zend_update_property_long(box2d_ce_b2QueryFilter, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maskBits"), maskBits);

	b2QueryFilter native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2QueryFilter_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SurfaceMaterial, __construct)
{
	double friction = 0.0;
	double restitution = 0.0;
	double rollingResistance = 0.0;
	double tangentSpeed = 0.0;
	zend_long userMaterialId = 0;
	zend_long customColor = 0;

	ZEND_PARSE_PARAMETERS_START(0, 6)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(friction)
		Z_PARAM_DOUBLE(restitution)
		Z_PARAM_DOUBLE(rollingResistance)
		Z_PARAM_DOUBLE(tangentSpeed)
		Z_PARAM_LONG(userMaterialId)
		Z_PARAM_LONG(customColor)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_double(box2d_ce_b2SurfaceMaterial, Z_OBJ_P(ZEND_THIS), ZEND_STRL("friction"), friction);

	zend_update_property_double(box2d_ce_b2SurfaceMaterial, Z_OBJ_P(ZEND_THIS), ZEND_STRL("restitution"), restitution);

	zend_update_property_double(box2d_ce_b2SurfaceMaterial, Z_OBJ_P(ZEND_THIS), ZEND_STRL("rollingResistance"), rollingResistance);

	zend_update_property_double(box2d_ce_b2SurfaceMaterial, Z_OBJ_P(ZEND_THIS), ZEND_STRL("tangentSpeed"), tangentSpeed);

	zend_update_property_long(box2d_ce_b2SurfaceMaterial, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userMaterialId"), userMaterialId);

	zend_update_property_long(box2d_ce_b2SurfaceMaterial, Z_OBJ_P(ZEND_THIS), ZEND_STRL("customColor"), customColor);

	b2SurfaceMaterial native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SurfaceMaterial_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ShapeDef, __construct)
{
	zend_long userData = 0;
	zval *material = NULL;
	double density = 0.0;
	zval *filter = NULL;
	bool isSensor = false;
	bool enableSensorEvents = false;
	bool enableContactEvents = false;
	bool enableHitEvents = false;
	bool enablePreSolveEvents = false;
	bool invokeContactCreation = false;
	bool updateBodyMass = false;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 12)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(userData)
		Z_PARAM_OBJECT_OF_CLASS(material, box2d_ce_b2SurfaceMaterial)
		Z_PARAM_DOUBLE(density)
		Z_PARAM_OBJECT_OF_CLASS(filter, box2d_ce_b2Filter)
		Z_PARAM_BOOL(isSensor)
		Z_PARAM_BOOL(enableSensorEvents)
		Z_PARAM_BOOL(enableContactEvents)
		Z_PARAM_BOOL(enableHitEvents)
		Z_PARAM_BOOL(enablePreSolveEvents)
		Z_PARAM_BOOL(invokeContactCreation)
		Z_PARAM_BOOL(updateBodyMass)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	if (material == NULL) {
		zval created_material;
		if (box2d_new_default(box2d_ce_b2SurfaceMaterial, &created_material) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("material"), &created_material);
		zval_ptr_dtor(&created_material);
	} else {
		zend_update_property(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("material"), material);
	}

	zend_update_property_double(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("density"), density);

	if (filter == NULL) {
		zval created_filter;
		if (box2d_new_default(box2d_ce_b2Filter, &created_filter) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("filter"), &created_filter);
		zval_ptr_dtor(&created_filter);
	} else {
		zend_update_property(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("filter"), filter);
	}

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("isSensor"), isSensor);

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSensorEvents"), enableSensorEvents);

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableContactEvents"), enableContactEvents);

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableHitEvents"), enableHitEvents);

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enablePreSolveEvents"), enablePreSolveEvents);

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("invokeContactCreation"), invokeContactCreation);

	zend_update_property_bool(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("updateBodyMass"), updateBodyMass);

	zend_update_property_long(box2d_ce_b2ShapeDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2ShapeDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ShapeDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ChainDef, __construct)
{
	zend_long userData = 0;
	zval *points = NULL;
	zend_long count = 0;
	zval *materials = NULL;
	zend_long materialCount = 0;
	zval *filter = NULL;
	bool isLoop = false;
	bool enableSensorEvents = false;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 9)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(userData)
		Z_PARAM_ARRAY(points)
		Z_PARAM_LONG(count)
		Z_PARAM_ARRAY(materials)
		Z_PARAM_LONG(materialCount)
		Z_PARAM_OBJECT_OF_CLASS(filter, box2d_ce_b2Filter)
		Z_PARAM_BOOL(isLoop)
		Z_PARAM_BOOL(enableSensorEvents)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	if (points == NULL) {
		zval empty_points;
		array_init(&empty_points);
		zend_update_property(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), &empty_points);
		zval_ptr_dtor(&empty_points);
	} else {
		zend_update_property(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), points);
	}

	zend_update_property_long(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("count"), count);

	if (materials == NULL) {
		zval empty_materials;
		array_init(&empty_materials);
		zend_update_property(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("materials"), &empty_materials);
		zval_ptr_dtor(&empty_materials);
	} else {
		zend_update_property(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("materials"), materials);
	}

	zend_update_property_long(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("materialCount"), materialCount);

	if (filter == NULL) {
		zval created_filter;
		if (box2d_new_default(box2d_ce_b2Filter, &created_filter) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("filter"), &created_filter);
		zval_ptr_dtor(&created_filter);
	} else {
		zend_update_property(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("filter"), filter);
	}

	zend_update_property_bool(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("isLoop"), isLoop);

	zend_update_property_bool(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSensorEvents"), enableSensorEvents);

	zend_update_property_long(box2d_ce_b2ChainDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2ChainDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ChainDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Profile, __construct)
{
	double step = 0.0;
	double pairs = 0.0;
	double collide = 0.0;
	double solve = 0.0;
	double mergeIslands = 0.0;
	double prepareStages = 0.0;
	double solveConstraints = 0.0;
	double prepareConstraints = 0.0;
	double integrateVelocities = 0.0;
	double warmStart = 0.0;
	double solveImpulses = 0.0;
	double integratePositions = 0.0;
	double relaxImpulses = 0.0;
	double applyRestitution = 0.0;
	double storeImpulses = 0.0;
	double splitIslands = 0.0;
	double transforms = 0.0;
	double hitEvents = 0.0;
	double refit = 0.0;
	double bullets = 0.0;
	double sleepIslands = 0.0;
	double sensors = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 22)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(step)
		Z_PARAM_DOUBLE(pairs)
		Z_PARAM_DOUBLE(collide)
		Z_PARAM_DOUBLE(solve)
		Z_PARAM_DOUBLE(mergeIslands)
		Z_PARAM_DOUBLE(prepareStages)
		Z_PARAM_DOUBLE(solveConstraints)
		Z_PARAM_DOUBLE(prepareConstraints)
		Z_PARAM_DOUBLE(integrateVelocities)
		Z_PARAM_DOUBLE(warmStart)
		Z_PARAM_DOUBLE(solveImpulses)
		Z_PARAM_DOUBLE(integratePositions)
		Z_PARAM_DOUBLE(relaxImpulses)
		Z_PARAM_DOUBLE(applyRestitution)
		Z_PARAM_DOUBLE(storeImpulses)
		Z_PARAM_DOUBLE(splitIslands)
		Z_PARAM_DOUBLE(transforms)
		Z_PARAM_DOUBLE(hitEvents)
		Z_PARAM_DOUBLE(refit)
		Z_PARAM_DOUBLE(bullets)
		Z_PARAM_DOUBLE(sleepIslands)
		Z_PARAM_DOUBLE(sensors)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("step"), step);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pairs"), pairs);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collide"), collide);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("solve"), solve);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("mergeIslands"), mergeIslands);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("prepareStages"), prepareStages);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("solveConstraints"), solveConstraints);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("prepareConstraints"), prepareConstraints);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("integrateVelocities"), integrateVelocities);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("warmStart"), warmStart);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("solveImpulses"), solveImpulses);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("integratePositions"), integratePositions);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("relaxImpulses"), relaxImpulses);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("applyRestitution"), applyRestitution);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("storeImpulses"), storeImpulses);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("splitIslands"), splitIslands);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transforms"), transforms);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hitEvents"), hitEvents);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("refit"), refit);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bullets"), bullets);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sleepIslands"), sleepIslands);

	zend_update_property_double(box2d_ce_b2Profile, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sensors"), sensors);

	b2Profile native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Profile_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Counters, __construct)
{
	zend_long bodyCount = 0;
	zend_long shapeCount = 0;
	zend_long contactCount = 0;
	zend_long jointCount = 0;
	zend_long islandCount = 0;
	zend_long stackUsed = 0;
	zend_long staticTreeHeight = 0;
	zend_long treeHeight = 0;
	zend_long byteCount = 0;
	zend_long taskCount = 0;
	zval *colorCounts = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 11)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(bodyCount)
		Z_PARAM_LONG(shapeCount)
		Z_PARAM_LONG(contactCount)
		Z_PARAM_LONG(jointCount)
		Z_PARAM_LONG(islandCount)
		Z_PARAM_LONG(stackUsed)
		Z_PARAM_LONG(staticTreeHeight)
		Z_PARAM_LONG(treeHeight)
		Z_PARAM_LONG(byteCount)
		Z_PARAM_LONG(taskCount)
		Z_PARAM_ARRAY(colorCounts)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyCount"), bodyCount);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeCount"), shapeCount);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("contactCount"), contactCount);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("jointCount"), jointCount);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("islandCount"), islandCount);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("stackUsed"), stackUsed);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("staticTreeHeight"), staticTreeHeight);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("treeHeight"), treeHeight);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("byteCount"), byteCount);

	zend_update_property_long(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("taskCount"), taskCount);

	if (colorCounts == NULL) {
		box2d_set_long_list(Z_OBJ_P(ZEND_THIS), ZEND_STRL("colorCounts"), 12);
	} else {
		zend_update_property(box2d_ce_b2Counters, Z_OBJ_P(ZEND_THIS), ZEND_STRL("colorCounts"), colorCounts);
	}

	b2Counters native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Counters_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2DistanceJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *localAnchorA = NULL;
	zval *localAnchorB = NULL;
	double length = 0.0;
	bool enableSpring = false;
	double hertz = 0.0;
	double dampingRatio = 0.0;
	bool enableLimit = false;
	double minLength = 0.0;
	double maxLength = 0.0;
	bool enableMotor = false;
	double maxMotorForce = 0.0;
	double motorSpeed = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 17)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorB, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(length)
		Z_PARAM_BOOL(enableSpring)
		Z_PARAM_DOUBLE(hertz)
		Z_PARAM_DOUBLE(dampingRatio)
		Z_PARAM_BOOL(enableLimit)
		Z_PARAM_DOUBLE(minLength)
		Z_PARAM_DOUBLE(maxLength)
		Z_PARAM_BOOL(enableMotor)
		Z_PARAM_DOUBLE(maxMotorForce)
		Z_PARAM_DOUBLE(motorSpeed)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (localAnchorA == NULL) {
		zval created_localAnchorA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), &created_localAnchorA);
		zval_ptr_dtor(&created_localAnchorA);
	} else {
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), localAnchorA);
	}

	if (localAnchorB == NULL) {
		zval created_localAnchorB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), &created_localAnchorB);
		zval_ptr_dtor(&created_localAnchorB);
	} else {
		zend_update_property(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), localAnchorB);
	}

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("length"), length);

	zend_update_property_bool(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSpring"), enableSpring);

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hertz"), hertz);

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("dampingRatio"), dampingRatio);

	zend_update_property_bool(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableLimit"), enableLimit);

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("minLength"), minLength);

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxLength"), maxLength);

	zend_update_property_bool(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableMotor"), enableMotor);

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxMotorForce"), maxMotorForce);

	zend_update_property_double(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("motorSpeed"), motorSpeed);

	zend_update_property_bool(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2DistanceJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2DistanceJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2DistanceJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2MotorJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *linearOffset = NULL;
	double angularOffset = 0.0;
	double maxForce = 0.0;
	double maxTorque = 0.0;
	double correctionFactor = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 10)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(linearOffset, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(angularOffset)
		Z_PARAM_DOUBLE(maxForce)
		Z_PARAM_DOUBLE(maxTorque)
		Z_PARAM_DOUBLE(correctionFactor)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (linearOffset == NULL) {
		zval created_linearOffset;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_linearOffset) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearOffset"), &created_linearOffset);
		zval_ptr_dtor(&created_linearOffset);
	} else {
		zend_update_property(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearOffset"), linearOffset);
	}

	zend_update_property_double(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("angularOffset"), angularOffset);

	zend_update_property_double(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxForce"), maxForce);

	zend_update_property_double(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxTorque"), maxTorque);

	zend_update_property_double(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("correctionFactor"), correctionFactor);

	zend_update_property_bool(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2MotorJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2MotorJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2MotorJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2MouseJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *target = NULL;
	double hertz = 0.0;
	double dampingRatio = 0.0;
	double maxForce = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 9)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(target, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(hertz)
		Z_PARAM_DOUBLE(dampingRatio)
		Z_PARAM_DOUBLE(maxForce)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (target == NULL) {
		zval created_target;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_target) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("target"), &created_target);
		zval_ptr_dtor(&created_target);
	} else {
		zend_update_property(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("target"), target);
	}

	zend_update_property_double(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hertz"), hertz);

	zend_update_property_double(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("dampingRatio"), dampingRatio);

	zend_update_property_double(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxForce"), maxForce);

	zend_update_property_bool(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2MouseJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2MouseJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2MouseJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2FilterJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2FilterJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2FilterJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2FilterJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2FilterJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	zend_update_property_long(box2d_ce_b2FilterJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2FilterJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2FilterJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2FilterJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2PrismaticJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *localAnchorA = NULL;
	zval *localAnchorB = NULL;
	zval *localAxisA = NULL;
	double referenceAngle = 0.0;
	double targetTranslation = 0.0;
	bool enableSpring = false;
	double hertz = 0.0;
	double dampingRatio = 0.0;
	bool enableLimit = false;
	double lowerTranslation = 0.0;
	double upperTranslation = 0.0;
	bool enableMotor = false;
	double maxMotorForce = 0.0;
	double motorSpeed = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 19)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorB, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAxisA, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(referenceAngle)
		Z_PARAM_DOUBLE(targetTranslation)
		Z_PARAM_BOOL(enableSpring)
		Z_PARAM_DOUBLE(hertz)
		Z_PARAM_DOUBLE(dampingRatio)
		Z_PARAM_BOOL(enableLimit)
		Z_PARAM_DOUBLE(lowerTranslation)
		Z_PARAM_DOUBLE(upperTranslation)
		Z_PARAM_BOOL(enableMotor)
		Z_PARAM_DOUBLE(maxMotorForce)
		Z_PARAM_DOUBLE(motorSpeed)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (localAnchorA == NULL) {
		zval created_localAnchorA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), &created_localAnchorA);
		zval_ptr_dtor(&created_localAnchorA);
	} else {
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), localAnchorA);
	}

	if (localAnchorB == NULL) {
		zval created_localAnchorB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), &created_localAnchorB);
		zval_ptr_dtor(&created_localAnchorB);
	} else {
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), localAnchorB);
	}

	if (localAxisA == NULL) {
		zval created_localAxisA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAxisA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAxisA"), &created_localAxisA);
		zval_ptr_dtor(&created_localAxisA);
	} else {
		zend_update_property(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAxisA"), localAxisA);
	}

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("referenceAngle"), referenceAngle);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("targetTranslation"), targetTranslation);

	zend_update_property_bool(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSpring"), enableSpring);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hertz"), hertz);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("dampingRatio"), dampingRatio);

	zend_update_property_bool(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableLimit"), enableLimit);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("lowerTranslation"), lowerTranslation);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("upperTranslation"), upperTranslation);

	zend_update_property_bool(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableMotor"), enableMotor);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxMotorForce"), maxMotorForce);

	zend_update_property_double(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("motorSpeed"), motorSpeed);

	zend_update_property_bool(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2PrismaticJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2PrismaticJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2PrismaticJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2RevoluteJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *localAnchorA = NULL;
	zval *localAnchorB = NULL;
	double referenceAngle = 0.0;
	double targetAngle = 0.0;
	bool enableSpring = false;
	double hertz = 0.0;
	double dampingRatio = 0.0;
	bool enableLimit = false;
	double lowerAngle = 0.0;
	double upperAngle = 0.0;
	bool enableMotor = false;
	double maxMotorTorque = 0.0;
	double motorSpeed = 0.0;
	double drawSize = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 19)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorB, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(referenceAngle)
		Z_PARAM_DOUBLE(targetAngle)
		Z_PARAM_BOOL(enableSpring)
		Z_PARAM_DOUBLE(hertz)
		Z_PARAM_DOUBLE(dampingRatio)
		Z_PARAM_BOOL(enableLimit)
		Z_PARAM_DOUBLE(lowerAngle)
		Z_PARAM_DOUBLE(upperAngle)
		Z_PARAM_BOOL(enableMotor)
		Z_PARAM_DOUBLE(maxMotorTorque)
		Z_PARAM_DOUBLE(motorSpeed)
		Z_PARAM_DOUBLE(drawSize)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (localAnchorA == NULL) {
		zval created_localAnchorA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), &created_localAnchorA);
		zval_ptr_dtor(&created_localAnchorA);
	} else {
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), localAnchorA);
	}

	if (localAnchorB == NULL) {
		zval created_localAnchorB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), &created_localAnchorB);
		zval_ptr_dtor(&created_localAnchorB);
	} else {
		zend_update_property(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), localAnchorB);
	}

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("referenceAngle"), referenceAngle);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("targetAngle"), targetAngle);

	zend_update_property_bool(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSpring"), enableSpring);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hertz"), hertz);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("dampingRatio"), dampingRatio);

	zend_update_property_bool(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableLimit"), enableLimit);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("lowerAngle"), lowerAngle);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("upperAngle"), upperAngle);

	zend_update_property_bool(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableMotor"), enableMotor);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxMotorTorque"), maxMotorTorque);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("motorSpeed"), motorSpeed);

	zend_update_property_double(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawSize"), drawSize);

	zend_update_property_bool(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2RevoluteJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2RevoluteJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2RevoluteJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2WeldJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *localAnchorA = NULL;
	zval *localAnchorB = NULL;
	double referenceAngle = 0.0;
	double linearHertz = 0.0;
	double angularHertz = 0.0;
	double linearDampingRatio = 0.0;
	double angularDampingRatio = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 12)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorB, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(referenceAngle)
		Z_PARAM_DOUBLE(linearHertz)
		Z_PARAM_DOUBLE(angularHertz)
		Z_PARAM_DOUBLE(linearDampingRatio)
		Z_PARAM_DOUBLE(angularDampingRatio)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (localAnchorA == NULL) {
		zval created_localAnchorA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), &created_localAnchorA);
		zval_ptr_dtor(&created_localAnchorA);
	} else {
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), localAnchorA);
	}

	if (localAnchorB == NULL) {
		zval created_localAnchorB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), &created_localAnchorB);
		zval_ptr_dtor(&created_localAnchorB);
	} else {
		zend_update_property(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), localAnchorB);
	}

	zend_update_property_double(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("referenceAngle"), referenceAngle);

	zend_update_property_double(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearHertz"), linearHertz);

	zend_update_property_double(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("angularHertz"), angularHertz);

	zend_update_property_double(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("linearDampingRatio"), linearDampingRatio);

	zend_update_property_double(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("angularDampingRatio"), angularDampingRatio);

	zend_update_property_bool(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2WeldJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2WeldJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2WeldJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2WheelJointDef, __construct)
{
	zval *bodyIdA = NULL;
	zval *bodyIdB = NULL;
	zval *localAnchorA = NULL;
	zval *localAnchorB = NULL;
	zval *localAxisA = NULL;
	bool enableSpring = false;
	double hertz = 0.0;
	double dampingRatio = 0.0;
	bool enableLimit = false;
	double lowerTranslation = 0.0;
	double upperTranslation = 0.0;
	bool enableMotor = false;
	double maxMotorTorque = 0.0;
	double motorSpeed = 0.0;
	bool collideConnected = false;
	zend_long userData = 0;
	zend_long internalValue = 0;

	ZEND_PARSE_PARAMETERS_START(0, 17)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(bodyIdA, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(bodyIdB, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAnchorB, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(localAxisA, box2d_ce_b2Vec2)
		Z_PARAM_BOOL(enableSpring)
		Z_PARAM_DOUBLE(hertz)
		Z_PARAM_DOUBLE(dampingRatio)
		Z_PARAM_BOOL(enableLimit)
		Z_PARAM_DOUBLE(lowerTranslation)
		Z_PARAM_DOUBLE(upperTranslation)
		Z_PARAM_BOOL(enableMotor)
		Z_PARAM_DOUBLE(maxMotorTorque)
		Z_PARAM_DOUBLE(motorSpeed)
		Z_PARAM_BOOL(collideConnected)
		Z_PARAM_LONG(userData)
		Z_PARAM_LONG(internalValue)
	ZEND_PARSE_PARAMETERS_END();

	if (bodyIdA == NULL) {
		zval created_bodyIdA;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), &created_bodyIdA);
		zval_ptr_dtor(&created_bodyIdA);
	} else {
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdA"), bodyIdA);
	}

	if (bodyIdB == NULL) {
		zval created_bodyIdB;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), &created_bodyIdB);
		zval_ptr_dtor(&created_bodyIdB);
	} else {
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyIdB"), bodyIdB);
	}

	if (localAnchorA == NULL) {
		zval created_localAnchorA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), &created_localAnchorA);
		zval_ptr_dtor(&created_localAnchorA);
	} else {
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorA"), localAnchorA);
	}

	if (localAnchorB == NULL) {
		zval created_localAnchorB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAnchorB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), &created_localAnchorB);
		zval_ptr_dtor(&created_localAnchorB);
	} else {
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAnchorB"), localAnchorB);
	}

	if (localAxisA == NULL) {
		zval created_localAxisA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localAxisA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAxisA"), &created_localAxisA);
		zval_ptr_dtor(&created_localAxisA);
	} else {
		zend_update_property(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localAxisA"), localAxisA);
	}

	zend_update_property_bool(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableSpring"), enableSpring);

	zend_update_property_double(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hertz"), hertz);

	zend_update_property_double(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("dampingRatio"), dampingRatio);

	zend_update_property_bool(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableLimit"), enableLimit);

	zend_update_property_double(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("lowerTranslation"), lowerTranslation);

	zend_update_property_double(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("upperTranslation"), upperTranslation);

	zend_update_property_bool(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("enableMotor"), enableMotor);

	zend_update_property_double(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxMotorTorque"), maxMotorTorque);

	zend_update_property_double(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("motorSpeed"), motorSpeed);

	zend_update_property_bool(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("collideConnected"), collideConnected);

	zend_update_property_long(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_long(box2d_ce_b2WheelJointDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("internalValue"), internalValue);

	b2WheelJointDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2WheelJointDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ExplosionDef, __construct)
{
	zend_long maskBits = 0;
	zval *position = NULL;
	double radius = 0.0;
	double falloff = 0.0;
	double impulsePerLength = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(maskBits)
		Z_PARAM_OBJECT_OF_CLASS(position, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(radius)
		Z_PARAM_DOUBLE(falloff)
		Z_PARAM_DOUBLE(impulsePerLength)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2ExplosionDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maskBits"), maskBits);

	if (position == NULL) {
		zval created_position;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_position) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ExplosionDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("position"), &created_position);
		zval_ptr_dtor(&created_position);
	} else {
		zend_update_property(box2d_ce_b2ExplosionDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("position"), position);
	}

	zend_update_property_double(box2d_ce_b2ExplosionDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("radius"), radius);

	zend_update_property_double(box2d_ce_b2ExplosionDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("falloff"), falloff);

	zend_update_property_double(box2d_ce_b2ExplosionDef, Z_OBJ_P(ZEND_THIS), ZEND_STRL("impulsePerLength"), impulsePerLength);

	b2ExplosionDef native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ExplosionDef_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SensorBeginTouchEvent, __construct)
{
	zval *sensorShapeId = NULL;
	zval *visitorShapeId = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(sensorShapeId, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(visitorShapeId, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	if (sensorShapeId == NULL) {
		zval created_sensorShapeId;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_sensorShapeId) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SensorBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sensorShapeId"), &created_sensorShapeId);
		zval_ptr_dtor(&created_sensorShapeId);
	} else {
		zend_update_property(box2d_ce_b2SensorBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sensorShapeId"), sensorShapeId);
	}

	if (visitorShapeId == NULL) {
		zval created_visitorShapeId;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_visitorShapeId) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SensorBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("visitorShapeId"), &created_visitorShapeId);
		zval_ptr_dtor(&created_visitorShapeId);
	} else {
		zend_update_property(box2d_ce_b2SensorBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("visitorShapeId"), visitorShapeId);
	}

	b2SensorBeginTouchEvent native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SensorBeginTouchEvent_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SensorEndTouchEvent, __construct)
{
	zval *sensorShapeId = NULL;
	zval *visitorShapeId = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(sensorShapeId, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(visitorShapeId, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	if (sensorShapeId == NULL) {
		zval created_sensorShapeId;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_sensorShapeId) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SensorEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sensorShapeId"), &created_sensorShapeId);
		zval_ptr_dtor(&created_sensorShapeId);
	} else {
		zend_update_property(box2d_ce_b2SensorEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sensorShapeId"), sensorShapeId);
	}

	if (visitorShapeId == NULL) {
		zval created_visitorShapeId;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_visitorShapeId) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SensorEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("visitorShapeId"), &created_visitorShapeId);
		zval_ptr_dtor(&created_visitorShapeId);
	} else {
		zend_update_property(box2d_ce_b2SensorEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("visitorShapeId"), visitorShapeId);
	}

	b2SensorEndTouchEvent native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SensorEndTouchEvent_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SensorEvents, __construct)
{
	zval *beginEvents = NULL;
	zval *endEvents = NULL;
	zend_long beginCount = 0;
	zend_long endCount = 0;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(beginEvents)
		Z_PARAM_ARRAY(endEvents)
		Z_PARAM_LONG(beginCount)
		Z_PARAM_LONG(endCount)
	ZEND_PARSE_PARAMETERS_END();

	if (beginEvents == NULL) {
		zval empty_beginEvents;
		array_init(&empty_beginEvents);
		zend_update_property(box2d_ce_b2SensorEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("beginEvents"), &empty_beginEvents);
		zval_ptr_dtor(&empty_beginEvents);
	} else {
		zend_update_property(box2d_ce_b2SensorEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("beginEvents"), beginEvents);
	}

	if (endEvents == NULL) {
		zval empty_endEvents;
		array_init(&empty_endEvents);
		zend_update_property(box2d_ce_b2SensorEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("endEvents"), &empty_endEvents);
		zval_ptr_dtor(&empty_endEvents);
	} else {
		zend_update_property(box2d_ce_b2SensorEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("endEvents"), endEvents);
	}

	zend_update_property_long(box2d_ce_b2SensorEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("beginCount"), beginCount);

	zend_update_property_long(box2d_ce_b2SensorEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("endCount"), endCount);

	b2SensorEvents native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SensorEvents_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ContactBeginTouchEvent, __construct)
{
	zval *shapeIdA = NULL;
	zval *shapeIdB = NULL;
	zval *manifold = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(shapeIdA, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(shapeIdB, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(manifold, box2d_ce_b2Manifold)
	ZEND_PARSE_PARAMETERS_END();

	if (shapeIdA == NULL) {
		zval created_shapeIdA;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), &created_shapeIdA);
		zval_ptr_dtor(&created_shapeIdA);
	} else {
		zend_update_property(box2d_ce_b2ContactBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), shapeIdA);
	}

	if (shapeIdB == NULL) {
		zval created_shapeIdB;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), &created_shapeIdB);
		zval_ptr_dtor(&created_shapeIdB);
	} else {
		zend_update_property(box2d_ce_b2ContactBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), shapeIdB);
	}

	if (manifold == NULL) {
		zval created_manifold;
		if (box2d_new_default(box2d_ce_b2Manifold, &created_manifold) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("manifold"), &created_manifold);
		zval_ptr_dtor(&created_manifold);
	} else {
		zend_update_property(box2d_ce_b2ContactBeginTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("manifold"), manifold);
	}

	b2ContactBeginTouchEvent native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ContactBeginTouchEvent_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ContactEndTouchEvent, __construct)
{
	zval *shapeIdA = NULL;
	zval *shapeIdB = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(shapeIdA, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(shapeIdB, box2d_ce_b2ShapeId)
	ZEND_PARSE_PARAMETERS_END();

	if (shapeIdA == NULL) {
		zval created_shapeIdA;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), &created_shapeIdA);
		zval_ptr_dtor(&created_shapeIdA);
	} else {
		zend_update_property(box2d_ce_b2ContactEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), shapeIdA);
	}

	if (shapeIdB == NULL) {
		zval created_shapeIdB;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), &created_shapeIdB);
		zval_ptr_dtor(&created_shapeIdB);
	} else {
		zend_update_property(box2d_ce_b2ContactEndTouchEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), shapeIdB);
	}

	b2ContactEndTouchEvent native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ContactEndTouchEvent_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ContactHitEvent, __construct)
{
	zval *shapeIdA = NULL;
	zval *shapeIdB = NULL;
	zval *point = NULL;
	zval *normal = NULL;
	double approachSpeed = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(shapeIdA, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(shapeIdB, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(point, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(normal, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(approachSpeed)
	ZEND_PARSE_PARAMETERS_END();

	if (shapeIdA == NULL) {
		zval created_shapeIdA;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), &created_shapeIdA);
		zval_ptr_dtor(&created_shapeIdA);
	} else {
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), shapeIdA);
	}

	if (shapeIdB == NULL) {
		zval created_shapeIdB;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), &created_shapeIdB);
		zval_ptr_dtor(&created_shapeIdB);
	} else {
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), shapeIdB);
	}

	if (point == NULL) {
		zval created_point;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), &created_point);
		zval_ptr_dtor(&created_point);
	} else {
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), point);
	}

	if (normal == NULL) {
		zval created_normal;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_normal) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), &created_normal);
		zval_ptr_dtor(&created_normal);
	} else {
		zend_update_property(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), normal);
	}

	zend_update_property_double(box2d_ce_b2ContactHitEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("approachSpeed"), approachSpeed);

	b2ContactHitEvent native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ContactHitEvent_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ContactEvents, __construct)
{
	zval *beginEvents = NULL;
	zval *endEvents = NULL;
	zval *hitEvents = NULL;
	zend_long beginCount = 0;
	zend_long endCount = 0;
	zend_long hitCount = 0;

	ZEND_PARSE_PARAMETERS_START(0, 6)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(beginEvents)
		Z_PARAM_ARRAY(endEvents)
		Z_PARAM_ARRAY(hitEvents)
		Z_PARAM_LONG(beginCount)
		Z_PARAM_LONG(endCount)
		Z_PARAM_LONG(hitCount)
	ZEND_PARSE_PARAMETERS_END();

	if (beginEvents == NULL) {
		zval empty_beginEvents;
		array_init(&empty_beginEvents);
		zend_update_property(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("beginEvents"), &empty_beginEvents);
		zval_ptr_dtor(&empty_beginEvents);
	} else {
		zend_update_property(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("beginEvents"), beginEvents);
	}

	if (endEvents == NULL) {
		zval empty_endEvents;
		array_init(&empty_endEvents);
		zend_update_property(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("endEvents"), &empty_endEvents);
		zval_ptr_dtor(&empty_endEvents);
	} else {
		zend_update_property(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("endEvents"), endEvents);
	}

	if (hitEvents == NULL) {
		zval empty_hitEvents;
		array_init(&empty_hitEvents);
		zend_update_property(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hitEvents"), &empty_hitEvents);
		zval_ptr_dtor(&empty_hitEvents);
	} else {
		zend_update_property(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hitEvents"), hitEvents);
	}

	zend_update_property_long(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("beginCount"), beginCount);

	zend_update_property_long(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("endCount"), endCount);

	zend_update_property_long(box2d_ce_b2ContactEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hitCount"), hitCount);

	b2ContactEvents native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ContactEvents_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2BodyMoveEvent, __construct)
{
	zval *transform = NULL;
	zval *bodyId = NULL;
	zend_long userData = 0;
	bool fellAsleep = false;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(transform, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(bodyId, box2d_ce_b2BodyId)
		Z_PARAM_LONG(userData)
		Z_PARAM_BOOL(fellAsleep)
	ZEND_PARSE_PARAMETERS_END();

	if (transform == NULL) {
		zval created_transform;
		if (box2d_new_default(box2d_ce_b2Transform, &created_transform) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2BodyMoveEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transform"), &created_transform);
		zval_ptr_dtor(&created_transform);
	} else {
		zend_update_property(box2d_ce_b2BodyMoveEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transform"), transform);
	}

	if (bodyId == NULL) {
		zval created_bodyId;
		if (box2d_new_default(box2d_ce_b2BodyId, &created_bodyId) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2BodyMoveEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyId"), &created_bodyId);
		zval_ptr_dtor(&created_bodyId);
	} else {
		zend_update_property(box2d_ce_b2BodyMoveEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("bodyId"), bodyId);
	}

	zend_update_property_long(box2d_ce_b2BodyMoveEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("userData"), userData);

	zend_update_property_bool(box2d_ce_b2BodyMoveEvent, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fellAsleep"), fellAsleep);

	b2BodyMoveEvent native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2BodyMoveEvent_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2BodyEvents, __construct)
{
	zval *moveEvents = NULL;
	zend_long moveCount = 0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(moveEvents)
		Z_PARAM_LONG(moveCount)
	ZEND_PARSE_PARAMETERS_END();

	if (moveEvents == NULL) {
		zval empty_moveEvents;
		array_init(&empty_moveEvents);
		zend_update_property(box2d_ce_b2BodyEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("moveEvents"), &empty_moveEvents);
		zval_ptr_dtor(&empty_moveEvents);
	} else {
		zend_update_property(box2d_ce_b2BodyEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("moveEvents"), moveEvents);
	}

	zend_update_property_long(box2d_ce_b2BodyEvents, Z_OBJ_P(ZEND_THIS), ZEND_STRL("moveCount"), moveCount);

	b2BodyEvents native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2BodyEvents_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ContactData, __construct)
{
	zval *shapeIdA = NULL;
	zval *shapeIdB = NULL;
	zval *manifold = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(shapeIdA, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(shapeIdB, box2d_ce_b2ShapeId)
		Z_PARAM_OBJECT_OF_CLASS(manifold, box2d_ce_b2Manifold)
	ZEND_PARSE_PARAMETERS_END();

	if (shapeIdA == NULL) {
		zval created_shapeIdA;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), &created_shapeIdA);
		zval_ptr_dtor(&created_shapeIdA);
	} else {
		zend_update_property(box2d_ce_b2ContactData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdA"), shapeIdA);
	}

	if (shapeIdB == NULL) {
		zval created_shapeIdB;
		if (box2d_new_default(box2d_ce_b2ShapeId, &created_shapeIdB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), &created_shapeIdB);
		zval_ptr_dtor(&created_shapeIdB);
	} else {
		zend_update_property(box2d_ce_b2ContactData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("shapeIdB"), shapeIdB);
	}

	if (manifold == NULL) {
		zval created_manifold;
		if (box2d_new_default(box2d_ce_b2Manifold, &created_manifold) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ContactData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("manifold"), &created_manifold);
		zval_ptr_dtor(&created_manifold);
	} else {
		zend_update_property(box2d_ce_b2ContactData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("manifold"), manifold);
	}

	b2ContactData native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ContactData_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2DebugDraw, __construct)
{
	zval *DrawPolygonFcn = NULL;
	zval *DrawSolidPolygonFcn = NULL;
	zval *DrawCircleFcn = NULL;
	zval *DrawSolidCircleFcn = NULL;
	zval *DrawSolidCapsuleFcn = NULL;
	zval *DrawSegmentFcn = NULL;
	zval *DrawTransformFcn = NULL;
	zval *DrawPointFcn = NULL;
	zval *DrawStringFcn = NULL;
	zval *drawingBounds = NULL;
	bool useDrawingBounds = false;
	bool drawShapes = false;
	bool drawJoints = false;
	bool drawJointExtras = false;
	bool drawBounds = false;
	bool drawMass = false;
	bool drawBodyNames = false;
	bool drawContacts = false;
	bool drawGraphColors = false;
	bool drawContactNormals = false;
	bool drawContactImpulses = false;
	bool drawContactFeatures = false;
	bool drawFrictionImpulses = false;
	bool drawIslands = false;
	zval *context = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 25)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawPolygonFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawSolidPolygonFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawCircleFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawSolidCircleFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawSolidCapsuleFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawSegmentFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawTransformFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawPointFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(DrawStringFcn, zend_ce_closure)
		Z_PARAM_OBJECT_OF_CLASS(drawingBounds, box2d_ce_b2AABB)
		Z_PARAM_BOOL(useDrawingBounds)
		Z_PARAM_BOOL(drawShapes)
		Z_PARAM_BOOL(drawJoints)
		Z_PARAM_BOOL(drawJointExtras)
		Z_PARAM_BOOL(drawBounds)
		Z_PARAM_BOOL(drawMass)
		Z_PARAM_BOOL(drawBodyNames)
		Z_PARAM_BOOL(drawContacts)
		Z_PARAM_BOOL(drawGraphColors)
		Z_PARAM_BOOL(drawContactNormals)
		Z_PARAM_BOOL(drawContactImpulses)
		Z_PARAM_BOOL(drawContactFeatures)
		Z_PARAM_BOOL(drawFrictionImpulses)
		Z_PARAM_BOOL(drawIslands)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();

	if (DrawPolygonFcn == NULL || Z_TYPE_P(DrawPolygonFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawPolygonFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawPolygonFcn"), DrawPolygonFcn);
	}

	if (DrawSolidPolygonFcn == NULL || Z_TYPE_P(DrawSolidPolygonFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSolidPolygonFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSolidPolygonFcn"), DrawSolidPolygonFcn);
	}

	if (DrawCircleFcn == NULL || Z_TYPE_P(DrawCircleFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawCircleFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawCircleFcn"), DrawCircleFcn);
	}

	if (DrawSolidCircleFcn == NULL || Z_TYPE_P(DrawSolidCircleFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSolidCircleFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSolidCircleFcn"), DrawSolidCircleFcn);
	}

	if (DrawSolidCapsuleFcn == NULL || Z_TYPE_P(DrawSolidCapsuleFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSolidCapsuleFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSolidCapsuleFcn"), DrawSolidCapsuleFcn);
	}

	if (DrawSegmentFcn == NULL || Z_TYPE_P(DrawSegmentFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSegmentFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawSegmentFcn"), DrawSegmentFcn);
	}

	if (DrawTransformFcn == NULL || Z_TYPE_P(DrawTransformFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawTransformFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawTransformFcn"), DrawTransformFcn);
	}

	if (DrawPointFcn == NULL || Z_TYPE_P(DrawPointFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawPointFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawPointFcn"), DrawPointFcn);
	}

	if (DrawStringFcn == NULL || Z_TYPE_P(DrawStringFcn) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawStringFcn"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("DrawStringFcn"), DrawStringFcn);
	}

	if (drawingBounds == NULL) {
		zval created_drawingBounds;
		if (box2d_new_default(box2d_ce_b2AABB, &created_drawingBounds) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawingBounds"), &created_drawingBounds);
		zval_ptr_dtor(&created_drawingBounds);
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawingBounds"), drawingBounds);
	}

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("useDrawingBounds"), useDrawingBounds);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawShapes"), drawShapes);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawJoints"), drawJoints);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawJointExtras"), drawJointExtras);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawBounds"), drawBounds);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawMass"), drawMass);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawBodyNames"), drawBodyNames);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawContacts"), drawContacts);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawGraphColors"), drawGraphColors);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawContactNormals"), drawContactNormals);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawContactImpulses"), drawContactImpulses);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawContactFeatures"), drawContactFeatures);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawFrictionImpulses"), drawFrictionImpulses);

	zend_update_property_bool(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("drawIslands"), drawIslands);

	if (context == NULL || Z_TYPE_P(context) == IS_NULL) {
		zend_update_property_null(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("context"));
	} else {
		zend_update_property(box2d_ce_b2DebugDraw, Z_OBJ_P(ZEND_THIS), ZEND_STRL("context"), context);
	}

	b2DebugDraw native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2DebugDraw_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

void box2d_register_types(int module_number)
{
	box2d_ce_b2RayResult = register_class_b2RayResult();
	box2d_class_is_value(box2d_ce_b2RayResult);
	box2d_ce_b2WorldDef = register_class_b2WorldDef();
	box2d_class_is_value(box2d_ce_b2WorldDef);
	box2d_ce_b2BodyDef = register_class_b2BodyDef();
	box2d_class_is_value(box2d_ce_b2BodyDef);
	box2d_ce_b2Filter = register_class_b2Filter();
	box2d_class_is_value(box2d_ce_b2Filter);
	box2d_ce_b2QueryFilter = register_class_b2QueryFilter();
	box2d_class_is_value(box2d_ce_b2QueryFilter);
	box2d_ce_b2SurfaceMaterial = register_class_b2SurfaceMaterial();
	box2d_class_is_value(box2d_ce_b2SurfaceMaterial);
	box2d_ce_b2ShapeDef = register_class_b2ShapeDef();
	box2d_class_is_value(box2d_ce_b2ShapeDef);
	box2d_ce_b2ChainDef = register_class_b2ChainDef();
	box2d_class_is_value(box2d_ce_b2ChainDef);
	box2d_ce_b2Profile = register_class_b2Profile();
	box2d_class_is_value(box2d_ce_b2Profile);
	box2d_ce_b2Counters = register_class_b2Counters();
	box2d_class_is_value(box2d_ce_b2Counters);
	box2d_ce_b2DistanceJointDef = register_class_b2DistanceJointDef();
	box2d_class_is_value(box2d_ce_b2DistanceJointDef);
	box2d_ce_b2MotorJointDef = register_class_b2MotorJointDef();
	box2d_class_is_value(box2d_ce_b2MotorJointDef);
	box2d_ce_b2MouseJointDef = register_class_b2MouseJointDef();
	box2d_class_is_value(box2d_ce_b2MouseJointDef);
	box2d_ce_b2FilterJointDef = register_class_b2FilterJointDef();
	box2d_class_is_value(box2d_ce_b2FilterJointDef);
	box2d_ce_b2PrismaticJointDef = register_class_b2PrismaticJointDef();
	box2d_class_is_value(box2d_ce_b2PrismaticJointDef);
	box2d_ce_b2RevoluteJointDef = register_class_b2RevoluteJointDef();
	box2d_class_is_value(box2d_ce_b2RevoluteJointDef);
	box2d_ce_b2WeldJointDef = register_class_b2WeldJointDef();
	box2d_class_is_value(box2d_ce_b2WeldJointDef);
	box2d_ce_b2WheelJointDef = register_class_b2WheelJointDef();
	box2d_class_is_value(box2d_ce_b2WheelJointDef);
	box2d_ce_b2ExplosionDef = register_class_b2ExplosionDef();
	box2d_class_is_value(box2d_ce_b2ExplosionDef);
	box2d_ce_b2SensorBeginTouchEvent = register_class_b2SensorBeginTouchEvent();
	box2d_class_is_value(box2d_ce_b2SensorBeginTouchEvent);
	box2d_ce_b2SensorEndTouchEvent = register_class_b2SensorEndTouchEvent();
	box2d_class_is_value(box2d_ce_b2SensorEndTouchEvent);
	box2d_ce_b2SensorEvents = register_class_b2SensorEvents();
	box2d_class_is_value(box2d_ce_b2SensorEvents);
	box2d_ce_b2ContactBeginTouchEvent = register_class_b2ContactBeginTouchEvent();
	box2d_class_is_value(box2d_ce_b2ContactBeginTouchEvent);
	box2d_ce_b2ContactEndTouchEvent = register_class_b2ContactEndTouchEvent();
	box2d_class_is_value(box2d_ce_b2ContactEndTouchEvent);
	box2d_ce_b2ContactHitEvent = register_class_b2ContactHitEvent();
	box2d_class_is_value(box2d_ce_b2ContactHitEvent);
	box2d_ce_b2ContactEvents = register_class_b2ContactEvents();
	box2d_class_is_value(box2d_ce_b2ContactEvents);
	box2d_ce_b2BodyMoveEvent = register_class_b2BodyMoveEvent();
	box2d_class_is_value(box2d_ce_b2BodyMoveEvent);
	box2d_ce_b2BodyEvents = register_class_b2BodyEvents();
	box2d_class_is_value(box2d_ce_b2BodyEvents);
	box2d_ce_b2ContactData = register_class_b2ContactData();
	box2d_class_is_value(box2d_ce_b2ContactData);
	box2d_ce_b2DebugDraw = register_class_b2DebugDraw();
	box2d_class_is_value(box2d_ce_b2DebugDraw);
	register_types_symbols(module_number);
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
}
