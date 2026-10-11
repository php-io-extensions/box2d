<?php

/** @generate-class-entries */

/**
 * Every category bit. The C macro is UINT64_MAX; a PHP int holds that bit pattern as -1.
 * @var int
 * @cvalue (zend_long) B2_DEFAULT_MASK_BITS
 */
const B2_DEFAULT_MASK_BITS = UNKNOWN;

/**
 * @var int
 * @cvalue B2_DEFAULT_CATEGORY_BITS
 */
const B2_DEFAULT_CATEGORY_BITS = UNKNOWN;

/**
 * @var int
 * @cvalue b2_staticBody
 */
const b2_staticBody = UNKNOWN;

/**
 * @var int
 * @cvalue b2_kinematicBody
 */
const b2_kinematicBody = UNKNOWN;

/**
 * @var int
 * @cvalue b2_dynamicBody
 */
const b2_dynamicBody = UNKNOWN;

/**
 * @var int
 * @cvalue b2_bodyTypeCount
 */
const b2_bodyTypeCount = UNKNOWN;

/**
 * @var int
 * @cvalue b2_circleShape
 */
const b2_circleShape = UNKNOWN;

/**
 * @var int
 * @cvalue b2_capsuleShape
 */
const b2_capsuleShape = UNKNOWN;

/**
 * @var int
 * @cvalue b2_segmentShape
 */
const b2_segmentShape = UNKNOWN;

/**
 * @var int
 * @cvalue b2_polygonShape
 */
const b2_polygonShape = UNKNOWN;

/**
 * @var int
 * @cvalue b2_chainSegmentShape
 */
const b2_chainSegmentShape = UNKNOWN;

/**
 * @var int
 * @cvalue b2_shapeTypeCount
 */
const b2_shapeTypeCount = UNKNOWN;

/**
 * @var int
 * @cvalue b2_distanceJoint
 */
const b2_distanceJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_filterJoint
 */
const b2_filterJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_motorJoint
 */
const b2_motorJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_mouseJoint
 */
const b2_mouseJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_prismaticJoint
 */
const b2_prismaticJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_revoluteJoint
 */
const b2_revoluteJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_weldJoint
 */
const b2_weldJoint = UNKNOWN;

/**
 * @var int
 * @cvalue b2_wheelJoint
 */
const b2_wheelJoint = UNKNOWN;

final class b2RayResult
{
    public b2ShapeId $shapeId;
    public b2Vec2 $point;
    public b2Vec2 $normal;
    public float $fraction = 0.0;
    public int $nodeVisits = 0;
    public int $leafVisits = 0;
    public bool $hit = false;

    public function __construct(b2ShapeId $shapeId = new b2ShapeId(), b2Vec2 $point = new b2Vec2(), b2Vec2 $normal = new b2Vec2(), float $fraction = 0.0, int $nodeVisits = 0, int $leafVisits = 0, bool $hit = false) {}
}

final class b2WorldDef
{
    public b2Vec2 $gravity;
    public float $restitutionThreshold = 0.0;
    public float $hitEventThreshold = 0.0;
    public float $contactHertz = 0.0;
    public float $contactDampingRatio = 0.0;
    public float $maxContactPushSpeed = 0.0;
    public float $maximumLinearSpeed = 0.0;
    public ?Closure $frictionCallback = null;
    public ?Closure $restitutionCallback = null;
    public bool $enableSleep = false;
    public bool $enableContinuous = false;
    public int $workerCount = 0;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2Vec2 $gravity = new b2Vec2(), float $restitutionThreshold = 0.0, float $hitEventThreshold = 0.0, float $contactHertz = 0.0, float $contactDampingRatio = 0.0, float $maxContactPushSpeed = 0.0, float $maximumLinearSpeed = 0.0, ?Closure $frictionCallback = null, ?Closure $restitutionCallback = null, bool $enableSleep = false, bool $enableContinuous = false, int $workerCount = 0, int $userData = 0, int $internalValue = 0) {}
}

final class b2BodyDef
{
    public int $type = 0;
    public b2Vec2 $position;
    public b2Rot $rotation;
    public b2Vec2 $linearVelocity;
    public float $angularVelocity = 0.0;
    public float $linearDamping = 0.0;
    public float $angularDamping = 0.0;
    public float $gravityScale = 0.0;
    public float $sleepThreshold = 0.0;
    public ?string $name = null;
    public int $userData = 0;
    public bool $enableSleep = false;
    public bool $isAwake = false;
    public bool $fixedRotation = false;
    public bool $isBullet = false;
    public bool $isEnabled = false;
    public bool $allowFastRotation = false;
    public int $internalValue = 0;

