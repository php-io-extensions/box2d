<?php

declare(strict_types=1);

function box2d_event_world(): b2WorldId
{
    $definition = b2DefaultWorldDef();
    $definition->enableSleep = false;

    return b2CreateWorld($definition);
}

function box2d_event_ground(b2WorldId $world): b2ShapeId
{
    $body = b2CreateBody($world, b2DefaultBodyDef());
    $definition = b2DefaultShapeDef();
    $definition->enableContactEvents = true;
    $definition->enableHitEvents = true;
    $definition->enablePreSolveEvents = true;

    return b2CreatePolygonShape($body, $definition, b2MakeBox(20.0, 0.5));
}

function box2d_event_box(b2WorldId $world, float $x, float $y, int $userData = 0): b2BodyId
{
    $definition = b2DefaultBodyDef();
    $definition->type = b2_dynamicBody;
    $definition->position = new b2Vec2($x, $y);
    $definition->enableSleep = false;
    $definition->userData = $userData;
    $body = b2CreateBody($world, $definition);
    $shape = b2DefaultShapeDef();
    $shape->enableContactEvents = true;
    $shape->enableHitEvents = true;
    $shape->enablePreSolveEvents = true;
    b2CreatePolygonShape($body, $shape, b2MakeBox(0.5, 0.5));

    return $body;
}

it('copies contact, sensor, and body events that stay readable after the next step', function (): void {
    $world = box2d_event_world();
    b2World_SetHitEventThreshold($world, 0.0);
    box2d_event_ground($world);
    $box = box2d_event_box($world, 0.0, 0.95, 77);
    b2Body_SetLinearVelocity($box, new b2Vec2(0.0, -5.0));

    $sensorBody = b2CreateBody($world, b2DefaultBodyDef());
    $sensorDefinition = b2DefaultShapeDef();
    $sensorDefinition->isSensor = true;
    $sensorDefinition->enableSensorEvents = true;
    b2CreateCircleShape($sensorBody, $sensorDefinition, new b2Circle(new b2Vec2(6.0, 4.0), 1.0));
    $visitorDefinition = b2DefaultBodyDef();
    $visitorDefinition->type = b2_dynamicBody;
    $visitorDefinition->position = new b2Vec2(6.0, 4.0);
    $visitorDefinition->enableSleep = false;
    $visitor = b2CreateBody($world, $visitorDefinition);
    $visitorShape = b2DefaultShapeDef();
    $visitorShape->enableSensorEvents = true;
    b2CreateCircleShape($visitor, $visitorShape, new b2Circle(new b2Vec2(0.0, 0.0), 0.25));

    b2World_Step($world, 1.0 / 60.0, 4);

    $contacts = b2World_GetContactEvents($world);
    $sensors = b2World_GetSensorEvents($world);
    $moves = b2World_GetBodyEvents($world);

    expect($contacts->beginCount)->toBeGreaterThan(0)
        ->and($contacts->hitCount)->toBeGreaterThan(0)
        ->and($contacts->beginEvents)->toHaveCount($contacts->beginCount)
        ->and($contacts->hitEvents)->toHaveCount($contacts->hitCount)
        ->and($contacts->beginEvents[0])->toBeInstanceOf(b2ContactBeginTouchEvent::class)
        ->and($contacts->hitEvents[0])->toBeInstanceOf(b2ContactHitEvent::class)
        ->and($contacts->beginEvents[0]->manifold)->toBeInstanceOf(b2Manifold::class)
        ->and($sensors->beginCount)->toBeGreaterThan(0)
        ->and($sensors->beginEvents)->toHaveCount($sensors->beginCount)
        ->and($sensors->beginEvents[0]->sensorShapeId)->toBeInstanceOf(b2ShapeId::class)
        ->and($moves->moveCount)->toBeGreaterThan(0)
        ->and($moves->moveEvents)->toHaveCount($moves->moveCount);

    $moved = null;
    foreach ($moves->moveEvents as $event) {
        if (b2Body_IsValid($event->bodyId) && B2_ID_EQUALS($event->bodyId, $box)) {
            $moved = $event;
            break;
        }
    }
    expect($moved)->not->toBeNull()
        ->and($moved->userData)->toBe(77)
        ->and($moved->transform)->toBeInstanceOf(b2Transform::class)
        ->and($moved->fellAsleep)->toBeBool();

    $beginShape = $contacts->beginEvents[0]->shapeIdA;
    b2DestroyBody($box);
    b2World_Step($world, 1.0 / 60.0, 4);

    $after = b2World_GetContactEvents($world);
    expect($after->endCount)->toBeGreaterThan(0)
        ->and($contacts->beginEvents[0]->shapeIdA)->toBeInstanceOf(b2ShapeId::class)
        ->and($moved->transform->p)->toBeInstanceOf(b2Vec2::class)
        ->and(b2Body_IsValid($moved->bodyId))->toBeFalse()
        ->and($beginShape)->toBeInstanceOf(b2ShapeId::class);

    b2DestroyWorld($world);
});

