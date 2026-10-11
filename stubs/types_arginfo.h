/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a8f24d63b22580cd1e9f9b2d0df2b6cc43fd9083 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultWorldDef, 0, 0, b2WorldDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultBodyDef, 0, 0, b2BodyDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultFilter, 0, 0, b2Filter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultQueryFilter, 0, 0, b2QueryFilter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultSurfaceMaterial, 0, 0, b2SurfaceMaterial, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultShapeDef, 0, 0, b2ShapeDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultChainDef, 0, 0, b2ChainDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultDistanceJointDef, 0, 0, b2DistanceJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultMotorJointDef, 0, 0, b2MotorJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultMouseJointDef, 0, 0, b2MouseJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultFilterJointDef, 0, 0, b2FilterJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultPrismaticJointDef, 0, 0, b2PrismaticJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultRevoluteJointDef, 0, 0, b2RevoluteJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultWeldJointDef, 0, 0, b2WeldJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultWheelJointDef, 0, 0, b2WheelJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultExplosionDef, 0, 0, b2ExplosionDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DefaultDebugDraw, 0, 0, b2DebugDraw, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2RayResult___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeId, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, normal, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fraction, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, nodeVisits, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, leafVisits, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hit, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2WorldDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, gravity, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, restitutionThreshold, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hitEventThreshold, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, contactHertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, contactDampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxContactPushSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maximumLinearSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, frictionCallback, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, restitutionCallback, Closure, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSleep, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableContinuous, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, workerCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2BodyDef___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_LONG, 0, "0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, position, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, rotation, b2Rot, 0, "new b2Rot()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, linearVelocity, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, angularVelocity, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, linearDamping, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, angularDamping, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, gravityScale, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sleepThreshold, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSleep, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isAwake, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fixedRotation, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isBullet, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isEnabled, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, allowFastRotation, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Filter___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, categoryBits, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskBits, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, groupIndex, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2QueryFilter___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, categoryBits, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskBits, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2SurfaceMaterial___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, friction, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, restitution, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rollingResistance, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, tangentSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userMaterialId, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, customColor, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ShapeDef___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, material, b2SurfaceMaterial, 0, "new b2SurfaceMaterial()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, density, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, filter, b2Filter, 0, "new b2Filter()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isSensor, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSensorEvents, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableContactEvents, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableHitEvents, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enablePreSolveEvents, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, invokeContactCreation, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, updateBodyMass, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ChainDef___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, points, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, count, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, materials, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, materialCount, IS_LONG, 0, "0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, filter, b2Filter, 0, "new b2Filter()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isLoop, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSensorEvents, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Profile___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pairs, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collide, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, solve, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mergeIslands, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prepareStages, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, solveConstraints, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prepareConstraints, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, integrateVelocities, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, warmStart, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, solveImpulses, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, integratePositions, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, relaxImpulses, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, applyRestitution, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, storeImpulses, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, splitIslands, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, transforms, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hitEvents, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, refit, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bullets, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sleepIslands, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sensors, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Counters___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bodyCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, shapeCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, contactCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, jointCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, islandCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, stackUsed, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, staticTreeHeight, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, treeHeight, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, byteCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, taskCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, colorCounts, IS_ARRAY, 0, "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2DistanceJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSpring, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableLimit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, minLength, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxLength, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableMotor, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxMotorForce, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, motorSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2MotorJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, linearOffset, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, angularOffset, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxForce, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxTorque, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, correctionFactor, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2MouseJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, target, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxForce, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2FilterJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2PrismaticJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAxisA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, referenceAngle, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, targetTranslation, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSpring, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableLimit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, lowerTranslation, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, upperTranslation, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableMotor, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxMotorForce, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, motorSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2RevoluteJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, referenceAngle, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, targetAngle, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSpring, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableLimit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, lowerAngle, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, upperAngle, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableMotor, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxMotorTorque, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, motorSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawSize, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2WeldJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, referenceAngle, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, linearHertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, angularHertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, linearDampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, angularDampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2WheelJointDef___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdA, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyIdB, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAnchorB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localAxisA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableSpring, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hertz, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dampingRatio, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableLimit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, lowerTranslation, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, upperTranslation, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, enableMotor, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxMotorTorque, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, motorSpeed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, collideConnected, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, internalValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ExplosionDef___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskBits, IS_LONG, 0, "0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, position, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, radius, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, falloff, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, impulsePerLength, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2SensorBeginTouchEvent___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, sensorShapeId, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, visitorShapeId, b2ShapeId, 0, "new b2ShapeId()")
ZEND_END_ARG_INFO()

#define arginfo_class_b2SensorEndTouchEvent___construct arginfo_class_b2SensorBeginTouchEvent___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2SensorEvents___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, beginEvents, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endEvents, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, beginCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endCount, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ContactBeginTouchEvent___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeIdA, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeIdB, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, manifold, b2Manifold, 0, "new b2Manifold()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ContactEndTouchEvent___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeIdA, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeIdB, b2ShapeId, 0, "new b2ShapeId()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ContactHitEvent___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeIdA, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, shapeIdB, b2ShapeId, 0, "new b2ShapeId()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, normal, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, approachSpeed, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ContactEvents___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, beginEvents, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endEvents, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hitEvents, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, beginCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endCount, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hitCount, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2BodyMoveEvent___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, transform, b2Transform, 0, "new b2Transform()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, bodyId, b2BodyId, 0, "new b2BodyId()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userData, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fellAsleep, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2BodyEvents___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, moveEvents, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, moveCount, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_b2ContactData___construct arginfo_class_b2ContactBeginTouchEvent___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2DebugDraw___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawPolygonFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawSolidPolygonFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawCircleFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawSolidCircleFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawSolidCapsuleFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawSegmentFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawTransformFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawPointFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, DrawStringFcn, Closure, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, drawingBounds, b2AABB, 0, "new b2AABB()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useDrawingBounds, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawShapes, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawJoints, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawJointExtras, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawBounds, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawMass, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawBodyNames, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawContacts, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawGraphColors, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawContactNormals, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawContactImpulses, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawContactFeatures, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawFrictionImpulses, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, drawIslands, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_MIXED, 0, "null")
ZEND_END_ARG_INFO()

ZEND_FUNCTION(b2DefaultWorldDef);
ZEND_FUNCTION(b2DefaultBodyDef);
ZEND_FUNCTION(b2DefaultFilter);
ZEND_FUNCTION(b2DefaultQueryFilter);
ZEND_FUNCTION(b2DefaultSurfaceMaterial);
ZEND_FUNCTION(b2DefaultShapeDef);
ZEND_FUNCTION(b2DefaultChainDef);
ZEND_FUNCTION(b2DefaultDistanceJointDef);
ZEND_FUNCTION(b2DefaultMotorJointDef);
ZEND_FUNCTION(b2DefaultMouseJointDef);
ZEND_FUNCTION(b2DefaultFilterJointDef);
ZEND_FUNCTION(b2DefaultPrismaticJointDef);
ZEND_FUNCTION(b2DefaultRevoluteJointDef);
ZEND_FUNCTION(b2DefaultWeldJointDef);
ZEND_FUNCTION(b2DefaultWheelJointDef);
ZEND_FUNCTION(b2DefaultExplosionDef);
ZEND_FUNCTION(b2DefaultDebugDraw);
ZEND_METHOD(b2RayResult, __construct);
ZEND_METHOD(b2WorldDef, __construct);
ZEND_METHOD(b2BodyDef, __construct);
ZEND_METHOD(b2Filter, __construct);
ZEND_METHOD(b2QueryFilter, __construct);
ZEND_METHOD(b2SurfaceMaterial, __construct);
ZEND_METHOD(b2ShapeDef, __construct);
ZEND_METHOD(b2ChainDef, __construct);
ZEND_METHOD(b2Profile, __construct);
ZEND_METHOD(b2Counters, __construct);
ZEND_METHOD(b2DistanceJointDef, __construct);
ZEND_METHOD(b2MotorJointDef, __construct);
ZEND_METHOD(b2MouseJointDef, __construct);
ZEND_METHOD(b2FilterJointDef, __construct);
ZEND_METHOD(b2PrismaticJointDef, __construct);
ZEND_METHOD(b2RevoluteJointDef, __construct);
ZEND_METHOD(b2WeldJointDef, __construct);
ZEND_METHOD(b2WheelJointDef, __construct);
ZEND_METHOD(b2ExplosionDef, __construct);
ZEND_METHOD(b2SensorBeginTouchEvent, __construct);
ZEND_METHOD(b2SensorEndTouchEvent, __construct);
ZEND_METHOD(b2SensorEvents, __construct);
ZEND_METHOD(b2ContactBeginTouchEvent, __construct);
ZEND_METHOD(b2ContactEndTouchEvent, __construct);
ZEND_METHOD(b2ContactHitEvent, __construct);
ZEND_METHOD(b2ContactEvents, __construct);
ZEND_METHOD(b2BodyMoveEvent, __construct);
ZEND_METHOD(b2BodyEvents, __construct);
ZEND_METHOD(b2ContactData, __construct);
ZEND_METHOD(b2DebugDraw, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(b2DefaultWorldDef, arginfo_b2DefaultWorldDef)
	ZEND_FE(b2DefaultBodyDef, arginfo_b2DefaultBodyDef)
	ZEND_FE(b2DefaultFilter, arginfo_b2DefaultFilter)
	ZEND_FE(b2DefaultQueryFilter, arginfo_b2DefaultQueryFilter)
	ZEND_FE(b2DefaultSurfaceMaterial, arginfo_b2DefaultSurfaceMaterial)
	ZEND_FE(b2DefaultShapeDef, arginfo_b2DefaultShapeDef)
	ZEND_FE(b2DefaultChainDef, arginfo_b2DefaultChainDef)
	ZEND_FE(b2DefaultDistanceJointDef, arginfo_b2DefaultDistanceJointDef)
	ZEND_FE(b2DefaultMotorJointDef, arginfo_b2DefaultMotorJointDef)
	ZEND_FE(b2DefaultMouseJointDef, arginfo_b2DefaultMouseJointDef)
	ZEND_FE(b2DefaultFilterJointDef, arginfo_b2DefaultFilterJointDef)
	ZEND_FE(b2DefaultPrismaticJointDef, arginfo_b2DefaultPrismaticJointDef)
	ZEND_FE(b2DefaultRevoluteJointDef, arginfo_b2DefaultRevoluteJointDef)
	ZEND_FE(b2DefaultWeldJointDef, arginfo_b2DefaultWeldJointDef)
	ZEND_FE(b2DefaultWheelJointDef, arginfo_b2DefaultWheelJointDef)
	ZEND_FE(b2DefaultExplosionDef, arginfo_b2DefaultExplosionDef)
	ZEND_FE(b2DefaultDebugDraw, arginfo_b2DefaultDebugDraw)
	ZEND_FE_END
};

