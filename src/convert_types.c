#include "convert.h"
#include "classes.h"

#include <string.h>

zend_result box2d_b2RayResult_from_zval(zval *zv, b2RayResult *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2RayResult) {
		zend_type_error("b2RayResult expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("shapeId"), box2d_from_slot_b2ShapeId, &out->shapeId, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("point"), box2d_from_slot_b2Vec2, &out->point, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("normal"), box2d_from_slot_b2Vec2, &out->normal, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("fraction"), &out->fraction) == FAILURE) return FAILURE;
	int nodeVisits_bits;
	if (box2d_prop_i32(object, ZEND_STRL("nodeVisits"), &nodeVisits_bits) == FAILURE) return FAILURE;
	out->nodeVisits = nodeVisits_bits;
	int leafVisits_bits;
	if (box2d_prop_i32(object, ZEND_STRL("leafVisits"), &leafVisits_bits) == FAILURE) return FAILURE;
	out->leafVisits = leafVisits_bits;
	if (box2d_prop_bool(object, ZEND_STRL("hit"), &out->hit) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2RayResult_to_zval(const b2RayResult *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2RayResult);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("shapeId"), box2d_to_slot_b2ShapeId, &in->shapeId) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("point"), box2d_to_slot_b2Vec2, &in->point) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("normal"), box2d_to_slot_b2Vec2, &in->normal) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("fraction"), in->fraction);
	box2d_put_i32(object, ZEND_STRL("nodeVisits"), in->nodeVisits);
	box2d_put_i32(object, ZEND_STRL("leafVisits"), in->leafVisits);
	box2d_put_bool(object, ZEND_STRL("hit"), in->hit);
	return SUCCESS;
}

zend_result box2d_from_slot_b2RayResult(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2RayResult_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2RayResult(const void *in, zval *out)
{
	return box2d_b2RayResult_to_zval(in, out);
}


zend_result box2d_b2WorldDef_from_zval(zval *zv, b2WorldDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2WorldDef) {
		zend_type_error("b2WorldDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("gravity"), box2d_from_slot_b2Vec2, &out->gravity, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("restitutionThreshold"), &out->restitutionThreshold) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hitEventThreshold"), &out->hitEventThreshold) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("contactHertz"), &out->contactHertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("contactDampingRatio"), &out->contactDampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxContactPushSpeed"), &out->maxContactPushSpeed) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maximumLinearSpeed"), &out->maximumLinearSpeed) == FAILURE) return FAILURE;
	(void) zend_read_property(object->ce, object, ZEND_STRL("frictionCallback"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("restitutionCallback"), 0, NULL);
	if (box2d_prop_bool(object, ZEND_STRL("enableSleep"), &out->enableSleep) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableContinuous"), &out->enableContinuous) == FAILURE) return FAILURE;
	int workerCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("workerCount"), &workerCount_bits) == FAILURE) return FAILURE;
	out->workerCount = workerCount_bits;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2WorldDef_to_zval(const b2WorldDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2WorldDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("gravity"), box2d_to_slot_b2Vec2, &in->gravity) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("restitutionThreshold"), in->restitutionThreshold);
	box2d_put_f32(object, ZEND_STRL("hitEventThreshold"), in->hitEventThreshold);
	box2d_put_f32(object, ZEND_STRL("contactHertz"), in->contactHertz);
	box2d_put_f32(object, ZEND_STRL("contactDampingRatio"), in->contactDampingRatio);
	box2d_put_f32(object, ZEND_STRL("maxContactPushSpeed"), in->maxContactPushSpeed);
	box2d_put_f32(object, ZEND_STRL("maximumLinearSpeed"), in->maximumLinearSpeed);
	zend_update_property_null(object->ce, object, ZEND_STRL("frictionCallback"));
	zend_update_property_null(object->ce, object, ZEND_STRL("restitutionCallback"));
	box2d_put_bool(object, ZEND_STRL("enableSleep"), in->enableSleep);
	box2d_put_bool(object, ZEND_STRL("enableContinuous"), in->enableContinuous);
	box2d_put_i32(object, ZEND_STRL("workerCount"), in->workerCount);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2WorldDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2WorldDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2WorldDef(const void *in, zval *out)
{
	return box2d_b2WorldDef_to_zval(in, out);
}


zend_result box2d_b2BodyDef_from_zval(zval *zv, b2BodyDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2BodyDef) {
		zend_type_error("b2BodyDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int type_bits;
	if (box2d_prop_i32(object, ZEND_STRL("type"), &type_bits) == FAILURE) return FAILURE;
	out->type = type_bits;
	if (box2d_prop_struct(object, ZEND_STRL("position"), box2d_from_slot_b2Vec2, &out->position, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("rotation"), box2d_from_slot_b2Rot, &out->rotation, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("linearVelocity"), box2d_from_slot_b2Vec2, &out->linearVelocity, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("angularVelocity"), &out->angularVelocity) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("linearDamping"), &out->linearDamping) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("angularDamping"), &out->angularDamping) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("gravityScale"), &out->gravityScale) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("sleepThreshold"), &out->sleepThreshold) == FAILURE) return FAILURE;
	if (box2d_prop_string(object, ZEND_STRL("name"), &out->name) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSleep"), &out->enableSleep) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("isAwake"), &out->isAwake) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("fixedRotation"), &out->fixedRotation) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("isBullet"), &out->isBullet) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("isEnabled"), &out->isEnabled) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("allowFastRotation"), &out->allowFastRotation) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2BodyDef_to_zval(const b2BodyDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2BodyDef);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("type"), in->type);
	if (box2d_put_struct(object, ZEND_STRL("position"), box2d_to_slot_b2Vec2, &in->position) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("rotation"), box2d_to_slot_b2Rot, &in->rotation) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("linearVelocity"), box2d_to_slot_b2Vec2, &in->linearVelocity) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("angularVelocity"), in->angularVelocity);
	box2d_put_f32(object, ZEND_STRL("linearDamping"), in->linearDamping);
	box2d_put_f32(object, ZEND_STRL("angularDamping"), in->angularDamping);
	box2d_put_f32(object, ZEND_STRL("gravityScale"), in->gravityScale);
	box2d_put_f32(object, ZEND_STRL("sleepThreshold"), in->sleepThreshold);
	box2d_put_string(object, ZEND_STRL("name"), in->name);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_bool(object, ZEND_STRL("enableSleep"), in->enableSleep);
	box2d_put_bool(object, ZEND_STRL("isAwake"), in->isAwake);
	box2d_put_bool(object, ZEND_STRL("fixedRotation"), in->fixedRotation);
	box2d_put_bool(object, ZEND_STRL("isBullet"), in->isBullet);
	box2d_put_bool(object, ZEND_STRL("isEnabled"), in->isEnabled);
	box2d_put_bool(object, ZEND_STRL("allowFastRotation"), in->allowFastRotation);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2BodyDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2BodyDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2BodyDef(const void *in, zval *out)
{
	return box2d_b2BodyDef_to_zval(in, out);
}


