<?php

/** @generate-class-entries */

function b2CreateWorld(b2WorldDef $def): b2WorldId {}

function b2DestroyWorld(b2WorldId $worldId): void {}

function b2World_IsValid(b2WorldId $id): bool {}

function b2World_Step(b2WorldId $worldId, float $timeStep, int $subStepCount): void {}

function b2World_Draw(b2WorldId $worldId, b2DebugDraw $draw): void {}

function b2World_GetBodyEvents(b2WorldId $worldId): b2BodyEvents {}

function b2World_GetSensorEvents(b2WorldId $worldId): b2SensorEvents {}

function b2World_GetContactEvents(b2WorldId $worldId): b2ContactEvents {}

function b2World_OverlapAABB(b2WorldId $worldId, b2AABB $aabb, b2QueryFilter $filter, callable $fcn, mixed $context): b2TreeStats {}

function b2World_OverlapShape(b2WorldId $worldId, b2ShapeProxy $proxy, b2QueryFilter $filter, callable $fcn, mixed $context): b2TreeStats {}

function b2World_CastRay(b2WorldId $worldId, b2Vec2 $origin, b2Vec2 $translation, b2QueryFilter $filter, callable $fcn, mixed $context): b2TreeStats {}

function b2World_CastRayClosest(b2WorldId $worldId, b2Vec2 $origin, b2Vec2 $translation, b2QueryFilter $filter): b2RayResult {}

function b2World_CastShape(b2WorldId $worldId, b2ShapeProxy $proxy, b2Vec2 $translation, b2QueryFilter $filter, callable $fcn, mixed $context): b2TreeStats {}

function b2World_CastMover(b2WorldId $worldId, b2Capsule $mover, b2Vec2 $translation, b2QueryFilter $filter): float {}

function b2World_CollideMover(b2WorldId $worldId, b2Capsule $mover, b2QueryFilter $filter, callable $fcn, mixed $context): void {}

function b2World_SetCustomFilterCallback(b2WorldId $worldId, ?Closure $callback, mixed $context): void {}

function b2World_SetPreSolveCallback(b2WorldId $worldId, ?Closure $callback, mixed $context): void {}

function b2World_EnableSleeping(b2WorldId $worldId, bool $flag): void {}

function b2World_IsSleepingEnabled(b2WorldId $worldId): bool {}

function b2World_EnableContinuous(b2WorldId $worldId, bool $flag): void {}

function b2World_IsContinuousEnabled(b2WorldId $worldId): bool {}

function b2World_SetRestitutionThreshold(b2WorldId $worldId, float $value): void {}

function b2World_GetRestitutionThreshold(b2WorldId $worldId): float {}

function b2World_SetHitEventThreshold(b2WorldId $worldId, float $value): void {}

function b2World_GetHitEventThreshold(b2WorldId $worldId): float {}

function b2World_SetGravity(b2WorldId $worldId, b2Vec2 $gravity): void {}

function b2World_GetGravity(b2WorldId $worldId): b2Vec2 {}

function b2World_Explode(b2WorldId $worldId, b2ExplosionDef $explosionDef): void {}

function b2World_SetContactTuning(b2WorldId $worldId, float $hertz, float $dampingRatio, float $pushSpeed): void {}

function b2World_SetMaximumLinearSpeed(b2WorldId $worldId, float $maximumLinearSpeed): void {}

function b2World_GetMaximumLinearSpeed(b2WorldId $worldId): float {}

function b2World_EnableWarmStarting(b2WorldId $worldId, bool $flag): void {}

function b2World_IsWarmStartingEnabled(b2WorldId $worldId): bool {}

function b2World_GetAwakeBodyCount(b2WorldId $worldId): int {}

function b2World_GetProfile(b2WorldId $worldId): b2Profile {}

function b2World_GetCounters(b2WorldId $worldId): b2Counters {}

function b2World_SetUserData(b2WorldId $worldId, int $userData): void {}

function b2World_GetUserData(b2WorldId $worldId): int {}

function b2World_SetFrictionCallback(b2WorldId $worldId, ?Closure $callback): void {}

function b2World_SetRestitutionCallback(b2WorldId $worldId, ?Closure $callback): void {}

function b2World_DumpMemoryStats(b2WorldId $worldId): void {}

