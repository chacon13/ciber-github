/* 
 * @file   SimuladorParticulas.cpp
 * @title  Reproduce el comportamiento de las partículas dentro de un espacio cúbico
 * @author Antonio Jesús Rueda Ruiz
 * @author José Ángel Pastrana Padilla
 */

#include "SimuladorParticulas.h"

SimuladorParticulas::SimuladorParticulas(int numParticulas) : particulas(),espacio(),eResultado(),eTotalP(0),eTotalF(0),eDesLibre(0),eDesOcupa(0) {
    srand(time(NULL)); /* Semilla. */
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
}

void SimuladorParticulas::actualizar() {
    srand(time(NULL)); /* Semilla. */
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
                    ++eTotalF;
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
    if (DESINTEGRAR) {
        itP=particulas.iteradorFin();
        while (!itP.fin()) {
            int m=itP.dato()->getMasa();
            if (desintegrarParticula(m)) {
                m/=2;
                itP.dato()->aumentaMasa((-1)*m);

                unsigned int ox, oy, oz;
                int dx, dy, dz;
                ox=itP.dato()->getX(), oy=itP.dato()->getY(), oz=itP.dato()->getZ();
                do {
                    dx=ox+(rand()%3)-1, dy=oy+(rand()%3)-1, dz=oz+(rand()%3)-1;
                } while ((ox==dx && oy==dy) && oz==dz);
                dx = ( dx>=0 ) ? ( ( dx<tE ) ? dx : --dx ) : ++dx; 
                dy = ( dy>=0 ) ? ( ( dy<tE ) ? dy : --dy ) : ++dy; 
                dz = ( dz>=0 ) ? ( ( dz<tE ) ? dz : --dz ) : ++dz; 

                if (espacio(dx,dy,dz)) {
                    espacio(dx,dy,dz)->aumentaMasa(m);
                    ++eDesOcupa; ++eTotalF;
                } else {
                    espacio(dx,dy,dz)=particulas.insertarFin(new Particula(dx,dy,dz,m));
                    ++eDesLibre;
                }
            }
            itP.anterior();
        }
    }
}

void SimuladorParticulas::imprimirEstadisticas() {
    Lista<Particula*>::Iterador itP=particulas.iteradorIni();
    while (!itP.fin()) {
        eResultado[itP.dato()->getMasa()-1]++;
        delete itP.dato();
        if (LIMPIARVISTA) {
                particulas.borrarIni();
        }
        itP.siguiente();
    }
    
    cout << "Masa" << '\t' << "Num. de partículas" << endl;

    for (int c=0; c<tP; ++c) {
        if (eResultado[c]>0) {
            cout << c+1 << '\t' << eResultado[c] << endl;
            eTotalP+=eResultado[c];
        }
    }
    
    cout << "Total de partículas: " << eTotalP << endl;
    cout << "Total de fusiones: "<< eTotalF << endl;
    cout << "Total de desintegraciones: " << eDesLibre+eDesOcupa << endl;
    cout << "Desintegraciones que se fusionaron con una partícula adyacente: " << eDesOcupa << endl ;
}