    public function __construct(int $type = 0, b2Vec2 $position = new b2Vec2(), b2Rot $rotation = new b2Rot(), b2Vec2 $linearVelocity = new b2Vec2(), float $angularVelocity = 0.0, float $linearDamping = 0.0, float $angularDamping = 0.0, float $gravityScale = 0.0, float $sleepThreshold = 0.0, ?string $name = null, int $userData = 0, bool $enableSleep = false, bool $isAwake = false, bool $fixedRotation = false, bool $isBullet = false, bool $isEnabled = false, bool $allowFastRotation = false, int $internalValue = 0) {}
}

final class b2Filter
{
    public int $categoryBits = 0;
    public int $maskBits = 0;
    public int $groupIndex = 0;

    public function __construct(int $categoryBits = 0, int $maskBits = 0, int $groupIndex = 0) {}
}

final class b2QueryFilter
{
    public int $categoryBits = 0;
    public int $maskBits = 0;

    public function __construct(int $categoryBits = 0, int $maskBits = 0) {}
}

final class b2SurfaceMaterial
{
    public float $friction = 0.0;
    public float $restitution = 0.0;
    public float $rollingResistance = 0.0;
    public float $tangentSpeed = 0.0;
    public int $userMaterialId = 0;
    public int $customColor = 0;

    public function __construct(float $friction = 0.0, float $restitution = 0.0, float $rollingResistance = 0.0, float $tangentSpeed = 0.0, int $userMaterialId = 0, int $customColor = 0) {}
}

final class b2ShapeDef
{
    public int $userData = 0;
    public b2SurfaceMaterial $material;
    public float $density = 0.0;
    public b2Filter $filter;
    public bool $isSensor = false;
    public bool $enableSensorEvents = false;
    public bool $enableContactEvents = false;
    public bool $enableHitEvents = false;
    public bool $enablePreSolveEvents = false;
    public bool $invokeContactCreation = false;
    public bool $updateBodyMass = false;
    public int $internalValue = 0;

    public function __construct(int $userData = 0, b2SurfaceMaterial $material = new b2SurfaceMaterial(), float $density = 0.0, b2Filter $filter = new b2Filter(), bool $isSensor = false, bool $enableSensorEvents = false, bool $enableContactEvents = false, bool $enableHitEvents = false, bool $enablePreSolveEvents = false, bool $invokeContactCreation = false, bool $updateBodyMass = false, int $internalValue = 0) {}
}

final class b2ChainDef
{
    public int $userData = 0;
    public array $points = [];
    public int $count = 0;
    public array $materials = [];
    public int $materialCount = 0;
    public b2Filter $filter;
    public bool $isLoop = false;
    public bool $enableSensorEvents = false;
    public int $internalValue = 0;

    public function __construct(int $userData = 0, array $points = [], int $count = 0, array $materials = [], int $materialCount = 0, b2Filter $filter = new b2Filter(), bool $isLoop = false, bool $enableSensorEvents = false, int $internalValue = 0) {}
}

final class b2Profile
{
    public float $step = 0.0;
    public float $pairs = 0.0;
    public float $collide = 0.0;
    public float $solve = 0.0;
    public float $mergeIslands = 0.0;
    public float $prepareStages = 0.0;
    public float $solveConstraints = 0.0;
    public float $prepareConstraints = 0.0;
    public float $integrateVelocities = 0.0;
    public float $warmStart = 0.0;
    public float $solveImpulses = 0.0;
    public float $integratePositions = 0.0;
    public float $relaxImpulses = 0.0;
    public float $applyRestitution = 0.0;
    public float $storeImpulses = 0.0;
    public float $splitIslands = 0.0;
    public float $transforms = 0.0;
    public float $hitEvents = 0.0;
    public float $refit = 0.0;
    public float $bullets = 0.0;
    public float $sleepIslands = 0.0;
    public float $sensors = 0.0;

    public function __construct(float $step = 0.0, float $pairs = 0.0, float $collide = 0.0, float $solve = 0.0, float $mergeIslands = 0.0, float $prepareStages = 0.0, float $solveConstraints = 0.0, float $prepareConstraints = 0.0, float $integrateVelocities = 0.0, float $warmStart = 0.0, float $solveImpulses = 0.0, float $integratePositions = 0.0, float $relaxImpulses = 0.0, float $applyRestitution = 0.0, float $storeImpulses = 0.0, float $splitIslands = 0.0, float $transforms = 0.0, float $hitEvents = 0.0, float $refit = 0.0, float $bullets = 0.0, float $sleepIslands = 0.0, float $sensors = 0.0) {}
}

