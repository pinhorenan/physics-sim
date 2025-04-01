#include "RigidBody.h"
#include <iostream>

RigidBody::RigidBody(const double m, const double rest, const double damp, const double r, const Vector2D& initialPosition)
    : mass(m), restitution(rest), damping(damp), radius(r),
    position(initialPosition), velocity(0, 0), acceleration(0, 0), netForce(0, 0) {}

void RigidBody::applyForce(const Vector2D& force) {
    netForce = netForce + force;
}

void RigidBody::clearForces() {
    netForce = Vector2D(0, 0);
}

void RigidBody::integrate(const double deltaTime) {
    // Calcular aceleração e atualizar velocidade
    acceleration = netForce / mass;
    velocity = velocity + acceleration * deltaTime;

    // Aplicar damping
    velocity = velocity * damping;

    // Atualizar posição
    position = position + velocity * deltaTime;

    clearForces();

    // Colisão com chão (Y ≦ 0)
    if (position.y < 0) {
        position.y = 0;
        velocity.y = -velocity.y * restitution;
    }

    clearForces();
}

void RigidBody::printState() const {
    std::cout << "Pos: "; position.print();
    std::cout << "Vel: "; velocity.print();
}

bool RigidBody::isColliding(const RigidBody& other) const {
    const Vector2D diff = position - other.position;
    const double distance = diff.magnitude();
    return distance < (radius + other.radius);
}
