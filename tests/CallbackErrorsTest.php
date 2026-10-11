<?php

declare(strict_types=1);

function box2d_callback_contact_world(): array
{
    $world = b2CreateWorld(b2DefaultWorldDef());
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    $groundShape = b2DefaultShapeDef();
    $groundShape->enablePreSolveEvents = true;
    b2CreatePolygonShape($ground, $groundShape, b2MakeBox(8.0, 0.5));

    $bodies = [];
    foreach ([ -1.2, 1.2 ] as $x) {
        $definition = b2DefaultBodyDef();
        $definition->type = b2_dynamicBody;
        $definition->position = new b2Vec2($x, 0.55);
        $definition->enableSleep = false;
        $body = b2CreateBody($world, $definition);
        $shape = b2DefaultShapeDef();
        $shape->enablePreSolveEvents = true;
        b2CreatePolygonShape($body, $shape, b2MakeBox(0.4, 0.4));
        $bodies[] = $body;
    }

    return [$world, $bodies];
}

it('stops friction callbacks after an exception and rethrows the default path', function (): void {
    [$world] = box2d_callback_contact_world();
    $calls = 0;
    b2World_SetFrictionCallback($world, function () use (&$calls): float {
        $calls++;
        throw new RuntimeException('friction broke');
    });

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(RuntimeException::class, 'friction broke');
    expect($calls)->toBe(1);
    expect(b2World_IsValid($world))->toBeTrue();

    b2DestroyWorld($world);
});

it('stops restitution callbacks after an exception', function (): void {
    [$world] = box2d_callback_contact_world();
    $calls = 0;
    b2World_SetRestitutionCallback($world, function () use (&$calls): float {
        $calls++;
        throw new RuntimeException('restitution broke');
    });

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(RuntimeException::class, 'restitution broke');
    expect($calls)->toBe(1);

    b2DestroyWorld($world);
});

it('stops custom filter callbacks after an exception and allows the rest of the step', function (): void {
    [$world] = box2d_callback_contact_world();
    $calls = 0;
    b2World_SetCustomFilterCallback($world, function () use (&$calls): bool {
        $calls++;
        throw new RuntimeException('filter broke');
    }, null);

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(RuntimeException::class, 'filter broke');
    expect($calls)->toBe(1);
    expect(b2World_IsValid($world))->toBeTrue();

    b2DestroyWorld($world);
});

it('stops pre-solve callbacks after an exception', function (): void {
    [$world] = box2d_callback_contact_world();
    $calls = 0;
    b2World_SetPreSolveCallback($world, function () use (&$calls): bool {
        $calls++;
        throw new RuntimeException('pre-solve broke');
    }, null);

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(RuntimeException::class, 'pre-solve broke');
    expect($calls)->toBe(1);

    b2DestroyWorld($world);
});

it('rejects a friction return that is not a float', function (): void {
    [$world] = box2d_callback_contact_world();
    b2World_SetFrictionCallback($world, function (): array {
        return ['nope'];
    });

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(TypeError::class, 'float');

    b2DestroyWorld($world);
});

it('rejects a filter return that is not a bool', function (): void {
    [$world] = box2d_callback_contact_world();
    b2World_SetCustomFilterCallback($world, function (): array {
        return ['nope'];
    }, null);

    expect(fn () => b2World_Step($world, 1.0 / 60.0, 4))->toThrow(TypeError::class, 'bool');

    b2DestroyWorld($world);
});

it('terminates an overlap query when the callback throws', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));
    b2CreateCircleShape($body, b2DefaultShapeDef(), new b2Circle(new b2Vec2(3.0, 0.0), 0.4));
    $calls = 0;
    $overlap = function () use (&$calls): bool {
        $calls++;
        throw new RuntimeException('query broke');
    };

    expect(fn () => b2World_OverlapAABB(
        $world,
        new b2AABB(new b2Vec2(-2.0, -2.0), new b2Vec2(6.0, 2.0)),
        b2DefaultQueryFilter(),
        $overlap,
        null,
    ))->toThrow(RuntimeException::class, 'query broke');
    expect($calls)->toBe(1);

    b2DestroyWorld($world);
});

it('rejects a cast return that is not a float', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));

    expect(fn () => b2World_CastRay(
        $world,
        new b2Vec2(0.0, 3.0),
        new b2Vec2(0.0, -6.0),
        b2DefaultQueryFilter(),
        function (): array {
            return ['nope'];
        },
        null,
    ))->toThrow(TypeError::class, 'float');

    b2DestroyWorld($world);
});

it('does not call a second debug draw closure after the first throws', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));
    b2Body_SetName($body, 'named');
    $calls = 0;
    $draw = b2DefaultDebugDraw();
    $draw->drawShapes = true;
    $draw->drawBodyNames = true;
    $boom = function () use (&$calls): void {
        $calls++;
        throw new RuntimeException('draw broke');
    };
    $draw->DrawSolidPolygonFcn = $boom;
    $draw->DrawStringFcn = $boom;

    expect(fn () => b2World_Draw($world, $draw))->toThrow(RuntimeException::class, 'draw broke');
    expect($calls)->toBe(1);

    b2DestroyWorld($world);
});
