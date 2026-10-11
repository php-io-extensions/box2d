<?php

declare(strict_types=1);

function box2d_joint_world(bool $gravity = true, bool $sleep = true): b2WorldId
{
    $definition = b2DefaultWorldDef();
    $definition->gravity = new b2Vec2(0.0, $gravity ? -10.0 : 0.0);
    $definition->enableSleep = $sleep;

    return b2CreateWorld($definition);
}

function box2d_joint_body(b2WorldId $world, int $type, float $x, float $y, bool $sleep = true): b2BodyId
{
    $definition = b2DefaultBodyDef();
    $definition->type = $type;
    $definition->position = new b2Vec2($x, $y);
    $definition->enableSleep = $sleep;
    $body = b2CreateBody($world, $definition);
    b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    return $body;
}

function box2d_joint_steps(b2WorldId $world, int $count): void
{
    for ($step = 0; $step < $count; $step++) {
        b2World_Step($world, 1.0 / 60.0, 4);
    }
}

function box2d_joint_round_trip(b2JointId $joint, b2WorldId $world, b2BodyId $bodyA, b2BodyId $bodyB, bool $axis, bool $reference): void
{
    expect(b2Joint_IsValid($joint))->toBeTrue()
        ->and(B2_ID_EQUALS(b2Joint_GetBodyA($joint), $bodyA))->toBeTrue()
        ->and(B2_ID_EQUALS(b2Joint_GetBodyB($joint), $bodyB))->toBeTrue()
        ->and(b2Joint_GetWorld($joint)->index1)->toBe($world->index1)
        ->and(b2Joint_GetWorld($joint)->generation)->toBe($world->generation);

    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.25, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(-0.25, 0.0));
    b2Joint_SetUserData($joint, 9);
    b2Joint_SetCollideConnected($joint, true);
    b2Joint_SetConstraintTuning($joint, 4.0, 0.5);
    b2Joint_WakeBodies($joint);

    $anchorA = b2Joint_GetLocalAnchorA($joint);
    $anchorB = b2Joint_GetLocalAnchorB($joint);
    $hertz = 0.0;
    $damping = 0.0;
    b2Joint_GetConstraintTuning($joint, $hertz, $damping);
    $force = b2Joint_GetConstraintForce($joint);

    expect($anchorA->x)->toBe(0.25)
        ->and($anchorB->x)->toBe(-0.25)
        ->and(b2Joint_GetUserData($joint))->toBe(9)
        ->and(b2Joint_GetCollideConnected($joint))->toBeTrue()
        ->and($hertz)->toBe(4.0)
        ->and($damping)->toBe(0.5)
        ->and($force)->toBeInstanceOf(b2Vec2::class)
        ->and(b2Joint_GetConstraintTorque($joint))->toBeFloat()
        ->and(b2Joint_GetLinearSeparation($joint))->toBeFloat()
        ->and(b2Joint_GetAngularSeparation($joint))->toBeFloat();

    b2Joint_SetCollideConnected($joint, false);
    expect(b2Joint_GetCollideConnected($joint))->toBeFalse();

    if ($reference) {
        b2Joint_SetReferenceAngle($joint, 0.25);
        box2d_expect_near(b2Joint_GetReferenceAngle($joint), 0.25);
    } else {
        b2Joint_SetReferenceAngle($joint, 0.25);
        expect(b2Joint_GetReferenceAngle($joint))->toBe(0.0);
    }

    if ($axis) {
        b2Joint_SetLocalAxisA($joint, new b2Vec2(1.0, 0.0));
        $stored = b2Joint_GetLocalAxisA($joint);
        expect($stored->x)->toBe(1.0)
            ->and($stored->y)->toBe(0.0);
    } else {
        b2Joint_SetLocalAxisA($joint, new b2Vec2(1.0, 0.0));
        expect(b2Joint_GetLocalAxisA($joint)->x)->toBe(0.0);
    }
}

