<?php

declare(strict_types=1);

/**
 * collision.h geometry, distance, manifolds, and the plane solver.
 * Tree functions live in DynamicTreeTest.
 */

function geoVec(float $x, float $y): b2Vec2
{
    return new b2Vec2($x, $y);
}

function geoIdentity(): b2Transform
{
    return b2Transform_identity();
}

function geoBox(): b2Polygon
{
    return b2MakeBox(0.5, 0.5);
}

function geoCircle(float $x, float $y, float $radius): b2Circle
{
    return new b2Circle(geoVec($x, $y), $radius);
}

function geoRay(float $x, float $y, float $dx, float $dy): b2RayCastInput
{
    return new b2RayCastInput(geoVec($x, $y), geoVec($dx, $dy), 1.0);
}

function geoChain(): b2ChainSegment
{
    return new b2ChainSegment(
        geoVec(-1.0, 0.0),
        new b2Segment(geoVec(0.0, 0.0), geoVec(1.0, 0.0)),
        geoVec(2.0, 0.0),
        0,
    );
}

function expectManifoldPoint(b2Manifold $manifold): void
{
    expect($manifold->pointCount)->toBeGreaterThan(0)
        ->and($manifold->points)->toHaveCount($manifold->pointCount)
        ->and($manifold->points[0])->toBeInstanceOf(b2ManifoldPoint::class);
}

it('binds every collision.h function', function (): void {
    $names = [
        'b2IsValidRay', 'b2MakePolygon', 'b2MakeOffsetPolygon', 'b2MakeOffsetRoundedPolygon',
        'b2MakeSquare', 'b2MakeBox', 'b2MakeRoundedBox', 'b2MakeOffsetBox', 'b2MakeOffsetRoundedBox',
        'b2TransformPolygon', 'b2ComputeCircleMass', 'b2ComputeCapsuleMass', 'b2ComputePolygonMass',
        'b2ComputeCircleAABB', 'b2ComputeCapsuleAABB', 'b2ComputePolygonAABB', 'b2ComputeSegmentAABB',
        'b2PointInCircle', 'b2PointInCapsule', 'b2PointInPolygon', 'b2RayCastCircle', 'b2RayCastCapsule',
        'b2RayCastSegment', 'b2RayCastPolygon', 'b2ShapeCastCircle', 'b2ShapeCastCapsule',
        'b2ShapeCastSegment', 'b2ShapeCastPolygon', 'b2ComputeHull', 'b2ValidateHull', 'b2SegmentDistance',
        'b2ShapeDistance', 'b2ShapeCast', 'b2MakeProxy', 'b2MakeOffsetProxy', 'b2GetSweepTransform',
        'b2TimeOfImpact', 'b2CollideCircles', 'b2CollideCapsuleAndCircle', 'b2CollideSegmentAndCircle',
        'b2CollidePolygonAndCircle', 'b2CollideCapsules', 'b2CollideSegmentAndCapsule',
        'b2CollidePolygonAndCapsule', 'b2CollidePolygons', 'b2CollideSegmentAndPolygon',
        'b2CollideChainSegmentAndCircle', 'b2CollideChainSegmentAndCapsule', 'b2CollideChainSegmentAndPolygon',
        'b2DynamicTree_Create', 'b2DynamicTree_Destroy', 'b2DynamicTree_CreateProxy', 'b2DynamicTree_DestroyProxy',
        'b2DynamicTree_MoveProxy', 'b2DynamicTree_EnlargeProxy', 'b2DynamicTree_SetCategoryBits',
        'b2DynamicTree_GetCategoryBits', 'b2DynamicTree_Query', 'b2DynamicTree_RayCast', 'b2DynamicTree_ShapeCast',
        'b2DynamicTree_GetHeight', 'b2DynamicTree_GetAreaRatio', 'b2DynamicTree_GetRootBounds',
        'b2DynamicTree_GetProxyCount', 'b2DynamicTree_Rebuild', 'b2DynamicTree_GetByteCount',
        'b2DynamicTree_GetUserData', 'b2DynamicTree_GetAABB', 'b2DynamicTree_Validate',
        'b2DynamicTree_ValidateNoEnlarged', 'b2SolvePlanes', 'b2ClipVector',
    ];

    $loaded = get_extension_funcs('box2d');
    expect($loaded)->toBeArray();
    foreach ($names as $name) {
        expect($loaded)->toContain($name);
    }
    expect($names)->toHaveCount(72);
});

it('rejects a negative box half-width with the geometry assert', function (): void {
    expect(fn () => b2MakeBox(-1.0, 1.0))->toThrow(function (b2AssertionError $error): void {
        expect($error->getMessage())->toContain('halfWidth > 0.0f')
            ->and($error->getMessage())->toContain('geometry.c');
    });
});

