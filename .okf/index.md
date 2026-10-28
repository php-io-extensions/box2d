---
okf_version: "0.2"
---

# ext-box2d

1:1 PHP bindings of Box2D v3.1.1 (vendored, unchanged). Version 0.11.0. Linux, macOS. PHP 8.4 NTS + ZTS.

# API

* [Bindings](api/bindings.md) — 505 functions, 72 classes, 27 constants by header; translations.

# Architecture

* [Guards and errors](architecture/guards.md) — Live ids, def cookie, narrow ints, owner thread, stepping world, assertions.
* [Workers and callbacks](architecture/workers.md) — Per-world pthread pool, FIFO ranges, callback queue to stepping thread, fork, request end.

# Runbooks

* [Build, install, test](runbooks/build.md) — Mac NTS/ZTS, scratch builds, the Pi.
