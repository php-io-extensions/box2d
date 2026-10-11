<?php

/** @generate-class-entries */

final class b2RayCastInput
{
    public b2Vec2 $origin;
    public b2Vec2 $translation;
    public float $maxFraction = 0.0;

    public function __construct(b2Vec2 $origin = new b2Vec2(), b2Vec2 $translation = new b2Vec2(), float $maxFraction = 0.0) {}
}

final class b2ShapeProxy
{
    public array $points = [];
    public int $count = 0;
    public float $radius = 0.0;

    public function __construct(array $points = [], int $count = 0, float $radius = 0.0) {}
}

final class b2ShapeCastInput
{
    public b2ShapeProxy $proxy;
    public b2Vec2 $translation;
    public float $maxFraction = 0.0;
    public bool $canEncroach = false;

    public function __construct(b2ShapeProxy $proxy = new b2ShapeProxy(), b2Vec2 $translation = new b2Vec2(), float $maxFraction = 0.0, bool $canEncroach = false) {}
}

final class b2CastOutput
{
    public b2Vec2 $normal;
    public b2Vec2 $point;
    public float $fraction = 0.0;
    public int $iterations = 0;
    public bool $hit = false;

    public function __construct(b2Vec2 $normal = new b2Vec2(), b2Vec2 $point = new b2Vec2(), float $fraction = 0.0, int $iterations = 0, bool $hit = false) {}
}

final class b2MassData
{
    public float $mass = 0.0;
    public b2Vec2 $center;
    public float $rotationalInertia = 0.0;

    public function __construct(float $mass = 0.0, b2Vec2 $center = new b2Vec2(), float $rotationalInertia = 0.0) {}
}

final class b2Circle
{
    public b2Vec2 $center;
    public float $radius = 0.0;

    public function __construct(b2Vec2 $center = new b2Vec2(), float $radius = 0.0) {}
}

final class b2Capsule
{
    public b2Vec2 $center1;
    public b2Vec2 $center2;
    public float $radius = 0.0;

    public function __construct(b2Vec2 $center1 = new b2Vec2(), b2Vec2 $center2 = new b2Vec2(), float $radius = 0.0) {}
}

final class b2Polygon
{
    public array $vertices = [];
    public array $normals = [];
    public b2Vec2 $centroid;
    public float $radius = 0.0;
    public int $count = 0;

    public function __construct(array $vertices = [], array $normals = [], b2Vec2 $centroid = new b2Vec2(), float $radius = 0.0, int $count = 0) {}
}

final class b2Segment
{
    public b2Vec2 $point1;
    public b2Vec2 $point2;

    public function __construct(b2Vec2 $point1 = new b2Vec2(), b2Vec2 $point2 = new b2Vec2()) {}
}

final class b2ChainSegment
{
    public b2Vec2 $ghost1;
    public b2Segment $segment;
    public b2Vec2 $ghost2;
    public int $chainId = 0;

    public function __construct(b2Vec2 $ghost1 = new b2Vec2(), b2Segment $segment = new b2Segment(), b2Vec2 $ghost2 = new b2Vec2(), int $chainId = 0) {}
}

final class b2Hull
{
    public array $points = [];
    public int $count = 0;

    public function __construct(array $points = [], int $count = 0) {}
}

final class b2SegmentDistanceResult
{
    public b2Vec2 $closest1;
    public b2Vec2 $closest2;
    public float $fraction1 = 0.0;
    public float $fraction2 = 0.0;
    public float $distanceSquared = 0.0;

    public function __construct(b2Vec2 $closest1 = new b2Vec2(), b2Vec2 $closest2 = new b2Vec2(), float $fraction1 = 0.0, float $fraction2 = 0.0, float $distanceSquared = 0.0) {}
}

final class b2SimplexCache
{
    public int $count = 0;
    public array $indexA = [];
    public array $indexB = [];

    public function __construct(int $count = 0, array $indexA = [0, 0, 0], array $indexB = [0, 0, 0]) {}
}

