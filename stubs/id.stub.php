<?php

/** @generate-class-entries */

final class b2WorldId
{
    public int $index1 = 0;
    public int $generation = 0;

    public function __construct(int $index1 = 0, int $generation = 0) {}
}

final class b2BodyId
{
    public int $index1 = 0;
    public int $world0 = 0;
    public int $generation = 0;

    public function __construct(int $index1 = 0, int $world0 = 0, int $generation = 0) {}
}

final class b2ShapeId
{
    public int $index1 = 0;
    public int $world0 = 0;
    public int $generation = 0;

    public function __construct(int $index1 = 0, int $world0 = 0, int $generation = 0) {}
}

final class b2ChainId
{
    public int $index1 = 0;
    public int $world0 = 0;
    public int $generation = 0;

    public function __construct(int $index1 = 0, int $world0 = 0, int $generation = 0) {}
}

final class b2JointId
{
    public int $index1 = 0;
    public int $world0 = 0;
    public int $generation = 0;

    public function __construct(int $index1 = 0, int $world0 = 0, int $generation = 0) {}
}

function B2_IS_NULL(b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId $id): bool {}

function B2_IS_NON_NULL(b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId $id): bool {}

function B2_ID_EQUALS(b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId $id1, b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId $id2): bool {}

function b2StoreWorldId(b2WorldId $id): int {}

function b2LoadWorldId(int $x): b2WorldId {}

function b2StoreBodyId(b2BodyId $id): int {}

function b2LoadBodyId(int $x): b2BodyId {}

function b2StoreShapeId(b2ShapeId $id): int {}

function b2LoadShapeId(int $x): b2ShapeId {}

function b2StoreChainId(b2ChainId $id): int {}

function b2LoadChainId(int $x): b2ChainId {}

function b2StoreJointId(b2JointId $id): int {}

function b2LoadJointId(int $x): b2JointId {}

function b2_nullWorldId(): b2WorldId {}

function b2_nullBodyId(): b2BodyId {}

function b2_nullShapeId(): b2ShapeId {}

function b2_nullChainId(): b2ChainId {}

function b2_nullJointId(): b2JointId {}
