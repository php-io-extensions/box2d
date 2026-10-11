# ext-box2d

[![Latest Version on Packagist](https://img.shields.io/packagist/v/php-io-extensions/box2d.svg)](https://packagist.org/packages/php-io-extensions/box2d)
[![License](https://img.shields.io/packagist/l/php-io-extensions/box2d.svg)](LICENSE)

1:1 PHP bindings of [Box2D](https://github.com/erincatto/box2d) v3.1.1, Erin Catto's 2D physics engine: worlds, bodies, shapes, chains, the eight joint types, events, queries, debug draw, and the collision and math libraries underneath. Version 0.10.0. Linux and macOS. PHP 8.4, NTS and ZTS.

Box2D ships inside the extension, from tag `v3.1.1` (commit `8c661469c9507d3ad6fbd2fea3f1aa71669c2fe3`), copied unchanged into `lib/box2d/`. Nothing to install from the system.

## Requirements

- PHP 8.4, NTS or ZTS
- A C compiler. Debian trixie and Raspberry Pi OS: `apt install build-essential php8.4-dev`

## Install

Through PIE:

```bash
pie install php-io-extensions/box2d
```

From a checkout:

```bash
./install-macos.sh              # Homebrew php@8.4 and php@8.4-zts
./install-debian-trixie.sh      # Debian trixie / Raspberry Pi OS
```

The macOS installer ad-hoc signs the `.so` and writes `30-box2d.ini`, unless an ini in that PHP's scan directory already loads `box2d`. Pass other PHP binaries as arguments to install those instead. `php --ri box2d` shows the extension version and the Box2D version and commit.

## A falling box

```php
$world = b2CreateWorld(b2DefaultWorldDef());                 // gravity (0, -10)

$ground = b2CreateBody($world, b2DefaultBodyDef());
b2CreatePolygonShape($ground, b2DefaultShapeDef(), b2MakeBox(50.0, 1.0));

$def = b2DefaultBodyDef();
$def->type = b2_dynamicBody;
$def->position = new b2Vec2(0.0, 4.0);
$box = b2CreateBody($world, $def);
$shape = b2DefaultShapeDef();
$shape->density = 1.0;
$shape->material->friction = 0.3;
b2CreatePolygonShape($box, $shape, b2MakeBox(1.0, 1.0));

for ($i = 0; $i < 90; $i++) {
    b2World_Step($world, 1.0 / 60.0, 4);
}
$p = b2Body_GetPosition($box);
printf("%.2f %.2f\n", $p->x, $p->y);                         // 0.00 2.00: at rest on the ground

b2DestroyWorld($world);
```

## Names

Function, struct, enum and constant names are the C names. The translations:

- A struct is a `final` class of the same name with one typed property per field, in field order; the constructor takes every field, zero by default. Ids (`b2WorldId`, `b2BodyId` …) are struct classes.
- A fixed C array in a struct is a list. A `const T*` argument is a `T` object; a scalar out-parameter is by-reference; an output array with a capacity is `?array &$list, int $capacity`, returning the count.
- `uint64_t` bits are PHP `int` with the same 64 bits (`B2_DEFAULT_MASK_BITS` is `-1`). Narrow integers are range-checked.
- A callback is a `callable` with its `mixed $context` passed through unchanged. Struct fields holding callbacks (`b2WorldDef.frictionCallback`, `b2DebugDraw.Draw*Fcn`) are `?Closure`.
- Static values (`b2_nullBodyId`, `b2Vec2_zero`, `b2Transform_identity` …) are functions returning a fresh instance.
- `b2DynamicTree` is an opaque handle, destroyed when its last reference goes if `b2DynamicTree_Destroy` was not called.

## Errors

- A dead id, a def not made by a `b2Default*Def()` function, or an integer out of range is a `ValueError` before Box2D sees it.
- A failed Box2D assertion is a `b2AssertionError` naming the condition, file and line.
- While a world steps, its callbacks may read what Box2D does not write during a step (validity, types, user data, filters, materials); any other call on that world is an `Error("world is stepping")`.
- An exception thrown in a callback stops that callable for the rest of the step (Box2D's default answer is used) and is rethrown when the call returns. A return value of the wrong type is a `TypeError`.

## Workers

Set `b2WorldDef::$workerCount` above 1 and the world gets its own pool of `min(workerCount, 64)` threads for its steps. `b2World_Step` still blocks until the step is done; the pool only spreads it over more cores. Results are identical bit for bit for every worker count.

Friction, restitution, custom filter and pre-solve callables still run on the PHP thread that called `b2World_Step`: a worker thread hands the call over and waits. A pool does not survive `fork()`, so stepping a pooled world in a child is an `Error`; serial worlds keep working. Each request's worlds, pools and dynamic trees are freed when the request ends.

## Reference

Every function, class and constant is declared with its PHP types in [`stubs/`](stubs), one stub per Box2D header (`base`, `box2d`, `collision`, `id`, `math_functions`, `types`). Box2D's own [documentation](https://box2d.org/documentation/) describes the behaviour; the names above map it to PHP.

## Upgrading

This is the first release.

## Tests

```bash
composer install
php -d memory_limit=128M vendor/bin/pest
```

## Security

ext-box2d runs Box2D's C code on values from PHP, and threads when a world has workers. See [SECURITY.md](SECURITY.md) for what it guards against and how to report a vulnerability.

## License

MIT. Box2D is MIT, Copyright (c) 2022 Erin Catto: `lib/box2d/LICENSE`.