function b2World_RebuildStaticTree(b2WorldId $worldId): void {}

function b2World_EnableSpeculative(b2WorldId $worldId, bool $flag): void {}

function b2CreateBody(b2WorldId $worldId, b2BodyDef $def): b2BodyId {}

function b2DestroyBody(b2BodyId $bodyId): void {}

function b2Body_IsValid(b2BodyId $id): bool {}

function b2Body_GetType(b2BodyId $bodyId): int {}

function b2Body_SetType(b2BodyId $bodyId, int $type): void {}

function b2Body_SetName(b2BodyId $bodyId, ?string $name): void {}

function b2Body_GetName(b2BodyId $bodyId): ?string {}

function b2Body_SetUserData(b2BodyId $bodyId, int $userData): void {}

function b2Body_GetUserData(b2BodyId $bodyId): int {}

function b2Body_GetPosition(b2BodyId $bodyId): b2Vec2 {}

function b2Body_GetRotation(b2BodyId $bodyId): b2Rot {}

function b2Body_GetTransform(b2BodyId $bodyId): b2Transform {}

function b2Body_SetTransform(b2BodyId $bodyId, b2Vec2 $position, b2Rot $rotation): void {}

function b2Body_GetLocalPoint(b2BodyId $bodyId, b2Vec2 $worldPoint): b2Vec2 {}

function b2Body_GetWorldPoint(b2BodyId $bodyId, b2Vec2 $localPoint): b2Vec2 {}

function b2Body_GetLocalVector(b2BodyId $bodyId, b2Vec2 $worldVector): b2Vec2 {}

function b2Body_GetWorldVector(b2BodyId $bodyId, b2Vec2 $localVector): b2Vec2 {}

function b2Body_GetLinearVelocity(b2BodyId $bodyId): b2Vec2 {}

function b2Body_GetAngularVelocity(b2BodyId $bodyId): float {}

function b2Body_SetLinearVelocity(b2BodyId $bodyId, b2Vec2 $linearVelocity): void {}

function b2Body_SetAngularVelocity(b2BodyId $bodyId, float $angularVelocity): void {}

function b2Body_SetTargetTransform(b2BodyId $bodyId, b2Transform $target, float $timeStep): void {}

function b2Body_GetLocalPointVelocity(b2BodyId $bodyId, b2Vec2 $localPoint): b2Vec2 {}

function b2Body_GetWorldPointVelocity(b2BodyId $bodyId, b2Vec2 $worldPoint): b2Vec2 {}

function b2Body_ApplyForce(b2BodyId $bodyId, b2Vec2 $force, b2Vec2 $point, bool $wake): void {}

function b2Body_ApplyForceToCenter(b2BodyId $bodyId, b2Vec2 $force, bool $wake): void {}

function b2Body_ApplyTorque(b2BodyId $bodyId, float $torque, bool $wake): void {}

function b2Body_ApplyLinearImpulse(b2BodyId $bodyId, b2Vec2 $impulse, b2Vec2 $point, bool $wake): void {}

function b2Body_ApplyLinearImpulseToCenter(b2BodyId $bodyId, b2Vec2 $impulse, bool $wake): void {}

function b2Body_ApplyAngularImpulse(b2BodyId $bodyId, float $impulse, bool $wake): void {}

function b2Body_GetMass(b2BodyId $bodyId): float {}

function b2Body_GetRotationalInertia(b2BodyId $bodyId): float {}

function b2Body_GetLocalCenterOfMass(b2BodyId $bodyId): b2Vec2 {}

function b2Body_GetWorldCenterOfMass(b2BodyId $bodyId): b2Vec2 {}

function b2Body_SetMassData(b2BodyId $bodyId, b2MassData $massData): void {}

function b2Body_GetMassData(b2BodyId $bodyId): b2MassData {}

function b2Body_ApplyMassFromShapes(b2BodyId $bodyId): void {}

function b2Body_SetLinearDamping(b2BodyId $bodyId, float $linearDamping): void {}

function b2Body_GetLinearDamping(b2BodyId $bodyId): float {}

function b2Body_SetAngularDamping(b2BodyId $bodyId, float $angularDamping): void {}

function b2Body_GetAngularDamping(b2BodyId $bodyId): float {}

