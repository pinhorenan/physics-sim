#ifndef PHYSICSSIM_HPP
#define PHYSICSSIM_HPP

#include <vector>
#include "RigidBody.h"

class PhysicsSim {
public:
    std::vector<RigidBody> bodies;
    Vector2D globalForce;

    PhysicsSim();

    void addBody(const RigidBody& body);
    void applyGlobalForce(const Vector2D& force);
    void simulateStep(double deltaTime);
};

#endif
