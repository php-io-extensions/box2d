<?php

declare(strict_types=1);

it('round-trips the default shape definition', function (): void {
    $definition = b2DefaultShapeDef();
    $filter = b2DefaultFilter();
    $query = b2DefaultQueryFilter();
    $material = b2DefaultSurfaceMaterial();

    expect($definition->userData)->toBe(0)
        ->and($definition->density)->toBe(1.0)
        ->and($definition->isSensor)->toBeFalse()
        ->and($definition->enableSensorEvents)->toBeFalse()
        ->and($definition->enableContactEvents)->toBeFalse()
        ->and($definition->enableHitEvents)->toBeFalse()
        ->and($definition->enablePreSolveEvents)->toBeFalse()
        ->and($definition->invokeContactCreation)->toBeTrue()
        ->and($definition->updateBodyMass)->toBeTrue()
        ->and($definition->internalValue)->toBe(1152023)
        ->and($definition->filter->categoryBits)->toBe(B2_DEFAULT_CATEGORY_BITS)
        ->and($definition->filter->maskBits)->toBe(-1)
        ->and($definition->filter->groupIndex)->toBe(0)
        ->and($filter->categoryBits)->toBe(1)
        ->and($filter->maskBits)->toBe(-1)
        ->and($query->categoryBits)->toBe(1)
        ->and($query->maskBits)->toBe(-1);
    box2d_expect_near($definition->material->friction, 0.6);
    box2d_expect_near($material->friction, 0.6);
});