it('holds a distance joint at its length', function (): void {
    $definition = b2DefaultDistanceJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->length)->toBe(1.0)
        ->and($definition->maxLength)->toBe(100000.0)
        ->and($definition->enableSpring)->toBeFalse();

    $world = box2d_joint_world(false);
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 2.0, 0.0);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $definition->localAnchorA = new b2Vec2(0.0, 0.0);
    $definition->localAnchorB = new b2Vec2(0.0, 0.0);
    $definition->length = 2.0;
    $joint = b2CreateDistanceJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_distanceJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, false, false);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(0.0, 0.0));

    b2DistanceJoint_SetLength($joint, 2.0);
    b2DistanceJoint_EnableSpring($joint, true);
    b2DistanceJoint_SetSpringHertz($joint, 2.0);
    b2DistanceJoint_SetSpringDampingRatio($joint, 0.5);
    b2DistanceJoint_EnableLimit($joint, true);
    b2DistanceJoint_SetLengthRange($joint, 0.5, 3.0);
    b2DistanceJoint_EnableMotor($joint, true);
    b2DistanceJoint_SetMotorSpeed($joint, 0.0);
    b2DistanceJoint_SetMaxMotorForce($joint, 10.0);
    b2DistanceJoint_EnableSpring($joint, false);
    b2DistanceJoint_EnableLimit($joint, false);
    b2DistanceJoint_EnableMotor($joint, false);

    expect(b2DistanceJoint_GetLength($joint))->toBe(2.0)
        ->and(b2DistanceJoint_IsSpringEnabled($joint))->toBeFalse()
        ->and(b2DistanceJoint_GetSpringHertz($joint))->toBe(2.0)
        ->and(b2DistanceJoint_GetSpringDampingRatio($joint))->toBe(0.5)
        ->and(b2DistanceJoint_IsLimitEnabled($joint))->toBeFalse()
        ->and(b2DistanceJoint_GetMinLength($joint))->toBe(0.5)
        ->and(b2DistanceJoint_GetMaxLength($joint))->toBe(3.0)
        ->and(b2DistanceJoint_IsMotorEnabled($joint))->toBeFalse()
        ->and(b2DistanceJoint_GetMotorSpeed($joint))->toBe(0.0)
        ->and(b2DistanceJoint_GetMaxMotorForce($joint))->toBe(10.0)
        ->and(b2DistanceJoint_GetMotorForce($joint))->toBeFloat();

    b2Body_SetLinearVelocity($bodyB, new b2Vec2(8.0, 0.0));
    box2d_joint_steps($world, 90);
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near(hypot($position->x, $position->y), 2.0, 0.05);
    box2d_expect_near(b2DistanceJoint_GetCurrentLength($joint), 2.0, 0.05);

    b2DestroyJoint($joint);
    expect(b2Joint_IsValid($joint))->toBeFalse();
    b2DestroyWorld($world);
});

it('holds a revolute joint at its anchor', function (): void {
    $definition = b2DefaultRevoluteJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->drawSize)->toBe(0.25);

    $world = box2d_joint_world();
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 1.0, 0.0);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $definition->localAnchorA = new b2Vec2(0.0, 0.0);
    $definition->localAnchorB = new b2Vec2(-1.0, 0.0);
    $joint = b2CreateRevoluteJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_revoluteJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, false, true);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(-1.0, 0.0));
    b2Joint_SetReferenceAngle($joint, 0.0);

    b2RevoluteJoint_EnableSpring($joint, true);
    b2RevoluteJoint_SetSpringHertz($joint, 2.0);
    b2RevoluteJoint_SetSpringDampingRatio($joint, 0.5);
    b2RevoluteJoint_SetTargetAngle($joint, 0.25);
    b2RevoluteJoint_EnableLimit($joint, true);
    b2RevoluteJoint_SetLimits($joint, -0.5, 0.5);
    b2RevoluteJoint_EnableMotor($joint, true);
    b2RevoluteJoint_SetMotorSpeed($joint, 1.0);
    b2RevoluteJoint_SetMaxMotorTorque($joint, 20.0);
    b2RevoluteJoint_EnableSpring($joint, false);
    b2RevoluteJoint_EnableLimit($joint, false);
    b2RevoluteJoint_EnableMotor($joint, false);
    b2RevoluteJoint_SetMotorSpeed($joint, 0.0);

    expect(b2RevoluteJoint_IsSpringEnabled($joint))->toBeFalse()
        ->and(b2RevoluteJoint_GetSpringHertz($joint))->toBe(2.0)
        ->and(b2RevoluteJoint_GetSpringDampingRatio($joint))->toBe(0.5)
        ->and(b2RevoluteJoint_GetTargetAngle($joint))->toBe(0.25)
        ->and(b2RevoluteJoint_IsLimitEnabled($joint))->toBeFalse()
        ->and(b2RevoluteJoint_GetLowerLimit($joint))->toBe(-0.5)
        ->and(b2RevoluteJoint_GetUpperLimit($joint))->toBe(0.5)
        ->and(b2RevoluteJoint_IsMotorEnabled($joint))->toBeFalse()
        ->and(b2RevoluteJoint_GetMotorSpeed($joint))->toBe(0.0)
        ->and(b2RevoluteJoint_GetMaxMotorTorque($joint))->toBe(20.0)
        ->and(b2RevoluteJoint_GetMotorTorque($joint))->toBeFloat()
        ->and(b2RevoluteJoint_GetAngle($joint))->toBeFloat();

    box2d_joint_steps($world, 90);
    $anchor = b2Body_GetWorldPoint($bodyB, new b2Vec2(-1.0, 0.0));
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near($anchor->x, 0.0, 0.05);
    box2d_expect_near($anchor->y, 0.0, 0.05);
    expect(abs($position->y))->toBeGreaterThan(0.1);

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});

