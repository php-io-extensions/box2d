<?php

declare(strict_types=1);

function box2d_worker_scene(int $workers): array
{
    $definition = b2DefaultWorldDef();
    $definition->workerCount = $workers;
    $definition->enableSleep = false;
    $world = b2CreateWorld($definition);
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(30.0, 0.5));

    $bodies = [];
    for ($index = 0; $index < 200; $index++) {
        $bodyDefinition = b2DefaultBodyDef();
        $bodyDefinition->type = b2_dynamicBody;
        $bodyDefinition->enableSleep = false;
        $bodyDefinition->position = new b2Vec2(($index % 20) * 1.05 - 10.0, 1.2 + intdiv($index, 20) * 1.05);
        $body = b2CreateBody($world, $bodyDefinition);
        b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.45, 0.45));
        $bodies[] = $body;
    }

    for ($step = 0; $step < 120; $step++) {
        b2World_Step($world, 1.0 / 60.0, 4);
    }

    $bits = [];
    foreach ($bodies as $body) {
        $position = b2Body_GetPosition($body);
        $rotation = b2Body_GetRotation($body);
        $bits[] = pack('G', $position->x).pack('G', $position->y).pack('G', $rotation->c).pack('G', $rotation->s);
    }
    b2DestroyWorld($world);

    return $bits;
}

function box2d_worker_pair(int $workers): array
{
    $definition = b2DefaultWorldDef();
    $definition->workerCount = $workers;
    $definition->enableSleep = false;
    $world = b2CreateWorld($definition);
    $ground = b2CreateBody($world, b2DefaultBodyDef());
    $groundShape = b2DefaultShapeDef();
    $groundShape->enablePreSolveEvents = true;
    $groundShape->material->friction = 0.4;
    $groundShape->material->restitution = 0.2;
    b2CreatePolygonShape($ground, $groundShape, b2MakeBox(8.0, 0.5));
    $bodyDefinition = b2DefaultBodyDef();
    $bodyDefinition->type = b2_dynamicBody;
    $bodyDefinition->enableSleep = false;
    $bodyDefinition->position = new b2Vec2(0.0, 2.0);
    $bodyDefinition->linearVelocity = new b2Vec2(2.0, 0.0);
    $body = b2CreateBody($world, $bodyDefinition);
    $shape = b2DefaultShapeDef();
    $shape->enablePreSolveEvents = true;
    $shape->material->friction = 0.4;
    $shape->material->restitution = 0.2;
    b2CreatePolygonShape($body, $shape, b2MakeBox(0.4, 0.4));

    return [$world, $body];
}

it('matches serial transforms for worker counts 4 and 65', function (): void {
    $serial = box2d_worker_scene(0);
    $pooled = box2d_worker_scene(4);
    $clamped = box2d_worker_scene(65);

    expect($pooled)->toBe($serial)
        ->and($clamped)->toBe($serial);
});

it('rejects a negative worker count and creates no world', function (): void {
    $existing = b2CreateWorld(b2DefaultWorldDef());
    $definition = b2DefaultWorldDef();
    $definition->workerCount = -1;

    expect(fn () => b2CreateWorld($definition))->toThrow(ValueError::class, 'workerCount');
    expect(b2World_IsValid($existing))->toBeTrue();

    $after = b2CreateWorld(b2DefaultWorldDef());
    expect(b2World_IsValid($existing))->toBeTrue()
        ->and(b2World_IsValid($after))->toBeTrue()
        ->and($after->index1)->not->toBe($existing->index1);

    b2DestroyWorld($existing);
    b2DestroyWorld($after);
});

