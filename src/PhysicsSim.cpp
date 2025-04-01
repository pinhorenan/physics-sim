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
    handleCollisions();
}

void PhysicsSim::handleCollisions() {
    for (size_t i = 0; i < bodies.size(); i++) {
        for (size_t j = i + 1; j < bodies.size(); j++) {
            if (bodies[i].isColliding(bodies[j])) {
                // Vetor normal da colisão
                Vector2D normal = bodies[j].position - bodies[i].position;
                normal = normal.normalized();

                // Obtém as velocidades na direção do normal (produto escalar)
                const double v1n = (bodies[i].velocity.x * normal.x + bodies[i].velocity.y * normal.y);
                const double v2n = (bodies[j].velocity.x * normal.x + bodies[j].velocity.y * normal.y);

                // Massas dos corpos
                double m1 = bodies[i].mass;
                double m2 = bodies[j].mass;

                // Coeficiente de restituição médio
                double e = (bodies[i].restitution + bodies[j].restitution) / 2.0;

                // Calcula as novas velocidades normais usando as equações de colisão 1D:
                // v1n' = [(m1 - e*m2)*v1n + (1+e)*m2*v2n] / (m1 + m2)
                // v2n' = [(m2 - e*m1)*v2n + (1+e)*m1*v1n] / (m1 + m2)
                double v1n_new = ((m1 - e * m2) * v1n + (1 + e) * m2 * v2n) / (m1 + m2);
                double v2n_new = ((m2 - e * m1) * v2n + (1 + e) * m1 * v1n) / (m1 + m2);

                // Determina o delta na componente normal
                double dv1 = v1n_new - v1n;
                double dv2 = v2n_new - v2n;

                // Atualiza as velocidades, somando a mudança na direção do normal
                bodies[i].velocity = bodies[i].velocity + normal * dv1;
                bodies[j].velocity = bodies[j].velocity + normal * dv2;

                // Resolver interpenetração: empurra os corpos para fora, dividindo a sobreposição igualmente
                double distance = (bodies[j].position - bodies[i].position).magnitude();
                double overlap = (bodies[i].radius + bodies[j].radius) - distance;
                if (overlap > 0) {
                    Vector2D correction = normal * (overlap / 2.0);
                    bodies[i].position = bodies[i].position - correction;
                    bodies[j].position = bodies[j].position + correction;
                }

            }
        }
    }
}