/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1040b02b24e490106c488a302eaa5d3e11e228a0 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2_emptySimplexCache, 0, 0, b2SimplexCache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2IsValidRay, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakePolygon, 0, 2, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, hull, b2Hull, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeOffsetPolygon, 0, 3, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, hull, b2Hull, 0)
	ZEND_ARG_OBJ_INFO(0, position, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, rotation, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeOffsetRoundedPolygon, 0, 4, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, hull, b2Hull, 0)
	ZEND_ARG_OBJ_INFO(0, position, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, rotation, b2Rot, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeSquare, 0, 1, b2Polygon, 0)
	ZEND_ARG_TYPE_INFO(0, halfWidth, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeBox, 0, 2, b2Polygon, 0)
	ZEND_ARG_TYPE_INFO(0, halfWidth, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, halfHeight, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeRoundedBox, 0, 3, b2Polygon, 0)
	ZEND_ARG_TYPE_INFO(0, halfWidth, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, halfHeight, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeOffsetBox, 0, 4, b2Polygon, 0)
	ZEND_ARG_TYPE_INFO(0, halfWidth, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, halfHeight, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, center, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, rotation, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeOffsetRoundedBox, 0, 5, b2Polygon, 0)
	ZEND_ARG_TYPE_INFO(0, halfWidth, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, halfHeight, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, center, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, rotation, b2Rot, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2TransformPolygon, 0, 2, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, transform, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, polygon, b2Polygon, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeCircleMass, 0, 2, b2MassData, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Circle, 0)
	ZEND_ARG_TYPE_INFO(0, density, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeCapsuleMass, 0, 2, b2MassData, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Capsule, 0)
	ZEND_ARG_TYPE_INFO(0, density, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputePolygonMass, 0, 2, b2MassData, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Polygon, 0)
	ZEND_ARG_TYPE_INFO(0, density, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeCircleAABB, 0, 2, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, transform, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeCapsuleAABB, 0, 2, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, transform, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputePolygonAABB, 0, 2, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, transform, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeSegmentAABB, 0, 2, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Segment, 0)
	ZEND_ARG_OBJ_INFO(0, transform, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2PointInCircle, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Circle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2PointInCapsule, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Capsule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2PointInPolygon, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, point, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Polygon, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2RayCastCircle, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Circle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2RayCastCapsule, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Capsule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2RayCastSegment, 0, 3, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Segment, 0)
	ZEND_ARG_TYPE_INFO(0, oneSided, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2RayCastPolygon, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Polygon, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ShapeCastCircle, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2ShapeCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Circle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ShapeCastCapsule, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2ShapeCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Capsule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ShapeCastSegment, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2ShapeCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Segment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ShapeCastPolygon, 0, 2, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2ShapeCastInput, 0)
	ZEND_ARG_OBJ_INFO(0, shape, b2Polygon, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ComputeHull, 0, 2, b2Hull, 0)
	ZEND_ARG_TYPE_INFO(0, points, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2ValidateHull, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, hull, b2Hull, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2SegmentDistance, 0, 4, b2SegmentDistanceResult, 0)
	ZEND_ARG_OBJ_INFO(0, p1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, q1, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, p2, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, q2, b2Vec2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ShapeDistance, 0, 4, b2DistanceOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2DistanceInput, 0)
	ZEND_ARG_OBJ_INFO(0, cache, b2SimplexCache, 0)
	ZEND_ARG_TYPE_INFO(1, simplexes, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, simplexCapacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ShapeCast, 0, 1, b2CastOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2ShapeCastPairInput, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeProxy, 0, 3, b2ShapeProxy, 0)
	ZEND_ARG_TYPE_INFO(0, points, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2MakeOffsetProxy, 0, 5, b2ShapeProxy, 0)
	ZEND_ARG_TYPE_INFO(0, points, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, position, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, rotation, b2Rot, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2GetSweepTransform, 0, 2, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, sweep, b2Sweep, 0)
	ZEND_ARG_TYPE_INFO(0, time, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2TimeOfImpact, 0, 1, b2TOIOutput, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2TOIInput, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideCircles, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, circleA, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, circleB, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideCapsuleAndCircle, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, capsuleA, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, circleB, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideSegmentAndCircle, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, segmentA, b2Segment, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, circleB, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollidePolygonAndCircle, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, polygonA, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, circleB, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideCapsules, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, capsuleA, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, capsuleB, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideSegmentAndCapsule, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, segmentA, b2Segment, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, capsuleB, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollidePolygonAndCapsule, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, polygonA, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, capsuleB, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollidePolygons, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, polygonA, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, polygonB, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideSegmentAndPolygon, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, segmentA, b2Segment, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, polygonB, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideChainSegmentAndCircle, 0, 4, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, segmentA, b2ChainSegment, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, circleB, b2Circle, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideChainSegmentAndCapsule, 0, 5, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, segmentA, b2ChainSegment, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, capsuleB, b2Capsule, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, cache, b2SimplexCache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2CollideChainSegmentAndPolygon, 0, 5, b2Manifold, 0)
	ZEND_ARG_OBJ_INFO(0, segmentA, b2ChainSegment, 0)
	ZEND_ARG_OBJ_INFO(0, xfA, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, polygonB, b2Polygon, 0)
	ZEND_ARG_OBJ_INFO(0, xfB, b2Transform, 0)
	ZEND_ARG_OBJ_INFO(0, cache, b2SimplexCache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DynamicTree_Create, 0, 0, b2DynamicTree, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_Destroy, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_CreateProxy, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_OBJ_INFO(0, aabb, b2AABB, 0)
	ZEND_ARG_TYPE_INFO(0, categoryBits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, userData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_DestroyProxy, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_TYPE_INFO(0, proxyId, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_MoveProxy, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_TYPE_INFO(0, proxyId, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aabb, b2AABB, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DynamicTree_EnlargeProxy arginfo_b2DynamicTree_MoveProxy

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_SetCategoryBits, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_TYPE_INFO(0, proxyId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, categoryBits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_GetCategoryBits, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_TYPE_INFO(0, proxyId, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DynamicTree_Query, 0, 5, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_OBJ_INFO(0, aabb, b2AABB, 0)
	ZEND_ARG_TYPE_INFO(0, maskBits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DynamicTree_RayCast, 0, 5, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2RayCastInput, 0)
	ZEND_ARG_TYPE_INFO(0, maskBits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DynamicTree_ShapeCast, 0, 5, b2TreeStats, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_OBJ_INFO(0, input, b2ShapeCastInput, 0)
	ZEND_ARG_TYPE_INFO(0, maskBits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_GetHeight, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_GetAreaRatio, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DynamicTree_GetRootBounds, 0, 1, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DynamicTree_GetProxyCount arginfo_b2DynamicTree_GetHeight

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_b2DynamicTree_Rebuild, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_TYPE_INFO(0, fullBuild, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DynamicTree_GetByteCount arginfo_b2DynamicTree_GetHeight

#define arginfo_b2DynamicTree_GetUserData arginfo_b2DynamicTree_GetCategoryBits

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2DynamicTree_GetAABB, 0, 2, b2AABB, 0)
	ZEND_ARG_OBJ_INFO(0, tree, b2DynamicTree, 0)
	ZEND_ARG_TYPE_INFO(0, proxyId, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_b2DynamicTree_Validate arginfo_b2DynamicTree_Destroy

#define arginfo_b2DynamicTree_ValidateNoEnlarged arginfo_b2DynamicTree_Destroy

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2SolvePlanes, 0, 3, b2PlaneSolverResult, 0)
	ZEND_ARG_OBJ_INFO(0, targetDelta, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, planes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_b2ClipVector, 0, 3, b2Vec2, 0)
	ZEND_ARG_OBJ_INFO(0, vector, b2Vec2, 0)
	ZEND_ARG_TYPE_INFO(0, planes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2RayCastInput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, origin, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, translation, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxFraction, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ShapeProxy___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, points, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, count, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, radius, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ShapeCastInput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxy, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, translation, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxFraction, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, canEncroach, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2CastOutput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, normal, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fraction, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, iterations, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hit, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2MassData___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mass, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, center, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rotationalInertia, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Circle___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, center, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, radius, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Capsule___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, center1, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, center2, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, radius, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Polygon___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, vertices, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, normals, IS_ARRAY, 0, "[]")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, centroid, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, radius, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, count, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Segment___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point1, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point2, b2Vec2, 0, "new b2Vec2()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ChainSegment___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, ghost1, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, segment, b2Segment, 0, "new b2Segment()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, ghost2, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, chainId, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Hull___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, points, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, count, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2SegmentDistanceResult___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, closest1, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, closest2, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fraction1, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fraction2, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, distanceSquared, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2SimplexCache___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, count, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indexA, IS_ARRAY, 0, "[0, 0, 0]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indexB, IS_ARRAY, 0, "[0, 0, 0]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2DistanceInput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxyA, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxyB, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, transformA, b2Transform, 0, "new b2Transform()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, transformB, b2Transform, 0, "new b2Transform()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useRadii, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2DistanceOutput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, pointA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, pointB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, normal, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, distance, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, iterations, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, simplexCount, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2SimplexVertex___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, wA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, wB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, w, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, a, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indexA, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, indexB, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Simplex___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, v1, b2SimplexVertex, 0, "new b2SimplexVertex()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, v2, b2SimplexVertex, 0, "new b2SimplexVertex()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, v3, b2SimplexVertex, 0, "new b2SimplexVertex()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, count, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ShapeCastPairInput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxyA, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxyB, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, transformA, b2Transform, 0, "new b2Transform()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, transformB, b2Transform, 0, "new b2Transform()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, translationB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxFraction, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, canEncroach, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Sweep___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, localCenter, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, c1, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, c2, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, q1, b2Rot, 0, "new b2Rot()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, q2, b2Rot, 0, "new b2Rot()")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2TOIInput___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxyA, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, proxyB, b2ShapeProxy, 0, "new b2ShapeProxy()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, sweepA, b2Sweep, 0, "new b2Sweep()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, sweepB, b2Sweep, 0, "new b2Sweep()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxFraction, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2TOIOutput___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, state, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fraction, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2ManifoldPoint___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, anchorA, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, anchorB, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separation, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, normalImpulse, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, tangentImpulse, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, totalNormalImpulse, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, normalVelocity, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, id, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, persisted, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2Manifold___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, normal, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rollingImpulse, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, points, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pointCount, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2DynamicTree___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2TreeStats___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, nodeVisits, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, leafVisits, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2PlaneResult___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, plane, b2Plane, 0, "new b2Plane()")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, point, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, hit, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2CollisionPlane___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, plane, b2Plane, 0, "new b2Plane()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pushLimit, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, push, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, clipVelocity, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_b2PlaneSolverResult___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, translation, b2Vec2, 0, "new b2Vec2()")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, iterationCount, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_FUNCTION(b2_emptySimplexCache);
ZEND_FUNCTION(b2IsValidRay);
ZEND_FUNCTION(b2MakePolygon);
ZEND_FUNCTION(b2MakeOffsetPolygon);
ZEND_FUNCTION(b2MakeOffsetRoundedPolygon);
ZEND_FUNCTION(b2MakeSquare);
ZEND_FUNCTION(b2MakeBox);
ZEND_FUNCTION(b2MakeRoundedBox);
ZEND_FUNCTION(b2MakeOffsetBox);
ZEND_FUNCTION(b2MakeOffsetRoundedBox);
ZEND_FUNCTION(b2TransformPolygon);
ZEND_FUNCTION(b2ComputeCircleMass);
ZEND_FUNCTION(b2ComputeCapsuleMass);
ZEND_FUNCTION(b2ComputePolygonMass);
ZEND_FUNCTION(b2ComputeCircleAABB);
ZEND_FUNCTION(b2ComputeCapsuleAABB);
ZEND_FUNCTION(b2ComputePolygonAABB);
ZEND_FUNCTION(b2ComputeSegmentAABB);
ZEND_FUNCTION(b2PointInCircle);
ZEND_FUNCTION(b2PointInCapsule);
ZEND_FUNCTION(b2PointInPolygon);
ZEND_FUNCTION(b2RayCastCircle);
ZEND_FUNCTION(b2RayCastCapsule);
ZEND_FUNCTION(b2RayCastSegment);
ZEND_FUNCTION(b2RayCastPolygon);
ZEND_FUNCTION(b2ShapeCastCircle);
ZEND_FUNCTION(b2ShapeCastCapsule);
ZEND_FUNCTION(b2ShapeCastSegment);
ZEND_FUNCTION(b2ShapeCastPolygon);
ZEND_FUNCTION(b2ComputeHull);
ZEND_FUNCTION(b2ValidateHull);
ZEND_FUNCTION(b2SegmentDistance);
ZEND_FUNCTION(b2ShapeDistance);
ZEND_FUNCTION(b2ShapeCast);
ZEND_FUNCTION(b2MakeProxy);
ZEND_FUNCTION(b2MakeOffsetProxy);
ZEND_FUNCTION(b2GetSweepTransform);
ZEND_FUNCTION(b2TimeOfImpact);
ZEND_FUNCTION(b2CollideCircles);
ZEND_FUNCTION(b2CollideCapsuleAndCircle);
ZEND_FUNCTION(b2CollideSegmentAndCircle);
ZEND_FUNCTION(b2CollidePolygonAndCircle);
ZEND_FUNCTION(b2CollideCapsules);
ZEND_FUNCTION(b2CollideSegmentAndCapsule);
ZEND_FUNCTION(b2CollidePolygonAndCapsule);
ZEND_FUNCTION(b2CollidePolygons);
ZEND_FUNCTION(b2CollideSegmentAndPolygon);
ZEND_FUNCTION(b2CollideChainSegmentAndCircle);
ZEND_FUNCTION(b2CollideChainSegmentAndCapsule);
ZEND_FUNCTION(b2CollideChainSegmentAndPolygon);
ZEND_FUNCTION(b2DynamicTree_Create);
ZEND_FUNCTION(b2DynamicTree_Destroy);
ZEND_FUNCTION(b2DynamicTree_CreateProxy);
ZEND_FUNCTION(b2DynamicTree_DestroyProxy);
ZEND_FUNCTION(b2DynamicTree_MoveProxy);
ZEND_FUNCTION(b2DynamicTree_EnlargeProxy);
ZEND_FUNCTION(b2DynamicTree_SetCategoryBits);
ZEND_FUNCTION(b2DynamicTree_GetCategoryBits);
ZEND_FUNCTION(b2DynamicTree_Query);
ZEND_FUNCTION(b2DynamicTree_RayCast);
ZEND_FUNCTION(b2DynamicTree_ShapeCast);
ZEND_FUNCTION(b2DynamicTree_GetHeight);
ZEND_FUNCTION(b2DynamicTree_GetAreaRatio);
ZEND_FUNCTION(b2DynamicTree_GetRootBounds);
ZEND_FUNCTION(b2DynamicTree_GetProxyCount);
ZEND_FUNCTION(b2DynamicTree_Rebuild);
ZEND_FUNCTION(b2DynamicTree_GetByteCount);
ZEND_FUNCTION(b2DynamicTree_GetUserData);
ZEND_FUNCTION(b2DynamicTree_GetAABB);
ZEND_FUNCTION(b2DynamicTree_Validate);
ZEND_FUNCTION(b2DynamicTree_ValidateNoEnlarged);
ZEND_FUNCTION(b2SolvePlanes);
ZEND_FUNCTION(b2ClipVector);
ZEND_METHOD(b2RayCastInput, __construct);
ZEND_METHOD(b2ShapeProxy, __construct);
ZEND_METHOD(b2ShapeCastInput, __construct);
ZEND_METHOD(b2CastOutput, __construct);
ZEND_METHOD(b2MassData, __construct);
ZEND_METHOD(b2Circle, __construct);
ZEND_METHOD(b2Capsule, __construct);
ZEND_METHOD(b2Polygon, __construct);
ZEND_METHOD(b2Segment, __construct);
ZEND_METHOD(b2ChainSegment, __construct);
ZEND_METHOD(b2Hull, __construct);
ZEND_METHOD(b2SegmentDistanceResult, __construct);
ZEND_METHOD(b2SimplexCache, __construct);
ZEND_METHOD(b2DistanceInput, __construct);
ZEND_METHOD(b2DistanceOutput, __construct);
ZEND_METHOD(b2SimplexVertex, __construct);
ZEND_METHOD(b2Simplex, __construct);
ZEND_METHOD(b2ShapeCastPairInput, __construct);
ZEND_METHOD(b2Sweep, __construct);
ZEND_METHOD(b2TOIInput, __construct);
ZEND_METHOD(b2TOIOutput, __construct);
ZEND_METHOD(b2ManifoldPoint, __construct);
ZEND_METHOD(b2Manifold, __construct);
ZEND_METHOD(b2DynamicTree, __construct);
ZEND_METHOD(b2TreeStats, __construct);
ZEND_METHOD(b2PlaneResult, __construct);
ZEND_METHOD(b2CollisionPlane, __construct);
ZEND_METHOD(b2PlaneSolverResult, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(b2_emptySimplexCache, arginfo_b2_emptySimplexCache)
	ZEND_FE(b2IsValidRay, arginfo_b2IsValidRay)
	ZEND_FE(b2MakePolygon, arginfo_b2MakePolygon)
	ZEND_FE(b2MakeOffsetPolygon, arginfo_b2MakeOffsetPolygon)
	ZEND_FE(b2MakeOffsetRoundedPolygon, arginfo_b2MakeOffsetRoundedPolygon)
	ZEND_FE(b2MakeSquare, arginfo_b2MakeSquare)
	ZEND_FE(b2MakeBox, arginfo_b2MakeBox)
	ZEND_FE(b2MakeRoundedBox, arginfo_b2MakeRoundedBox)
	ZEND_FE(b2MakeOffsetBox, arginfo_b2MakeOffsetBox)
	ZEND_FE(b2MakeOffsetRoundedBox, arginfo_b2MakeOffsetRoundedBox)
	ZEND_FE(b2TransformPolygon, arginfo_b2TransformPolygon)
	ZEND_FE(b2ComputeCircleMass, arginfo_b2ComputeCircleMass)
	ZEND_FE(b2ComputeCapsuleMass, arginfo_b2ComputeCapsuleMass)
	ZEND_FE(b2ComputePolygonMass, arginfo_b2ComputePolygonMass)
	ZEND_FE(b2ComputeCircleAABB, arginfo_b2ComputeCircleAABB)
	ZEND_FE(b2ComputeCapsuleAABB, arginfo_b2ComputeCapsuleAABB)
	ZEND_FE(b2ComputePolygonAABB, arginfo_b2ComputePolygonAABB)
	ZEND_FE(b2ComputeSegmentAABB, arginfo_b2ComputeSegmentAABB)
	ZEND_FE(b2PointInCircle, arginfo_b2PointInCircle)
	ZEND_FE(b2PointInCapsule, arginfo_b2PointInCapsule)
	ZEND_FE(b2PointInPolygon, arginfo_b2PointInPolygon)
	ZEND_FE(b2RayCastCircle, arginfo_b2RayCastCircle)
	ZEND_FE(b2RayCastCapsule, arginfo_b2RayCastCapsule)
	ZEND_FE(b2RayCastSegment, arginfo_b2RayCastSegment)
	ZEND_FE(b2RayCastPolygon, arginfo_b2RayCastPolygon)
	ZEND_FE(b2ShapeCastCircle, arginfo_b2ShapeCastCircle)
	ZEND_FE(b2ShapeCastCapsule, arginfo_b2ShapeCastCapsule)
	ZEND_FE(b2ShapeCastSegment, arginfo_b2ShapeCastSegment)
	ZEND_FE(b2ShapeCastPolygon, arginfo_b2ShapeCastPolygon)
	ZEND_FE(b2ComputeHull, arginfo_b2ComputeHull)
	ZEND_FE(b2ValidateHull, arginfo_b2ValidateHull)
	ZEND_FE(b2SegmentDistance, arginfo_b2SegmentDistance)
	ZEND_FE(b2ShapeDistance, arginfo_b2ShapeDistance)
	ZEND_FE(b2ShapeCast, arginfo_b2ShapeCast)
	ZEND_FE(b2MakeProxy, arginfo_b2MakeProxy)
	ZEND_FE(b2MakeOffsetProxy, arginfo_b2MakeOffsetProxy)
	ZEND_FE(b2GetSweepTransform, arginfo_b2GetSweepTransform)
	ZEND_FE(b2TimeOfImpact, arginfo_b2TimeOfImpact)
	ZEND_FE(b2CollideCircles, arginfo_b2CollideCircles)
	ZEND_FE(b2CollideCapsuleAndCircle, arginfo_b2CollideCapsuleAndCircle)
	ZEND_FE(b2CollideSegmentAndCircle, arginfo_b2CollideSegmentAndCircle)
	ZEND_FE(b2CollidePolygonAndCircle, arginfo_b2CollidePolygonAndCircle)
	ZEND_FE(b2CollideCapsules, arginfo_b2CollideCapsules)
	ZEND_FE(b2CollideSegmentAndCapsule, arginfo_b2CollideSegmentAndCapsule)
	ZEND_FE(b2CollidePolygonAndCapsule, arginfo_b2CollidePolygonAndCapsule)
	ZEND_FE(b2CollidePolygons, arginfo_b2CollidePolygons)
	ZEND_FE(b2CollideSegmentAndPolygon, arginfo_b2CollideSegmentAndPolygon)
	ZEND_FE(b2CollideChainSegmentAndCircle, arginfo_b2CollideChainSegmentAndCircle)
	ZEND_FE(b2CollideChainSegmentAndCapsule, arginfo_b2CollideChainSegmentAndCapsule)
	ZEND_FE(b2CollideChainSegmentAndPolygon, arginfo_b2CollideChainSegmentAndPolygon)
	ZEND_FE(b2DynamicTree_Create, arginfo_b2DynamicTree_Create)
	ZEND_FE(b2DynamicTree_Destroy, arginfo_b2DynamicTree_Destroy)
	ZEND_FE(b2DynamicTree_CreateProxy, arginfo_b2DynamicTree_CreateProxy)
	ZEND_FE(b2DynamicTree_DestroyProxy, arginfo_b2DynamicTree_DestroyProxy)
	ZEND_FE(b2DynamicTree_MoveProxy, arginfo_b2DynamicTree_MoveProxy)
	ZEND_FE(b2DynamicTree_EnlargeProxy, arginfo_b2DynamicTree_EnlargeProxy)
	ZEND_FE(b2DynamicTree_SetCategoryBits, arginfo_b2DynamicTree_SetCategoryBits)
	ZEND_FE(b2DynamicTree_GetCategoryBits, arginfo_b2DynamicTree_GetCategoryBits)
	ZEND_FE(b2DynamicTree_Query, arginfo_b2DynamicTree_Query)
	ZEND_FE(b2DynamicTree_RayCast, arginfo_b2DynamicTree_RayCast)
	ZEND_FE(b2DynamicTree_ShapeCast, arginfo_b2DynamicTree_ShapeCast)
	ZEND_FE(b2DynamicTree_GetHeight, arginfo_b2DynamicTree_GetHeight)
	ZEND_FE(b2DynamicTree_GetAreaRatio, arginfo_b2DynamicTree_GetAreaRatio)
	ZEND_FE(b2DynamicTree_GetRootBounds, arginfo_b2DynamicTree_GetRootBounds)
	ZEND_FE(b2DynamicTree_GetProxyCount, arginfo_b2DynamicTree_GetProxyCount)
	ZEND_FE(b2DynamicTree_Rebuild, arginfo_b2DynamicTree_Rebuild)
	ZEND_FE(b2DynamicTree_GetByteCount, arginfo_b2DynamicTree_GetByteCount)
	ZEND_FE(b2DynamicTree_GetUserData, arginfo_b2DynamicTree_GetUserData)
	ZEND_FE(b2DynamicTree_GetAABB, arginfo_b2DynamicTree_GetAABB)
	ZEND_FE(b2DynamicTree_Validate, arginfo_b2DynamicTree_Validate)
	ZEND_FE(b2DynamicTree_ValidateNoEnlarged, arginfo_b2DynamicTree_ValidateNoEnlarged)
	ZEND_FE(b2SolvePlanes, arginfo_b2SolvePlanes)
	ZEND_FE(b2ClipVector, arginfo_b2ClipVector)
	ZEND_FE_END
};

static const zend_function_entry class_b2RayCastInput_methods[] = {
	ZEND_ME(b2RayCastInput, __construct, arginfo_class_b2RayCastInput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ShapeProxy_methods[] = {
	ZEND_ME(b2ShapeProxy, __construct, arginfo_class_b2ShapeProxy___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ShapeCastInput_methods[] = {
	ZEND_ME(b2ShapeCastInput, __construct, arginfo_class_b2ShapeCastInput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2CastOutput_methods[] = {
	ZEND_ME(b2CastOutput, __construct, arginfo_class_b2CastOutput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2MassData_methods[] = {
	ZEND_ME(b2MassData, __construct, arginfo_class_b2MassData___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Circle_methods[] = {
	ZEND_ME(b2Circle, __construct, arginfo_class_b2Circle___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Capsule_methods[] = {
	ZEND_ME(b2Capsule, __construct, arginfo_class_b2Capsule___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Polygon_methods[] = {
	ZEND_ME(b2Polygon, __construct, arginfo_class_b2Polygon___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Segment_methods[] = {
	ZEND_ME(b2Segment, __construct, arginfo_class_b2Segment___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ChainSegment_methods[] = {
	ZEND_ME(b2ChainSegment, __construct, arginfo_class_b2ChainSegment___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Hull_methods[] = {
	ZEND_ME(b2Hull, __construct, arginfo_class_b2Hull___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SegmentDistanceResult_methods[] = {
	ZEND_ME(b2SegmentDistanceResult, __construct, arginfo_class_b2SegmentDistanceResult___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SimplexCache_methods[] = {
	ZEND_ME(b2SimplexCache, __construct, arginfo_class_b2SimplexCache___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2DistanceInput_methods[] = {
	ZEND_ME(b2DistanceInput, __construct, arginfo_class_b2DistanceInput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2DistanceOutput_methods[] = {
	ZEND_ME(b2DistanceOutput, __construct, arginfo_class_b2DistanceOutput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2SimplexVertex_methods[] = {
	ZEND_ME(b2SimplexVertex, __construct, arginfo_class_b2SimplexVertex___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Simplex_methods[] = {
	ZEND_ME(b2Simplex, __construct, arginfo_class_b2Simplex___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ShapeCastPairInput_methods[] = {
	ZEND_ME(b2ShapeCastPairInput, __construct, arginfo_class_b2ShapeCastPairInput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Sweep_methods[] = {
	ZEND_ME(b2Sweep, __construct, arginfo_class_b2Sweep___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2TOIInput_methods[] = {
	ZEND_ME(b2TOIInput, __construct, arginfo_class_b2TOIInput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2TOIOutput_methods[] = {
	ZEND_ME(b2TOIOutput, __construct, arginfo_class_b2TOIOutput___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2ManifoldPoint_methods[] = {
	ZEND_ME(b2ManifoldPoint, __construct, arginfo_class_b2ManifoldPoint___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2Manifold_methods[] = {
	ZEND_ME(b2Manifold, __construct, arginfo_class_b2Manifold___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2DynamicTree_methods[] = {
	ZEND_ME(b2DynamicTree, __construct, arginfo_class_b2DynamicTree___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};

static const zend_function_entry class_b2TreeStats_methods[] = {
	ZEND_ME(b2TreeStats, __construct, arginfo_class_b2TreeStats___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2PlaneResult_methods[] = {
	ZEND_ME(b2PlaneResult, __construct, arginfo_class_b2PlaneResult___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2CollisionPlane_methods[] = {
	ZEND_ME(b2CollisionPlane, __construct, arginfo_class_b2CollisionPlane___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_b2PlaneSolverResult_methods[] = {
	ZEND_ME(b2PlaneSolverResult, __construct, arginfo_class_b2PlaneSolverResult___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_collision_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("b2_toiStateUnknown", b2_toiStateUnknown, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_toiStateFailed", b2_toiStateFailed, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_toiStateOverlapped", b2_toiStateOverlapped, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_toiStateHit", b2_toiStateHit, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("b2_toiStateSeparated", b2_toiStateSeparated, CONST_PERSISTENT);
}

static zend_class_entry *register_class_b2RayCastInput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2RayCastInput", class_b2RayCastInput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_origin_default_value;
	ZVAL_UNDEF(&property_origin_default_value);
	zend_string *property_origin_name = zend_string_init("origin", sizeof("origin") - 1, 1);
	zend_string *property_origin_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_origin_name, &property_origin_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_origin_class_b2Vec2, 0, 0));
	zend_string_release(property_origin_name);

	zval property_translation_default_value;
	ZVAL_UNDEF(&property_translation_default_value);
	zend_string *property_translation_name = zend_string_init("translation", sizeof("translation") - 1, 1);
	zend_string *property_translation_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_translation_name, &property_translation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_translation_class_b2Vec2, 0, 0));
	zend_string_release(property_translation_name);

	zval property_maxFraction_default_value;
	ZVAL_DOUBLE(&property_maxFraction_default_value, 0.0);
	zend_string *property_maxFraction_name = zend_string_init("maxFraction", sizeof("maxFraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFraction_name, &property_maxFraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxFraction_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ShapeProxy(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ShapeProxy", class_b2ShapeProxy_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_points_default_value;
	ZVAL_EMPTY_ARRAY(&property_points_default_value);
	zend_string *property_points_name = zend_string_init("points", sizeof("points") - 1, 1);
	zend_declare_typed_property(class_entry, property_points_name, &property_points_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_points_name);

	zval property_count_default_value;
	ZVAL_LONG(&property_count_default_value, 0);
	zend_string *property_count_name = zend_string_init("count", sizeof("count") - 1, 1);
	zend_declare_typed_property(class_entry, property_count_name, &property_count_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_count_name);

	zval property_radius_default_value;
	ZVAL_DOUBLE(&property_radius_default_value, 0.0);
	zend_string *property_radius_name = zend_string_init("radius", sizeof("radius") - 1, 1);
	zend_declare_typed_property(class_entry, property_radius_name, &property_radius_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_radius_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ShapeCastInput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ShapeCastInput", class_b2ShapeCastInput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_proxy_default_value;
	ZVAL_UNDEF(&property_proxy_default_value);
	zend_string *property_proxy_name = zend_string_init("proxy", sizeof("proxy") - 1, 1);
	zend_string *property_proxy_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxy_name, &property_proxy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxy_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxy_name);

	zval property_translation_default_value;
	ZVAL_UNDEF(&property_translation_default_value);
	zend_string *property_translation_name = zend_string_init("translation", sizeof("translation") - 1, 1);
	zend_string *property_translation_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_translation_name, &property_translation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_translation_class_b2Vec2, 0, 0));
	zend_string_release(property_translation_name);

	zval property_maxFraction_default_value;
	ZVAL_DOUBLE(&property_maxFraction_default_value, 0.0);
	zend_string *property_maxFraction_name = zend_string_init("maxFraction", sizeof("maxFraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFraction_name, &property_maxFraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxFraction_name);

	zval property_canEncroach_default_value;
	ZVAL_FALSE(&property_canEncroach_default_value);
	zend_string *property_canEncroach_name = zend_string_init("canEncroach", sizeof("canEncroach") - 1, 1);
	zend_declare_typed_property(class_entry, property_canEncroach_name, &property_canEncroach_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_canEncroach_name);

	return class_entry;
}

static zend_class_entry *register_class_b2CastOutput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2CastOutput", class_b2CastOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_normal_default_value;
	ZVAL_UNDEF(&property_normal_default_value);
	zend_string *property_normal_name = zend_string_init("normal", sizeof("normal") - 1, 1);
	zend_string *property_normal_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_normal_name, &property_normal_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_normal_class_b2Vec2, 0, 0));
	zend_string_release(property_normal_name);

	zval property_point_default_value;
	ZVAL_UNDEF(&property_point_default_value);
	zend_string *property_point_name = zend_string_init("point", sizeof("point") - 1, 1);
	zend_string *property_point_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point_name, &property_point_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point_class_b2Vec2, 0, 0));
	zend_string_release(property_point_name);

	zval property_fraction_default_value;
	ZVAL_DOUBLE(&property_fraction_default_value, 0.0);
	zend_string *property_fraction_name = zend_string_init("fraction", sizeof("fraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_fraction_name, &property_fraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_fraction_name);

	zval property_iterations_default_value;
	ZVAL_LONG(&property_iterations_default_value, 0);
	zend_string *property_iterations_name = zend_string_init("iterations", sizeof("iterations") - 1, 1);
	zend_declare_typed_property(class_entry, property_iterations_name, &property_iterations_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_iterations_name);

	zval property_hit_default_value;
	ZVAL_FALSE(&property_hit_default_value);
	zend_string *property_hit_name = zend_string_init("hit", sizeof("hit") - 1, 1);
	zend_declare_typed_property(class_entry, property_hit_name, &property_hit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_hit_name);

	return class_entry;
}

static zend_class_entry *register_class_b2MassData(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2MassData", class_b2MassData_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_mass_default_value;
	ZVAL_DOUBLE(&property_mass_default_value, 0.0);
	zend_string *property_mass_name = zend_string_init("mass", sizeof("mass") - 1, 1);
	zend_declare_typed_property(class_entry, property_mass_name, &property_mass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mass_name);

	zval property_center_default_value;
	ZVAL_UNDEF(&property_center_default_value);
	zend_string *property_center_name = zend_string_init("center", sizeof("center") - 1, 1);
	zend_string *property_center_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_center_name, &property_center_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_center_class_b2Vec2, 0, 0));
	zend_string_release(property_center_name);

	zval property_rotationalInertia_default_value;
	ZVAL_DOUBLE(&property_rotationalInertia_default_value, 0.0);
	zend_string *property_rotationalInertia_name = zend_string_init("rotationalInertia", sizeof("rotationalInertia") - 1, 1);
	zend_declare_typed_property(class_entry, property_rotationalInertia_name, &property_rotationalInertia_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_rotationalInertia_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Circle(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Circle", class_b2Circle_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_center_default_value;
	ZVAL_UNDEF(&property_center_default_value);
	zend_string *property_center_name = zend_string_init("center", sizeof("center") - 1, 1);
	zend_string *property_center_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_center_name, &property_center_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_center_class_b2Vec2, 0, 0));
	zend_string_release(property_center_name);

	zval property_radius_default_value;
	ZVAL_DOUBLE(&property_radius_default_value, 0.0);
	zend_string *property_radius_name = zend_string_init("radius", sizeof("radius") - 1, 1);
	zend_declare_typed_property(class_entry, property_radius_name, &property_radius_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_radius_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Capsule(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Capsule", class_b2Capsule_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_center1_default_value;
	ZVAL_UNDEF(&property_center1_default_value);
	zend_string *property_center1_name = zend_string_init("center1", sizeof("center1") - 1, 1);
	zend_string *property_center1_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_center1_name, &property_center1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_center1_class_b2Vec2, 0, 0));
	zend_string_release(property_center1_name);

	zval property_center2_default_value;
	ZVAL_UNDEF(&property_center2_default_value);
	zend_string *property_center2_name = zend_string_init("center2", sizeof("center2") - 1, 1);
	zend_string *property_center2_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_center2_name, &property_center2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_center2_class_b2Vec2, 0, 0));
	zend_string_release(property_center2_name);

	zval property_radius_default_value;
	ZVAL_DOUBLE(&property_radius_default_value, 0.0);
	zend_string *property_radius_name = zend_string_init("radius", sizeof("radius") - 1, 1);
	zend_declare_typed_property(class_entry, property_radius_name, &property_radius_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_radius_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Polygon(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Polygon", class_b2Polygon_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_vertices_default_value;
	ZVAL_EMPTY_ARRAY(&property_vertices_default_value);
	zend_string *property_vertices_name = zend_string_init("vertices", sizeof("vertices") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertices_name, &property_vertices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_vertices_name);

	zval property_normals_default_value;
	ZVAL_EMPTY_ARRAY(&property_normals_default_value);
	zend_string *property_normals_name = zend_string_init("normals", sizeof("normals") - 1, 1);
	zend_declare_typed_property(class_entry, property_normals_name, &property_normals_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_normals_name);

	zval property_centroid_default_value;
	ZVAL_UNDEF(&property_centroid_default_value);
	zend_string *property_centroid_name = zend_string_init("centroid", sizeof("centroid") - 1, 1);
	zend_string *property_centroid_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_centroid_name, &property_centroid_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_centroid_class_b2Vec2, 0, 0));
	zend_string_release(property_centroid_name);

	zval property_radius_default_value;
	ZVAL_DOUBLE(&property_radius_default_value, 0.0);
	zend_string *property_radius_name = zend_string_init("radius", sizeof("radius") - 1, 1);
	zend_declare_typed_property(class_entry, property_radius_name, &property_radius_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_radius_name);

	zval property_count_default_value;
	ZVAL_LONG(&property_count_default_value, 0);
	zend_string *property_count_name = zend_string_init("count", sizeof("count") - 1, 1);
	zend_declare_typed_property(class_entry, property_count_name, &property_count_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_count_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Segment(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Segment", class_b2Segment_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_point1_default_value;
	ZVAL_UNDEF(&property_point1_default_value);
	zend_string *property_point1_name = zend_string_init("point1", sizeof("point1") - 1, 1);
	zend_string *property_point1_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point1_name, &property_point1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point1_class_b2Vec2, 0, 0));
	zend_string_release(property_point1_name);

	zval property_point2_default_value;
	ZVAL_UNDEF(&property_point2_default_value);
	zend_string *property_point2_name = zend_string_init("point2", sizeof("point2") - 1, 1);
	zend_string *property_point2_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point2_name, &property_point2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point2_class_b2Vec2, 0, 0));
	zend_string_release(property_point2_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ChainSegment(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ChainSegment", class_b2ChainSegment_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_ghost1_default_value;
	ZVAL_UNDEF(&property_ghost1_default_value);
	zend_string *property_ghost1_name = zend_string_init("ghost1", sizeof("ghost1") - 1, 1);
	zend_string *property_ghost1_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_ghost1_name, &property_ghost1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_ghost1_class_b2Vec2, 0, 0));
	zend_string_release(property_ghost1_name);

	zval property_segment_default_value;
	ZVAL_UNDEF(&property_segment_default_value);
	zend_string *property_segment_name = zend_string_init("segment", sizeof("segment") - 1, 1);
	zend_string *property_segment_class_b2Segment = zend_string_init("b2Segment", sizeof("b2Segment")-1, 1);
	zend_declare_typed_property(class_entry, property_segment_name, &property_segment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_segment_class_b2Segment, 0, 0));
	zend_string_release(property_segment_name);

	zval property_ghost2_default_value;
	ZVAL_UNDEF(&property_ghost2_default_value);
	zend_string *property_ghost2_name = zend_string_init("ghost2", sizeof("ghost2") - 1, 1);
	zend_string *property_ghost2_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_ghost2_name, &property_ghost2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_ghost2_class_b2Vec2, 0, 0));
	zend_string_release(property_ghost2_name);

	zval property_chainId_default_value;
	ZVAL_LONG(&property_chainId_default_value, 0);
	zend_string *property_chainId_name = zend_string_init("chainId", sizeof("chainId") - 1, 1);
	zend_declare_typed_property(class_entry, property_chainId_name, &property_chainId_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_chainId_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Hull(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Hull", class_b2Hull_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_points_default_value;
	ZVAL_EMPTY_ARRAY(&property_points_default_value);
	zend_string *property_points_name = zend_string_init("points", sizeof("points") - 1, 1);
	zend_declare_typed_property(class_entry, property_points_name, &property_points_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_points_name);

	zval property_count_default_value;
	ZVAL_LONG(&property_count_default_value, 0);
	zend_string *property_count_name = zend_string_init("count", sizeof("count") - 1, 1);
	zend_declare_typed_property(class_entry, property_count_name, &property_count_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_count_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SegmentDistanceResult(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SegmentDistanceResult", class_b2SegmentDistanceResult_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_closest1_default_value;
	ZVAL_UNDEF(&property_closest1_default_value);
	zend_string *property_closest1_name = zend_string_init("closest1", sizeof("closest1") - 1, 1);
	zend_string *property_closest1_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_closest1_name, &property_closest1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_closest1_class_b2Vec2, 0, 0));
	zend_string_release(property_closest1_name);

	zval property_closest2_default_value;
	ZVAL_UNDEF(&property_closest2_default_value);
	zend_string *property_closest2_name = zend_string_init("closest2", sizeof("closest2") - 1, 1);
	zend_string *property_closest2_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_closest2_name, &property_closest2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_closest2_class_b2Vec2, 0, 0));
	zend_string_release(property_closest2_name);

	zval property_fraction1_default_value;
	ZVAL_DOUBLE(&property_fraction1_default_value, 0.0);
	zend_string *property_fraction1_name = zend_string_init("fraction1", sizeof("fraction1") - 1, 1);
	zend_declare_typed_property(class_entry, property_fraction1_name, &property_fraction1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_fraction1_name);

	zval property_fraction2_default_value;
	ZVAL_DOUBLE(&property_fraction2_default_value, 0.0);
	zend_string *property_fraction2_name = zend_string_init("fraction2", sizeof("fraction2") - 1, 1);
	zend_declare_typed_property(class_entry, property_fraction2_name, &property_fraction2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_fraction2_name);

	zval property_distanceSquared_default_value;
	ZVAL_DOUBLE(&property_distanceSquared_default_value, 0.0);
	zend_string *property_distanceSquared_name = zend_string_init("distanceSquared", sizeof("distanceSquared") - 1, 1);
	zend_declare_typed_property(class_entry, property_distanceSquared_name, &property_distanceSquared_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_distanceSquared_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SimplexCache(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SimplexCache", class_b2SimplexCache_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_count_default_value;
	ZVAL_LONG(&property_count_default_value, 0);
	zend_string *property_count_name = zend_string_init("count", sizeof("count") - 1, 1);
	zend_declare_typed_property(class_entry, property_count_name, &property_count_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_count_name);

	zval property_indexA_default_value;
	ZVAL_EMPTY_ARRAY(&property_indexA_default_value);
	zend_string *property_indexA_name = zend_string_init("indexA", sizeof("indexA") - 1, 1);
	zend_declare_typed_property(class_entry, property_indexA_name, &property_indexA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_indexA_name);

	zval property_indexB_default_value;
	ZVAL_EMPTY_ARRAY(&property_indexB_default_value);
	zend_string *property_indexB_name = zend_string_init("indexB", sizeof("indexB") - 1, 1);
	zend_declare_typed_property(class_entry, property_indexB_name, &property_indexB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_indexB_name);

	return class_entry;
}

static zend_class_entry *register_class_b2DistanceInput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2DistanceInput", class_b2DistanceInput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_proxyA_default_value;
	ZVAL_UNDEF(&property_proxyA_default_value);
	zend_string *property_proxyA_name = zend_string_init("proxyA", sizeof("proxyA") - 1, 1);
	zend_string *property_proxyA_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxyA_name, &property_proxyA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxyA_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxyA_name);

	zval property_proxyB_default_value;
	ZVAL_UNDEF(&property_proxyB_default_value);
	zend_string *property_proxyB_name = zend_string_init("proxyB", sizeof("proxyB") - 1, 1);
	zend_string *property_proxyB_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxyB_name, &property_proxyB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxyB_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxyB_name);

	zval property_transformA_default_value;
	ZVAL_UNDEF(&property_transformA_default_value);
	zend_string *property_transformA_name = zend_string_init("transformA", sizeof("transformA") - 1, 1);
	zend_string *property_transformA_class_b2Transform = zend_string_init("b2Transform", sizeof("b2Transform")-1, 1);
	zend_declare_typed_property(class_entry, property_transformA_name, &property_transformA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_transformA_class_b2Transform, 0, 0));
	zend_string_release(property_transformA_name);

	zval property_transformB_default_value;
	ZVAL_UNDEF(&property_transformB_default_value);
	zend_string *property_transformB_name = zend_string_init("transformB", sizeof("transformB") - 1, 1);
	zend_string *property_transformB_class_b2Transform = zend_string_init("b2Transform", sizeof("b2Transform")-1, 1);
	zend_declare_typed_property(class_entry, property_transformB_name, &property_transformB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_transformB_class_b2Transform, 0, 0));
	zend_string_release(property_transformB_name);

	zval property_useRadii_default_value;
	ZVAL_FALSE(&property_useRadii_default_value);
	zend_string *property_useRadii_name = zend_string_init("useRadii", sizeof("useRadii") - 1, 1);
	zend_declare_typed_property(class_entry, property_useRadii_name, &property_useRadii_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_useRadii_name);

	return class_entry;
}

static zend_class_entry *register_class_b2DistanceOutput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2DistanceOutput", class_b2DistanceOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_pointA_default_value;
	ZVAL_UNDEF(&property_pointA_default_value);
	zend_string *property_pointA_name = zend_string_init("pointA", sizeof("pointA") - 1, 1);
	zend_string *property_pointA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_pointA_name, &property_pointA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pointA_class_b2Vec2, 0, 0));
	zend_string_release(property_pointA_name);

	zval property_pointB_default_value;
	ZVAL_UNDEF(&property_pointB_default_value);
	zend_string *property_pointB_name = zend_string_init("pointB", sizeof("pointB") - 1, 1);
	zend_string *property_pointB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_pointB_name, &property_pointB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pointB_class_b2Vec2, 0, 0));
	zend_string_release(property_pointB_name);

	zval property_normal_default_value;
	ZVAL_UNDEF(&property_normal_default_value);
	zend_string *property_normal_name = zend_string_init("normal", sizeof("normal") - 1, 1);
	zend_string *property_normal_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_normal_name, &property_normal_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_normal_class_b2Vec2, 0, 0));
	zend_string_release(property_normal_name);

	zval property_distance_default_value;
	ZVAL_DOUBLE(&property_distance_default_value, 0.0);
	zend_string *property_distance_name = zend_string_init("distance", sizeof("distance") - 1, 1);
	zend_declare_typed_property(class_entry, property_distance_name, &property_distance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_distance_name);

	zval property_iterations_default_value;
	ZVAL_LONG(&property_iterations_default_value, 0);
	zend_string *property_iterations_name = zend_string_init("iterations", sizeof("iterations") - 1, 1);
	zend_declare_typed_property(class_entry, property_iterations_name, &property_iterations_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_iterations_name);

	zval property_simplexCount_default_value;
	ZVAL_LONG(&property_simplexCount_default_value, 0);
	zend_string *property_simplexCount_name = zend_string_init("simplexCount", sizeof("simplexCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_simplexCount_name, &property_simplexCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_simplexCount_name);

	return class_entry;
}

static zend_class_entry *register_class_b2SimplexVertex(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2SimplexVertex", class_b2SimplexVertex_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_wA_default_value;
	ZVAL_UNDEF(&property_wA_default_value);
	zend_string *property_wA_name = zend_string_init("wA", sizeof("wA") - 1, 1);
	zend_string *property_wA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_wA_name, &property_wA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_wA_class_b2Vec2, 0, 0));
	zend_string_release(property_wA_name);

	zval property_wB_default_value;
	ZVAL_UNDEF(&property_wB_default_value);
	zend_string *property_wB_name = zend_string_init("wB", sizeof("wB") - 1, 1);
	zend_string *property_wB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_wB_name, &property_wB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_wB_class_b2Vec2, 0, 0));
	zend_string_release(property_wB_name);

	zval property_w_default_value;
	ZVAL_UNDEF(&property_w_default_value);
	zend_string *property_w_name = zend_string_init("w", sizeof("w") - 1, 1);
	zend_string *property_w_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_w_name, &property_w_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_w_class_b2Vec2, 0, 0));
	zend_string_release(property_w_name);

	zval property_a_default_value;
	ZVAL_DOUBLE(&property_a_default_value, 0.0);
	zend_string *property_a_name = zend_string_init("a", sizeof("a") - 1, 1);
	zend_declare_typed_property(class_entry, property_a_name, &property_a_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_a_name);

	zval property_indexA_default_value;
	ZVAL_LONG(&property_indexA_default_value, 0);
	zend_string *property_indexA_name = zend_string_init("indexA", sizeof("indexA") - 1, 1);
	zend_declare_typed_property(class_entry, property_indexA_name, &property_indexA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_indexA_name);

	zval property_indexB_default_value;
	ZVAL_LONG(&property_indexB_default_value, 0);
	zend_string *property_indexB_name = zend_string_init("indexB", sizeof("indexB") - 1, 1);
	zend_declare_typed_property(class_entry, property_indexB_name, &property_indexB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_indexB_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Simplex(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Simplex", class_b2Simplex_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_v1_default_value;
	ZVAL_UNDEF(&property_v1_default_value);
	zend_string *property_v1_name = zend_string_init("v1", sizeof("v1") - 1, 1);
	zend_string *property_v1_class_b2SimplexVertex = zend_string_init("b2SimplexVertex", sizeof("b2SimplexVertex")-1, 1);
	zend_declare_typed_property(class_entry, property_v1_name, &property_v1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_v1_class_b2SimplexVertex, 0, 0));
	zend_string_release(property_v1_name);

	zval property_v2_default_value;
	ZVAL_UNDEF(&property_v2_default_value);
	zend_string *property_v2_name = zend_string_init("v2", sizeof("v2") - 1, 1);
	zend_string *property_v2_class_b2SimplexVertex = zend_string_init("b2SimplexVertex", sizeof("b2SimplexVertex")-1, 1);
	zend_declare_typed_property(class_entry, property_v2_name, &property_v2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_v2_class_b2SimplexVertex, 0, 0));
	zend_string_release(property_v2_name);

	zval property_v3_default_value;
	ZVAL_UNDEF(&property_v3_default_value);
	zend_string *property_v3_name = zend_string_init("v3", sizeof("v3") - 1, 1);
	zend_string *property_v3_class_b2SimplexVertex = zend_string_init("b2SimplexVertex", sizeof("b2SimplexVertex")-1, 1);
	zend_declare_typed_property(class_entry, property_v3_name, &property_v3_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_v3_class_b2SimplexVertex, 0, 0));
	zend_string_release(property_v3_name);

	zval property_count_default_value;
	ZVAL_LONG(&property_count_default_value, 0);
	zend_string *property_count_name = zend_string_init("count", sizeof("count") - 1, 1);
	zend_declare_typed_property(class_entry, property_count_name, &property_count_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_count_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ShapeCastPairInput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ShapeCastPairInput", class_b2ShapeCastPairInput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_proxyA_default_value;
	ZVAL_UNDEF(&property_proxyA_default_value);
	zend_string *property_proxyA_name = zend_string_init("proxyA", sizeof("proxyA") - 1, 1);
	zend_string *property_proxyA_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxyA_name, &property_proxyA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxyA_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxyA_name);

	zval property_proxyB_default_value;
	ZVAL_UNDEF(&property_proxyB_default_value);
	zend_string *property_proxyB_name = zend_string_init("proxyB", sizeof("proxyB") - 1, 1);
	zend_string *property_proxyB_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxyB_name, &property_proxyB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxyB_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxyB_name);

	zval property_transformA_default_value;
	ZVAL_UNDEF(&property_transformA_default_value);
	zend_string *property_transformA_name = zend_string_init("transformA", sizeof("transformA") - 1, 1);
	zend_string *property_transformA_class_b2Transform = zend_string_init("b2Transform", sizeof("b2Transform")-1, 1);
	zend_declare_typed_property(class_entry, property_transformA_name, &property_transformA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_transformA_class_b2Transform, 0, 0));
	zend_string_release(property_transformA_name);

	zval property_transformB_default_value;
	ZVAL_UNDEF(&property_transformB_default_value);
	zend_string *property_transformB_name = zend_string_init("transformB", sizeof("transformB") - 1, 1);
	zend_string *property_transformB_class_b2Transform = zend_string_init("b2Transform", sizeof("b2Transform")-1, 1);
	zend_declare_typed_property(class_entry, property_transformB_name, &property_transformB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_transformB_class_b2Transform, 0, 0));
	zend_string_release(property_transformB_name);

	zval property_translationB_default_value;
	ZVAL_UNDEF(&property_translationB_default_value);
	zend_string *property_translationB_name = zend_string_init("translationB", sizeof("translationB") - 1, 1);
	zend_string *property_translationB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_translationB_name, &property_translationB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_translationB_class_b2Vec2, 0, 0));
	zend_string_release(property_translationB_name);

	zval property_maxFraction_default_value;
	ZVAL_DOUBLE(&property_maxFraction_default_value, 0.0);
	zend_string *property_maxFraction_name = zend_string_init("maxFraction", sizeof("maxFraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFraction_name, &property_maxFraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxFraction_name);

	zval property_canEncroach_default_value;
	ZVAL_FALSE(&property_canEncroach_default_value);
	zend_string *property_canEncroach_name = zend_string_init("canEncroach", sizeof("canEncroach") - 1, 1);
	zend_declare_typed_property(class_entry, property_canEncroach_name, &property_canEncroach_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_canEncroach_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Sweep(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Sweep", class_b2Sweep_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_localCenter_default_value;
	ZVAL_UNDEF(&property_localCenter_default_value);
	zend_string *property_localCenter_name = zend_string_init("localCenter", sizeof("localCenter") - 1, 1);
	zend_string *property_localCenter_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_localCenter_name, &property_localCenter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_localCenter_class_b2Vec2, 0, 0));
	zend_string_release(property_localCenter_name);

	zval property_c1_default_value;
	ZVAL_UNDEF(&property_c1_default_value);
	zend_string *property_c1_name = zend_string_init("c1", sizeof("c1") - 1, 1);
	zend_string *property_c1_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_c1_name, &property_c1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_c1_class_b2Vec2, 0, 0));
	zend_string_release(property_c1_name);

	zval property_c2_default_value;
	ZVAL_UNDEF(&property_c2_default_value);
	zend_string *property_c2_name = zend_string_init("c2", sizeof("c2") - 1, 1);
	zend_string *property_c2_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_c2_name, &property_c2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_c2_class_b2Vec2, 0, 0));
	zend_string_release(property_c2_name);

	zval property_q1_default_value;
	ZVAL_UNDEF(&property_q1_default_value);
	zend_string *property_q1_name = zend_string_init("q1", sizeof("q1") - 1, 1);
	zend_string *property_q1_class_b2Rot = zend_string_init("b2Rot", sizeof("b2Rot")-1, 1);
	zend_declare_typed_property(class_entry, property_q1_name, &property_q1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_q1_class_b2Rot, 0, 0));
	zend_string_release(property_q1_name);

	zval property_q2_default_value;
	ZVAL_UNDEF(&property_q2_default_value);
	zend_string *property_q2_name = zend_string_init("q2", sizeof("q2") - 1, 1);
	zend_string *property_q2_class_b2Rot = zend_string_init("b2Rot", sizeof("b2Rot")-1, 1);
	zend_declare_typed_property(class_entry, property_q2_name, &property_q2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_q2_class_b2Rot, 0, 0));
	zend_string_release(property_q2_name);

	return class_entry;
}

static zend_class_entry *register_class_b2TOIInput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2TOIInput", class_b2TOIInput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_proxyA_default_value;
	ZVAL_UNDEF(&property_proxyA_default_value);
	zend_string *property_proxyA_name = zend_string_init("proxyA", sizeof("proxyA") - 1, 1);
	zend_string *property_proxyA_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxyA_name, &property_proxyA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxyA_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxyA_name);

	zval property_proxyB_default_value;
	ZVAL_UNDEF(&property_proxyB_default_value);
	zend_string *property_proxyB_name = zend_string_init("proxyB", sizeof("proxyB") - 1, 1);
	zend_string *property_proxyB_class_b2ShapeProxy = zend_string_init("b2ShapeProxy", sizeof("b2ShapeProxy")-1, 1);
	zend_declare_typed_property(class_entry, property_proxyB_name, &property_proxyB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_proxyB_class_b2ShapeProxy, 0, 0));
	zend_string_release(property_proxyB_name);

	zval property_sweepA_default_value;
	ZVAL_UNDEF(&property_sweepA_default_value);
	zend_string *property_sweepA_name = zend_string_init("sweepA", sizeof("sweepA") - 1, 1);
	zend_string *property_sweepA_class_b2Sweep = zend_string_init("b2Sweep", sizeof("b2Sweep")-1, 1);
	zend_declare_typed_property(class_entry, property_sweepA_name, &property_sweepA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_sweepA_class_b2Sweep, 0, 0));
	zend_string_release(property_sweepA_name);

	zval property_sweepB_default_value;
	ZVAL_UNDEF(&property_sweepB_default_value);
	zend_string *property_sweepB_name = zend_string_init("sweepB", sizeof("sweepB") - 1, 1);
	zend_string *property_sweepB_class_b2Sweep = zend_string_init("b2Sweep", sizeof("b2Sweep")-1, 1);
	zend_declare_typed_property(class_entry, property_sweepB_name, &property_sweepB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_sweepB_class_b2Sweep, 0, 0));
	zend_string_release(property_sweepB_name);

	zval property_maxFraction_default_value;
	ZVAL_DOUBLE(&property_maxFraction_default_value, 0.0);
	zend_string *property_maxFraction_name = zend_string_init("maxFraction", sizeof("maxFraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFraction_name, &property_maxFraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxFraction_name);

	return class_entry;
}

static zend_class_entry *register_class_b2TOIOutput(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2TOIOutput", class_b2TOIOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_state_default_value;
	ZVAL_LONG(&property_state_default_value, 0);
	zend_string *property_state_name = zend_string_init("state", sizeof("state") - 1, 1);
	zend_declare_typed_property(class_entry, property_state_name, &property_state_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_state_name);

	zval property_fraction_default_value;
	ZVAL_DOUBLE(&property_fraction_default_value, 0.0);
	zend_string *property_fraction_name = zend_string_init("fraction", sizeof("fraction") - 1, 1);
	zend_declare_typed_property(class_entry, property_fraction_name, &property_fraction_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_fraction_name);

	return class_entry;
}

static zend_class_entry *register_class_b2ManifoldPoint(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2ManifoldPoint", class_b2ManifoldPoint_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_point_default_value;
	ZVAL_UNDEF(&property_point_default_value);
	zend_string *property_point_name = zend_string_init("point", sizeof("point") - 1, 1);
	zend_string *property_point_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point_name, &property_point_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point_class_b2Vec2, 0, 0));
	zend_string_release(property_point_name);

	zval property_anchorA_default_value;
	ZVAL_UNDEF(&property_anchorA_default_value);
	zend_string *property_anchorA_name = zend_string_init("anchorA", sizeof("anchorA") - 1, 1);
	zend_string *property_anchorA_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_anchorA_name, &property_anchorA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_anchorA_class_b2Vec2, 0, 0));
	zend_string_release(property_anchorA_name);

	zval property_anchorB_default_value;
	ZVAL_UNDEF(&property_anchorB_default_value);
	zend_string *property_anchorB_name = zend_string_init("anchorB", sizeof("anchorB") - 1, 1);
	zend_string *property_anchorB_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_anchorB_name, &property_anchorB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_anchorB_class_b2Vec2, 0, 0));
	zend_string_release(property_anchorB_name);

	zval property_separation_default_value;
	ZVAL_DOUBLE(&property_separation_default_value, 0.0);
	zend_string *property_separation_name = zend_string_init("separation", sizeof("separation") - 1, 1);
	zend_declare_typed_property(class_entry, property_separation_name, &property_separation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_separation_name);

	zval property_normalImpulse_default_value;
	ZVAL_DOUBLE(&property_normalImpulse_default_value, 0.0);
	zend_string *property_normalImpulse_name = zend_string_init("normalImpulse", sizeof("normalImpulse") - 1, 1);
	zend_declare_typed_property(class_entry, property_normalImpulse_name, &property_normalImpulse_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_normalImpulse_name);

	zval property_tangentImpulse_default_value;
	ZVAL_DOUBLE(&property_tangentImpulse_default_value, 0.0);
	zend_string *property_tangentImpulse_name = zend_string_init("tangentImpulse", sizeof("tangentImpulse") - 1, 1);
	zend_declare_typed_property(class_entry, property_tangentImpulse_name, &property_tangentImpulse_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_tangentImpulse_name);

	zval property_totalNormalImpulse_default_value;
	ZVAL_DOUBLE(&property_totalNormalImpulse_default_value, 0.0);
	zend_string *property_totalNormalImpulse_name = zend_string_init("totalNormalImpulse", sizeof("totalNormalImpulse") - 1, 1);
	zend_declare_typed_property(class_entry, property_totalNormalImpulse_name, &property_totalNormalImpulse_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_totalNormalImpulse_name);

	zval property_normalVelocity_default_value;
	ZVAL_DOUBLE(&property_normalVelocity_default_value, 0.0);
	zend_string *property_normalVelocity_name = zend_string_init("normalVelocity", sizeof("normalVelocity") - 1, 1);
	zend_declare_typed_property(class_entry, property_normalVelocity_name, &property_normalVelocity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_normalVelocity_name);

	zval property_id_default_value;
	ZVAL_LONG(&property_id_default_value, 0);
	zend_string *property_id_name = zend_string_init("id", sizeof("id") - 1, 1);
	zend_declare_typed_property(class_entry, property_id_name, &property_id_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_id_name);

	zval property_persisted_default_value;
	ZVAL_FALSE(&property_persisted_default_value);
	zend_string *property_persisted_name = zend_string_init("persisted", sizeof("persisted") - 1, 1);
	zend_declare_typed_property(class_entry, property_persisted_name, &property_persisted_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_persisted_name);

	return class_entry;
}

static zend_class_entry *register_class_b2Manifold(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2Manifold", class_b2Manifold_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_normal_default_value;
	ZVAL_UNDEF(&property_normal_default_value);
	zend_string *property_normal_name = zend_string_init("normal", sizeof("normal") - 1, 1);
	zend_string *property_normal_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_normal_name, &property_normal_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_normal_class_b2Vec2, 0, 0));
	zend_string_release(property_normal_name);

	zval property_rollingImpulse_default_value;
	ZVAL_DOUBLE(&property_rollingImpulse_default_value, 0.0);
	zend_string *property_rollingImpulse_name = zend_string_init("rollingImpulse", sizeof("rollingImpulse") - 1, 1);
	zend_declare_typed_property(class_entry, property_rollingImpulse_name, &property_rollingImpulse_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_rollingImpulse_name);

	zval property_points_default_value;
	ZVAL_EMPTY_ARRAY(&property_points_default_value);
	zend_string *property_points_name = zend_string_init("points", sizeof("points") - 1, 1);
	zend_declare_typed_property(class_entry, property_points_name, &property_points_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_points_name);

	zval property_pointCount_default_value;
	ZVAL_LONG(&property_pointCount_default_value, 0);
	zend_string *property_pointCount_name = zend_string_init("pointCount", sizeof("pointCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_pointCount_name, &property_pointCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_pointCount_name);

	return class_entry;
}

static zend_class_entry *register_class_b2DynamicTree(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2DynamicTree", class_b2DynamicTree_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	return class_entry;
}

static zend_class_entry *register_class_b2TreeStats(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2TreeStats", class_b2TreeStats_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_nodeVisits_default_value;
	ZVAL_LONG(&property_nodeVisits_default_value, 0);
	zend_string *property_nodeVisits_name = zend_string_init("nodeVisits", sizeof("nodeVisits") - 1, 1);
	zend_declare_typed_property(class_entry, property_nodeVisits_name, &property_nodeVisits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_nodeVisits_name);

	zval property_leafVisits_default_value;
	ZVAL_LONG(&property_leafVisits_default_value, 0);
	zend_string *property_leafVisits_name = zend_string_init("leafVisits", sizeof("leafVisits") - 1, 1);
	zend_declare_typed_property(class_entry, property_leafVisits_name, &property_leafVisits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_leafVisits_name);

	return class_entry;
}

static zend_class_entry *register_class_b2PlaneResult(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2PlaneResult", class_b2PlaneResult_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_plane_default_value;
	ZVAL_UNDEF(&property_plane_default_value);
	zend_string *property_plane_name = zend_string_init("plane", sizeof("plane") - 1, 1);
	zend_string *property_plane_class_b2Plane = zend_string_init("b2Plane", sizeof("b2Plane")-1, 1);
	zend_declare_typed_property(class_entry, property_plane_name, &property_plane_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_plane_class_b2Plane, 0, 0));
	zend_string_release(property_plane_name);

	zval property_point_default_value;
	ZVAL_UNDEF(&property_point_default_value);
	zend_string *property_point_name = zend_string_init("point", sizeof("point") - 1, 1);
	zend_string *property_point_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_point_name, &property_point_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_point_class_b2Vec2, 0, 0));
	zend_string_release(property_point_name);

	zval property_hit_default_value;
	ZVAL_FALSE(&property_hit_default_value);
	zend_string *property_hit_name = zend_string_init("hit", sizeof("hit") - 1, 1);
	zend_declare_typed_property(class_entry, property_hit_name, &property_hit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_hit_name);

	return class_entry;
}

static zend_class_entry *register_class_b2CollisionPlane(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2CollisionPlane", class_b2CollisionPlane_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_plane_default_value;
	ZVAL_UNDEF(&property_plane_default_value);
	zend_string *property_plane_name = zend_string_init("plane", sizeof("plane") - 1, 1);
	zend_string *property_plane_class_b2Plane = zend_string_init("b2Plane", sizeof("b2Plane")-1, 1);
	zend_declare_typed_property(class_entry, property_plane_name, &property_plane_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_plane_class_b2Plane, 0, 0));
	zend_string_release(property_plane_name);

	zval property_pushLimit_default_value;
	ZVAL_DOUBLE(&property_pushLimit_default_value, 0.0);
	zend_string *property_pushLimit_name = zend_string_init("pushLimit", sizeof("pushLimit") - 1, 1);
	zend_declare_typed_property(class_entry, property_pushLimit_name, &property_pushLimit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_pushLimit_name);

	zval property_push_default_value;
	ZVAL_DOUBLE(&property_push_default_value, 0.0);
	zend_string *property_push_name = zend_string_init("push", sizeof("push") - 1, 1);
	zend_declare_typed_property(class_entry, property_push_name, &property_push_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_push_name);

	zval property_clipVelocity_default_value;
	ZVAL_FALSE(&property_clipVelocity_default_value);
	zend_string *property_clipVelocity_name = zend_string_init("clipVelocity", sizeof("clipVelocity") - 1, 1);
	zend_declare_typed_property(class_entry, property_clipVelocity_name, &property_clipVelocity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_clipVelocity_name);

	return class_entry;
}

static zend_class_entry *register_class_b2PlaneSolverResult(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "b2PlaneSolverResult", class_b2PlaneSolverResult_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_translation_default_value;
	ZVAL_UNDEF(&property_translation_default_value);
	zend_string *property_translation_name = zend_string_init("translation", sizeof("translation") - 1, 1);
	zend_string *property_translation_class_b2Vec2 = zend_string_init("b2Vec2", sizeof("b2Vec2")-1, 1);
	zend_declare_typed_property(class_entry, property_translation_name, &property_translation_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_translation_class_b2Vec2, 0, 0));
	zend_string_release(property_translation_name);

	zval property_iterationCount_default_value;
	ZVAL_LONG(&property_iterationCount_default_value, 0);
	zend_string *property_iterationCount_name = zend_string_init("iterationCount", sizeof("iterationCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_iterationCount_name, &property_iterationCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_iterationCount_name);

	return class_entry;
}
