#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <sstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "tb.h"
#include "simparticulas.h"

using namespace std;

#define SIMULACION_PARADA -1
#define SIMULACION_CONTINUA -2

#define NUM_PASOS_SIMULACION 1000

/** Clase principal del simulador de partículas */
class VisualizadorParticulas {
    
    static VisualizadorParticulas *instancia;
    
    /** Simulador de partículas */
    SimuladorParticulas simuladorParticulas;
    
    /** Dimensiones del viewport */
    int width, height;
    
    /** Número de pasos de simulación */
    int pasos;
    /** Número de frames dibujados desde la última actualización de fps */
    int frames;
    /** Tiempo de la último actualización de fps */
    int tiempoAnterior;
    /** Número de fps. */
    int fps;
    
    /** Iniciación del simulador */
    VisualizadorParticulas(int totalPasos = NUM_PASOS_SIMULACION): simuladorParticulas() {
        this->pasos = totalPasos;
        frames = fps = -1;
        tiempoAnterior = glutGet(GLUT_ELAPSED_TIME);
    }
    
    /** Actualización de partículas */
    void actualizarParticulas() {
        // Si quedan pasos de simulación, actualizar.
        if (pasos > 0 || pasos == SIMULACION_CONTINUA) {
            simuladorParticulas.actualizar();
            
            if (pasos != SIMULACION_CONTINUA)
                --pasos;
        }
        // Si ha finalizado la simulación, imprimir estadísticas
        else if (pasos == 0) {
            simuladorParticulas.imprimirEstadisticas();
            pasos = SIMULACION_PARADA;
        }
    }
    
    /** Dibujado de partículas */
    static void dibujarParticulas() {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glPushMatrix();
        
        tbMatrix();
        
        glTranslatef(-5.0f, -5.0f, -5.0f);
        
        glColor4f(1.0f, 0.0f, 0.0f, 0.3f);
        list<Particula *>& particulas = instancia->simuladorParticulas.listaParticulas();
        list<Particula *>::iterator p = particulas.begin();
        while (p != particulas.end()) {
            glPointSize((*p)->getMasa());
            glBegin(GL_POINTS);
            glVertex3f((*p)->getX() / 10.0f, (*p)->getY() / 10.0f, (*p)->getZ() / 10.0f);
            glEnd();
            
            ++p;
        }
        
        glPopMatrix();
        
        if (instancia->fps >= 0) {
            stringstream ss;
            ss << instancia->fps << " fps.";
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            escribirTexto(20.0f, instancia->height - 20.0f, ss.str().c_str());
        }
        
        glutSwapBuffers();
    }
    
    /** Escribir un texto usando OpenGL */
    static void escribirTexto(GLfloat x, GLfloat y, const char *text)
    {
        const char *p;
    
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, instancia->width, 0, instancia->height);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        glRasterPos2f(x, y);
        for (p=text; *p != '\0'; p++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *p);
        }
        glPopMatrix();
     
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        
        glMatrixMode(GL_MODELVIEW);        
    }
    
    void calcularFPS()
    {
        //  Incrementar contador de frames
        frames++;
        
        // Obtener tiempo actual
        int tiempoActual = glutGet(GLUT_ELAPSED_TIME);
        
        // Calcular el tiempo pasado desde el último cálculo
        int intervaloTiempo = tiempoActual - tiempoAnterior;
        
        // Si ha pasado más de un segundo, actualizar
        if(intervaloTiempo > 1000) {
            //  Calcular los fps
            fps = frames / (intervaloTiempo / 1000.0f);
            
            // Resetar tiempo y contador de frames
            tiempoAnterior = tiempoActual;
            frames = 0;
        }
    }
    
    /** Actualizar visor opengl al redimensionar ventana */
    static void redimensionarVentana(int width, int height) {
        instancia->width = width;
        instancia->height = height;
        
        // Trackball update
        tbReshape(width, height);
                
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 50.0);        
        glViewport(0, 0, width, height);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -15.0f);
        
        glutPostRedisplay();
    }

    /** Procesar eventos de ratón */
    static void procesarRaton(int button, int state, int x, int y) {
        tbMouse(button, state, x, y);
        glutPostRedisplay();
    }

    /** Procesar movimiento de ratón */
    static void procesarMovimientoRaton(int x, int y) {
        tbMotion(x, y);
        glutPostRedisplay();
    }

    static void procesarTeclado(unsigned char key, int x, int y)
    {
        switch (key) {
            case 27:
            case 'Q':
            case 'q':
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
        }
    }
    
    /** Bucle principal de actualización y repintado */
    static void espera() {
        instancia->actualizarParticulas();
        instancia->calcularFPS();
        glutPostRedisplay();
    }
    
public:
    /** Iniciar openGL y configurar GLUT */
    void iniciarGL() {
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        
        // Trackball
        tbInit(GLUT_LEFT_BUTTON);
        tbAnimate(GL_TRUE);
        
        glutReshapeFunc(VisualizadorParticulas::redimensionarVentana);
        glutDisplayFunc(VisualizadorParticulas::dibujarParticulas);
        glutKeyboardFunc(VisualizadorParticulas::procesarTeclado);
        glutMouseFunc(VisualizadorParticulas::procesarRaton);
        glutMotionFunc(VisualizadorParticulas::procesarMovimientoRaton);
        
        glutIdleFunc(VisualizadorParticulas::espera);
    }
    
    /** Arrancar bucle de simulación */
    void ejecutar() {
        glutMainLoop();
    }
    
    /** Liberar memoria */
    void finalizar() {
        delete VisualizadorParticulas::instancia;
        VisualizadorParticulas::instancia = 0;
    }
    
    /** Obtener instancia del simulador de partículas */
    static VisualizadorParticulas *leerInstancia() {
        if (instancia == 0) {
            instancia = new VisualizadorParticulas();
        }
        
        return instancia;
    }
};

VisualizadorParticulas *VisualizadorParticulas::instancia = 0;

int main(int argc, char **argv)
{
    // Iniciar GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Partículas");
    
    // Arrancar simulador
    VisualizadorParticulas::leerInstancia()->iniciarGL();
    VisualizadorParticulas::leerInstancia()->ejecutar();
    VisualizadorParticulas::leerInstancia()->finalizar();
    
    return 0;
}