final class b2DistanceInput
{
    public b2ShapeProxy $proxyA;
    public b2ShapeProxy $proxyB;
    public b2Transform $transformA;
    public b2Transform $transformB;
    public bool $useRadii = false;

    public function __construct(b2ShapeProxy $proxyA = new b2ShapeProxy(), b2ShapeProxy $proxyB = new b2ShapeProxy(), b2Transform $transformA = new b2Transform(), b2Transform $transformB = new b2Transform(), bool $useRadii = false) {}
}

final class b2DistanceOutput
{
    public b2Vec2 $pointA;
    public b2Vec2 $pointB;
    public b2Vec2 $normal;
    public float $distance = 0.0;
    public int $iterations = 0;
    public int $simplexCount = 0;

    public function __construct(b2Vec2 $pointA = new b2Vec2(), b2Vec2 $pointB = new b2Vec2(), b2Vec2 $normal = new b2Vec2(), float $distance = 0.0, int $iterations = 0, int $simplexCount = 0) {}
}

final class b2SimplexVertex
{
    public b2Vec2 $wA;
    public b2Vec2 $wB;
    public b2Vec2 $w;
    public float $a = 0.0;
    public int $indexA = 0;
    public int $indexB = 0;

    public function __construct(b2Vec2 $wA = new b2Vec2(), b2Vec2 $wB = new b2Vec2(), b2Vec2 $w = new b2Vec2(), float $a = 0.0, int $indexA = 0, int $indexB = 0) {}
}

final class b2Simplex
{
    public b2SimplexVertex $v1;
    public b2SimplexVertex $v2;
    public b2SimplexVertex $v3;
    public int $count = 0;

    public function __construct(b2SimplexVertex $v1 = new b2SimplexVertex(), b2SimplexVertex $v2 = new b2SimplexVertex(), b2SimplexVertex $v3 = new b2SimplexVertex(), int $count = 0) {}
}

final class b2ShapeCastPairInput
{
    public b2ShapeProxy $proxyA;
    public b2ShapeProxy $proxyB;
    public b2Transform $transformA;
    public b2Transform $transformB;
    public b2Vec2 $translationB;
    public float $maxFraction = 0.0;
    public bool $canEncroach = false;

    public function __construct(b2ShapeProxy $proxyA = new b2ShapeProxy(), b2ShapeProxy $proxyB = new b2ShapeProxy(), b2Transform $transformA = new b2Transform(), b2Transform $transformB = new b2Transform(), b2Vec2 $translationB = new b2Vec2(), float $maxFraction = 0.0, bool $canEncroach = false) {}
}

final class b2Sweep
{
    public b2Vec2 $localCenter;
    public b2Vec2 $c1;
    public b2Vec2 $c2;
    public b2Rot $q1;
    public b2Rot $q2;

    public function __construct(b2Vec2 $localCenter = new b2Vec2(), b2Vec2 $c1 = new b2Vec2(), b2Vec2 $c2 = new b2Vec2(), b2Rot $q1 = new b2Rot(), b2Rot $q2 = new b2Rot()) {}
}

final class b2TOIInput
{
    public b2ShapeProxy $proxyA;
    public b2ShapeProxy $proxyB;
    public b2Sweep $sweepA;
    public b2Sweep $sweepB;
    public float $maxFraction = 0.0;

    public function __construct(b2ShapeProxy $proxyA = new b2ShapeProxy(), b2ShapeProxy $proxyB = new b2ShapeProxy(), b2Sweep $sweepA = new b2Sweep(), b2Sweep $sweepB = new b2Sweep(), float $maxFraction = 0.0) {}
}

final class b2TOIOutput
{
    public int $state = 0;
    public float $fraction = 0.0;

    public function __construct(int $state = 0, float $fraction = 0.0) {}
}

final class b2ManifoldPoint
{
    public b2Vec2 $point;
    public b2Vec2 $anchorA;
    public b2Vec2 $anchorB;
    public float $separation = 0.0;
    public float $normalImpulse = 0.0;
    public float $tangentImpulse = 0.0;
    public float $totalNormalImpulse = 0.0;
    public float $normalVelocity = 0.0;
    public int $id = 0;
    public bool $persisted = false;

