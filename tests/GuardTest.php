<?php

declare(strict_types=1);

/**
 * Struct classes, conversion, id checks, and the world guards from phase 5.
 */

function box2d_struct_classes(): array
{
    return [
        'b2WorldId', 'b2BodyId', 'b2ShapeId', 'b2ChainId', 'b2JointId', 'b2Version',
        'b2RayCastInput', 'b2ShapeProxy', 'b2ShapeCastInput', 'b2CastOutput', 'b2MassData',
        'b2Circle', 'b2Capsule', 'b2Polygon', 'b2Segment', 'b2ChainSegment', 'b2Hull',
        'b2SegmentDistanceResult', 'b2SimplexCache', 'b2DistanceInput', 'b2DistanceOutput',
        'b2SimplexVertex', 'b2Simplex', 'b2ShapeCastPairInput', 'b2Sweep', 'b2TOIInput',
        'b2TOIOutput', 'b2ManifoldPoint', 'b2Manifold', 'b2DynamicTree', 'b2TreeStats',
        'b2PlaneResult', 'b2CollisionPlane', 'b2PlaneSolverResult', 'b2RayResult',
        'b2WorldDef', 'b2BodyDef', 'b2Filter', 'b2QueryFilter', 'b2SurfaceMaterial',
        'b2ShapeDef', 'b2ChainDef', 'b2Profile', 'b2Counters', 'b2DistanceJointDef',
        'b2MotorJointDef', 'b2MouseJointDef', 'b2FilterJointDef', 'b2PrismaticJointDef',
        'b2RevoluteJointDef', 'b2WeldJointDef', 'b2WheelJointDef', 'b2ExplosionDef',
        'b2SensorBeginTouchEvent', 'b2SensorEndTouchEvent', 'b2SensorEvents',
        'b2ContactBeginTouchEvent', 'b2ContactEndTouchEvent', 'b2ContactHitEvent',
        'b2ContactEvents', 'b2BodyMoveEvent', 'b2BodyEvents', 'b2ContactData', 'b2DebugDraw',
        'b2Vec2', 'b2CosSin', 'b2Rot', 'b2Transform', 'b2Mat22', 'b2AABB', 'b2Plane',
    ];
}

it('registers every struct class and the dynamic tree handle', function (): void {
    expect(box2d_struct_classes())->toHaveCount(71);

    foreach (box2d_struct_classes() as $class) {
        expect(class_exists($class))->toBeTrue()
            ->and((new ReflectionClass($class))->isFinal())->toBeTrue();
    }
});

it('gives b2DynamicTree no properties and no public constructor', function (): void {
    $class = new ReflectionClass(b2DynamicTree::class);

    expect($class->getProperties())->toBe([])
        ->and(fn () => new b2DynamicTree())->toThrow(Error::class);
});

it('keeps b2WorldDef field order and drops the task callbacks', function (): void {
    $names = array_map(
        static fn (ReflectionProperty $property): string => $property->getName(),
        (new ReflectionClass(b2WorldDef::class))->getProperties(),
    );

    expect($names)->toBe([
        'gravity',
        'restitutionThreshold',
        'hitEventThreshold',
        'contactHertz',
        'contactDampingRatio',
        'maxContactPushSpeed',
        'maximumLinearSpeed',
        'frictionCallback',
        'restitutionCallback',
        'enableSleep',
        'enableContinuous',
        'workerCount',
        'userData',
        'internalValue',
    ])
        ->and($names)->not->toContain('enqueueTask', 'finishTask', 'userTaskContext');
});

it('zero-initializes a vector and a nested transform', function (): void {
    $vector = new b2Vec2();
    $transform = new b2Transform();

    expect($vector->x)->toBe(0.0)
        ->and($vector->y)->toBe(0.0)
        ->and($transform->p)->toBeInstanceOf(b2Vec2::class)
        ->and($transform->p->x)->toBe(0.0)
        ->and($transform->p->y)->toBe(0.0)
        ->and($transform->q)->toBeInstanceOf(b2Rot::class)
        ->and($transform->q->c)->toBe(0.0)
        ->and($transform->q->s)->toBe(0.0);
});