it('holds a weld joint at its relative pose', function (): void {
    $definition = b2DefaultWeldJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->linearHertz)->toBe(0.0);

    $world = box2d_joint_world();
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 1.5, 0.0);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $definition->localAnchorA = new b2Vec2(1.5, 0.0);
    $definition->localAnchorB = new b2Vec2(0.0, 0.0);
    $joint = b2CreateWeldJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_weldJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, false, true);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(1.5, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetReferenceAngle($joint, 0.0);
    b2WeldJoint_SetLinearHertz($joint, 0.0);
    b2WeldJoint_SetLinearDampingRatio($joint, 0.5);
    b2WeldJoint_SetAngularHertz($joint, 0.0);
    b2WeldJoint_SetAngularDampingRatio($joint, 0.5);

    expect(b2WeldJoint_GetLinearHertz($joint))->toBe(0.0)
        ->and(b2WeldJoint_GetLinearDampingRatio($joint))->toBe(0.5)
        ->and(b2WeldJoint_GetAngularHertz($joint))->toBe(0.0)
        ->and(b2WeldJoint_GetAngularDampingRatio($joint))->toBe(0.5);

    b2Body_ApplyForceToCenter($bodyB, new b2Vec2(0.0, 50.0), true);
    box2d_joint_steps($world, 60);
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near($position->x, 1.5, 0.05);
    box2d_expect_near($position->y, 0.0, 0.05);
    box2d_expect_near(b2Body_GetRotation($bodyB)->s, 0.0, 0.05);

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});

it('holds a prismatic joint on its axis', function (): void {
    $definition = b2DefaultPrismaticJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->localAxisA->x)->toBe(1.0)
        ->and($definition->localAxisA->y)->toBe(0.0);

    $world = box2d_joint_world();
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 0.0, 0.0);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $joint = b2CreatePrismaticJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_prismaticJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, true, true);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAxisA($joint, new b2Vec2(1.0, 0.0));
    b2Joint_SetReferenceAngle($joint, 0.0);

    b2PrismaticJoint_EnableSpring($joint, true);
    b2PrismaticJoint_SetSpringHertz($joint, 2.0);
    b2PrismaticJoint_SetSpringDampingRatio($joint, 0.5);
    b2PrismaticJoint_SetTargetTranslation($joint, 0.25);
    b2PrismaticJoint_EnableLimit($joint, true);
    b2PrismaticJoint_SetLimits($joint, -1.0, 2.0);
    b2PrismaticJoint_EnableMotor($joint, true);
    b2PrismaticJoint_SetMotorSpeed($joint, 1.0);
    b2PrismaticJoint_SetMaxMotorForce($joint, 10.0);
    b2PrismaticJoint_EnableSpring($joint, false);
    b2PrismaticJoint_EnableLimit($joint, false);
    b2PrismaticJoint_EnableMotor($joint, false);
    b2PrismaticJoint_SetMotorSpeed($joint, 0.0);

    expect(b2PrismaticJoint_IsSpringEnabled($joint))->toBeFalse()
        ->and(b2PrismaticJoint_GetSpringHertz($joint))->toBe(2.0)
        ->and(b2PrismaticJoint_GetSpringDampingRatio($joint))->toBe(0.5)
        ->and(b2PrismaticJoint_GetTargetTranslation($joint))->toBe(0.25)
        ->and(b2PrismaticJoint_IsLimitEnabled($joint))->toBeFalse()
        ->and(b2PrismaticJoint_GetLowerLimit($joint))->toBe(-1.0)
        ->and(b2PrismaticJoint_GetUpperLimit($joint))->toBe(2.0)
        ->and(b2PrismaticJoint_IsMotorEnabled($joint))->toBeFalse()
        ->and(b2PrismaticJoint_GetMotorSpeed($joint))->toBe(0.0)
        ->and(b2PrismaticJoint_GetMaxMotorForce($joint))->toBe(10.0)
        ->and(b2PrismaticJoint_GetMotorForce($joint))->toBeFloat();

    b2Body_SetLinearVelocity($bodyB, new b2Vec2(2.0, -5.0));
    box2d_joint_steps($world, 30);
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near($position->y, 0.0, 0.05);
    expect(abs($position->x))->toBeGreaterThan(0.2);
    expect(abs(b2PrismaticJoint_GetTranslation($joint)))->toBeGreaterThan(0.2);
    expect(b2PrismaticJoint_GetSpeed($joint))->toBeFloat();

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});