    public function __construct(b2Vec2 $point = new b2Vec2(), b2Vec2 $anchorA = new b2Vec2(), b2Vec2 $anchorB = new b2Vec2(), float $separation = 0.0, float $normalImpulse = 0.0, float $tangentImpulse = 0.0, float $totalNormalImpulse = 0.0, float $normalVelocity = 0.0, int $id = 0, bool $persisted = false) {}
}

final class b2Manifold
{
    public b2Vec2 $normal;
    public float $rollingImpulse = 0.0;
    public array $points = [];
    public int $pointCount = 0;

    public function __construct(b2Vec2 $normal = new b2Vec2(), float $rollingImpulse = 0.0, array $points = [], int $pointCount = 0) {}
}

/**
 * Opaque dynamic tree. Box2D owns the node storage.
 * Create one with b2DynamicTree_Create().
 */
final class b2DynamicTree
{
    private function __construct() {}
}

final class b2TreeStats
{
    public int $nodeVisits = 0;
    public int $leafVisits = 0;

    public function __construct(int $nodeVisits = 0, int $leafVisits = 0) {}
}

final class b2PlaneResult
{
    public b2Plane $plane;
    public b2Vec2 $point;
    public bool $hit = false;

    public function __construct(b2Plane $plane = new b2Plane(), b2Vec2 $point = new b2Vec2(), bool $hit = false) {}
}

final class b2CollisionPlane
{
    public b2Plane $plane;
    public float $pushLimit = 0.0;
    public float $push = 0.0;
    public bool $clipVelocity = false;

    public function __construct(b2Plane $plane = new b2Plane(), float $pushLimit = 0.0, float $push = 0.0, bool $clipVelocity = false) {}
}

final class b2PlaneSolverResult
{
    public b2Vec2 $translation;
    public int $iterationCount = 0;

    public function __construct(b2Vec2 $translation = new b2Vec2(), int $iterationCount = 0) {}
}

/**
 * @var int
 * @cvalue b2_toiStateUnknown
 */
const b2_toiStateUnknown = UNKNOWN;

/**
 * @var int
 * @cvalue b2_toiStateFailed
 */
const b2_toiStateFailed = UNKNOWN;

/**
 * @var int
 * @cvalue b2_toiStateOverlapped
 */
const b2_toiStateOverlapped = UNKNOWN;

/**
 * @var int
 * @cvalue b2_toiStateHit
 */
const b2_toiStateHit = UNKNOWN;

/**
 * @var int
 * @cvalue b2_toiStateSeparated
 */
const b2_toiStateSeparated = UNKNOWN;

function b2_emptySimplexCache(): b2SimplexCache {}

function b2IsValidRay(b2RayCastInput $input): bool {}

function b2MakePolygon(b2Hull $hull, float $radius): b2Polygon {}

function b2MakeOffsetPolygon(b2Hull $hull, b2Vec2 $position, b2Rot $rotation): b2Polygon {}

function b2MakeOffsetRoundedPolygon(b2Hull $hull, b2Vec2 $position, b2Rot $rotation, float $radius): b2Polygon {}

function b2MakeSquare(float $halfWidth): b2Polygon {}

function b2MakeBox(float $halfWidth, float $halfHeight): b2Polygon {}

function b2MakeRoundedBox(float $halfWidth, float $halfHeight, float $radius): b2Polygon {}

function b2MakeOffsetBox(float $halfWidth, float $halfHeight, b2Vec2 $center, b2Rot $rotation): b2Polygon {}

function b2MakeOffsetRoundedBox(float $halfWidth, float $halfHeight, b2Vec2 $center, b2Rot $rotation, float $radius): b2Polygon {}

function b2TransformPolygon(b2Transform $transform, b2Polygon $polygon): b2Polygon {}

function b2ComputeCircleMass(b2Circle $shape, float $density): b2MassData {}

function b2ComputeCapsuleMass(b2Capsule $shape, float $density): b2MassData {}

function b2ComputePolygonMass(b2Polygon $shape, float $density): b2MassData {}

