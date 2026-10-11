<?php

declare(strict_types=1);

/**
 * base.h, id.h, and math_functions.h.
 * Identity cases are the ones the phase names. A second small-integer case
 * is included wherever returning the input unchanged would also pass.
 */

function vec(float $x, float $y): b2Vec2
{
    return new b2Vec2($x, $y);
}

function rot(float $c, float $s): b2Rot
{
    return new b2Rot($c, $s);
}

function identityRot(): b2Rot
{
    return rot(1.0, 0.0);
}

function translated(float $x, float $y): b2Transform
{
    return new b2Transform(vec($x, $y), identityRot());
}

function aabb(float $x0, float $y0, float $x1, float $y1): b2AABB
{
    return new b2AABB(vec($x0, $y0), vec($x1, $y1));
}

function expectVec(b2Vec2 $vector, float $x, float $y): void
{
    expect($vector->x)->toBe($x)
        ->and($vector->y)->toBe($y);
}

function expectRot(b2Rot $rotation, float $c, float $s): void
{
    expect($rotation->c)->toBe($c)
        ->and($rotation->s)->toBe($s);
}

function expectSameVec(b2Vec2 $vector, b2Vec2 $other): void
{
    expectVec($vector, $other->x, $other->y);
}

it('publishes the mask, pi, and hash constants', function (): void {
    expect(B2_DEFAULT_MASK_BITS)->toBe(-1)
        ->and(B2_PI)->toBeFloat()
        ->and(B2_HASH_INIT)->toBe(5381);
});

it('reports the byte count, ticks, and a yielded timeslice', function (): void {
    expect(b2GetByteCount())->toBeInt()->toBeGreaterThanOrEqual(0);

    $ticks = b2GetTicks();
    expect($ticks)->toBeInt()->toBeGreaterThan(0);

    $elapsed = b2GetMilliseconds($ticks);
    expect($elapsed)->toBeFloat()->toBeGreaterThanOrEqual(0.0);

    $cursor = $ticks;
    $reset = b2GetMillisecondsAndReset($cursor);
    expect($reset)->toBeFloat()->toBeGreaterThanOrEqual(0.0)
        ->and($cursor)->toBeInt()->toBeGreaterThanOrEqual($ticks);

    expect(b2Yield())->toBeNull();
});

it('hashes the prefix of a string and rejects a count past the buffer', function (): void {
    expect(b2Hash(B2_HASH_INIT, 'ab', 0))->toBe(B2_HASH_INIT)
        ->and(b2Hash(B2_HASH_INIT, 'abX', 2))->toBe(5863208)
        ->and(b2Hash(B2_HASH_INIT, 'ab', 2))->toBe(5863208);

    expect(fn () => b2Hash(B2_HASH_INIT, 'ab', 3))->toThrow(ValueError::class);
    expect(fn () => b2Hash(B2_HASH_INIT, 'ab', -1))->toThrow(ValueError::class);
});

it('round-trips every id through its store and load functions', function (): void {
    $world = b2LoadWorldId(b2StoreWorldId(new b2WorldId(4, 9)));
    expect($world->index1)->toBe(4)->and($world->generation)->toBe(9);

    $body = b2LoadBodyId(b2StoreBodyId(new b2BodyId(-1, 2, 3)));
    expect($body->index1)->toBe(-1)->and($body->world0)->toBe(2)->and($body->generation)->toBe(3);

    $shape = b2LoadShapeId(b2StoreShapeId(new b2ShapeId(6, 1, 8)));
    expect($shape->index1)->toBe(6)->and($shape->world0)->toBe(1)->and($shape->generation)->toBe(8);

    $chain = b2LoadChainId(b2StoreChainId(new b2ChainId(5, 7, 2)));
    expect($chain->index1)->toBe(5)->and($chain->world0)->toBe(7)->and($chain->generation)->toBe(2);

    $joint = b2LoadJointId(b2StoreJointId(new b2JointId(11, 1, 4)));
    expect($joint->index1)->toBe(11)->and($joint->world0)->toBe(1)->and($joint->generation)->toBe(4);
});

