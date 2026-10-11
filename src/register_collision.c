#include "convert.h"
#include "classes.h"

#include "../stubs/collision_arginfo.h"

zend_class_entry *box2d_ce_b2RayCastInput;
zend_class_entry *box2d_ce_b2ShapeProxy;
zend_class_entry *box2d_ce_b2ShapeCastInput;
zend_class_entry *box2d_ce_b2CastOutput;
zend_class_entry *box2d_ce_b2MassData;
zend_class_entry *box2d_ce_b2Circle;
zend_class_entry *box2d_ce_b2Capsule;
zend_class_entry *box2d_ce_b2Polygon;
zend_class_entry *box2d_ce_b2Segment;
zend_class_entry *box2d_ce_b2ChainSegment;
zend_class_entry *box2d_ce_b2Hull;
zend_class_entry *box2d_ce_b2SegmentDistanceResult;
zend_class_entry *box2d_ce_b2SimplexCache;
zend_class_entry *box2d_ce_b2DistanceInput;
zend_class_entry *box2d_ce_b2DistanceOutput;
zend_class_entry *box2d_ce_b2SimplexVertex;
zend_class_entry *box2d_ce_b2Simplex;
zend_class_entry *box2d_ce_b2ShapeCastPairInput;
zend_class_entry *box2d_ce_b2Sweep;
zend_class_entry *box2d_ce_b2TOIInput;
zend_class_entry *box2d_ce_b2TOIOutput;
zend_class_entry *box2d_ce_b2ManifoldPoint;
zend_class_entry *box2d_ce_b2Manifold;
zend_class_entry *box2d_ce_b2DynamicTree;
zend_class_entry *box2d_ce_b2TreeStats;
zend_class_entry *box2d_ce_b2PlaneResult;
zend_class_entry *box2d_ce_b2CollisionPlane;
zend_class_entry *box2d_ce_b2PlaneSolverResult;

