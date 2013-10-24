/* 
 * @author José Ángel Pastrana Padilla
 * @email japp0005@red.ujaen.es
 */

#ifndef CONFIG_H
#define	CONFIG_H

/** Parámetros del profesor. */
#define SIMULACION_PARADA -1
#define SIMULACION_CONTINUA -2

/** Número de iteraciones que acometerá la aplicación. */
#define NUM_PASOS_SIMULACION 1000

/** Tamaño físico para el espacio. */
#define tE 100

/** Cantidad de partículas. */
#define tP 2

/** Realiza la simulación teniendo en cuenta que las partículas se desintegran en función de su masa. */
#define DESINTEGRAR false

/** Limpia el visualizador acabando con todas las partículas al finalizar la simulación. */
#define LIMPIARVISTA true

#endif	/* CONFIG_H */

