#include "../include/Vector2D.h"
#include "../include/RigidBody.h"
#include "../include/PhysicsSim.h"

int main() {
    PhysicsSim sim;

    // Cria dois corpos com posições próximas para testar colisões
    const RigidBody corpo1(1.0, 0.7, 0.99, 1.0, Vector2D(0, 5));
    const RigidBody corpo2(1.0, 0.7, 0.99, 1.0, Vector2D(0.5, 5));
    sim.addBody(corpo1);
    sim.addBody(corpo2);

    sim.applyGlobalForce(Vector2D(0, -9.8)); // gravidade

    for (int i = 0; i < 60; ++i) {
        sim.simulateStep(0.016); // simula 1 frame (~60 FPS)

        std::cout << "Frame " << i << ": ";
        for (size_t j = 0; j < sim.bodies.size(); ++j) {
            std::cout << " Corpo" << j << ": ";
            sim.bodies[j].printState();
        }
    }

    return 0;
}
