#include "../include/PhysicsSim.h"

int main() {
    PhysicsSim sim;
    sim.simulateStep(0.016); // Simula ~1 frame a 60 FPS
    return 0;
}