it('builds a hull and polygon from a square', function (): void {
    $square = [geoVec(-1.0, -1.0), geoVec(1.0, -1.0), geoVec(1.0, 1.0), geoVec(-1.0, 1.0)];

    expect(fn () => b2ComputeHull($square, 5))->toThrow(ValueError::class);

    $hull = b2ComputeHull($square, 4);
    expect($hull->count)->toBe(4)
        ->and(b2ValidateHull($hull))->toBeTrue()
        ->and($hull->points)->toHaveCount(4);

    $polygon = b2MakePolygon($hull, 0.0);
    expect($polygon->count)->toBe(4)
        ->and($polygon->radius)->toBe(0.0)
        ->and($polygon->vertices)->toHaveCount(4);

    $moved = b2MakeOffsetPolygon($hull, geoVec(2.0, 0.0), b2Rot_identity());
    expect($moved->count)->toBe(4)
        ->and($moved->centroid->x)->toBe(2.0);

    $rounded = b2MakeOffsetRoundedPolygon($hull, geoVec(0.0, 0.0), b2Rot_identity(), 0.25);
    expect($rounded->count)->toBe(4)
        ->and($rounded->radius)->toBe(0.25);
});

it('measures a unit box and a unit circle', function (): void {
    $box = geoBox();
    expect($box->count)->toBe(4)
        ->and($box->vertices[0]->x)->toBe(-0.5)
        ->and($box->vertices[0]->y)->toBe(-0.5)
        ->and($box->vertices[2]->x)->toBe(0.5)
        ->and($box->vertices[2]->y)->toBe(0.5);

    $square = b2MakeSquare(0.5);
    expect($square->count)->toBe(4);

    $rounded = b2MakeRoundedBox(0.5, 0.5, 0.25);
    expect($rounded->radius)->toBe(0.25)
        ->and($rounded->count)->toBe(4);

    $offset = b2MakeOffsetBox(0.5, 0.5, geoVec(3.0, 0.0), b2Rot_identity());
    expect($offset->centroid->x)->toBe(3.0);

    $offsetRounded = b2MakeOffsetRoundedBox(0.5, 0.5, geoVec(0.0, 4.0), b2Rot_identity(), 0.25);
    expect($offsetRounded->centroid->y)->toBe(4.0)
        ->and($offsetRounded->radius)->toBe(0.25);

    $shifted = b2TransformPolygon(new b2Transform(geoVec(1.0, 0.0), b2Rot_identity()), $box);
    expect($shifted->vertices[0]->x)->toBe(0.5)
        ->and($shifted->centroid->x)->toBe(1.0);

    $mass = b2ComputePolygonMass($box, 1.0);
    expect($mass->mass)->toBe(1.0)
        ->and($mass->center->x)->toBe(0.0)
        ->and($mass->center->y)->toBe(0.0);

    $circle = geoCircle(0.0, 0.0, 1.0);
    $circleMass = b2ComputeCircleMass($circle, 1.0);
    expect($circleMass->mass)->toBe(B2_PI);

    $capsule = new b2Capsule(geoVec(0.0, -0.5), geoVec(0.0, 0.5), 0.5);
    $capsuleMass = b2ComputeCapsuleMass($capsule, 1.0);
    expect($capsuleMass->mass)->toBeGreaterThan(0.0)
        ->and($capsuleMass->center->x)->toBe(0.0)
        ->and($capsuleMass->center->y)->toBe(0.0);

    $boxAabb = b2ComputePolygonAABB($box, geoIdentity());
    expect($boxAabb->lowerBound->x)->toBe(-0.5)
        ->and($boxAabb->lowerBound->y)->toBe(-0.5)
        ->and($boxAabb->upperBound->x)->toBe(0.5)
        ->and($boxAabb->upperBound->y)->toBe(0.5);

    $circleAabb = b2ComputeCircleAABB($circle, geoIdentity());
    expect($circleAabb->lowerBound->x)->toBe(-1.0)
        ->and($circleAabb->upperBound->x)->toBe(1.0);

    $capsuleAabb = b2ComputeCapsuleAABB($capsule, geoIdentity());
    expect($capsuleAabb->lowerBound->y)->toBe(-1.0)
        ->and($capsuleAabb->upperBound->y)->toBe(1.0);

    $segment = new b2Segment(geoVec(0.0, 0.0), geoVec(1.0, 0.0));
    $segmentAabb = b2ComputeSegmentAABB($segment, geoIdentity());
    expect($segmentAabb->lowerBound->x)->toBe(0.0)
        ->and($segmentAabb->upperBound->x)->toBe(1.0);
});

