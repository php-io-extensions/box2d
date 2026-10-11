<?php

declare(strict_types=1);

it('calls every chain function', function (): void {
    $definition = b2DefaultChainDef();
    expect($definition->count)->toBe(0)
        ->and($definition->materialCount)->toBe(1)
        ->and($definition->isLoop)->toBeFalse()
        ->and($definition->enableSensorEvents)->toBeFalse()
        ->and($definition->userData)->toBe(0)
        ->and($definition->internalValue)->toBe(1152023)
        ->and($definition->filter->categoryBits)->toBe(1);
    box2d_expect_near($definition->materials[0]->friction, 0.6);

    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    $definition->points = [
        new b2Vec2(0.0, 0.0),
        new b2Vec2(2.0, 0.0),
        new b2Vec2(2.0, 1.0),
        new b2Vec2(0.0, 1.0),
    ];
    $definition->count = 4;
    $definition->isLoop = true;
    $chain = b2CreateChain($body, $definition);

    b2Chain_SetFriction($chain, 0.25);
    b2Chain_SetRestitution($chain, 0.5);
    b2Chain_SetMaterial($chain, 3);

    $segments = null;
    $count = b2Chain_GetSegments($chain, $segments, b2Chain_GetSegmentCount($chain));

    expect(b2Chain_IsValid($chain))->toBeTrue()
        ->and(b2Chain_GetWorld($chain)->index1)->toBe($world->index1)
        ->and(b2Chain_GetWorld($chain)->generation)->toBe($world->generation)
        ->and(b2Chain_GetFriction($chain))->toBe(0.25)
        ->and(b2Chain_GetRestitution($chain))->toBe(0.5)
        ->and(b2Chain_GetMaterial($chain))->toBe(3)
        ->and($count)->toBe(4)
        ->and($segments)->toHaveCount(4)
        ->and(b2Shape_GetType($segments[0]))->toBe(b2_chainSegmentShape);

    $empty = null;
    expect(b2Chain_GetSegments($chain, $empty, 0))->toBe(0)
        ->and($empty)->toBe([]);

    b2DestroyChain($chain);
    expect(b2Chain_IsValid($chain))->toBeFalse();
    b2DestroyWorld($world);
});
