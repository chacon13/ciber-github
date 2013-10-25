/* 
 * @file   config.h
 * @title  Configuración del comportamiento de la aplicación mediante macros de precompilador
 * @author José Ángel Pastrana Padilla
 * @email  japp0005@red.ujaen.es
 */

#ifndef CONFIG_H
#define	CONFIG_H

/** Parámetros del profesor. */
#define SIMULACION_PARADA -1
#define SIMULACION_CONTINUA -2

/** Número de iteraciones que acometerá la aplicación. */
#define NUM_PASOS_SIMULACION 1000

/** Tamaño físico para el espacio. */
#define tE 200

/** Cantidad de partículas. */
#define tP 1000

/** Realiza la simulación teniendo en cuenta que las partículas se desintegran en función de su masa. */
#define DESINTEGRAR false

#endif	/* CONFIG_H */

