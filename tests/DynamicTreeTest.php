<?php

declare(strict_types=1);

/**
 * b2DynamicTree: proxies, query, ray cast, shape cast, rebuild, destroy.
 */

function treeAabb(float $x0, float $y0, float $x1, float $y1): b2AABB
{
    return new b2AABB(new b2Vec2($x0, $y0), new b2Vec2($x1, $y1));
}

it('creates, queries, moves, rebuilds, and destroys a proxy', function (): void {
    $before = b2GetByteCount();
    $tree = b2DynamicTree_Create();
    expect($tree)->toBeInstanceOf(b2DynamicTree::class)
        ->and(b2DynamicTree_GetProxyCount($tree))->toBe(0);

    $box = treeAabb(0.0, 0.0, 1.0, 1.0);
    $proxyId = b2DynamicTree_CreateProxy($tree, $box, 1, 42);
    expect($proxyId)->toBeInt()
        ->and(b2DynamicTree_GetProxyCount($tree))->toBe(1)
        ->and(b2DynamicTree_GetUserData($tree, $proxyId))->toBe(42)
        ->and(b2DynamicTree_GetCategoryBits($tree, $proxyId))->toBe(1)
        ->and(b2DynamicTree_GetByteCount($tree))->toBeGreaterThan(0)
        ->and(b2DynamicTree_GetHeight($tree))->toBeGreaterThanOrEqual(0);

    $stored = b2DynamicTree_GetAABB($tree, $proxyId);
    expect($stored->lowerBound->x)->toBeLessThanOrEqual(0.0)
        ->and($stored->upperBound->x)->toBeGreaterThanOrEqual(1.0);

    $hits = [];
    $stats = b2DynamicTree_Query(
        $tree,
        $box,
        1,
        function (int $id, int $userData, mixed $context) use (&$hits): bool {
            $hits[] = [$id, $userData, $context];

            return true;
        },
        'ctx',
    );
    expect($hits)->toBe([[$proxyId, 42, 'ctx']])
        ->and($stats->leafVisits)->toBeGreaterThan(0)
        ->and($stats)->toBeInstanceOf(b2TreeStats::class);

    $masked = 0;
    b2DynamicTree_Query($tree, $box, 2, function () use (&$masked): bool {
        $masked++;

        return true;
    }, null);
    expect($masked)->toBe(0);

    $rays = [];
    $ray = new b2RayCastInput(new b2Vec2(-1.0, 0.5), new b2Vec2(3.0, 0.0), 1.0);
    b2DynamicTree_RayCast(
        $tree,
        $ray,
        1,
        function (b2RayCastInput $input, int $id, int $userData, mixed $context) use (&$rays): float {
            $rays[] = [$id, $userData, $context, $input->maxFraction];

            return $input->maxFraction;
        },
        7,
    );
    expect($rays)->toBe([[$proxyId, 42, 7, 1.0]]);

    $casts = [];
    $shape = new b2ShapeCastInput(b2MakeProxy([new b2Vec2(-1.0, 0.5)], 1, 0.0), new b2Vec2(3.0, 0.0), 1.0, false);
    b2DynamicTree_ShapeCast(
        $tree,
        $shape,
        1,
        function (b2ShapeCastInput $input, int $id, int $userData, mixed $context) use (&$casts): float {
            $casts[] = [$id, $userData, $context, $input->translation->x];

            return $input->maxFraction;
        },
        null,
    );
    expect($casts)->toBe([[$proxyId, 42, null, 3.0]]);

    b2DynamicTree_MoveProxy($tree, $proxyId, treeAabb(2.0, 2.0, 3.0, 3.0));
    b2DynamicTree_EnlargeProxy($tree, $proxyId, treeAabb(2.0, 2.0, 4.0, 4.0));
    expect(b2DynamicTree_GetCategoryBits($tree, $proxyId))->toBe(1);

    // A leaf stores userData in the same union as its children. SetCategoryBits
    // asserts those child slots are the null index, which is the bit pattern of -1.
    $categoryProxy = b2DynamicTree_CreateProxy($tree, treeAabb(6.0, 6.0, 7.0, 7.0), 1, -1);
    b2DynamicTree_SetCategoryBits($tree, $categoryProxy, 4);
    expect(b2DynamicTree_GetCategoryBits($tree, $categoryProxy))->toBe(4);
    b2DynamicTree_DestroyProxy($tree, $categoryProxy);

    $moved = b2DynamicTree_GetAABB($tree, $proxyId);
    expect($moved->upperBound->x)->toBeGreaterThanOrEqual(3.0);

    $sorted = b2DynamicTree_Rebuild($tree, true);
    expect($sorted)->toBeInt()->toBeGreaterThanOrEqual(0);
    b2DynamicTree_Validate($tree);
    b2DynamicTree_ValidateNoEnlarged($tree);

    $other = b2DynamicTree_CreateProxy($tree, treeAabb(10.0, 10.0, 11.0, 11.0), 1, 3);
    $third = b2DynamicTree_CreateProxy($tree, treeAabb(12.0, 12.0, 13.0, 13.0), 1, 5);
    $ratio = b2DynamicTree_GetAreaRatio($tree);
    expect($ratio)->toBeFloat()->toBeGreaterThan(0.0);
    b2DynamicTree_DestroyProxy($tree, $third);
    b2DynamicTree_DestroyProxy($tree, $other);

    $root = b2DynamicTree_GetRootBounds($tree);
    expect($root->upperBound->x)->toBeGreaterThan($root->lowerBound->x);

    b2DynamicTree_DestroyProxy($tree, $proxyId);
    expect(b2DynamicTree_GetProxyCount($tree))->toBe(0);

    b2DynamicTree_Destroy($tree);
    expect(b2GetByteCount())->toBe($before);
});

