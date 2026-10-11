<?php

declare(strict_types=1);

/** Runs $code in a fresh PHP process with this process's ini scan dir; returns [exit code, stdout, stderr]. */
function box2d_subprocess(string $code): array
{
    $process = proc_open([PHP_BINARY, '-d', 'memory_limit=128M', '-r', $code], [1 => ['pipe', 'w'], 2 => ['pipe', 'w']], $pipes);
    $stdout = stream_get_contents($pipes[1]);
    $stderr = stream_get_contents($pipes[2]);
    fclose($pipes[1]);
    fclose($pipes[2]);

    return [proc_close($process), $stdout, $stderr];
}

const BOX2D_POOLED_WORLDS = <<<'PHP'
for ($w = 0; $w < 8; $w++) {
    $definition = b2DefaultWorldDef();
    $definition->workerCount = 4;
    $world = b2CreateWorld($definition);
    for ($i = 0; $i < 50; $i++) {
        $body = b2DefaultBodyDef();
        $body->type = b2_dynamicBody;
        $body->position = new b2Vec2($i * 1.1, 2.0 + $w);
        b2CreatePolygonShape(b2CreateBody($world, $body), b2DefaultShapeDef(), b2MakeBox(0.5, 0.5));
    }
    for ($s = 0; $s < 10; $s++) {
        b2World_Step($world, 1.0 / 60.0, 4);
    }
}
PHP;

it('ends a request that left pooled worlds running without crashing or reporting', function (): void {
    [$status, $stdout, $stderr] = box2d_subprocess(BOX2D_POOLED_WORLDS.' echo "stepped";');

    expect($status)->toBe(0)
        ->and($stdout)->toBe('stepped')
        ->and($stderr)->toBe('');
});

it('lets a forked child exit cleanly with the pools it inherited dead', function (): void {
    [$status, $stdout, $stderr] = box2d_subprocess(BOX2D_POOLED_WORLDS.<<<'PHP'
        $pid = pcntl_fork();
        if ($pid === 0) {
            exit(0);
        }
        pcntl_waitpid($pid, $child);
        echo pcntl_wexitstatus($child);
        PHP);

    expect($status)->toBe(0)
        ->and($stdout)->toBe('0')
        ->and($stderr)->toBe('');
});

/** Native threads in process $pid. */
function box2d_thread_count(int $pid): int
{
    if (is_dir("/proc/{$pid}/task")) {
        return count(scandir("/proc/{$pid}/task")) - 2;
    }

    return count(array_filter(explode("\n", (string) shell_exec("ps -M -p {$pid}")))) - 1;
}

it('frees every pooled world and joins its threads at the end of each request in a long-lived process', function (): void {
    $dir = sys_get_temp_dir().'/box2d-lifecycle-'.bin2hex(random_bytes(4));
    mkdir($dir);
    file_put_contents("{$dir}/index.php", '<?php '.BOX2D_POOLED_WORLDS.' echo "ok";');
    $port = 20000 + random_int(0, 20000);
    $server = proc_open([PHP_BINARY, '-d', 'memory_limit=128M', '-S', "127.0.0.1:{$port}", '-t', $dir], [1 => ['file', '/dev/null', 'w'], 2 => ['file', "{$dir}/server.log", 'w']], $pipes);
    $pid = proc_get_status($server)['pid'];
    $get = function () use ($port): string|false {
        set_error_handler(fn (): bool => true);      // the server refuses connections until it is listening
        try {
            return file_get_contents("http://127.0.0.1:{$port}/index.php");
        } finally {
            restore_error_handler();
        }
    };

    try {
        for ($wait = 0; $wait < 50 && $get() === false; $wait++) {
            usleep(100_000);
        }
        $baseline = box2d_thread_count($pid);
        $bodies = [];
        for ($request = 0; $request < 20; $request++) {      // 160 worlds against Box2D's 128-slot table
            $bodies[] = $get();
        }

        expect($bodies)->toBe(array_fill(0, 20, 'ok'))
            ->and(box2d_thread_count($pid))->toBe($baseline);
    } finally {
        proc_terminate($server);
        proc_close($server);
        array_map('unlink', glob("{$dir}/*"));
        rmdir($dir);
    }
});

