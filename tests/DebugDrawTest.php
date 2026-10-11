<?php

declare(strict_types=1);

it('invokes each debug draw closure with its argument types', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $static = b2CreateBody($world, b2DefaultBodyDef());
    b2Body_SetName($static, 'ground');
    b2CreatePolygonShape($static, b2DefaultShapeDef(), b2MakeBox(4.0, 0.5));
    b2CreateCircleShape($static, b2DefaultShapeDef(), new b2Circle(new b2Vec2(2.0, 1.0), 0.3));
    b2CreateCapsuleShape($static, b2DefaultShapeDef(), new b2Capsule(new b2Vec2(-2.0, 0.5), new b2Vec2(-2.0, 1.2), 0.2));
    b2CreateSegmentShape($static, b2DefaultShapeDef(), new b2Segment(new b2Vec2(-1.0, 2.0), new b2Vec2(1.0, 2.0)));

    $chain = b2DefaultChainDef();
    $chain->points = [new b2Vec2(-3.0, 3.0), new b2Vec2(-2.0, 3.0), new b2Vec2(-2.0, 4.0), new b2Vec2(-3.0, 4.0)];
    $chain->count = 4;
    $chain->isLoop = true;
    b2CreateChain($static, $chain);

    $dynamicDefinition = b2DefaultBodyDef();
    $dynamicDefinition->type = b2_dynamicBody;
    $dynamicDefinition->position = new b2Vec2(0.0, 1.2);
    $dynamicDefinition->enableSleep = false;
    $dynamic = b2CreateBody($world, $dynamicDefinition);
    b2CreatePolygonShape($dynamic, b2DefaultShapeDef(), b2MakeBox(0.4, 0.4));

    $joint = b2DefaultRevoluteJointDef();
    $joint->bodyIdA = $static;
    $joint->bodyIdB = $dynamic;
    $joint->localAnchorA = new b2Vec2(0.0, 1.2);
    $joint->localAnchorB = new b2Vec2(0.0, 0.0);
    $joint->drawSize = 0.4;
    b2CreateRevoluteJoint($world, $joint);
    b2World_Step($world, 1.0 / 60.0, 4);

    $seen = [];
    $draw = b2DefaultDebugDraw();
    $draw->drawShapes = true;
    $draw->drawJoints = true;
    $draw->drawJointExtras = true;
    $draw->drawBounds = true;
    $draw->drawMass = true;
    $draw->drawBodyNames = true;
    $draw->drawContacts = true;
    $draw->drawContactNormals = true;
    $draw->drawContactFeatures = true;
    $draw->context = 'pen';

    $draw->DrawPolygonFcn = function (array $vertices, int $vertexCount, int $color, mixed $context) use (&$seen): void {
        expect($vertices)->toHaveCount($vertexCount)
            ->and($vertices[0])->toBeInstanceOf(b2Vec2::class)
            ->and($context)->toBe('pen');
        $seen['polygon'] = true;
    };
    $draw->DrawSolidPolygonFcn = function (b2Transform $transform, array $vertices, int $vertexCount, float $radius, int $color, mixed $context) use (&$seen): void {
        expect($transform)->toBeInstanceOf(b2Transform::class)
            ->and($vertices)->toHaveCount($vertexCount)
            ->and($context)->toBe('pen');
        $seen['solidPolygon'] = true;
    };
    $draw->DrawCircleFcn = function (b2Vec2 $center, float $radius, int $color, mixed $context) use (&$seen): void {
        expect($center)->toBeInstanceOf(b2Vec2::class)->and($context)->toBe('pen');
        $seen['circle'] = true;
    };
    $draw->DrawSolidCircleFcn = function (b2Transform $transform, float $radius, int $color, mixed $context) use (&$seen): void {
        expect($transform)->toBeInstanceOf(b2Transform::class)->and($context)->toBe('pen');
        $seen['solidCircle'] = true;
    };
    $draw->DrawSolidCapsuleFcn = function (b2Vec2 $p1, b2Vec2 $p2, float $radius, int $color, mixed $context) use (&$seen): void {
        expect($p1)->toBeInstanceOf(b2Vec2::class)
            ->and($p2)->toBeInstanceOf(b2Vec2::class)
            ->and($context)->toBe('pen');
        $seen['capsule'] = true;
    };
    $draw->DrawSegmentFcn = function (b2Vec2 $p1, b2Vec2 $p2, int $color, mixed $context) use (&$seen): void {
        expect($p1)->toBeInstanceOf(b2Vec2::class)
            ->and($p2)->toBeInstanceOf(b2Vec2::class)
            ->and($context)->toBe('pen');
        $seen['segment'] = true;
    };
    $draw->DrawTransformFcn = function (b2Transform $transform, mixed $context) use (&$seen): void {
        expect($transform)->toBeInstanceOf(b2Transform::class)->and($context)->toBe('pen');
        $seen['transform'] = true;
    };
    $draw->DrawPointFcn = function (b2Vec2 $p, float $size, int $color, mixed $context) use (&$seen): void {
        expect($p)->toBeInstanceOf(b2Vec2::class)->and($context)->toBe('pen');
        $seen['point'] = true;
    };
    $draw->DrawStringFcn = function (b2Vec2 $p, string $s, int $color, mixed $context) use (&$seen): void {
        expect($p)->toBeInstanceOf(b2Vec2::class)
            ->and($s)->not->toBe('')
            ->and($context)->toBe('pen');
        $seen['string'] = true;
    };

    b2World_Draw($world, $draw);

    expect($seen)->toHaveKeys([
        'polygon',
        'solidPolygon',
        'circle',
        'solidCircle',
        'capsule',
        'segment',
        'transform',
        'point',
        'string',
    ]);

    b2DestroyWorld($world);
});

it('does not call a null debug draw closure', function (): void {
    $world = b2CreateWorld(b2DefaultWorldDef());
    $body = b2CreateBody($world, b2DefaultBodyDef());
    b2CreatePolygonShape($body, b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));
    $calls = 0;
    $draw = b2DefaultDebugDraw();
    $draw->drawShapes = true;
    $draw->DrawSolidPolygonFcn = null;
    $draw->DrawPolygonFcn = function () use (&$calls): void {
        $calls++;
    };

    b2World_Draw($world, $draw);
    expect($calls)->toBe(0);

    b2DestroyWorld($world);
});