it('applies callback results while four workers step the world', function (): void {
    [$slippery, $slipBody] = box2d_worker_pair(4);
    $frictionCalls = 0;
    b2World_SetFrictionCallback($slippery, function () use (&$frictionCalls): float {
        $frictionCalls++;

        return 0.0;
    });
    [$sticky, $stickBody] = box2d_worker_pair(4);
    b2World_SetFrictionCallback($sticky, function (): float {
        return 1.0;
    });
    for ($step = 0; $step < 90; $step++) {
        b2World_Step($slippery, 1.0 / 60.0, 4);
        b2World_Step($sticky, 1.0 / 60.0, 4);
    }
    expect($frictionCalls)->toBeGreaterThan(0)
        ->and(b2Body_GetPosition($slipBody)->x)->toBeGreaterThan(b2Body_GetPosition($stickBody)->x + 0.2);
    b2DestroyWorld($slippery);
    b2DestroyWorld($sticky);

    [$bouncy, $bouncyBody] = box2d_worker_pair(4);
    $restitutionCalls = 0;
    b2World_SetRestitutionCallback($bouncy, function () use (&$restitutionCalls): float {
        $restitutionCalls++;

        return 1.0;
    });
    [$dead, $deadBody] = box2d_worker_pair(4);
    b2World_SetRestitutionCallback($dead, function (): float {
        return 0.0;
    });
    for ($step = 0; $step < 40; $step++) {
        b2World_Step($bouncy, 1.0 / 60.0, 4);
        b2World_Step($dead, 1.0 / 60.0, 4);
    }
    expect($restitutionCalls)->toBeGreaterThan(0)
        ->and(b2Body_GetPosition($bouncyBody)->y)->toBeGreaterThan(b2Body_GetPosition($deadBody)->y);
    b2DestroyWorld($bouncy);
    b2DestroyWorld($dead);

    [$filtered, $filteredBody] = box2d_worker_pair(4);
    $filterCalls = 0;
    b2World_SetCustomFilterCallback($filtered, function () use (&$filterCalls): bool {
        $filterCalls++;

        return false;
    }, 'workers');
    for ($step = 0; $step < 90; $step++) {
        b2World_Step($filtered, 1.0 / 60.0, 4);
    }
    expect($filterCalls)->toBeGreaterThan(0)
        ->and(b2Body_GetPosition($filteredBody)->y)->toBeLessThan(0.0);
    b2DestroyWorld($filtered);

    [$edited, $editedBody] = box2d_worker_pair(4);
    $held = null;
    b2World_SetPreSolveCallback($edited, function (b2ShapeId $shapeIdA, b2ShapeId $shapeIdB, b2Manifold $manifold) use (&$held): bool {
        if ($manifold->pointCount > 0) {
            $manifold->normal = new b2Vec2(1.0, 0.0);
            $manifold->points[0]->normalImpulse = 42.0;
            $held = $manifold;
        }

        return true;
    }, null);
    for ($step = 0; $step < 90 && $held === null; $step++) {
        b2World_Step($edited, 1.0 / 60.0, 4);
    }
    $contacts = null;
    $count = b2Body_GetContactData($editedBody, $contacts, 4);
    expect($held)->toBeInstanceOf(b2Manifold::class)
        ->and($held->points[0]->normalImpulse)->toBe(42.0)
        ->and($count)->toBeGreaterThan(0)
        ->and($contacts[0]->manifold->normal->x)->toBe(1.0)
        ->and($contacts[0]->manifold->normal->y)->toBe(0.0);
    b2DestroyWorld($edited);
});

it('rejects a pooled step in a forked child and still steps a serial world', function (): void {
    $serialDefinition = b2DefaultWorldDef();
    $serialDefinition->workerCount = 0;
    $serial = b2CreateWorld($serialDefinition);
    $pooledDefinition = b2DefaultWorldDef();
    $pooledDefinition->workerCount = 4;
    $pooled = b2CreateWorld($pooledDefinition);

    $pid = pcntl_fork();
    expect($pid)->not->toBe(-1);
    if ($pid === 0) {
        try {
            b2World_Step($serial, 1.0 / 60.0, 4);
            b2World_Step($pooled, 1.0 / 60.0, 4);
            exit(2);
        } catch (Error $error) {
            $message = $error->getMessage();
            exit(str_contains($message, "world's worker pool did not survive fork") ? 0 : 3);
        }
    }

    pcntl_waitpid($pid, $status);
    expect(pcntl_wexitstatus($status))->toBe(0);
    b2World_Step($pooled, 1.0 / 60.0, 4);
    expect(b2World_IsValid($pooled))->toBeTrue()
        ->and(b2World_IsValid($serial))->toBeTrue();

    b2DestroyWorld($pooled);
    b2DestroyWorld($serial);
});
