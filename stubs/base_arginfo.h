/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: deccf5853a0cf8b71189933b60e2fb63deffab1a */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2GetVersion, 0, 0, b2Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2GetByteCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2GetTicks arginfo_b2GetByteCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2GetMilliseconds, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ticks, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2GetMillisecondsAndReset, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, ticks, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Yield, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2Hash, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Version___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, major, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, minor, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, revision, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_FUNCTION(b2GetVersion);
ZEND_FUNCTION(b2GetByteCount);
ZEND_FUNCTION(b2GetTicks);
ZEND_FUNCTION(b2GetMilliseconds);
ZEND_FUNCTION(b2GetMillisecondsAndReset);
ZEND_FUNCTION(b2Yield);
ZEND_FUNCTION(b2Hash);
ZEND_METHOD(b2Version, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(b2GetVersion, arginfo_b2GetVersion)
	ZEND_FE(b2GetByteCount, arginfo_b2GetByteCount)
	ZEND_FE(b2GetTicks, arginfo_b2GetTicks)
	ZEND_FE(b2GetMilliseconds, arginfo_b2GetMilliseconds)
	ZEND_FE(b2GetMillisecondsAndReset, arginfo_b2GetMillisecondsAndReset)
	ZEND_FE(b2Yield, arginfo_b2Yield)
	ZEND_FE(b2Hash, arginfo_b2Hash)
	ZEND_FE_END
};

static const zend_function_entry class_b2Version_methods[] = {
	ZEND_ME(b2Version, __construct, arginfo_class_b2Version___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_base_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("B2_HASH_INIT", B2_HASH_INIT, CONST_PERSISTENT);
}

static zend_class_entry *register_class_b2Version(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Version", class_b2Version_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_major_default_value;
	ZVAL_LONG(&property_major_default_value, 0);
	zend_string *property_major_name = zend_string_init("major", sizeof("major") - 1, 1);
	zend_declare_typed_property(class_entry, property_major_name, &property_major_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_major_name);

	zval property_minor_default_value;
	ZVAL_LONG(&property_minor_default_value, 0);
	zend_string *property_minor_name = zend_string_init("minor", sizeof("minor") - 1, 1);
	zend_declare_typed_property(class_entry, property_minor_name, &property_minor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minor_name);

	zval property_revision_default_value;
	ZVAL_LONG(&property_revision_default_value, 0);
	zend_string *property_revision_name = zend_string_init("revision", sizeof("revision") - 1, 1);
	zend_declare_typed_property(class_entry, property_revision_name, &property_revision_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_revision_name);

	return class_entry;
}

static zend_class_entry *register_class_b2AssertionError(zend_class_entry *class_entry_Error)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2AssertionError", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Error, 0);

	return class_entry;
}