final class b2Counters
{
    public int $bodyCount = 0;
    public int $shapeCount = 0;
    public int $contactCount = 0;
    public int $jointCount = 0;
    public int $islandCount = 0;
    public int $stackUsed = 0;
    public int $staticTreeHeight = 0;
    public int $treeHeight = 0;
    public int $byteCount = 0;
    public int $taskCount = 0;
    public array $colorCounts = [];

    public function __construct(int $bodyCount = 0, int $shapeCount = 0, int $contactCount = 0, int $jointCount = 0, int $islandCount = 0, int $stackUsed = 0, int $staticTreeHeight = 0, int $treeHeight = 0, int $byteCount = 0, int $taskCount = 0, array $colorCounts = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]) {}
}

final class b2DistanceJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $localAnchorA;
    public b2Vec2 $localAnchorB;
    public float $length = 0.0;
    public bool $enableSpring = false;
    public float $hertz = 0.0;
    public float $dampingRatio = 0.0;
    public bool $enableLimit = false;
    public float $minLength = 0.0;
    public float $maxLength = 0.0;
    public bool $enableMotor = false;
    public float $maxMotorForce = 0.0;
    public float $motorSpeed = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $localAnchorA = new b2Vec2(), b2Vec2 $localAnchorB = new b2Vec2(), float $length = 0.0, bool $enableSpring = false, float $hertz = 0.0, float $dampingRatio = 0.0, bool $enableLimit = false, float $minLength = 0.0, float $maxLength = 0.0, bool $enableMotor = false, float $maxMotorForce = 0.0, float $motorSpeed = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2MotorJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $linearOffset;
    public float $angularOffset = 0.0;
    public float $maxForce = 0.0;
    public float $maxTorque = 0.0;
    public float $correctionFactor = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $linearOffset = new b2Vec2(), float $angularOffset = 0.0, float $maxForce = 0.0, float $maxTorque = 0.0, float $correctionFactor = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2MouseJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $target;
    public float $hertz = 0.0;
    public float $dampingRatio = 0.0;
    public float $maxForce = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $target = new b2Vec2(), float $hertz = 0.0, float $dampingRatio = 0.0, float $maxForce = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2FilterJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), int $userData = 0, int $internalValue = 0) {}
}

final class b2PrismaticJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $localAnchorA;
    public b2Vec2 $localAnchorB;
    public b2Vec2 $localAxisA;
    public float $referenceAngle = 0.0;
    public float $targetTranslation = 0.0;
    public bool $enableSpring = false;
    public float $hertz = 0.0;
    public float $dampingRatio = 0.0;
    public bool $enableLimit = false;
    public float $lowerTranslation = 0.0;
    public float $upperTranslation = 0.0;
    public bool $enableMotor = false;
    public float $maxMotorForce = 0.0;
    public float $motorSpeed = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $localAnchorA = new b2Vec2(), b2Vec2 $localAnchorB = new b2Vec2(), b2Vec2 $localAxisA = new b2Vec2(), float $referenceAngle = 0.0, float $targetTranslation = 0.0, bool $enableSpring = false, float $hertz = 0.0, float $dampingRatio = 0.0, bool $enableLimit = false, float $lowerTranslation = 0.0, float $upperTranslation = 0.0, bool $enableMotor = false, float $maxMotorForce = 0.0, float $motorSpeed = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2RevoluteJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $localAnchorA;
    public b2Vec2 $localAnchorB;
    public float $referenceAngle = 0.0;
    public float $targetAngle = 0.0;
    public bool $enableSpring = false;
    public float $hertz = 0.0;
    public float $dampingRatio = 0.0;
    public bool $enableLimit = false;
    public float $lowerAngle = 0.0;
    public float $upperAngle = 0.0;
    public bool $enableMotor = false;
    public float $maxMotorTorque = 0.0;
    public float $motorSpeed = 0.0;
    public float $drawSize = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $localAnchorA = new b2Vec2(), b2Vec2 $localAnchorB = new b2Vec2(), float $referenceAngle = 0.0, float $targetAngle = 0.0, bool $enableSpring = false, float $hertz = 0.0, float $dampingRatio = 0.0, bool $enableLimit = false, float $lowerAngle = 0.0, float $upperAngle = 0.0, bool $enableMotor = false, float $maxMotorTorque = 0.0, float $motorSpeed = 0.0, float $drawSize = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2WeldJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $localAnchorA;
    public b2Vec2 $localAnchorB;
    public float $referenceAngle = 0.0;
    public float $linearHertz = 0.0;
    public float $angularHertz = 0.0;
    public float $linearDampingRatio = 0.0;
    public float $angularDampingRatio = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $localAnchorA = new b2Vec2(), b2Vec2 $localAnchorB = new b2Vec2(), float $referenceAngle = 0.0, float $linearHertz = 0.0, float $angularHertz = 0.0, float $linearDampingRatio = 0.0, float $angularDampingRatio = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2WheelJointDef
{
    public b2BodyId $bodyIdA;
    public b2BodyId $bodyIdB;
    public b2Vec2 $localAnchorA;
    public b2Vec2 $localAnchorB;
    public b2Vec2 $localAxisA;
    public bool $enableSpring = false;
    public float $hertz = 0.0;
    public float $dampingRatio = 0.0;
    public bool $enableLimit = false;
    public float $lowerTranslation = 0.0;
    public float $upperTranslation = 0.0;
    public bool $enableMotor = false;
    public float $maxMotorTorque = 0.0;
    public float $motorSpeed = 0.0;
    public bool $collideConnected = false;
    public int $userData = 0;
    public int $internalValue = 0;

    public function __construct(b2BodyId $bodyIdA = new b2BodyId(), b2BodyId $bodyIdB = new b2BodyId(), b2Vec2 $localAnchorA = new b2Vec2(), b2Vec2 $localAnchorB = new b2Vec2(), b2Vec2 $localAxisA = new b2Vec2(), bool $enableSpring = false, float $hertz = 0.0, float $dampingRatio = 0.0, bool $enableLimit = false, float $lowerTranslation = 0.0, float $upperTranslation = 0.0, bool $enableMotor = false, float $maxMotorTorque = 0.0, float $motorSpeed = 0.0, bool $collideConnected = false, int $userData = 0, int $internalValue = 0) {}
}