zend_result box2d_b2Filter_from_zval(zval *zv, b2Filter *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Filter) {
		zend_type_error("b2Filter expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_u64(object, ZEND_STRL("categoryBits"), &out->categoryBits) == FAILURE) return FAILURE;
	if (box2d_prop_u64(object, ZEND_STRL("maskBits"), &out->maskBits) == FAILURE) return FAILURE;
	int groupIndex_bits;
	if (box2d_prop_i32(object, ZEND_STRL("groupIndex"), &groupIndex_bits) == FAILURE) return FAILURE;
	out->groupIndex = groupIndex_bits;
	return SUCCESS;
}

zend_result box2d_b2Filter_to_zval(const b2Filter *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Filter);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_u64(object, ZEND_STRL("categoryBits"), in->categoryBits);
	box2d_put_u64(object, ZEND_STRL("maskBits"), in->maskBits);
	box2d_put_i32(object, ZEND_STRL("groupIndex"), in->groupIndex);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Filter(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Filter_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Filter(const void *in, zval *out)
{
	return box2d_b2Filter_to_zval(in, out);
}


zend_result box2d_b2QueryFilter_from_zval(zval *zv, b2QueryFilter *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2QueryFilter) {
		zend_type_error("b2QueryFilter expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_u64(object, ZEND_STRL("categoryBits"), &out->categoryBits) == FAILURE) return FAILURE;
	if (box2d_prop_u64(object, ZEND_STRL("maskBits"), &out->maskBits) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2QueryFilter_to_zval(const b2QueryFilter *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2QueryFilter);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_u64(object, ZEND_STRL("categoryBits"), in->categoryBits);
	box2d_put_u64(object, ZEND_STRL("maskBits"), in->maskBits);
	return SUCCESS;
}

zend_result box2d_from_slot_b2QueryFilter(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2QueryFilter_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2QueryFilter(const void *in, zval *out)
{
	return box2d_b2QueryFilter_to_zval(in, out);
}


zend_result box2d_b2SurfaceMaterial_from_zval(zval *zv, b2SurfaceMaterial *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SurfaceMaterial) {
		zend_type_error("b2SurfaceMaterial expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_f32(object, ZEND_STRL("friction"), &out->friction) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("restitution"), &out->restitution) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("rollingResistance"), &out->rollingResistance) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("tangentSpeed"), &out->tangentSpeed) == FAILURE) return FAILURE;
	int userMaterialId_bits;
	if (box2d_prop_i32(object, ZEND_STRL("userMaterialId"), &userMaterialId_bits) == FAILURE) return FAILURE;
	out->userMaterialId = userMaterialId_bits;
	if (box2d_prop_u32(object, ZEND_STRL("customColor"), &out->customColor) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2SurfaceMaterial_to_zval(const b2SurfaceMaterial *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SurfaceMaterial);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_f32(object, ZEND_STRL("friction"), in->friction);
	box2d_put_f32(object, ZEND_STRL("restitution"), in->restitution);
	box2d_put_f32(object, ZEND_STRL("rollingResistance"), in->rollingResistance);
	box2d_put_f32(object, ZEND_STRL("tangentSpeed"), in->tangentSpeed);
	box2d_put_i32(object, ZEND_STRL("userMaterialId"), in->userMaterialId);
	box2d_put_u32(object, ZEND_STRL("customColor"), in->customColor);
	return SUCCESS;
}

zend_result box2d_from_slot_b2SurfaceMaterial(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SurfaceMaterial_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SurfaceMaterial(const void *in, zval *out)
{
	return box2d_b2SurfaceMaterial_to_zval(in, out);
}


zend_result box2d_b2ShapeDef_from_zval(zval *zv, b2ShapeDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ShapeDef) {
		zend_type_error("b2ShapeDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("material"), box2d_from_slot_b2SurfaceMaterial, &out->material, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("density"), &out->density) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("filter"), box2d_from_slot_b2Filter, &out->filter, frame) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("isSensor"), &out->isSensor) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSensorEvents"), &out->enableSensorEvents) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableContactEvents"), &out->enableContactEvents) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableHitEvents"), &out->enableHitEvents) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enablePreSolveEvents"), &out->enablePreSolveEvents) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("invokeContactCreation"), &out->invokeContactCreation) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("updateBodyMass"), &out->updateBodyMass) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2ShapeDef_to_zval(const b2ShapeDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ShapeDef);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	if (box2d_put_struct(object, ZEND_STRL("material"), box2d_to_slot_b2SurfaceMaterial, &in->material) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("density"), in->density);
	if (box2d_put_struct(object, ZEND_STRL("filter"), box2d_to_slot_b2Filter, &in->filter) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_bool(object, ZEND_STRL("isSensor"), in->isSensor);
	box2d_put_bool(object, ZEND_STRL("enableSensorEvents"), in->enableSensorEvents);
	box2d_put_bool(object, ZEND_STRL("enableContactEvents"), in->enableContactEvents);
	box2d_put_bool(object, ZEND_STRL("enableHitEvents"), in->enableHitEvents);
	box2d_put_bool(object, ZEND_STRL("enablePreSolveEvents"), in->enablePreSolveEvents);
	box2d_put_bool(object, ZEND_STRL("invokeContactCreation"), in->invokeContactCreation);
	box2d_put_bool(object, ZEND_STRL("updateBodyMass"), in->updateBodyMass);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ShapeDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ShapeDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ShapeDef(const void *in, zval *out)
{
	return box2d_b2ShapeDef_to_zval(in, out);
}


zend_result box2d_b2ChainDef_from_zval(zval *zv, b2ChainDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ChainDef) {
		zend_type_error("b2ChainDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int count_value;
	if (box2d_prop_i32(object, ZEND_STRL("count"), &count_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(count_value, -1, "b2ChainDef::$count") == FAILURE) {
		return FAILURE;
	}
	int materialCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("materialCount"), &materialCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(materialCount_value, -1, "b2ChainDef::$materialCount") == FAILURE) {
		return FAILURE;
	}
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	void *points_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("points"), count_value, &points_block, sizeof(b2Vec2), box2d_from_slot_b2Vec2, frame) == FAILURE) return FAILURE;
	out->points = points_block;
	out->count = count_value;
	void *materials_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("materials"), materialCount_value, &materials_block, sizeof(b2SurfaceMaterial), box2d_from_slot_b2SurfaceMaterial, frame) == FAILURE) return FAILURE;
	out->materials = materials_block;
	out->materialCount = materialCount_value;
	if (box2d_prop_struct(object, ZEND_STRL("filter"), box2d_from_slot_b2Filter, &out->filter, frame) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("isLoop"), &out->isLoop) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSensorEvents"), &out->enableSensorEvents) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2ChainDef_to_zval(const b2ChainDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ChainDef);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	if (in->points == NULL) {
		zval empty_points;
		array_init(&empty_points);
		zend_update_property(object->ce, object, ZEND_STRL("points"), &empty_points);
		zval_ptr_dtor(&empty_points);
	} else if (box2d_put_struct_list(object, ZEND_STRL("points"), in->count, in->points, sizeof(b2Vec2), box2d_to_slot_b2Vec2) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("count"), in->count);
	if (in->materials == NULL) {
		zval empty_materials;
		array_init(&empty_materials);
		zend_update_property(object->ce, object, ZEND_STRL("materials"), &empty_materials);
		zval_ptr_dtor(&empty_materials);
	} else if (box2d_put_struct_list(object, ZEND_STRL("materials"), in->materialCount, in->materials, sizeof(b2SurfaceMaterial), box2d_to_slot_b2SurfaceMaterial) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("materialCount"), in->materialCount);
	if (box2d_put_struct(object, ZEND_STRL("filter"), box2d_to_slot_b2Filter, &in->filter) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_bool(object, ZEND_STRL("isLoop"), in->isLoop);
	box2d_put_bool(object, ZEND_STRL("enableSensorEvents"), in->enableSensorEvents);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ChainDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ChainDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ChainDef(const void *in, zval *out)
{
	return box2d_b2ChainDef_to_zval(in, out);
}


zend_result box2d_b2Profile_from_zval(zval *zv, b2Profile *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Profile) {
		zend_type_error("b2Profile expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_f32(object, ZEND_STRL("step"), &out->step) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("pairs"), &out->pairs) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("collide"), &out->collide) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("solve"), &out->solve) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("mergeIslands"), &out->mergeIslands) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("prepareStages"), &out->prepareStages) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("solveConstraints"), &out->solveConstraints) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("prepareConstraints"), &out->prepareConstraints) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("integrateVelocities"), &out->integrateVelocities) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("warmStart"), &out->warmStart) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("solveImpulses"), &out->solveImpulses) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("integratePositions"), &out->integratePositions) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("relaxImpulses"), &out->relaxImpulses) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("applyRestitution"), &out->applyRestitution) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("storeImpulses"), &out->storeImpulses) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("splitIslands"), &out->splitIslands) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("transforms"), &out->transforms) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hitEvents"), &out->hitEvents) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("refit"), &out->refit) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("bullets"), &out->bullets) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("sleepIslands"), &out->sleepIslands) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("sensors"), &out->sensors) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Profile_to_zval(const b2Profile *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Profile);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_f32(object, ZEND_STRL("step"), in->step);
	box2d_put_f32(object, ZEND_STRL("pairs"), in->pairs);
	box2d_put_f32(object, ZEND_STRL("collide"), in->collide);
	box2d_put_f32(object, ZEND_STRL("solve"), in->solve);
	box2d_put_f32(object, ZEND_STRL("mergeIslands"), in->mergeIslands);
	box2d_put_f32(object, ZEND_STRL("prepareStages"), in->prepareStages);
	box2d_put_f32(object, ZEND_STRL("solveConstraints"), in->solveConstraints);
	box2d_put_f32(object, ZEND_STRL("prepareConstraints"), in->prepareConstraints);
	box2d_put_f32(object, ZEND_STRL("integrateVelocities"), in->integrateVelocities);
	box2d_put_f32(object, ZEND_STRL("warmStart"), in->warmStart);
	box2d_put_f32(object, ZEND_STRL("solveImpulses"), in->solveImpulses);
	box2d_put_f32(object, ZEND_STRL("integratePositions"), in->integratePositions);
	box2d_put_f32(object, ZEND_STRL("relaxImpulses"), in->relaxImpulses);
	box2d_put_f32(object, ZEND_STRL("applyRestitution"), in->applyRestitution);
	box2d_put_f32(object, ZEND_STRL("storeImpulses"), in->storeImpulses);
	box2d_put_f32(object, ZEND_STRL("splitIslands"), in->splitIslands);
	box2d_put_f32(object, ZEND_STRL("transforms"), in->transforms);
	box2d_put_f32(object, ZEND_STRL("hitEvents"), in->hitEvents);
	box2d_put_f32(object, ZEND_STRL("refit"), in->refit);
	box2d_put_f32(object, ZEND_STRL("bullets"), in->bullets);
	box2d_put_f32(object, ZEND_STRL("sleepIslands"), in->sleepIslands);
	box2d_put_f32(object, ZEND_STRL("sensors"), in->sensors);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Profile(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Profile_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Profile(const void *in, zval *out)
{
	return box2d_b2Profile_to_zval(in, out);
}


zend_result box2d_b2Counters_from_zval(zval *zv, b2Counters *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2Counters) {
		zend_type_error("b2Counters expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int bodyCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("bodyCount"), &bodyCount_bits) == FAILURE) return FAILURE;
	out->bodyCount = bodyCount_bits;
	int shapeCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("shapeCount"), &shapeCount_bits) == FAILURE) return FAILURE;
	out->shapeCount = shapeCount_bits;
	int contactCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("contactCount"), &contactCount_bits) == FAILURE) return FAILURE;
	out->contactCount = contactCount_bits;
	int jointCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("jointCount"), &jointCount_bits) == FAILURE) return FAILURE;
	out->jointCount = jointCount_bits;
	int islandCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("islandCount"), &islandCount_bits) == FAILURE) return FAILURE;
	out->islandCount = islandCount_bits;
	int stackUsed_bits;
	if (box2d_prop_i32(object, ZEND_STRL("stackUsed"), &stackUsed_bits) == FAILURE) return FAILURE;
	out->stackUsed = stackUsed_bits;
	int staticTreeHeight_bits;
	if (box2d_prop_i32(object, ZEND_STRL("staticTreeHeight"), &staticTreeHeight_bits) == FAILURE) return FAILURE;
	out->staticTreeHeight = staticTreeHeight_bits;
	int treeHeight_bits;
	if (box2d_prop_i32(object, ZEND_STRL("treeHeight"), &treeHeight_bits) == FAILURE) return FAILURE;
	out->treeHeight = treeHeight_bits;
	int byteCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("byteCount"), &byteCount_bits) == FAILURE) return FAILURE;
	out->byteCount = byteCount_bits;
	int taskCount_bits;
	if (box2d_prop_i32(object, ZEND_STRL("taskCount"), &taskCount_bits) == FAILURE) return FAILURE;
	out->taskCount = taskCount_bits;
	if (box2d_list_i32(object, ZEND_STRL("colorCounts"), 12, out->colorCounts) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2Counters_to_zval(const b2Counters *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2Counters);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_i32(object, ZEND_STRL("bodyCount"), in->bodyCount);
	box2d_put_i32(object, ZEND_STRL("shapeCount"), in->shapeCount);
	box2d_put_i32(object, ZEND_STRL("contactCount"), in->contactCount);
	box2d_put_i32(object, ZEND_STRL("jointCount"), in->jointCount);
	box2d_put_i32(object, ZEND_STRL("islandCount"), in->islandCount);
	box2d_put_i32(object, ZEND_STRL("stackUsed"), in->stackUsed);
	box2d_put_i32(object, ZEND_STRL("staticTreeHeight"), in->staticTreeHeight);
	box2d_put_i32(object, ZEND_STRL("treeHeight"), in->treeHeight);
	box2d_put_i32(object, ZEND_STRL("byteCount"), in->byteCount);
	box2d_put_i32(object, ZEND_STRL("taskCount"), in->taskCount);
	box2d_put_i32_list(object, ZEND_STRL("colorCounts"), 12, in->colorCounts);
	return SUCCESS;
}