function b2Body_SetGravityScale(b2BodyId $bodyId, float $gravityScale): void {}

function b2Body_GetGravityScale(b2BodyId $bodyId): float {}

function b2Body_IsAwake(b2BodyId $bodyId): bool {}

function b2Body_SetAwake(b2BodyId $bodyId, bool $awake): void {}

function b2Body_EnableSleep(b2BodyId $bodyId, bool $enableSleep): void {}

function b2Body_IsSleepEnabled(b2BodyId $bodyId): bool {}

function b2Body_SetSleepThreshold(b2BodyId $bodyId, float $sleepThreshold): void {}

function b2Body_GetSleepThreshold(b2BodyId $bodyId): float {}

function b2Body_IsEnabled(b2BodyId $bodyId): bool {}

function b2Body_Disable(b2BodyId $bodyId): void {}

function b2Body_Enable(b2BodyId $bodyId): void {}

function b2Body_SetFixedRotation(b2BodyId $bodyId, bool $flag): void {}

function b2Body_IsFixedRotation(b2BodyId $bodyId): bool {}

function b2Body_SetBullet(b2BodyId $bodyId, bool $flag): void {}

function b2Body_IsBullet(b2BodyId $bodyId): bool {}

function b2Body_EnableContactEvents(b2BodyId $bodyId, bool $flag): void {}

function b2Body_EnableHitEvents(b2BodyId $bodyId, bool $flag): void {}

function b2Body_GetWorld(b2BodyId $bodyId): b2WorldId {}

function b2Body_GetShapeCount(b2BodyId $bodyId): int {}

function b2Body_GetShapes(b2BodyId $bodyId, ?array &$shapeArray, int $capacity): int {}

function b2Body_GetJointCount(b2BodyId $bodyId): int {}

function b2Body_GetJoints(b2BodyId $bodyId, ?array &$jointArray, int $capacity): int {}

function b2Body_GetContactCapacity(b2BodyId $bodyId): int {}

function b2Body_GetContactData(b2BodyId $bodyId, ?array &$contactData, int $capacity): int {}

function b2Body_ComputeAABB(b2BodyId $bodyId): b2AABB {}

function b2CreateCircleShape(b2BodyId $bodyId, b2ShapeDef $def, b2Circle $circle): b2ShapeId {}

function b2CreateSegmentShape(b2BodyId $bodyId, b2ShapeDef $def, b2Segment $segment): b2ShapeId {}

function b2CreateCapsuleShape(b2BodyId $bodyId, b2ShapeDef $def, b2Capsule $capsule): b2ShapeId {}

function b2CreatePolygonShape(b2BodyId $bodyId, b2ShapeDef $def, b2Polygon $polygon): b2ShapeId {}

function b2DestroyShape(b2ShapeId $shapeId, bool $updateBodyMass): void {}

function b2Shape_IsValid(b2ShapeId $id): bool {}

function b2Shape_GetType(b2ShapeId $shapeId): int {}

function b2Shape_GetBody(b2ShapeId $shapeId): b2BodyId {}

function b2Shape_GetWorld(b2ShapeId $shapeId): b2WorldId {}

function b2Shape_IsSensor(b2ShapeId $shapeId): bool {}

function b2Shape_SetUserData(b2ShapeId $shapeId, int $userData): void {}

function b2Shape_GetUserData(b2ShapeId $shapeId): int {}

function b2Shape_SetDensity(b2ShapeId $shapeId, float $density, bool $updateBodyMass): void {}

function b2Shape_GetDensity(b2ShapeId $shapeId): float {}

function b2Shape_SetFriction(b2ShapeId $shapeId, float $friction): void {}

function b2Shape_GetFriction(b2ShapeId $shapeId): float {}

function b2Shape_SetRestitution(b2ShapeId $shapeId, float $restitution): void {}

function b2Shape_GetRestitution(b2ShapeId $shapeId): float {}

function b2Shape_SetMaterial(b2ShapeId $shapeId, int $material): void {}

function b2Shape_GetMaterial(b2ShapeId $shapeId): int {}

function b2Shape_SetSurfaceMaterial(b2ShapeId $shapeId, b2SurfaceMaterial $surfaceMaterial): void {}

