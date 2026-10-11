#ifndef PHP_BOX2D_H
#define PHP_BOX2D_H

extern zend_module_entry box2d_module_entry;
#define phpext_box2d_ptr &box2d_module_entry

#define PHP_BOX2D_VERSION "0.10.0"

/* Box2D tag v3.1.1. A newer library lands only by replacing lib/box2d/ from a published tag. */
#define PHP_BOX2D_UPSTREAM_COMMIT "8c661469c9507d3ad6fbd2fea3f1aa71669c2fe3"

extern zend_class_entry *box2d_ce_b2Version;

#if defined(ZTS) && defined(COMPILE_DL_BOX2D)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
