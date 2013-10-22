/* 
 * @author José Ángel Pastrana Padilla
 * @email japp0005@red.ujaen.es
 */

#ifndef MATRIZ3D_H
#define	MATRIZ3D_H

#include "FueraRango.h"

/**
 * @brief Representación de una matriz tridimensional.
 */
template<typename T, const unsigned int N>
class Matriz3D {
private:
    T*** vector; /**< Puntero dónde quedará almacenado toda la matriz tridimensional **/
    
public:
    Matriz3D(); /**< Constructor por defecto */ 
    Matriz3D(const Matriz3D<T,N>& orig); /**< Constructor por copia */ 
    virtual ~Matriz3D(); /**< Constructor por defecto */ 
    
    /**
     * @brief Operador ().
     * @param x Acceso al eje X de la matriz.
     * @param y Acceso al eje Y de la matriz.
     * @param z Acceso al eje Z de la matriz.
     * @throw Excepción FueraRango si la posición dada fue inválida.
     * @return Objeto solicitado ubicado en la matriz en las coordenadas indicadas.
     */
    T& operator()(const unsigned int x, const unsigned int y, const unsigned int z) throw (FueraRango);
};

template<typename T, const unsigned int N>
Matriz3D<T,N>::Matriz3D() {
    vector=new T**[N];
    for (int i=0; i<N; ++i) {
        vector[i]=new T*[N];
        for (int j=0; j<N; ++j) {
            vector[i][j]=new T[N];
        }
    }
}

template<typename T, const unsigned int N>
Matriz3D<T,N>::Matriz3D(const Matriz3D<T,N>& orig) {
    vector=new T**[N];
    for (int i=0; i<N; ++i) {
        vector[i]=new T*[N];
        for (int j=0; j<N; ++j) {
            vector[i][j]=new T[N];
            for (int k=0; k<N; ++k) {
                vector[i][j][k]=orig.vector[i][j][k];
            }
        }
    }
}

template<typename T, const unsigned int N>
Matriz3D<T,N>::~Matriz3D() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            delete[] vector[i][j];
        }
        delete[] vector[i];
    }
    delete[] vector;
}

template<typename T, const unsigned int N>
T& Matriz3D<T,N>::operator()(const unsigned int x, const unsigned int y, const unsigned int z) throw (FueraRango) {
    if ( x >= 0 && x < N ) {
        if ( y >= 0 && y < N ) {
            if ( z >= 0 && z < N ) {
                return vector[x][y][z];
            }
        }
    }
    const int indices[]={x,y,z};
    const unsigned int tamIndices[]={N,N,N};
    throw FueraRango(3,indices,tamIndices);
}

#endif	/* MATRIZ3D_H */