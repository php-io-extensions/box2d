#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

ZEND_FUNCTION(b2Body_SetName)
{
	zval *body_id;
	zval *name_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(body_id, box2d_ce_b2BodyId)
		Z_PARAM_ZVAL(name_zv)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(body_id, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2BodyId id;
	if (box2d_bind_read(body_id, &id, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId scope = box2d_tracked_world(box2d_world_index_from_world0(id.world0));
	box2d_guard_step(scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	const char *name = box2d_body_name(name_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	box2d_world_ctx *previous = box2d_world_push(scope);
	b2Body_SetName(id, name);
	box2d_world_pop(previous);
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(b2Body_GetName)
{
	zval *body_id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(body_id, box2d_ce_b2BodyId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(body_id, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	b2BodyId id;
	if (box2d_bind_read(body_id, &id, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId scope = box2d_tracked_world(box2d_world_index_from_world0(id.world0));
	box2d_guard_step(scope, BOX2D_OP_BODY_GET_NAME);
	if (EG(exception)) {
		RETURN_THROWS();
	}

	box2d_world_ctx *previous = box2d_world_push(scope);
	const char *name = b2Body_GetName(id);
	box2d_world_pop(previous);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (name == NULL) {
		RETURN_NULL();
	}
	RETURN_STRING(name);
}