function b2ComputeCircleAABB(b2Circle $shape, b2Transform $transform): b2AABB {}

function b2ComputeCapsuleAABB(b2Capsule $shape, b2Transform $transform): b2AABB {}

function b2ComputePolygonAABB(b2Polygon $shape, b2Transform $transform): b2AABB {}

function b2ComputeSegmentAABB(b2Segment $shape, b2Transform $transform): b2AABB {}

function b2PointInCircle(b2Vec2 $point, b2Circle $shape): bool {}

function b2PointInCapsule(b2Vec2 $point, b2Capsule $shape): bool {}

function b2PointInPolygon(b2Vec2 $point, b2Polygon $shape): bool {}

function b2RayCastCircle(b2RayCastInput $input, b2Circle $shape): b2CastOutput {}

function b2RayCastCapsule(b2RayCastInput $input, b2Capsule $shape): b2CastOutput {}

function b2RayCastSegment(b2RayCastInput $input, b2Segment $shape, bool $oneSided): b2CastOutput {}

function b2RayCastPolygon(b2RayCastInput $input, b2Polygon $shape): b2CastOutput {}

function b2ShapeCastCircle(b2ShapeCastInput $input, b2Circle $shape): b2CastOutput {}

function b2ShapeCastCapsule(b2ShapeCastInput $input, b2Capsule $shape): b2CastOutput {}

function b2ShapeCastSegment(b2ShapeCastInput $input, b2Segment $shape): b2CastOutput {}

function b2ShapeCastPolygon(b2ShapeCastInput $input, b2Polygon $shape): b2CastOutput {}

/** $points is a list of b2Vec2. $count is how many of those points to read. */
function b2ComputeHull(array $points, int $count): b2Hull {}

function b2ValidateHull(b2Hull $hull): bool {}

function b2SegmentDistance(b2Vec2 $p1, b2Vec2 $q1, b2Vec2 $p2, b2Vec2 $q2): b2SegmentDistanceResult {}

/**
 * $cache is updated on the same object.
 * $simplexes receives output.simplexCount entries. $simplexCapacity 0 stores none.
 * $simplexCapacity below 0 throws ValueError.
 */
function b2ShapeDistance(b2DistanceInput $input, b2SimplexCache $cache, ?array &$simplexes, int $simplexCapacity): b2DistanceOutput {}

function b2ShapeCast(b2ShapeCastPairInput $input): b2CastOutput {}

/** $points is a list of b2Vec2. $count is how many of those points to read. */
function b2MakeProxy(array $points, int $count, float $radius): b2ShapeProxy {}

/** $points is a list of b2Vec2. $count is how many of those points to read. */
function b2MakeOffsetProxy(array $points, int $count, float $radius, b2Vec2 $position, b2Rot $rotation): b2ShapeProxy {}

function b2GetSweepTransform(b2Sweep $sweep, float $time): b2Transform {}

function b2TimeOfImpact(b2TOIInput $input): b2TOIOutput {}

function b2CollideCircles(b2Circle $circleA, b2Transform $xfA, b2Circle $circleB, b2Transform $xfB): b2Manifold {}

function b2CollideCapsuleAndCircle(b2Capsule $capsuleA, b2Transform $xfA, b2Circle $circleB, b2Transform $xfB): b2Manifold {}

function b2CollideSegmentAndCircle(b2Segment $segmentA, b2Transform $xfA, b2Circle $circleB, b2Transform $xfB): b2Manifold {}

function b2CollidePolygonAndCircle(b2Polygon $polygonA, b2Transform $xfA, b2Circle $circleB, b2Transform $xfB): b2Manifold {}

function b2CollideCapsules(b2Capsule $capsuleA, b2Transform $xfA, b2Capsule $capsuleB, b2Transform $xfB): b2Manifold {}

function b2CollideSegmentAndCapsule(b2Segment $segmentA, b2Transform $xfA, b2Capsule $capsuleB, b2Transform $xfB): b2Manifold {}

function b2CollidePolygonAndCapsule(b2Polygon $polygonA, b2Transform $xfA, b2Capsule $capsuleB, b2Transform $xfB): b2Manifold {}

