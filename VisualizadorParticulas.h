/* 
 * @file   VisualizadorParticulas.h
 * @title  Representa gráficamente un mundo simulado de partículas
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

/**
 * @brief Clase principal del simulador de partículas.
 */
class VisualizadorParticulas {
private:
    static VisualizadorParticulas* instancia;
    SimuladorParticulas simuladorParticulas; /**< Simulador de partículas. */
    int width, height; /**< Dimensiones del viewport. */
    int pasos; /**< Número de pasos de simulación. */
    int frames; /**< Número de frames dibujados desde la última actualización de fps. */
    int tiempoAnterior; /**< Tiempo de la último actualización de fps. */
    int fps; /**< Número de fps. */
    double rotate_y, rotate_x; /**< Rotación de la simulación. */

    VisualizadorParticulas(int totalPasos = NUM_PASOS_SIMULACION); /**< Iniciación del simulador. */
    void actualizarParticulas(); /**< Actualización de partículas. */
    static void dibujarParticulas(); /**< Dibujado de partículas. */
    static void escribirTexto(GLfloat x, GLfloat y, const char *text); /**< Escribir un texto usando OpenGL. */
    void calcularFPS(); /**< Calculo de FPS actuales. */
    static void redimensionarVentana(int width, int height); /**< Actualizar visor opengl al redimensionar ventana. */
    static void procesarRaton(int button, int state, int x, int y); /**< Procesar eventos de ratón. */
    static void procesarMovimientoRaton(int x, int y); /**< Procesar movimiento de ratón. */
    static void procesarTeclado(unsigned char key, int x, int y); /**< Procesar acciones del teclado. */
    static void espera(); /**< Bucle principal de actualización y repintado. */

public:
    void iniciarGL(); /**< Iniciar openGL y configurar GLUT. */
    void ejecutar(); /**< Arrancar bucle de simulación. */
    void finalizar(); /**< Liberar memoria. */
    static VisualizadorParticulas *leerInstancia(); /**< Obtener instancia del simulador de partículas. */
    virtual ~VisualizadorParticulas(); /**< Destructor del visualizador. */
};

#endif	/* VISUALIZADORPARTICULAS_H */
