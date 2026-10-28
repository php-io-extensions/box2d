<?php

declare(strict_types=1);

it('reports Box2D 3.1.1', function (): void {
    $version = b2GetVersion();

    expect($version)->toBeInstanceOf(b2Version::class)
        ->and($version->major)->toBe(3)
        ->and($version->minor)->toBe(1)
        ->and($version->revision)->toBe(1);
});

it('prints the extension version, the Box2D version, and the upstream commit', function (): void {
    ob_start();
    phpinfo(INFO_MODULES);
    $info = ob_get_clean();

    expect($info)->toContain('0.11.0')
        ->and($info)->toContain('3.1.1')
        ->and($info)->toContain('8c661469c9507d3ad6fbd2fea3f1aa71669c2fe3');
});
