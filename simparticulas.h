//
//  simparticulas.h
//  particulas3D
//
//  Created by Antonio Jesús Rueda Ruiz on 21/10/13.
//

#ifndef __particulas3D__simuladorparticulas__
#define __particulas3D__simuladorparticulas__

#include <iostream>
#include <list>
#include <cstdlib>
#include "Particula.h"

using namespace std;

/** Clase donde debe implementarse la simulación de las partículas */
class SimuladorParticulas {
    // Añadir aquí estructuras de datos y atributos adicionales
    
    /** Lista de partículas */
    list<Particula *> particulas;
    
public:
    /** Implementar creación de partículas */
    SimuladorParticulas(int numParticulas = 1000);

    /** Liberación de memoria */
    ~SimuladorParticulas();
    
    /** Actualización de las partículas (sólo un paso) */
    void actualizar();
    
    /** Impresión de estadísticas */
    void imprimirEstadisticas();
    
    /** Devolver la lista de partículas para visualización */
    list<Particula *>& listaParticulas() {
        return particulas;
    }
};


#endif /* defined(__particulas3D__simuladorparticulas__) */