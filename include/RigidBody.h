#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Vector2D.h"

class RigidBody {
public:
    double mass;
    double restitution; // entre 0 e 1, 1 = rebote perfeito
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    Vector2D netForce;

    explicit RigidBody(double m, double rest = 0.7, const Vector2D& initialPosition = Vector2D(0, 0));

    void applyForce(const Vector2D& force);
    void clearForces();
    void integrate(double deltaTime);

    void printState() const;
};

#endif