zend_result box2d_from_slot_b2Counters(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2Counters_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2Counters(const void *in, zval *out)
{
	return box2d_b2Counters_to_zval(in, out);
}


zend_result box2d_b2DistanceJointDef_from_zval(zval *zv, b2DistanceJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2DistanceJointDef) {
		zend_type_error("b2DistanceJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorA"), box2d_from_slot_b2Vec2, &out->localAnchorA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorB"), box2d_from_slot_b2Vec2, &out->localAnchorB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("length"), &out->length) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSpring"), &out->enableSpring) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hertz"), &out->hertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("dampingRatio"), &out->dampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableLimit"), &out->enableLimit) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("minLength"), &out->minLength) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxLength"), &out->maxLength) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableMotor"), &out->enableMotor) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxMotorForce"), &out->maxMotorForce) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("motorSpeed"), &out->motorSpeed) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2DistanceJointDef_to_zval(const b2DistanceJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2DistanceJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorA"), box2d_to_slot_b2Vec2, &in->localAnchorA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorB"), box2d_to_slot_b2Vec2, &in->localAnchorB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("length"), in->length);
	box2d_put_bool(object, ZEND_STRL("enableSpring"), in->enableSpring);
	box2d_put_f32(object, ZEND_STRL("hertz"), in->hertz);
	box2d_put_f32(object, ZEND_STRL("dampingRatio"), in->dampingRatio);
	box2d_put_bool(object, ZEND_STRL("enableLimit"), in->enableLimit);
	box2d_put_f32(object, ZEND_STRL("minLength"), in->minLength);
	box2d_put_f32(object, ZEND_STRL("maxLength"), in->maxLength);
	box2d_put_bool(object, ZEND_STRL("enableMotor"), in->enableMotor);
	box2d_put_f32(object, ZEND_STRL("maxMotorForce"), in->maxMotorForce);
	box2d_put_f32(object, ZEND_STRL("motorSpeed"), in->motorSpeed);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2DistanceJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2DistanceJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2DistanceJointDef(const void *in, zval *out)
{
	return box2d_b2DistanceJointDef_to_zval(in, out);
}


