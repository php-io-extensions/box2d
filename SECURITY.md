# Security Policy

## Supported versions

ext-box2d is pre-1.0. No 0.x release receives security fixes or advisories; fixes land in the
next release line. Security support starts with 1.0.

| Version | Security fixes |
|---------|----------------|
| < 1.0   | No             |

## Reporting a vulnerability

Please don't open a public issue for a security problem.

Report it privately through GitHub: the **Report a vulnerability** button on the
[php-io-extensions/box2d](https://github.com/php-io-extensions/box2d) repository's **Security** tab.
If that isn't available, email **info@projectsaturnstudios.com**.

Include what you found, the affected version, your platform, PHP build (NTS or ZTS), the
`workerCount` of the world involved, and steps to reproduce (`php --ri box2d` shows the extension
version and the Box2D tag and commit it carries). Reports are read and weighed for the release
line in development; before 1.0 there is no response-time commitment.

A defect in Box2D itself belongs with that project. Report it here as well when ext-box2d should
guard against it.

## Security model

ext-box2d runs a physics simulation in the PHP process. It reads no files, opens no sockets and
links no system library: Box2D 3.1.1 is compiled into the module.

- **Ids.** Every world, body, shape, chain and joint id is checked live (generation and index)
  before Box2D sees it; a dead id is a `ValueError`. A world id from another PHP thread is an
  `Error` on ZTS.
- **Inputs.** Narrow C integers are range-checked; counts must sit inside their lists; a def must
  carry Box2D's cookie, so a hand-built def is refused before Box2D reads it.
- **Assertions.** Box2D's assertions stay on in every build. The handler records the first failure
  and returns, so Box2D never traps; the binding throws `b2AssertionError` after the call.
- **Stepping.** While a world steps, a callback may only read what Box2D does not write during a
  step; anything else on that world is an `Error`.
- **Workers.** Pool threads never enter PHP. A callback a pool thread needs is queued to the
  stepping thread, which runs the PHP callable. A pool does not survive `fork()`; stepping it in
  the child is an `Error`. Request end stops every pool and destroys every world the request left.

A report is in scope when ext-box2d itself reads or writes memory it should not, leaks, races,
deadlocks or crashes: a list copied past its count, an id reaching Box2D dead, a callable reached
after it was released, a pool thread touching PHP, a world or thread left after request end.