it('returns a fresh null id and a fresh zero vector on every call', function (): void {
    $worlds = [b2_nullWorldId(), b2_nullWorldId()];
    $bodies = [b2_nullBodyId(), b2_nullBodyId()];
    $shapes = [b2_nullShapeId(), b2_nullShapeId()];
    $chains = [b2_nullChainId(), b2_nullChainId()];
    $joints = [b2_nullJointId(), b2_nullJointId()];
    $zeroes = [b2Vec2_zero(), b2Vec2_zero()];

    expect($worlds[0])->not->toBe($worlds[1])
        ->and($worlds[0]->index1)->toBe(0)
        ->and($worlds[0]->generation)->toBe(0)
        ->and(B2_IS_NULL($worlds[0]))->toBeTrue()
        ->and($bodies[0])->not->toBe($bodies[1])
        ->and($bodies[0]->index1)->toBe(0)
        ->and($shapes[0])->not->toBe($shapes[1])
        ->and($shapes[0]->index1)->toBe(0)
        ->and($chains[0])->not->toBe($chains[1])
        ->and($chains[0]->index1)->toBe(0)
        ->and($joints[0])->not->toBe($joints[1])
        ->and($joints[0]->index1)->toBe(0)
        ->and($zeroes[0])->not->toBe($zeroes[1]);
    expectVec($zeroes[0], 0.0, 0.0);

    $rotation = b2Rot_identity();
    expect($rotation)->not->toBe(b2Rot_identity());
    expectRot($rotation, 1.0, 0.0);

    $transform = b2Transform_identity();
    expect($transform)->not->toBe(b2Transform_identity());
    expectVec($transform->p, 0.0, 0.0);
    expectRot($transform->q, 1.0, 0.0);

    $matrix = b2Mat22_zero();
    expect($matrix)->not->toBe(b2Mat22_zero());
    expectVec($matrix->cx, 0.0, 0.0);
    expectVec($matrix->cy, 0.0, 0.0);
});

it('checks scalars, vectors, rotations, boxes, and planes', function (): void {
    expect(b2IsValidFloat(1.0))->toBeTrue()
        ->and(b2IsValidFloat(NAN))->toBeFalse()
        ->and(b2IsValidFloat(INF))->toBeFalse()
        ->and(b2IsValidVec2(vec(1.0, 2.0)))->toBeTrue()
        ->and(b2IsValidVec2(vec(NAN, 0.0)))->toBeFalse()
        ->and(b2IsValidRotation(identityRot()))->toBeTrue()
        ->and(b2IsValidRotation(rot(0.0, 0.0)))->toBeFalse()
        ->and(b2IsValidAABB(aabb(0.0, 0.0, 1.0, 1.0)))->toBeTrue()
        ->and(b2IsValidAABB(aabb(2.0, 0.0, 1.0, 1.0)))->toBeFalse()
        ->and(b2IsValidPlane(new b2Plane(vec(1.0, 0.0), 0.0)))->toBeTrue()
        ->and(b2IsValidPlane(new b2Plane(vec(2.0, 0.0), 0.0)))->toBeFalse();
});

it('clamps integers and floats', function (): void {
    expect(b2MinInt(2, 5))->toBe(2)
        ->and(b2MaxInt(2, 5))->toBe(5)
        ->and(b2AbsInt(-3))->toBe(3)
        ->and(b2ClampInt(10, 0, 4))->toBe(4)
        ->and(b2MinFloat(2.0, 5.0))->toBe(2.0)
        ->and(b2MaxFloat(2.0, 5.0))->toBe(5.0)
        ->and(b2AbsFloat(-1.5))->toBe(1.5)
        ->and(b2ClampFloat(10.0, 0.0, 4.0))->toBe(4.0);
});

it('computes atan2 and cosine-sine of zero', function (): void {
    expect(b2Atan2(0.0, 1.0))->toBe(0.0)
        ->and(b2Atan2(0.0, 0.0))->toBe(0.0);

    $angle = b2ComputeCosSin(0.0);
    expect($angle->cosine)->toBe(1.0)
        ->and($angle->sine)->toBe(0.0);
});