it('holds a wheel joint on its axle', function (): void {
    $definition = b2DefaultWheelJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->enableSpring)->toBeTrue()
        ->and($definition->localAxisA->x)->toBe(0.0)
        ->and($definition->localAxisA->y)->toBe(1.0)
        ->and($definition->hertz)->toBe(1.0);
    box2d_expect_near($definition->dampingRatio, 0.7);

    $world = box2d_joint_world();
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 0.0, 0.0);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $definition->enableSpring = false;
    $joint = b2CreateWheelJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_wheelJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, true, false);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAxisA($joint, new b2Vec2(0.0, 1.0));

    b2WheelJoint_EnableSpring($joint, true);
    b2WheelJoint_SetSpringHertz($joint, 2.0);
    b2WheelJoint_SetSpringDampingRatio($joint, 0.5);
    b2WheelJoint_EnableLimit($joint, true);
    b2WheelJoint_SetLimits($joint, -1.0, 1.0);
    b2WheelJoint_EnableMotor($joint, true);
    b2WheelJoint_SetMotorSpeed($joint, 1.0);
    b2WheelJoint_SetMaxMotorTorque($joint, 8.0);
    b2WheelJoint_EnableSpring($joint, false);
    b2WheelJoint_EnableLimit($joint, false);
    b2WheelJoint_EnableMotor($joint, false);
    b2WheelJoint_SetMotorSpeed($joint, 0.0);

    expect(b2WheelJoint_IsSpringEnabled($joint))->toBeFalse()
        ->and(b2WheelJoint_GetSpringHertz($joint))->toBe(2.0)
        ->and(b2WheelJoint_GetSpringDampingRatio($joint))->toBe(0.5)
        ->and(b2WheelJoint_IsLimitEnabled($joint))->toBeFalse()
        ->and(b2WheelJoint_GetLowerLimit($joint))->toBe(-1.0)
        ->and(b2WheelJoint_GetUpperLimit($joint))->toBe(1.0)
        ->and(b2WheelJoint_IsMotorEnabled($joint))->toBeFalse()
        ->and(b2WheelJoint_GetMotorSpeed($joint))->toBe(0.0)
        ->and(b2WheelJoint_GetMaxMotorTorque($joint))->toBe(8.0)
        ->and(b2WheelJoint_GetMotorTorque($joint))->toBeFloat();

    b2Body_SetLinearVelocity($bodyB, new b2Vec2(4.0, -2.0));
    box2d_joint_steps($world, 30);
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near($position->x, 0.0, 0.05);
    expect(abs($position->y))->toBeGreaterThan(0.2);

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});

it('pulls a motor joint toward its offset', function (): void {
    $definition = b2DefaultMotorJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->maxForce)->toBe(1.0)
        ->and($definition->maxTorque)->toBe(1.0);
    box2d_expect_near($definition->correctionFactor, 0.3);

    $world = box2d_joint_world(false, false);
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0, false);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 0.0, 0.0, false);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $definition->linearOffset = new b2Vec2(1.0, 0.0);
    $definition->maxForce = 1000.0;
    $definition->maxTorque = 1000.0;
    $definition->correctionFactor = 1.0;
    $joint = b2CreateMotorJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_motorJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, false, false);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(0.0, 0.0));
    b2MotorJoint_SetLinearOffset($joint, new b2Vec2(1.0, 0.0));
    b2MotorJoint_SetAngularOffset($joint, 0.0);
    b2MotorJoint_SetMaxForce($joint, 1000.0);
    b2MotorJoint_SetMaxTorque($joint, 1000.0);
    b2MotorJoint_SetCorrectionFactor($joint, 1.0);

    $offset = b2MotorJoint_GetLinearOffset($joint);
    expect($offset->x)->toBe(1.0)
        ->and($offset->y)->toBe(0.0)
        ->and(b2MotorJoint_GetAngularOffset($joint))->toBe(0.0)
        ->and(b2MotorJoint_GetMaxForce($joint))->toBe(1000.0)
        ->and(b2MotorJoint_GetMaxTorque($joint))->toBe(1000.0)
        ->and(b2MotorJoint_GetCorrectionFactor($joint))->toBe(1.0);

    box2d_joint_steps($world, 180);
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near($position->x, 1.0, 0.05);
    box2d_expect_near($position->y, 0.0, 0.05);

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});

