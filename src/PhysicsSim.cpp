#include "PhysicsSim.h"

PhysicsSim::PhysicsSim() : globalForce(0, 0) {}

void PhysicsSim::addBody(const RigidBody& body) {
    bodies.push_back(body);
}

void PhysicsSim::applyGlobalForce(const Vector2D& force) {
    globalForce = force;
}

void PhysicsSim::simulateStep(double deltaTime) {
    for (RigidBody& body : bodies) {
        body.applyForce(globalForce * body.mass); // F = m * a
        body.integrate(deltaTime);
    }
}