zend_result box2d_b2MotorJointDef_from_zval(zval *zv, b2MotorJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2MotorJointDef) {
		zend_type_error("b2MotorJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("linearOffset"), box2d_from_slot_b2Vec2, &out->linearOffset, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("angularOffset"), &out->angularOffset) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxForce"), &out->maxForce) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxTorque"), &out->maxTorque) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("correctionFactor"), &out->correctionFactor) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2MotorJointDef_to_zval(const b2MotorJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2MotorJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("linearOffset"), box2d_to_slot_b2Vec2, &in->linearOffset) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("angularOffset"), in->angularOffset);
	box2d_put_f32(object, ZEND_STRL("maxForce"), in->maxForce);
	box2d_put_f32(object, ZEND_STRL("maxTorque"), in->maxTorque);
	box2d_put_f32(object, ZEND_STRL("correctionFactor"), in->correctionFactor);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2MotorJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2MotorJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2MotorJointDef(const void *in, zval *out)
{
	return box2d_b2MotorJointDef_to_zval(in, out);
}


zend_result box2d_b2MouseJointDef_from_zval(zval *zv, b2MouseJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2MouseJointDef) {
		zend_type_error("b2MouseJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("target"), box2d_from_slot_b2Vec2, &out->target, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hertz"), &out->hertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("dampingRatio"), &out->dampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxForce"), &out->maxForce) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2MouseJointDef_to_zval(const b2MouseJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2MouseJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("target"), box2d_to_slot_b2Vec2, &in->target) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("hertz"), in->hertz);
	box2d_put_f32(object, ZEND_STRL("dampingRatio"), in->dampingRatio);
	box2d_put_f32(object, ZEND_STRL("maxForce"), in->maxForce);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2MouseJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2MouseJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2MouseJointDef(const void *in, zval *out)
{
	return box2d_b2MouseJointDef_to_zval(in, out);
}


zend_result box2d_b2FilterJointDef_from_zval(zval *zv, b2FilterJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2FilterJointDef) {
		zend_type_error("b2FilterJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2FilterJointDef_to_zval(const b2FilterJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2FilterJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2FilterJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2FilterJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2FilterJointDef(const void *in, zval *out)
{
	return box2d_b2FilterJointDef_to_zval(in, out);
}


zend_result box2d_b2PrismaticJointDef_from_zval(zval *zv, b2PrismaticJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2PrismaticJointDef) {
		zend_type_error("b2PrismaticJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorA"), box2d_from_slot_b2Vec2, &out->localAnchorA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorB"), box2d_from_slot_b2Vec2, &out->localAnchorB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAxisA"), box2d_from_slot_b2Vec2, &out->localAxisA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("referenceAngle"), &out->referenceAngle) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("targetTranslation"), &out->targetTranslation) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSpring"), &out->enableSpring) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hertz"), &out->hertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("dampingRatio"), &out->dampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableLimit"), &out->enableLimit) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("lowerTranslation"), &out->lowerTranslation) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("upperTranslation"), &out->upperTranslation) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableMotor"), &out->enableMotor) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxMotorForce"), &out->maxMotorForce) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("motorSpeed"), &out->motorSpeed) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2PrismaticJointDef_to_zval(const b2PrismaticJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2PrismaticJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorA"), box2d_to_slot_b2Vec2, &in->localAnchorA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorB"), box2d_to_slot_b2Vec2, &in->localAnchorB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAxisA"), box2d_to_slot_b2Vec2, &in->localAxisA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("referenceAngle"), in->referenceAngle);
	box2d_put_f32(object, ZEND_STRL("targetTranslation"), in->targetTranslation);
	box2d_put_bool(object, ZEND_STRL("enableSpring"), in->enableSpring);
	box2d_put_f32(object, ZEND_STRL("hertz"), in->hertz);
	box2d_put_f32(object, ZEND_STRL("dampingRatio"), in->dampingRatio);
	box2d_put_bool(object, ZEND_STRL("enableLimit"), in->enableLimit);
	box2d_put_f32(object, ZEND_STRL("lowerTranslation"), in->lowerTranslation);
	box2d_put_f32(object, ZEND_STRL("upperTranslation"), in->upperTranslation);
	box2d_put_bool(object, ZEND_STRL("enableMotor"), in->enableMotor);
	box2d_put_f32(object, ZEND_STRL("maxMotorForce"), in->maxMotorForce);
	box2d_put_f32(object, ZEND_STRL("motorSpeed"), in->motorSpeed);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2PrismaticJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2PrismaticJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2PrismaticJointDef(const void *in, zval *out)
{
	return box2d_b2PrismaticJointDef_to_zval(in, out);
}


