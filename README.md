# Compilación del proyecto en Netbeans

## Linux Ubuntu a partir de 11.04
0. ~~Puede ser que necesites previamente instalar algunas dependencias gráficas o de ligadura dinámica en el sistema:~~
 * sudo apt-get install mesa-common-dev
 * sudo apt-get install binutils-gold 
1. Instalación de freeglut:
 * sudo apt-get install freeglut3 freeglut3-dev freeglut3-dbg
2. Configuración de freeglut en Netbeans:
 1. File -> Project Properties
 2. Build -> Linker -> Compilation Line -> Additional Options
 3. Agrega:  __-lglut -lGLU -lGL__
3. Clean & Build. Y Run. :)

## Windows
0. ~~Prepara el compilador MinGW de 32 bits con MSYS.~~
1. Descarga esto: [GLUT para MinGW32](https://git.ujacraft.es/files/note/4/GLUT-MinGW-3.7.6-6.mp.zip)
2. Copia /GLUT/include/glut.h del zip en C:\MinGW\include\GL
3. Copia /GLUT/lib/libglut32.a del zip en C:\MinGW\lib
4. Copia /GLUT/glut32.dll del zip en SYSTEM32/SYSWOW64 dependiendo de la versión de Windows.
5. Al abrir el projecto en Netbeans, debes resolver los conflictos por el cambio de plataforma (*Resolve problems...* en la ventana emergente que aparece).
5. Configuración de GLUT en Netbeans:
 1. File -> Project Properties
 2. Build -> Linker -> Compilation Line -> Additional Options
 3. Agrega:  __-static -lglut32 -lopengl32 -lglu32__
6. Clean & Build. Y Run. Recuerda agregar la biblioteca glut32.dll en la ruta del ejecutable siempre que vayas a exportarlo en otro ordenador. :)
