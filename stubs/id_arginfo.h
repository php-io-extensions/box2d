/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 99e91b72f8460a2c52c8bcbc299781448d629b3c */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_B2_IS_NULL, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, id, b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId, 0, NULL)
ZEND_END_ARG_INFO()

#define arginfo_B2_IS_NON_NULL arginfo_B2_IS_NULL

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_B2_ID_EQUALS, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, id1, b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId, 0, NULL)
	ZEND_ARG_OBJ_TYPE_MASK(0, id2, b2WorldId|b2BodyId|b2ShapeId|b2ChainId|b2JointId, 0, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2StoreWorldId, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2LoadWorldId, 0, 1, b2WorldId, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2StoreBodyId, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2LoadBodyId, 0, 1, b2BodyId, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2StoreShapeId, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2LoadShapeId, 0, 1, b2ShapeId, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2StoreChainId, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2LoadChainId, 0, 1, b2ChainId, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2StoreJointId, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, id, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2LoadJointId, 0, 1, b2JointId, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2_nullWorldId, 0, 0, b2WorldId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2_nullBodyId, 0, 0, b2BodyId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2_nullShapeId, 0, 0, b2ShapeId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2_nullChainId, 0, 0, b2ChainId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2_nullJointId, 0, 0, b2JointId, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2WorldId___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, index1, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, generation, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2BodyId___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, index1, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, world0, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, generation, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_b2ShapeId___construct arginfo_class_b2BodyId___construct

#define arginfo_class_b2ChainId___construct arginfo_class_b2BodyId___construct

#define arginfo_class_b2JointId___construct arginfo_class_b2BodyId___construct

ZEND_FUNCTION(B2_IS_NULL);
ZEND_FUNCTION(B2_IS_NON_NULL);
ZEND_FUNCTION(B2_ID_EQUALS);
ZEND_FUNCTION(b2StoreWorldId);
ZEND_FUNCTION(b2LoadWorldId);
ZEND_FUNCTION(b2StoreBodyId);
ZEND_FUNCTION(b2LoadBodyId);
ZEND_FUNCTION(b2StoreShapeId);
ZEND_FUNCTION(b2LoadShapeId);
ZEND_FUNCTION(b2StoreChainId);
ZEND_FUNCTION(b2LoadChainId);
ZEND_FUNCTION(b2StoreJointId);
ZEND_FUNCTION(b2LoadJointId);
ZEND_FUNCTION(b2_nullWorldId);
ZEND_FUNCTION(b2_nullBodyId);
ZEND_FUNCTION(b2_nullShapeId);
ZEND_FUNCTION(b2_nullChainId);
ZEND_FUNCTION(b2_nullJointId);
ZEND_METHOD(b2WorldId, __construct);
ZEND_METHOD(b2BodyId, __construct);
ZEND_METHOD(b2ShapeId, __construct);
ZEND_METHOD(b2ChainId, __construct);
ZEND_METHOD(b2JointId, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(B2_IS_NULL, arginfo_B2_IS_NULL)
	ZEND_FE(B2_IS_NON_NULL, arginfo_B2_IS_NON_NULL)
	ZEND_FE(B2_ID_EQUALS, arginfo_B2_ID_EQUALS)
	ZEND_FE(b2StoreWorldId, arginfo_b2StoreWorldId)
	ZEND_FE(b2LoadWorldId, arginfo_b2LoadWorldId)
	ZEND_FE(b2StoreBodyId, arginfo_b2StoreBodyId)
	ZEND_FE(b2LoadBodyId, arginfo_b2LoadBodyId)
	ZEND_FE(b2StoreShapeId, arginfo_b2StoreShapeId)
	ZEND_FE(b2LoadShapeId, arginfo_b2LoadShapeId)
	ZEND_FE(b2StoreChainId, arginfo_b2StoreChainId)
	ZEND_FE(b2LoadChainId, arginfo_b2LoadChainId)
	ZEND_FE(b2StoreJointId, arginfo_b2StoreJointId)
	ZEND_FE(b2LoadJointId, arginfo_b2LoadJointId)
	ZEND_FE(b2_nullWorldId, arginfo_b2_nullWorldId)
	ZEND_FE(b2_nullBodyId, arginfo_b2_nullBodyId)
	ZEND_FE(b2_nullShapeId, arginfo_b2_nullShapeId)
	ZEND_FE(b2_nullChainId, arginfo_b2_nullChainId)
	ZEND_FE(b2_nullJointId, arginfo_b2_nullJointId)
	ZEND_FE_END
};

static const zend_function_entry class_b2WorldId_methods[] = {
	ZEND_ME(b2WorldId, __construct, arginfo_class_b2WorldId___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2BodyId_methods[] = {
	ZEND_ME(b2BodyId, __construct, arginfo_class_b2BodyId___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ShapeId_methods[] = {
	ZEND_ME(b2ShapeId, __construct, arginfo_class_b2ShapeId___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ChainId_methods[] = {
	ZEND_ME(b2ChainId, __construct, arginfo_class_b2ChainId___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2JointId_methods[] = {
	ZEND_ME(b2JointId, __construct, arginfo_class_b2JointId___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_b2WorldId(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2WorldId", class_b2WorldId_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_index1_default_value;
	ZVAL_LONG(&property_index1_default_value, 0);
	zend_string *property_index1_name = zend_string_init("index1", sizeof("index1") - 1, 1);
	zend_declare_typed_property(class_entry, property_index1_name, &property_index1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index1_name);

	zval property_generation_default_value;
	ZVAL_LONG(&property_generation_default_value, 0);
	zend_string *property_generation_name = zend_string_init("generation", sizeof("generation") - 1, 1);
	zend_declare_typed_property(class_entry, property_generation_name, &property_generation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_generation_name);

	return class_entry;
}

static zend_class_entry *register_class_b2BodyId(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2BodyId", class_b2BodyId_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_index1_default_value;
	ZVAL_LONG(&property_index1_default_value, 0);
	zend_string *property_index1_name = zend_string_init("index1", sizeof("index1") - 1, 1);
	zend_declare_typed_property(class_entry, property_index1_name, &property_index1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index1_name);

	zval property_world0_default_value;
	ZVAL_LONG(&property_world0_default_value, 0);
	zend_string *property_world0_name = zend_string_init("world0", sizeof("world0") - 1, 1);
	zend_declare_typed_property(class_entry, property_world0_name, &property_world0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_world0_name);

	zval property_generation_default_value;
	ZVAL_LONG(&property_generation_default_value, 0);
	zend_string *property_generation_name = zend_string_init("generation", sizeof("generation") - 1, 1);
	zend_declare_typed_property(class_entry, property_generation_name, &property_generation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_generation_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ShapeId(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ShapeId", class_b2ShapeId_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_index1_default_value;
	ZVAL_LONG(&property_index1_default_value, 0);
	zend_string *property_index1_name = zend_string_init("index1", sizeof("index1") - 1, 1);
	zend_declare_typed_property(class_entry, property_index1_name, &property_index1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index1_name);

	zval property_world0_default_value;
	ZVAL_LONG(&property_world0_default_value, 0);
	zend_string *property_world0_name = zend_string_init("world0", sizeof("world0") - 1, 1);
	zend_declare_typed_property(class_entry, property_world0_name, &property_world0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_world0_name);

	zval property_generation_default_value;
	ZVAL_LONG(&property_generation_default_value, 0);
	zend_string *property_generation_name = zend_string_init("generation", sizeof("generation") - 1, 1);
	zend_declare_typed_property(class_entry, property_generation_name, &property_generation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_generation_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ChainId(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ChainId", class_b2ChainId_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_index1_default_value;
	ZVAL_LONG(&property_index1_default_value, 0);
	zend_string *property_index1_name = zend_string_init("index1", sizeof("index1") - 1, 1);
	zend_declare_typed_property(class_entry, property_index1_name, &property_index1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index1_name);

	zval property_world0_default_value;
	ZVAL_LONG(&property_world0_default_value, 0);
	zend_string *property_world0_name = zend_string_init("world0", sizeof("world0") - 1, 1);
	zend_declare_typed_property(class_entry, property_world0_name, &property_world0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_world0_name);

	zval property_generation_default_value;
	ZVAL_LONG(&property_generation_default_value, 0);
	zend_string *property_generation_name = zend_string_init("generation", sizeof("generation") - 1, 1);
	zend_declare_typed_property(class_entry, property_generation_name, &property_generation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_generation_name);

	return class_entry;
}

static zend_class_entry *register_class_b2JointId(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2JointId", class_b2JointId_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_index1_default_value;
	ZVAL_LONG(&property_index1_default_value, 0);
	zend_string *property_index1_name = zend_string_init("index1", sizeof("index1") - 1, 1);
	zend_declare_typed_property(class_entry, property_index1_name, &property_index1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index1_name);

	zval property_world0_default_value;
	ZVAL_LONG(&property_world0_default_value, 0);
	zend_string *property_world0_name = zend_string_init("world0", sizeof("world0") - 1, 1);
	zend_declare_typed_property(class_entry, property_world0_name, &property_world0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_world0_name);

	zval property_generation_default_value;
	ZVAL_LONG(&property_generation_default_value, 0);
	zend_string *property_generation_name = zend_string_init("generation", sizeof("generation") - 1, 1);
	zend_declare_typed_property(class_entry, property_generation_name, &property_generation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_generation_name);

	return class_entry;
}