function b2Shape_GetSurfaceMaterial(b2ShapeId $shapeId): b2SurfaceMaterial {}

function b2Shape_GetFilter(b2ShapeId $shapeId): b2Filter {}

function b2Shape_SetFilter(b2ShapeId $shapeId, b2Filter $filter): void {}

function b2Shape_EnableSensorEvents(b2ShapeId $shapeId, bool $flag): void {}

function b2Shape_AreSensorEventsEnabled(b2ShapeId $shapeId): bool {}

function b2Shape_EnableContactEvents(b2ShapeId $shapeId, bool $flag): void {}

function b2Shape_AreContactEventsEnabled(b2ShapeId $shapeId): bool {}

function b2Shape_EnablePreSolveEvents(b2ShapeId $shapeId, bool $flag): void {}

function b2Shape_ArePreSolveEventsEnabled(b2ShapeId $shapeId): bool {}

function b2Shape_EnableHitEvents(b2ShapeId $shapeId, bool $flag): void {}

function b2Shape_AreHitEventsEnabled(b2ShapeId $shapeId): bool {}

function b2Shape_TestPoint(b2ShapeId $shapeId, b2Vec2 $point): bool {}

function b2Shape_RayCast(b2ShapeId $shapeId, b2RayCastInput $input): b2CastOutput {}

function b2Shape_GetCircle(b2ShapeId $shapeId): b2Circle {}

function b2Shape_GetSegment(b2ShapeId $shapeId): b2Segment {}

function b2Shape_GetChainSegment(b2ShapeId $shapeId): b2ChainSegment {}

function b2Shape_GetCapsule(b2ShapeId $shapeId): b2Capsule {}

function b2Shape_GetPolygon(b2ShapeId $shapeId): b2Polygon {}

function b2Shape_SetCircle(b2ShapeId $shapeId, b2Circle $circle): void {}

function b2Shape_SetCapsule(b2ShapeId $shapeId, b2Capsule $capsule): void {}

function b2Shape_SetSegment(b2ShapeId $shapeId, b2Segment $segment): void {}

function b2Shape_SetPolygon(b2ShapeId $shapeId, b2Polygon $polygon): void {}

function b2Shape_GetParentChain(b2ShapeId $shapeId): b2ChainId {}

function b2Shape_GetContactCapacity(b2ShapeId $shapeId): int {}

function b2Shape_GetContactData(b2ShapeId $shapeId, ?array &$contactData, int $capacity): int {}

function b2Shape_GetSensorCapacity(b2ShapeId $shapeId): int {}

function b2Shape_GetSensorOverlaps(b2ShapeId $shapeId, ?array &$overlaps, int $capacity): int {}

function b2Shape_GetAABB(b2ShapeId $shapeId): b2AABB {}

function b2Shape_GetMassData(b2ShapeId $shapeId): b2MassData {}

function b2Shape_GetClosestPoint(b2ShapeId $shapeId, b2Vec2 $target): b2Vec2 {}

function b2CreateChain(b2BodyId $bodyId, b2ChainDef $def): b2ChainId {}

function b2DestroyChain(b2ChainId $chainId): void {}

function b2Chain_GetWorld(b2ChainId $chainId): b2WorldId {}

function b2Chain_GetSegmentCount(b2ChainId $chainId): int {}

function b2Chain_GetSegments(b2ChainId $chainId, ?array &$segmentArray, int $capacity): int {}

function b2Chain_SetFriction(b2ChainId $chainId, float $friction): void {}

function b2Chain_GetFriction(b2ChainId $chainId): float {}

function b2Chain_SetRestitution(b2ChainId $chainId, float $restitution): void {}

function b2Chain_GetRestitution(b2ChainId $chainId): float {}

function b2Chain_SetMaterial(b2ChainId $chainId, int $material): void {}

function b2Chain_GetMaterial(b2ChainId $chainId): int {}

function b2Chain_IsValid(b2ChainId $id): bool {}

function b2DestroyJoint(b2JointId $jointId): void {}

function b2Joint_IsValid(b2JointId $id): bool {}

function b2Joint_GetType(b2JointId $jointId): int {}

function b2Joint_GetBodyA(b2JointId $jointId): b2BodyId {}

