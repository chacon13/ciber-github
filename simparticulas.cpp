//
//  simparticulas.cpp
//  particulas3D
//
//  Created by Antonio Jesús Rueda Ruiz on 21/10/13.
//

#include "simparticulas.h"

SimuladorParticulas::SimuladorParticulas(int numParticulas) : particulas() {
    // Sustituir este código por la creación de partículas propia
    for (int i = 0; i < numParticulas; i++) {
        particulas.push_back(new Particula(rand() % 100, rand() % 100, rand() % 100));
    }
}

SimuladorParticulas::~SimuladorParticulas() {
    // Implementar
}


void SimuladorParticulas::actualizar() {
    // Implementar
}


void SimuladorParticulas::imprimirEstadisticas() {
    // Implementar
}