it('pulls a mouse joint toward its target', function (): void {
    $definition = b2DefaultMouseJointDef();
    expect($definition->internalValue)->toBe(1152023)
        ->and($definition->hertz)->toBe(4.0)
        ->and($definition->dampingRatio)->toBe(1.0)
        ->and($definition->maxForce)->toBe(1.0);

    $world = box2d_joint_world(false, false);
    $bodyA = box2d_joint_body($world, b2_staticBody, 0.0, 0.0, false);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 0.0, 3.0, false);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $definition->target = new b2Vec2(0.0, 3.0);
    $definition->maxForce = 2000.0;
    $definition->hertz = 5.0;
    $definition->dampingRatio = 0.7;
    $joint = b2CreateMouseJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_mouseJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, false, false);
    b2Joint_SetLocalAnchorA($joint, new b2Vec2(0.0, 0.0));
    b2Joint_SetLocalAnchorB($joint, new b2Vec2(0.0, 0.0));
    b2MouseJoint_SetTarget($joint, new b2Vec2(2.0, 3.0));
    b2MouseJoint_SetSpringHertz($joint, 5.0);
    b2MouseJoint_SetSpringDampingRatio($joint, 0.7);
    b2MouseJoint_SetMaxForce($joint, 2000.0);
    b2Joint_WakeBodies($joint);

    $target = b2MouseJoint_GetTarget($joint);
    expect($target->x)->toBe(2.0)
        ->and($target->y)->toBe(3.0)
        ->and(b2MouseJoint_GetSpringHertz($joint))->toBe(5.0)
        ->and(b2MouseJoint_GetMaxForce($joint))->toBe(2000.0);
    box2d_expect_near(b2MouseJoint_GetSpringDampingRatio($joint), 0.7);

    box2d_joint_steps($world, 180);
    $position = b2Body_GetPosition($bodyB);
    box2d_expect_near($position->x, 2.0, 0.05);
    box2d_expect_near($position->y, 3.0, 0.05);

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});

it('removes collisions with a filter joint', function (): void {
    $definition = b2DefaultFilterJointDef();
    expect($definition->internalValue)->toBe(1152023);

    $separated = box2d_joint_world(false);
    $left = box2d_joint_body($separated, b2_dynamicBody, 0.0, 0.0);
    $right = box2d_joint_body($separated, b2_dynamicBody, 0.0, 0.0);
    box2d_joint_steps($separated, 60);
    $apartA = b2Body_GetPosition($left);
    $apartB = b2Body_GetPosition($right);
    $apart = hypot($apartA->x - $apartB->x, $apartA->y - $apartB->y);
    b2DestroyWorld($separated);
    expect($apart)->toBeGreaterThan(0.5);

    $world = box2d_joint_world(false);
    $bodyA = box2d_joint_body($world, b2_dynamicBody, 0.0, 0.0);
    $bodyB = box2d_joint_body($world, b2_dynamicBody, 0.0, 0.0);
    $definition->bodyIdA = $bodyA;
    $definition->bodyIdB = $bodyB;
    $joint = b2CreateFilterJoint($world, $definition);

    expect(b2Joint_GetType($joint))->toBe(b2_filterJoint);
    box2d_joint_round_trip($joint, $world, $bodyA, $bodyB, false, false);
    box2d_joint_steps($world, 60);
    $positionA = b2Body_GetPosition($bodyA);
    $positionB = b2Body_GetPosition($bodyB);
    expect(hypot($positionA->x - $positionB->x, $positionA->y - $positionB->y))->toBeLessThan(0.1);

    b2DestroyJoint($joint);
    b2DestroyWorld($world);
});
