/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: bebd789e4b10ee1e934ce57761d7dfa201794c26 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateWorld, 0, 1, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2WorldDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DestroyWorld, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_IsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_Step, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, timeStep, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, subStepCount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_Draw, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, draw, b2DebugDraw, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_GetBodyEvents, 0, 1, b2BodyEvents, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_GetSensorEvents, 0, 1, b2SensorEvents, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_GetContactEvents, 0, 1, b2ContactEvents, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_OverlapAABB, 0, 5, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, aabb, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
	ZEND_ARG_TYPE_INFO(0, fcn, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_OverlapShape, 0, 5, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, proxy, b2ShapeProxy, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
	ZEND_ARG_TYPE_INFO(0, fcn, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_CastRay, 0, 6, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, origin, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, translation, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
	ZEND_ARG_TYPE_INFO(0, fcn, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_CastRayClosest, 0, 4, b2RayResult, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, origin, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, translation, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_CastShape, 0, 6, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, proxy, b2ShapeProxy, 0)
	ZEND_ARG_OBJ_INFO(0, translation, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
	ZEND_ARG_TYPE_INFO(0, fcn, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_CastMover, 0, 4, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, mover, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, translation, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_CollideMover, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, mover, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2QueryFilter, 0)
	ZEND_ARG_TYPE_INFO(0, fcn, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetCustomFilterCallback, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 1)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2World_SetPreSolveCallback arginfo_b2World_SetCustomFilterCallback

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_EnableSleeping, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, flag, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_IsSleepingEnabled, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2World_EnableContinuous arginfo_b2World_EnableSleeping

#define arginfo_b2World_IsContinuousEnabled arginfo_b2World_IsSleepingEnabled

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetRestitutionThreshold, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_GetRestitutionThreshold, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2World_SetHitEventThreshold arginfo_b2World_SetRestitutionThreshold

#define arginfo_b2World_GetHitEventThreshold arginfo_b2World_GetRestitutionThreshold

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetGravity, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, gravity, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_GetGravity, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_Explode, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, explosionDef, b2ExplosionDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetContactTuning, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, hertz, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dampingRatio, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, pushSpeed, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetMaximumLinearSpeed, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, maximumLinearSpeed, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2World_GetMaximumLinearSpeed arginfo_b2World_GetRestitutionThreshold

#define arginfo_b2World_EnableWarmStarting arginfo_b2World_EnableSleeping

#define arginfo_b2World_IsWarmStartingEnabled arginfo_b2World_IsSleepingEnabled

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_GetAwakeBodyCount, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_GetProfile, 0, 1, b2Profile, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2World_GetCounters, 0, 1, b2Counters, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetUserData, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, userData, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2World_GetUserData arginfo_b2World_GetAwakeBodyCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2World_SetFrictionCallback, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 1)
ZEND_END_ARG_INFO()

#define arginfo_b2World_SetRestitutionCallback arginfo_b2World_SetFrictionCallback

#define arginfo_b2World_DumpMemoryStats arginfo_b2DestroyWorld

#define arginfo_b2World_RebuildStaticTree arginfo_b2DestroyWorld

#define arginfo_b2World_EnableSpeculative arginfo_b2World_EnableSleeping

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateBody, 0, 2, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2BodyDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DestroyBody, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_IsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_GetType, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetType, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetName, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_GetName, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetUserData, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, userData, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetUserData arginfo_b2Body_GetType

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetPosition, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetRotation, 0, 1, b2Rot, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetTransform, 0, 1, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetTransform, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, position, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, rotation, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetLocalPoint, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, worldPoint, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetWorldPoint, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, localPoint, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetLocalVector, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, worldVector, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetWorldVector, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, localVector, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetLinearVelocity arginfo_b2Body_GetPosition

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_GetAngularVelocity, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetLinearVelocity, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, linearVelocity, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetAngularVelocity, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, angularVelocity, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetTargetTransform, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, target, b2Transform, 0)
	ZEND_ARG_TYPE_INFO(0, timeStep, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetLocalPointVelocity arginfo_b2Body_GetWorldPoint

#define arginfo_b2Body_GetWorldPointVelocity arginfo_b2Body_GetLocalPoint

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_ApplyForce, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, force, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, wake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_ApplyForceToCenter, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, force, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, wake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_ApplyTorque, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, torque, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, wake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_ApplyLinearImpulse, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, impulse, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, wake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_ApplyLinearImpulseToCenter, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, impulse, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, wake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_ApplyAngularImpulse, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, impulse, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, wake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetMass arginfo_b2Body_GetAngularVelocity

#define arginfo_b2Body_GetRotationalInertia arginfo_b2Body_GetAngularVelocity

#define arginfo_b2Body_GetLocalCenterOfMass arginfo_b2Body_GetPosition

#define arginfo_b2Body_GetWorldCenterOfMass arginfo_b2Body_GetPosition

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetMassData, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, massData, b2MassData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetMassData, 0, 1, b2MassData, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_ApplyMassFromShapes arginfo_b2DestroyBody

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetLinearDamping, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, linearDamping, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetLinearDamping arginfo_b2Body_GetAngularVelocity

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetAngularDamping, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, angularDamping, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetAngularDamping arginfo_b2Body_GetAngularVelocity

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetGravityScale, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, gravityScale, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetGravityScale arginfo_b2Body_GetAngularVelocity

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_IsAwake, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetAwake, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, awake, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_EnableSleep, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, enableSleep, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_IsSleepEnabled arginfo_b2Body_IsAwake

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetSleepThreshold, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, sleepThreshold, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetSleepThreshold arginfo_b2Body_GetAngularVelocity

#define arginfo_b2Body_IsEnabled arginfo_b2Body_IsAwake

#define arginfo_b2Body_Disable arginfo_b2DestroyBody

#define arginfo_b2Body_Enable arginfo_b2DestroyBody

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_SetFixedRotation, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, flag, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_IsFixedRotation arginfo_b2Body_IsAwake

#define arginfo_b2Body_SetBullet arginfo_b2Body_SetFixedRotation

#define arginfo_b2Body_IsBullet arginfo_b2Body_IsAwake

#define arginfo_b2Body_EnableContactEvents arginfo_b2Body_SetFixedRotation

#define arginfo_b2Body_EnableHitEvents arginfo_b2Body_SetFixedRotation

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_GetWorld, 0, 1, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetShapeCount arginfo_b2Body_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_GetShapes, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(1, shapeArray, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, capacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetJointCount arginfo_b2Body_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_GetJoints, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(1, jointArray, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, capacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Body_GetContactCapacity arginfo_b2Body_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Body_GetContactData, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(1, contactData, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, capacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Body_ComputeAABB, 0, 1, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateCircleShape, 0, 3, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2ShapeDef, 0)
	ZEND_ARG_OBJ_INFO(0, circle, b2Circle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateSegmentShape, 0, 3, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2ShapeDef, 0)
	ZEND_ARG_OBJ_INFO(0, segment, b2Segment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateCapsuleShape, 0, 3, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2ShapeDef, 0)
	ZEND_ARG_OBJ_INFO(0, capsule, b2Capsule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreatePolygonShape, 0, 3, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2ShapeDef, 0)
	ZEND_ARG_OBJ_INFO(0, polygon, b2Polygon, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DestroyShape, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, updateBodyMass, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_IsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_GetType, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetBody, 0, 1, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetWorld, 0, 1, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_IsSensor, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetUserData, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, userData, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_GetUserData arginfo_b2Shape_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetDensity, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, density, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, updateBodyMass, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_GetDensity, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetFriction, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, friction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_GetFriction arginfo_b2Shape_GetDensity

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetRestitution, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, restitution, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_GetRestitution arginfo_b2Shape_GetDensity

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetMaterial, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, material, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_GetMaterial arginfo_b2Shape_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetSurfaceMaterial, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, surfaceMaterial, b2SurfaceMaterial, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetSurfaceMaterial, 0, 1, b2SurfaceMaterial, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetFilter, 0, 1, b2Filter, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetFilter, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, filter, b2Filter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_EnableSensorEvents, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, flag, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_AreSensorEventsEnabled arginfo_b2Shape_IsSensor

#define arginfo_b2Shape_EnableContactEvents arginfo_b2Shape_EnableSensorEvents

#define arginfo_b2Shape_AreContactEventsEnabled arginfo_b2Shape_IsSensor

#define arginfo_b2Shape_EnablePreSolveEvents arginfo_b2Shape_EnableSensorEvents

#define arginfo_b2Shape_ArePreSolveEventsEnabled arginfo_b2Shape_IsSensor

#define arginfo_b2Shape_EnableHitEvents arginfo_b2Shape_EnableSensorEvents

#define arginfo_b2Shape_AreHitEventsEnabled arginfo_b2Shape_IsSensor

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_TestPoint, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_RayCast, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetCircle, 0, 1, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetSegment, 0, 1, b2Segment, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetChainSegment, 0, 1, b2ChainSegment, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetCapsule, 0, 1, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetPolygon, 0, 1, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetCircle, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, circle, b2Circle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetCapsule, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, capsule, b2Capsule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetSegment, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, segment, b2Segment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_SetPolygon, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, polygon, b2Polygon, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetParentChain, 0, 1, b2ChainId, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_GetContactCapacity arginfo_b2Shape_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_GetContactData, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(1, contactData, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, capacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Shape_GetSensorCapacity arginfo_b2Shape_GetType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Shape_GetSensorOverlaps, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(1, overlaps, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, capacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetAABB, 0, 1, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetMassData, 0, 1, b2MassData, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Shape_GetClosestPoint, 0, 2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, shapeId, b2ShapeId, 0)
	ZEND_ARG_OBJ_INFO(0, target, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateChain, 0, 2, b2ChainId, 0)
	ZEND_ARG_OBJ_INFO(0, bodyId, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2ChainDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DestroyChain, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Chain_GetWorld, 0, 1, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_GetSegmentCount, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_GetSegments, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
	ZEND_ARG_TYPE_INFO(1, segmentArray, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, capacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_SetFriction, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
	ZEND_ARG_TYPE_INFO(0, friction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_GetFriction, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_SetRestitution, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
	ZEND_ARG_TYPE_INFO(0, restitution, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Chain_GetRestitution arginfo_b2Chain_GetFriction

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_SetMaterial, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chainId, b2ChainId, 0)
	ZEND_ARG_TYPE_INFO(0, material, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Chain_GetMaterial arginfo_b2Chain_GetSegmentCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Chain_IsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DestroyJoint, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_IsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_GetType, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Joint_GetBodyA, 0, 1, b2BodyId, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Joint_GetBodyB arginfo_b2Joint_GetBodyA

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Joint_GetWorld, 0, 1, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_SetLocalAnchorA, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, localAnchor, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2Joint_GetLocalAnchorA, 0, 1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Joint_SetLocalAnchorB arginfo_b2Joint_SetLocalAnchorA

#define arginfo_b2Joint_GetLocalAnchorB arginfo_b2Joint_GetLocalAnchorA

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_GetReferenceAngle, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_SetReferenceAngle, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, angleInRadians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_SetLocalAxisA, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, localAxis, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Joint_GetLocalAxisA arginfo_b2Joint_GetLocalAnchorA

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_SetCollideConnected, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, shouldCollide, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_GetCollideConnected, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_SetUserData, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, userData, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2Joint_GetUserData arginfo_b2Joint_GetType

#define arginfo_b2Joint_WakeBodies arginfo_b2DestroyJoint

#define arginfo_b2Joint_GetConstraintForce arginfo_b2Joint_GetLocalAnchorA

#define arginfo_b2Joint_GetConstraintTorque arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2Joint_GetLinearSeparation arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2Joint_GetAngularSeparation arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_GetConstraintTuning, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(1, hertz, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, dampingRatio, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Joint_SetConstraintTuning, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, hertz, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dampingRatio, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateDistanceJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2DistanceJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_SetLength, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_GetLength arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_EnableSpring, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, enableSpring, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_IsSpringEnabled arginfo_b2Joint_GetCollideConnected

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_SetSpringHertz, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, hertz, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_SetSpringDampingRatio, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, dampingRatio, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_GetSpringHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2DistanceJoint_GetSpringDampingRatio arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_EnableLimit, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, enableLimit, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_IsLimitEnabled arginfo_b2Joint_GetCollideConnected

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_SetLengthRange, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, minLength, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxLength, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_GetMinLength arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2DistanceJoint_GetMaxLength arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2DistanceJoint_GetCurrentLength arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_EnableMotor, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, enableMotor, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_IsMotorEnabled arginfo_b2Joint_GetCollideConnected

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_SetMotorSpeed, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, motorSpeed, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_GetMotorSpeed arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DistanceJoint_SetMaxMotorForce, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, force, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DistanceJoint_GetMaxMotorForce arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2DistanceJoint_GetMotorForce arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateMotorJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2MotorJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MotorJoint_SetLinearOffset, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, linearOffset, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MotorJoint_GetLinearOffset arginfo_b2Joint_GetLocalAnchorA

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MotorJoint_SetAngularOffset, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, angularOffset, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MotorJoint_GetAngularOffset arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MotorJoint_SetMaxForce, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, maxForce, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MotorJoint_GetMaxForce arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MotorJoint_SetMaxTorque, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, maxTorque, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MotorJoint_GetMaxTorque arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MotorJoint_SetCorrectionFactor, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, correctionFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MotorJoint_GetCorrectionFactor arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateMouseJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2MouseJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2MouseJoint_SetTarget, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, target, b2Vec2, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2MouseJoint_GetTarget arginfo_b2Joint_GetLocalAnchorA

#define arginfo_b2MouseJoint_SetSpringHertz arginfo_b2DistanceJoint_SetSpringHertz

#define arginfo_b2MouseJoint_GetSpringHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2MouseJoint_SetSpringDampingRatio arginfo_b2DistanceJoint_SetSpringDampingRatio

#define arginfo_b2MouseJoint_GetSpringDampingRatio arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2MouseJoint_SetMaxForce arginfo_b2MotorJoint_SetMaxForce

#define arginfo_b2MouseJoint_GetMaxForce arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateFilterJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2FilterJointDef, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreatePrismaticJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2PrismaticJointDef, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2PrismaticJoint_EnableSpring arginfo_b2DistanceJoint_EnableSpring

#define arginfo_b2PrismaticJoint_IsSpringEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2PrismaticJoint_SetSpringHertz arginfo_b2DistanceJoint_SetSpringHertz

#define arginfo_b2PrismaticJoint_GetSpringHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_SetSpringDampingRatio arginfo_b2DistanceJoint_SetSpringDampingRatio

#define arginfo_b2PrismaticJoint_GetSpringDampingRatio arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2PrismaticJoint_SetTargetTranslation, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, translation, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2PrismaticJoint_GetTargetTranslation arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_EnableLimit arginfo_b2DistanceJoint_EnableLimit

#define arginfo_b2PrismaticJoint_IsLimitEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2PrismaticJoint_GetLowerLimit arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_GetUpperLimit arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2PrismaticJoint_SetLimits, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2PrismaticJoint_EnableMotor arginfo_b2DistanceJoint_EnableMotor

#define arginfo_b2PrismaticJoint_IsMotorEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2PrismaticJoint_SetMotorSpeed arginfo_b2DistanceJoint_SetMotorSpeed

#define arginfo_b2PrismaticJoint_GetMotorSpeed arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_SetMaxMotorForce arginfo_b2DistanceJoint_SetMaxMotorForce

#define arginfo_b2PrismaticJoint_GetMaxMotorForce arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_GetMotorForce arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_GetTranslation arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2PrismaticJoint_GetSpeed arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateRevoluteJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2RevoluteJointDef, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2RevoluteJoint_EnableSpring arginfo_b2DistanceJoint_EnableSpring

#define arginfo_b2RevoluteJoint_IsSpringEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2RevoluteJoint_SetSpringHertz arginfo_b2DistanceJoint_SetSpringHertz

#define arginfo_b2RevoluteJoint_GetSpringHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2RevoluteJoint_SetSpringDampingRatio arginfo_b2DistanceJoint_SetSpringDampingRatio

#define arginfo_b2RevoluteJoint_GetSpringDampingRatio arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2RevoluteJoint_SetTargetAngle, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2RevoluteJoint_GetTargetAngle arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2RevoluteJoint_GetAngle arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2RevoluteJoint_EnableLimit arginfo_b2DistanceJoint_EnableLimit

#define arginfo_b2RevoluteJoint_IsLimitEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2RevoluteJoint_GetLowerLimit arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2RevoluteJoint_GetUpperLimit arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2RevoluteJoint_SetLimits arginfo_b2PrismaticJoint_SetLimits

#define arginfo_b2RevoluteJoint_EnableMotor arginfo_b2DistanceJoint_EnableMotor

#define arginfo_b2RevoluteJoint_IsMotorEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2RevoluteJoint_SetMotorSpeed arginfo_b2DistanceJoint_SetMotorSpeed

#define arginfo_b2RevoluteJoint_GetMotorSpeed arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2RevoluteJoint_GetMotorTorque arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2RevoluteJoint_SetMaxMotorTorque, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jointId, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, torque, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2RevoluteJoint_GetMaxMotorTorque arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateWeldJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2WeldJointDef, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2WeldJoint_SetLinearHertz arginfo_b2DistanceJoint_SetSpringHertz

#define arginfo_b2WeldJoint_GetLinearHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WeldJoint_SetLinearDampingRatio arginfo_b2DistanceJoint_SetSpringDampingRatio

#define arginfo_b2WeldJoint_GetLinearDampingRatio arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WeldJoint_SetAngularHertz arginfo_b2DistanceJoint_SetSpringHertz

#define arginfo_b2WeldJoint_GetAngularHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WeldJoint_SetAngularDampingRatio arginfo_b2DistanceJoint_SetSpringDampingRatio

#define arginfo_b2WeldJoint_GetAngularDampingRatio arginfo_b2Joint_GetReferenceAngle

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CreateWheelJoint, 0, 2, b2JointId, 0)
	ZEND_ARG_OBJ_INFO(0, worldId, b2WorldId, 0)
	ZEND_ARG_OBJ_INFO(0, def, b2WheelJointDef, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2WheelJoint_EnableSpring arginfo_b2DistanceJoint_EnableSpring

#define arginfo_b2WheelJoint_IsSpringEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2WheelJoint_SetSpringHertz arginfo_b2DistanceJoint_SetSpringHertz

#define arginfo_b2WheelJoint_GetSpringHertz arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WheelJoint_SetSpringDampingRatio arginfo_b2DistanceJoint_SetSpringDampingRatio

#define arginfo_b2WheelJoint_GetSpringDampingRatio arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WheelJoint_EnableLimit arginfo_b2DistanceJoint_EnableLimit

#define arginfo_b2WheelJoint_IsLimitEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2WheelJoint_GetLowerLimit arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WheelJoint_GetUpperLimit arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WheelJoint_SetLimits arginfo_b2PrismaticJoint_SetLimits

#define arginfo_b2WheelJoint_EnableMotor arginfo_b2DistanceJoint_EnableMotor

#define arginfo_b2WheelJoint_IsMotorEnabled arginfo_b2Joint_GetCollideConnected

#define arginfo_b2WheelJoint_SetMotorSpeed arginfo_b2DistanceJoint_SetMotorSpeed

#define arginfo_b2WheelJoint_GetMotorSpeed arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WheelJoint_SetMaxMotorTorque arginfo_b2RevoluteJoint_SetMaxMotorTorque

#define arginfo_b2WheelJoint_GetMaxMotorTorque arginfo_b2Joint_GetReferenceAngle

#define arginfo_b2WheelJoint_GetMotorTorque arginfo_b2Joint_GetReferenceAngle

ZEND_FUNCTION(b2CreateWorld);
ZEND_FUNCTION(b2DestroyWorld);
ZEND_FUNCTION(b2World_IsValid);
ZEND_FUNCTION(b2World_Step);
ZEND_FUNCTION(b2World_Draw);
ZEND_FUNCTION(b2World_GetBodyEvents);
ZEND_FUNCTION(b2World_GetSensorEvents);
ZEND_FUNCTION(b2World_GetContactEvents);
ZEND_FUNCTION(b2World_OverlapAABB);
ZEND_FUNCTION(b2World_OverlapShape);
ZEND_FUNCTION(b2World_CastRay);
ZEND_FUNCTION(b2World_CastRayClosest);
ZEND_FUNCTION(b2World_CastShape);
ZEND_FUNCTION(b2World_CastMover);
ZEND_FUNCTION(b2World_CollideMover);
ZEND_FUNCTION(b2World_SetCustomFilterCallback);
ZEND_FUNCTION(b2World_SetPreSolveCallback);
ZEND_FUNCTION(b2World_EnableSleeping);
ZEND_FUNCTION(b2World_IsSleepingEnabled);
ZEND_FUNCTION(b2World_EnableContinuous);
ZEND_FUNCTION(b2World_IsContinuousEnabled);
ZEND_FUNCTION(b2World_SetRestitutionThreshold);
ZEND_FUNCTION(b2World_GetRestitutionThreshold);
ZEND_FUNCTION(b2World_SetHitEventThreshold);
ZEND_FUNCTION(b2World_GetHitEventThreshold);
ZEND_FUNCTION(b2World_SetGravity);
ZEND_FUNCTION(b2World_GetGravity);
ZEND_FUNCTION(b2World_Explode);
ZEND_FUNCTION(b2World_SetContactTuning);
ZEND_FUNCTION(b2World_SetMaximumLinearSpeed);
ZEND_FUNCTION(b2World_GetMaximumLinearSpeed);
ZEND_FUNCTION(b2World_EnableWarmStarting);
ZEND_FUNCTION(b2World_IsWarmStartingEnabled);
ZEND_FUNCTION(b2World_GetAwakeBodyCount);
ZEND_FUNCTION(b2World_GetProfile);
ZEND_FUNCTION(b2World_GetCounters);
ZEND_FUNCTION(b2World_SetUserData);
ZEND_FUNCTION(b2World_GetUserData);
ZEND_FUNCTION(b2World_SetFrictionCallback);
ZEND_FUNCTION(b2World_SetRestitutionCallback);
ZEND_FUNCTION(b2World_DumpMemoryStats);
ZEND_FUNCTION(b2World_RebuildStaticTree);
ZEND_FUNCTION(b2World_EnableSpeculative);
ZEND_FUNCTION(b2CreateBody);
ZEND_FUNCTION(b2DestroyBody);
ZEND_FUNCTION(b2Body_IsValid);
ZEND_FUNCTION(b2Body_GetType);
ZEND_FUNCTION(b2Body_SetType);
ZEND_FUNCTION(b2Body_SetName);
ZEND_FUNCTION(b2Body_GetName);
ZEND_FUNCTION(b2Body_SetUserData);
ZEND_FUNCTION(b2Body_GetUserData);
ZEND_FUNCTION(b2Body_GetPosition);
ZEND_FUNCTION(b2Body_GetRotation);
ZEND_FUNCTION(b2Body_GetTransform);
ZEND_FUNCTION(b2Body_SetTransform);
ZEND_FUNCTION(b2Body_GetLocalPoint);
ZEND_FUNCTION(b2Body_GetWorldPoint);
ZEND_FUNCTION(b2Body_GetLocalVector);
ZEND_FUNCTION(b2Body_GetWorldVector);
ZEND_FUNCTION(b2Body_GetLinearVelocity);
ZEND_FUNCTION(b2Body_GetAngularVelocity);
ZEND_FUNCTION(b2Body_SetLinearVelocity);
ZEND_FUNCTION(b2Body_SetAngularVelocity);
ZEND_FUNCTION(b2Body_SetTargetTransform);
ZEND_FUNCTION(b2Body_GetLocalPointVelocity);
ZEND_FUNCTION(b2Body_GetWorldPointVelocity);
ZEND_FUNCTION(b2Body_ApplyForce);
ZEND_FUNCTION(b2Body_ApplyForceToCenter);
ZEND_FUNCTION(b2Body_ApplyTorque);
ZEND_FUNCTION(b2Body_ApplyLinearImpulse);
ZEND_FUNCTION(b2Body_ApplyLinearImpulseToCenter);
ZEND_FUNCTION(b2Body_ApplyAngularImpulse);
ZEND_FUNCTION(b2Body_GetMass);
ZEND_FUNCTION(b2Body_GetRotationalInertia);
ZEND_FUNCTION(b2Body_GetLocalCenterOfMass);
ZEND_FUNCTION(b2Body_GetWorldCenterOfMass);
ZEND_FUNCTION(b2Body_SetMassData);
ZEND_FUNCTION(b2Body_GetMassData);
ZEND_FUNCTION(b2Body_ApplyMassFromShapes);
ZEND_FUNCTION(b2Body_SetLinearDamping);
ZEND_FUNCTION(b2Body_GetLinearDamping);
ZEND_FUNCTION(b2Body_SetAngularDamping);
ZEND_FUNCTION(b2Body_GetAngularDamping);
ZEND_FUNCTION(b2Body_SetGravityScale);
ZEND_FUNCTION(b2Body_GetGravityScale);
ZEND_FUNCTION(b2Body_IsAwake);
ZEND_FUNCTION(b2Body_SetAwake);
ZEND_FUNCTION(b2Body_EnableSleep);
ZEND_FUNCTION(b2Body_IsSleepEnabled);
ZEND_FUNCTION(b2Body_SetSleepThreshold);
ZEND_FUNCTION(b2Body_GetSleepThreshold);
ZEND_FUNCTION(b2Body_IsEnabled);
ZEND_FUNCTION(b2Body_Disable);
ZEND_FUNCTION(b2Body_Enable);
ZEND_FUNCTION(b2Body_SetFixedRotation);
ZEND_FUNCTION(b2Body_IsFixedRotation);
ZEND_FUNCTION(b2Body_SetBullet);
ZEND_FUNCTION(b2Body_IsBullet);
ZEND_FUNCTION(b2Body_EnableContactEvents);
ZEND_FUNCTION(b2Body_EnableHitEvents);
ZEND_FUNCTION(b2Body_GetWorld);
ZEND_FUNCTION(b2Body_GetShapeCount);
ZEND_FUNCTION(b2Body_GetShapes);
ZEND_FUNCTION(b2Body_GetJointCount);
ZEND_FUNCTION(b2Body_GetJoints);
ZEND_FUNCTION(b2Body_GetContactCapacity);
ZEND_FUNCTION(b2Body_GetContactData);
ZEND_FUNCTION(b2Body_ComputeAABB);
ZEND_FUNCTION(b2CreateCircleShape);
ZEND_FUNCTION(b2CreateSegmentShape);
ZEND_FUNCTION(b2CreateCapsuleShape);
ZEND_FUNCTION(b2CreatePolygonShape);
ZEND_FUNCTION(b2DestroyShape);
ZEND_FUNCTION(b2Shape_IsValid);
ZEND_FUNCTION(b2Shape_GetType);
ZEND_FUNCTION(b2Shape_GetBody);
ZEND_FUNCTION(b2Shape_GetWorld);
ZEND_FUNCTION(b2Shape_IsSensor);
ZEND_FUNCTION(b2Shape_SetUserData);
ZEND_FUNCTION(b2Shape_GetUserData);
ZEND_FUNCTION(b2Shape_SetDensity);
ZEND_FUNCTION(b2Shape_GetDensity);
ZEND_FUNCTION(b2Shape_SetFriction);
ZEND_FUNCTION(b2Shape_GetFriction);
ZEND_FUNCTION(b2Shape_SetRestitution);
ZEND_FUNCTION(b2Shape_GetRestitution);
ZEND_FUNCTION(b2Shape_SetMaterial);
ZEND_FUNCTION(b2Shape_GetMaterial);
ZEND_FUNCTION(b2Shape_SetSurfaceMaterial);
ZEND_FUNCTION(b2Shape_GetSurfaceMaterial);
ZEND_FUNCTION(b2Shape_GetFilter);
ZEND_FUNCTION(b2Shape_SetFilter);
ZEND_FUNCTION(b2Shape_EnableSensorEvents);
ZEND_FUNCTION(b2Shape_AreSensorEventsEnabled);
ZEND_FUNCTION(b2Shape_EnableContactEvents);
ZEND_FUNCTION(b2Shape_AreContactEventsEnabled);
ZEND_FUNCTION(b2Shape_EnablePreSolveEvents);
ZEND_FUNCTION(b2Shape_ArePreSolveEventsEnabled);
ZEND_FUNCTION(b2Shape_EnableHitEvents);
ZEND_FUNCTION(b2Shape_AreHitEventsEnabled);
ZEND_FUNCTION(b2Shape_TestPoint);
ZEND_FUNCTION(b2Shape_RayCast);
ZEND_FUNCTION(b2Shape_GetCircle);
ZEND_FUNCTION(b2Shape_GetSegment);
ZEND_FUNCTION(b2Shape_GetChainSegment);
ZEND_FUNCTION(b2Shape_GetCapsule);
ZEND_FUNCTION(b2Shape_GetPolygon);
ZEND_FUNCTION(b2Shape_SetCircle);
ZEND_FUNCTION(b2Shape_SetCapsule);
ZEND_FUNCTION(b2Shape_SetSegment);
ZEND_FUNCTION(b2Shape_SetPolygon);
ZEND_FUNCTION(b2Shape_GetParentChain);
ZEND_FUNCTION(b2Shape_GetContactCapacity);
ZEND_FUNCTION(b2Shape_GetContactData);
ZEND_FUNCTION(b2Shape_GetSensorCapacity);
ZEND_FUNCTION(b2Shape_GetSensorOverlaps);
ZEND_FUNCTION(b2Shape_GetAABB);
ZEND_FUNCTION(b2Shape_GetMassData);
ZEND_FUNCTION(b2Shape_GetClosestPoint);
ZEND_FUNCTION(b2CreateChain);
ZEND_FUNCTION(b2DestroyChain);
ZEND_FUNCTION(b2Chain_GetWorld);
ZEND_FUNCTION(b2Chain_GetSegmentCount);
ZEND_FUNCTION(b2Chain_GetSegments);
ZEND_FUNCTION(b2Chain_SetFriction);
ZEND_FUNCTION(b2Chain_GetFriction);
ZEND_FUNCTION(b2Chain_SetRestitution);
ZEND_FUNCTION(b2Chain_GetRestitution);
ZEND_FUNCTION(b2Chain_SetMaterial);
ZEND_FUNCTION(b2Chain_GetMaterial);
ZEND_FUNCTION(b2Chain_IsValid);
ZEND_FUNCTION(b2DestroyJoint);
ZEND_FUNCTION(b2Joint_IsValid);
ZEND_FUNCTION(b2Joint_GetType);
ZEND_FUNCTION(b2Joint_GetBodyA);
ZEND_FUNCTION(b2Joint_GetBodyB);
ZEND_FUNCTION(b2Joint_GetWorld);
ZEND_FUNCTION(b2Joint_SetLocalAnchorA);
ZEND_FUNCTION(b2Joint_GetLocalAnchorA);
ZEND_FUNCTION(b2Joint_SetLocalAnchorB);
ZEND_FUNCTION(b2Joint_GetLocalAnchorB);
ZEND_FUNCTION(b2Joint_GetReferenceAngle);
ZEND_FUNCTION(b2Joint_SetReferenceAngle);
ZEND_FUNCTION(b2Joint_SetLocalAxisA);
ZEND_FUNCTION(b2Joint_GetLocalAxisA);
ZEND_FUNCTION(b2Joint_SetCollideConnected);
ZEND_FUNCTION(b2Joint_GetCollideConnected);
ZEND_FUNCTION(b2Joint_SetUserData);
ZEND_FUNCTION(b2Joint_GetUserData);
ZEND_FUNCTION(b2Joint_WakeBodies);
ZEND_FUNCTION(b2Joint_GetConstraintForce);
ZEND_FUNCTION(b2Joint_GetConstraintTorque);
ZEND_FUNCTION(b2Joint_GetLinearSeparation);
ZEND_FUNCTION(b2Joint_GetAngularSeparation);
ZEND_FUNCTION(b2Joint_GetConstraintTuning);
ZEND_FUNCTION(b2Joint_SetConstraintTuning);
ZEND_FUNCTION(b2CreateDistanceJoint);
ZEND_FUNCTION(b2DistanceJoint_SetLength);
ZEND_FUNCTION(b2DistanceJoint_GetLength);
ZEND_FUNCTION(b2DistanceJoint_EnableSpring);
ZEND_FUNCTION(b2DistanceJoint_IsSpringEnabled);
ZEND_FUNCTION(b2DistanceJoint_SetSpringHertz);
ZEND_FUNCTION(b2DistanceJoint_SetSpringDampingRatio);
ZEND_FUNCTION(b2DistanceJoint_GetSpringHertz);
ZEND_FUNCTION(b2DistanceJoint_GetSpringDampingRatio);
ZEND_FUNCTION(b2DistanceJoint_EnableLimit);
ZEND_FUNCTION(b2DistanceJoint_IsLimitEnabled);
ZEND_FUNCTION(b2DistanceJoint_SetLengthRange);
ZEND_FUNCTION(b2DistanceJoint_GetMinLength);
ZEND_FUNCTION(b2DistanceJoint_GetMaxLength);
ZEND_FUNCTION(b2DistanceJoint_GetCurrentLength);
ZEND_FUNCTION(b2DistanceJoint_EnableMotor);
ZEND_FUNCTION(b2DistanceJoint_IsMotorEnabled);
ZEND_FUNCTION(b2DistanceJoint_SetMotorSpeed);
ZEND_FUNCTION(b2DistanceJoint_GetMotorSpeed);
ZEND_FUNCTION(b2DistanceJoint_SetMaxMotorForce);
ZEND_FUNCTION(b2DistanceJoint_GetMaxMotorForce);
ZEND_FUNCTION(b2DistanceJoint_GetMotorForce);
ZEND_FUNCTION(b2CreateMotorJoint);
ZEND_FUNCTION(b2MotorJoint_SetLinearOffset);
ZEND_FUNCTION(b2MotorJoint_GetLinearOffset);
ZEND_FUNCTION(b2MotorJoint_SetAngularOffset);
ZEND_FUNCTION(b2MotorJoint_GetAngularOffset);
ZEND_FUNCTION(b2MotorJoint_SetMaxForce);
ZEND_FUNCTION(b2MotorJoint_GetMaxForce);
ZEND_FUNCTION(b2MotorJoint_SetMaxTorque);
ZEND_FUNCTION(b2MotorJoint_GetMaxTorque);
ZEND_FUNCTION(b2MotorJoint_SetCorrectionFactor);
ZEND_FUNCTION(b2MotorJoint_GetCorrectionFactor);
ZEND_FUNCTION(b2CreateMouseJoint);
ZEND_FUNCTION(b2MouseJoint_SetTarget);
ZEND_FUNCTION(b2MouseJoint_GetTarget);
ZEND_FUNCTION(b2MouseJoint_SetSpringHertz);
ZEND_FUNCTION(b2MouseJoint_GetSpringHertz);
ZEND_FUNCTION(b2MouseJoint_SetSpringDampingRatio);
ZEND_FUNCTION(b2MouseJoint_GetSpringDampingRatio);
ZEND_FUNCTION(b2MouseJoint_SetMaxForce);
ZEND_FUNCTION(b2MouseJoint_GetMaxForce);
ZEND_FUNCTION(b2CreateFilterJoint);
ZEND_FUNCTION(b2CreatePrismaticJoint);
ZEND_FUNCTION(b2PrismaticJoint_EnableSpring);
ZEND_FUNCTION(b2PrismaticJoint_IsSpringEnabled);
ZEND_FUNCTION(b2PrismaticJoint_SetSpringHertz);
ZEND_FUNCTION(b2PrismaticJoint_GetSpringHertz);
ZEND_FUNCTION(b2PrismaticJoint_SetSpringDampingRatio);
ZEND_FUNCTION(b2PrismaticJoint_GetSpringDampingRatio);
ZEND_FUNCTION(b2PrismaticJoint_SetTargetTranslation);
ZEND_FUNCTION(b2PrismaticJoint_GetTargetTranslation);
ZEND_FUNCTION(b2PrismaticJoint_EnableLimit);
ZEND_FUNCTION(b2PrismaticJoint_IsLimitEnabled);
ZEND_FUNCTION(b2PrismaticJoint_GetLowerLimit);
ZEND_FUNCTION(b2PrismaticJoint_GetUpperLimit);
ZEND_FUNCTION(b2PrismaticJoint_SetLimits);
ZEND_FUNCTION(b2PrismaticJoint_EnableMotor);
ZEND_FUNCTION(b2PrismaticJoint_IsMotorEnabled);
ZEND_FUNCTION(b2PrismaticJoint_SetMotorSpeed);
ZEND_FUNCTION(b2PrismaticJoint_GetMotorSpeed);
ZEND_FUNCTION(b2PrismaticJoint_SetMaxMotorForce);
ZEND_FUNCTION(b2PrismaticJoint_GetMaxMotorForce);
ZEND_FUNCTION(b2PrismaticJoint_GetMotorForce);
ZEND_FUNCTION(b2PrismaticJoint_GetTranslation);
ZEND_FUNCTION(b2PrismaticJoint_GetSpeed);
ZEND_FUNCTION(b2CreateRevoluteJoint);
ZEND_FUNCTION(b2RevoluteJoint_EnableSpring);
ZEND_FUNCTION(b2RevoluteJoint_IsSpringEnabled);
ZEND_FUNCTION(b2RevoluteJoint_SetSpringHertz);
ZEND_FUNCTION(b2RevoluteJoint_GetSpringHertz);
ZEND_FUNCTION(b2RevoluteJoint_SetSpringDampingRatio);
ZEND_FUNCTION(b2RevoluteJoint_GetSpringDampingRatio);
ZEND_FUNCTION(b2RevoluteJoint_SetTargetAngle);
ZEND_FUNCTION(b2RevoluteJoint_GetTargetAngle);
ZEND_FUNCTION(b2RevoluteJoint_GetAngle);
ZEND_FUNCTION(b2RevoluteJoint_EnableLimit);
ZEND_FUNCTION(b2RevoluteJoint_IsLimitEnabled);
ZEND_FUNCTION(b2RevoluteJoint_GetLowerLimit);
ZEND_FUNCTION(b2RevoluteJoint_GetUpperLimit);
ZEND_FUNCTION(b2RevoluteJoint_SetLimits);
ZEND_FUNCTION(b2RevoluteJoint_EnableMotor);
ZEND_FUNCTION(b2RevoluteJoint_IsMotorEnabled);
ZEND_FUNCTION(b2RevoluteJoint_SetMotorSpeed);
ZEND_FUNCTION(b2RevoluteJoint_GetMotorSpeed);
ZEND_FUNCTION(b2RevoluteJoint_GetMotorTorque);
ZEND_FUNCTION(b2RevoluteJoint_SetMaxMotorTorque);
ZEND_FUNCTION(b2RevoluteJoint_GetMaxMotorTorque);
ZEND_FUNCTION(b2CreateWeldJoint);
ZEND_FUNCTION(b2WeldJoint_SetLinearHertz);
ZEND_FUNCTION(b2WeldJoint_GetLinearHertz);
ZEND_FUNCTION(b2WeldJoint_SetLinearDampingRatio);
ZEND_FUNCTION(b2WeldJoint_GetLinearDampingRatio);
ZEND_FUNCTION(b2WeldJoint_SetAngularHertz);
ZEND_FUNCTION(b2WeldJoint_GetAngularHertz);
ZEND_FUNCTION(b2WeldJoint_SetAngularDampingRatio);
ZEND_FUNCTION(b2WeldJoint_GetAngularDampingRatio);
ZEND_FUNCTION(b2CreateWheelJoint);
ZEND_FUNCTION(b2WheelJoint_EnableSpring);
ZEND_FUNCTION(b2WheelJoint_IsSpringEnabled);
ZEND_FUNCTION(b2WheelJoint_SetSpringHertz);
ZEND_FUNCTION(b2WheelJoint_GetSpringHertz);
ZEND_FUNCTION(b2WheelJoint_SetSpringDampingRatio);
ZEND_FUNCTION(b2WheelJoint_GetSpringDampingRatio);
ZEND_FUNCTION(b2WheelJoint_EnableLimit);
ZEND_FUNCTION(b2WheelJoint_IsLimitEnabled);
ZEND_FUNCTION(b2WheelJoint_GetLowerLimit);
ZEND_FUNCTION(b2WheelJoint_GetUpperLimit);
ZEND_FUNCTION(b2WheelJoint_SetLimits);
ZEND_FUNCTION(b2WheelJoint_EnableMotor);
ZEND_FUNCTION(b2WheelJoint_IsMotorEnabled);
ZEND_FUNCTION(b2WheelJoint_SetMotorSpeed);
ZEND_FUNCTION(b2WheelJoint_GetMotorSpeed);
ZEND_FUNCTION(b2WheelJoint_SetMaxMotorTorque);
ZEND_FUNCTION(b2WheelJoint_GetMaxMotorTorque);
ZEND_FUNCTION(b2WheelJoint_GetMotorTorque);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(b2CreateWorld, arginfo_b2CreateWorld)
	ZEND_FE(b2DestroyWorld, arginfo_b2DestroyWorld)
	ZEND_FE(b2World_IsValid, arginfo_b2World_IsValid)
	ZEND_FE(b2World_Step, arginfo_b2World_Step)
	ZEND_FE(b2World_Draw, arginfo_b2World_Draw)
	ZEND_FE(b2World_GetBodyEvents, arginfo_b2World_GetBodyEvents)
	ZEND_FE(b2World_GetSensorEvents, arginfo_b2World_GetSensorEvents)
	ZEND_FE(b2World_GetContactEvents, arginfo_b2World_GetContactEvents)
	ZEND_FE(b2World_OverlapAABB, arginfo_b2World_OverlapAABB)
	ZEND_FE(b2World_OverlapShape, arginfo_b2World_OverlapShape)
	ZEND_FE(b2World_CastRay, arginfo_b2World_CastRay)
	ZEND_FE(b2World_CastRayClosest, arginfo_b2World_CastRayClosest)
	ZEND_FE(b2World_CastShape, arginfo_b2World_CastShape)
	ZEND_FE(b2World_CastMover, arginfo_b2World_CastMover)
	ZEND_FE(b2World_CollideMover, arginfo_b2World_CollideMover)
	ZEND_FE(b2World_SetCustomFilterCallback, arginfo_b2World_SetCustomFilterCallback)
	ZEND_FE(b2World_SetPreSolveCallback, arginfo_b2World_SetPreSolveCallback)
	ZEND_FE(b2World_EnableSleeping, arginfo_b2World_EnableSleeping)
	ZEND_FE(b2World_IsSleepingEnabled, arginfo_b2World_IsSleepingEnabled)
	ZEND_FE(b2World_EnableContinuous, arginfo_b2World_EnableContinuous)
	ZEND_FE(b2World_IsContinuousEnabled, arginfo_b2World_IsContinuousEnabled)
	ZEND_FE(b2World_SetRestitutionThreshold, arginfo_b2World_SetRestitutionThreshold)
	ZEND_FE(b2World_GetRestitutionThreshold, arginfo_b2World_GetRestitutionThreshold)
	ZEND_FE(b2World_SetHitEventThreshold, arginfo_b2World_SetHitEventThreshold)
	ZEND_FE(b2World_GetHitEventThreshold, arginfo_b2World_GetHitEventThreshold)
	ZEND_FE(b2World_SetGravity, arginfo_b2World_SetGravity)
	ZEND_FE(b2World_GetGravity, arginfo_b2World_GetGravity)
	ZEND_FE(b2World_Explode, arginfo_b2World_Explode)
	ZEND_FE(b2World_SetContactTuning, arginfo_b2World_SetContactTuning)
	ZEND_FE(b2World_SetMaximumLinearSpeed, arginfo_b2World_SetMaximumLinearSpeed)
	ZEND_FE(b2World_GetMaximumLinearSpeed, arginfo_b2World_GetMaximumLinearSpeed)
	ZEND_FE(b2World_EnableWarmStarting, arginfo_b2World_EnableWarmStarting)
	ZEND_FE(b2World_IsWarmStartingEnabled, arginfo_b2World_IsWarmStartingEnabled)
	ZEND_FE(b2World_GetAwakeBodyCount, arginfo_b2World_GetAwakeBodyCount)
	ZEND_FE(b2World_GetProfile, arginfo_b2World_GetProfile)
	ZEND_FE(b2World_GetCounters, arginfo_b2World_GetCounters)
	ZEND_FE(b2World_SetUserData, arginfo_b2World_SetUserData)
	ZEND_FE(b2World_GetUserData, arginfo_b2World_GetUserData)
	ZEND_FE(b2World_SetFrictionCallback, arginfo_b2World_SetFrictionCallback)
	ZEND_FE(b2World_SetRestitutionCallback, arginfo_b2World_SetRestitutionCallback)
	ZEND_FE(b2World_DumpMemoryStats, arginfo_b2World_DumpMemoryStats)
	ZEND_FE(b2World_RebuildStaticTree, arginfo_b2World_RebuildStaticTree)
	ZEND_FE(b2World_EnableSpeculative, arginfo_b2World_EnableSpeculative)
	ZEND_FE(b2CreateBody, arginfo_b2CreateBody)
	ZEND_FE(b2DestroyBody, arginfo_b2DestroyBody)
	ZEND_FE(b2Body_IsValid, arginfo_b2Body_IsValid)
	ZEND_FE(b2Body_GetType, arginfo_b2Body_GetType)
	ZEND_FE(b2Body_SetType, arginfo_b2Body_SetType)
	ZEND_FE(b2Body_SetName, arginfo_b2Body_SetName)
	ZEND_FE(b2Body_GetName, arginfo_b2Body_GetName)
	ZEND_FE(b2Body_SetUserData, arginfo_b2Body_SetUserData)
	ZEND_FE(b2Body_GetUserData, arginfo_b2Body_GetUserData)
	ZEND_FE(b2Body_GetPosition, arginfo_b2Body_GetPosition)
	ZEND_FE(b2Body_GetRotation, arginfo_b2Body_GetRotation)
	ZEND_FE(b2Body_GetTransform, arginfo_b2Body_GetTransform)
	ZEND_FE(b2Body_SetTransform, arginfo_b2Body_SetTransform)
	ZEND_FE(b2Body_GetLocalPoint, arginfo_b2Body_GetLocalPoint)
	ZEND_FE(b2Body_GetWorldPoint, arginfo_b2Body_GetWorldPoint)
	ZEND_FE(b2Body_GetLocalVector, arginfo_b2Body_GetLocalVector)
	ZEND_FE(b2Body_GetWorldVector, arginfo_b2Body_GetWorldVector)
	ZEND_FE(b2Body_GetLinearVelocity, arginfo_b2Body_GetLinearVelocity)
	ZEND_FE(b2Body_GetAngularVelocity, arginfo_b2Body_GetAngularVelocity)
	ZEND_FE(b2Body_SetLinearVelocity, arginfo_b2Body_SetLinearVelocity)
	ZEND_FE(b2Body_SetAngularVelocity, arginfo_b2Body_SetAngularVelocity)
	ZEND_FE(b2Body_SetTargetTransform, arginfo_b2Body_SetTargetTransform)
	ZEND_FE(b2Body_GetLocalPointVelocity, arginfo_b2Body_GetLocalPointVelocity)
	ZEND_FE(b2Body_GetWorldPointVelocity, arginfo_b2Body_GetWorldPointVelocity)
	ZEND_FE(b2Body_ApplyForce, arginfo_b2Body_ApplyForce)
	ZEND_FE(b2Body_ApplyForceToCenter, arginfo_b2Body_ApplyForceToCenter)
	ZEND_FE(b2Body_ApplyTorque, arginfo_b2Body_ApplyTorque)
	ZEND_FE(b2Body_ApplyLinearImpulse, arginfo_b2Body_ApplyLinearImpulse)
	ZEND_FE(b2Body_ApplyLinearImpulseToCenter, arginfo_b2Body_ApplyLinearImpulseToCenter)
	ZEND_FE(b2Body_ApplyAngularImpulse, arginfo_b2Body_ApplyAngularImpulse)
	ZEND_FE(b2Body_GetMass, arginfo_b2Body_GetMass)
	ZEND_FE(b2Body_GetRotationalInertia, arginfo_b2Body_GetRotationalInertia)
	ZEND_FE(b2Body_GetLocalCenterOfMass, arginfo_b2Body_GetLocalCenterOfMass)
	ZEND_FE(b2Body_GetWorldCenterOfMass, arginfo_b2Body_GetWorldCenterOfMass)
	ZEND_FE(b2Body_SetMassData, arginfo_b2Body_SetMassData)
	ZEND_FE(b2Body_GetMassData, arginfo_b2Body_GetMassData)
	ZEND_FE(b2Body_ApplyMassFromShapes, arginfo_b2Body_ApplyMassFromShapes)
	ZEND_FE(b2Body_SetLinearDamping, arginfo_b2Body_SetLinearDamping)
	ZEND_FE(b2Body_GetLinearDamping, arginfo_b2Body_GetLinearDamping)
	ZEND_FE(b2Body_SetAngularDamping, arginfo_b2Body_SetAngularDamping)
	ZEND_FE(b2Body_GetAngularDamping, arginfo_b2Body_GetAngularDamping)
	ZEND_FE(b2Body_SetGravityScale, arginfo_b2Body_SetGravityScale)
	ZEND_FE(b2Body_GetGravityScale, arginfo_b2Body_GetGravityScale)
	ZEND_FE(b2Body_IsAwake, arginfo_b2Body_IsAwake)
	ZEND_FE(b2Body_SetAwake, arginfo_b2Body_SetAwake)
	ZEND_FE(b2Body_EnableSleep, arginfo_b2Body_EnableSleep)
	ZEND_FE(b2Body_IsSleepEnabled, arginfo_b2Body_IsSleepEnabled)
	ZEND_FE(b2Body_SetSleepThreshold, arginfo_b2Body_SetSleepThreshold)
	ZEND_FE(b2Body_GetSleepThreshold, arginfo_b2Body_GetSleepThreshold)
	ZEND_FE(b2Body_IsEnabled, arginfo_b2Body_IsEnabled)
	ZEND_FE(b2Body_Disable, arginfo_b2Body_Disable)
	ZEND_FE(b2Body_Enable, arginfo_b2Body_Enable)
	ZEND_FE(b2Body_SetFixedRotation, arginfo_b2Body_SetFixedRotation)
	ZEND_FE(b2Body_IsFixedRotation, arginfo_b2Body_IsFixedRotation)
	ZEND_FE(b2Body_SetBullet, arginfo_b2Body_SetBullet)
	ZEND_FE(b2Body_IsBullet, arginfo_b2Body_IsBullet)
	ZEND_FE(b2Body_EnableContactEvents, arginfo_b2Body_EnableContactEvents)
	ZEND_FE(b2Body_EnableHitEvents, arginfo_b2Body_EnableHitEvents)
	ZEND_FE(b2Body_GetWorld, arginfo_b2Body_GetWorld)
	ZEND_FE(b2Body_GetShapeCount, arginfo_b2Body_GetShapeCount)
	ZEND_FE(b2Body_GetShapes, arginfo_b2Body_GetShapes)
	ZEND_FE(b2Body_GetJointCount, arginfo_b2Body_GetJointCount)
	ZEND_FE(b2Body_GetJoints, arginfo_b2Body_GetJoints)
	ZEND_FE(b2Body_GetContactCapacity, arginfo_b2Body_GetContactCapacity)
	ZEND_FE(b2Body_GetContactData, arginfo_b2Body_GetContactData)
	ZEND_FE(b2Body_ComputeAABB, arginfo_b2Body_ComputeAABB)
	ZEND_FE(b2CreateCircleShape, arginfo_b2CreateCircleShape)
	ZEND_FE(b2CreateSegmentShape, arginfo_b2CreateSegmentShape)
	ZEND_FE(b2CreateCapsuleShape, arginfo_b2CreateCapsuleShape)
	ZEND_FE(b2CreatePolygonShape, arginfo_b2CreatePolygonShape)
	ZEND_FE(b2DestroyShape, arginfo_b2DestroyShape)
	ZEND_FE(b2Shape_IsValid, arginfo_b2Shape_IsValid)
	ZEND_FE(b2Shape_GetType, arginfo_b2Shape_GetType)
	ZEND_FE(b2Shape_GetBody, arginfo_b2Shape_GetBody)
	ZEND_FE(b2Shape_GetWorld, arginfo_b2Shape_GetWorld)
	ZEND_FE(b2Shape_IsSensor, arginfo_b2Shape_IsSensor)
	ZEND_FE(b2Shape_SetUserData, arginfo_b2Shape_SetUserData)
	ZEND_FE(b2Shape_GetUserData, arginfo_b2Shape_GetUserData)
	ZEND_FE(b2Shape_SetDensity, arginfo_b2Shape_SetDensity)
	ZEND_FE(b2Shape_GetDensity, arginfo_b2Shape_GetDensity)
	ZEND_FE(b2Shape_SetFriction, arginfo_b2Shape_SetFriction)
	ZEND_FE(b2Shape_GetFriction, arginfo_b2Shape_GetFriction)
	ZEND_FE(b2Shape_SetRestitution, arginfo_b2Shape_SetRestitution)
	ZEND_FE(b2Shape_GetRestitution, arginfo_b2Shape_GetRestitution)
	ZEND_FE(b2Shape_SetMaterial, arginfo_b2Shape_SetMaterial)
	ZEND_FE(b2Shape_GetMaterial, arginfo_b2Shape_GetMaterial)
	ZEND_FE(b2Shape_SetSurfaceMaterial, arginfo_b2Shape_SetSurfaceMaterial)
	ZEND_FE(b2Shape_GetSurfaceMaterial, arginfo_b2Shape_GetSurfaceMaterial)
	ZEND_FE(b2Shape_GetFilter, arginfo_b2Shape_GetFilter)
	ZEND_FE(b2Shape_SetFilter, arginfo_b2Shape_SetFilter)
	ZEND_FE(b2Shape_EnableSensorEvents, arginfo_b2Shape_EnableSensorEvents)
	ZEND_FE(b2Shape_AreSensorEventsEnabled, arginfo_b2Shape_AreSensorEventsEnabled)
	ZEND_FE(b2Shape_EnableContactEvents, arginfo_b2Shape_EnableContactEvents)
	ZEND_FE(b2Shape_AreContactEventsEnabled, arginfo_b2Shape_AreContactEventsEnabled)
	ZEND_FE(b2Shape_EnablePreSolveEvents, arginfo_b2Shape_EnablePreSolveEvents)
	ZEND_FE(b2Shape_ArePreSolveEventsEnabled, arginfo_b2Shape_ArePreSolveEventsEnabled)
	ZEND_FE(b2Shape_EnableHitEvents, arginfo_b2Shape_EnableHitEvents)
	ZEND_FE(b2Shape_AreHitEventsEnabled, arginfo_b2Shape_AreHitEventsEnabled)
	ZEND_FE(b2Shape_TestPoint, arginfo_b2Shape_TestPoint)
	ZEND_FE(b2Shape_RayCast, arginfo_b2Shape_RayCast)
	ZEND_FE(b2Shape_GetCircle, arginfo_b2Shape_GetCircle)
	ZEND_FE(b2Shape_GetSegment, arginfo_b2Shape_GetSegment)
	ZEND_FE(b2Shape_GetChainSegment, arginfo_b2Shape_GetChainSegment)
	ZEND_FE(b2Shape_GetCapsule, arginfo_b2Shape_GetCapsule)
	ZEND_FE(b2Shape_GetPolygon, arginfo_b2Shape_GetPolygon)
	ZEND_FE(b2Shape_SetCircle, arginfo_b2Shape_SetCircle)
	ZEND_FE(b2Shape_SetCapsule, arginfo_b2Shape_SetCapsule)
	ZEND_FE(b2Shape_SetSegment, arginfo_b2Shape_SetSegment)
	ZEND_FE(b2Shape_SetPolygon, arginfo_b2Shape_SetPolygon)
	ZEND_FE(b2Shape_GetParentChain, arginfo_b2Shape_GetParentChain)
	ZEND_FE(b2Shape_GetContactCapacity, arginfo_b2Shape_GetContactCapacity)
	ZEND_FE(b2Shape_GetContactData, arginfo_b2Shape_GetContactData)
	ZEND_FE(b2Shape_GetSensorCapacity, arginfo_b2Shape_GetSensorCapacity)
	ZEND_FE(b2Shape_GetSensorOverlaps, arginfo_b2Shape_GetSensorOverlaps)
	ZEND_FE(b2Shape_GetAABB, arginfo_b2Shape_GetAABB)
	ZEND_FE(b2Shape_GetMassData, arginfo_b2Shape_GetMassData)
	ZEND_FE(b2Shape_GetClosestPoint, arginfo_b2Shape_GetClosestPoint)
	ZEND_FE(b2CreateChain, arginfo_b2CreateChain)
	ZEND_FE(b2DestroyChain, arginfo_b2DestroyChain)
	ZEND_FE(b2Chain_GetWorld, arginfo_b2Chain_GetWorld)
	ZEND_FE(b2Chain_GetSegmentCount, arginfo_b2Chain_GetSegmentCount)
	ZEND_FE(b2Chain_GetSegments, arginfo_b2Chain_GetSegments)
	ZEND_FE(b2Chain_SetFriction, arginfo_b2Chain_SetFriction)
	ZEND_FE(b2Chain_GetFriction, arginfo_b2Chain_GetFriction)
	ZEND_FE(b2Chain_SetRestitution, arginfo_b2Chain_SetRestitution)
	ZEND_FE(b2Chain_GetRestitution, arginfo_b2Chain_GetRestitution)
	ZEND_FE(b2Chain_SetMaterial, arginfo_b2Chain_SetMaterial)
	ZEND_FE(b2Chain_GetMaterial, arginfo_b2Chain_GetMaterial)
	ZEND_FE(b2Chain_IsValid, arginfo_b2Chain_IsValid)
	ZEND_FE(b2DestroyJoint, arginfo_b2DestroyJoint)
	ZEND_FE(b2Joint_IsValid, arginfo_b2Joint_IsValid)
	ZEND_FE(b2Joint_GetType, arginfo_b2Joint_GetType)
	ZEND_FE(b2Joint_GetBodyA, arginfo_b2Joint_GetBodyA)
	ZEND_FE(b2Joint_GetBodyB, arginfo_b2Joint_GetBodyB)
	ZEND_FE(b2Joint_GetWorld, arginfo_b2Joint_GetWorld)
	ZEND_FE(b2Joint_SetLocalAnchorA, arginfo_b2Joint_SetLocalAnchorA)
	ZEND_FE(b2Joint_GetLocalAnchorA, arginfo_b2Joint_GetLocalAnchorA)
	ZEND_FE(b2Joint_SetLocalAnchorB, arginfo_b2Joint_SetLocalAnchorB)
	ZEND_FE(b2Joint_GetLocalAnchorB, arginfo_b2Joint_GetLocalAnchorB)
	ZEND_FE(b2Joint_GetReferenceAngle, arginfo_b2Joint_GetReferenceAngle)
	ZEND_FE(b2Joint_SetReferenceAngle, arginfo_b2Joint_SetReferenceAngle)
	ZEND_FE(b2Joint_SetLocalAxisA, arginfo_b2Joint_SetLocalAxisA)
	ZEND_FE(b2Joint_GetLocalAxisA, arginfo_b2Joint_GetLocalAxisA)
	ZEND_FE(b2Joint_SetCollideConnected, arginfo_b2Joint_SetCollideConnected)
	ZEND_FE(b2Joint_GetCollideConnected, arginfo_b2Joint_GetCollideConnected)
	ZEND_FE(b2Joint_SetUserData, arginfo_b2Joint_SetUserData)
	ZEND_FE(b2Joint_GetUserData, arginfo_b2Joint_GetUserData)
	ZEND_FE(b2Joint_WakeBodies, arginfo_b2Joint_WakeBodies)
	ZEND_FE(b2Joint_GetConstraintForce, arginfo_b2Joint_GetConstraintForce)
	ZEND_FE(b2Joint_GetConstraintTorque, arginfo_b2Joint_GetConstraintTorque)
	ZEND_FE(b2Joint_GetLinearSeparation, arginfo_b2Joint_GetLinearSeparation)
	ZEND_FE(b2Joint_GetAngularSeparation, arginfo_b2Joint_GetAngularSeparation)
	ZEND_FE(b2Joint_GetConstraintTuning, arginfo_b2Joint_GetConstraintTuning)
	ZEND_FE(b2Joint_SetConstraintTuning, arginfo_b2Joint_SetConstraintTuning)
	ZEND_FE(b2CreateDistanceJoint, arginfo_b2CreateDistanceJoint)
	ZEND_FE(b2DistanceJoint_SetLength, arginfo_b2DistanceJoint_SetLength)
	ZEND_FE(b2DistanceJoint_GetLength, arginfo_b2DistanceJoint_GetLength)
	ZEND_FE(b2DistanceJoint_EnableSpring, arginfo_b2DistanceJoint_EnableSpring)
	ZEND_FE(b2DistanceJoint_IsSpringEnabled, arginfo_b2DistanceJoint_IsSpringEnabled)
	ZEND_FE(b2DistanceJoint_SetSpringHertz, arginfo_b2DistanceJoint_SetSpringHertz)
	ZEND_FE(b2DistanceJoint_SetSpringDampingRatio, arginfo_b2DistanceJoint_SetSpringDampingRatio)
	ZEND_FE(b2DistanceJoint_GetSpringHertz, arginfo_b2DistanceJoint_GetSpringHertz)
	ZEND_FE(b2DistanceJoint_GetSpringDampingRatio, arginfo_b2DistanceJoint_GetSpringDampingRatio)
	ZEND_FE(b2DistanceJoint_EnableLimit, arginfo_b2DistanceJoint_EnableLimit)
	ZEND_FE(b2DistanceJoint_IsLimitEnabled, arginfo_b2DistanceJoint_IsLimitEnabled)
	ZEND_FE(b2DistanceJoint_SetLengthRange, arginfo_b2DistanceJoint_SetLengthRange)
	ZEND_FE(b2DistanceJoint_GetMinLength, arginfo_b2DistanceJoint_GetMinLength)
	ZEND_FE(b2DistanceJoint_GetMaxLength, arginfo_b2DistanceJoint_GetMaxLength)
	ZEND_FE(b2DistanceJoint_GetCurrentLength, arginfo_b2DistanceJoint_GetCurrentLength)
	ZEND_FE(b2DistanceJoint_EnableMotor, arginfo_b2DistanceJoint_EnableMotor)
	ZEND_FE(b2DistanceJoint_IsMotorEnabled, arginfo_b2DistanceJoint_IsMotorEnabled)
	ZEND_FE(b2DistanceJoint_SetMotorSpeed, arginfo_b2DistanceJoint_SetMotorSpeed)
	ZEND_FE(b2DistanceJoint_GetMotorSpeed, arginfo_b2DistanceJoint_GetMotorSpeed)
	ZEND_FE(b2DistanceJoint_SetMaxMotorForce, arginfo_b2DistanceJoint_SetMaxMotorForce)
	ZEND_FE(b2DistanceJoint_GetMaxMotorForce, arginfo_b2DistanceJoint_GetMaxMotorForce)
	ZEND_FE(b2DistanceJoint_GetMotorForce, arginfo_b2DistanceJoint_GetMotorForce)
	ZEND_FE(b2CreateMotorJoint, arginfo_b2CreateMotorJoint)
	ZEND_FE(b2MotorJoint_SetLinearOffset, arginfo_b2MotorJoint_SetLinearOffset)
	ZEND_FE(b2MotorJoint_GetLinearOffset, arginfo_b2MotorJoint_GetLinearOffset)
	ZEND_FE(b2MotorJoint_SetAngularOffset, arginfo_b2MotorJoint_SetAngularOffset)
	ZEND_FE(b2MotorJoint_GetAngularOffset, arginfo_b2MotorJoint_GetAngularOffset)
	ZEND_FE(b2MotorJoint_SetMaxForce, arginfo_b2MotorJoint_SetMaxForce)
	ZEND_FE(b2MotorJoint_GetMaxForce, arginfo_b2MotorJoint_GetMaxForce)
	ZEND_FE(b2MotorJoint_SetMaxTorque, arginfo_b2MotorJoint_SetMaxTorque)
	ZEND_FE(b2MotorJoint_GetMaxTorque, arginfo_b2MotorJoint_GetMaxTorque)
	ZEND_FE(b2MotorJoint_SetCorrectionFactor, arginfo_b2MotorJoint_SetCorrectionFactor)
	ZEND_FE(b2MotorJoint_GetCorrectionFactor, arginfo_b2MotorJoint_GetCorrectionFactor)
	ZEND_FE(b2CreateMouseJoint, arginfo_b2CreateMouseJoint)
	ZEND_FE(b2MouseJoint_SetTarget, arginfo_b2MouseJoint_SetTarget)
	ZEND_FE(b2MouseJoint_GetTarget, arginfo_b2MouseJoint_GetTarget)
	ZEND_FE(b2MouseJoint_SetSpringHertz, arginfo_b2MouseJoint_SetSpringHertz)
	ZEND_FE(b2MouseJoint_GetSpringHertz, arginfo_b2MouseJoint_GetSpringHertz)
	ZEND_FE(b2MouseJoint_SetSpringDampingRatio, arginfo_b2MouseJoint_SetSpringDampingRatio)
	ZEND_FE(b2MouseJoint_GetSpringDampingRatio, arginfo_b2MouseJoint_GetSpringDampingRatio)
	ZEND_FE(b2MouseJoint_SetMaxForce, arginfo_b2MouseJoint_SetMaxForce)
	ZEND_FE(b2MouseJoint_GetMaxForce, arginfo_b2MouseJoint_GetMaxForce)
	ZEND_FE(b2CreateFilterJoint, arginfo_b2CreateFilterJoint)
	ZEND_FE(b2CreatePrismaticJoint, arginfo_b2CreatePrismaticJoint)
	ZEND_FE(b2PrismaticJoint_EnableSpring, arginfo_b2PrismaticJoint_EnableSpring)
	ZEND_FE(b2PrismaticJoint_IsSpringEnabled, arginfo_b2PrismaticJoint_IsSpringEnabled)
	ZEND_FE(b2PrismaticJoint_SetSpringHertz, arginfo_b2PrismaticJoint_SetSpringHertz)
	ZEND_FE(b2PrismaticJoint_GetSpringHertz, arginfo_b2PrismaticJoint_GetSpringHertz)
	ZEND_FE(b2PrismaticJoint_SetSpringDampingRatio, arginfo_b2PrismaticJoint_SetSpringDampingRatio)
	ZEND_FE(b2PrismaticJoint_GetSpringDampingRatio, arginfo_b2PrismaticJoint_GetSpringDampingRatio)
	ZEND_FE(b2PrismaticJoint_SetTargetTranslation, arginfo_b2PrismaticJoint_SetTargetTranslation)
	ZEND_FE(b2PrismaticJoint_GetTargetTranslation, arginfo_b2PrismaticJoint_GetTargetTranslation)
	ZEND_FE(b2PrismaticJoint_EnableLimit, arginfo_b2PrismaticJoint_EnableLimit)
	ZEND_FE(b2PrismaticJoint_IsLimitEnabled, arginfo_b2PrismaticJoint_IsLimitEnabled)
	ZEND_FE(b2PrismaticJoint_GetLowerLimit, arginfo_b2PrismaticJoint_GetLowerLimit)
	ZEND_FE(b2PrismaticJoint_GetUpperLimit, arginfo_b2PrismaticJoint_GetUpperLimit)
	ZEND_FE(b2PrismaticJoint_SetLimits, arginfo_b2PrismaticJoint_SetLimits)
	ZEND_FE(b2PrismaticJoint_EnableMotor, arginfo_b2PrismaticJoint_EnableMotor)
	ZEND_FE(b2PrismaticJoint_IsMotorEnabled, arginfo_b2PrismaticJoint_IsMotorEnabled)
	ZEND_FE(b2PrismaticJoint_SetMotorSpeed, arginfo_b2PrismaticJoint_SetMotorSpeed)
	ZEND_FE(b2PrismaticJoint_GetMotorSpeed, arginfo_b2PrismaticJoint_GetMotorSpeed)
	ZEND_FE(b2PrismaticJoint_SetMaxMotorForce, arginfo_b2PrismaticJoint_SetMaxMotorForce)
	ZEND_FE(b2PrismaticJoint_GetMaxMotorForce, arginfo_b2PrismaticJoint_GetMaxMotorForce)
	ZEND_FE(b2PrismaticJoint_GetMotorForce, arginfo_b2PrismaticJoint_GetMotorForce)
	ZEND_FE(b2PrismaticJoint_GetTranslation, arginfo_b2PrismaticJoint_GetTranslation)
	ZEND_FE(b2PrismaticJoint_GetSpeed, arginfo_b2PrismaticJoint_GetSpeed)
	ZEND_FE(b2CreateRevoluteJoint, arginfo_b2CreateRevoluteJoint)
	ZEND_FE(b2RevoluteJoint_EnableSpring, arginfo_b2RevoluteJoint_EnableSpring)
	ZEND_FE(b2RevoluteJoint_IsSpringEnabled, arginfo_b2RevoluteJoint_IsSpringEnabled)
	ZEND_FE(b2RevoluteJoint_SetSpringHertz, arginfo_b2RevoluteJoint_SetSpringHertz)
	ZEND_FE(b2RevoluteJoint_GetSpringHertz, arginfo_b2RevoluteJoint_GetSpringHertz)
	ZEND_FE(b2RevoluteJoint_SetSpringDampingRatio, arginfo_b2RevoluteJoint_SetSpringDampingRatio)
	ZEND_FE(b2RevoluteJoint_GetSpringDampingRatio, arginfo_b2RevoluteJoint_GetSpringDampingRatio)
	ZEND_FE(b2RevoluteJoint_SetTargetAngle, arginfo_b2RevoluteJoint_SetTargetAngle)
	ZEND_FE(b2RevoluteJoint_GetTargetAngle, arginfo_b2RevoluteJoint_GetTargetAngle)
	ZEND_FE(b2RevoluteJoint_GetAngle, arginfo_b2RevoluteJoint_GetAngle)
	ZEND_FE(b2RevoluteJoint_EnableLimit, arginfo_b2RevoluteJoint_EnableLimit)
	ZEND_FE(b2RevoluteJoint_IsLimitEnabled, arginfo_b2RevoluteJoint_IsLimitEnabled)
	ZEND_FE(b2RevoluteJoint_GetLowerLimit, arginfo_b2RevoluteJoint_GetLowerLimit)
	ZEND_FE(b2RevoluteJoint_GetUpperLimit, arginfo_b2RevoluteJoint_GetUpperLimit)
	ZEND_FE(b2RevoluteJoint_SetLimits, arginfo_b2RevoluteJoint_SetLimits)
	ZEND_FE(b2RevoluteJoint_EnableMotor, arginfo_b2RevoluteJoint_EnableMotor)
	ZEND_FE(b2RevoluteJoint_IsMotorEnabled, arginfo_b2RevoluteJoint_IsMotorEnabled)
	ZEND_FE(b2RevoluteJoint_SetMotorSpeed, arginfo_b2RevoluteJoint_SetMotorSpeed)
	ZEND_FE(b2RevoluteJoint_GetMotorSpeed, arginfo_b2RevoluteJoint_GetMotorSpeed)
	ZEND_FE(b2RevoluteJoint_GetMotorTorque, arginfo_b2RevoluteJoint_GetMotorTorque)
	ZEND_FE(b2RevoluteJoint_SetMaxMotorTorque, arginfo_b2RevoluteJoint_SetMaxMotorTorque)
	ZEND_FE(b2RevoluteJoint_GetMaxMotorTorque, arginfo_b2RevoluteJoint_GetMaxMotorTorque)
	ZEND_FE(b2CreateWeldJoint, arginfo_b2CreateWeldJoint)
	ZEND_FE(b2WeldJoint_SetLinearHertz, arginfo_b2WeldJoint_SetLinearHertz)
	ZEND_FE(b2WeldJoint_GetLinearHertz, arginfo_b2WeldJoint_GetLinearHertz)
	ZEND_FE(b2WeldJoint_SetLinearDampingRatio, arginfo_b2WeldJoint_SetLinearDampingRatio)
	ZEND_FE(b2WeldJoint_GetLinearDampingRatio, arginfo_b2WeldJoint_GetLinearDampingRatio)
	ZEND_FE(b2WeldJoint_SetAngularHertz, arginfo_b2WeldJoint_SetAngularHertz)
	ZEND_FE(b2WeldJoint_GetAngularHertz, arginfo_b2WeldJoint_GetAngularHertz)
	ZEND_FE(b2WeldJoint_SetAngularDampingRatio, arginfo_b2WeldJoint_SetAngularDampingRatio)
	ZEND_FE(b2WeldJoint_GetAngularDampingRatio, arginfo_b2WeldJoint_GetAngularDampingRatio)
	ZEND_FE(b2CreateWheelJoint, arginfo_b2CreateWheelJoint)
	ZEND_FE(b2WheelJoint_EnableSpring, arginfo_b2WheelJoint_EnableSpring)
	ZEND_FE(b2WheelJoint_IsSpringEnabled, arginfo_b2WheelJoint_IsSpringEnabled)
	ZEND_FE(b2WheelJoint_SetSpringHertz, arginfo_b2WheelJoint_SetSpringHertz)
	ZEND_FE(b2WheelJoint_GetSpringHertz, arginfo_b2WheelJoint_GetSpringHertz)
	ZEND_FE(b2WheelJoint_SetSpringDampingRatio, arginfo_b2WheelJoint_SetSpringDampingRatio)
	ZEND_FE(b2WheelJoint_GetSpringDampingRatio, arginfo_b2WheelJoint_GetSpringDampingRatio)
	ZEND_FE(b2WheelJoint_EnableLimit, arginfo_b2WheelJoint_EnableLimit)
	ZEND_FE(b2WheelJoint_IsLimitEnabled, arginfo_b2WheelJoint_IsLimitEnabled)
	ZEND_FE(b2WheelJoint_GetLowerLimit, arginfo_b2WheelJoint_GetLowerLimit)
	ZEND_FE(b2WheelJoint_GetUpperLimit, arginfo_b2WheelJoint_GetUpperLimit)
	ZEND_FE(b2WheelJoint_SetLimits, arginfo_b2WheelJoint_SetLimits)
	ZEND_FE(b2WheelJoint_EnableMotor, arginfo_b2WheelJoint_EnableMotor)
	ZEND_FE(b2WheelJoint_IsMotorEnabled, arginfo_b2WheelJoint_IsMotorEnabled)
	ZEND_FE(b2WheelJoint_SetMotorSpeed, arginfo_b2WheelJoint_SetMotorSpeed)
	ZEND_FE(b2WheelJoint_GetMotorSpeed, arginfo_b2WheelJoint_GetMotorSpeed)
	ZEND_FE(b2WheelJoint_SetMaxMotorTorque, arginfo_b2WheelJoint_SetMaxMotorTorque)
	ZEND_FE(b2WheelJoint_GetMaxMotorTorque, arginfo_b2WheelJoint_GetMaxMotorTorque)
	ZEND_FE(b2WheelJoint_GetMotorTorque, arginfo_b2WheelJoint_GetMotorTorque)
	ZEND_FE_END
};