it('adds, multiplies, and crosses vectors', function (): void {
    expect(b2Dot(vec(1.0, 0.0), vec(0.0, 1.0)))->toBe(0.0)
        ->and(b2Dot(vec(2.0, 0.0), vec(3.0, 0.0)))->toBe(6.0)
        ->and(b2Cross(vec(1.0, 0.0), vec(0.0, 1.0)))->toBe(1.0);

    expectVec(b2CrossVS(vec(1.0, 0.0), 2.0), 0.0, -2.0);
    expectVec(b2CrossSV(2.0, vec(1.0, 0.0)), 0.0, 2.0);
    expectVec(b2LeftPerp(vec(2.0, 0.0)), 0.0, 2.0);
    expectVec(b2RightPerp(vec(2.0, 0.0)), 0.0, -2.0);
    expectVec(b2Add(vec(1.0, 2.0), vec(3.0, 4.0)), 4.0, 6.0);
    expectVec(b2Sub(vec(3.0, 4.0), vec(1.0, 2.0)), 2.0, 2.0);
    expectVec(b2Neg(vec(1.0, -2.0)), -1.0, 2.0);
    expectVec(b2Lerp(vec(0.0, 0.0), vec(4.0, 8.0), 0.5), 2.0, 4.0);
    expectVec(b2Mul(vec(2.0, 3.0), vec(4.0, 5.0)), 8.0, 15.0);
    expectVec(b2MulSV(2.0, vec(3.0, 4.0)), 6.0, 8.0);
    expectVec(b2MulAdd(vec(1.0, 2.0), 3.0, vec(4.0, 5.0)), 13.0, 17.0);
    expectVec(b2MulSub(vec(10.0, 10.0), 2.0, vec(3.0, 4.0)), 4.0, 2.0);
    expectVec(b2Abs(vec(-2.0, 3.0)), 2.0, 3.0);
    expectVec(b2Min(vec(1.0, 5.0), vec(2.0, 3.0)), 1.0, 3.0);
    expectVec(b2Max(vec(1.0, 5.0), vec(2.0, 3.0)), 2.0, 5.0);
    expectVec(b2Clamp(vec(5.0, -1.0), vec(0.0, 0.0), vec(2.0, 2.0)), 2.0, 0.0);
});

it('measures and normalizes vectors', function (): void {
    expect(b2Length(vec(0.0, 4.0)))->toBe(4.0)
        ->and(b2Distance(vec(0.0, 0.0), vec(0.0, 4.0)))->toBe(4.0)
        ->and(b2LengthSquared(vec(3.0, 4.0)))->toBe(25.0)
        ->and(b2DistanceSquared(vec(0.0, 0.0), vec(3.0, 4.0)))->toBe(25.0)
        ->and(b2IsNormalized(vec(0.0, 1.0)))->toBeTrue()
        ->and(b2IsNormalized(vec(2.0, 0.0)))->toBeFalse();

    expectVec(b2Normalize(vec(0.0, 4.0)), 0.0, 1.0);
    expectVec(b2Normalize(vec(0.0, 0.0)), 0.0, 0.0);

    $length = 0.0;
    $unit = b2GetLengthAndNormalize($length, vec(0.0, 4.0));
    expect($length)->toBe(4.0);
    expectVec($unit, 0.0, 1.0);
});

it('builds and composes rotations', function (): void {
    expectRot(b2MakeRot(0.0), 1.0, 0.0);
    expectRot(b2ComputeRotationBetweenUnitVectors(vec(1.0, 0.0), vec(0.0, 1.0)), 0.0, 1.0);
    expect(b2IsNormalizedRot(identityRot()))->toBeTrue()
        ->and(b2IsNormalizedRot(rot(2.0, 0.0)))->toBeFalse();

    expectRot(b2NormalizeRot(rot(4.0, 0.0)), 1.0, 0.0);
    expectRot(b2IntegrateRotation(identityRot(), 0.0), 1.0, 0.0);
    expectRot(b2NLerp(identityRot(), identityRot(), 0.5), 1.0, 0.0);
    expectRot(b2MulRot(identityRot(), rot(0.0, 1.0)), 0.0, 1.0);
    expectRot(b2InvMulRot(rot(0.0, 1.0), rot(0.0, 1.0)), 1.0, 0.0);

    expect(b2ComputeAngularVelocity(identityRot(), identityRot(), 1.0))->toBe(0.0)
        ->and(b2Rot_GetAngle(identityRot()))->toBe(0.0)
        ->and(b2RelativeAngle(identityRot(), identityRot()))->toBe(0.0)
        ->and(b2UnwindAngle(0.0))->toBe(0.0);

    expectVec(b2Rot_GetXAxis(identityRot()), 1.0, 0.0);
    expectVec(b2Rot_GetYAxis(identityRot()), 0.0, 1.0);
    expectVec(b2RotateVector(rot(0.0, 1.0), vec(1.0, 0.0)), 0.0, 1.0);
    expectVec(b2InvRotateVector(rot(0.0, 1.0), vec(0.0, 1.0)), 1.0, 0.0);
});

