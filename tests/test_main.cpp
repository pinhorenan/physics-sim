#include "../include/Vector2D.h"
#include "../include/RigidBody.h"
#include "../include/PhysicsSim.h"
#include <iostream>
#include <cmath>

// Teste 1: Queda Livre com Colisão com o Chão
void testFreeFall() {
    std::cout << "=== Teste de Queda Livre e Colisao com o Chao ===\n";
    PhysicsSim sim;
    // Cria um corpo em altura 10
    RigidBody body(1.0, 0.7, 0.99, 1.0, Vector2D(0, 10));
    sim.addBody(body);
    sim.applyGlobalForce(Vector2D(0, -9.8)); // gravidade

    // Simula 100 frames (~1.6 segundos)
    for (int i = 0; i < 100; ++i) {
        sim.simulateStep(0.016);
        std::cout << "Frame " << i << ": ";
        sim.bodies[0].printState();
    }
    // Verifica se o corpo colidiu eventualmente com o chão (y == 0)
    if (std::abs(sim.bodies[0].position.y) < 1e-5) {
        std::cout << "Teste de Queda Livre: OK (Colisao com o chao detectada)\n";
    } else {
        std::cout << "Teste de Queda Livre: Falhou (Corpo nao colidiu com o chao)\n";
    }
}

// Teste 2: Colisão entre Dois Corpos
void testTwoBodiesCollision() {
    std::cout << "\n=== Teste de Colisao entre Dois Corpos ===\n";
    PhysicsSim sim;
    // Cria dois corpos com posições próximas para colisão
    RigidBody body1(1.0, 0.7, 0.99, 1.0, Vector2D(0, 5));
    RigidBody body2(1.0, 0.7, 0.99, 1.0, Vector2D(0.5, 5));
    sim.addBody(body1);
    sim.addBody(body2);
    sim.applyGlobalForce(Vector2D(0, -9.8)); // gravidade

    // Simula 60 frames (~1 segundo)
    for (int i = 0; i < 60; ++i) {
        sim.simulateStep(0.016);
        std::cout << "Frame " << i << ":\n";
        for (size_t j = 0; j < sim.bodies.size(); ++j) {
            std::cout << "  Corpo " << j << ": ";
            sim.bodies[j].printState();
        }
    }
    // Verifica se os corpos não estão mais interpenetrados
    double distance = (sim.bodies[0].position - sim.bodies[1].position).magnitude();
    if (distance >= (sim.bodies[0].radius + sim.bodies[1].radius) - 1e-5) {
        std::cout << "Teste de Colisao entre Dois Corpos: OK\n";
    } else {
        std::cout << "Teste de Colisao entre Dois Corpos: Falhou (Corpos sobrepostos)\n";
    }
}

// Teste 3: Múltiplos Corpos em Simulação
void testMultipleBodies() {
    std::cout << "\n=== Teste com Multiplos Corpos ===\n";
    PhysicsSim sim;
    // Cria 5 corpos distribuídos horizontalmente, com mesma altura
    for (int i = 0; i < 5; ++i) {
        // Espaçamento maior que o diâmetro para iniciar sem colisão
        RigidBody body(1.0, 0.7, 0.99, 1.0, Vector2D(i * 2.5, 10));
        sim.addBody(body);
    }
    sim.applyGlobalForce(Vector2D(0, -9.8)); // gravidade

    // Simula 100 frames
    for (int i = 0; i < 100; ++i) {
        sim.simulateStep(0.016);
        std::cout << "Frame " << i << ":\n";
        for (size_t j = 0; j < sim.bodies.size(); ++j) {
            std::cout << "  Corpo " << j << ": ";
            sim.bodies[j].printState();
        }
    }
    std::cout << "Teste com Multiplos Corpos: Concluido\n";
}

// Teste 4: Movimento Horizontal
// Cria um corpo e aplica uma força horizontal (sem gravidade vertical).
void testHorizontalMovement() {
    std::cout << "\n=== Teste de Movimento Horizontal ===\n";
    PhysicsSim sim;
    // Cria um corpo em altura 5
    RigidBody body(1.0, 0.7, 0.99, 1.0, Vector2D(0, 5));
    sim.addBody(body);
    // Aplica força horizontal positiva (5 unidades) e nenhuma vertical
    sim.applyGlobalForce(Vector2D(5, 0));

    for (int i = 0; i < 50; ++i) {
        sim.simulateStep(0.016);
        std::cout << "Frame " << i << ": ";
        sim.bodies[0].printState();
    }
}

// Teste 5: Movimento Inercial com Damping
// Inicia um corpo com velocidade inicial e sem forças externas para verificar a ação do damping.
void testInertialMovement() {
    std::cout << "\n=== Teste de Movimento Inercial com Damping ===\n";
    PhysicsSim sim;
    // Cria um corpo em altura 5
    RigidBody body(1.0, 0.7, 0.99, 1.0, Vector2D(0, 5));
    // Define uma velocidade inicial horizontal (10 unidades) sem aceleração vertical
    body.velocity = Vector2D(10, 0);
    sim.addBody(body);
    // Não aplica nenhuma força global
    sim.applyGlobalForce(Vector2D(0, 0));

    for (int i = 0; i < 50; ++i) {
        sim.simulateStep(0.016);
        std::cout << "Frame " << i << ": ";
        sim.bodies[0].printState();
    }
}

// Teste 6: Rebote no Chão (Múltiplos Quiques)
// Cria um corpo que bate no chão repetidamente para verificar os efeitos da colisão e restituição.
void testGroundBounce() {
    std::cout << "\n=== Teste de Rebote no Chao (Multiplos Quiques) ===\n";
    PhysicsSim sim;
    // Cria um corpo em posição baixa para atingir o chão rapidamente
    RigidBody body(1.0, 0.7, 0.99, 1.0, Vector2D(0, 2));
    sim.addBody(body);
    sim.applyGlobalForce(Vector2D(0, -9.8)); // gravidade

    for (int i = 0; i < 100; ++i) {
        sim.simulateStep(0.016);
        std::cout << "Frame " << i << ": ";
        sim.bodies[0].printState();
    }
}

int main() {
    testFreeFall();
    testTwoBodiesCollision();
    testMultipleBodies();
    testHorizontalMovement();
    testInertialMovement();
    testGroundBounce();
    return 0;
}
