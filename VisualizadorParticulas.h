/* 
 * @file   VisualizadorParticulas.h
 * @author Antonio Jesús Rueda Ruiz
 * @author José Ángel Pastrana Padilla
 */

#ifndef VISUALIZADORPARTICULAS_H
#define	VISUALIZADORPARTICULAS_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "config.h"
#include "SimuladorParticulas.h"
#include "tb.h"

/** Clase principal del simulador de partículas */
class VisualizadorParticulas {
private:
    static VisualizadorParticulas* instancia;
    SimuladorParticulas simuladorParticulas; /**< Simulador de partículas */
    int width, height; /**< Dimensiones del viewport */
    int pasos; /**< Número de pasos de simulación */
    int frames; /**< Número de frames dibujados desde la última actualización de fps */
    int tiempoAnterior; /**< Tiempo de la último actualización de fps */
    int fps; /**< Número de fps. */

    VisualizadorParticulas(int totalPasos = NUM_PASOS_SIMULACION);
    void actualizarParticulas();
    static void dibujarParticulas();
    static void escribirTexto(GLfloat x, GLfloat y, const char *text);
    void calcularFPS();
    static void redimensionarVentana(int width, int height);
    static void procesarRaton(int button, int state, int x, int y);
    static void procesarMovimientoRaton(int x, int y);
    static void procesarTeclado(unsigned char key, int x, int y);
    static void espera();

public:
    void iniciarGL();
    void ejecutar();
    void finalizar();
    static VisualizadorParticulas *leerInstancia();
};

#endif	/* VISUALIZADORPARTICULAS_H */