it('tests points, rays, and shape casts', function (): void {
    $circle = geoCircle(0.0, 0.0, 1.0);
    $capsule = new b2Capsule(geoVec(0.0, -0.5), geoVec(0.0, 0.5), 0.5);
    $box = geoBox();
    $segment = new b2Segment(geoVec(0.0, 0.0), geoVec(1.0, 0.0));

    expect(b2PointInCircle(geoVec(0.0, 0.0), $circle))->toBeTrue()
        ->and(b2PointInCircle(geoVec(2.0, 0.0), $circle))->toBeFalse()
        ->and(b2PointInCapsule(geoVec(0.0, 0.0), $capsule))->toBeTrue()
        ->and(b2PointInCapsule(geoVec(2.0, 0.0), $capsule))->toBeFalse()
        ->and(b2PointInPolygon(geoVec(0.0, 0.0), $box))->toBeTrue()
        ->and(b2PointInPolygon(geoVec(2.0, 0.0), $box))->toBeFalse();

    $ray = geoRay(-2.0, 0.0, 4.0, 0.0);
    expect(b2IsValidRay($ray))->toBeTrue();

    $circleHit = b2RayCastCircle($ray, $circle);
    expect($circleHit->hit)->toBeTrue()
        ->and($circleHit->fraction)->toBe(0.25)
        ->and($circleHit->point->x)->toBe(-1.0)
        ->and($circleHit->point->y)->toBe(0.0);

    $crossing = geoRay(0.5, -1.0, 0.0, 2.0);
    expect(b2RayCastCapsule($ray, $capsule)->hit)->toBeTrue()
        ->and(b2RayCastPolygon($ray, $box)->hit)->toBeTrue()
        ->and(b2RayCastSegment($crossing, $segment, false)->hit)->toBeTrue();

    $cast = new b2ShapeCastInput(b2MakeProxy([geoVec(-2.0, 0.0)], 1, 0.0), geoVec(4.0, 0.0), 1.0, false);
    $segmentCast = new b2ShapeCastInput(b2MakeProxy([geoVec(0.5, -1.0)], 1, 0.0), geoVec(0.0, 2.0), 1.0, false);
    expect(b2ShapeCastCircle($cast, $circle)->hit)->toBeTrue()
        ->and(b2ShapeCastCapsule($cast, $capsule)->hit)->toBeTrue()
        ->and(b2ShapeCastPolygon($cast, $box)->hit)->toBeTrue()
        ->and(b2ShapeCastSegment($segmentCast, $segment)->hit)->toBeTrue();
});

it('reuses a distance cache and reports time of impact', function (): void {
    $gap = b2SegmentDistance(geoVec(0.0, 0.0), geoVec(1.0, 0.0), geoVec(0.0, 1.0), geoVec(1.0, 1.0));
    expect($gap->distanceSquared)->toBe(1.0)
        ->and($gap->closest1->y)->toBe(0.0)
        ->and($gap->closest2->y)->toBe(1.0);

    $proxyA = b2MakeProxy([geoVec(0.0, 0.0)], 1, 1.0);
    $proxyB = b2MakeOffsetProxy([geoVec(0.0, 0.0)], 1, 1.0, geoVec(3.0, 0.0), b2Rot_identity());
    expect($proxyA->count)->toBe(1)
        ->and($proxyB->count)->toBe(1)
        ->and($proxyB->radius)->toBe(1.0);

    $input = new b2DistanceInput($proxyA, $proxyB, geoIdentity(), geoIdentity(), true);
    $cache = b2_emptySimplexCache();
    $cacheId = spl_object_id($cache);
    $simplexes = null;
    $first = b2ShapeDistance($input, $cache, $simplexes, 8);

    expect(spl_object_id($cache))->toBe($cacheId)
        ->and($cache->count)->toBeGreaterThan(0)
        ->and($first->distance)->toEqualWithDelta(1.0, 1.0e-5)
        ->and($simplexes)->toBeArray()
        ->and($simplexes)->toHaveCount($first->simplexCount)
        ->and($first->simplexCount)->toBeGreaterThan(0);

    $second = b2ShapeDistance($input, $cache, $simplexes, 8);
    expect($second->distance)->toEqualWithDelta($first->distance, 1.0e-6);

    $none = null;
    $skipped = b2ShapeDistance($input, $cache, $none, 0);
    expect($skipped->distance)->toEqualWithDelta(1.0, 1.0e-5)
        ->and($none)->toBeArray()
        ->and($none)->toHaveCount(0);

    expect(fn () => b2ShapeDistance($input, $cache, $none, -1))->toThrow(ValueError::class);

    $pair = new b2ShapeCastPairInput(
        $proxyA,
        b2MakeProxy([geoVec(0.0, 0.0)], 1, 1.0),
        geoIdentity(),
        new b2Transform(geoVec(3.0, 0.0), b2Rot_identity()),
        geoVec(-3.0, 0.0),
        1.0,
        false,
    );
    $cast = b2ShapeCast($pair);
    expect($cast->hit)->toBeTrue()
        ->and($cast->fraction)->toBeGreaterThan(0.0)
        ->and($cast->fraction)->toBeLessThan(1.0);

    $sweepA = new b2Sweep(geoVec(0.0, 0.0), geoVec(0.0, 0.0), geoVec(0.0, 0.0), b2Rot_identity(), b2Rot_identity());
    $sweepB = new b2Sweep(geoVec(0.0, 0.0), geoVec(3.0, 0.0), geoVec(0.0, 0.0), b2Rot_identity(), b2Rot_identity());
    expect(b2GetSweepTransform($sweepB, 0.0)->p->x)->toBe(3.0)
        ->and(b2GetSweepTransform($sweepB, 1.0)->p->x)->toBe(0.0);

    $toi = b2TimeOfImpact(new b2TOIInput($proxyA, b2MakeProxy([geoVec(0.0, 0.0)], 1, 1.0), $sweepA, $sweepB, 1.0));
    expect($toi->state)->toBe(b2_toiStateHit)
        ->and($toi->fraction)->toEqualWithDelta(1.0 / 3.0, 0.02);
});