zend_result box2d_b2RevoluteJointDef_from_zval(zval *zv, b2RevoluteJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2RevoluteJointDef) {
		zend_type_error("b2RevoluteJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorA"), box2d_from_slot_b2Vec2, &out->localAnchorA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorB"), box2d_from_slot_b2Vec2, &out->localAnchorB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("referenceAngle"), &out->referenceAngle) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("targetAngle"), &out->targetAngle) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSpring"), &out->enableSpring) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hertz"), &out->hertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("dampingRatio"), &out->dampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableLimit"), &out->enableLimit) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("lowerAngle"), &out->lowerAngle) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("upperAngle"), &out->upperAngle) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableMotor"), &out->enableMotor) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxMotorTorque"), &out->maxMotorTorque) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("motorSpeed"), &out->motorSpeed) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("drawSize"), &out->drawSize) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2RevoluteJointDef_to_zval(const b2RevoluteJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2RevoluteJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorA"), box2d_to_slot_b2Vec2, &in->localAnchorA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorB"), box2d_to_slot_b2Vec2, &in->localAnchorB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("referenceAngle"), in->referenceAngle);
	box2d_put_f32(object, ZEND_STRL("targetAngle"), in->targetAngle);
	box2d_put_bool(object, ZEND_STRL("enableSpring"), in->enableSpring);
	box2d_put_f32(object, ZEND_STRL("hertz"), in->hertz);
	box2d_put_f32(object, ZEND_STRL("dampingRatio"), in->dampingRatio);
	box2d_put_bool(object, ZEND_STRL("enableLimit"), in->enableLimit);
	box2d_put_f32(object, ZEND_STRL("lowerAngle"), in->lowerAngle);
	box2d_put_f32(object, ZEND_STRL("upperAngle"), in->upperAngle);
	box2d_put_bool(object, ZEND_STRL("enableMotor"), in->enableMotor);
	box2d_put_f32(object, ZEND_STRL("maxMotorTorque"), in->maxMotorTorque);
	box2d_put_f32(object, ZEND_STRL("motorSpeed"), in->motorSpeed);
	box2d_put_f32(object, ZEND_STRL("drawSize"), in->drawSize);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2RevoluteJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2RevoluteJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2RevoluteJointDef(const void *in, zval *out)
{
	return box2d_b2RevoluteJointDef_to_zval(in, out);
}


zend_result box2d_b2WeldJointDef_from_zval(zval *zv, b2WeldJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2WeldJointDef) {
		zend_type_error("b2WeldJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorA"), box2d_from_slot_b2Vec2, &out->localAnchorA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorB"), box2d_from_slot_b2Vec2, &out->localAnchorB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("referenceAngle"), &out->referenceAngle) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("linearHertz"), &out->linearHertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("angularHertz"), &out->angularHertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("linearDampingRatio"), &out->linearDampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("angularDampingRatio"), &out->angularDampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2WeldJointDef_to_zval(const b2WeldJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2WeldJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorA"), box2d_to_slot_b2Vec2, &in->localAnchorA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorB"), box2d_to_slot_b2Vec2, &in->localAnchorB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("referenceAngle"), in->referenceAngle);
	box2d_put_f32(object, ZEND_STRL("linearHertz"), in->linearHertz);
	box2d_put_f32(object, ZEND_STRL("angularHertz"), in->angularHertz);
	box2d_put_f32(object, ZEND_STRL("linearDampingRatio"), in->linearDampingRatio);
	box2d_put_f32(object, ZEND_STRL("angularDampingRatio"), in->angularDampingRatio);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2WeldJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2WeldJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2WeldJointDef(const void *in, zval *out)
{
	return box2d_b2WeldJointDef_to_zval(in, out);
}


zend_result box2d_b2WheelJointDef_from_zval(zval *zv, b2WheelJointDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2WheelJointDef) {
		zend_type_error("b2WheelJointDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdA"), box2d_from_slot_b2BodyId, &out->bodyIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyIdB"), box2d_from_slot_b2BodyId, &out->bodyIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorA"), box2d_from_slot_b2Vec2, &out->localAnchorA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAnchorB"), box2d_from_slot_b2Vec2, &out->localAnchorB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("localAxisA"), box2d_from_slot_b2Vec2, &out->localAxisA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableSpring"), &out->enableSpring) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("hertz"), &out->hertz) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("dampingRatio"), &out->dampingRatio) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableLimit"), &out->enableLimit) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("lowerTranslation"), &out->lowerTranslation) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("upperTranslation"), &out->upperTranslation) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("enableMotor"), &out->enableMotor) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("maxMotorTorque"), &out->maxMotorTorque) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("motorSpeed"), &out->motorSpeed) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("collideConnected"), &out->collideConnected) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	int internalValue_bits;
	if (box2d_prop_i32(object, ZEND_STRL("internalValue"), &internalValue_bits) == FAILURE) return FAILURE;
	out->internalValue = internalValue_bits;
	return SUCCESS;
}

zend_result box2d_b2WheelJointDef_to_zval(const b2WheelJointDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2WheelJointDef);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("bodyIdA"), box2d_to_slot_b2BodyId, &in->bodyIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyIdB"), box2d_to_slot_b2BodyId, &in->bodyIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorA"), box2d_to_slot_b2Vec2, &in->localAnchorA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAnchorB"), box2d_to_slot_b2Vec2, &in->localAnchorB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("localAxisA"), box2d_to_slot_b2Vec2, &in->localAxisA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_bool(object, ZEND_STRL("enableSpring"), in->enableSpring);
	box2d_put_f32(object, ZEND_STRL("hertz"), in->hertz);
	box2d_put_f32(object, ZEND_STRL("dampingRatio"), in->dampingRatio);
	box2d_put_bool(object, ZEND_STRL("enableLimit"), in->enableLimit);
	box2d_put_f32(object, ZEND_STRL("lowerTranslation"), in->lowerTranslation);
	box2d_put_f32(object, ZEND_STRL("upperTranslation"), in->upperTranslation);
	box2d_put_bool(object, ZEND_STRL("enableMotor"), in->enableMotor);
	box2d_put_f32(object, ZEND_STRL("maxMotorTorque"), in->maxMotorTorque);
	box2d_put_f32(object, ZEND_STRL("motorSpeed"), in->motorSpeed);
	box2d_put_bool(object, ZEND_STRL("collideConnected"), in->collideConnected);
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_i32(object, ZEND_STRL("internalValue"), in->internalValue);
	return SUCCESS;
}

zend_result box2d_from_slot_b2WheelJointDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2WheelJointDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2WheelJointDef(const void *in, zval *out)
{
	return box2d_b2WheelJointDef_to_zval(in, out);
}


