#include "Physics.h"
#include <iostream>


void Physics::SimpleNewtonMotion(PhysicsObject &object, const float deltaTime) {
	object.pos += object.vel * deltaTime + 0.5f * object.accel * deltaTime * deltaTime;
	object.vel += object.accel * deltaTime;
}

void Physics::RigidBodyRotation(PhysicsObject& object, const float deltaTime) {
	object.angle += object.angularVel * deltaTime + 0.5f * object.angularAccel * deltaTime * deltaTime;
	object.angularVel += object.angularAccel * deltaTime;
}

bool Physics::PlaneSphereCollision(const PhysicsObject &object, const Plane &p) {
	return false;
}

void Physics::PlaneSphereCollisionResponse(PhysicsObject &object, const Plane &p) {
}

bool Physics::SphereSphereCollision(const PhysicsObject &object1, const PhysicsObject &object2) {
	return false;
}

void Physics::SphereSphereCollisionResponse(PhysicsObject &object1, PhysicsObject &object2) {
}