function b2CollidePolygons(b2Polygon $polygonA, b2Transform $xfA, b2Polygon $polygonB, b2Transform $xfB): b2Manifold {}

function b2CollideSegmentAndPolygon(b2Segment $segmentA, b2Transform $xfA, b2Polygon $polygonB, b2Transform $xfB): b2Manifold {}

function b2CollideChainSegmentAndCircle(b2ChainSegment $segmentA, b2Transform $xfA, b2Circle $circleB, b2Transform $xfB): b2Manifold {}

/** $cache is updated on the same object. */
function b2CollideChainSegmentAndCapsule(b2ChainSegment $segmentA, b2Transform $xfA, b2Capsule $capsuleB, b2Transform $xfB, b2SimplexCache $cache): b2Manifold {}

/** $cache is updated on the same object. */
function b2CollideChainSegmentAndPolygon(b2ChainSegment $segmentA, b2Transform $xfA, b2Polygon $polygonB, b2Transform $xfB, b2SimplexCache $cache): b2Manifold {}

function b2DynamicTree_Create(): b2DynamicTree {}

function b2DynamicTree_Destroy(b2DynamicTree $tree): void {}

function b2DynamicTree_CreateProxy(b2DynamicTree $tree, b2AABB $aabb, int $categoryBits, int $userData): int {}

function b2DynamicTree_DestroyProxy(b2DynamicTree $tree, int $proxyId): void {}

function b2DynamicTree_MoveProxy(b2DynamicTree $tree, int $proxyId, b2AABB $aabb): void {}

function b2DynamicTree_EnlargeProxy(b2DynamicTree $tree, int $proxyId, b2AABB $aabb): void {}

function b2DynamicTree_SetCategoryBits(b2DynamicTree $tree, int $proxyId, int $categoryBits): void {}

function b2DynamicTree_GetCategoryBits(b2DynamicTree $tree, int $proxyId): int {}

/** $callback is fn(int $proxyId, int $userData, mixed $context): bool */
function b2DynamicTree_Query(b2DynamicTree $tree, b2AABB $aabb, int $maskBits, callable $callback, mixed $context): b2TreeStats {}

/** $callback is fn(b2RayCastInput $input, int $proxyId, int $userData, mixed $context): float */
function b2DynamicTree_RayCast(b2DynamicTree $tree, b2RayCastInput $input, int $maskBits, callable $callback, mixed $context): b2TreeStats {}

/** $callback is fn(b2ShapeCastInput $input, int $proxyId, int $userData, mixed $context): float */
function b2DynamicTree_ShapeCast(b2DynamicTree $tree, b2ShapeCastInput $input, int $maskBits, callable $callback, mixed $context): b2TreeStats {}

function b2DynamicTree_GetHeight(b2DynamicTree $tree): int {}

function b2DynamicTree_GetAreaRatio(b2DynamicTree $tree): float {}

function b2DynamicTree_GetRootBounds(b2DynamicTree $tree): b2AABB {}

function b2DynamicTree_GetProxyCount(b2DynamicTree $tree): int {}

function b2DynamicTree_Rebuild(b2DynamicTree $tree, bool $fullBuild): int {}

function b2DynamicTree_GetByteCount(b2DynamicTree $tree): int {}

function b2DynamicTree_GetUserData(b2DynamicTree $tree, int $proxyId): int {}

function b2DynamicTree_GetAABB(b2DynamicTree $tree, int $proxyId): b2AABB {}

function b2DynamicTree_Validate(b2DynamicTree $tree): void {}

function b2DynamicTree_ValidateNoEnlarged(b2DynamicTree $tree): void {}

/** $planes is a list of b2CollisionPlane. Each object's push is updated in place. $count is how many planes to read. */
function b2SolvePlanes(b2Vec2 $targetDelta, array $planes, int $count): b2PlaneSolverResult {}

/** $planes is a list of b2CollisionPlane. $count is how many planes to read. */
function b2ClipVector(b2Vec2 $vector, array $planes, int $count): b2Vec2 {}
