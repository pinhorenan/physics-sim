#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Vector2D.h"

class RigidBody {
public:
    double mass;
    double restitution; // entre 0 e 1, 1 = rebote perfeito
    double damping;     // entre 0 e 1, 0 = sem amortecimento
    double radius;      // tamanho o corpo, para colisões
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    Vector2D netForce;

    // Construtor: massa, restituição, damping e posição inicial (com valores padrão)
    explicit RigidBody(double m, double rest = 0.7, double damp = 0.99, double r = 1.0, const Vector2D& initialPosition = Vector2D(0, 0));

    void applyForce(const Vector2D& force);
    void clearForces();
    void integrate(double deltaTime);

    void printState() const;

    // Para detectar colisão com outro corpo rígido
    bool isColliding(const RigidBody& other) const;
};

#endif
