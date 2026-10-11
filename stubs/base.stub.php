<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue B2_HASH_INIT
 */
const B2_HASH_INIT = UNKNOWN;

/**
 * Version numbering scheme.
 * See https://semver.org/
 */
final class b2Version
{
    /** Significant changes */
    public int $major = 0;

    /** Incremental changes */
    public int $minor = 0;

    /** Bug fixes */
    public int $revision = 0;

    public function __construct(int $major = 0, int $minor = 0, int $revision = 0) {}
}

/** Get the current version of Box2D */
function b2GetVersion(): b2Version {}

function b2GetByteCount(): int {}

function b2GetTicks(): int {}

function b2GetMilliseconds(int $ticks): float {}

function b2GetMillisecondsAndReset(int &$ticks): float {}

function b2Yield(): void {}

function b2Hash(int $hash, string $data, int $count): int {}

/**
 * A Box2D assertion failed.
 * The message is "<condition> at <file>:<line>".
 */
class b2AssertionError extends Error
{
}
