PHP_ARG_ENABLE([box2d],
  [whether to enable box2d support],
  [AS_HELP_STRING([--enable-box2d], [Enable the Box2D 3.1.1 bindings])],
  [no])

if test "$PHP_BOX2D" != "no"; then
  dnl Upstream .c files only. Headers, src/CMakeLists.txt, and src/box2d.natvis stay uncompiled.
  box2d_sources=" \
    src/box2d.c \
    src/base.c \
    src/classes.c \
    src/convert_props.c \
    src/convert_math.c \
    src/convert_collision.c \
    src/convert_types.c \
    src/guards.c \
    src/id.c \
    src/math_functions.c \
    src/collision.c \
    src/bind.c \
    src/world.c \
    src/events.c \
    src/tasks.c \
    src/world_funcs.c \
    src/body.c \
    src/body_name.c \
    src/shape.c \
    src/chain.c \
    src/joints.c \
    src/types_api.c \
    src/register_math.c \
    src/register_id.c \
    src/register_collision.c \
    src/register_types.c \
    lib/box2d/src/aabb.c \
    lib/box2d/src/arena_allocator.c \
    lib/box2d/src/array.c \
    lib/box2d/src/bitset.c \
    lib/box2d/src/body.c \
    lib/box2d/src/broad_phase.c \
    lib/box2d/src/constraint_graph.c \
    lib/box2d/src/contact.c \
    lib/box2d/src/contact_solver.c \
    lib/box2d/src/core.c \
    lib/box2d/src/distance.c \
    lib/box2d/src/distance_joint.c \
    lib/box2d/src/dynamic_tree.c \
    lib/box2d/src/geometry.c \
    lib/box2d/src/hull.c \
    lib/box2d/src/id_pool.c \
    lib/box2d/src/island.c \
    lib/box2d/src/joint.c \
    lib/box2d/src/manifold.c \
    lib/box2d/src/math_functions.c \
    lib/box2d/src/motor_joint.c \
    lib/box2d/src/mouse_joint.c \
    lib/box2d/src/mover.c \
    lib/box2d/src/prismatic_joint.c \
    lib/box2d/src/revolute_joint.c \
    lib/box2d/src/sensor.c \
    lib/box2d/src/shape.c \
    lib/box2d/src/solver.c \
    lib/box2d/src/solver_set.c \
    lib/box2d/src/table.c \
    lib/box2d/src/timer.c \
    lib/box2d/src/types.c \
    lib/box2d/src/weld_joint.c \
    lib/box2d/src/wheel_joint.c \
    lib/box2d/src/world.c"

  PHP_NEW_EXTENSION([box2d],
    [$box2d_sources],
    [$ext_shared],,
    [-std=gnu17 -ffp-contract=off -fvisibility=hidden -DB2_ENABLE_ASSERT -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -I$ext_srcdir/lib/box2d/include -I$ext_srcdir/lib/box2d/src])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])
  PHP_ADD_BUILD_DIR([$ext_builddir/lib/box2d/src])

  dnl Darwin's libSystem provides pthread. Linux needs -lpthread on the link line.
  case $host_os in
    darwin*) ;;
    *)
      PHP_ADD_LIBRARY([pthread],, [BOX2D_SHARED_LIBADD])
      PHP_SUBST([BOX2D_SHARED_LIBADD])
      ;;
  esac
fi
