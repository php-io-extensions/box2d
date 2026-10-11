<?php

declare(strict_types=1);

it('round-trips the default body definition', function (): void {
    $definition = b2DefaultBodyDef();

    expect($definition->type)->toBe(b2_staticBody)
        ->and($definition->position->x)->toBe(0.0)
        ->and($definition->position->y)->toBe(0.0)
        ->and($definition->rotation->c)->toBe(1.0)
        ->and($definition->rotation->s)->toBe(0.0)
        ->and($definition->linearVelocity->x)->toBe(0.0)
        ->and($definition->angularVelocity)->toBe(0.0)
        ->and($definition->linearDamping)->toBe(0.0)
        ->and($definition->angularDamping)->toBe(0.0)
        ->and($definition->gravityScale)->toBe(1.0)
        ->and($definition->name)->toBeNull()
        ->and($definition->userData)->toBe(0)
        ->and($definition->enableSleep)->toBeTrue()
        ->and($definition->isAwake)->toBeTrue()
        ->and($definition->fixedRotation)->toBeFalse()
        ->and($definition->isBullet)->toBeFalse()
        ->and($definition->isEnabled)->toBeTrue()
        ->and($definition->allowFastRotation)->toBeFalse()
        ->and($definition->internalValue)->toBe(1152023);
    box2d_expect_near($definition->sleepThreshold, 0.05);
});