zend_result box2d_b2ExplosionDef_from_zval(zval *zv, b2ExplosionDef *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ExplosionDef) {
		zend_type_error("b2ExplosionDef expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_u64(object, ZEND_STRL("maskBits"), &out->maskBits) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("position"), box2d_from_slot_b2Vec2, &out->position, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("radius"), &out->radius) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("falloff"), &out->falloff) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("impulsePerLength"), &out->impulsePerLength) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ExplosionDef_to_zval(const b2ExplosionDef *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ExplosionDef);
	zend_object *object = Z_OBJ_P(out);
	box2d_put_u64(object, ZEND_STRL("maskBits"), in->maskBits);
	if (box2d_put_struct(object, ZEND_STRL("position"), box2d_to_slot_b2Vec2, &in->position) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("radius"), in->radius);
	box2d_put_f32(object, ZEND_STRL("falloff"), in->falloff);
	box2d_put_f32(object, ZEND_STRL("impulsePerLength"), in->impulsePerLength);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ExplosionDef(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ExplosionDef_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ExplosionDef(const void *in, zval *out)
{
	return box2d_b2ExplosionDef_to_zval(in, out);
}


zend_result box2d_b2SensorBeginTouchEvent_from_zval(zval *zv, b2SensorBeginTouchEvent *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SensorBeginTouchEvent) {
		zend_type_error("b2SensorBeginTouchEvent expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("sensorShapeId"), box2d_from_slot_b2ShapeId, &out->sensorShapeId, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("visitorShapeId"), box2d_from_slot_b2ShapeId, &out->visitorShapeId, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2SensorBeginTouchEvent_to_zval(const b2SensorBeginTouchEvent *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SensorBeginTouchEvent);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("sensorShapeId"), box2d_to_slot_b2ShapeId, &in->sensorShapeId) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("visitorShapeId"), box2d_to_slot_b2ShapeId, &in->visitorShapeId) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2SensorBeginTouchEvent(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SensorBeginTouchEvent_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SensorBeginTouchEvent(const void *in, zval *out)
{
	return box2d_b2SensorBeginTouchEvent_to_zval(in, out);
}


zend_result box2d_b2SensorEndTouchEvent_from_zval(zval *zv, b2SensorEndTouchEvent *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SensorEndTouchEvent) {
		zend_type_error("b2SensorEndTouchEvent expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("sensorShapeId"), box2d_from_slot_b2ShapeId, &out->sensorShapeId, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("visitorShapeId"), box2d_from_slot_b2ShapeId, &out->visitorShapeId, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2SensorEndTouchEvent_to_zval(const b2SensorEndTouchEvent *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SensorEndTouchEvent);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("sensorShapeId"), box2d_to_slot_b2ShapeId, &in->sensorShapeId) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("visitorShapeId"), box2d_to_slot_b2ShapeId, &in->visitorShapeId) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2SensorEndTouchEvent(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SensorEndTouchEvent_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SensorEndTouchEvent(const void *in, zval *out)
{
	return box2d_b2SensorEndTouchEvent_to_zval(in, out);
}


zend_result box2d_b2SensorEvents_from_zval(zval *zv, b2SensorEvents *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2SensorEvents) {
		zend_type_error("b2SensorEvents expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int beginCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("beginCount"), &beginCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(beginCount_value, -1, "b2SensorEvents::$beginCount") == FAILURE) {
		return FAILURE;
	}
	int endCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("endCount"), &endCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(endCount_value, -1, "b2SensorEvents::$endCount") == FAILURE) {
		return FAILURE;
	}
	void *beginEvents_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("beginEvents"), beginCount_value, &beginEvents_block, sizeof(b2SensorBeginTouchEvent), box2d_from_slot_b2SensorBeginTouchEvent, frame) == FAILURE) return FAILURE;
	out->beginEvents = beginEvents_block;
	void *endEvents_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("endEvents"), endCount_value, &endEvents_block, sizeof(b2SensorEndTouchEvent), box2d_from_slot_b2SensorEndTouchEvent, frame) == FAILURE) return FAILURE;
	out->endEvents = endEvents_block;
	out->beginCount = beginCount_value;
	out->endCount = endCount_value;
	return SUCCESS;
}

zend_result box2d_b2SensorEvents_to_zval(const b2SensorEvents *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2SensorEvents);
	zend_object *object = Z_OBJ_P(out);
	if (in->beginEvents == NULL) {
		zval empty_beginEvents;
		array_init(&empty_beginEvents);
		zend_update_property(object->ce, object, ZEND_STRL("beginEvents"), &empty_beginEvents);
		zval_ptr_dtor(&empty_beginEvents);
	} else if (box2d_put_struct_list(object, ZEND_STRL("beginEvents"), in->beginCount, in->beginEvents, sizeof(b2SensorBeginTouchEvent), box2d_to_slot_b2SensorBeginTouchEvent) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (in->endEvents == NULL) {
		zval empty_endEvents;
		array_init(&empty_endEvents);
		zend_update_property(object->ce, object, ZEND_STRL("endEvents"), &empty_endEvents);
		zval_ptr_dtor(&empty_endEvents);
	} else if (box2d_put_struct_list(object, ZEND_STRL("endEvents"), in->endCount, in->endEvents, sizeof(b2SensorEndTouchEvent), box2d_to_slot_b2SensorEndTouchEvent) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("beginCount"), in->beginCount);
	box2d_put_i32(object, ZEND_STRL("endCount"), in->endCount);
	return SUCCESS;
}

zend_result box2d_from_slot_b2SensorEvents(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2SensorEvents_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2SensorEvents(const void *in, zval *out)
{
	return box2d_b2SensorEvents_to_zval(in, out);
}


zend_result box2d_b2ContactBeginTouchEvent_from_zval(zval *zv, b2ContactBeginTouchEvent *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ContactBeginTouchEvent) {
		zend_type_error("b2ContactBeginTouchEvent expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdA"), box2d_from_slot_b2ShapeId, &out->shapeIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdB"), box2d_from_slot_b2ShapeId, &out->shapeIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("manifold"), box2d_from_slot_b2Manifold, &out->manifold, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ContactBeginTouchEvent_to_zval(const b2ContactBeginTouchEvent *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ContactBeginTouchEvent);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("shapeIdA"), box2d_to_slot_b2ShapeId, &in->shapeIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("shapeIdB"), box2d_to_slot_b2ShapeId, &in->shapeIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("manifold"), box2d_to_slot_b2Manifold, &in->manifold) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2ContactBeginTouchEvent(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ContactBeginTouchEvent_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ContactBeginTouchEvent(const void *in, zval *out)
{
	return box2d_b2ContactBeginTouchEvent_to_zval(in, out);
}


zend_result box2d_b2ContactEndTouchEvent_from_zval(zval *zv, b2ContactEndTouchEvent *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ContactEndTouchEvent) {
		zend_type_error("b2ContactEndTouchEvent expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdA"), box2d_from_slot_b2ShapeId, &out->shapeIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdB"), box2d_from_slot_b2ShapeId, &out->shapeIdB, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ContactEndTouchEvent_to_zval(const b2ContactEndTouchEvent *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ContactEndTouchEvent);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("shapeIdA"), box2d_to_slot_b2ShapeId, &in->shapeIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("shapeIdB"), box2d_to_slot_b2ShapeId, &in->shapeIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2ContactEndTouchEvent(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ContactEndTouchEvent_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ContactEndTouchEvent(const void *in, zval *out)
{
	return box2d_b2ContactEndTouchEvent_to_zval(in, out);
}


zend_result box2d_b2ContactHitEvent_from_zval(zval *zv, b2ContactHitEvent *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ContactHitEvent) {
		zend_type_error("b2ContactHitEvent expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdA"), box2d_from_slot_b2ShapeId, &out->shapeIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdB"), box2d_from_slot_b2ShapeId, &out->shapeIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("point"), box2d_from_slot_b2Vec2, &out->point, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("normal"), box2d_from_slot_b2Vec2, &out->normal, frame) == FAILURE) return FAILURE;
	if (box2d_prop_f32(object, ZEND_STRL("approachSpeed"), &out->approachSpeed) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ContactHitEvent_to_zval(const b2ContactHitEvent *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ContactHitEvent);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("shapeIdA"), box2d_to_slot_b2ShapeId, &in->shapeIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("shapeIdB"), box2d_to_slot_b2ShapeId, &in->shapeIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("point"), box2d_to_slot_b2Vec2, &in->point) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("normal"), box2d_to_slot_b2Vec2, &in->normal) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_f32(object, ZEND_STRL("approachSpeed"), in->approachSpeed);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ContactHitEvent(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ContactHitEvent_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ContactHitEvent(const void *in, zval *out)
{
	return box2d_b2ContactHitEvent_to_zval(in, out);
}


zend_result box2d_b2ContactEvents_from_zval(zval *zv, b2ContactEvents *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ContactEvents) {
		zend_type_error("b2ContactEvents expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int beginCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("beginCount"), &beginCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(beginCount_value, -1, "b2ContactEvents::$beginCount") == FAILURE) {
		return FAILURE;
	}
	int endCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("endCount"), &endCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(endCount_value, -1, "b2ContactEvents::$endCount") == FAILURE) {
		return FAILURE;
	}
	int hitCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("hitCount"), &hitCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(hitCount_value, -1, "b2ContactEvents::$hitCount") == FAILURE) {
		return FAILURE;
	}
	void *beginEvents_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("beginEvents"), beginCount_value, &beginEvents_block, sizeof(b2ContactBeginTouchEvent), box2d_from_slot_b2ContactBeginTouchEvent, frame) == FAILURE) return FAILURE;
	out->beginEvents = beginEvents_block;
	void *endEvents_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("endEvents"), endCount_value, &endEvents_block, sizeof(b2ContactEndTouchEvent), box2d_from_slot_b2ContactEndTouchEvent, frame) == FAILURE) return FAILURE;
	out->endEvents = endEvents_block;
	void *hitEvents_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("hitEvents"), hitCount_value, &hitEvents_block, sizeof(b2ContactHitEvent), box2d_from_slot_b2ContactHitEvent, frame) == FAILURE) return FAILURE;
	out->hitEvents = hitEvents_block;
	out->beginCount = beginCount_value;
	out->endCount = endCount_value;
	out->hitCount = hitCount_value;
	return SUCCESS;
}