function b2Joint_GetBodyB(b2JointId $jointId): b2BodyId {}

function b2Joint_GetWorld(b2JointId $jointId): b2WorldId {}

function b2Joint_SetLocalAnchorA(b2JointId $jointId, b2Vec2 $localAnchor): void {}

function b2Joint_GetLocalAnchorA(b2JointId $jointId): b2Vec2 {}

function b2Joint_SetLocalAnchorB(b2JointId $jointId, b2Vec2 $localAnchor): void {}

function b2Joint_GetLocalAnchorB(b2JointId $jointId): b2Vec2 {}

function b2Joint_GetReferenceAngle(b2JointId $jointId): float {}

function b2Joint_SetReferenceAngle(b2JointId $jointId, float $angleInRadians): void {}

function b2Joint_SetLocalAxisA(b2JointId $jointId, b2Vec2 $localAxis): void {}

function b2Joint_GetLocalAxisA(b2JointId $jointId): b2Vec2 {}

function b2Joint_SetCollideConnected(b2JointId $jointId, bool $shouldCollide): void {}

function b2Joint_GetCollideConnected(b2JointId $jointId): bool {}

function b2Joint_SetUserData(b2JointId $jointId, int $userData): void {}

function b2Joint_GetUserData(b2JointId $jointId): int {}

function b2Joint_WakeBodies(b2JointId $jointId): void {}

function b2Joint_GetConstraintForce(b2JointId $jointId): b2Vec2 {}

function b2Joint_GetConstraintTorque(b2JointId $jointId): float {}

function b2Joint_GetLinearSeparation(b2JointId $jointId): float {}

function b2Joint_GetAngularSeparation(b2JointId $jointId): float {}

function b2Joint_GetConstraintTuning(b2JointId $jointId, float &$hertz, float &$dampingRatio): void {}

function b2Joint_SetConstraintTuning(b2JointId $jointId, float $hertz, float $dampingRatio): void {}

function b2CreateDistanceJoint(b2WorldId $worldId, b2DistanceJointDef $def): b2JointId {}

function b2DistanceJoint_SetLength(b2JointId $jointId, float $length): void {}

function b2DistanceJoint_GetLength(b2JointId $jointId): float {}

function b2DistanceJoint_EnableSpring(b2JointId $jointId, bool $enableSpring): void {}

function b2DistanceJoint_IsSpringEnabled(b2JointId $jointId): bool {}

function b2DistanceJoint_SetSpringHertz(b2JointId $jointId, float $hertz): void {}

function b2DistanceJoint_SetSpringDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2DistanceJoint_GetSpringHertz(b2JointId $jointId): float {}

function b2DistanceJoint_GetSpringDampingRatio(b2JointId $jointId): float {}

function b2DistanceJoint_EnableLimit(b2JointId $jointId, bool $enableLimit): void {}

function b2DistanceJoint_IsLimitEnabled(b2JointId $jointId): bool {}

function b2DistanceJoint_SetLengthRange(b2JointId $jointId, float $minLength, float $maxLength): void {}

function b2DistanceJoint_GetMinLength(b2JointId $jointId): float {}

function b2DistanceJoint_GetMaxLength(b2JointId $jointId): float {}

function b2DistanceJoint_GetCurrentLength(b2JointId $jointId): float {}

function b2DistanceJoint_EnableMotor(b2JointId $jointId, bool $enableMotor): void {}

function b2DistanceJoint_IsMotorEnabled(b2JointId $jointId): bool {}

function b2DistanceJoint_SetMotorSpeed(b2JointId $jointId, float $motorSpeed): void {}

function b2DistanceJoint_GetMotorSpeed(b2JointId $jointId): float {}

function b2DistanceJoint_SetMaxMotorForce(b2JointId $jointId, float $force): void {}

function b2DistanceJoint_GetMaxMotorForce(b2JointId $jointId): float {}

function b2DistanceJoint_GetMotorForce(b2JointId $jointId): float {}

function b2CreateMotorJoint(b2WorldId $worldId, b2MotorJointDef $def): b2JointId {}

function b2MotorJoint_SetLinearOffset(b2JointId $jointId, b2Vec2 $linearOffset): void {}

function b2MotorJoint_GetLinearOffset(b2JointId $jointId): b2Vec2 {}