it('calls every body function and returns the shapes, joints, and contacts that were created', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $definition = b2DefaultBodyDef();
    $definition->type = b2_dynamicBody;
    $definition->position = new b2Vec2(1.0, 2.0);
    $definition->name = 'crate';
    $definition->userData = 7;
    $body = b2CreateBody($world, $definition);
    $shape = b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    expect(b2Body_IsValid($body))->toBeTrue()
        ->and(b2Body_GetType($body))->toBe(b2_dynamicBody)
        ->and(b2Body_GetName($body))->toBe('crate')
        ->and(b2Body_GetUserData($body))->toBe(7)
        ->and(b2Body_GetWorld($body)->index1)->toBe($world->index1)
        ->and(b2Body_GetWorld($body)->generation)->toBe($world->generation);

    $position = b2Body_GetPosition($body);
    $rotation = b2Body_GetRotation($body);
    expect($position->x)->toBe(1.0)
        ->and($position->y)->toBe(2.0)
        ->and($rotation->c)->toBe(1.0)
        ->and($rotation->s)->toBe(0.0);

    b2Body_SetName($body, 'renamed');
    b2Body_SetUserData($body, 8);
    b2Body_SetTransform($body, new b2Vec2(3.0, 4.0), b2MakeRot(0.0));
    b2Body_SetLinearVelocity($body, new b2Vec2(0.25, 0.0));
    b2Body_SetAngularVelocity($body, 0.5);
    $angular = b2Body_GetAngularVelocity($body);
    b2Body_SetLinearDamping($body, 0.25);
    b2Body_SetAngularDamping($body, 0.5);
    b2Body_SetGravityScale($body, 0.5);
    b2Body_SetAwake($body, true);
    b2Body_EnableSleep($body, false);
    b2Body_SetSleepThreshold($body, 0.25);
    b2Body_SetFixedRotation($body, true);
    b2Body_SetBullet($body, true);
    b2Body_EnableContactEvents($body, true);
    b2Body_EnableHitEvents($body, true);

    $moved = b2Body_GetPosition($body);
    $local = b2Body_GetLocalPoint($body, new b2Vec2(4.0, 4.0));
    $worldPoint = b2Body_GetWorldPoint($body, new b2Vec2(1.0, 0.0));
    $localVector = b2Body_GetLocalVector($body, new b2Vec2(0.0, 1.0));
    $worldVector = b2Body_GetWorldVector($body, new b2Vec2(1.0, 0.0));
    $linear = b2Body_GetLinearVelocity($body);
    $mass = b2Body_GetMassData($body);
    $center = b2Body_GetLocalCenterOfMass($body);

    expect(b2Body_GetName($body))->toBe('renamed')
        ->and(b2Body_GetUserData($body))->toBe(8)
        ->and($moved->x)->toBe(3.0)
        ->and($moved->y)->toBe(4.0)
        ->and($local->x)->toBe(1.0)
        ->and($worldPoint->x)->toBe(4.0)
        ->and($worldPoint->y)->toBe(4.0)
        ->and($localVector->y)->toBe(1.0)
        ->and($worldVector->x)->toBe(1.0)
        ->and($linear->x)->toBe(0.25)
        ->and($angular)->toBe(0.5)
        ->and(b2Body_GetLinearDamping($body))->toBe(0.25)
        ->and(b2Body_GetAngularDamping($body))->toBe(0.5)
        ->and(b2Body_GetGravityScale($body))->toBe(0.5)
        ->and(b2Body_IsAwake($body))->toBeTrue()
        ->and(b2Body_IsSleepEnabled($body))->toBeFalse()
        ->and(b2Body_GetSleepThreshold($body))->toBe(0.25)
        ->and(b2Body_IsEnabled($body))->toBeTrue()
        ->and(b2Body_IsFixedRotation($body))->toBeTrue()
        ->and(b2Body_IsBullet($body))->toBeTrue()
        ->and(b2Body_GetType($body))->toBe(b2_dynamicBody)
        ->and(b2Body_GetMass($body))->toBe(1.0)
        ->and($mass->mass)->toBe(1.0)
        ->and($center->x)->toBe(0.0)
        ->and(b2Body_GetShapeCount($body))->toBe(1);

    box2d_expect_near(b2Body_GetRotationalInertia($body), 0.0, 1.0e-3);
    $pointVelocity = b2Body_GetLocalPointVelocity($body, new b2Vec2(0.0, 0.0));
    $worldVelocity = b2Body_GetWorldPointVelocity($body, new b2Vec2(3.0, 4.0));
    expect($pointVelocity)->toBeInstanceOf(b2Vec2::class)
        ->and($worldVelocity)->toBeInstanceOf(b2Vec2::class);

    b2Body_SetType($body, b2_kinematicBody);
    b2Body_SetTargetTransform($body, new b2Transform(new b2Vec2(3.0, 4.0), b2Rot_identity()), 1.0 / 60.0);
    expect(b2Body_GetType($body))->toBe(b2_kinematicBody);
    b2Body_SetType($body, b2_dynamicBody);
    b2Body_SetFixedRotation($body, false);
    b2Body_SetAwake($body, true);
    b2Body_ApplyForce($body, new b2Vec2(1.0, 0.0), new b2Vec2(3.0, 4.0), true);
    b2Body_ApplyForceToCenter($body, new b2Vec2(0.0, 1.0), true);
    b2Body_ApplyTorque($body, 0.25, true);
    b2Body_ApplyLinearImpulse($body, new b2Vec2(0.1, 0.0), new b2Vec2(3.0, 4.0), true);
    b2Body_ApplyLinearImpulseToCenter($body, new b2Vec2(0.0, 0.1), true);
    b2Body_ApplyAngularImpulse($body, 0.1, true);
    b2Body_SetMassData($body, new b2MassData(2.0, new b2Vec2(0.0, 0.0), 1.0));
    expect(b2Body_GetMass($body))->toBe(2.0);
    b2Body_ApplyMassFromShapes($body);
    expect(b2Body_GetMass($body))->toBe(1.0);

    $transform = b2Body_GetTransform($body);
    expect($transform->p->x)->toBe(3.0)
        ->and($transform->q)->toBeInstanceOf(b2Rot::class);

    $shapes = null;
    expect(fn () => b2Body_GetShapes($body, $shapes, -1))->toThrow(ValueError::class);
    expect($shapes)->toBeNull();
    $count = b2Body_GetShapes($body, $shapes, 4);
    expect($count)->toBe(1)
        ->and($shapes)->toHaveCount(1)
        ->and(B2_ID_EQUALS($shapes[0], $shape))->toBeTrue();

    $other = b2DefaultBodyDef();
    $other->position = new b2Vec2(3.0, 4.0);
    $anchor = b2CreateBody($world, $other);
    b2CreatePolygonShape($anchor, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));
    $jointDefinition = b2DefaultDistanceJointDef();
    $jointDefinition->bodyIdA = $anchor;
    $jointDefinition->bodyIdB = $body;
    $jointDefinition->length = 1.0;
    $joint = b2CreateDistanceJoint($world, $jointDefinition);
    $joints = null;
    expect(b2Body_GetJointCount($body))->toBe(1)
        ->and(b2Body_GetJoints($body, $joints, 4))->toBe(1)
        ->and(B2_ID_EQUALS($joints[0], $joint))->toBeTrue();

    $touchDefinition = b2DefaultBodyDef();
    $touchDefinition->position = new b2Vec2(0.0, 0.0);
    $touch = b2CreateBody($world, $touchDefinition);
    b2CreatePolygonShape($touch, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));
    b2Body_SetLinearVelocity($body, new b2Vec2(0.0, 0.0));
    b2Body_SetAngularVelocity($body, 0.0);
    b2Body_SetTransform($body, new b2Vec2(0.0, 0.0), b2Rot_identity());
    b2Body_SetAwake($body, true);
    b2World_Step($world, 1.0 / 60.0, 4);
    $contacts = null;
    $contactCount = b2Body_GetContactData($body, $contacts, b2Body_GetContactCapacity($body));
    expect($contactCount)->toBeGreaterThan(0)
        ->and($contacts)->toHaveCount($contactCount)
        ->and($contacts[0])->toBeInstanceOf(b2ContactData::class);

    $bounds = b2Body_ComputeAABB($body);
    expect($bounds)->toBeInstanceOf(b2AABB::class)
        ->and($bounds->upperBound->x)->toBeGreaterThan($bounds->lowerBound->x);

    $worldCenter = b2Body_GetWorldCenterOfMass($body);
    box2d_expect_near($worldCenter->x, b2Body_GetPosition($body)->x);
    box2d_expect_near($worldCenter->y, b2Body_GetPosition($body)->y);

    b2Body_Disable($touch);
    expect(b2Body_IsEnabled($touch))->toBeFalse();
    b2Body_Enable($touch);
    expect(b2Body_IsEnabled($touch))->toBeTrue();

    b2Body_SetName($body, null);
    expect(b2Body_GetName($body))->toBe('');

    b2DestroyBody($body);
    expect(b2Body_IsValid($body))->toBeFalse();
    b2DestroyWorld($world);
});