it('calls every shape function and returns the ids that were created', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $bodyDefinition = b2DefaultBodyDef();
    $bodyDefinition->type = b2_dynamicBody;
    $body = b2CreateBody($world, $bodyDefinition);

    $definition = b2DefaultShapeDef();
    $definition->userData = 5;
    $definition->density = 2.0;
    $circle = b2CreateCircleShape($body, $definition, new b2Circle(new b2Vec2(0.0, 0.0), 1.0));
    $segment = b2CreateSegmentShape($body, b2DefaultShapeDef(), new b2Segment(new b2Vec2(-1.0, 0.0), new b2Vec2(1.0, 0.0)));
    $capsule = b2CreateCapsuleShape($body, b2DefaultShapeDef(), new b2Capsule(new b2Vec2(0.0, -0.5), new b2Vec2(0.0, 0.5), 0.25));
    $polygon = b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    expect(b2Shape_IsValid($circle))->toBeTrue()
        ->and(b2Shape_GetType($circle))->toBe(b2_circleShape)
        ->and(b2Shape_GetType($segment))->toBe(b2_segmentShape)
        ->and(b2Shape_GetType($capsule))->toBe(b2_capsuleShape)
        ->and(b2Shape_GetType($polygon))->toBe(b2_polygonShape)
        ->and(B2_ID_EQUALS(b2Shape_GetBody($circle), $body))->toBeTrue()
        ->and(b2Shape_GetWorld($circle)->index1)->toBe($world->index1)
        ->and(b2Shape_IsSensor($circle))->toBeFalse()
        ->and(b2Shape_GetUserData($circle))->toBe(5)
        ->and(b2Shape_GetDensity($circle))->toBe(2.0)
        ->and(B2_IS_NULL(b2Shape_GetParentChain($circle)))->toBeTrue();

    $readCircle = b2Shape_GetCircle($circle);
    $readSegment = b2Shape_GetSegment($segment);
    $readCapsule = b2Shape_GetCapsule($capsule);
    $readPolygon = b2Shape_GetPolygon($polygon);
    expect($readCircle->radius)->toBe(1.0)
        ->and($readSegment->point1->x)->toBe(-1.0)
        ->and($readCapsule->radius)->toBe(0.25)
        ->and($readPolygon->count)->toBe(4);

    b2Shape_SetUserData($circle, 9);
    b2Shape_SetDensity($circle, 3.0, true);
    b2Shape_SetFriction($circle, 0.25);
    b2Shape_SetRestitution($circle, 0.5);
    b2Shape_SetMaterial($circle, 7);
    $surface = b2DefaultSurfaceMaterial();
    $surface->friction = 0.25;
    $surface->restitution = 0.5;
    $surface->userMaterialId = 7;
    b2Shape_SetSurfaceMaterial($circle, $surface);
    $filter = b2DefaultFilter();
    $filter->categoryBits = 2;
    $filter->maskBits = 4;
    $filter->groupIndex = -1;
    b2Shape_SetFilter($circle, $filter);
    b2Shape_EnableSensorEvents($circle, true);
    b2Shape_EnableContactEvents($circle, true);
    b2Shape_EnablePreSolveEvents($circle, true);
    b2Shape_EnableHitEvents($circle, true);

    $storedFilter = b2Shape_GetFilter($circle);
    $storedSurface = b2Shape_GetSurfaceMaterial($circle);
    expect(b2Shape_GetUserData($circle))->toBe(9)
        ->and(b2Shape_GetDensity($circle))->toBe(3.0)
        ->and(b2Shape_GetFriction($circle))->toBe(0.25)
        ->and(b2Shape_GetRestitution($circle))->toBe(0.5)
        ->and(b2Shape_GetMaterial($circle))->toBe(7)
        ->and($storedSurface->userMaterialId)->toBe(7)
        ->and($storedFilter->categoryBits)->toBe(2)
        ->and($storedFilter->maskBits)->toBe(4)
        ->and($storedFilter->groupIndex)->toBe(-1)
        ->and(b2Shape_AreSensorEventsEnabled($circle))->toBeTrue()
        ->and(b2Shape_AreContactEventsEnabled($circle))->toBeTrue()
        ->and(b2Shape_ArePreSolveEventsEnabled($circle))->toBeTrue()
        ->and(b2Shape_AreHitEventsEnabled($circle))->toBeTrue()
        ->and(b2Shape_TestPoint($circle, new b2Vec2(0.0, 0.0)))->toBeTrue()
        ->and(b2Shape_TestPoint($circle, new b2Vec2(5.0, 0.0)))->toBeFalse();

    $cast = b2Shape_RayCast($circle, new b2RayCastInput(new b2Vec2(-2.0, 0.0), new b2Vec2(4.0, 0.0), 1.0));
    expect($cast->hit)->toBeTrue();

    b2Shape_SetCircle($circle, new b2Circle(new b2Vec2(0.25, 0.0), 0.5));
    expect(b2Shape_GetCircle($circle)->radius)->toBe(0.5);
    b2Shape_SetCapsule($capsule, new b2Capsule(new b2Vec2(0.0, -1.0), new b2Vec2(0.0, 1.0), 0.5));
    expect(b2Shape_GetCapsule($capsule)->radius)->toBe(0.5);
    b2Shape_SetSegment($segment, new b2Segment(new b2Vec2(0.0, 0.0), new b2Vec2(2.0, 0.0)));
    expect(b2Shape_GetSegment($segment)->point2->x)->toBe(2.0);
    b2Shape_SetPolygon($polygon, b2MakeSquare(1.0));
    expect(b2Shape_GetPolygon($polygon)->count)->toBe(4);

    $closest = b2Shape_GetClosestPoint($circle, new b2Vec2(3.0, 0.0));
    $bounds = b2Shape_GetAABB($circle);
    $mass = b2Shape_GetMassData($circle);
    expect($closest->x)->toBeGreaterThan(0.0)
        ->and($bounds->upperBound->x)->toBeGreaterThan($bounds->lowerBound->x)
        ->and($mass->mass)->toBeGreaterThan(0.0);

    $chainDefinition = b2DefaultChainDef();
    $chainDefinition->points = [new b2Vec2(0.0, 0.0), new b2Vec2(1.0, 0.0), new b2Vec2(1.0, 1.0), new b2Vec2(0.0, 1.0)];
    $chainDefinition->count = 4;
    $chainDefinition->isLoop = true;
    $chain = b2CreateChain($body, $chainDefinition);
    $segments = null;
    $segmentCount = b2Chain_GetSegments($chain, $segments, 8);
    expect($segmentCount)->toBeGreaterThan(0)
        ->and(b2Shape_GetType($segments[0]))->toBe(b2_chainSegmentShape)
        ->and(b2Shape_GetChainSegment($segments[0]))->toBeInstanceOf(b2ChainSegment::class)
        ->and(B2_ID_EQUALS(b2Shape_GetParentChain($segments[0]), $chain))->toBeTrue();

    $sensorDefinition = b2DefaultShapeDef();
    $sensorDefinition->isSensor = true;
    $sensorDefinition->enableSensorEvents = true;
    $sensor = b2CreateCircleShape($body, $sensorDefinition, new b2Circle(new b2Vec2(6.0, 0.0), 1.0));
    $visitorDefinition = b2DefaultBodyDef();
    $visitorDefinition->type = b2_dynamicBody;
    $visitorDefinition->position = new b2Vec2(6.0, 0.0);
    $visitor = b2CreateBody($world, $visitorDefinition);
    $visitorShapeDefinition = b2DefaultShapeDef();
    $visitorShapeDefinition->enableSensorEvents = true;
    $visitorShape = b2CreateCircleShape($visitor, $visitorShapeDefinition, new b2Circle(new b2Vec2(0.0, 0.0), 0.25));
    b2World_Step($world, 1.0 / 60.0, 4);

    $overlaps = null;
    $overlapCount = b2Shape_GetSensorOverlaps($sensor, $overlaps, b2Shape_GetSensorCapacity($sensor));
    expect($overlapCount)->toBe(1)
        ->and(B2_ID_EQUALS($overlaps[0], $visitorShape))->toBeTrue();

    $solid = b2CreatePolygonShape($visitor, b2DefaultShapeDef(), b2MakeBox(0.2, 0.2));
    b2Body_SetTransform($visitor, new b2Vec2(0.0, 0.0), b2Rot_identity());
    b2World_Step($world, 1.0 / 60.0, 4);
    $contacts = null;
    $contactCount = b2Shape_GetContactData($polygon, $contacts, b2Shape_GetContactCapacity($polygon));
    expect($contactCount)->toBeGreaterThan(0)
        ->and($contacts[0]->shapeIdA)->toBeInstanceOf(b2ShapeId::class);

    b2DestroyShape($segment, true);
    expect(b2Shape_IsValid($segment))->toBeFalse()
        ->and(b2Shape_IsValid($circle))->toBeTrue()
        ->and(b2Shape_IsValid($solid))->toBeTrue();

    b2DestroyWorld($world);
});