zend_result box2d_b2ContactEvents_to_zval(const b2ContactEvents *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ContactEvents);
	zend_object *object = Z_OBJ_P(out);
	if (in->beginEvents == NULL) {
		zval empty_beginEvents;
		array_init(&empty_beginEvents);
		zend_update_property(object->ce, object, ZEND_STRL("beginEvents"), &empty_beginEvents);
		zval_ptr_dtor(&empty_beginEvents);
	} else if (box2d_put_struct_list(object, ZEND_STRL("beginEvents"), in->beginCount, in->beginEvents, sizeof(b2ContactBeginTouchEvent), box2d_to_slot_b2ContactBeginTouchEvent) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (in->endEvents == NULL) {
		zval empty_endEvents;
		array_init(&empty_endEvents);
		zend_update_property(object->ce, object, ZEND_STRL("endEvents"), &empty_endEvents);
		zval_ptr_dtor(&empty_endEvents);
	} else if (box2d_put_struct_list(object, ZEND_STRL("endEvents"), in->endCount, in->endEvents, sizeof(b2ContactEndTouchEvent), box2d_to_slot_b2ContactEndTouchEvent) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (in->hitEvents == NULL) {
		zval empty_hitEvents;
		array_init(&empty_hitEvents);
		zend_update_property(object->ce, object, ZEND_STRL("hitEvents"), &empty_hitEvents);
		zval_ptr_dtor(&empty_hitEvents);
	} else if (box2d_put_struct_list(object, ZEND_STRL("hitEvents"), in->hitCount, in->hitEvents, sizeof(b2ContactHitEvent), box2d_to_slot_b2ContactHitEvent) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("beginCount"), in->beginCount);
	box2d_put_i32(object, ZEND_STRL("endCount"), in->endCount);
	box2d_put_i32(object, ZEND_STRL("hitCount"), in->hitCount);
	return SUCCESS;
}

zend_result box2d_from_slot_b2ContactEvents(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ContactEvents_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ContactEvents(const void *in, zval *out)
{
	return box2d_b2ContactEvents_to_zval(in, out);
}


zend_result box2d_b2BodyMoveEvent_from_zval(zval *zv, b2BodyMoveEvent *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2BodyMoveEvent) {
		zend_type_error("b2BodyMoveEvent expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("transform"), box2d_from_slot_b2Transform, &out->transform, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("bodyId"), box2d_from_slot_b2BodyId, &out->bodyId, frame) == FAILURE) return FAILURE;
	if (box2d_prop_userdata(object, ZEND_STRL("userData"), &out->userData) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("fellAsleep"), &out->fellAsleep) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2BodyMoveEvent_to_zval(const b2BodyMoveEvent *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2BodyMoveEvent);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("transform"), box2d_to_slot_b2Transform, &in->transform) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("bodyId"), box2d_to_slot_b2BodyId, &in->bodyId) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_userdata(object, ZEND_STRL("userData"), in->userData);
	box2d_put_bool(object, ZEND_STRL("fellAsleep"), in->fellAsleep);
	return SUCCESS;
}

zend_result box2d_from_slot_b2BodyMoveEvent(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2BodyMoveEvent_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2BodyMoveEvent(const void *in, zval *out)
{
	return box2d_b2BodyMoveEvent_to_zval(in, out);
}


zend_result box2d_b2BodyEvents_from_zval(zval *zv, b2BodyEvents *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2BodyEvents) {
		zend_type_error("b2BodyEvents expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	int moveCount_value;
	if (box2d_prop_i32(object, ZEND_STRL("moveCount"), &moveCount_value) == FAILURE) {
		return FAILURE;
	}
	if (box2d_check_count(moveCount_value, -1, "b2BodyEvents::$moveCount") == FAILURE) {
		return FAILURE;
	}
	void *moveEvents_block = NULL;
	if (box2d_list_alloc(object, ZEND_STRL("moveEvents"), moveCount_value, &moveEvents_block, sizeof(b2BodyMoveEvent), box2d_from_slot_b2BodyMoveEvent, frame) == FAILURE) return FAILURE;
	out->moveEvents = moveEvents_block;
	out->moveCount = moveCount_value;
	return SUCCESS;
}

zend_result box2d_b2BodyEvents_to_zval(const b2BodyEvents *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2BodyEvents);
	zend_object *object = Z_OBJ_P(out);
	if (in->moveEvents == NULL) {
		zval empty_moveEvents;
		array_init(&empty_moveEvents);
		zend_update_property(object->ce, object, ZEND_STRL("moveEvents"), &empty_moveEvents);
		zval_ptr_dtor(&empty_moveEvents);
	} else if (box2d_put_struct_list(object, ZEND_STRL("moveEvents"), in->moveCount, in->moveEvents, sizeof(b2BodyMoveEvent), box2d_to_slot_b2BodyMoveEvent) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_i32(object, ZEND_STRL("moveCount"), in->moveCount);
	return SUCCESS;
}

zend_result box2d_from_slot_b2BodyEvents(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2BodyEvents_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2BodyEvents(const void *in, zval *out)
{
	return box2d_b2BodyEvents_to_zval(in, out);
}


zend_result box2d_b2ContactData_from_zval(zval *zv, b2ContactData *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2ContactData) {
		zend_type_error("b2ContactData expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdA"), box2d_from_slot_b2ShapeId, &out->shapeIdA, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("shapeIdB"), box2d_from_slot_b2ShapeId, &out->shapeIdB, frame) == FAILURE) return FAILURE;
	if (box2d_prop_struct(object, ZEND_STRL("manifold"), box2d_from_slot_b2Manifold, &out->manifold, frame) == FAILURE) return FAILURE;
	return SUCCESS;
}

zend_result box2d_b2ContactData_to_zval(const b2ContactData *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2ContactData);
	zend_object *object = Z_OBJ_P(out);
	if (box2d_put_struct(object, ZEND_STRL("shapeIdA"), box2d_to_slot_b2ShapeId, &in->shapeIdA) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("shapeIdB"), box2d_to_slot_b2ShapeId, &in->shapeIdB) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	if (box2d_put_struct(object, ZEND_STRL("manifold"), box2d_to_slot_b2Manifold, &in->manifold) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	return SUCCESS;
}

zend_result box2d_from_slot_b2ContactData(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2ContactData_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2ContactData(const void *in, zval *out)
{
	return box2d_b2ContactData_to_zval(in, out);
}


zend_result box2d_b2DebugDraw_from_zval(zval *zv, b2DebugDraw *out, box2d_frame *frame)
{
	(void) frame;
	if (Z_TYPE_P(zv) != IS_OBJECT || Z_OBJCE_P(zv) != box2d_ce_b2DebugDraw) {
		zend_type_error("b2DebugDraw expected, %s given", zend_zval_type_name(zv));
		return FAILURE;
	}
	zend_object *object = Z_OBJ_P(zv);
	memset(out, 0, sizeof(*out));
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawPolygonFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawSolidPolygonFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawCircleFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawSolidCircleFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawSolidCapsuleFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawSegmentFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawTransformFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawPointFcn"), 0, NULL);
	(void) zend_read_property(object->ce, object, ZEND_STRL("DrawStringFcn"), 0, NULL);
	if (box2d_prop_struct(object, ZEND_STRL("drawingBounds"), box2d_from_slot_b2AABB, &out->drawingBounds, frame) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("useDrawingBounds"), &out->useDrawingBounds) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawShapes"), &out->drawShapes) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawJoints"), &out->drawJoints) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawJointExtras"), &out->drawJointExtras) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawBounds"), &out->drawBounds) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawMass"), &out->drawMass) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawBodyNames"), &out->drawBodyNames) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawContacts"), &out->drawContacts) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawGraphColors"), &out->drawGraphColors) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawContactNormals"), &out->drawContactNormals) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawContactImpulses"), &out->drawContactImpulses) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawContactFeatures"), &out->drawContactFeatures) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawFrictionImpulses"), &out->drawFrictionImpulses) == FAILURE) return FAILURE;
	if (box2d_prop_bool(object, ZEND_STRL("drawIslands"), &out->drawIslands) == FAILURE) return FAILURE;
	(void) zend_read_property(object->ce, object, ZEND_STRL("context"), 0, NULL);
	return SUCCESS;
}

