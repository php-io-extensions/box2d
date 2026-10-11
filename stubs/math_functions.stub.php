<?php

/** @generate-class-entries */

/**
 * @var float
 * @cvalue B2_PI
 */
const B2_PI = UNKNOWN;

final class b2Vec2
{
    public float $x = 0.0;
    public float $y = 0.0;

    public function __construct(float $x = 0.0, float $y = 0.0) {}
}

final class b2CosSin
{
    public float $cosine = 0.0;
    public float $sine = 0.0;

    public function __construct(float $cosine = 0.0, float $sine = 0.0) {}
}

final class b2Rot
{
    public float $c = 0.0;
    public float $s = 0.0;

    public function __construct(float $c = 0.0, float $s = 0.0) {}
}

final class b2Transform
{
    public b2Vec2 $p;
    public b2Rot $q;

    public function __construct(b2Vec2 $p = new b2Vec2(), b2Rot $q = new b2Rot()) {}
}

final class b2Mat22
{
    public b2Vec2 $cx;
    public b2Vec2 $cy;

    public function __construct(b2Vec2 $cx = new b2Vec2(), b2Vec2 $cy = new b2Vec2()) {}
}

final class b2AABB
{
    public b2Vec2 $lowerBound;
    public b2Vec2 $upperBound;

    public function __construct(b2Vec2 $lowerBound = new b2Vec2(), b2Vec2 $upperBound = new b2Vec2()) {}
}

final class b2Plane
{
    public b2Vec2 $normal;
    public float $offset = 0.0;

    public function __construct(b2Vec2 $normal = new b2Vec2(), float $offset = 0.0) {}
}

function b2Vec2_zero(): b2Vec2 {}

function b2Rot_identity(): b2Rot {}

function b2Transform_identity(): b2Transform {}

function b2Mat22_zero(): b2Mat22 {}

function b2IsValidFloat(float $a): bool {}

function b2IsValidVec2(b2Vec2 $v): bool {}

function b2IsValidRotation(b2Rot $q): bool {}

function b2IsValidAABB(b2AABB $aabb): bool {}

function b2IsValidPlane(b2Plane $a): bool {}

function b2MinInt(int $a, int $b): int {}

function b2MaxInt(int $a, int $b): int {}

function b2AbsInt(int $a): int {}

function b2ClampInt(int $a, int $lower, int $upper): int {}

function b2MinFloat(float $a, float $b): float {}

function b2MaxFloat(float $a, float $b): float {}

function b2AbsFloat(float $a): float {}

function b2ClampFloat(float $a, float $lower, float $upper): float {}

function b2Atan2(float $y, float $x): float {}

function b2ComputeCosSin(float $radians): b2CosSin {}

function b2Dot(b2Vec2 $a, b2Vec2 $b): float {}

function b2Cross(b2Vec2 $a, b2Vec2 $b): float {}

function b2CrossVS(b2Vec2 $v, float $s): b2Vec2 {}

function b2CrossSV(float $s, b2Vec2 $v): b2Vec2 {}

function b2LeftPerp(b2Vec2 $v): b2Vec2 {}

function b2RightPerp(b2Vec2 $v): b2Vec2 {}

function b2Add(b2Vec2 $a, b2Vec2 $b): b2Vec2 {}

function b2Sub(b2Vec2 $a, b2Vec2 $b): b2Vec2 {}

function b2Neg(b2Vec2 $a): b2Vec2 {}

function b2Lerp(b2Vec2 $a, b2Vec2 $b, float $t): b2Vec2 {}

function b2Mul(b2Vec2 $a, b2Vec2 $b): b2Vec2 {}

function b2MulSV(float $s, b2Vec2 $v): b2Vec2 {}

function b2MulAdd(b2Vec2 $a, float $s, b2Vec2 $b): b2Vec2 {}

function b2MulSub(b2Vec2 $a, float $s, b2Vec2 $b): b2Vec2 {}

function b2Abs(b2Vec2 $a): b2Vec2 {}

function b2Min(b2Vec2 $a, b2Vec2 $b): b2Vec2 {}

function b2Max(b2Vec2 $a, b2Vec2 $b): b2Vec2 {}

function b2Clamp(b2Vec2 $v, b2Vec2 $a, b2Vec2 $b): b2Vec2 {}

function b2Length(b2Vec2 $v): float {}

function b2Distance(b2Vec2 $a, b2Vec2 $b): float {}

function b2Normalize(b2Vec2 $v): b2Vec2 {}

function b2IsNormalized(b2Vec2 $a): bool {}

function b2GetLengthAndNormalize(float &$length, b2Vec2 $v): b2Vec2 {}

function b2NormalizeRot(b2Rot $q): b2Rot {}

function b2IntegrateRotation(b2Rot $q1, float $deltaAngle): b2Rot {}

function b2LengthSquared(b2Vec2 $v): float {}

function b2DistanceSquared(b2Vec2 $a, b2Vec2 $b): float {}

function b2MakeRot(float $radians): b2Rot {}

function b2ComputeRotationBetweenUnitVectors(b2Vec2 $v1, b2Vec2 $v2): b2Rot {}

function b2IsNormalizedRot(b2Rot $q): bool {}

function b2NLerp(b2Rot $q1, b2Rot $q2, float $t): b2Rot {}

function b2ComputeAngularVelocity(b2Rot $q1, b2Rot $q2, float $inv_h): float {}

function b2Rot_GetAngle(b2Rot $q): float {}

function b2Rot_GetXAxis(b2Rot $q): b2Vec2 {}

function b2Rot_GetYAxis(b2Rot $q): b2Vec2 {}

function b2MulRot(b2Rot $q, b2Rot $r): b2Rot {}

function b2InvMulRot(b2Rot $q, b2Rot $r): b2Rot {}

function b2RelativeAngle(b2Rot $b, b2Rot $a): float {}

function b2UnwindAngle(float $radians): float {}

function b2RotateVector(b2Rot $q, b2Vec2 $v): b2Vec2 {}

function b2InvRotateVector(b2Rot $q, b2Vec2 $v): b2Vec2 {}

function b2TransformPoint(b2Transform $t, b2Vec2 $p): b2Vec2 {}

function b2InvTransformPoint(b2Transform $t, b2Vec2 $p): b2Vec2 {}

function b2MulTransforms(b2Transform $A, b2Transform $B): b2Transform {}

function b2InvMulTransforms(b2Transform $A, b2Transform $B): b2Transform {}

function b2MulMV(b2Mat22 $A, b2Vec2 $v): b2Vec2 {}

function b2GetInverse22(b2Mat22 $A): b2Mat22 {}

function b2Solve22(b2Mat22 $A, b2Vec2 $b): b2Vec2 {}

function b2AABB_Contains(b2AABB $a, b2AABB $b): bool {}

function b2AABB_Center(b2AABB $a): b2Vec2 {}

function b2AABB_Extents(b2AABB $a): b2Vec2 {}

function b2AABB_Union(b2AABB $a, b2AABB $b): b2AABB {}

function b2AABB_Overlaps(b2AABB $a, b2AABB $b): bool {}

/** $points is a list of b2Vec2. $count is how many of those points to read. */
function b2MakeAABB(array $points, int $count, float $radius): b2AABB {}

function b2PlaneSeparation(b2Plane $plane, b2Vec2 $point): float {}

function b2SpringDamper(float $hertz, float $dampingRatio, float $position, float $velocity, float $timeStep): float {}

function b2SetLengthUnitsPerMeter(float $lengthUnits): void {}

function b2GetLengthUnitsPerMeter(): float {}
