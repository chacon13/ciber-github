/* 
 * @file   VisualizadorParticulas.cpp
 * @title  Representa gráficamente un mundo simulado de partículas
 * @author Antonio Jesús Rueda Ruiz
 * @author José Ángel Pastrana Padilla
 */

#include "VisualizadorParticulas.h"

VisualizadorParticulas* VisualizadorParticulas::instancia = 0;

VisualizadorParticulas::VisualizadorParticulas(int totalPasos): simuladorParticulas(),rotate_x(0),rotate_y(0) {
    this->pasos = totalPasos;
    frames = fps = -1;
    tiempoAnterior = glutGet(GLUT_ELAPSED_TIME);
}

VisualizadorParticulas::~VisualizadorParticulas() {};

void VisualizadorParticulas::actualizarParticulas() {
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

void VisualizadorParticulas::dibujarParticulas() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    tbMatrix();
    
    const float GL_tE=tE/10.0f; /*< Cálculo de las dimensiones a la hora de pintar el cubo. */
    const float GL_xyz=GL_tE/-2.0f; /*< Cálculo del centro del eje del cubo */
    glRotatef( instancia->rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( instancia->rotate_y, 0.0, 1.0, 0.0 );
    glTranslatef(GL_xyz,GL_xyz,GL_xyz); //glTranslatef(-5.0f, -5.0f, -5.0f);
    
    GL_ARISTACUBO
    GL_PAREDCUBO
    
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f); //glColor4f(1.0f, 0.0f, 0.0f, 0.3f);
    Lista<Particula*>& particulas = instancia->simuladorParticulas.listaParticulas();
    Lista<Particula*>::Iterador p = particulas.iteradorIni();
    
    while (!p.fin()) {
        glPointSize(p.dato()->getMasa());
        glBegin(GL_POINTS);
        glVertex3f(p.dato()->getX() / 10.0f, p.dato()->getY() / 10.0f, p.dato()->getZ() / 10.0f);
        glEnd();
        p.siguiente();
    }

    glPopMatrix();

    if (instancia->fps >= 0) {
        stringstream ss;
        ss << instancia->fps << " fps.";
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        escribirTexto(20.0f, instancia->height - 20.0f, ss.str().c_str());
    }

    glutSwapBuffers();
    
    espera(); // Remember: Esto no es competencia de DisplayFunc, en sus tiempos lo administraba Idle. :P
}

void VisualizadorParticulas::escribirTexto(GLfloat x, GLfloat y, const char *text)
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

void VisualizadorParticulas::calcularFPS()
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

void VisualizadorParticulas::redimensionarVentana(int width, int height) {
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

void VisualizadorParticulas::procesarRaton(int button, int state, int x, int y) {
    tbMouse(button, state, x, y);
    glutPostRedisplay();
}

void VisualizadorParticulas::procesarMovimientoRaton(int x, int y) {
    tbMotion(x, y);
    glutPostRedisplay();
}

void VisualizadorParticulas::procesarTeclado(unsigned char key, int x, int y)
{
    switch (key) {
        case 'W': case 'w': instancia->rotate_x += 3; break;
        case 'A': case 'a': instancia->rotate_y -= 3; break;
        case 'S': case 's': instancia->rotate_x -= 3; break;
        case 'D': case 'd': instancia->rotate_y += 3; break;
        case 27:
        case 'Q':
        case 'q':
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
}

void VisualizadorParticulas::espera() {
    instancia->actualizarParticulas();
    instancia->calcularFPS();
    glutPostRedisplay();
}

void VisualizadorParticulas::iniciarGL() {
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
    //glutIdleFunc(VisualizadorParticulas::espera); /**< DisplayFunc se encargará de todo ahora :D */
}

void VisualizadorParticulas::ejecutar() {
    glutMainLoop();
}

void VisualizadorParticulas::finalizar() {
    delete VisualizadorParticulas::instancia;
    VisualizadorParticulas::instancia = 0;
}

VisualizadorParticulas* VisualizadorParticulas::leerInstancia() {
    if (instancia == 0) {
        instancia = new VisualizadorParticulas();
    }

    return instancia;
}
