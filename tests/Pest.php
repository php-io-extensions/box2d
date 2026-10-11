<?php

declare(strict_types=1);

if (! extension_loaded('box2d')) {
    throw new RuntimeException('The box2d extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

function box2d_expect_near(float $actual, float $expected, float $delta = 1.0e-4): void
{
    expect(abs($actual - $expected))->toBeLessThan($delta);
}