final class b2ExplosionDef
{
    public int $maskBits = 0;
    public b2Vec2 $position;
    public float $radius = 0.0;
    public float $falloff = 0.0;
    public float $impulsePerLength = 0.0;

    public function __construct(int $maskBits = 0, b2Vec2 $position = new b2Vec2(), float $radius = 0.0, float $falloff = 0.0, float $impulsePerLength = 0.0) {}
}

final class b2SensorBeginTouchEvent
{
    public b2ShapeId $sensorShapeId;
    public b2ShapeId $visitorShapeId;

    public function __construct(b2ShapeId $sensorShapeId = new b2ShapeId(), b2ShapeId $visitorShapeId = new b2ShapeId()) {}
}

final class b2SensorEndTouchEvent
{
    public b2ShapeId $sensorShapeId;
    public b2ShapeId $visitorShapeId;

    public function __construct(b2ShapeId $sensorShapeId = new b2ShapeId(), b2ShapeId $visitorShapeId = new b2ShapeId()) {}
}

final class b2SensorEvents
{
    public array $beginEvents = [];
    public array $endEvents = [];
    public int $beginCount = 0;
    public int $endCount = 0;

    public function __construct(array $beginEvents = [], array $endEvents = [], int $beginCount = 0, int $endCount = 0) {}
}

final class b2ContactBeginTouchEvent
{
    public b2ShapeId $shapeIdA;
    public b2ShapeId $shapeIdB;
    public b2Manifold $manifold;

    public function __construct(b2ShapeId $shapeIdA = new b2ShapeId(), b2ShapeId $shapeIdB = new b2ShapeId(), b2Manifold $manifold = new b2Manifold()) {}
}

final class b2ContactEndTouchEvent
{
    public b2ShapeId $shapeIdA;
    public b2ShapeId $shapeIdB;

    public function __construct(b2ShapeId $shapeIdA = new b2ShapeId(), b2ShapeId $shapeIdB = new b2ShapeId()) {}
}

final class b2ContactHitEvent
{
    public b2ShapeId $shapeIdA;
    public b2ShapeId $shapeIdB;
    public b2Vec2 $point;
    public b2Vec2 $normal;
    public float $approachSpeed = 0.0;

    public function __construct(b2ShapeId $shapeIdA = new b2ShapeId(), b2ShapeId $shapeIdB = new b2ShapeId(), b2Vec2 $point = new b2Vec2(), b2Vec2 $normal = new b2Vec2(), float $approachSpeed = 0.0) {}
}