it('transforms points and multiplies transforms', function (): void {
    $point = vec(1.0, 2.0);
    expectSameVec(b2TransformPoint(b2Transform_identity(), $point), $point);
    expectVec(b2TransformPoint(translated(3.0, 4.0), $point), 4.0, 6.0);
    expectSameVec(b2InvTransformPoint(b2Transform_identity(), $point), $point);
    expectVec(b2InvTransformPoint(translated(3.0, 4.0), vec(4.0, 6.0)), 1.0, 2.0);

    $product = b2MulTransforms(translated(3.0, 4.0), translated(1.0, 2.0));
    expectVec($product->p, 4.0, 6.0);
    expectRot($product->q, 1.0, 0.0);

    $inverse = b2InvMulTransforms(translated(3.0, 4.0), translated(4.0, 6.0));
    expectVec($inverse->p, 1.0, 2.0);
    expectRot($inverse->q, 1.0, 0.0);
});

it('solves a 2-by-2 system and inverts the identity', function (): void {
    $identity = new b2Mat22(vec(1.0, 0.0), vec(0.0, 1.0));
    $scaled = new b2Mat22(vec(2.0, 0.0), vec(0.0, 2.0));
    $rightHandSide = vec(2.0, 3.0);

    expectSameVec(b2MulMV($identity, $rightHandSide), $rightHandSide);
    expectVec(b2MulMV($scaled, vec(2.0, 3.0)), 4.0, 6.0);
    expectSameVec(b2Solve22($identity, $rightHandSide), $rightHandSide);
    expectVec(b2Solve22($scaled, vec(4.0, 6.0)), 2.0, 3.0);

    $inverse = b2GetInverse22($identity);
    expectVec($inverse->cx, 1.0, 0.0);
    expectVec($inverse->cy, 0.0, 1.0);

    $inverseScaled = b2GetInverse22($scaled);
    expectVec($inverseScaled->cx, 0.5, 0.0);
    expectVec($inverseScaled->cy, 0.0, 0.5);
});

it('contains, overlaps, and unions boxes', function (): void {
    $unit = aabb(0.0, 0.0, 1.0, 1.0);
    $larger = aabb(0.0, 0.0, 2.0, 2.0);
    $disjoint = aabb(3.0, 3.0, 4.0, 4.0);

    expect(b2AABB_Contains($larger, $unit))->toBeTrue()
        ->and(b2AABB_Contains($unit, $larger))->toBeFalse()
        ->and(b2AABB_Overlaps($unit, $larger))->toBeTrue()
        ->and(b2AABB_Overlaps($unit, $disjoint))->toBeFalse();

    expectVec(b2AABB_Center($larger), 1.0, 1.0);
    expectVec(b2AABB_Extents($larger), 1.0, 1.0);

    $union = b2AABB_Union($unit, $disjoint);
    expectVec($union->lowerBound, 0.0, 0.0);
    expectVec($union->upperBound, 4.0, 4.0);

    $made = b2MakeAABB([vec(1.0, 2.0), vec(9.0, 9.0)], 1, 0.0);
    expectVec($made->lowerBound, 1.0, 2.0);
    expectVec($made->upperBound, 1.0, 2.0);

    $padded = b2MakeAABB([vec(0.0, 0.0), vec(2.0, 4.0)], 2, 1.0);
    expectVec($padded->lowerBound, -1.0, -1.0);
    expectVec($padded->upperBound, 3.0, 5.0);

    expect(fn () => b2MakeAABB([vec(1.0, 2.0)], 2, 0.0))->toThrow(ValueError::class);
});

it('separates a point from a plane and damps a spring at rest frequency', function (): void {
    expect(b2PlaneSeparation(new b2Plane(vec(0.0, 1.0), 0.0), vec(0.0, 4.0)))->toBe(4.0)
        ->and(b2SpringDamper(0.0, 0.0, 1.0, 2.0, 0.25))->toBe(2.0);
});

it('sets the process-global length units and restores the previous value', function (): void {
    $previous = b2GetLengthUnitsPerMeter();

    try {
        b2SetLengthUnitsPerMeter(32.0);
        expect(b2GetLengthUnitsPerMeter())->toBe(32.0);
    } finally {
        b2SetLengthUnitsPerMeter($previous);
    }

    expect(b2GetLengthUnitsPerMeter())->toBe($previous);
});
