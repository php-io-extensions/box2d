# Agent guidance — php-io-extensions/box2d

1. **Read [`.okf/index.md`](.okf/index.md) first** before changing the API, the C, or packaging. Open only the concepts the change touches.
2. **Bindings are 1:1 at Box2D v3.1.1** (tag `v3.1.1`, commit `8c661469c9507d3ad6fbd2fea3f1aa71669c2fe3`). Function, struct, enum and constant names are the C names. No defaults, no composites. The design spec (`docs/superpowers/specs/2026-10-10-box2d-design.md`) lists every translation; there are no others.
3. **Upstream is copied unchanged** into `lib/box2d/`. Never edit it. A new Box2D only from a new upstream tag: replace `lib/box2d/`, diff `include/`, update stubs, binding C and tests, bump the version.
4. **Structs** are `final` classes with one typed property per C field in field order; ids are struct classes too. Static const values (`b2_nullBodyId`, `b2Vec2_zero` …) are functions returning fresh instances.
5. **Guards run before Box2D**: live ids, def cookie, narrow ints, counts, owner thread (ZTS), stepping world. Box2D assertions become `b2AssertionError` after the call.
6. **Workers** (`src/tasks.c`): `workerCount <= 1` steps serially with no task callbacks. Above 1, one pool of `min(workerCount, 64)` pthreads per world, worker index fixed per thread, FIFO ranges. Pool threads never enter PHP: callbacks are queued to the stepping thread, which serves them inside `finishTask`. Results are bit-identical across worker counts.
7. **Request end** stops every pool and destroys every world and dynamic tree the request left. `pthread_atfork` marks pools dead in a child.
8. **The stub is the declaration.** Edit `stubs/*.stub.php`, regenerate with `php84 /opt/homebrew/opt/php@8.4/lib/php/build/gen_stub.php stubs`, commit both. Never hand-edit `*_arginfo.h`.
9. **Build.** `./install-macos.sh` into Homebrew `php@8.4` and `php@8.4-zts`. On the Pi, copy the tree with `fnk` (set `COPYFILE_DISABLE=1` on the Mac `tar` so no `._*` files reach gen_stub) and `./install-debian-trixie.sh`. Pest at `-d memory_limit=128M`, with `XDEBUG_MODE=off` for any timing. Gate a commit on the suite's exit code.
10. **Durable facts go in `.okf`.** Update the matching concept and append `.okf/log.md`.
11. **Version** is `PHP_BOX2D_VERSION` in `php_box2d.h`: 0.10.5. `os-families`: linux, darwin.