final class b2ContactEvents
{
    public array $beginEvents = [];
    public array $endEvents = [];
    public array $hitEvents = [];
    public int $beginCount = 0;
    public int $endCount = 0;
    public int $hitCount = 0;

    public function __construct(array $beginEvents = [], array $endEvents = [], array $hitEvents = [], int $beginCount = 0, int $endCount = 0, int $hitCount = 0) {}
}

final class b2BodyMoveEvent
{
    public b2Transform $transform;
    public b2BodyId $bodyId;
    public int $userData = 0;
    public bool $fellAsleep = false;

    public function __construct(b2Transform $transform = new b2Transform(), b2BodyId $bodyId = new b2BodyId(), int $userData = 0, bool $fellAsleep = false) {}
}

final class b2BodyEvents
{
    public array $moveEvents = [];
    public int $moveCount = 0;

    public function __construct(array $moveEvents = [], int $moveCount = 0) {}
}

final class b2ContactData
{
    public b2ShapeId $shapeIdA;
    public b2ShapeId $shapeIdB;
    public b2Manifold $manifold;

    public function __construct(b2ShapeId $shapeIdA = new b2ShapeId(), b2ShapeId $shapeIdB = new b2ShapeId(), b2Manifold $manifold = new b2Manifold()) {}
}

final class b2DebugDraw
{
    public ?Closure $DrawPolygonFcn = null;
    public ?Closure $DrawSolidPolygonFcn = null;
    public ?Closure $DrawCircleFcn = null;
    public ?Closure $DrawSolidCircleFcn = null;
    public ?Closure $DrawSolidCapsuleFcn = null;
    public ?Closure $DrawSegmentFcn = null;
    public ?Closure $DrawTransformFcn = null;
    public ?Closure $DrawPointFcn = null;
    public ?Closure $DrawStringFcn = null;
    public b2AABB $drawingBounds;
    public bool $useDrawingBounds = false;
    public bool $drawShapes = false;
    public bool $drawJoints = false;
    public bool $drawJointExtras = false;
    public bool $drawBounds = false;
    public bool $drawMass = false;
    public bool $drawBodyNames = false;
    public bool $drawContacts = false;
    public bool $drawGraphColors = false;
    public bool $drawContactNormals = false;
    public bool $drawContactImpulses = false;
    public bool $drawContactFeatures = false;
    public bool $drawFrictionImpulses = false;
    public bool $drawIslands = false;
    public mixed $context = null;

    public function __construct(?Closure $DrawPolygonFcn = null, ?Closure $DrawSolidPolygonFcn = null, ?Closure $DrawCircleFcn = null, ?Closure $DrawSolidCircleFcn = null, ?Closure $DrawSolidCapsuleFcn = null, ?Closure $DrawSegmentFcn = null, ?Closure $DrawTransformFcn = null, ?Closure $DrawPointFcn = null, ?Closure $DrawStringFcn = null, b2AABB $drawingBounds = new b2AABB(), bool $useDrawingBounds = false, bool $drawShapes = false, bool $drawJoints = false, bool $drawJointExtras = false, bool $drawBounds = false, bool $drawMass = false, bool $drawBodyNames = false, bool $drawContacts = false, bool $drawGraphColors = false, bool $drawContactNormals = false, bool $drawContactImpulses = false, bool $drawContactFeatures = false, bool $drawFrictionImpulses = false, bool $drawIslands = false, mixed $context = null) {}
}

function b2DefaultWorldDef(): b2WorldDef {}

function b2DefaultBodyDef(): b2BodyDef {}

function b2DefaultFilter(): b2Filter {}

function b2DefaultQueryFilter(): b2QueryFilter {}

function b2DefaultSurfaceMaterial(): b2SurfaceMaterial {}

function b2DefaultShapeDef(): b2ShapeDef {}

function b2DefaultChainDef(): b2ChainDef {}

function b2DefaultDistanceJointDef(): b2DistanceJointDef {}

function b2DefaultMotorJointDef(): b2MotorJointDef {}

function b2DefaultMouseJointDef(): b2MouseJointDef {}

function b2DefaultFilterJointDef(): b2FilterJointDef {}

function b2DefaultPrismaticJointDef(): b2PrismaticJointDef {}

function b2DefaultRevoluteJointDef(): b2RevoluteJointDef {}

function b2DefaultWeldJointDef(): b2WeldJointDef {}

function b2DefaultWheelJointDef(): b2WheelJointDef {}

function b2DefaultExplosionDef(): b2ExplosionDef {}

function b2DefaultDebugDraw(): b2DebugDraw {}

