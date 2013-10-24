/* 
 * @author José Ángel Pastrana Padilla
 * @email japp0005@red.ujaen.es
 */

#ifndef PARTICULA_H
#define	PARTICULA_H

/**
 * @brief Partícula ubicada en un espacio tridimensional y con masa concreta.
 */
class Particula {
private:
    unsigned int x, y, z, /**< Posición dentro de la matriz. **/
                 masa;    /**< Masa de la partícula. **/
    
public:
    
    /**
     * @brief Constructor por defecto.
     * @param _x Posición de la partícula respecto al eje x.
     * @param _y Posición de la partícula respecto al eje y.
     * @param _z Posición de la partícula respecto al eje z.
     * @param _masa Masa de la partícula. Defecto: 1.
     */
    Particula(const unsigned int _x, const unsigned int _y, const unsigned int _z, const unsigned int _masa=1);
    
    /**
     * @brief Constructor por copia
     * @param orig Objeto de origen a copiar
     */
    Particula(const Particula& orig);
    
    virtual ~Particula(); /**< Destructor de la partícula. */
    
    /**
     * @brief Obtener la masa de la partícula.
     * @return Valor de la masa.
     */
    const unsigned int getMasa() const;
    
    /**
     * @brief Aumentar masa de la partícula.
     * @param _masa Variación a aplicar de la masa.
     */
    void aumentaMasa(const unsigned int _masa);
    
    /**
     * @brief Actualizar la posición de la partícula.
     * @param _x Nueva posición de la partícula respecto al eje x.
     * @param _y Nueva posición de la partícula respecto al eje y.
     * @param _z Nueva posición de la partícula respecto al eje z.
     */
    void actualizaPosicion(const unsigned int _x, const unsigned int _y, const unsigned int _z);
    
    const unsigned int getZ() const; /**< Observador del eje Z para la partícula. */
    const unsigned int getY() const; /**< Observador del eje Y para la partícula. */
    const unsigned int getX() const; /**< Observador del eje X para la partícula. */
};

#endif	/* PARTICULA_H */