it('deep-copies nested structs when cloned', function (): void {
    $transform = new b2Transform(new b2Vec2(1.0, 2.0), new b2Rot(3.0, 4.0));
    $copy = clone $transform;
    $copy->p->x = 9.0;

    $polygon = new b2Polygon([new b2Vec2(1.0, 2.0)], [new b2Vec2(0.0, 1.0)], new b2Vec2(), 0.0, 1);
    $polygonCopy = clone $polygon;
    $polygonCopy->vertices[0]->x = 8.0;

    expect($transform->p->x)->toBe(1.0)
        ->and($copy->p->x)->toBe(9.0)
        ->and($copy->q)->not->toBe($transform->q)
        ->and($polygon->vertices[0]->x)->toBe(1.0)
        ->and($polygonCopy->vertices[0]->x)->toBe(8.0);
});

it('rejects a uint8_t field of 256', function (): void {
    expect(fn () => new b2SimplexCache(0, [256, 0, 0], [0, 0, 0]))
        ->toThrow(ValueError::class, 'uint8');
});

it('rejects a uint8_t field of -1', function (): void {
    expect(fn () => new b2SimplexCache(0, [-1, 0, 0], [0, 0, 0]))
        ->toThrow(ValueError::class, 'uint8');
});

it('rejects a uint8 list shorter than its fixed length', function (): void {
    expect(fn () => new b2SimplexCache(0, [1, 2], [0, 0, 0]))
        ->toThrow(ValueError::class);
});

it('accepts a simplex cache whose uint8 indices fit', function (): void {
    $cache = new b2SimplexCache(1, [1, 2, 255], [0, 4, 8]);

    expect($cache->count)->toBe(1)
        ->and($cache->indexA)->toBe([1, 2, 255])
        ->and($cache->indexB)->toBe([0, 4, 8]);
});

it('rejects narrow integers that do not fit their C type', function (string $class, array $args): void {
    expect(fn () => new $class(...$args))->toThrow(ValueError::class);
})->with([
    'world index above uint16' => ['b2WorldId', [65536, 0]],
    'world index negative' => ['b2WorldId', [-1, 0]],
    'body index above int32' => ['b2BodyId', [2147483648, 0, 0]],
    'body index below int32' => ['b2BodyId', [-2147483649, 0, 0]],
    'surface color above uint32' => ['b2SurfaceMaterial', [0.0, 0.0, 0.0, 0.0, 0, 4294967296]],
    'surface color negative' => ['b2SurfaceMaterial', [0.0, 0.0, 0.0, 0.0, 0, -1]],
    'simplex count above uint16' => ['b2SimplexCache', [65536, [0, 0, 0], [0, 0, 0]]],
]);

it('stores the full uint32 range in customColor', function (): void {
    $material = new b2SurfaceMaterial(0.0, 0.0, 0.0, 0.0, 0, 4294967295);

    expect($material->customColor)->toBe(4294967295);
});

it('rejects a list shorter than the struct count', function (): void {
    expect(fn () => new b2Polygon(
        vertices: [new b2Vec2()],
        normals: [],
        centroid: new b2Vec2(),
        radius: 0.0,
        count: 2,
    ))->toThrow(ValueError::class);
});

it('rejects a polygon count above B2_MAX_POLYGON_VERTICES', function (): void {
    $points = array_fill(0, 9, new b2Vec2());

    expect(fn () => new b2Polygon($points, $points, new b2Vec2(), 0.0, 9))
        ->toThrow(ValueError::class);
});

it('rejects a manifold pointCount above 2', function (): void {
    $point = new b2ManifoldPoint();

    expect(fn () => new b2Manifold(new b2Vec2(), 0.0, [$point, $point, $point], 3))
        ->toThrow(ValueError::class);
});

it('writes colorCounts at full length', function (): void {
    $counters = new b2Counters();

    expect($counters->colorCounts)->toBe([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
});

it('keeps def internalValue public', function (): void {
    $definition = new b2BodyDef();

    expect($definition->internalValue)->toBe(0)
        ->and($definition->name)->toBeNull()
        ->and($definition->userData)->toBe(0);
});

it('throws ValueError when B2_ID_EQUALS is given two b2WorldId values', function (): void {
    expect(fn () => B2_ID_EQUALS(new b2WorldId(1, 1), new b2WorldId(1, 1)))
        ->toThrow(ValueError::class, 'b2WorldId');
});

it('rejects a destroyed body id before Box2D runs', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    b2DestroyBody($body);

    expect(fn () => b2Body_GetPosition($body))
        ->toThrow(ValueError::class, 'b2BodyId is not a live body');
    expect(b2Body_IsValid($body))->toBeFalse();

    b2DestroyWorld($world);
});

it('rejects a body definition whose cookie is not the Box2D secret', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $definition = new b2BodyDef();

    expect(fn () => b2CreateBody($world, $definition))->toThrow(ValueError::class, 'internalValue');
    expect(b2World_GetCounters($world)->bodyCount)->toBe(0);

    b2DestroyWorld($world);
});

