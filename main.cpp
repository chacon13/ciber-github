/* 
 * @file   main.cpp
 * @title  Principal - Ejecución de la simulación empleando GLUT
 * @author Antonio Jesús Rueda Ruiz
 * @author José Ángel Pastrana Padilla
 */

#include "VisualizadorParticulas.h"

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