/* 
 * @file   Util.h
 * @title  Repositorio de funciones empleadas por las diferentes partes de la aplicación
 * @author José Ángel Pastrana Padilla
 * @email  japp0005@red.ujaen.es
 */

#ifndef UTIL_H
#define	UTIL_H

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

#endif	/* UTIL_H */