zend_result box2d_b2DebugDraw_to_zval(const b2DebugDraw *in, zval *out)
{
	object_init_ex(out, box2d_ce_b2DebugDraw);
	zend_object *object = Z_OBJ_P(out);
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawPolygonFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawSolidPolygonFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawCircleFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawSolidCircleFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawSolidCapsuleFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawSegmentFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawTransformFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawPointFcn"));
	zend_update_property_null(object->ce, object, ZEND_STRL("DrawStringFcn"));
	if (box2d_put_struct(object, ZEND_STRL("drawingBounds"), box2d_to_slot_b2AABB, &in->drawingBounds) == FAILURE) {
		zval_ptr_dtor(out);
		return FAILURE;
	}
	box2d_put_bool(object, ZEND_STRL("useDrawingBounds"), in->useDrawingBounds);
	box2d_put_bool(object, ZEND_STRL("drawShapes"), in->drawShapes);
	box2d_put_bool(object, ZEND_STRL("drawJoints"), in->drawJoints);
	box2d_put_bool(object, ZEND_STRL("drawJointExtras"), in->drawJointExtras);
	box2d_put_bool(object, ZEND_STRL("drawBounds"), in->drawBounds);
	box2d_put_bool(object, ZEND_STRL("drawMass"), in->drawMass);
	box2d_put_bool(object, ZEND_STRL("drawBodyNames"), in->drawBodyNames);
	box2d_put_bool(object, ZEND_STRL("drawContacts"), in->drawContacts);
	box2d_put_bool(object, ZEND_STRL("drawGraphColors"), in->drawGraphColors);
	box2d_put_bool(object, ZEND_STRL("drawContactNormals"), in->drawContactNormals);
	box2d_put_bool(object, ZEND_STRL("drawContactImpulses"), in->drawContactImpulses);
	box2d_put_bool(object, ZEND_STRL("drawContactFeatures"), in->drawContactFeatures);
	box2d_put_bool(object, ZEND_STRL("drawFrictionImpulses"), in->drawFrictionImpulses);
	box2d_put_bool(object, ZEND_STRL("drawIslands"), in->drawIslands);
	zend_update_property_null(object->ce, object, ZEND_STRL("context"));
	return SUCCESS;
}

zend_result box2d_from_slot_b2DebugDraw(zval *zv, void *out, box2d_frame *frame)
{
	return box2d_b2DebugDraw_from_zval(zv, out, frame);
}

zend_result box2d_to_slot_b2DebugDraw(const void *in, zval *out)
{
	return box2d_b2DebugDraw_to_zval(in, out);
}