static const zend_function_entry class_b2RayResult_methods[] = {
	ZEND_ME(b2RayResult, __construct, arginfo_class_b2RayResult___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2WorldDef_methods[] = {
	ZEND_ME(b2WorldDef, __construct, arginfo_class_b2WorldDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2BodyDef_methods[] = {
	ZEND_ME(b2BodyDef, __construct, arginfo_class_b2BodyDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Filter_methods[] = {
	ZEND_ME(b2Filter, __construct, arginfo_class_b2Filter___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2QueryFilter_methods[] = {
	ZEND_ME(b2QueryFilter, __construct, arginfo_class_b2QueryFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SurfaceMaterial_methods[] = {
	ZEND_ME(b2SurfaceMaterial, __construct, arginfo_class_b2SurfaceMaterial___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ShapeDef_methods[] = {
	ZEND_ME(b2ShapeDef, __construct, arginfo_class_b2ShapeDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ChainDef_methods[] = {
	ZEND_ME(b2ChainDef, __construct, arginfo_class_b2ChainDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Profile_methods[] = {
	ZEND_ME(b2Profile, __construct, arginfo_class_b2Profile___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Counters_methods[] = {
	ZEND_ME(b2Counters, __construct, arginfo_class_b2Counters___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2DistanceJointDef_methods[] = {
	ZEND_ME(b2DistanceJointDef, __construct, arginfo_class_b2DistanceJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2MotorJointDef_methods[] = {
	ZEND_ME(b2MotorJointDef, __construct, arginfo_class_b2MotorJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2MouseJointDef_methods[] = {
	ZEND_ME(b2MouseJointDef, __construct, arginfo_class_b2MouseJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2FilterJointDef_methods[] = {
	ZEND_ME(b2FilterJointDef, __construct, arginfo_class_b2FilterJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2PrismaticJointDef_methods[] = {
	ZEND_ME(b2PrismaticJointDef, __construct, arginfo_class_b2PrismaticJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2RevoluteJointDef_methods[] = {
	ZEND_ME(b2RevoluteJointDef, __construct, arginfo_class_b2RevoluteJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2WeldJointDef_methods[] = {
	ZEND_ME(b2WeldJointDef, __construct, arginfo_class_b2WeldJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2WheelJointDef_methods[] = {
	ZEND_ME(b2WheelJointDef, __construct, arginfo_class_b2WheelJointDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ExplosionDef_methods[] = {
	ZEND_ME(b2ExplosionDef, __construct, arginfo_class_b2ExplosionDef___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SensorBeginTouchEvent_methods[] = {
	ZEND_ME(b2SensorBeginTouchEvent, __construct, arginfo_class_b2SensorBeginTouchEvent___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SensorEndTouchEvent_methods[] = {
	ZEND_ME(b2SensorEndTouchEvent, __construct, arginfo_class_b2SensorEndTouchEvent___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SensorEvents_methods[] = {
	ZEND_ME(b2SensorEvents, __construct, arginfo_class_b2SensorEvents___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ContactBeginTouchEvent_methods[] = {
	ZEND_ME(b2ContactBeginTouchEvent, __construct, arginfo_class_b2ContactBeginTouchEvent___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ContactEndTouchEvent_methods[] = {
	ZEND_ME(b2ContactEndTouchEvent, __construct, arginfo_class_b2ContactEndTouchEvent___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ContactHitEvent_methods[] = {
	ZEND_ME(b2ContactHitEvent, __construct, arginfo_class_b2ContactHitEvent___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ContactEvents_methods[] = {
	ZEND_ME(b2ContactEvents, __construct, arginfo_class_b2ContactEvents___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2BodyMoveEvent_methods[] = {
	ZEND_ME(b2BodyMoveEvent, __construct, arginfo_class_b2BodyMoveEvent___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2BodyEvents_methods[] = {
	ZEND_ME(b2BodyEvents, __construct, arginfo_class_b2BodyEvents___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ContactData_methods[] = {
	ZEND_ME(b2ContactData, __construct, arginfo_class_b2ContactData___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2DebugDraw_methods[] = {
	ZEND_ME(b2DebugDraw, __construct, arginfo_class_b2DebugDraw___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_types_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("B2_DEFAULT_MASK_BITS", (zend_long) B2_DEFAULT_MASK_BITS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("B2_DEFAULT_CATEGORY_BITS", B2_DEFAULT_CATEGORY_BITS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_staticBody", b2_staticBody, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_kinematicBody", b2_kinematicBody, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_dynamicBody", b2_dynamicBody, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_bodyTypeCount", b2_bodyTypeCount, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_circleShape", b2_circleShape, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_capsuleShape", b2_capsuleShape, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_segmentShape", b2_segmentShape, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_polygonShape", b2_polygonShape, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_chainSegmentShape", b2_chainSegmentShape, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_shapeTypeCount", b2_shapeTypeCount, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_distanceJoint", b2_distanceJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_filterJoint", b2_filterJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_motorJoint", b2_motorJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_mouseJoint", b2_mouseJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_prismaticJoint", b2_prismaticJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_revoluteJoint", b2_revoluteJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_weldJoint", b2_weldJoint, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_wheelJoint", b2_wheelJoint, CONST_PERSISTENT);
}

static zend_class_entry *register_class_b2RayResult(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2RayResult", class_b2RayResult_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_shapeId_default_value;
	ZVAL_UNDEF(&property_shapeId_default_value);
	zend_string *property_shapeId_name = zend_string_init("shapeId", sizeof("shapeId") - 1, 1);
	zend_string *property_shapeId_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeId_name, &property_shapeId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeId_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeId_name);

	zval property_point_default_value;
	ZVAL_UNDEF(&property_point_default_value);
	zend_string *property_point_name = zend_string_init("point", sizeof("point") - 1, 1);
	zend_string *property_point_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point_name, &property_point_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point_class_b2Vec2, 0, 0));
	zend_string_release(property_point_name);

	zval property_normal_default_value;
	ZVAL_UNDEF(&property_normal_default_value);
	zend_string *property_normal_name = zend_string_init("normal", sizeof("normal") - 1, 1);
	zend_string *property_normal_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_normal_name, &property_normal_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_normal_class_b2Vec2, 0, 0));
	zend_string_release(property_normal_name);

	zval property_fraction_default_value;
	ZVAL_DOUBLE(&property_fraction_default_value, 0.0);
	zend_string *property_fraction_name = zend_string_init("fraction", sizeof("fraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_fraction_name, &property_fraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_fraction_name);

	zval property_nodeVisits_default_value;
	ZVAL_LONG(&property_nodeVisits_default_value, 0);
	zend_string *property_nodeVisits_name = zend_string_init("nodeVisits", sizeof("nodeVisits") - 1, 1);
	zend_declare_typed_property(class_entry, property_nodeVisits_name, &property_nodeVisits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_nodeVisits_name);

	zval property_leafVisits_default_value;
	ZVAL_LONG(&property_leafVisits_default_value, 0);
	zend_string *property_leafVisits_name = zend_string_init("leafVisits", sizeof("leafVisits") - 1, 1);
	zend_declare_typed_property(class_entry, property_leafVisits_name, &property_leafVisits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_leafVisits_name);

	zval property_hit_default_value;
	ZVAL_FALSE(&property_hit_default_value);
	zend_string *property_hit_name = zend_string_init("hit", sizeof("hit") - 1, 1);
	zend_declare_typed_property(class_entry, property_hit_name, &property_hit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_hit_name);

	return class_entry;
}

static zend_class_entry *register_class_b2WorldDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2WorldDef", class_b2WorldDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_gravity_default_value;
	ZVAL_UNDEF(&property_gravity_default_value);
	zend_string *property_gravity_name = zend_string_init("gravity", sizeof("gravity") - 1, 1);
	zend_string *property_gravity_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_gravity_name, &property_gravity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_gravity_class_b2Vec2, 0, 0));
	zend_string_release(property_gravity_name);

	zval property_restitutionThreshold_default_value;
	ZVAL_DOUBLE(&property_restitutionThreshold_default_value, 0.0);
	zend_string *property_restitutionThreshold_name = zend_string_init("restitutionThreshold", sizeof("restitutionThreshold") - 1, 1);
	zend_declare_typed_property(class_entry, property_restitutionThreshold_name, &property_restitutionThreshold_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_restitutionThreshold_name);

	zval property_hitEventThreshold_default_value;
	ZVAL_DOUBLE(&property_hitEventThreshold_default_value, 0.0);
	zend_string *property_hitEventThreshold_name = zend_string_init("hitEventThreshold", sizeof("hitEventThreshold") - 1, 1);
	zend_declare_typed_property(class_entry, property_hitEventThreshold_name, &property_hitEventThreshold_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hitEventThreshold_name);

	zval property_contactHertz_default_value;
	ZVAL_DOUBLE(&property_contactHertz_default_value, 0.0);
	zend_string *property_contactHertz_name = zend_string_init("contactHertz", sizeof("contactHertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_contactHertz_name, &property_contactHertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_contactHertz_name);

	zval property_contactDampingRatio_default_value;
	ZVAL_DOUBLE(&property_contactDampingRatio_default_value, 0.0);
	zend_string *property_contactDampingRatio_name = zend_string_init("contactDampingRatio", sizeof("contactDampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_contactDampingRatio_name, &property_contactDampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_contactDampingRatio_name);

	zval property_maxContactPushSpeed_default_value;
	ZVAL_DOUBLE(&property_maxContactPushSpeed_default_value, 0.0);
	zend_string *property_maxContactPushSpeed_name = zend_string_init("maxContactPushSpeed", sizeof("maxContactPushSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxContactPushSpeed_name, &property_maxContactPushSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxContactPushSpeed_name);

	zval property_maximumLinearSpeed_default_value;
	ZVAL_DOUBLE(&property_maximumLinearSpeed_default_value, 0.0);
	zend_string *property_maximumLinearSpeed_name = zend_string_init("maximumLinearSpeed", sizeof("maximumLinearSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_maximumLinearSpeed_name, &property_maximumLinearSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maximumLinearSpeed_name);

	zval property_frictionCallback_default_value;
	ZVAL_NULL(&property_frictionCallback_default_value);
	zend_string *property_frictionCallback_name = zend_string_init("frictionCallback", sizeof("frictionCallback") - 1, 1);
	zend_string *property_frictionCallback_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_frictionCallback_name, &property_frictionCallback_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_frictionCallback_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_frictionCallback_name);

	zval property_restitutionCallback_default_value;
	ZVAL_NULL(&property_restitutionCallback_default_value);
	zend_string *property_restitutionCallback_name = zend_string_init("restitutionCallback", sizeof("restitutionCallback") - 1, 1);
	zend_string *property_restitutionCallback_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_restitutionCallback_name, &property_restitutionCallback_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_restitutionCallback_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_restitutionCallback_name);

	zval property_enableSleep_default_value;
	ZVAL_FALSE(&property_enableSleep_default_value);
	zend_string *property_enableSleep_name = zend_string_init("enableSleep", sizeof("enableSleep") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSleep_name, &property_enableSleep_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSleep_name);

	zval property_enableContinuous_default_value;
	ZVAL_FALSE(&property_enableContinuous_default_value);
	zend_string *property_enableContinuous_name = zend_string_init("enableContinuous", sizeof("enableContinuous") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableContinuous_name, &property_enableContinuous_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableContinuous_name);

	zval property_workerCount_default_value;
	ZVAL_LONG(&property_workerCount_default_value, 0);
	zend_string *property_workerCount_name = zend_string_init("workerCount", sizeof("workerCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_workerCount_name, &property_workerCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_workerCount_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2BodyDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2BodyDef", class_b2BodyDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_type_default_value;
	ZVAL_LONG(&property_type_default_value, 0);
	zend_string *property_type_name = zend_string_init("type", sizeof("type") - 1, 1);
	zend_declare_typed_property(class_entry, property_type_name, &property_type_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_type_name);

	zval property_position_default_value;
	ZVAL_UNDEF(&property_position_default_value);
	zend_string *property_position_name = zend_string_init("position", sizeof("position") - 1, 1);
	zend_string *property_position_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_position_name, &property_position_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_position_class_b2Vec2, 0, 0));
	zend_string_release(property_position_name);

	zval property_rotation_default_value;
	ZVAL_UNDEF(&property_rotation_default_value);
	zend_string *property_rotation_name = zend_string_init("rotation", sizeof("rotation") - 1, 1);
	zend_string *property_rotation_class_b2Rot = zend_string_init("b2Rot", sizeof("b2Rot")-1, 1);
	zend_declare_typed_property(class_entry, property_rotation_name, &property_rotation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_rotation_class_b2Rot, 0, 0));
	zend_string_release(property_rotation_name);

	zval property_linearVelocity_default_value;
	ZVAL_UNDEF(&property_linearVelocity_default_value);
	zend_string *property_linearVelocity_name = zend_string_init("linearVelocity", sizeof("linearVelocity") - 1, 1);
	zend_string *property_linearVelocity_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_linearVelocity_name, &property_linearVelocity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_linearVelocity_class_b2Vec2, 0, 0));
	zend_string_release(property_linearVelocity_name);

	zval property_angularVelocity_default_value;
	ZVAL_DOUBLE(&property_angularVelocity_default_value, 0.0);
	zend_string *property_angularVelocity_name = zend_string_init("angularVelocity", sizeof("angularVelocity") - 1, 1);
	zend_declare_typed_property(class_entry, property_angularVelocity_name, &property_angularVelocity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_angularVelocity_name);

	zval property_linearDamping_default_value;
	ZVAL_DOUBLE(&property_linearDamping_default_value, 0.0);
	zend_string *property_linearDamping_name = zend_string_init("linearDamping", sizeof("linearDamping") - 1, 1);
	zend_declare_typed_property(class_entry, property_linearDamping_name, &property_linearDamping_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_linearDamping_name);

	zval property_angularDamping_default_value;
	ZVAL_DOUBLE(&property_angularDamping_default_value, 0.0);
	zend_string *property_angularDamping_name = zend_string_init("angularDamping", sizeof("angularDamping") - 1, 1);
	zend_declare_typed_property(class_entry, property_angularDamping_name, &property_angularDamping_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_angularDamping_name);

	zval property_gravityScale_default_value;
	ZVAL_DOUBLE(&property_gravityScale_default_value, 0.0);
	zend_string *property_gravityScale_name = zend_string_init("gravityScale", sizeof("gravityScale") - 1, 1);
	zend_declare_typed_property(class_entry, property_gravityScale_name, &property_gravityScale_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_gravityScale_name);

	zval property_sleepThreshold_default_value;
	ZVAL_DOUBLE(&property_sleepThreshold_default_value, 0.0);
	zend_string *property_sleepThreshold_name = zend_string_init("sleepThreshold", sizeof("sleepThreshold") - 1, 1);
	zend_declare_typed_property(class_entry, property_sleepThreshold_name, &property_sleepThreshold_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_sleepThreshold_name);

	zval property_name_default_value;
	ZVAL_NULL(&property_name_default_value);
	zend_string *property_name_name = zend_string_init("name", sizeof("name") - 1, 1);
	zend_declare_typed_property(class_entry, property_name_name, &property_name_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_name_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_enableSleep_default_value;
	ZVAL_FALSE(&property_enableSleep_default_value);
	zend_string *property_enableSleep_name = zend_string_init("enableSleep", sizeof("enableSleep") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSleep_name, &property_enableSleep_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSleep_name);

	zval property_isAwake_default_value;
	ZVAL_FALSE(&property_isAwake_default_value);
	zend_string *property_isAwake_name = zend_string_init("isAwake", sizeof("isAwake") - 1, 1);
	zend_declare_typed_property(class_entry, property_isAwake_name, &property_isAwake_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_isAwake_name);

	zval property_fixedRotation_default_value;
	ZVAL_FALSE(&property_fixedRotation_default_value);
	zend_string *property_fixedRotation_name = zend_string_init("fixedRotation", sizeof("fixedRotation") - 1, 1);
	zend_declare_typed_property(class_entry, property_fixedRotation_name, &property_fixedRotation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_fixedRotation_name);

	zval property_isBullet_default_value;
	ZVAL_FALSE(&property_isBullet_default_value);
	zend_string *property_isBullet_name = zend_string_init("isBullet", sizeof("isBullet") - 1, 1);
	zend_declare_typed_property(class_entry, property_isBullet_name, &property_isBullet_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_isBullet_name);

	zval property_isEnabled_default_value;
	ZVAL_FALSE(&property_isEnabled_default_value);
	zend_string *property_isEnabled_name = zend_string_init("isEnabled", sizeof("isEnabled") - 1, 1);
	zend_declare_typed_property(class_entry, property_isEnabled_name, &property_isEnabled_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_isEnabled_name);

	zval property_allowFastRotation_default_value;
	ZVAL_FALSE(&property_allowFastRotation_default_value);
	zend_string *property_allowFastRotation_name = zend_string_init("allowFastRotation", sizeof("allowFastRotation") - 1, 1);
	zend_declare_typed_property(class_entry, property_allowFastRotation_name, &property_allowFastRotation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_allowFastRotation_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Filter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Filter", class_b2Filter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_categoryBits_default_value;
	ZVAL_LONG(&property_categoryBits_default_value, 0);
	zend_string *property_categoryBits_name = zend_string_init("categoryBits", sizeof("categoryBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_categoryBits_name, &property_categoryBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_categoryBits_name);

	zval property_maskBits_default_value;
	ZVAL_LONG(&property_maskBits_default_value, 0);
	zend_string *property_maskBits_name = zend_string_init("maskBits", sizeof("maskBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_maskBits_name, &property_maskBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maskBits_name);

	zval property_groupIndex_default_value;
	ZVAL_LONG(&property_groupIndex_default_value, 0);
	zend_string *property_groupIndex_name = zend_string_init("groupIndex", sizeof("groupIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_groupIndex_name, &property_groupIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_groupIndex_name);

	return class_entry;
}

static zend_class_entry *register_class_b2QueryFilter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2QueryFilter", class_b2QueryFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_categoryBits_default_value;
	ZVAL_LONG(&property_categoryBits_default_value, 0);
	zend_string *property_categoryBits_name = zend_string_init("categoryBits", sizeof("categoryBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_categoryBits_name, &property_categoryBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_categoryBits_name);

	zval property_maskBits_default_value;
	ZVAL_LONG(&property_maskBits_default_value, 0);
	zend_string *property_maskBits_name = zend_string_init("maskBits", sizeof("maskBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_maskBits_name, &property_maskBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maskBits_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SurfaceMaterial(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SurfaceMaterial", class_b2SurfaceMaterial_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_friction_default_value;
	ZVAL_DOUBLE(&property_friction_default_value, 0.0);
	zend_string *property_friction_name = zend_string_init("friction", sizeof("friction") - 1, 1);
	zend_declare_typed_property(class_entry, property_friction_name, &property_friction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_friction_name);

	zval property_restitution_default_value;
	ZVAL_DOUBLE(&property_restitution_default_value, 0.0);
	zend_string *property_restitution_name = zend_string_init("restitution", sizeof("restitution") - 1, 1);
	zend_declare_typed_property(class_entry, property_restitution_name, &property_restitution_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_restitution_name);

	zval property_rollingResistance_default_value;
	ZVAL_DOUBLE(&property_rollingResistance_default_value, 0.0);
	zend_string *property_rollingResistance_name = zend_string_init("rollingResistance", sizeof("rollingResistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_rollingResistance_name, &property_rollingResistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_rollingResistance_name);

	zval property_tangentSpeed_default_value;
	ZVAL_DOUBLE(&property_tangentSpeed_default_value, 0.0);
	zend_string *property_tangentSpeed_name = zend_string_init("tangentSpeed", sizeof("tangentSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_tangentSpeed_name, &property_tangentSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_tangentSpeed_name);

	zval property_userMaterialId_default_value;
	ZVAL_LONG(&property_userMaterialId_default_value, 0);
	zend_string *property_userMaterialId_name = zend_string_init("userMaterialId", sizeof("userMaterialId") - 1, 1);
	zend_declare_typed_property(class_entry, property_userMaterialId_name, &property_userMaterialId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userMaterialId_name);

	zval property_customColor_default_value;
	ZVAL_LONG(&property_customColor_default_value, 0);
	zend_string *property_customColor_name = zend_string_init("customColor", sizeof("customColor") - 1, 1);
	zend_declare_typed_property(class_entry, property_customColor_name, &property_customColor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_customColor_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ShapeDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ShapeDef", class_b2ShapeDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_material_default_value;
	ZVAL_UNDEF(&property_material_default_value);
	zend_string *property_material_name = zend_string_init("material", sizeof("material") - 1, 1);
	zend_string *property_material_class_b2SurfaceMaterial = zend_string_init("b2SurfaceMaterial", sizeof("b2SurfaceMaterial")-1, 1);
	zend_declare_typed_property(class_entry, property_material_name, &property_material_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_material_class_b2SurfaceMaterial, 0, 0));
	zend_string_release(property_material_name);

	zval property_density_default_value;
	ZVAL_DOUBLE(&property_density_default_value, 0.0);
	zend_string *property_density_name = zend_string_init("density", sizeof("density") - 1, 1);
	zend_declare_typed_property(class_entry, property_density_name, &property_density_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_density_name);

	zval property_filter_default_value;
	ZVAL_UNDEF(&property_filter_default_value);
	zend_string *property_filter_name = zend_string_init("filter", sizeof("filter") - 1, 1);
	zend_string *property_filter_class_b2Filter = zend_string_init("b2Filter", sizeof("b2Filter")-1, 1);
	zend_declare_typed_property(class_entry, property_filter_name, &property_filter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_filter_class_b2Filter, 0, 0));
	zend_string_release(property_filter_name);

	zval property_isSensor_default_value;
	ZVAL_FALSE(&property_isSensor_default_value);
	zend_string *property_isSensor_name = zend_string_init("isSensor", sizeof("isSensor") - 1, 1);
	zend_declare_typed_property(class_entry, property_isSensor_name, &property_isSensor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_isSensor_name);

	zval property_enableSensorEvents_default_value;
	ZVAL_FALSE(&property_enableSensorEvents_default_value);
	zend_string *property_enableSensorEvents_name = zend_string_init("enableSensorEvents", sizeof("enableSensorEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSensorEvents_name, &property_enableSensorEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSensorEvents_name);

	zval property_enableContactEvents_default_value;
	ZVAL_FALSE(&property_enableContactEvents_default_value);
	zend_string *property_enableContactEvents_name = zend_string_init("enableContactEvents", sizeof("enableContactEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableContactEvents_name, &property_enableContactEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableContactEvents_name);

	zval property_enableHitEvents_default_value;
	ZVAL_FALSE(&property_enableHitEvents_default_value);
	zend_string *property_enableHitEvents_name = zend_string_init("enableHitEvents", sizeof("enableHitEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableHitEvents_name, &property_enableHitEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableHitEvents_name);

	zval property_enablePreSolveEvents_default_value;
	ZVAL_FALSE(&property_enablePreSolveEvents_default_value);
	zend_string *property_enablePreSolveEvents_name = zend_string_init("enablePreSolveEvents", sizeof("enablePreSolveEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_enablePreSolveEvents_name, &property_enablePreSolveEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enablePreSolveEvents_name);

	zval property_invokeContactCreation_default_value;
	ZVAL_FALSE(&property_invokeContactCreation_default_value);
	zend_string *property_invokeContactCreation_name = zend_string_init("invokeContactCreation", sizeof("invokeContactCreation") - 1, 1);
	zend_declare_typed_property(class_entry, property_invokeContactCreation_name, &property_invokeContactCreation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_invokeContactCreation_name);

	zval property_updateBodyMass_default_value;
	ZVAL_FALSE(&property_updateBodyMass_default_value);
	zend_string *property_updateBodyMass_name = zend_string_init("updateBodyMass", sizeof("updateBodyMass") - 1, 1);
	zend_declare_typed_property(class_entry, property_updateBodyMass_name, &property_updateBodyMass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_updateBodyMass_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ChainDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ChainDef", class_b2ChainDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_points_default_value;
	ZVAL_EMPTY_ARRAY(&property_points_default_value);
	zend_string *property_points_name = zend_string_init("points", sizeof("points") - 1, 1);
	zend_declare_typed_property(class_entry, property_points_name, &property_points_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_points_name);

	zval property_count_default_value;
	ZVAL_LONG(&property_count_default_value, 0);
	zend_string *property_count_name = zend_string_init("count", sizeof("count") - 1, 1);
	zend_declare_typed_property(class_entry, property_count_name, &property_count_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_count_name);

	zval property_materials_default_value;
	ZVAL_EMPTY_ARRAY(&property_materials_default_value);
	zend_string *property_materials_name = zend_string_init("materials", sizeof("materials") - 1, 1);
	zend_declare_typed_property(class_entry, property_materials_name, &property_materials_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_materials_name);

	zval property_materialCount_default_value;
	ZVAL_LONG(&property_materialCount_default_value, 0);
	zend_string *property_materialCount_name = zend_string_init("materialCount", sizeof("materialCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_materialCount_name, &property_materialCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_materialCount_name);

	zval property_filter_default_value;
	ZVAL_UNDEF(&property_filter_default_value);
	zend_string *property_filter_name = zend_string_init("filter", sizeof("filter") - 1, 1);
	zend_string *property_filter_class_b2Filter = zend_string_init("b2Filter", sizeof("b2Filter")-1, 1);
	zend_declare_typed_property(class_entry, property_filter_name, &property_filter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_filter_class_b2Filter, 0, 0));
	zend_string_release(property_filter_name);

	zval property_isLoop_default_value;
	ZVAL_FALSE(&property_isLoop_default_value);
	zend_string *property_isLoop_name = zend_string_init("isLoop", sizeof("isLoop") - 1, 1);
	zend_declare_typed_property(class_entry, property_isLoop_name, &property_isLoop_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_isLoop_name);

	zval property_enableSensorEvents_default_value;
	ZVAL_FALSE(&property_enableSensorEvents_default_value);
	zend_string *property_enableSensorEvents_name = zend_string_init("enableSensorEvents", sizeof("enableSensorEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSensorEvents_name, &property_enableSensorEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSensorEvents_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Profile(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Profile", class_b2Profile_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_step_default_value;
	ZVAL_DOUBLE(&property_step_default_value, 0.0);
	zend_string *property_step_name = zend_string_init("step", sizeof("step") - 1, 1);
	zend_declare_typed_property(class_entry, property_step_name, &property_step_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_step_name);

	zval property_pairs_default_value;
	ZVAL_DOUBLE(&property_pairs_default_value, 0.0);
	zend_string *property_pairs_name = zend_string_init("pairs", sizeof("pairs") - 1, 1);
	zend_declare_typed_property(class_entry, property_pairs_name, &property_pairs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_pairs_name);

	zval property_collide_default_value;
	ZVAL_DOUBLE(&property_collide_default_value, 0.0);
	zend_string *property_collide_name = zend_string_init("collide", sizeof("collide") - 1, 1);
	zend_declare_typed_property(class_entry, property_collide_name, &property_collide_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_collide_name);

	zval property_solve_default_value;
	ZVAL_DOUBLE(&property_solve_default_value, 0.0);
	zend_string *property_solve_name = zend_string_init("solve", sizeof("solve") - 1, 1);
	zend_declare_typed_property(class_entry, property_solve_name, &property_solve_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_solve_name);

	zval property_mergeIslands_default_value;
	ZVAL_DOUBLE(&property_mergeIslands_default_value, 0.0);
	zend_string *property_mergeIslands_name = zend_string_init("mergeIslands", sizeof("mergeIslands") - 1, 1);
	zend_declare_typed_property(class_entry, property_mergeIslands_name, &property_mergeIslands_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mergeIslands_name);

	zval property_prepareStages_default_value;
	ZVAL_DOUBLE(&property_prepareStages_default_value, 0.0);
	zend_string *property_prepareStages_name = zend_string_init("prepareStages", sizeof("prepareStages") - 1, 1);
	zend_declare_typed_property(class_entry, property_prepareStages_name, &property_prepareStages_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_prepareStages_name);

	zval property_solveConstraints_default_value;
	ZVAL_DOUBLE(&property_solveConstraints_default_value, 0.0);
	zend_string *property_solveConstraints_name = zend_string_init("solveConstraints", sizeof("solveConstraints") - 1, 1);
	zend_declare_typed_property(class_entry, property_solveConstraints_name, &property_solveConstraints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_solveConstraints_name);

	zval property_prepareConstraints_default_value;
	ZVAL_DOUBLE(&property_prepareConstraints_default_value, 0.0);
	zend_string *property_prepareConstraints_name = zend_string_init("prepareConstraints", sizeof("prepareConstraints") - 1, 1);
	zend_declare_typed_property(class_entry, property_prepareConstraints_name, &property_prepareConstraints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_prepareConstraints_name);

	zval property_integrateVelocities_default_value;
	ZVAL_DOUBLE(&property_integrateVelocities_default_value, 0.0);
	zend_string *property_integrateVelocities_name = zend_string_init("integrateVelocities", sizeof("integrateVelocities") - 1, 1);
	zend_declare_typed_property(class_entry, property_integrateVelocities_name, &property_integrateVelocities_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_integrateVelocities_name);

	zval property_warmStart_default_value;
	ZVAL_DOUBLE(&property_warmStart_default_value, 0.0);
	zend_string *property_warmStart_name = zend_string_init("warmStart", sizeof("warmStart") - 1, 1);
	zend_declare_typed_property(class_entry, property_warmStart_name, &property_warmStart_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_warmStart_name);

	zval property_solveImpulses_default_value;
	ZVAL_DOUBLE(&property_solveImpulses_default_value, 0.0);
	zend_string *property_solveImpulses_name = zend_string_init("solveImpulses", sizeof("solveImpulses") - 1, 1);
	zend_declare_typed_property(class_entry, property_solveImpulses_name, &property_solveImpulses_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_solveImpulses_name);

	zval property_integratePositions_default_value;
	ZVAL_DOUBLE(&property_integratePositions_default_value, 0.0);
	zend_string *property_integratePositions_name = zend_string_init("integratePositions", sizeof("integratePositions") - 1, 1);
	zend_declare_typed_property(class_entry, property_integratePositions_name, &property_integratePositions_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_integratePositions_name);

	zval property_relaxImpulses_default_value;
	ZVAL_DOUBLE(&property_relaxImpulses_default_value, 0.0);
	zend_string *property_relaxImpulses_name = zend_string_init("relaxImpulses", sizeof("relaxImpulses") - 1, 1);
	zend_declare_typed_property(class_entry, property_relaxImpulses_name, &property_relaxImpulses_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_relaxImpulses_name);

	zval property_applyRestitution_default_value;
	ZVAL_DOUBLE(&property_applyRestitution_default_value, 0.0);
	zend_string *property_applyRestitution_name = zend_string_init("applyRestitution", sizeof("applyRestitution") - 1, 1);
	zend_declare_typed_property(class_entry, property_applyRestitution_name, &property_applyRestitution_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_applyRestitution_name);

	zval property_storeImpulses_default_value;
	ZVAL_DOUBLE(&property_storeImpulses_default_value, 0.0);
	zend_string *property_storeImpulses_name = zend_string_init("storeImpulses", sizeof("storeImpulses") - 1, 1);
	zend_declare_typed_property(class_entry, property_storeImpulses_name, &property_storeImpulses_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_storeImpulses_name);

	zval property_splitIslands_default_value;
	ZVAL_DOUBLE(&property_splitIslands_default_value, 0.0);
	zend_string *property_splitIslands_name = zend_string_init("splitIslands", sizeof("splitIslands") - 1, 1);
	zend_declare_typed_property(class_entry, property_splitIslands_name, &property_splitIslands_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_splitIslands_name);

	zval property_transforms_default_value;
	ZVAL_DOUBLE(&property_transforms_default_value, 0.0);
	zend_string *property_transforms_name = zend_string_init("transforms", sizeof("transforms") - 1, 1);
	zend_declare_typed_property(class_entry, property_transforms_name, &property_transforms_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_transforms_name);

	zval property_hitEvents_default_value;
	ZVAL_DOUBLE(&property_hitEvents_default_value, 0.0);
	zend_string *property_hitEvents_name = zend_string_init("hitEvents", sizeof("hitEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_hitEvents_name, &property_hitEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hitEvents_name);

	zval property_refit_default_value;
	ZVAL_DOUBLE(&property_refit_default_value, 0.0);
	zend_string *property_refit_name = zend_string_init("refit", sizeof("refit") - 1, 1);
	zend_declare_typed_property(class_entry, property_refit_name, &property_refit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_refit_name);

	zval property_bullets_default_value;
	ZVAL_DOUBLE(&property_bullets_default_value, 0.0);
	zend_string *property_bullets_name = zend_string_init("bullets", sizeof("bullets") - 1, 1);
	zend_declare_typed_property(class_entry, property_bullets_name, &property_bullets_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_bullets_name);

	zval property_sleepIslands_default_value;
	ZVAL_DOUBLE(&property_sleepIslands_default_value, 0.0);
	zend_string *property_sleepIslands_name = zend_string_init("sleepIslands", sizeof("sleepIslands") - 1, 1);
	zend_declare_typed_property(class_entry, property_sleepIslands_name, &property_sleepIslands_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_sleepIslands_name);

	zval property_sensors_default_value;
	ZVAL_DOUBLE(&property_sensors_default_value, 0.0);
	zend_string *property_sensors_name = zend_string_init("sensors", sizeof("sensors") - 1, 1);
	zend_declare_typed_property(class_entry, property_sensors_name, &property_sensors_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_sensors_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Counters(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Counters", class_b2Counters_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyCount_default_value;
	ZVAL_LONG(&property_bodyCount_default_value, 0);
	zend_string *property_bodyCount_name = zend_string_init("bodyCount", sizeof("bodyCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_bodyCount_name, &property_bodyCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bodyCount_name);

	zval property_shapeCount_default_value;
	ZVAL_LONG(&property_shapeCount_default_value, 0);
	zend_string *property_shapeCount_name = zend_string_init("shapeCount", sizeof("shapeCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_shapeCount_name, &property_shapeCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_shapeCount_name);

	zval property_contactCount_default_value;
	ZVAL_LONG(&property_contactCount_default_value, 0);
	zend_string *property_contactCount_name = zend_string_init("contactCount", sizeof("contactCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_contactCount_name, &property_contactCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_contactCount_name);

	zval property_jointCount_default_value;
	ZVAL_LONG(&property_jointCount_default_value, 0);
	zend_string *property_jointCount_name = zend_string_init("jointCount", sizeof("jointCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_jointCount_name, &property_jointCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_jointCount_name);

	zval property_islandCount_default_value;
	ZVAL_LONG(&property_islandCount_default_value, 0);
	zend_string *property_islandCount_name = zend_string_init("islandCount", sizeof("islandCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_islandCount_name, &property_islandCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_islandCount_name);

	zval property_stackUsed_default_value;
	ZVAL_LONG(&property_stackUsed_default_value, 0);
	zend_string *property_stackUsed_name = zend_string_init("stackUsed", sizeof("stackUsed") - 1, 1);
	zend_declare_typed_property(class_entry, property_stackUsed_name, &property_stackUsed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stackUsed_name);

	zval property_staticTreeHeight_default_value;
	ZVAL_LONG(&property_staticTreeHeight_default_value, 0);
	zend_string *property_staticTreeHeight_name = zend_string_init("staticTreeHeight", sizeof("staticTreeHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_staticTreeHeight_name, &property_staticTreeHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_staticTreeHeight_name);

	zval property_treeHeight_default_value;
	ZVAL_LONG(&property_treeHeight_default_value, 0);
	zend_string *property_treeHeight_name = zend_string_init("treeHeight", sizeof("treeHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_treeHeight_name, &property_treeHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_treeHeight_name);

	zval property_byteCount_default_value;
	ZVAL_LONG(&property_byteCount_default_value, 0);
	zend_string *property_byteCount_name = zend_string_init("byteCount", sizeof("byteCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_byteCount_name, &property_byteCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_byteCount_name);

	zval property_taskCount_default_value;
	ZVAL_LONG(&property_taskCount_default_value, 0);
	zend_string *property_taskCount_name = zend_string_init("taskCount", sizeof("taskCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_taskCount_name, &property_taskCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_taskCount_name);

	zval property_colorCounts_default_value;
	ZVAL_EMPTY_ARRAY(&property_colorCounts_default_value);
	zend_string *property_colorCounts_name = zend_string_init("colorCounts", sizeof("colorCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_colorCounts_name, &property_colorCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_colorCounts_name);

	return class_entry;
}

static zend_class_entry *register_class_b2DistanceJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2DistanceJointDef", class_b2DistanceJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_localAnchorA_default_value;
	ZVAL_UNDEF(&property_localAnchorA_default_value);
	zend_string *property_localAnchorA_name = zend_string_init("localAnchorA", sizeof("localAnchorA") - 1, 1);
	zend_string *property_localAnchorA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorA_name, &property_localAnchorA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorA_name);

	zval property_localAnchorB_default_value;
	ZVAL_UNDEF(&property_localAnchorB_default_value);
	zend_string *property_localAnchorB_name = zend_string_init("localAnchorB", sizeof("localAnchorB") - 1, 1);
	zend_string *property_localAnchorB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorB_name, &property_localAnchorB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorB_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorB_name);

	zval property_length_default_value;
	ZVAL_DOUBLE(&property_length_default_value, 0.0);
	zend_string *property_length_name = zend_string_init("length", sizeof("length") - 1, 1);
	zend_declare_typed_property(class_entry, property_length_name, &property_length_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_length_name);

	zval property_enableSpring_default_value;
	ZVAL_FALSE(&property_enableSpring_default_value);
	zend_string *property_enableSpring_name = zend_string_init("enableSpring", sizeof("enableSpring") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSpring_name, &property_enableSpring_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSpring_name);

	zval property_hertz_default_value;
	ZVAL_DOUBLE(&property_hertz_default_value, 0.0);
	zend_string *property_hertz_name = zend_string_init("hertz", sizeof("hertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_hertz_name, &property_hertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hertz_name);

	zval property_dampingRatio_default_value;
	ZVAL_DOUBLE(&property_dampingRatio_default_value, 0.0);
	zend_string *property_dampingRatio_name = zend_string_init("dampingRatio", sizeof("dampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_dampingRatio_name, &property_dampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_dampingRatio_name);

	zval property_enableLimit_default_value;
	ZVAL_FALSE(&property_enableLimit_default_value);
	zend_string *property_enableLimit_name = zend_string_init("enableLimit", sizeof("enableLimit") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableLimit_name, &property_enableLimit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableLimit_name);

	zval property_minLength_default_value;
	ZVAL_DOUBLE(&property_minLength_default_value, 0.0);
	zend_string *property_minLength_name = zend_string_init("minLength", sizeof("minLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_minLength_name, &property_minLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_minLength_name);

	zval property_maxLength_default_value;
	ZVAL_DOUBLE(&property_maxLength_default_value, 0.0);
	zend_string *property_maxLength_name = zend_string_init("maxLength", sizeof("maxLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxLength_name, &property_maxLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxLength_name);

	zval property_enableMotor_default_value;
	ZVAL_FALSE(&property_enableMotor_default_value);
	zend_string *property_enableMotor_name = zend_string_init("enableMotor", sizeof("enableMotor") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableMotor_name, &property_enableMotor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableMotor_name);

	zval property_maxMotorForce_default_value;
	ZVAL_DOUBLE(&property_maxMotorForce_default_value, 0.0);
	zend_string *property_maxMotorForce_name = zend_string_init("maxMotorForce", sizeof("maxMotorForce") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMotorForce_name, &property_maxMotorForce_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxMotorForce_name);

	zval property_motorSpeed_default_value;
	ZVAL_DOUBLE(&property_motorSpeed_default_value, 0.0);
	zend_string *property_motorSpeed_name = zend_string_init("motorSpeed", sizeof("motorSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_motorSpeed_name, &property_motorSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_motorSpeed_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2MotorJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2MotorJointDef", class_b2MotorJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_linearOffset_default_value;
	ZVAL_UNDEF(&property_linearOffset_default_value);
	zend_string *property_linearOffset_name = zend_string_init("linearOffset", sizeof("linearOffset") - 1, 1);
	zend_string *property_linearOffset_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_linearOffset_name, &property_linearOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_linearOffset_class_b2Vec2, 0, 0));
	zend_string_release(property_linearOffset_name);

	zval property_angularOffset_default_value;
	ZVAL_DOUBLE(&property_angularOffset_default_value, 0.0);
	zend_string *property_angularOffset_name = zend_string_init("angularOffset", sizeof("angularOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_angularOffset_name, &property_angularOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_angularOffset_name);

	zval property_maxForce_default_value;
	ZVAL_DOUBLE(&property_maxForce_default_value, 0.0);
	zend_string *property_maxForce_name = zend_string_init("maxForce", sizeof("maxForce") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxForce_name, &property_maxForce_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxForce_name);

	zval property_maxTorque_default_value;
	ZVAL_DOUBLE(&property_maxTorque_default_value, 0.0);
	zend_string *property_maxTorque_name = zend_string_init("maxTorque", sizeof("maxTorque") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTorque_name, &property_maxTorque_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxTorque_name);

	zval property_correctionFactor_default_value;
	ZVAL_DOUBLE(&property_correctionFactor_default_value, 0.0);
	zend_string *property_correctionFactor_name = zend_string_init("correctionFactor", sizeof("correctionFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_correctionFactor_name, &property_correctionFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_correctionFactor_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2MouseJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2MouseJointDef", class_b2MouseJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_target_default_value;
	ZVAL_UNDEF(&property_target_default_value);
	zend_string *property_target_name = zend_string_init("target", sizeof("target") - 1, 1);
	zend_string *property_target_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_target_name, &property_target_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_target_class_b2Vec2, 0, 0));
	zend_string_release(property_target_name);

	zval property_hertz_default_value;
	ZVAL_DOUBLE(&property_hertz_default_value, 0.0);
	zend_string *property_hertz_name = zend_string_init("hertz", sizeof("hertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_hertz_name, &property_hertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hertz_name);

	zval property_dampingRatio_default_value;
	ZVAL_DOUBLE(&property_dampingRatio_default_value, 0.0);
	zend_string *property_dampingRatio_name = zend_string_init("dampingRatio", sizeof("dampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_dampingRatio_name, &property_dampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_dampingRatio_name);

	zval property_maxForce_default_value;
	ZVAL_DOUBLE(&property_maxForce_default_value, 0.0);
	zend_string *property_maxForce_name = zend_string_init("maxForce", sizeof("maxForce") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxForce_name, &property_maxForce_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxForce_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2FilterJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2FilterJointDef", class_b2FilterJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2PrismaticJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2PrismaticJointDef", class_b2PrismaticJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_localAnchorA_default_value;
	ZVAL_UNDEF(&property_localAnchorA_default_value);
	zend_string *property_localAnchorA_name = zend_string_init("localAnchorA", sizeof("localAnchorA") - 1, 1);
	zend_string *property_localAnchorA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorA_name, &property_localAnchorA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorA_name);

	zval property_localAnchorB_default_value;
	ZVAL_UNDEF(&property_localAnchorB_default_value);
	zend_string *property_localAnchorB_name = zend_string_init("localAnchorB", sizeof("localAnchorB") - 1, 1);
	zend_string *property_localAnchorB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorB_name, &property_localAnchorB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorB_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorB_name);

	zval property_localAxisA_default_value;
	ZVAL_UNDEF(&property_localAxisA_default_value);
	zend_string *property_localAxisA_name = zend_string_init("localAxisA", sizeof("localAxisA") - 1, 1);
	zend_string *property_localAxisA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAxisA_name, &property_localAxisA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAxisA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAxisA_name);

	zval property_referenceAngle_default_value;
	ZVAL_DOUBLE(&property_referenceAngle_default_value, 0.0);
	zend_string *property_referenceAngle_name = zend_string_init("referenceAngle", sizeof("referenceAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_referenceAngle_name, &property_referenceAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_referenceAngle_name);

	zval property_targetTranslation_default_value;
	ZVAL_DOUBLE(&property_targetTranslation_default_value, 0.0);
	zend_string *property_targetTranslation_name = zend_string_init("targetTranslation", sizeof("targetTranslation") - 1, 1);
	zend_declare_typed_property(class_entry, property_targetTranslation_name, &property_targetTranslation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_targetTranslation_name);

	zval property_enableSpring_default_value;
	ZVAL_FALSE(&property_enableSpring_default_value);
	zend_string *property_enableSpring_name = zend_string_init("enableSpring", sizeof("enableSpring") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSpring_name, &property_enableSpring_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSpring_name);

	zval property_hertz_default_value;
	ZVAL_DOUBLE(&property_hertz_default_value, 0.0);
	zend_string *property_hertz_name = zend_string_init("hertz", sizeof("hertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_hertz_name, &property_hertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hertz_name);

	zval property_dampingRatio_default_value;
	ZVAL_DOUBLE(&property_dampingRatio_default_value, 0.0);
	zend_string *property_dampingRatio_name = zend_string_init("dampingRatio", sizeof("dampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_dampingRatio_name, &property_dampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_dampingRatio_name);

	zval property_enableLimit_default_value;
	ZVAL_FALSE(&property_enableLimit_default_value);
	zend_string *property_enableLimit_name = zend_string_init("enableLimit", sizeof("enableLimit") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableLimit_name, &property_enableLimit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableLimit_name);

	zval property_lowerTranslation_default_value;
	ZVAL_DOUBLE(&property_lowerTranslation_default_value, 0.0);
	zend_string *property_lowerTranslation_name = zend_string_init("lowerTranslation", sizeof("lowerTranslation") - 1, 1);
	zend_declare_typed_property(class_entry, property_lowerTranslation_name, &property_lowerTranslation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lowerTranslation_name);

	zval property_upperTranslation_default_value;
	ZVAL_DOUBLE(&property_upperTranslation_default_value, 0.0);
	zend_string *property_upperTranslation_name = zend_string_init("upperTranslation", sizeof("upperTranslation") - 1, 1);
	zend_declare_typed_property(class_entry, property_upperTranslation_name, &property_upperTranslation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_upperTranslation_name);

	zval property_enableMotor_default_value;
	ZVAL_FALSE(&property_enableMotor_default_value);
	zend_string *property_enableMotor_name = zend_string_init("enableMotor", sizeof("enableMotor") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableMotor_name, &property_enableMotor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableMotor_name);

	zval property_maxMotorForce_default_value;
	ZVAL_DOUBLE(&property_maxMotorForce_default_value, 0.0);
	zend_string *property_maxMotorForce_name = zend_string_init("maxMotorForce", sizeof("maxMotorForce") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMotorForce_name, &property_maxMotorForce_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxMotorForce_name);

	zval property_motorSpeed_default_value;
	ZVAL_DOUBLE(&property_motorSpeed_default_value, 0.0);
	zend_string *property_motorSpeed_name = zend_string_init("motorSpeed", sizeof("motorSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_motorSpeed_name, &property_motorSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_motorSpeed_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2RevoluteJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2RevoluteJointDef", class_b2RevoluteJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_localAnchorA_default_value;
	ZVAL_UNDEF(&property_localAnchorA_default_value);
	zend_string *property_localAnchorA_name = zend_string_init("localAnchorA", sizeof("localAnchorA") - 1, 1);
	zend_string *property_localAnchorA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorA_name, &property_localAnchorA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorA_name);

	zval property_localAnchorB_default_value;
	ZVAL_UNDEF(&property_localAnchorB_default_value);
	zend_string *property_localAnchorB_name = zend_string_init("localAnchorB", sizeof("localAnchorB") - 1, 1);
	zend_string *property_localAnchorB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorB_name, &property_localAnchorB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorB_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorB_name);

	zval property_referenceAngle_default_value;
	ZVAL_DOUBLE(&property_referenceAngle_default_value, 0.0);
	zend_string *property_referenceAngle_name = zend_string_init("referenceAngle", sizeof("referenceAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_referenceAngle_name, &property_referenceAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_referenceAngle_name);

	zval property_targetAngle_default_value;
	ZVAL_DOUBLE(&property_targetAngle_default_value, 0.0);
	zend_string *property_targetAngle_name = zend_string_init("targetAngle", sizeof("targetAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_targetAngle_name, &property_targetAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_targetAngle_name);

	zval property_enableSpring_default_value;
	ZVAL_FALSE(&property_enableSpring_default_value);
	zend_string *property_enableSpring_name = zend_string_init("enableSpring", sizeof("enableSpring") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSpring_name, &property_enableSpring_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSpring_name);

	zval property_hertz_default_value;
	ZVAL_DOUBLE(&property_hertz_default_value, 0.0);
	zend_string *property_hertz_name = zend_string_init("hertz", sizeof("hertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_hertz_name, &property_hertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hertz_name);

	zval property_dampingRatio_default_value;
	ZVAL_DOUBLE(&property_dampingRatio_default_value, 0.0);
	zend_string *property_dampingRatio_name = zend_string_init("dampingRatio", sizeof("dampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_dampingRatio_name, &property_dampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_dampingRatio_name);

	zval property_enableLimit_default_value;
	ZVAL_FALSE(&property_enableLimit_default_value);
	zend_string *property_enableLimit_name = zend_string_init("enableLimit", sizeof("enableLimit") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableLimit_name, &property_enableLimit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableLimit_name);

	zval property_lowerAngle_default_value;
	ZVAL_DOUBLE(&property_lowerAngle_default_value, 0.0);
	zend_string *property_lowerAngle_name = zend_string_init("lowerAngle", sizeof("lowerAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_lowerAngle_name, &property_lowerAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lowerAngle_name);

	zval property_upperAngle_default_value;
	ZVAL_DOUBLE(&property_upperAngle_default_value, 0.0);
	zend_string *property_upperAngle_name = zend_string_init("upperAngle", sizeof("upperAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_upperAngle_name, &property_upperAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_upperAngle_name);

	zval property_enableMotor_default_value;
	ZVAL_FALSE(&property_enableMotor_default_value);
	zend_string *property_enableMotor_name = zend_string_init("enableMotor", sizeof("enableMotor") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableMotor_name, &property_enableMotor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableMotor_name);

	zval property_maxMotorTorque_default_value;
	ZVAL_DOUBLE(&property_maxMotorTorque_default_value, 0.0);
	zend_string *property_maxMotorTorque_name = zend_string_init("maxMotorTorque", sizeof("maxMotorTorque") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMotorTorque_name, &property_maxMotorTorque_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxMotorTorque_name);

	zval property_motorSpeed_default_value;
	ZVAL_DOUBLE(&property_motorSpeed_default_value, 0.0);
	zend_string *property_motorSpeed_name = zend_string_init("motorSpeed", sizeof("motorSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_motorSpeed_name, &property_motorSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_motorSpeed_name);

	zval property_drawSize_default_value;
	ZVAL_DOUBLE(&property_drawSize_default_value, 0.0);
	zend_string *property_drawSize_name = zend_string_init("drawSize", sizeof("drawSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawSize_name, &property_drawSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_drawSize_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2WeldJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2WeldJointDef", class_b2WeldJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_localAnchorA_default_value;
	ZVAL_UNDEF(&property_localAnchorA_default_value);
	zend_string *property_localAnchorA_name = zend_string_init("localAnchorA", sizeof("localAnchorA") - 1, 1);
	zend_string *property_localAnchorA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorA_name, &property_localAnchorA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorA_name);

	zval property_localAnchorB_default_value;
	ZVAL_UNDEF(&property_localAnchorB_default_value);
	zend_string *property_localAnchorB_name = zend_string_init("localAnchorB", sizeof("localAnchorB") - 1, 1);
	zend_string *property_localAnchorB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorB_name, &property_localAnchorB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorB_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorB_name);

	zval property_referenceAngle_default_value;
	ZVAL_DOUBLE(&property_referenceAngle_default_value, 0.0);
	zend_string *property_referenceAngle_name = zend_string_init("referenceAngle", sizeof("referenceAngle") - 1, 1);
	zend_declare_typed_property(class_entry, property_referenceAngle_name, &property_referenceAngle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_referenceAngle_name);

	zval property_linearHertz_default_value;
	ZVAL_DOUBLE(&property_linearHertz_default_value, 0.0);
	zend_string *property_linearHertz_name = zend_string_init("linearHertz", sizeof("linearHertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_linearHertz_name, &property_linearHertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_linearHertz_name);

	zval property_angularHertz_default_value;
	ZVAL_DOUBLE(&property_angularHertz_default_value, 0.0);
	zend_string *property_angularHertz_name = zend_string_init("angularHertz", sizeof("angularHertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_angularHertz_name, &property_angularHertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_angularHertz_name);

	zval property_linearDampingRatio_default_value;
	ZVAL_DOUBLE(&property_linearDampingRatio_default_value, 0.0);
	zend_string *property_linearDampingRatio_name = zend_string_init("linearDampingRatio", sizeof("linearDampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_linearDampingRatio_name, &property_linearDampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_linearDampingRatio_name);

	zval property_angularDampingRatio_default_value;
	ZVAL_DOUBLE(&property_angularDampingRatio_default_value, 0.0);
	zend_string *property_angularDampingRatio_name = zend_string_init("angularDampingRatio", sizeof("angularDampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_angularDampingRatio_name, &property_angularDampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_angularDampingRatio_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2WheelJointDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2WheelJointDef", class_b2WheelJointDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_bodyIdA_default_value;
	ZVAL_UNDEF(&property_bodyIdA_default_value);
	zend_string *property_bodyIdA_name = zend_string_init("bodyIdA", sizeof("bodyIdA") - 1, 1);
	zend_string *property_bodyIdA_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdA_name, &property_bodyIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdA_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdA_name);

	zval property_bodyIdB_default_value;
	ZVAL_UNDEF(&property_bodyIdB_default_value);
	zend_string *property_bodyIdB_name = zend_string_init("bodyIdB", sizeof("bodyIdB") - 1, 1);
	zend_string *property_bodyIdB_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyIdB_name, &property_bodyIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyIdB_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyIdB_name);

	zval property_localAnchorA_default_value;
	ZVAL_UNDEF(&property_localAnchorA_default_value);
	zend_string *property_localAnchorA_name = zend_string_init("localAnchorA", sizeof("localAnchorA") - 1, 1);
	zend_string *property_localAnchorA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorA_name, &property_localAnchorA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorA_name);

	zval property_localAnchorB_default_value;
	ZVAL_UNDEF(&property_localAnchorB_default_value);
	zend_string *property_localAnchorB_name = zend_string_init("localAnchorB", sizeof("localAnchorB") - 1, 1);
	zend_string *property_localAnchorB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAnchorB_name, &property_localAnchorB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAnchorB_class_b2Vec2, 0, 0));
	zend_string_release(property_localAnchorB_name);

	zval property_localAxisA_default_value;
	ZVAL_UNDEF(&property_localAxisA_default_value);
	zend_string *property_localAxisA_name = zend_string_init("localAxisA", sizeof("localAxisA") - 1, 1);
	zend_string *property_localAxisA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localAxisA_name, &property_localAxisA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localAxisA_class_b2Vec2, 0, 0));
	zend_string_release(property_localAxisA_name);

	zval property_enableSpring_default_value;
	ZVAL_FALSE(&property_enableSpring_default_value);
	zend_string *property_enableSpring_name = zend_string_init("enableSpring", sizeof("enableSpring") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableSpring_name, &property_enableSpring_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableSpring_name);

	zval property_hertz_default_value;
	ZVAL_DOUBLE(&property_hertz_default_value, 0.0);
	zend_string *property_hertz_name = zend_string_init("hertz", sizeof("hertz") - 1, 1);
	zend_declare_typed_property(class_entry, property_hertz_name, &property_hertz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_hertz_name);

	zval property_dampingRatio_default_value;
	ZVAL_DOUBLE(&property_dampingRatio_default_value, 0.0);
	zend_string *property_dampingRatio_name = zend_string_init("dampingRatio", sizeof("dampingRatio") - 1, 1);
	zend_declare_typed_property(class_entry, property_dampingRatio_name, &property_dampingRatio_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_dampingRatio_name);

	zval property_enableLimit_default_value;
	ZVAL_FALSE(&property_enableLimit_default_value);
	zend_string *property_enableLimit_name = zend_string_init("enableLimit", sizeof("enableLimit") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableLimit_name, &property_enableLimit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableLimit_name);

	zval property_lowerTranslation_default_value;
	ZVAL_DOUBLE(&property_lowerTranslation_default_value, 0.0);
	zend_string *property_lowerTranslation_name = zend_string_init("lowerTranslation", sizeof("lowerTranslation") - 1, 1);
	zend_declare_typed_property(class_entry, property_lowerTranslation_name, &property_lowerTranslation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lowerTranslation_name);

	zval property_upperTranslation_default_value;
	ZVAL_DOUBLE(&property_upperTranslation_default_value, 0.0);
	zend_string *property_upperTranslation_name = zend_string_init("upperTranslation", sizeof("upperTranslation") - 1, 1);
	zend_declare_typed_property(class_entry, property_upperTranslation_name, &property_upperTranslation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_upperTranslation_name);

	zval property_enableMotor_default_value;
	ZVAL_FALSE(&property_enableMotor_default_value);
	zend_string *property_enableMotor_name = zend_string_init("enableMotor", sizeof("enableMotor") - 1, 1);
	zend_declare_typed_property(class_entry, property_enableMotor_name, &property_enableMotor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_enableMotor_name);

	zval property_maxMotorTorque_default_value;
	ZVAL_DOUBLE(&property_maxMotorTorque_default_value, 0.0);
	zend_string *property_maxMotorTorque_name = zend_string_init("maxMotorTorque", sizeof("maxMotorTorque") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMotorTorque_name, &property_maxMotorTorque_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxMotorTorque_name);

	zval property_motorSpeed_default_value;
	ZVAL_DOUBLE(&property_motorSpeed_default_value, 0.0);
	zend_string *property_motorSpeed_name = zend_string_init("motorSpeed", sizeof("motorSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_motorSpeed_name, &property_motorSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_motorSpeed_name);

	zval property_collideConnected_default_value;
	ZVAL_FALSE(&property_collideConnected_default_value);
	zend_string *property_collideConnected_name = zend_string_init("collideConnected", sizeof("collideConnected") - 1, 1);
	zend_declare_typed_property(class_entry, property_collideConnected_name, &property_collideConnected_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_collideConnected_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_internalValue_default_value;
	ZVAL_LONG(&property_internalValue_default_value, 0);
	zend_string *property_internalValue_name = zend_string_init("internalValue", sizeof("internalValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_internalValue_name, &property_internalValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_internalValue_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ExplosionDef(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ExplosionDef", class_b2ExplosionDef_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_maskBits_default_value;
	ZVAL_LONG(&property_maskBits_default_value, 0);
	zend_string *property_maskBits_name = zend_string_init("maskBits", sizeof("maskBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_maskBits_name, &property_maskBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maskBits_name);

	zval property_position_default_value;
	ZVAL_UNDEF(&property_position_default_value);
	zend_string *property_position_name = zend_string_init("position", sizeof("position") - 1, 1);
	zend_string *property_position_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_position_name, &property_position_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_position_class_b2Vec2, 0, 0));
	zend_string_release(property_position_name);

	zval property_radius_default_value;
	ZVAL_DOUBLE(&property_radius_default_value, 0.0);
	zend_string *property_radius_name = zend_string_init("radius", sizeof("radius") - 1, 1);
	zend_declare_typed_property(class_entry, property_radius_name, &property_radius_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_radius_name);

	zval property_falloff_default_value;
	ZVAL_DOUBLE(&property_falloff_default_value, 0.0);
	zend_string *property_falloff_name = zend_string_init("falloff", sizeof("falloff") - 1, 1);
	zend_declare_typed_property(class_entry, property_falloff_name, &property_falloff_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_falloff_name);

	zval property_impulsePerLength_default_value;
	ZVAL_DOUBLE(&property_impulsePerLength_default_value, 0.0);
	zend_string *property_impulsePerLength_name = zend_string_init("impulsePerLength", sizeof("impulsePerLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_impulsePerLength_name, &property_impulsePerLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_impulsePerLength_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SensorBeginTouchEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SensorBeginTouchEvent", class_b2SensorBeginTouchEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_sensorShapeId_default_value;
	ZVAL_UNDEF(&property_sensorShapeId_default_value);
	zend_string *property_sensorShapeId_name = zend_string_init("sensorShapeId", sizeof("sensorShapeId") - 1, 1);
	zend_string *property_sensorShapeId_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_sensorShapeId_name, &property_sensorShapeId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_sensorShapeId_class_b2ShapeId, 0, 0));
	zend_string_release(property_sensorShapeId_name);

	zval property_visitorShapeId_default_value;
	ZVAL_UNDEF(&property_visitorShapeId_default_value);
	zend_string *property_visitorShapeId_name = zend_string_init("visitorShapeId", sizeof("visitorShapeId") - 1, 1);
	zend_string *property_visitorShapeId_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_visitorShapeId_name, &property_visitorShapeId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_visitorShapeId_class_b2ShapeId, 0, 0));
	zend_string_release(property_visitorShapeId_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SensorEndTouchEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SensorEndTouchEvent", class_b2SensorEndTouchEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_sensorShapeId_default_value;
	ZVAL_UNDEF(&property_sensorShapeId_default_value);
	zend_string *property_sensorShapeId_name = zend_string_init("sensorShapeId", sizeof("sensorShapeId") - 1, 1);
	zend_string *property_sensorShapeId_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_sensorShapeId_name, &property_sensorShapeId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_sensorShapeId_class_b2ShapeId, 0, 0));
	zend_string_release(property_sensorShapeId_name);

	zval property_visitorShapeId_default_value;
	ZVAL_UNDEF(&property_visitorShapeId_default_value);
	zend_string *property_visitorShapeId_name = zend_string_init("visitorShapeId", sizeof("visitorShapeId") - 1, 1);
	zend_string *property_visitorShapeId_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_visitorShapeId_name, &property_visitorShapeId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_visitorShapeId_class_b2ShapeId, 0, 0));
	zend_string_release(property_visitorShapeId_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SensorEvents(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SensorEvents", class_b2SensorEvents_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_beginEvents_default_value;
	ZVAL_EMPTY_ARRAY(&property_beginEvents_default_value);
	zend_string *property_beginEvents_name = zend_string_init("beginEvents", sizeof("beginEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_beginEvents_name, &property_beginEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_beginEvents_name);

	zval property_endEvents_default_value;
	ZVAL_EMPTY_ARRAY(&property_endEvents_default_value);
	zend_string *property_endEvents_name = zend_string_init("endEvents", sizeof("endEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_endEvents_name, &property_endEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_endEvents_name);

	zval property_beginCount_default_value;
	ZVAL_LONG(&property_beginCount_default_value, 0);
	zend_string *property_beginCount_name = zend_string_init("beginCount", sizeof("beginCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_beginCount_name, &property_beginCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_beginCount_name);

	zval property_endCount_default_value;
	ZVAL_LONG(&property_endCount_default_value, 0);
	zend_string *property_endCount_name = zend_string_init("endCount", sizeof("endCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_endCount_name, &property_endCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_endCount_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ContactBeginTouchEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ContactBeginTouchEvent", class_b2ContactBeginTouchEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_shapeIdA_default_value;
	ZVAL_UNDEF(&property_shapeIdA_default_value);
	zend_string *property_shapeIdA_name = zend_string_init("shapeIdA", sizeof("shapeIdA") - 1, 1);
	zend_string *property_shapeIdA_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdA_name, &property_shapeIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdA_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdA_name);

	zval property_shapeIdB_default_value;
	ZVAL_UNDEF(&property_shapeIdB_default_value);
	zend_string *property_shapeIdB_name = zend_string_init("shapeIdB", sizeof("shapeIdB") - 1, 1);
	zend_string *property_shapeIdB_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdB_name, &property_shapeIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdB_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdB_name);

	zval property_manifold_default_value;
	ZVAL_UNDEF(&property_manifold_default_value);
	zend_string *property_manifold_name = zend_string_init("manifold", sizeof("manifold") - 1, 1);
	zend_string *property_manifold_class_b2Manifold = zend_string_init("b2Manifold", sizeof("b2Manifold")-1, 1);
	zend_declare_typed_property(class_entry, property_manifold_name, &property_manifold_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_manifold_class_b2Manifold, 0, 0));
	zend_string_release(property_manifold_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ContactEndTouchEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ContactEndTouchEvent", class_b2ContactEndTouchEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_shapeIdA_default_value;
	ZVAL_UNDEF(&property_shapeIdA_default_value);
	zend_string *property_shapeIdA_name = zend_string_init("shapeIdA", sizeof("shapeIdA") - 1, 1);
	zend_string *property_shapeIdA_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdA_name, &property_shapeIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdA_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdA_name);

	zval property_shapeIdB_default_value;
	ZVAL_UNDEF(&property_shapeIdB_default_value);
	zend_string *property_shapeIdB_name = zend_string_init("shapeIdB", sizeof("shapeIdB") - 1, 1);
	zend_string *property_shapeIdB_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdB_name, &property_shapeIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdB_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdB_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ContactHitEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ContactHitEvent", class_b2ContactHitEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_shapeIdA_default_value;
	ZVAL_UNDEF(&property_shapeIdA_default_value);
	zend_string *property_shapeIdA_name = zend_string_init("shapeIdA", sizeof("shapeIdA") - 1, 1);
	zend_string *property_shapeIdA_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdA_name, &property_shapeIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdA_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdA_name);

	zval property_shapeIdB_default_value;
	ZVAL_UNDEF(&property_shapeIdB_default_value);
	zend_string *property_shapeIdB_name = zend_string_init("shapeIdB", sizeof("shapeIdB") - 1, 1);
	zend_string *property_shapeIdB_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdB_name, &property_shapeIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdB_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdB_name);

	zval property_point_default_value;
	ZVAL_UNDEF(&property_point_default_value);
	zend_string *property_point_name = zend_string_init("point", sizeof("point") - 1, 1);
	zend_string *property_point_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point_name, &property_point_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point_class_b2Vec2, 0, 0));
	zend_string_release(property_point_name);

	zval property_normal_default_value;
	ZVAL_UNDEF(&property_normal_default_value);
	zend_string *property_normal_name = zend_string_init("normal", sizeof("normal") - 1, 1);
	zend_string *property_normal_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_normal_name, &property_normal_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_normal_class_b2Vec2, 0, 0));
	zend_string_release(property_normal_name);

	zval property_approachSpeed_default_value;
	ZVAL_DOUBLE(&property_approachSpeed_default_value, 0.0);
	zend_string *property_approachSpeed_name = zend_string_init("approachSpeed", sizeof("approachSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_approachSpeed_name, &property_approachSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_approachSpeed_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ContactEvents(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ContactEvents", class_b2ContactEvents_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_beginEvents_default_value;
	ZVAL_EMPTY_ARRAY(&property_beginEvents_default_value);
	zend_string *property_beginEvents_name = zend_string_init("beginEvents", sizeof("beginEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_beginEvents_name, &property_beginEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_beginEvents_name);

	zval property_endEvents_default_value;
	ZVAL_EMPTY_ARRAY(&property_endEvents_default_value);
	zend_string *property_endEvents_name = zend_string_init("endEvents", sizeof("endEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_endEvents_name, &property_endEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_endEvents_name);

	zval property_hitEvents_default_value;
	ZVAL_EMPTY_ARRAY(&property_hitEvents_default_value);
	zend_string *property_hitEvents_name = zend_string_init("hitEvents", sizeof("hitEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_hitEvents_name, &property_hitEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_hitEvents_name);

	zval property_beginCount_default_value;
	ZVAL_LONG(&property_beginCount_default_value, 0);
	zend_string *property_beginCount_name = zend_string_init("beginCount", sizeof("beginCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_beginCount_name, &property_beginCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_beginCount_name);

	zval property_endCount_default_value;
	ZVAL_LONG(&property_endCount_default_value, 0);
	zend_string *property_endCount_name = zend_string_init("endCount", sizeof("endCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_endCount_name, &property_endCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_endCount_name);

	zval property_hitCount_default_value;
	ZVAL_LONG(&property_hitCount_default_value, 0);
	zend_string *property_hitCount_name = zend_string_init("hitCount", sizeof("hitCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_hitCount_name, &property_hitCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_hitCount_name);

	return class_entry;
}

static zend_class_entry *register_class_b2BodyMoveEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2BodyMoveEvent", class_b2BodyMoveEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_transform_default_value;
	ZVAL_UNDEF(&property_transform_default_value);
	zend_string *property_transform_name = zend_string_init("transform", sizeof("transform") - 1, 1);
	zend_string *property_transform_class_b2Transform = zend_string_init("b2Transform", sizeof("b2Transform")-1, 1);
	zend_declare_typed_property(class_entry, property_transform_name, &property_transform_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_transform_class_b2Transform, 0, 0));
	zend_string_release(property_transform_name);

	zval property_bodyId_default_value;
	ZVAL_UNDEF(&property_bodyId_default_value);
	zend_string *property_bodyId_name = zend_string_init("bodyId", sizeof("bodyId") - 1, 1);
	zend_string *property_bodyId_class_b2BodyId = zend_string_init("b2BodyId", sizeof("b2BodyId")-1, 1);
	zend_declare_typed_property(class_entry, property_bodyId_name, &property_bodyId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_bodyId_class_b2BodyId, 0, 0));
	zend_string_release(property_bodyId_name);

	zval property_userData_default_value;
	ZVAL_LONG(&property_userData_default_value, 0);
	zend_string *property_userData_name = zend_string_init("userData", sizeof("userData") - 1, 1);
	zend_declare_typed_property(class_entry, property_userData_name, &property_userData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_userData_name);

	zval property_fellAsleep_default_value;
	ZVAL_FALSE(&property_fellAsleep_default_value);
	zend_string *property_fellAsleep_name = zend_string_init("fellAsleep", sizeof("fellAsleep") - 1, 1);
	zend_declare_typed_property(class_entry, property_fellAsleep_name, &property_fellAsleep_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_fellAsleep_name);

	return class_entry;
}

static zend_class_entry *register_class_b2BodyEvents(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2BodyEvents", class_b2BodyEvents_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_moveEvents_default_value;
	ZVAL_EMPTY_ARRAY(&property_moveEvents_default_value);
	zend_string *property_moveEvents_name = zend_string_init("moveEvents", sizeof("moveEvents") - 1, 1);
	zend_declare_typed_property(class_entry, property_moveEvents_name, &property_moveEvents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_moveEvents_name);

	zval property_moveCount_default_value;
	ZVAL_LONG(&property_moveCount_default_value, 0);
	zend_string *property_moveCount_name = zend_string_init("moveCount", sizeof("moveCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_moveCount_name, &property_moveCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_moveCount_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ContactData(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ContactData", class_b2ContactData_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_shapeIdA_default_value;
	ZVAL_UNDEF(&property_shapeIdA_default_value);
	zend_string *property_shapeIdA_name = zend_string_init("shapeIdA", sizeof("shapeIdA") - 1, 1);
	zend_string *property_shapeIdA_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdA_name, &property_shapeIdA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdA_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdA_name);

	zval property_shapeIdB_default_value;
	ZVAL_UNDEF(&property_shapeIdB_default_value);
	zend_string *property_shapeIdB_name = zend_string_init("shapeIdB", sizeof("shapeIdB") - 1, 1);
	zend_string *property_shapeIdB_class_b2ShapeId = zend_string_init("b2ShapeId", sizeof("b2ShapeId")-1, 1);
	zend_declare_typed_property(class_entry, property_shapeIdB_name, &property_shapeIdB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_shapeIdB_class_b2ShapeId, 0, 0));
	zend_string_release(property_shapeIdB_name);

	zval property_manifold_default_value;
	ZVAL_UNDEF(&property_manifold_default_value);
	zend_string *property_manifold_name = zend_string_init("manifold", sizeof("manifold") - 1, 1);
	zend_string *property_manifold_class_b2Manifold = zend_string_init("b2Manifold", sizeof("b2Manifold")-1, 1);
	zend_declare_typed_property(class_entry, property_manifold_name, &property_manifold_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_manifold_class_b2Manifold, 0, 0));
	zend_string_release(property_manifold_name);

	return class_entry;
}

static zend_class_entry *register_class_b2DebugDraw(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2DebugDraw", class_b2DebugDraw_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_DrawPolygonFcn_default_value;
	ZVAL_NULL(&property_DrawPolygonFcn_default_value);
	zend_string *property_DrawPolygonFcn_name = zend_string_init("DrawPolygonFcn", sizeof("DrawPolygonFcn") - 1, 1);
	zend_string *property_DrawPolygonFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawPolygonFcn_name, &property_DrawPolygonFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawPolygonFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawPolygonFcn_name);

	zval property_DrawSolidPolygonFcn_default_value;
	ZVAL_NULL(&property_DrawSolidPolygonFcn_default_value);
	zend_string *property_DrawSolidPolygonFcn_name = zend_string_init("DrawSolidPolygonFcn", sizeof("DrawSolidPolygonFcn") - 1, 1);
	zend_string *property_DrawSolidPolygonFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawSolidPolygonFcn_name, &property_DrawSolidPolygonFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawSolidPolygonFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawSolidPolygonFcn_name);

	zval property_DrawCircleFcn_default_value;
	ZVAL_NULL(&property_DrawCircleFcn_default_value);
	zend_string *property_DrawCircleFcn_name = zend_string_init("DrawCircleFcn", sizeof("DrawCircleFcn") - 1, 1);
	zend_string *property_DrawCircleFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawCircleFcn_name, &property_DrawCircleFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawCircleFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawCircleFcn_name);

	zval property_DrawSolidCircleFcn_default_value;
	ZVAL_NULL(&property_DrawSolidCircleFcn_default_value);
	zend_string *property_DrawSolidCircleFcn_name = zend_string_init("DrawSolidCircleFcn", sizeof("DrawSolidCircleFcn") - 1, 1);
	zend_string *property_DrawSolidCircleFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawSolidCircleFcn_name, &property_DrawSolidCircleFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawSolidCircleFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawSolidCircleFcn_name);

	zval property_DrawSolidCapsuleFcn_default_value;
	ZVAL_NULL(&property_DrawSolidCapsuleFcn_default_value);
	zend_string *property_DrawSolidCapsuleFcn_name = zend_string_init("DrawSolidCapsuleFcn", sizeof("DrawSolidCapsuleFcn") - 1, 1);
	zend_string *property_DrawSolidCapsuleFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawSolidCapsuleFcn_name, &property_DrawSolidCapsuleFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawSolidCapsuleFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawSolidCapsuleFcn_name);

	zval property_DrawSegmentFcn_default_value;
	ZVAL_NULL(&property_DrawSegmentFcn_default_value);
	zend_string *property_DrawSegmentFcn_name = zend_string_init("DrawSegmentFcn", sizeof("DrawSegmentFcn") - 1, 1);
	zend_string *property_DrawSegmentFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawSegmentFcn_name, &property_DrawSegmentFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawSegmentFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawSegmentFcn_name);

	zval property_DrawTransformFcn_default_value;
	ZVAL_NULL(&property_DrawTransformFcn_default_value);
	zend_string *property_DrawTransformFcn_name = zend_string_init("DrawTransformFcn", sizeof("DrawTransformFcn") - 1, 1);
	zend_string *property_DrawTransformFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawTransformFcn_name, &property_DrawTransformFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawTransformFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawTransformFcn_name);

	zval property_DrawPointFcn_default_value;
	ZVAL_NULL(&property_DrawPointFcn_default_value);
	zend_string *property_DrawPointFcn_name = zend_string_init("DrawPointFcn", sizeof("DrawPointFcn") - 1, 1);
	zend_string *property_DrawPointFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawPointFcn_name, &property_DrawPointFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawPointFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawPointFcn_name);

	zval property_DrawStringFcn_default_value;
	ZVAL_NULL(&property_DrawStringFcn_default_value);
	zend_string *property_DrawStringFcn_name = zend_string_init("DrawStringFcn", sizeof("DrawStringFcn") - 1, 1);
	zend_string *property_DrawStringFcn_class_Closure = zend_string_init("Closure", sizeof("Closure")-1, 1);
	zend_declare_typed_property(class_entry, property_DrawStringFcn_name, &property_DrawStringFcn_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_DrawStringFcn_class_Closure, 0, MAY_BE_NULL));
	zend_string_release(property_DrawStringFcn_name);

	zval property_drawingBounds_default_value;
	ZVAL_UNDEF(&property_drawingBounds_default_value);
	zend_string *property_drawingBounds_name = zend_string_init("drawingBounds", sizeof("drawingBounds") - 1, 1);
	zend_string *property_drawingBounds_class_b2AABB = zend_string_init("b2AABB", sizeof("b2AABB")-1, 1);
	zend_declare_typed_property(class_entry, property_drawingBounds_name, &property_drawingBounds_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_drawingBounds_class_b2AABB, 0, 0));
	zend_string_release(property_drawingBounds_name);

	zval property_useDrawingBounds_default_value;
	ZVAL_FALSE(&property_useDrawingBounds_default_value);
	zend_string *property_useDrawingBounds_name = zend_string_init("useDrawingBounds", sizeof("useDrawingBounds") - 1, 1);
	zend_declare_typed_property(class_entry, property_useDrawingBounds_name, &property_useDrawingBounds_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_useDrawingBounds_name);

	zval property_drawShapes_default_value;
	ZVAL_FALSE(&property_drawShapes_default_value);
	zend_string *property_drawShapes_name = zend_string_init("drawShapes", sizeof("drawShapes") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawShapes_name, &property_drawShapes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawShapes_name);

	zval property_drawJoints_default_value;
	ZVAL_FALSE(&property_drawJoints_default_value);
	zend_string *property_drawJoints_name = zend_string_init("drawJoints", sizeof("drawJoints") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawJoints_name, &property_drawJoints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawJoints_name);

	zval property_drawJointExtras_default_value;
	ZVAL_FALSE(&property_drawJointExtras_default_value);
	zend_string *property_drawJointExtras_name = zend_string_init("drawJointExtras", sizeof("drawJointExtras") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawJointExtras_name, &property_drawJointExtras_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawJointExtras_name);

	zval property_drawBounds_default_value;
	ZVAL_FALSE(&property_drawBounds_default_value);
	zend_string *property_drawBounds_name = zend_string_init("drawBounds", sizeof("drawBounds") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawBounds_name, &property_drawBounds_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawBounds_name);

	zval property_drawMass_default_value;
	ZVAL_FALSE(&property_drawMass_default_value);
	zend_string *property_drawMass_name = zend_string_init("drawMass", sizeof("drawMass") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawMass_name, &property_drawMass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawMass_name);

	zval property_drawBodyNames_default_value;
	ZVAL_FALSE(&property_drawBodyNames_default_value);
	zend_string *property_drawBodyNames_name = zend_string_init("drawBodyNames", sizeof("drawBodyNames") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawBodyNames_name, &property_drawBodyNames_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawBodyNames_name);

	zval property_drawContacts_default_value;
	ZVAL_FALSE(&property_drawContacts_default_value);
	zend_string *property_drawContacts_name = zend_string_init("drawContacts", sizeof("drawContacts") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawContacts_name, &property_drawContacts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawContacts_name);

	zval property_drawGraphColors_default_value;
	ZVAL_FALSE(&property_drawGraphColors_default_value);
	zend_string *property_drawGraphColors_name = zend_string_init("drawGraphColors", sizeof("drawGraphColors") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawGraphColors_name, &property_drawGraphColors_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawGraphColors_name);

	zval property_drawContactNormals_default_value;
	ZVAL_FALSE(&property_drawContactNormals_default_value);
	zend_string *property_drawContactNormals_name = zend_string_init("drawContactNormals", sizeof("drawContactNormals") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawContactNormals_name, &property_drawContactNormals_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawContactNormals_name);

	zval property_drawContactImpulses_default_value;
	ZVAL_FALSE(&property_drawContactImpulses_default_value);
	zend_string *property_drawContactImpulses_name = zend_string_init("drawContactImpulses", sizeof("drawContactImpulses") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawContactImpulses_name, &property_drawContactImpulses_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawContactImpulses_name);

	zval property_drawContactFeatures_default_value;
	ZVAL_FALSE(&property_drawContactFeatures_default_value);
	zend_string *property_drawContactFeatures_name = zend_string_init("drawContactFeatures", sizeof("drawContactFeatures") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawContactFeatures_name, &property_drawContactFeatures_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawContactFeatures_name);

	zval property_drawFrictionImpulses_default_value;
	ZVAL_FALSE(&property_drawFrictionImpulses_default_value);
	zend_string *property_drawFrictionImpulses_name = zend_string_init("drawFrictionImpulses", sizeof("drawFrictionImpulses") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawFrictionImpulses_name, &property_drawFrictionImpulses_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawFrictionImpulses_name);

	zval property_drawIslands_default_value;
	ZVAL_FALSE(&property_drawIslands_default_value);
	zend_string *property_drawIslands_name = zend_string_init("drawIslands", sizeof("drawIslands") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawIslands_name, &property_drawIslands_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawIslands_name);

	zval property_context_default_value;
	ZVAL_NULL(&property_context_default_value);
	zend_string *property_context_name = zend_string_init("context", sizeof("context") - 1, 1);
	zend_declare_typed_property(class_entry, property_context_name, &property_context_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ANY));
	zend_string_release(property_context_name);

	return class_entry;
}