it('rejects a body name longer than 31 characters and keeps the previous name', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    b2Body_SetName($body, 'short');

    expect(fn () => b2Body_SetName($body, str_repeat('a', 32)))
        ->toThrow(ValueError::class, '31');
    expect(b2Body_GetName($body))->toBe('short');
    expect(fn () => b2Body_SetName($body, str_repeat('b', 31)))->not->toThrow(ValueError::class);
    expect(b2Body_GetName($body))->toBe(str_repeat('b', 31));

    b2DestroyWorld($world);
});

it('rejects a chain count that is longer than the point list', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    $definition = b2DefaultChainDef();
    $definition->points = [new b2Vec2(0.0, 0.0), new b2Vec2(1.0, 0.0), new b2Vec2(1.0, 1.0), new b2Vec2(0.0, 1.0)];
    $definition->count = 5;

    expect(fn () => b2CreateChain($body, $definition))
        ->toThrow(ValueError::class, 'shorter than count');
    expect(b2Body_GetShapeCount($body))->toBe(0);

    b2DestroyWorld($world);
});

it('blocks a setter during a step and allows the user-data getters', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    b2World_SetUserData($world, 22);
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(5.0, 0.5));
    $boxDefinition = b2DefaultBodyDef();
    $boxDefinition->type = b2_dynamicBody;
    $boxDefinition->position = new b2Vec2(0.0, 0.2);
    $box = b2CreateBody($world, $boxDefinition);
    b2Body_SetUserData($box, 11);
    b2CreatePolygonShape($box, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    $ran = false;
    b2World_SetFrictionCallback($world, function (float $frictionA, int $userMaterialIdA, float $frictionB, int $userMaterialIdB) use (&$ran, $world, $box): float {
        expect(fn () => b2Body_SetAwake($box, true))->toThrow(Error::class, 'world is stepping');
        expect(b2Body_GetUserData($box))->toBe(11);
        expect(b2World_GetUserData($world))->toBe(22);
        $ran = true;

        return sqrt($frictionA * $frictionB);
    });

    b2World_Step($world, 1.0 / 60.0, 4);
    expect($ran)->toBeTrue();

    b2DestroyWorld($world);
});

it('rethrows a nested step from a friction callback and keeps the world', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(5.0, 0.5));
    $boxDefinition = b2DefaultBodyDef();
    $boxDefinition->type = b2_dynamicBody;
    $boxDefinition->position = new b2Vec2(0.0, 0.2);
    $box = b2CreateBody($world, $boxDefinition);
    b2CreatePolygonShape($box, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    b2World_SetFrictionCallback($world, function (float $frictionA, int $userMaterialIdA, float $frictionB, int $userMaterialIdB) use ($world): float {
        b2World_Step($world, 1.0 / 60.0, 4);

        return sqrt($frictionA * $frictionB);
    });

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(Error::class, 'world is stepping');
    expect(b2World_IsValid($world))->toBeTrue();

    b2DestroyWorld($world);
});

it('rethrows a nested destroy from a friction callback and keeps the world', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(5.0, 0.5));
    $boxDefinition = b2DefaultBodyDef();
    $boxDefinition->type = b2_dynamicBody;
    $boxDefinition->position = new b2Vec2(0.0, 0.2);
    $box = b2CreateBody($world, $boxDefinition);
    b2CreatePolygonShape($box, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    b2World_SetFrictionCallback($world, function (float $frictionA, int $userMaterialIdA, float $frictionB, int $userMaterialIdB) use ($world): float {
        b2DestroyWorld($world);

        return sqrt($frictionA * $frictionB);
    });

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(Error::class, 'world is stepping');
    expect(b2World_IsValid($world))->toBeTrue();

    b2DestroyWorld($world);
});

it('compares body ids by index, world, and generation', function (): void {
    $body = new b2BodyId(4, 1, 9);

    expect(B2_ID_EQUALS($body, new b2BodyId(4, 1, 9)))->toBeTrue()
        ->and(B2_ID_EQUALS($body, new b2BodyId(4, 1, 8)))->toBeFalse()
        ->and(B2_IS_NULL(new b2BodyId()))->toBeTrue()
        ->and(B2_IS_NON_NULL($body))->toBeTrue()
        ->and(fn () => B2_ID_EQUALS($body, new b2ShapeId(4, 1, 9)))->toThrow(ValueError::class);
});