it('reports a point for every collide pair that overlaps', function (): void {
    $xf = geoIdentity();
    $circle = geoCircle(0.0, 0.0, 1.0);
    $capsule = new b2Capsule(geoVec(0.0, -0.25), geoVec(0.0, 0.25), 0.5);
    $box = geoBox();
    $segment = new b2Segment(geoVec(-0.5, 0.0), geoVec(0.5, 0.0));
    $chain = geoChain();
    $below = geoIdentity();
    $belowCircle = geoCircle(0.5, -0.4, 0.5);
    $belowCapsule = new b2Capsule(geoVec(0.5, -0.6), geoVec(0.5, -0.2), 0.3);
    $belowBox = b2TransformPolygon(new b2Transform(geoVec(0.5, -0.51), b2Rot_identity()), geoBox());

    expectManifoldPoint(b2CollideCircles($circle, $xf, $circle, $xf));
    expectManifoldPoint(b2CollideCapsuleAndCircle($capsule, $xf, $circle, $xf));
    expectManifoldPoint(b2CollideSegmentAndCircle($segment, $xf, $circle, $xf));
    expectManifoldPoint(b2CollidePolygonAndCircle($box, $xf, $circle, $xf));
    expectManifoldPoint(b2CollideCapsules($capsule, $xf, $capsule, $xf));
    expectManifoldPoint(b2CollideSegmentAndCapsule($segment, $xf, $capsule, $xf));
    expectManifoldPoint(b2CollidePolygonAndCapsule($box, $xf, $capsule, $xf));
    expectManifoldPoint(b2CollidePolygons($box, $xf, $box, $xf));
    expectManifoldPoint(b2CollideSegmentAndPolygon($segment, $xf, $box, $xf));
    expectManifoldPoint(b2CollideChainSegmentAndCircle($chain, $xf, $belowCircle, $below));

    $cache = new b2SimplexCache();
    $cacheId = spl_object_id($cache);
    expectManifoldPoint(b2CollideChainSegmentAndCapsule($chain, $xf, $belowCapsule, $below, $cache));
    expect(spl_object_id($cache))->toBe($cacheId)
        ->and($cache->count)->toBeGreaterThan(0);

    $polygonCache = new b2SimplexCache();
    $polygonCacheId = spl_object_id($polygonCache);
    expectManifoldPoint(b2CollideChainSegmentAndPolygon($chain, $xf, $belowBox, $below, $polygonCache));
    expect(spl_object_id($polygonCache))->toBe($polygonCacheId)
        ->and($polygonCache->count)->toBeGreaterThan(0);
});

it('writes each plane push back onto the same object', function (): void {
    $plane = new b2CollisionPlane(new b2Plane(geoVec(0.0, 1.0), 0.0), 10.0, 0.0, true);
    $planeId = spl_object_id($plane);

    expect(fn () => b2SolvePlanes(geoVec(0.0, -1.0), [$plane], 2))->toThrow(ValueError::class);
    expect($plane->push)->toBe(0.0);

    $solved = b2SolvePlanes(geoVec(0.0, -1.0), [$plane], 1);
    expect(spl_object_id($plane))->toBe($planeId)
        ->and($plane->push)->toBeGreaterThan(0.0)
        ->and($solved->translation->y)->toBeGreaterThan(-1.0)
        ->and($solved->iterationCount)->toBeGreaterThan(0);

    $clipped = b2ClipVector(geoVec(1.0, -1.0), [$plane], 1);
    expect($clipped->x)->toBe(1.0)
        ->and($clipped->y)->toEqualWithDelta(0.0, 1.0e-5);

    expect(fn () => b2ClipVector(geoVec(0.0, -1.0), [$plane], 2))->toThrow(ValueError::class);
});