it('rejects use after destroy', function (): void {
    $tree = b2DynamicTree_Create();
    $proxyId = b2DynamicTree_CreateProxy($tree, treeAabb(0.0, 0.0, 1.0, 1.0), 1, 1);
    b2DynamicTree_Destroy($tree);

    expect(fn () => b2DynamicTree_GetProxyCount($tree))->toThrow(ValueError::class)
        ->and(fn () => b2DynamicTree_CreateProxy($tree, treeAabb(0.0, 0.0, 1.0, 1.0), 1, 1))->toThrow(ValueError::class)
        ->and(fn () => b2DynamicTree_DestroyProxy($tree, $proxyId))->toThrow(ValueError::class)
        ->and(fn () => b2DynamicTree_Query($tree, treeAabb(0.0, 0.0, 1.0, 1.0), 1, fn () => true, null))->toThrow(ValueError::class)
        ->and(fn () => b2DynamicTree_Destroy($tree))->toThrow(ValueError::class);
});

it('frees a tree that leaves scope without an explicit destroy', function (): void {
    $before = b2GetByteCount();
    $make = function (): void {
        $tree = b2DynamicTree_Create();
        b2DynamicTree_CreateProxy($tree, treeAabb(0.0, 0.0, 1.0, 1.0), 1, 9);
        expect(b2DynamicTree_GetProxyCount($tree))->toBe(1);
    };
    $make();

    expect(b2GetByteCount())->toBe($before);
});

it('rethrows a query callback exception and rejects a non-float cast return', function (): void {
    $tree = b2DynamicTree_Create();
    $box = treeAabb(0.0, 0.0, 1.0, 1.0);
    b2DynamicTree_CreateProxy($tree, $box, 1, 1);

    expect(fn () => b2DynamicTree_Query($tree, $box, 1, function (): bool {
        throw new RuntimeException('stop');
    }, null))->toThrow(RuntimeException::class, 'stop');

    $ray = new b2RayCastInput(new b2Vec2(-1.0, 0.5), new b2Vec2(3.0, 0.0), 1.0);
    expect(fn () => b2DynamicTree_RayCast($tree, $ray, 1, function (): stdClass {
        return new stdClass();
    }, null))->toThrow(TypeError::class);

    b2DynamicTree_Destroy($tree);
});
