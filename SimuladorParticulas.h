/* 
 * @file   SimuladorParticulas.h
 * @title  Reproduce el comportamiento de las partículas dentro de un espacio cúbico
 * @author Antonio Jesús Rueda Ruiz
 * @author José Ángel Pastrana Padilla
 */

#ifndef __particulas3D__simuladorparticulas__
#define __particulas3D__simuladorparticulas__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Particula.h"
#include "Lista.h"
#include "Matriz3D.h"
#include "util.h"
#include "config.h"

using namespace std;

/** 
 * @brief Clase donde debe implementarse la simulación de las partículas.
 */
class SimuladorParticulas {
private:
    Lista<Particula*>           particulas; /**< Lista de partículas */
    Matriz3D<Particula*,tE>     espacio; /**< Declaración del espacio 3D. */
    unsigned int                eResultado[tP], /**< Declaración del vector que guardará las estadísticas de masa. */
                                eTotalP, /**< Estadística del total de partículas restantes al finalizar la aplicación. */
                                eTotalF, /**< Estadística del total de fusiones que se produjeron. */
                                eDesLibre, /**< Estadística del total de desintegraciones asignadas en una posición adyacente libre. */
                                eDesOcupa; /**< Estadística del total de desintegraciones asignadas en una posición adyacente ocupada. */
public:
    SimuladorParticulas(int numParticulas = tP); /**< Implementar creación de partículas */
    virtual ~SimuladorParticulas(); /**< Liberación de memoria */
    void actualizar(); /**< Actualización de las partículas (sólo un paso) */
    void imprimirEstadisticas(); /**< Impresión de estadísticas */
    inline Lista<Particula*>& listaParticulas() { return particulas; }/**< Devolver la lista de partículas para visualización */
};


#endif /* defined(__particulas3D__simuladorparticulas__) */