#include "RigidBody.h"
#include <iostream>

RigidBody::RigidBody(const double m, const double rest, const Vector2D& initialPosition)
    : mass(m), restitution(rest), position(initialPosition), velocity(0, 0), acceleration(0, 0), netForce(0, 0) {}

void RigidBody::applyForce(const Vector2D& force) {
    netForce = netForce + force;
}

void RigidBody::clearForces() {
    netForce = Vector2D(0, 0);
}

void RigidBody::integrate(const double deltaTime) {
    acceleration = netForce / mass;
    velocity = velocity + acceleration * deltaTime;
    position = position + velocity * deltaTime;
    clearForces();

    // Após atualizar posição:
    position = position + velocity * deltaTime;

    // Colisão com chão (Y ≦ 0)
    if (position.y < 0) {
        position.y = 0; // Corrige "afundamento"
        velocity.y = -velocity.y * restitution; // Rebote
    }

    clearForces();

}

void RigidBody::printState() const {
    std::cout << "Pos: "; position.print();
    std::cout << "Vel: "; velocity.print();
}
