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

/**
 * @brief Construcción de las aristas de un cubo usando GLUT.
 * @pre Definición de la dimensión en una variable llamada GL_tE. Ejemplo: const float GL_tE=tE/10.0f;
 */
#define GL_ARISTACUBO \
    glColor4f(0.0f,1.0f,0.0f,0.6f); \
    glBegin(GL_LINES); \
        glVertex3f(0,0,0); \
        glVertex3f(GL_tE,0,0); \
        glVertex3f(0,0,0); \
        glVertex3f(0,GL_tE,0); \
        glVertex3f(0,0,0); \
        glVertex3f(0,0,GL_tE); \
        \
        glVertex3f(GL_tE,0,GL_tE); \
        glVertex3f(0,0,GL_tE); \
        glVertex3f(GL_tE,0,GL_tE); \
        glVertex3f(GL_tE,GL_tE,GL_tE); \
        glVertex3f(GL_tE,0,GL_tE); \
        glVertex3f(GL_tE,0,0); \
        \
        glVertex3f(0,GL_tE,GL_tE); \
        glVertex3f(0,GL_tE,0); \
        glVertex3f(0,GL_tE,GL_tE); \
        glVertex3f(GL_tE,GL_tE,GL_tE); \
        glVertex3f(0,GL_tE,GL_tE); \
        glVertex3f(0,0,GL_tE); \
        \
        glVertex3f(GL_tE,GL_tE,0); \
        glVertex3f(0,GL_tE,0); \
        glVertex3f(GL_tE,GL_tE,0); \
        glVertex3f(GL_tE,GL_tE,GL_tE); \
        glVertex3f(GL_tE,GL_tE,0); \
        glVertex3f(GL_tE,0,0); \
    glEnd();

/**
 * @brief Construcción de las paredes de un cubo usando GLUT.
 * @pre Definición de la dimensión en una variable llamada GL_tE. Ejemplo: const float GL_tE=tE/10.0f;
 */
#define GL_PAREDCUBO \
    glColor4f(0.0f,0.0f,1.0f,0.05f); \
    glBegin(GL_POLYGON); \
        glVertex3f(0,0,0); \
        glVertex3f(0,GL_tE,0); \
        glVertex3f(0,GL_tE,GL_tE); \
        glVertex3f(0,0,GL_tE); \
        \
        glVertex3f(0,0,0); \
        glVertex3f(GL_tE,0,0); \
        glVertex3f(GL_tE,0,GL_tE); \
        glVertex3f(0,0,GL_tE); \
        \
        glVertex3f(0,0,0); \
        glVertex3f(0,GL_tE,0); \
        glVertex3f(GL_tE,GL_tE,0); \
        glVertex3f(GL_tE,0,0); \
        \
    glEnd(); \
    glBegin(GL_POLYGON); \
        glVertex3f(GL_tE,GL_tE,GL_tE); \
        glVertex3f(0,GL_tE,GL_tE); \
        glVertex3f(0,0,GL_tE); \
        glVertex3f(GL_tE,0,GL_tE); \
        \
        glVertex3f(GL_tE,GL_tE,GL_tE); \
        glVertex3f(0,GL_tE,GL_tE); \
        glVertex3f(0,GL_tE,0); \
        glVertex3i(GL_tE,GL_tE,0); \
        \
        glVertex3f(GL_tE,GL_tE,GL_tE); \
        glVertex3f(GL_tE,GL_tE,0); \
        glVertex3f(GL_tE,0,0); \
        glVertex3f(GL_tE,0,GL_tE); \
        \
    glEnd();

#endif	/* UTIL_H */

