//
//  simparticulas.cpp
//  particulas3D
//
//  Created by Antonio Jesús Rueda Ruiz on 21/10/13.
//

#include "simparticulas.h"

SimuladorParticulas::SimuladorParticulas(int numParticulas) : particulas() {
    // Sustituir este código por la creación de partículas propia
//    for (int i = 0; i < numParticulas; i++) {
//        particulas.insertarFin(new Particula(rand() % 100, rand() % 100, rand() % 100));
//    }
    eResultado=new unsigned int[numParticulas];
    for (int i=0; i<tE; ++i) {
        for (int j=0; j<tE; ++j) {
            for (int k=0; k<tE; ++k) {
                espacio(i,j,k)=0;
            }
        }
    }
    for (int c=0; c<numParticulas; ++c) {
        unsigned int x, y, z;
        do {
            x=rand()%tE, y=rand()%tE, z=rand()%tE;
        } while (espacio(x,y,z));
        espacio(x,y,z)=particulas.insertarFin(new Particula(x,y,z));
        eResultado[c]=0;
    }
}

SimuladorParticulas::~SimuladorParticulas() {
    // Implementar
}


void SimuladorParticulas::actualizar() {
        Lista<Particula*>::Iterador itP=particulas.iteradorIni();
        while (!itP.fin())  {
            if ( rand()%2 ) {
                unsigned int ox, oy, oz;
                int dx, dy, dz;
                ox=itP.dato()->getX(), oy=itP.dato()->getY(), oz=itP.dato()->getZ();
                dx=ox+(rand()%3)-1, dy=oy+(rand()%3)-1, dz=oz+(rand()%3)-1;
                dx = ( dx>=0 ) ? ( ( dx<tE ) ? dx : --dx ) : ++dx; 
                dy = ( dy>=0 ) ? ( ( dy<tE ) ? dy : --dy ) : ++dy; 
                dz = ( dz>=0 ) ? ( ( dz<tE ) ? dz : --dz ) : ++dz; 
                if ( ((ox!=dx) || (oy!=dy)) || (oz!=dz) ) {
                    if (espacio(dx,dy,dz)) {
                        espacio(dx,dy,dz)->aumentaMasa(itP.dato()->getMasa());
                        delete itP.dato();
                        particulas.borrar(itP);
                        espacio(ox,oy,oz)=0;
//                        ++eTotalF;
                    } else {
                        itP.dato()->actualizaPosicion(dx,dy,dz);
                        espacio(ox,oy,oz)=0;
                        espacio(dx,dy,dz)=itP.dato();
                        itP.siguiente();
                    }
                } else {
                    itP.siguiente();
                }
            } else {
                itP.siguiente();
            }
        }
}


void SimuladorParticulas::imprimirEstadisticas() {
    // Implementar
}