function b2MotorJoint_SetAngularOffset(b2JointId $jointId, float $angularOffset): void {}

function b2MotorJoint_GetAngularOffset(b2JointId $jointId): float {}

function b2MotorJoint_SetMaxForce(b2JointId $jointId, float $maxForce): void {}

function b2MotorJoint_GetMaxForce(b2JointId $jointId): float {}

function b2MotorJoint_SetMaxTorque(b2JointId $jointId, float $maxTorque): void {}

function b2MotorJoint_GetMaxTorque(b2JointId $jointId): float {}

function b2MotorJoint_SetCorrectionFactor(b2JointId $jointId, float $correctionFactor): void {}

function b2MotorJoint_GetCorrectionFactor(b2JointId $jointId): float {}

function b2CreateMouseJoint(b2WorldId $worldId, b2MouseJointDef $def): b2JointId {}

function b2MouseJoint_SetTarget(b2JointId $jointId, b2Vec2 $target): void {}

function b2MouseJoint_GetTarget(b2JointId $jointId): b2Vec2 {}

function b2MouseJoint_SetSpringHertz(b2JointId $jointId, float $hertz): void {}

function b2MouseJoint_GetSpringHertz(b2JointId $jointId): float {}

function b2MouseJoint_SetSpringDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2MouseJoint_GetSpringDampingRatio(b2JointId $jointId): float {}

function b2MouseJoint_SetMaxForce(b2JointId $jointId, float $maxForce): void {}

function b2MouseJoint_GetMaxForce(b2JointId $jointId): float {}

function b2CreateFilterJoint(b2WorldId $worldId, b2FilterJointDef $def): b2JointId {}

function b2CreatePrismaticJoint(b2WorldId $worldId, b2PrismaticJointDef $def): b2JointId {}

function b2PrismaticJoint_EnableSpring(b2JointId $jointId, bool $enableSpring): void {}

function b2PrismaticJoint_IsSpringEnabled(b2JointId $jointId): bool {}

function b2PrismaticJoint_SetSpringHertz(b2JointId $jointId, float $hertz): void {}

function b2PrismaticJoint_GetSpringHertz(b2JointId $jointId): float {}

function b2PrismaticJoint_SetSpringDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2PrismaticJoint_GetSpringDampingRatio(b2JointId $jointId): float {}

function b2PrismaticJoint_SetTargetTranslation(b2JointId $jointId, float $translation): void {}

function b2PrismaticJoint_GetTargetTranslation(b2JointId $jointId): float {}

function b2PrismaticJoint_EnableLimit(b2JointId $jointId, bool $enableLimit): void {}

function b2PrismaticJoint_IsLimitEnabled(b2JointId $jointId): bool {}

function b2PrismaticJoint_GetLowerLimit(b2JointId $jointId): float {}

function b2PrismaticJoint_GetUpperLimit(b2JointId $jointId): float {}

function b2PrismaticJoint_SetLimits(b2JointId $jointId, float $lower, float $upper): void {}

function b2PrismaticJoint_EnableMotor(b2JointId $jointId, bool $enableMotor): void {}

function b2PrismaticJoint_IsMotorEnabled(b2JointId $jointId): bool {}

function b2PrismaticJoint_SetMotorSpeed(b2JointId $jointId, float $motorSpeed): void {}

function b2PrismaticJoint_GetMotorSpeed(b2JointId $jointId): float {}

function b2PrismaticJoint_SetMaxMotorForce(b2JointId $jointId, float $force): void {}

function b2PrismaticJoint_GetMaxMotorForce(b2JointId $jointId): float {}

function b2PrismaticJoint_GetMotorForce(b2JointId $jointId): float {}

function b2PrismaticJoint_GetTranslation(b2JointId $jointId): float {}

function b2PrismaticJoint_GetSpeed(b2JointId $jointId): float {}

function b2CreateRevoluteJoint(b2WorldId $worldId, b2RevoluteJointDef $def): b2JointId {}

function b2RevoluteJoint_EnableSpring(b2JointId $jointId, bool $enableSpring): void {}

function b2RevoluteJoint_IsSpringEnabled(b2JointId $jointId): bool {}

function b2RevoluteJoint_SetSpringHertz(b2JointId $jointId, float $hertz): void {}