ZEND_METHOD(b2RayCastInput, __construct)
{
	zval *origin = NULL;
	zval *translation = NULL;
	double maxFraction = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(origin, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(translation, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(maxFraction)
	ZEND_PARSE_PARAMETERS_END();

	if (origin == NULL) {
		zval created_origin;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_origin) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RayCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("origin"), &created_origin);
		zval_ptr_dtor(&created_origin);
	} else {
		zend_update_property(box2d_ce_b2RayCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("origin"), origin);
	}

	if (translation == NULL) {
		zval created_translation;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_translation) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2RayCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translation"), &created_translation);
		zval_ptr_dtor(&created_translation);
	} else {
		zend_update_property(box2d_ce_b2RayCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translation"), translation);
	}

	zend_update_property_double(box2d_ce_b2RayCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxFraction"), maxFraction);

	b2RayCastInput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2RayCastInput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ShapeProxy, __construct)
{
	zval *points = NULL;
	zend_long count = 0;
	double radius = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(points)
		Z_PARAM_LONG(count)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	if (points == NULL) {
		zval empty_points;
		array_init(&empty_points);
		zend_update_property(box2d_ce_b2ShapeProxy, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), &empty_points);
		zval_ptr_dtor(&empty_points);
	} else {
		zend_update_property(box2d_ce_b2ShapeProxy, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), points);
	}

	zend_update_property_long(box2d_ce_b2ShapeProxy, Z_OBJ_P(ZEND_THIS), ZEND_STRL("count"), count);

	zend_update_property_double(box2d_ce_b2ShapeProxy, Z_OBJ_P(ZEND_THIS), ZEND_STRL("radius"), radius);

	b2ShapeProxy native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ShapeProxy_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ShapeCastInput, __construct)
{
	zval *proxy = NULL;
	zval *translation = NULL;
	double maxFraction = 0.0;
	bool canEncroach = false;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(proxy, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(translation, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(maxFraction)
		Z_PARAM_BOOL(canEncroach)
	ZEND_PARSE_PARAMETERS_END();

	if (proxy == NULL) {
		zval created_proxy;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxy) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxy"), &created_proxy);
		zval_ptr_dtor(&created_proxy);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxy"), proxy);
	}

	if (translation == NULL) {
		zval created_translation;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_translation) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translation"), &created_translation);
		zval_ptr_dtor(&created_translation);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translation"), translation);
	}

	zend_update_property_double(box2d_ce_b2ShapeCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxFraction"), maxFraction);

	zend_update_property_bool(box2d_ce_b2ShapeCastInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("canEncroach"), canEncroach);

	b2ShapeCastInput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ShapeCastInput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2CastOutput, __construct)
{
	zval *normal = NULL;
	zval *point = NULL;
	double fraction = 0.0;
	zend_long iterations = 0;
	bool hit = false;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(normal, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(point, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(fraction)
		Z_PARAM_LONG(iterations)
		Z_PARAM_BOOL(hit)
	ZEND_PARSE_PARAMETERS_END();

	if (normal == NULL) {
		zval created_normal;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_normal) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), &created_normal);
		zval_ptr_dtor(&created_normal);
	} else {
		zend_update_property(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), normal);
	}

	if (point == NULL) {
		zval created_point;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), &created_point);
		zval_ptr_dtor(&created_point);
	} else {
		zend_update_property(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), point);
	}

	zend_update_property_double(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fraction"), fraction);

	zend_update_property_long(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("iterations"), iterations);

	zend_update_property_bool(box2d_ce_b2CastOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hit"), hit);

	b2CastOutput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2CastOutput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2MassData, __construct)
{
	double mass = 0.0;
	zval *center = NULL;
	double rotationalInertia = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(mass)
		Z_PARAM_OBJECT_OF_CLASS(center, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(rotationalInertia)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_double(box2d_ce_b2MassData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("mass"), mass);

	if (center == NULL) {
		zval created_center;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_center) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2MassData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center"), &created_center);
		zval_ptr_dtor(&created_center);
	} else {
		zend_update_property(box2d_ce_b2MassData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center"), center);
	}

	zend_update_property_double(box2d_ce_b2MassData, Z_OBJ_P(ZEND_THIS), ZEND_STRL("rotationalInertia"), rotationalInertia);

	b2MassData native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2MassData_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Circle, __construct)
{
	zval *center = NULL;
	double radius = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(center, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	if (center == NULL) {
		zval created_center;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_center) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Circle, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center"), &created_center);
		zval_ptr_dtor(&created_center);
	} else {
		zend_update_property(box2d_ce_b2Circle, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center"), center);
	}

	zend_update_property_double(box2d_ce_b2Circle, Z_OBJ_P(ZEND_THIS), ZEND_STRL("radius"), radius);

	b2Circle native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Circle_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Capsule, __construct)
{
	zval *center1 = NULL;
	zval *center2 = NULL;
	double radius = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(center1, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(center2, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(radius)
	ZEND_PARSE_PARAMETERS_END();

	if (center1 == NULL) {
		zval created_center1;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_center1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Capsule, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center1"), &created_center1);
		zval_ptr_dtor(&created_center1);
	} else {
		zend_update_property(box2d_ce_b2Capsule, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center1"), center1);
	}

	if (center2 == NULL) {
		zval created_center2;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_center2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Capsule, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center2"), &created_center2);
		zval_ptr_dtor(&created_center2);
	} else {
		zend_update_property(box2d_ce_b2Capsule, Z_OBJ_P(ZEND_THIS), ZEND_STRL("center2"), center2);
	}

	zend_update_property_double(box2d_ce_b2Capsule, Z_OBJ_P(ZEND_THIS), ZEND_STRL("radius"), radius);

	b2Capsule native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Capsule_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Polygon, __construct)
{
	zval *vertices = NULL;
	zval *normals = NULL;
	zval *centroid = NULL;
	double radius = 0.0;
	zend_long count = 0;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(vertices)
		Z_PARAM_ARRAY(normals)
		Z_PARAM_OBJECT_OF_CLASS(centroid, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(radius)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	if (vertices == NULL) {
		zval empty_vertices;
		array_init(&empty_vertices);
		zend_update_property(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("vertices"), &empty_vertices);
		zval_ptr_dtor(&empty_vertices);
	} else {
		zend_update_property(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("vertices"), vertices);
	}

	if (normals == NULL) {
		zval empty_normals;
		array_init(&empty_normals);
		zend_update_property(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normals"), &empty_normals);
		zval_ptr_dtor(&empty_normals);
	} else {
		zend_update_property(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normals"), normals);
	}

	if (centroid == NULL) {
		zval created_centroid;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_centroid) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("centroid"), &created_centroid);
		zval_ptr_dtor(&created_centroid);
	} else {
		zend_update_property(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("centroid"), centroid);
	}

	zend_update_property_double(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("radius"), radius);

	zend_update_property_long(box2d_ce_b2Polygon, Z_OBJ_P(ZEND_THIS), ZEND_STRL("count"), count);

	b2Polygon native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Polygon_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Segment, __construct)
{
	zval *point1 = NULL;
	zval *point2 = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(point1, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(point2, box2d_ce_b2Vec2)
	ZEND_PARSE_PARAMETERS_END();

	if (point1 == NULL) {
		zval created_point1;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Segment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point1"), &created_point1);
		zval_ptr_dtor(&created_point1);
	} else {
		zend_update_property(box2d_ce_b2Segment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point1"), point1);
	}

	if (point2 == NULL) {
		zval created_point2;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Segment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point2"), &created_point2);
		zval_ptr_dtor(&created_point2);
	} else {
		zend_update_property(box2d_ce_b2Segment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point2"), point2);
	}

	b2Segment native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Segment_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ChainSegment, __construct)
{
	zval *ghost1 = NULL;
	zval *segment = NULL;
	zval *ghost2 = NULL;
	zend_long chainId = 0;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(ghost1, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(segment, box2d_ce_b2Segment)
		Z_PARAM_OBJECT_OF_CLASS(ghost2, box2d_ce_b2Vec2)
		Z_PARAM_LONG(chainId)
	ZEND_PARSE_PARAMETERS_END();

	if (ghost1 == NULL) {
		zval created_ghost1;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_ghost1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("ghost1"), &created_ghost1);
		zval_ptr_dtor(&created_ghost1);
	} else {
		zend_update_property(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("ghost1"), ghost1);
	}

	if (segment == NULL) {
		zval created_segment;
		if (box2d_new_default(box2d_ce_b2Segment, &created_segment) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("segment"), &created_segment);
		zval_ptr_dtor(&created_segment);
	} else {
		zend_update_property(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("segment"), segment);
	}

	if (ghost2 == NULL) {
		zval created_ghost2;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_ghost2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("ghost2"), &created_ghost2);
		zval_ptr_dtor(&created_ghost2);
	} else {
		zend_update_property(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("ghost2"), ghost2);
	}

	zend_update_property_long(box2d_ce_b2ChainSegment, Z_OBJ_P(ZEND_THIS), ZEND_STRL("chainId"), chainId);

	b2ChainSegment native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ChainSegment_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Hull, __construct)
{
	zval *points = NULL;
	zend_long count = 0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(points)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	if (points == NULL) {
		zval empty_points;
		array_init(&empty_points);
		zend_update_property(box2d_ce_b2Hull, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), &empty_points);
		zval_ptr_dtor(&empty_points);
	} else {
		zend_update_property(box2d_ce_b2Hull, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), points);
	}

	zend_update_property_long(box2d_ce_b2Hull, Z_OBJ_P(ZEND_THIS), ZEND_STRL("count"), count);

	b2Hull native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Hull_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SegmentDistanceResult, __construct)
{
	zval *closest1 = NULL;
	zval *closest2 = NULL;
	double fraction1 = 0.0;
	double fraction2 = 0.0;
	double distanceSquared = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(closest1, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(closest2, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(fraction1)
		Z_PARAM_DOUBLE(fraction2)
		Z_PARAM_DOUBLE(distanceSquared)
	ZEND_PARSE_PARAMETERS_END();

	if (closest1 == NULL) {
		zval created_closest1;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_closest1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("closest1"), &created_closest1);
		zval_ptr_dtor(&created_closest1);
	} else {
		zend_update_property(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("closest1"), closest1);
	}

	if (closest2 == NULL) {
		zval created_closest2;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_closest2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("closest2"), &created_closest2);
		zval_ptr_dtor(&created_closest2);
	} else {
		zend_update_property(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("closest2"), closest2);
	}

	zend_update_property_double(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fraction1"), fraction1);

	zend_update_property_double(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fraction2"), fraction2);

	zend_update_property_double(box2d_ce_b2SegmentDistanceResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("distanceSquared"), distanceSquared);

	b2SegmentDistanceResult native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SegmentDistanceResult_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SimplexCache, __construct)
{
	zend_long count = 0;
	zval *indexA = NULL;
	zval *indexB = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(count)
		Z_PARAM_ARRAY(indexA)
		Z_PARAM_ARRAY(indexB)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2SimplexCache, Z_OBJ_P(ZEND_THIS), ZEND_STRL("count"), count);

	if (indexA == NULL) {
		box2d_set_long_list(Z_OBJ_P(ZEND_THIS), ZEND_STRL("indexA"), 3);
	} else {
		zend_update_property(box2d_ce_b2SimplexCache, Z_OBJ_P(ZEND_THIS), ZEND_STRL("indexA"), indexA);
	}

	if (indexB == NULL) {
		box2d_set_long_list(Z_OBJ_P(ZEND_THIS), ZEND_STRL("indexB"), 3);
	} else {
		zend_update_property(box2d_ce_b2SimplexCache, Z_OBJ_P(ZEND_THIS), ZEND_STRL("indexB"), indexB);
	}

	b2SimplexCache native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SimplexCache_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2DistanceInput, __construct)
{
	zval *proxyA = NULL;
	zval *proxyB = NULL;
	zval *transformA = NULL;
	zval *transformB = NULL;
	bool useRadii = false;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(proxyA, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(proxyB, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(transformA, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(transformB, box2d_ce_b2Transform)
		Z_PARAM_BOOL(useRadii)
	ZEND_PARSE_PARAMETERS_END();

	if (proxyA == NULL) {
		zval created_proxyA;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxyA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyA"), &created_proxyA);
		zval_ptr_dtor(&created_proxyA);
	} else {
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyA"), proxyA);
	}

	if (proxyB == NULL) {
		zval created_proxyB;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxyB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyB"), &created_proxyB);
		zval_ptr_dtor(&created_proxyB);
	} else {
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyB"), proxyB);
	}

	if (transformA == NULL) {
		zval created_transformA;
		if (box2d_new_default(box2d_ce_b2Transform, &created_transformA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformA"), &created_transformA);
		zval_ptr_dtor(&created_transformA);
	} else {
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformA"), transformA);
	}

	if (transformB == NULL) {
		zval created_transformB;
		if (box2d_new_default(box2d_ce_b2Transform, &created_transformB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformB"), &created_transformB);
		zval_ptr_dtor(&created_transformB);
	} else {
		zend_update_property(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformB"), transformB);
	}

	zend_update_property_bool(box2d_ce_b2DistanceInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("useRadii"), useRadii);

	b2DistanceInput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2DistanceInput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2DistanceOutput, __construct)
{
	zval *pointA = NULL;
	zval *pointB = NULL;
	zval *normal = NULL;
	double distance = 0.0;
	zend_long iterations = 0;
	zend_long simplexCount = 0;

	ZEND_PARSE_PARAMETERS_START(0, 6)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(pointA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(pointB, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(normal, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(distance)
		Z_PARAM_LONG(iterations)
		Z_PARAM_LONG(simplexCount)
	ZEND_PARSE_PARAMETERS_END();

	if (pointA == NULL) {
		zval created_pointA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_pointA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pointA"), &created_pointA);
		zval_ptr_dtor(&created_pointA);
	} else {
		zend_update_property(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pointA"), pointA);
	}

	if (pointB == NULL) {
		zval created_pointB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_pointB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pointB"), &created_pointB);
		zval_ptr_dtor(&created_pointB);
	} else {
		zend_update_property(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pointB"), pointB);
	}

	if (normal == NULL) {
		zval created_normal;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_normal) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), &created_normal);
		zval_ptr_dtor(&created_normal);
	} else {
		zend_update_property(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), normal);
	}

	zend_update_property_double(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("distance"), distance);

	zend_update_property_long(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("iterations"), iterations);

	zend_update_property_long(box2d_ce_b2DistanceOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("simplexCount"), simplexCount);

	b2DistanceOutput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2DistanceOutput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2SimplexVertex, __construct)
{
	zval *wA = NULL;
	zval *wB = NULL;
	zval *w = NULL;
	double a = 0.0;
	zend_long indexA = 0;
	zend_long indexB = 0;

	ZEND_PARSE_PARAMETERS_START(0, 6)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(wA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(wB, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(w, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(a)
		Z_PARAM_LONG(indexA)
		Z_PARAM_LONG(indexB)
	ZEND_PARSE_PARAMETERS_END();

	if (wA == NULL) {
		zval created_wA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_wA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("wA"), &created_wA);
		zval_ptr_dtor(&created_wA);
	} else {
		zend_update_property(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("wA"), wA);
	}

	if (wB == NULL) {
		zval created_wB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_wB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("wB"), &created_wB);
		zval_ptr_dtor(&created_wB);
	} else {
		zend_update_property(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("wB"), wB);
	}

	if (w == NULL) {
		zval created_w;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_w) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("w"), &created_w);
		zval_ptr_dtor(&created_w);
	} else {
		zend_update_property(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("w"), w);
	}

	zend_update_property_double(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("a"), a);

	zend_update_property_long(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("indexA"), indexA);

	zend_update_property_long(box2d_ce_b2SimplexVertex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("indexB"), indexB);

	b2SimplexVertex native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2SimplexVertex_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Simplex, __construct)
{
	zval *v1 = NULL;
	zval *v2 = NULL;
	zval *v3 = NULL;
	zend_long count = 0;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(v1, box2d_ce_b2SimplexVertex)
		Z_PARAM_OBJECT_OF_CLASS(v2, box2d_ce_b2SimplexVertex)
		Z_PARAM_OBJECT_OF_CLASS(v3, box2d_ce_b2SimplexVertex)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	if (v1 == NULL) {
		zval created_v1;
		if (box2d_new_default(box2d_ce_b2SimplexVertex, &created_v1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("v1"), &created_v1);
		zval_ptr_dtor(&created_v1);
	} else {
		zend_update_property(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("v1"), v1);
	}

	if (v2 == NULL) {
		zval created_v2;
		if (box2d_new_default(box2d_ce_b2SimplexVertex, &created_v2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("v2"), &created_v2);
		zval_ptr_dtor(&created_v2);
	} else {
		zend_update_property(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("v2"), v2);
	}

	if (v3 == NULL) {
		zval created_v3;
		if (box2d_new_default(box2d_ce_b2SimplexVertex, &created_v3) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("v3"), &created_v3);
		zval_ptr_dtor(&created_v3);
	} else {
		zend_update_property(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("v3"), v3);
	}

	zend_update_property_long(box2d_ce_b2Simplex, Z_OBJ_P(ZEND_THIS), ZEND_STRL("count"), count);

	b2Simplex native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Simplex_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ShapeCastPairInput, __construct)
{
	zval *proxyA = NULL;
	zval *proxyB = NULL;
	zval *transformA = NULL;
	zval *transformB = NULL;
	zval *translationB = NULL;
	double maxFraction = 0.0;
	bool canEncroach = false;

	ZEND_PARSE_PARAMETERS_START(0, 7)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(proxyA, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(proxyB, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(transformA, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(transformB, box2d_ce_b2Transform)
		Z_PARAM_OBJECT_OF_CLASS(translationB, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(maxFraction)
		Z_PARAM_BOOL(canEncroach)
	ZEND_PARSE_PARAMETERS_END();

	if (proxyA == NULL) {
		zval created_proxyA;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxyA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyA"), &created_proxyA);
		zval_ptr_dtor(&created_proxyA);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyA"), proxyA);
	}

	if (proxyB == NULL) {
		zval created_proxyB;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxyB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyB"), &created_proxyB);
		zval_ptr_dtor(&created_proxyB);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyB"), proxyB);
	}

	if (transformA == NULL) {
		zval created_transformA;
		if (box2d_new_default(box2d_ce_b2Transform, &created_transformA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformA"), &created_transformA);
		zval_ptr_dtor(&created_transformA);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformA"), transformA);
	}

	if (transformB == NULL) {
		zval created_transformB;
		if (box2d_new_default(box2d_ce_b2Transform, &created_transformB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformB"), &created_transformB);
		zval_ptr_dtor(&created_transformB);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("transformB"), transformB);
	}

	if (translationB == NULL) {
		zval created_translationB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_translationB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translationB"), &created_translationB);
		zval_ptr_dtor(&created_translationB);
	} else {
		zend_update_property(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translationB"), translationB);
	}

	zend_update_property_double(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxFraction"), maxFraction);

	zend_update_property_bool(box2d_ce_b2ShapeCastPairInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("canEncroach"), canEncroach);

	b2ShapeCastPairInput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ShapeCastPairInput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Sweep, __construct)
{
	zval *localCenter = NULL;
	zval *c1 = NULL;
	zval *c2 = NULL;
	zval *q1 = NULL;
	zval *q2 = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(localCenter, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(c1, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(c2, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(q1, box2d_ce_b2Rot)
		Z_PARAM_OBJECT_OF_CLASS(q2, box2d_ce_b2Rot)
	ZEND_PARSE_PARAMETERS_END();

	if (localCenter == NULL) {
		zval created_localCenter;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_localCenter) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localCenter"), &created_localCenter);
		zval_ptr_dtor(&created_localCenter);
	} else {
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("localCenter"), localCenter);
	}

	if (c1 == NULL) {
		zval created_c1;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_c1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("c1"), &created_c1);
		zval_ptr_dtor(&created_c1);
	} else {
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("c1"), c1);
	}

	if (c2 == NULL) {
		zval created_c2;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_c2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("c2"), &created_c2);
		zval_ptr_dtor(&created_c2);
	} else {
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("c2"), c2);
	}

	if (q1 == NULL) {
		zval created_q1;
		if (box2d_new_default(box2d_ce_b2Rot, &created_q1) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("q1"), &created_q1);
		zval_ptr_dtor(&created_q1);
	} else {
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("q1"), q1);
	}

	if (q2 == NULL) {
		zval created_q2;
		if (box2d_new_default(box2d_ce_b2Rot, &created_q2) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("q2"), &created_q2);
		zval_ptr_dtor(&created_q2);
	} else {
		zend_update_property(box2d_ce_b2Sweep, Z_OBJ_P(ZEND_THIS), ZEND_STRL("q2"), q2);
	}

	b2Sweep native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Sweep_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2TOIInput, __construct)
{
	zval *proxyA = NULL;
	zval *proxyB = NULL;
	zval *sweepA = NULL;
	zval *sweepB = NULL;
	double maxFraction = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 5)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(proxyA, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(proxyB, box2d_ce_b2ShapeProxy)
		Z_PARAM_OBJECT_OF_CLASS(sweepA, box2d_ce_b2Sweep)
		Z_PARAM_OBJECT_OF_CLASS(sweepB, box2d_ce_b2Sweep)
		Z_PARAM_DOUBLE(maxFraction)
	ZEND_PARSE_PARAMETERS_END();

	if (proxyA == NULL) {
		zval created_proxyA;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxyA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyA"), &created_proxyA);
		zval_ptr_dtor(&created_proxyA);
	} else {
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyA"), proxyA);
	}

	if (proxyB == NULL) {
		zval created_proxyB;
		if (box2d_new_default(box2d_ce_b2ShapeProxy, &created_proxyB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyB"), &created_proxyB);
		zval_ptr_dtor(&created_proxyB);
	} else {
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("proxyB"), proxyB);
	}

	if (sweepA == NULL) {
		zval created_sweepA;
		if (box2d_new_default(box2d_ce_b2Sweep, &created_sweepA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sweepA"), &created_sweepA);
		zval_ptr_dtor(&created_sweepA);
	} else {
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sweepA"), sweepA);
	}

	if (sweepB == NULL) {
		zval created_sweepB;
		if (box2d_new_default(box2d_ce_b2Sweep, &created_sweepB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sweepB"), &created_sweepB);
		zval_ptr_dtor(&created_sweepB);
	} else {
		zend_update_property(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("sweepB"), sweepB);
	}

	zend_update_property_double(box2d_ce_b2TOIInput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("maxFraction"), maxFraction);

	b2TOIInput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2TOIInput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2TOIOutput, __construct)
{
	zend_long state = 0;
	double fraction = 0.0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(state)
		Z_PARAM_DOUBLE(fraction)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2TOIOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("state"), state);

	zend_update_property_double(box2d_ce_b2TOIOutput, Z_OBJ_P(ZEND_THIS), ZEND_STRL("fraction"), fraction);

	b2TOIOutput native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2TOIOutput_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2ManifoldPoint, __construct)
{
	zval *point = NULL;
	zval *anchorA = NULL;
	zval *anchorB = NULL;
	double separation = 0.0;
	double normalImpulse = 0.0;
	double tangentImpulse = 0.0;
	double totalNormalImpulse = 0.0;
	double normalVelocity = 0.0;
	zend_long id = 0;
	bool persisted = false;

	ZEND_PARSE_PARAMETERS_START(0, 10)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(point, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(anchorA, box2d_ce_b2Vec2)
		Z_PARAM_OBJECT_OF_CLASS(anchorB, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(separation)
		Z_PARAM_DOUBLE(normalImpulse)
		Z_PARAM_DOUBLE(tangentImpulse)
		Z_PARAM_DOUBLE(totalNormalImpulse)
		Z_PARAM_DOUBLE(normalVelocity)
		Z_PARAM_LONG(id)
		Z_PARAM_BOOL(persisted)
	ZEND_PARSE_PARAMETERS_END();

	if (point == NULL) {
		zval created_point;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), &created_point);
		zval_ptr_dtor(&created_point);
	} else {
		zend_update_property(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), point);
	}

	if (anchorA == NULL) {
		zval created_anchorA;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_anchorA) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("anchorA"), &created_anchorA);
		zval_ptr_dtor(&created_anchorA);
	} else {
		zend_update_property(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("anchorA"), anchorA);
	}

	if (anchorB == NULL) {
		zval created_anchorB;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_anchorB) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("anchorB"), &created_anchorB);
		zval_ptr_dtor(&created_anchorB);
	} else {
		zend_update_property(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("anchorB"), anchorB);
	}

	zend_update_property_double(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("separation"), separation);

	zend_update_property_double(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normalImpulse"), normalImpulse);

	zend_update_property_double(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("tangentImpulse"), tangentImpulse);

	zend_update_property_double(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("totalNormalImpulse"), totalNormalImpulse);

	zend_update_property_double(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normalVelocity"), normalVelocity);

	zend_update_property_long(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("id"), id);

	zend_update_property_bool(box2d_ce_b2ManifoldPoint, Z_OBJ_P(ZEND_THIS), ZEND_STRL("persisted"), persisted);

	b2ManifoldPoint native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2ManifoldPoint_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2Manifold, __construct)
{
	zval *normal = NULL;
	double rollingImpulse = 0.0;
	zval *points = NULL;
	zend_long pointCount = 0;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(normal, box2d_ce_b2Vec2)
		Z_PARAM_DOUBLE(rollingImpulse)
		Z_PARAM_ARRAY(points)
		Z_PARAM_LONG(pointCount)
	ZEND_PARSE_PARAMETERS_END();

	if (normal == NULL) {
		zval created_normal;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_normal) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2Manifold, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), &created_normal);
		zval_ptr_dtor(&created_normal);
	} else {
		zend_update_property(box2d_ce_b2Manifold, Z_OBJ_P(ZEND_THIS), ZEND_STRL("normal"), normal);
	}

	zend_update_property_double(box2d_ce_b2Manifold, Z_OBJ_P(ZEND_THIS), ZEND_STRL("rollingImpulse"), rollingImpulse);

	if (points == NULL) {
		zval empty_points;
		array_init(&empty_points);
		zend_update_property(box2d_ce_b2Manifold, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), &empty_points);
		zval_ptr_dtor(&empty_points);
	} else {
		zend_update_property(box2d_ce_b2Manifold, Z_OBJ_P(ZEND_THIS), ZEND_STRL("points"), points);
	}

	zend_update_property_long(box2d_ce_b2Manifold, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pointCount"), pointCount);

	b2Manifold native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2Manifold_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2DynamicTree, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	zend_throw_error(NULL, "b2DynamicTree cannot be constructed");
}

ZEND_METHOD(b2TreeStats, __construct)
{
	zend_long nodeVisits = 0;
	zend_long leafVisits = 0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(nodeVisits)
		Z_PARAM_LONG(leafVisits)
	ZEND_PARSE_PARAMETERS_END();

	zend_update_property_long(box2d_ce_b2TreeStats, Z_OBJ_P(ZEND_THIS), ZEND_STRL("nodeVisits"), nodeVisits);

	zend_update_property_long(box2d_ce_b2TreeStats, Z_OBJ_P(ZEND_THIS), ZEND_STRL("leafVisits"), leafVisits);

	b2TreeStats native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2TreeStats_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2PlaneResult, __construct)
{
	zval *plane = NULL;
	zval *point = NULL;
	bool hit = false;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(plane, box2d_ce_b2Plane)
		Z_PARAM_OBJECT_OF_CLASS(point, box2d_ce_b2Vec2)
		Z_PARAM_BOOL(hit)
	ZEND_PARSE_PARAMETERS_END();

	if (plane == NULL) {
		zval created_plane;
		if (box2d_new_default(box2d_ce_b2Plane, &created_plane) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PlaneResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("plane"), &created_plane);
		zval_ptr_dtor(&created_plane);
	} else {
		zend_update_property(box2d_ce_b2PlaneResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("plane"), plane);
	}

	if (point == NULL) {
		zval created_point;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_point) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PlaneResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), &created_point);
		zval_ptr_dtor(&created_point);
	} else {
		zend_update_property(box2d_ce_b2PlaneResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("point"), point);
	}

	zend_update_property_bool(box2d_ce_b2PlaneResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("hit"), hit);

	b2PlaneResult native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2PlaneResult_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2CollisionPlane, __construct)
{
	zval *plane = NULL;
	double pushLimit = 0.0;
	double push = 0.0;
	bool clipVelocity = false;

	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(plane, box2d_ce_b2Plane)
		Z_PARAM_DOUBLE(pushLimit)
		Z_PARAM_DOUBLE(push)
		Z_PARAM_BOOL(clipVelocity)
	ZEND_PARSE_PARAMETERS_END();

	if (plane == NULL) {
		zval created_plane;
		if (box2d_new_default(box2d_ce_b2Plane, &created_plane) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2CollisionPlane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("plane"), &created_plane);
		zval_ptr_dtor(&created_plane);
	} else {
		zend_update_property(box2d_ce_b2CollisionPlane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("plane"), plane);
	}

	zend_update_property_double(box2d_ce_b2CollisionPlane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("pushLimit"), pushLimit);

	zend_update_property_double(box2d_ce_b2CollisionPlane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("push"), push);

	zend_update_property_bool(box2d_ce_b2CollisionPlane, Z_OBJ_P(ZEND_THIS), ZEND_STRL("clipVelocity"), clipVelocity);

	b2CollisionPlane native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2CollisionPlane_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

ZEND_METHOD(b2PlaneSolverResult, __construct)
{
	zval *translation = NULL;
	zend_long iterationCount = 0;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS(translation, box2d_ce_b2Vec2)
		Z_PARAM_LONG(iterationCount)
	ZEND_PARSE_PARAMETERS_END();

	if (translation == NULL) {
		zval created_translation;
		if (box2d_new_default(box2d_ce_b2Vec2, &created_translation) == FAILURE) {
			return;
		}
		zend_update_property(box2d_ce_b2PlaneSolverResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translation"), &created_translation);
		zval_ptr_dtor(&created_translation);
	} else {
		zend_update_property(box2d_ce_b2PlaneSolverResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("translation"), translation);
	}

	zend_update_property_long(box2d_ce_b2PlaneSolverResult, Z_OBJ_P(ZEND_THIS), ZEND_STRL("iterationCount"), iterationCount);

	b2PlaneSolverResult native;
	box2d_frame frame;
	box2d_frame_init(&frame);
	if (box2d_b2PlaneSolverResult_from_zval(ZEND_THIS, &native, &frame) == FAILURE) {
		box2d_frame_free(&frame);
		return;
	}
	box2d_frame_free(&frame);
}

void box2d_register_collision(int module_number)
{
	box2d_ce_b2RayCastInput = register_class_b2RayCastInput();
	box2d_class_is_value(box2d_ce_b2RayCastInput);
	box2d_ce_b2ShapeProxy = register_class_b2ShapeProxy();
	box2d_class_is_value(box2d_ce_b2ShapeProxy);
	box2d_ce_b2ShapeCastInput = register_class_b2ShapeCastInput();
	box2d_class_is_value(box2d_ce_b2ShapeCastInput);
	box2d_ce_b2CastOutput = register_class_b2CastOutput();
	box2d_class_is_value(box2d_ce_b2CastOutput);
	box2d_ce_b2MassData = register_class_b2MassData();
	box2d_class_is_value(box2d_ce_b2MassData);
	box2d_ce_b2Circle = register_class_b2Circle();
	box2d_class_is_value(box2d_ce_b2Circle);
	box2d_ce_b2Capsule = register_class_b2Capsule();
	box2d_class_is_value(box2d_ce_b2Capsule);
	box2d_ce_b2Polygon = register_class_b2Polygon();
	box2d_class_is_value(box2d_ce_b2Polygon);
	box2d_ce_b2Segment = register_class_b2Segment();
	box2d_class_is_value(box2d_ce_b2Segment);
	box2d_ce_b2ChainSegment = register_class_b2ChainSegment();
	box2d_class_is_value(box2d_ce_b2ChainSegment);
	box2d_ce_b2Hull = register_class_b2Hull();
	box2d_class_is_value(box2d_ce_b2Hull);
	box2d_ce_b2SegmentDistanceResult = register_class_b2SegmentDistanceResult();
	box2d_class_is_value(box2d_ce_b2SegmentDistanceResult);
	box2d_ce_b2SimplexCache = register_class_b2SimplexCache();
	box2d_class_is_value(box2d_ce_b2SimplexCache);
	box2d_ce_b2DistanceInput = register_class_b2DistanceInput();
	box2d_class_is_value(box2d_ce_b2DistanceInput);
	box2d_ce_b2DistanceOutput = register_class_b2DistanceOutput();
	box2d_class_is_value(box2d_ce_b2DistanceOutput);
	box2d_ce_b2SimplexVertex = register_class_b2SimplexVertex();
	box2d_class_is_value(box2d_ce_b2SimplexVertex);
	box2d_ce_b2Simplex = register_class_b2Simplex();
	box2d_class_is_value(box2d_ce_b2Simplex);
	box2d_ce_b2ShapeCastPairInput = register_class_b2ShapeCastPairInput();
	box2d_class_is_value(box2d_ce_b2ShapeCastPairInput);
	box2d_ce_b2Sweep = register_class_b2Sweep();
	box2d_class_is_value(box2d_ce_b2Sweep);
	box2d_ce_b2TOIInput = register_class_b2TOIInput();
	box2d_class_is_value(box2d_ce_b2TOIInput);
	box2d_ce_b2TOIOutput = register_class_b2TOIOutput();
	box2d_class_is_value(box2d_ce_b2TOIOutput);
	box2d_ce_b2ManifoldPoint = register_class_b2ManifoldPoint();
	box2d_class_is_value(box2d_ce_b2ManifoldPoint);
	box2d_ce_b2Manifold = register_class_b2Manifold();
	box2d_class_is_value(box2d_ce_b2Manifold);
	box2d_ce_b2DynamicTree = register_class_b2DynamicTree();
	box2d_class_is_tree(box2d_ce_b2DynamicTree);
	box2d_ce_b2TreeStats = register_class_b2TreeStats();
	box2d_class_is_value(box2d_ce_b2TreeStats);
	box2d_ce_b2PlaneResult = register_class_b2PlaneResult();
	box2d_class_is_value(box2d_ce_b2PlaneResult);
	box2d_ce_b2CollisionPlane = register_class_b2CollisionPlane();
	box2d_class_is_value(box2d_ce_b2CollisionPlane);
	box2d_ce_b2PlaneSolverResult = register_class_b2PlaneSolverResult();
	box2d_class_is_value(box2d_ce_b2PlaneSolverResult);
	register_collision_symbols(module_number);
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
}