it('reports overlaps, ray casts, shape casts, and mover planes', function (): void {
    $world = box2d_event_world();
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    $shape = b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(1.0, 0.5));
    $filter = b2DefaultQueryFilter();
    $seen = [];

    $stats = b2World_OverlapAABB(
        $world,
        new b2AABB(new b2Vec2(-2.0, -2.0), new b2Vec2(2.0, 2.0)),
        $filter,
        function (b2ShapeId $shapeId, mixed $context) use (&$seen): bool {
            $seen[] = [$shapeId, $context];

            return true;
        },
        'overlap',
    );
    expect($stats)->toBeInstanceOf(b2TreeStats::class)
        ->and($seen)->not->toBeEmpty()
        ->and($seen[0][1])->toBe('overlap')
        ->and(B2_ID_EQUALS($seen[0][0], $shape))->toBeTrue();

    $proxyHits = 0;
    b2World_OverlapShape(
        $world,
        b2MakeProxy([new b2Vec2(0.0, 0.0)], 1, 0.2),
        $filter,
        function (b2ShapeId $shapeId, mixed $context) use (&$proxyHits): bool {
            $proxyHits++;

            return true;
        },
        null,
    );
    expect($proxyHits)->toBeGreaterThan(0);

    $castHits = 0;
    b2World_CastRay(
        $world,
        new b2Vec2(0.0, 5.0),
        new b2Vec2(0.0, -10.0),
        $filter,
        function (b2ShapeId $shapeId, b2Vec2 $point, b2Vec2 $normal, float $fraction, mixed $context) use (&$castHits): float {
            expect($point)->toBeInstanceOf(b2Vec2::class)
                ->and($normal)->toBeInstanceOf(b2Vec2::class)
                ->and($fraction)->toBeGreaterThanOrEqual(0.0)
                ->and($context)->toBe('ray');
            $castHits++;

            return $fraction;
        },
        'ray',
    );
    expect($castHits)->toBeGreaterThan(0);

    $closest = b2World_CastRayClosest($world, new b2Vec2(0.0, 5.0), new b2Vec2(0.0, -10.0), $filter);
    expect($closest)->toBeInstanceOf(b2RayResult::class)
        ->and($closest->hit)->toBeTrue()
        ->and(B2_ID_EQUALS($closest->shapeId, $shape))->toBeTrue();

    $shapeHits = 0;
    b2World_CastShape(
        $world,
        b2MakeProxy([new b2Vec2(0.0, 3.0)], 1, 0.1),
        new b2Vec2(0.0, -6.0),
        $filter,
        function (b2ShapeId $shapeId, b2Vec2 $point, b2Vec2 $normal, float $fraction, mixed $context) use (&$shapeHits): float {
            $shapeHits++;

            return 1.0;
        },
        null,
    );
    expect($shapeHits)->toBeGreaterThan(0);

    $mover = new b2Capsule(new b2Vec2(0.0, 2.0), new b2Vec2(0.0, 2.5), 0.2);
    $fraction = b2World_CastMover($world, $mover, new b2Vec2(0.0, -4.0), $filter);
    expect($fraction)->toBeFloat()->toBeGreaterThanOrEqual(0.0);

    $planes = 0;
    b2World_CollideMover(
        $world,
        new b2Capsule(new b2Vec2(0.0, 0.6), new b2Vec2(0.0, 1.0), 0.2),
        $filter,
        function (b2ShapeId $shapeId, b2PlaneResult $plane, mixed $context) use (&$planes): bool {
            expect($plane->plane)->toBeInstanceOf(b2Plane::class)
                ->and($plane->point)->toBeInstanceOf(b2Vec2::class)
                ->and($context)->toBe('plane');
            $planes++;

            return true;
        },
        'plane',
    );
    expect($planes)->toBeGreaterThan(0);

    b2DestroyWorld($world);
});

it('writes a pre-solve manifold edit back onto the contact', function (): void {
    $world = box2d_event_world();
    $groundBody = b2CreateBody($world, b2DefaultBodyDef());
    $groundShape = b2DefaultShapeDef();
    $groundShape->enablePreSolveEvents = true;
    b2CreatePolygonShape($groundBody, $groundShape, b2MakeBox(5.0, 0.5));
    $box = box2d_event_box($world, 0.0, 0.6);
    $held = null;

    b2World_SetPreSolveCallback($world, function (b2ShapeId $shapeIdA, b2ShapeId $shapeIdB, b2Manifold $manifold, mixed $context) use (&$held): bool {
        expect($context)->toBe('pre');
        if ($manifold->pointCount > 0) {
            $manifold->normal = new b2Vec2(1.0, 0.0);
            $manifold->points[0]->normalImpulse = 42.0;
            $held = $manifold;
        }

        return true;
    }, 'pre');

    b2World_Step($world, 1.0 / 60.0, 4);
    expect($held)->toBeInstanceOf(b2Manifold::class)
        ->and($held->points[0]->normalImpulse)->toBe(42.0);

    $contacts = null;
    $count = b2Body_GetContactData($box, $contacts, 4);
    expect($count)->toBeGreaterThan(0)
        ->and($contacts[0]->manifold->normal->x)->toBe(1.0)
        ->and($contacts[0]->manifold->normal->y)->toBe(0.0);

    b2World_SetPreSolveCallback($world, null, null);
    b2DestroyWorld($world);
});

it('passes a custom filter context and can reject the pair', function (): void {
    $world = box2d_event_world();
    box2d_event_ground($world);
    box2d_event_box($world, 0.0, 0.6);
    $calls = 0;

    b2World_SetCustomFilterCallback($world, function (b2ShapeId $shapeIdA, b2ShapeId $shapeIdB, mixed $context) use (&$calls): bool {
        $calls++;
        expect($context)->toBe('filter');

        return false;
    }, 'filter');

    b2World_Step($world, 1.0 / 60.0, 4);
    $events = b2World_GetContactEvents($world);
    expect($calls)->toBeGreaterThan(0)
        ->and($events->beginCount)->toBe(0);

    b2DestroyWorld($world);
});