function b2RevoluteJoint_GetSpringHertz(b2JointId $jointId): float {}

function b2RevoluteJoint_SetSpringDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2RevoluteJoint_GetSpringDampingRatio(b2JointId $jointId): float {}

function b2RevoluteJoint_SetTargetAngle(b2JointId $jointId, float $angle): void {}

function b2RevoluteJoint_GetTargetAngle(b2JointId $jointId): float {}

function b2RevoluteJoint_GetAngle(b2JointId $jointId): float {}

function b2RevoluteJoint_EnableLimit(b2JointId $jointId, bool $enableLimit): void {}

function b2RevoluteJoint_IsLimitEnabled(b2JointId $jointId): bool {}

function b2RevoluteJoint_GetLowerLimit(b2JointId $jointId): float {}

function b2RevoluteJoint_GetUpperLimit(b2JointId $jointId): float {}

function b2RevoluteJoint_SetLimits(b2JointId $jointId, float $lower, float $upper): void {}

function b2RevoluteJoint_EnableMotor(b2JointId $jointId, bool $enableMotor): void {}

function b2RevoluteJoint_IsMotorEnabled(b2JointId $jointId): bool {}

function b2RevoluteJoint_SetMotorSpeed(b2JointId $jointId, float $motorSpeed): void {}

function b2RevoluteJoint_GetMotorSpeed(b2JointId $jointId): float {}

function b2RevoluteJoint_GetMotorTorque(b2JointId $jointId): float {}

function b2RevoluteJoint_SetMaxMotorTorque(b2JointId $jointId, float $torque): void {}

function b2RevoluteJoint_GetMaxMotorTorque(b2JointId $jointId): float {}

function b2CreateWeldJoint(b2WorldId $worldId, b2WeldJointDef $def): b2JointId {}

function b2WeldJoint_SetLinearHertz(b2JointId $jointId, float $hertz): void {}

function b2WeldJoint_GetLinearHertz(b2JointId $jointId): float {}

function b2WeldJoint_SetLinearDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2WeldJoint_GetLinearDampingRatio(b2JointId $jointId): float {}

function b2WeldJoint_SetAngularHertz(b2JointId $jointId, float $hertz): void {}

function b2WeldJoint_GetAngularHertz(b2JointId $jointId): float {}

function b2WeldJoint_SetAngularDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2WeldJoint_GetAngularDampingRatio(b2JointId $jointId): float {}

function b2CreateWheelJoint(b2WorldId $worldId, b2WheelJointDef $def): b2JointId {}

function b2WheelJoint_EnableSpring(b2JointId $jointId, bool $enableSpring): void {}

function b2WheelJoint_IsSpringEnabled(b2JointId $jointId): bool {}

function b2WheelJoint_SetSpringHertz(b2JointId $jointId, float $hertz): void {}

function b2WheelJoint_GetSpringHertz(b2JointId $jointId): float {}

function b2WheelJoint_SetSpringDampingRatio(b2JointId $jointId, float $dampingRatio): void {}

function b2WheelJoint_GetSpringDampingRatio(b2JointId $jointId): float {}

function b2WheelJoint_EnableLimit(b2JointId $jointId, bool $enableLimit): void {}

function b2WheelJoint_IsLimitEnabled(b2JointId $jointId): bool {}

function b2WheelJoint_GetLowerLimit(b2JointId $jointId): float {}

function b2WheelJoint_GetUpperLimit(b2JointId $jointId): float {}

function b2WheelJoint_SetLimits(b2JointId $jointId, float $lower, float $upper): void {}

function b2WheelJoint_EnableMotor(b2JointId $jointId, bool $enableMotor): void {}

function b2WheelJoint_IsMotorEnabled(b2JointId $jointId): bool {}

function b2WheelJoint_SetMotorSpeed(b2JointId $jointId, float $motorSpeed): void {}

function b2WheelJoint_GetMotorSpeed(b2JointId $jointId): float {}

function b2WheelJoint_SetMaxMotorTorque(b2JointId $jointId, float $torque): void {}

function b2WheelJoint_GetMaxMotorTorque(b2JointId $jointId): float {}

function b2WheelJoint_GetMotorTorque(b2JointId $jointId): float {}

