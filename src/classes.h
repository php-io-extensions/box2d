#ifndef BOX2D_CLASSES_H
#define BOX2D_CLASSES_H

#include "php.h"
#include "box2d/collision.h"

extern zend_class_entry *box2d_ce_b2Vec2;
extern zend_class_entry *box2d_ce_b2CosSin;
extern zend_class_entry *box2d_ce_b2Rot;
extern zend_class_entry *box2d_ce_b2Transform;
extern zend_class_entry *box2d_ce_b2Mat22;
extern zend_class_entry *box2d_ce_b2AABB;
extern zend_class_entry *box2d_ce_b2Plane;
extern zend_class_entry *box2d_ce_b2Version;
extern zend_class_entry *box2d_ce_b2WorldId;
extern zend_class_entry *box2d_ce_b2BodyId;
extern zend_class_entry *box2d_ce_b2ShapeId;
extern zend_class_entry *box2d_ce_b2ChainId;
extern zend_class_entry *box2d_ce_b2JointId;
extern zend_class_entry *box2d_ce_b2RayCastInput;
extern zend_class_entry *box2d_ce_b2ShapeProxy;
extern zend_class_entry *box2d_ce_b2ShapeCastInput;
extern zend_class_entry *box2d_ce_b2CastOutput;
extern zend_class_entry *box2d_ce_b2MassData;
extern zend_class_entry *box2d_ce_b2Circle;
extern zend_class_entry *box2d_ce_b2Capsule;
extern zend_class_entry *box2d_ce_b2Polygon;
extern zend_class_entry *box2d_ce_b2Segment;
extern zend_class_entry *box2d_ce_b2ChainSegment;
extern zend_class_entry *box2d_ce_b2Hull;
extern zend_class_entry *box2d_ce_b2SegmentDistanceResult;
extern zend_class_entry *box2d_ce_b2SimplexCache;
extern zend_class_entry *box2d_ce_b2DistanceInput;
extern zend_class_entry *box2d_ce_b2DistanceOutput;
extern zend_class_entry *box2d_ce_b2SimplexVertex;
extern zend_class_entry *box2d_ce_b2Simplex;
extern zend_class_entry *box2d_ce_b2ShapeCastPairInput;
extern zend_class_entry *box2d_ce_b2Sweep;
extern zend_class_entry *box2d_ce_b2TOIInput;
extern zend_class_entry *box2d_ce_b2TOIOutput;
extern zend_class_entry *box2d_ce_b2ManifoldPoint;
extern zend_class_entry *box2d_ce_b2Manifold;
extern zend_class_entry *box2d_ce_b2DynamicTree;
extern zend_class_entry *box2d_ce_b2TreeStats;
extern zend_class_entry *box2d_ce_b2PlaneResult;
extern zend_class_entry *box2d_ce_b2CollisionPlane;
extern zend_class_entry *box2d_ce_b2PlaneSolverResult;
extern zend_class_entry *box2d_ce_b2RayResult;
extern zend_class_entry *box2d_ce_b2WorldDef;
extern zend_class_entry *box2d_ce_b2BodyDef;
extern zend_class_entry *box2d_ce_b2Filter;
extern zend_class_entry *box2d_ce_b2QueryFilter;
extern zend_class_entry *box2d_ce_b2SurfaceMaterial;
extern zend_class_entry *box2d_ce_b2ShapeDef;
extern zend_class_entry *box2d_ce_b2ChainDef;
extern zend_class_entry *box2d_ce_b2Profile;
extern zend_class_entry *box2d_ce_b2Counters;
extern zend_class_entry *box2d_ce_b2DistanceJointDef;
extern zend_class_entry *box2d_ce_b2MotorJointDef;
extern zend_class_entry *box2d_ce_b2MouseJointDef;
extern zend_class_entry *box2d_ce_b2FilterJointDef;
extern zend_class_entry *box2d_ce_b2PrismaticJointDef;
extern zend_class_entry *box2d_ce_b2RevoluteJointDef;
extern zend_class_entry *box2d_ce_b2WeldJointDef;
extern zend_class_entry *box2d_ce_b2WheelJointDef;
extern zend_class_entry *box2d_ce_b2ExplosionDef;
extern zend_class_entry *box2d_ce_b2SensorBeginTouchEvent;
extern zend_class_entry *box2d_ce_b2SensorEndTouchEvent;
extern zend_class_entry *box2d_ce_b2SensorEvents;
extern zend_class_entry *box2d_ce_b2ContactBeginTouchEvent;
extern zend_class_entry *box2d_ce_b2ContactEndTouchEvent;
extern zend_class_entry *box2d_ce_b2ContactHitEvent;
extern zend_class_entry *box2d_ce_b2ContactEvents;
extern zend_class_entry *box2d_ce_b2BodyMoveEvent;
extern zend_class_entry *box2d_ce_b2BodyEvents;
extern zend_class_entry *box2d_ce_b2ContactData;
extern zend_class_entry *box2d_ce_b2DebugDraw;
extern zend_class_entry *box2d_ce_b2AssertionError;

void box2d_class_is_value(zend_class_entry *ce);
void box2d_class_is_tree(zend_class_entry *ce);
void box2d_register_structs(int module_number);
void box2d_register_math(int module_number);
void box2d_register_collision(int module_number);
void box2d_register_types(int module_number);
void box2d_register_ids(void);
void box2d_register_api(int module_number);

b2DynamicTree *box2d_tree_native(zend_object *object);
bool box2d_tree_is_live(zend_object *object);
void box2d_tree_set_live(zend_object *object, bool live);

#endif
