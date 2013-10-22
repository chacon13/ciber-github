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
#include <cmath>
#include "Particula.h"
#include "Lista.h"
#include "Matriz3D.h"

#define tE 100
#define tP 1000
#define desintegrar true

using namespace std;

/**
 * @brief Decide si una partícula se desintegra considerando su masa.
 * @para m Masa de la partícula.
 * @return True si se desintegra, False en cualquier otro caso.
 */
inline bool desintegrarParticula(const unsigned int m) {
    if (m==1) {
        return false;
    } else if (m>1) {
        const float fx=1-exp(-0.2*m); /* Función de probabilidad */
        int px=fx*1000000;
        int ra=rand()%1000000;
        return (ra<=px) ? true : false;
    }
}

/** Clase donde debe implementarse la simulación de las partículas */
class SimuladorParticulas {
    // Añadir aquí estructuras de datos y atributos adicionales
    
    /** Lista de partículas */
    Lista<Particula *> particulas;
    Matriz3D<Particula*,tE>      espacio;
    unsigned int* eResultado;
    unsigned int eTotalP, /**< Estadística del total de partículas restantes al finalizar la aplicación. */
                 eTotalF, /**< Estadística del total de fusiones que se produjeron. */
                 eDesLibre, /**< Estadística del total de desintegraciones asignadas en una posición adyacente libre. */
                 eDesOcupa; /**< Estadística del total de desintegraciones asignadas en una posición adyacente ocupada. */
    
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
    Lista<Particula *>& listaParticulas() {
        return particulas;
    }
};


#endif /* defined(__particulas3D__simuladorparticulas__) */