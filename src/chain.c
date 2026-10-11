#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "bind.h"
#include "classes.h"

ZEND_FUNCTION(b2CreateChain)
{
	zval *bodyId_zv;
	zval *def_zv;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(bodyId_zv, box2d_ce_b2BodyId)
		Z_PARAM_OBJECT_OF_CLASS(def_zv, box2d_ce_b2ChainDef)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(bodyId_zv, BOX2D_ID_BODY, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2BodyId bodyId_c;
	if (box2d_bind_read(bodyId_zv, &bodyId_c, box2d_from_slot_b2BodyId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(bodyId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_guard_cookie(def_zv);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_frame box2d_keep;
	box2d_frame_init(&box2d_keep);
	b2ChainDef def_c;
	if (box2d_b2ChainDef_from_zval(def_zv, &def_c, &box2d_keep) == FAILURE) {
		box2d_frame_free(&box2d_keep);
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2ChainId box2d_result = b2CreateChain(bodyId_c, &def_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		box2d_frame_free(&box2d_keep);
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		box2d_frame_free(&box2d_keep);
		RETURN_THROWS();
	}
	box2d_frame_free(&box2d_keep);
	if (box2d_b2ChainId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2DestroyChain)
{
	zval *chainId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2DestroyChain(chainId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Chain_GetWorld)
{
	zval *chainId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2WorldId box2d_result = b2Chain_GetWorld(chainId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (box2d_b2WorldId_to_zval(&box2d_result, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Chain_GetSegmentCount)
{
	zval *chainId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Chain_GetSegmentCount(chainId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Chain_GetSegments)
{
	zval *chainId_zv;
	zval *segmentArray_zv;
	zend_long capacity_l;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
		Z_PARAM_ZVAL(segmentArray_zv)
		Z_PARAM_LONG(capacity_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	if (capacity_l < 0) {
		zend_value_error("capacity %lld is negative", (long long) capacity_l);
		RETURN_THROWS();
	}
	int capacity_i;
	if (box2d_bind_i32(capacity_l, &capacity_i, "capacity") == FAILURE) {
		RETURN_THROWS();
	}
	b2ShapeId *segmentArray_buf = NULL;
	if (capacity_i > 0) {
		segmentArray_buf = safe_emalloc((size_t) capacity_i, sizeof(b2ShapeId), 0);
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Chain_GetSegments(chainId_c, segmentArray_buf, capacity_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		if (segmentArray_buf != NULL) {
			efree(segmentArray_buf);
		}
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		if (segmentArray_buf != NULL) {
			efree(segmentArray_buf);
		}
		RETURN_THROWS();
	}
	if (box2d_result < 0 || box2d_result > capacity_i) {
		if (segmentArray_buf != NULL) {
			efree(segmentArray_buf);
		}
		zend_value_error("capacity %d cannot hold %d results", capacity_i, box2d_result);
		RETURN_THROWS();
	}
	if (box2d_store_list(segmentArray_zv, box2d_result, segmentArray_buf, sizeof(b2ShapeId), box2d_to_slot_b2ShapeId) == FAILURE) {
		if (segmentArray_buf != NULL) {
			efree(segmentArray_buf);
		}
		RETURN_THROWS();
	}
	if (segmentArray_buf != NULL) {
		efree(segmentArray_buf);
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Chain_SetFriction)
{
	zval *chainId_zv;
	double friction_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
		Z_PARAM_DOUBLE(friction_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Chain_SetFriction(chainId_c, (float) friction_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Chain_GetFriction)
{
	zval *chainId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Chain_GetFriction(chainId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(box2d_result);
}


ZEND_FUNCTION(b2Chain_SetRestitution)
{
	zval *chainId_zv;
	double restitution_d;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
		Z_PARAM_DOUBLE(restitution_d)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Chain_SetRestitution(chainId_c, (float) restitution_d);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Chain_GetRestitution)
{
	zval *chainId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	float box2d_result = b2Chain_GetRestitution(chainId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(box2d_result);
}


ZEND_FUNCTION(b2Chain_SetMaterial)
{
	zval *chainId_zv;
	zend_long material_l;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
		Z_PARAM_LONG(material_l)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	int material_i;
	if (box2d_bind_i32(material_l, &material_i, "material") == FAILURE) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	b2Chain_SetMaterial(chainId_c, material_i);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
}


ZEND_FUNCTION(b2Chain_GetMaterial)
{
	zval *chainId_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(chainId_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(chainId_zv, BOX2D_ID_CHAIN, 0);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId chainId_c;
	if (box2d_bind_read(chainId_zv, &chainId_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(chainId_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_NONE);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	int box2d_result = b2Chain_GetMaterial(chainId_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_LONG(box2d_result);
}


ZEND_FUNCTION(b2Chain_IsValid)
{
	zval *id_zv;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(id_zv, box2d_ce_b2ChainId)
	ZEND_PARSE_PARAMETERS_END();

	box2d_guard_id(id_zv, BOX2D_ID_CHAIN, 1);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	b2ChainId id_c;
	if (box2d_bind_read(id_zv, &id_c, box2d_from_slot_b2ChainId) == FAILURE) {
		RETURN_THROWS();
	}
	b2WorldId box2d_scope = box2d_tracked_world(box2d_world_index_from_world0(id_c.world0));
	box2d_guard_step(box2d_scope, BOX2D_OP_CHAIN_IS_VALID);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_world_ctx *box2d_prev = box2d_world_push(box2d_scope);
	bool box2d_result = b2Chain_IsValid(id_c);
	box2d_world_pop(box2d_prev);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	box2d_assert_check();
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(box2d_result);
}

