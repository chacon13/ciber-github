#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>

#include "VisualizadorParticulas.h"

using namespace std;

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