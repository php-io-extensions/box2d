/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 74984e1e6cf4c7e7263e0330316b951e52bc3c4d */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Vec2_zero, 0, 0, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Rot_identity, 0, 0, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Transform_identity, 0, 0, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Mat22_zero, 0, 0, b2Mat22, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsValidFloat, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsValidVec2, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsValidRotation, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, q, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsValidAABB, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, aabb, b2AABB, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsValidPlane, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Plane, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MinInt, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MaxInt arginfo_b2MinInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2AbsInt, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2ClampInt, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MinFloat, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MaxFloat arginfo_b2MinFloat

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2AbsFloat, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2ClampFloat, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Atan2, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeCosSin, 0, 1, b2CosSin, 0)
	ZEND_ARG_TYPE_INFO(0, radians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Dot, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Cross arginfo_b2Dot

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CrossVS, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, s, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CrossSV, 0, 2, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, s, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2LeftPerp, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2RightPerp arginfo_b2LeftPerp

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Add, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Sub arginfo_b2Add

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Neg, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Lerp, 0, 3, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, t, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Mul arginfo_b2Add

#define arginfo_b2MulSV arginfo_b2CrossSV

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MulAdd, 0, 3, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, s, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MulSub arginfo_b2MulAdd

#define arginfo_b2Abs arginfo_b2Neg

#define arginfo_b2Min arginfo_b2Add

#define arginfo_b2Max arginfo_b2Add

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Clamp, 0, 3, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Length, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Distance arginfo_b2Dot

#define arginfo_b2Normalize arginfo_b2LeftPerp

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsNormalized, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2GetLengthAndNormalize, 0, 2, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(1, length, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2NormalizeRot, 0, 1, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, q, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2IntegrateRotation, 0, 2, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, q1, b2Rot, 0)
	ZEND_ARG_TYPE_INFO(0, deltaAngle, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2LengthSquared arginfo_b2Length

#define arginfo_b2DistanceSquared arginfo_b2Dot

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeRot, 0, 1, b2Rot, 0)
	ZEND_ARG_TYPE_INFO(0, radians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeRotationBetweenUnitVectors, 0, 2, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, v1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, v2, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2IsNormalizedRot arginfo_b2IsValidRotation

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2NLerp, 0, 3, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, q1, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, q2, b2Rot, 0)
	ZEND_ARG_TYPE_INFO(0, t, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2ComputeAngularVelocity, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, q1, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, q2, b2Rot, 0)
	ZEND_ARG_TYPE_INFO(0, inv_h, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Rot_GetAngle, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, q, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Rot_GetXAxis, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, q, b2Rot, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Rot_GetYAxis arginfo_b2Rot_GetXAxis

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MulRot, 0, 2, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, q, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, r, b2Rot, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2InvMulRot arginfo_b2MulRot

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2RelativeAngle, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2UnwindAngle, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, radians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2RotateVector, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, q, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2InvRotateVector arginfo_b2RotateVector

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2TransformPoint, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, t, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, p, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2InvTransformPoint arginfo_b2TransformPoint

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MulTransforms, 0, 2, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, A, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, B, b2Transform, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2InvMulTransforms arginfo_b2MulTransforms

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MulMV, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, A, b2Mat22, 0)
	ZEND_ARG_OBJ_INFO(0, v, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2GetInverse22, 0, 1, b2Mat22, 0)
	ZEND_ARG_OBJ_INFO(0, A, b2Mat22, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Solve22, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, A, b2Mat22, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2AABB_Contains, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2AABB, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2AABB_Center, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2AABB, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2AABB_Extents arginfo_b2AABB_Center

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2AABB_Union, 0, 2, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, a, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, b, b2AABB, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2AABB_Overlaps arginfo_b2AABB_Contains

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeAABB, 0, 3, b2AABB, 0)
	ZEND_ARG_TYPE_INFO(0, points, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2PlaneSeparation, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, plane, b2Plane, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2SpringDamper, 0, 5, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, hertz, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dampingRatio, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, velocity, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, timeStep, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2SetLengthUnitsPerMeter, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, lengthUnits, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2GetLengthUnitsPerMeter, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Vec2___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2CosSin___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cosine, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sine, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Rot___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, c, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, s, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Transform___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, p, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, q, b2Rot, 0, "new b2Rot()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Mat22___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, cx, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, cy, b2Vec2, 0, "new b2Vec2()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2AABB___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, lowerBound, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, upperBound, b2Vec2, 0, "new b2Vec2()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Plane___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, normal, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_FUNCTION(b2Vec2_zero);
ZEND_FUNCTION(b2Rot_identity);
ZEND_FUNCTION(b2Transform_identity);
ZEND_FUNCTION(b2Mat22_zero);
ZEND_FUNCTION(b2IsValidFloat);
ZEND_FUNCTION(b2IsValidVec2);
ZEND_FUNCTION(b2IsValidRotation);
ZEND_FUNCTION(b2IsValidAABB);
ZEND_FUNCTION(b2IsValidPlane);
ZEND_FUNCTION(b2MinInt);
ZEND_FUNCTION(b2MaxInt);
ZEND_FUNCTION(b2AbsInt);
ZEND_FUNCTION(b2ClampInt);
ZEND_FUNCTION(b2MinFloat);
ZEND_FUNCTION(b2MaxFloat);
ZEND_FUNCTION(b2AbsFloat);
ZEND_FUNCTION(b2ClampFloat);
ZEND_FUNCTION(b2Atan2);
ZEND_FUNCTION(b2ComputeCosSin);
ZEND_FUNCTION(b2Dot);
ZEND_FUNCTION(b2Cross);
ZEND_FUNCTION(b2CrossVS);
ZEND_FUNCTION(b2CrossSV);
ZEND_FUNCTION(b2LeftPerp);
ZEND_FUNCTION(b2RightPerp);
ZEND_FUNCTION(b2Add);
ZEND_FUNCTION(b2Sub);
ZEND_FUNCTION(b2Neg);
ZEND_FUNCTION(b2Lerp);
ZEND_FUNCTION(b2Mul);
ZEND_FUNCTION(b2MulSV);
ZEND_FUNCTION(b2MulAdd);
ZEND_FUNCTION(b2MulSub);
ZEND_FUNCTION(b2Abs);
ZEND_FUNCTION(b2Min);
ZEND_FUNCTION(b2Max);
ZEND_FUNCTION(b2Clamp);
ZEND_FUNCTION(b2Length);
ZEND_FUNCTION(b2Distance);
ZEND_FUNCTION(b2Normalize);
ZEND_FUNCTION(b2IsNormalized);
ZEND_FUNCTION(b2GetLengthAndNormalize);
ZEND_FUNCTION(b2NormalizeRot);
ZEND_FUNCTION(b2IntegrateRotation);
ZEND_FUNCTION(b2LengthSquared);
ZEND_FUNCTION(b2DistanceSquared);
ZEND_FUNCTION(b2MakeRot);
ZEND_FUNCTION(b2ComputeRotationBetweenUnitVectors);
ZEND_FUNCTION(b2IsNormalizedRot);
ZEND_FUNCTION(b2NLerp);
ZEND_FUNCTION(b2ComputeAngularVelocity);
ZEND_FUNCTION(b2Rot_GetAngle);
ZEND_FUNCTION(b2Rot_GetXAxis);
ZEND_FUNCTION(b2Rot_GetYAxis);
ZEND_FUNCTION(b2MulRot);
ZEND_FUNCTION(b2InvMulRot);
ZEND_FUNCTION(b2RelativeAngle);
ZEND_FUNCTION(b2UnwindAngle);
ZEND_FUNCTION(b2RotateVector);
ZEND_FUNCTION(b2InvRotateVector);
ZEND_FUNCTION(b2TransformPoint);
ZEND_FUNCTION(b2InvTransformPoint);
ZEND_FUNCTION(b2MulTransforms);
ZEND_FUNCTION(b2InvMulTransforms);
ZEND_FUNCTION(b2MulMV);
ZEND_FUNCTION(b2GetInverse22);
ZEND_FUNCTION(b2Solve22);
ZEND_FUNCTION(b2AABB_Contains);
ZEND_FUNCTION(b2AABB_Center);
ZEND_FUNCTION(b2AABB_Extents);
ZEND_FUNCTION(b2AABB_Union);
ZEND_FUNCTION(b2AABB_Overlaps);
ZEND_FUNCTION(b2MakeAABB);
ZEND_FUNCTION(b2PlaneSeparation);
ZEND_FUNCTION(b2SpringDamper);
ZEND_FUNCTION(b2SetLengthUnitsPerMeter);
ZEND_FUNCTION(b2GetLengthUnitsPerMeter);
ZEND_METHOD(b2Vec2, __construct);
ZEND_METHOD(b2CosSin, __construct);
ZEND_METHOD(b2Rot, __construct);
ZEND_METHOD(b2Transform, __construct);
ZEND_METHOD(b2Mat22, __construct);
ZEND_METHOD(b2AABB, __construct);
ZEND_METHOD(b2Plane, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(b2Vec2_zero, arginfo_b2Vec2_zero)
	ZEND_FE(b2Rot_identity, arginfo_b2Rot_identity)
	ZEND_FE(b2Transform_identity, arginfo_b2Transform_identity)
	ZEND_FE(b2Mat22_zero, arginfo_b2Mat22_zero)
	ZEND_FE(b2IsValidFloat, arginfo_b2IsValidFloat)
	ZEND_FE(b2IsValidVec2, arginfo_b2IsValidVec2)
	ZEND_FE(b2IsValidRotation, arginfo_b2IsValidRotation)
	ZEND_FE(b2IsValidAABB, arginfo_b2IsValidAABB)
	ZEND_FE(b2IsValidPlane, arginfo_b2IsValidPlane)
	ZEND_FE(b2MinInt, arginfo_b2MinInt)
	ZEND_FE(b2MaxInt, arginfo_b2MaxInt)
	ZEND_FE(b2AbsInt, arginfo_b2AbsInt)
	ZEND_FE(b2ClampInt, arginfo_b2ClampInt)
	ZEND_FE(b2MinFloat, arginfo_b2MinFloat)
	ZEND_FE(b2MaxFloat, arginfo_b2MaxFloat)
	ZEND_FE(b2AbsFloat, arginfo_b2AbsFloat)
	ZEND_FE(b2ClampFloat, arginfo_b2ClampFloat)
	ZEND_FE(b2Atan2, arginfo_b2Atan2)
	ZEND_FE(b2ComputeCosSin, arginfo_b2ComputeCosSin)
	ZEND_FE(b2Dot, arginfo_b2Dot)
	ZEND_FE(b2Cross, arginfo_b2Cross)
	ZEND_FE(b2CrossVS, arginfo_b2CrossVS)
	ZEND_FE(b2CrossSV, arginfo_b2CrossSV)
	ZEND_FE(b2LeftPerp, arginfo_b2LeftPerp)
	ZEND_FE(b2RightPerp, arginfo_b2RightPerp)
	ZEND_FE(b2Add, arginfo_b2Add)
	ZEND_FE(b2Sub, arginfo_b2Sub)
	ZEND_FE(b2Neg, arginfo_b2Neg)
	ZEND_FE(b2Lerp, arginfo_b2Lerp)
	ZEND_FE(b2Mul, arginfo_b2Mul)
	ZEND_FE(b2MulSV, arginfo_b2MulSV)
	ZEND_FE(b2MulAdd, arginfo_b2MulAdd)
	ZEND_FE(b2MulSub, arginfo_b2MulSub)
	ZEND_FE(b2Abs, arginfo_b2Abs)
	ZEND_FE(b2Min, arginfo_b2Min)
	ZEND_FE(b2Max, arginfo_b2Max)
	ZEND_FE(b2Clamp, arginfo_b2Clamp)
	ZEND_FE(b2Length, arginfo_b2Length)
	ZEND_FE(b2Distance, arginfo_b2Distance)
	ZEND_FE(b2Normalize, arginfo_b2Normalize)
	ZEND_FE(b2IsNormalized, arginfo_b2IsNormalized)
	ZEND_FE(b2GetLengthAndNormalize, arginfo_b2GetLengthAndNormalize)
	ZEND_FE(b2NormalizeRot, arginfo_b2NormalizeRot)
	ZEND_FE(b2IntegrateRotation, arginfo_b2IntegrateRotation)
	ZEND_FE(b2LengthSquared, arginfo_b2LengthSquared)
	ZEND_FE(b2DistanceSquared, arginfo_b2DistanceSquared)
	ZEND_FE(b2MakeRot, arginfo_b2MakeRot)
	ZEND_FE(b2ComputeRotationBetweenUnitVectors, arginfo_b2ComputeRotationBetweenUnitVectors)
	ZEND_FE(b2IsNormalizedRot, arginfo_b2IsNormalizedRot)
	ZEND_FE(b2NLerp, arginfo_b2NLerp)
	ZEND_FE(b2ComputeAngularVelocity, arginfo_b2ComputeAngularVelocity)
	ZEND_FE(b2Rot_GetAngle, arginfo_b2Rot_GetAngle)
	ZEND_FE(b2Rot_GetXAxis, arginfo_b2Rot_GetXAxis)
	ZEND_FE(b2Rot_GetYAxis, arginfo_b2Rot_GetYAxis)
	ZEND_FE(b2MulRot, arginfo_b2MulRot)
	ZEND_FE(b2InvMulRot, arginfo_b2InvMulRot)
	ZEND_FE(b2RelativeAngle, arginfo_b2RelativeAngle)
	ZEND_FE(b2UnwindAngle, arginfo_b2UnwindAngle)
	ZEND_FE(b2RotateVector, arginfo_b2RotateVector)
	ZEND_FE(b2InvRotateVector, arginfo_b2InvRotateVector)
	ZEND_FE(b2TransformPoint, arginfo_b2TransformPoint)
	ZEND_FE(b2InvTransformPoint, arginfo_b2InvTransformPoint)
	ZEND_FE(b2MulTransforms, arginfo_b2MulTransforms)
	ZEND_FE(b2InvMulTransforms, arginfo_b2InvMulTransforms)
	ZEND_FE(b2MulMV, arginfo_b2MulMV)
	ZEND_FE(b2GetInverse22, arginfo_b2GetInverse22)
	ZEND_FE(b2Solve22, arginfo_b2Solve22)
	ZEND_FE(b2AABB_Contains, arginfo_b2AABB_Contains)
	ZEND_FE(b2AABB_Center, arginfo_b2AABB_Center)
	ZEND_FE(b2AABB_Extents, arginfo_b2AABB_Extents)
	ZEND_FE(b2AABB_Union, arginfo_b2AABB_Union)
	ZEND_FE(b2AABB_Overlaps, arginfo_b2AABB_Overlaps)
	ZEND_FE(b2MakeAABB, arginfo_b2MakeAABB)
	ZEND_FE(b2PlaneSeparation, arginfo_b2PlaneSeparation)
	ZEND_FE(b2SpringDamper, arginfo_b2SpringDamper)
	ZEND_FE(b2SetLengthUnitsPerMeter, arginfo_b2SetLengthUnitsPerMeter)
	ZEND_FE(b2GetLengthUnitsPerMeter, arginfo_b2GetLengthUnitsPerMeter)
	ZEND_FE_END
};

static const zend_function_entry class_b2Vec2_methods[] = {
	ZEND_ME(b2Vec2, __construct, arginfo_class_b2Vec2___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2CosSin_methods[] = {
	ZEND_ME(b2CosSin, __construct, arginfo_class_b2CosSin___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Rot_methods[] = {
	ZEND_ME(b2Rot, __construct, arginfo_class_b2Rot___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Transform_methods[] = {
	ZEND_ME(b2Transform, __construct, arginfo_class_b2Transform___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Mat22_methods[] = {
	ZEND_ME(b2Mat22, __construct, arginfo_class_b2Mat22___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2AABB_methods[] = {
	ZEND_ME(b2AABB, __construct, arginfo_class_b2AABB___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Plane_methods[] = {
	ZEND_ME(b2Plane, __construct, arginfo_class_b2Plane___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_math_functions_symbols(int module_number)
{
	REGISTER_DOUBLE_CONSTANT("B2_PI", B2_PI, CONST_PERSISTENT);
}

static zend_class_entry *register_class_b2Vec2(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Vec2", class_b2Vec2_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_default_value;
	ZVAL_DOUBLE(&property_x_default_value, 0.0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_DOUBLE(&property_y_default_value, 0.0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	return class_entry;
}

static zend_class_entry *register_class_b2CosSin(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2CosSin", class_b2CosSin_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_cosine_default_value;
	ZVAL_DOUBLE(&property_cosine_default_value, 0.0);
	zend_string *property_cosine_name = zend_string_init("cosine", sizeof("cosine") - 1, 1);
	zend_declare_typed_property(class_entry, property_cosine_name, &property_cosine_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_cosine_name);

	zval property_sine_default_value;
	ZVAL_DOUBLE(&property_sine_default_value, 0.0);
	zend_string *property_sine_name = zend_string_init("sine", sizeof("sine") - 1, 1);
	zend_declare_typed_property(class_entry, property_sine_name, &property_sine_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_sine_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Rot(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Rot", class_b2Rot_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_c_default_value;
	ZVAL_DOUBLE(&property_c_default_value, 0.0);
	zend_string *property_c_name = zend_string_init("c", sizeof("c") - 1, 1);
	zend_declare_typed_property(class_entry, property_c_name, &property_c_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_c_name);

	zval property_s_default_value;
	ZVAL_DOUBLE(&property_s_default_value, 0.0);
	zend_string *property_s_name = zend_string_init("s", sizeof("s") - 1, 1);
	zend_declare_typed_property(class_entry, property_s_name, &property_s_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_s_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Transform(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Transform", class_b2Transform_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_p_default_value;
	ZVAL_UNDEF(&property_p_default_value);
	zend_string *property_p_name = zend_string_init("p", sizeof("p") - 1, 1);
	zend_string *property_p_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_p_name, &property_p_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_p_class_b2Vec2, 0, 0));
	zend_string_release(property_p_name);

	zval property_q_default_value;
	ZVAL_UNDEF(&property_q_default_value);
	zend_string *property_q_name = zend_string_init("q", sizeof("q") - 1, 1);
	zend_string *property_q_class_b2Rot = zend_string_init("b2Rot", sizeof("b2Rot")-1, 1);
	zend_declare_typed_property(class_entry, property_q_name, &property_q_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_q_class_b2Rot, 0, 0));
	zend_string_release(property_q_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Mat22(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Mat22", class_b2Mat22_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_cx_default_value;
	ZVAL_UNDEF(&property_cx_default_value);
	zend_string *property_cx_name = zend_string_init("cx", sizeof("cx") - 1, 1);
	zend_string *property_cx_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_cx_name, &property_cx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_cx_class_b2Vec2, 0, 0));
	zend_string_release(property_cx_name);

	zval property_cy_default_value;
	ZVAL_UNDEF(&property_cy_default_value);
	zend_string *property_cy_name = zend_string_init("cy", sizeof("cy") - 1, 1);
	zend_string *property_cy_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_cy_name, &property_cy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_cy_class_b2Vec2, 0, 0));
	zend_string_release(property_cy_name);

	return class_entry;
}

static zend_class_entry *register_class_b2AABB(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2AABB", class_b2AABB_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_lowerBound_default_value;
	ZVAL_UNDEF(&property_lowerBound_default_value);
	zend_string *property_lowerBound_name = zend_string_init("lowerBound", sizeof("lowerBound") - 1, 1);
	zend_string *property_lowerBound_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_lowerBound_name, &property_lowerBound_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_lowerBound_class_b2Vec2, 0, 0));
	zend_string_release(property_lowerBound_name);

	zval property_upperBound_default_value;
	ZVAL_UNDEF(&property_upperBound_default_value);
	zend_string *property_upperBound_name = zend_string_init("upperBound", sizeof("upperBound") - 1, 1);
	zend_string *property_upperBound_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_upperBound_name, &property_upperBound_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_upperBound_class_b2Vec2, 0, 0));
	zend_string_release(property_upperBound_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Plane(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Plane", class_b2Plane_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_normal_default_value;
	ZVAL_UNDEF(&property_normal_default_value);
	zend_string *property_normal_name = zend_string_init("normal", sizeof("normal") - 1, 1);
	zend_string *property_normal_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_normal_name, &property_normal_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_normal_class_b2Vec2, 0, 0));
	zend_string_release(property_normal_name);

	zval property_offset_default_value;
	ZVAL_DOUBLE(&property_offset_default_value, 0.0);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_offset_name);

	return class_entry;
}
