<?php

declare(strict_types=1);

function box2d_dynamic_box(b2WorldId $world, float $x, float $y): b2BodyId
{
    $definition = b2DefaultBodyDef();
    $definition->type = b2_dynamicBody;
    $definition->position = new b2Vec2($x, $y);
    $body = b2CreateBody($world, $definition);
    b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    return $body;
}

it('round-trips b2DefaultWorldDef field by field', function (): void {
    $definition = b2DefaultWorldDef();

    expect($definition->gravity->x)->toBe(0.0)
        ->and($definition->gravity->y)->toBe(-10.0)
        ->and($definition->restitutionThreshold)->toBe(1.0)
        ->and($definition->hitEventThreshold)->toBe(1.0)
        ->and($definition->contactHertz)->toBe(30.0)
        ->and($definition->contactDampingRatio)->toBe(10.0)
        ->and($definition->maxContactPushSpeed)->toBe(3.0)
        ->and($definition->maximumLinearSpeed)->toBe(400.0)
        ->and($definition->frictionCallback)->toBeNull()
        ->and($definition->restitutionCallback)->toBeNull()
        ->and($definition->enableSleep)->toBeTrue()
        ->and($definition->enableContinuous)->toBeTrue()
        ->and($definition->workerCount)->toBe(0)
        ->and($definition->userData)->toBe(0)
        ->and($definition->internalValue)->toBe(1152023);
});

it('lands a dynamic box on static ground', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(20.0, 0.5));
    b2Body_SetTransform($ground, new b2Vec2(0.0, -0.5), b2Rot_identity());
    $box = box2d_dynamic_box($world, 0.0, 4.0);

    for ($step = 0; $step < 180; $step++) {
        b2World_Step($world, 1.0 / 60.0, 4);
    }

    $position = b2Body_GetPosition($box);
    $velocity = b2Body_GetLinearVelocity($box);

    expect($position->y)->toBeGreaterThan(0.45)
        ->and($position->y)->toBeLessThan(0.55)
        ->and(abs($velocity->x))->toBeLessThan(0.01)
        ->and(abs($velocity->y))->toBeLessThan(0.01)
        ->and(b2Body_IsAwake($box))->toBeFalse();

    b2DestroyWorld($world);
    expect(b2World_IsValid($world))->toBeFalse();
});

it('stores every world setter and reads profile, counters, and the memory dump', function (): void {
    $dump = getcwd().'/box2d_memory.txt';
    if (is_file($dump)) {
        unlink($dump);
    }

    try {
        $world = b2CreateWorld(b2DefaultWorldDef());
        $ground = b2CreateBody($world, b2DefaultBodyDef());
        b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(10.0, 0.5));
        box2d_dynamic_box($world, 0.0, 2.0);
        b2World_Step($world, 1.0 / 60.0, 4);

        b2World_EnableSleeping($world, false);
        b2World_EnableContinuous($world, false);
        b2World_SetRestitutionThreshold($world, 1.5);
        b2World_SetHitEventThreshold($world, 2.5);
        b2World_SetGravity($world, new b2Vec2(1.0, -2.0));
        b2World_SetMaximumLinearSpeed($world, 12.0);
        b2World_EnableWarmStarting($world, false);
        b2World_SetUserData($world, 42);
        b2World_SetContactTuning($world, 20.0, 0.5, 1.0);
        b2World_EnableSpeculative($world, false);
        b2World_RebuildStaticTree($world);
        b2World_SetFrictionCallback($world, null);
        b2World_SetRestitutionCallback($world, null);

        $gravity = b2World_GetGravity($world);
        $profile = b2World_GetProfile($world);
        $counters = b2World_GetCounters($world);

        expect(b2World_IsSleepingEnabled($world))->toBeFalse()
            ->and(b2World_IsContinuousEnabled($world))->toBeFalse()
            ->and(b2World_GetRestitutionThreshold($world))->toBe(1.5)
            ->and(b2World_GetHitEventThreshold($world))->toBe(2.5)
            ->and($gravity->x)->toBe(1.0)
            ->and($gravity->y)->toBe(-2.0)
            ->and(b2World_GetMaximumLinearSpeed($world))->toBe(12.0)
            ->and(b2World_IsWarmStartingEnabled($world))->toBeFalse()
            ->and(b2World_GetUserData($world))->toBe(42)
            ->and(b2World_GetAwakeBodyCount($world))->toBeGreaterThanOrEqual(0)
            ->and($profile->step)->toBeGreaterThanOrEqual(0.0)
            ->and($counters->bodyCount)->toBe(2)
            ->and($counters->shapeCount)->toBe(2)
            ->and($counters->colorCounts)->toHaveCount(12);

        b2World_SetUserData($world, -1);
        expect(b2World_GetUserData($world))->toBe(-1);

        $explosion = b2DefaultExplosionDef();
        expect($explosion->maskBits)->toBe(-1);
        $explosion->position = new b2Vec2(0.0, 2.0);
        $explosion->radius = 8.0;
        $explosion->falloff = 0.5;
        $explosion->impulsePerLength = 20.0;
        b2World_Explode($world, $explosion);
        expect(b2World_IsValid($world))->toBeTrue();

        b2World_DumpMemoryStats($world);
        expect(is_file($dump))->toBeTrue()
            ->and(filesize($dump))->toBeGreaterThan(0);

        b2DestroyWorld($world);
    } finally {
        if (is_file($dump)) {
            unlink($dump);
        }
    }
});
