/*
 * box2d: 1:1 bindings of Box2D 3.1.1. The library is compiled into this
 * extension. Function, struct, and constant names stay the C names.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_box2d.h"

#include "ext/standard/info.h"

#include "runtime.h"
#include "classes.h"
#include "convert.h"

#include "zend_exceptions.h"

#include "../stubs/base_arginfo.h"

#include <stdio.h>

zend_class_entry *box2d_ce_b2Version;
zend_class_entry *box2d_ce_b2AssertionError;

_Thread_local box2d_assert_slot box2d_assert_tls;

ZEND_DECLARE_MODULE_GLOBALS(box2d)

static PHP_GINIT_FUNCTION(box2d)
{
	box2d_globals->worlds = NULL;
}

/* Returns 0 so Box2D does not trap. A later call reads the slot and throws. */
static int box2d_on_assert(const char *condition, const char *file_name, int line_number)
{
	if (!box2d_assert_tls.pending) {
		box2d_assert_tls.condition = condition;
		box2d_assert_tls.file = file_name;
		box2d_assert_tls.line = line_number;
		box2d_assert_tls.pending = true;
	}

	return 0;
}

ZEND_METHOD(b2Version, __construct)
{
	zend_long major = 0, minor = 0, revision = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(major)
		Z_PARAM_LONG(minor)
		Z_PARAM_LONG(revision)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2Version, Z_OBJ_P(ZEND_THIS), ZEND_STRL("major"), major);
	zend_update_property_long(box2d_ce_b2Version, Z_OBJ_P(ZEND_THIS), ZEND_STRL("minor"), minor);
	zend_update_property_long(box2d_ce_b2Version, Z_OBJ_P(ZEND_THIS), ZEND_STRL("revision"), revision);

	b2Version native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Version_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_FUNCTION(b2GetVersion)
{
	b2Version version;

	ZEND_PARSE_PARAMETERS_NONE();

	version = b2GetVersion();
	if (box2d_b2Version_to_zval(&version, return_value) == FAILURE) {
		RETURN_THROWS();
	}
	box2d_assert_check();
}

PHP_MINIT_FUNCTION(box2d)
{
#if defined(COMPILE_DL_BOX2D) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	box2d_register_structs(module_number);
	box2d_register_api(module_number);
	box2d_ce_b2Version = register_class_b2Version();
	box2d_class_is_value(box2d_ce_b2Version);
	box2d_ce_b2AssertionError = register_class_b2AssertionError(zend_ce_error);
	box2d_register_ids();
	register_base_symbols(module_number);
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	b2SetAssertFcn(box2d_on_assert);
	box2d_atfork_install();

	return SUCCESS;
}

PHP_RINIT_FUNCTION(box2d)
{
#if defined(COMPILE_DL_BOX2D) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	box2d_assert_tls.pending = false;
	box2d_assert_tls.condition = NULL;
	box2d_assert_tls.file = NULL;
	box2d_assert_tls.line = 0;

	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(box2d)
{
	box2d_worlds_shutdown();
	return SUCCESS;
}

PHP_MINFO_FUNCTION(box2d)
{
	b2Version version = b2GetVersion();
	char decoded[32];

	snprintf(decoded, sizeof(decoded), "%d.%d.%d", version.major, version.minor, version.revision);

	php_info_print_table_start();
	php_info_print_table_row(2, "box2d support", "enabled");
	php_info_print_table_row(2, "Version", PHP_BOX2D_VERSION);
	php_info_print_table_row(2, "Box2D version", decoded);
	php_info_print_table_row(2, "Box2D commit", PHP_BOX2D_UPSTREAM_COMMIT);
	php_info_print_table_end();
}

zend_module_entry box2d_module_entry = {
	STANDARD_MODULE_HEADER,
	"box2d",
	NULL,
	PHP_MINIT(box2d),
	NULL,
	PHP_RINIT(box2d),
	PHP_RSHUTDOWN(box2d),
	PHP_MINFO(box2d),
	PHP_BOX2D_VERSION,
	PHP_MODULE_GLOBALS(box2d),
	PHP_GINIT(box2d),
	NULL,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BOX2D
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(box2d)
#endif
