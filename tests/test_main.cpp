#include "../include/Vector2D.h"
#include "../include/RigidBody.h"
#include "../include/PhysicsSim.h"

int main() {
    PhysicsSim sim;

    const RigidBody bola(1.0, 0.7, Vector2D(0, 5)); // posição mais baixa; // posição mais baixa

    sim.addBody(bola);

    sim.applyGlobalForce(Vector2D(0, -9.8)); // gravidade

    for (int i = 0; i < 60; ++i) {
        sim.simulateStep(0.016); // simula 1 frame

        const RigidBody& corpo = sim.bodies[0];
        std::cout << "Frame " << i << ": ";
        corpo.printState();
    }

    return 0;
}
