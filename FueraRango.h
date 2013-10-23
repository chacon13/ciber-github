/* 
 * @author José Ángel Pastrana Padilla
 * @email japp0005@red.ujaen.es
 */

#ifndef FUERARANGO_H
#define	FUERARANGO_H

#include <exception>
#include <sstream>

/**
 * @brief Excepción de acceso fuera del rango válido.
 */
class FueraRango: public std::exception {
private:
    const unsigned int  n, /**< Número de índices que controla la clase **/
                      * v,/**< Coordenadas en las cuales se produjo la excepción **/
                      * l; /**< Indica los límites físicos para los índices **/
    
public:
    FueraRango():exception(),n(0),v(0),l(0) {}; /**< Constructor por defecto */
    
    /**
     * @brief Constructor parametrizado.
     * @param _n Número de índices que se manejan.
     * @param _v Vector con las coordenadas que produjeron la excepción.
     * @param _l Opcional. Vector con los límites de los índices.
     */
    FueraRango(const unsigned int _n, const unsigned int* _v, const unsigned int* _l=0):n(_n),v(_v),l(_l) {};
    
    /**
     * @brief Mensaje informativo sobre la excepción producida.
     * @return Devuelve una cadena de texto especificando los datos de la excepción.
     */
    virtual const char* what() const throw() {
        if (n && v) {
            std::stringstream ss;
            ss << "Se introdujo una posición inválida " << '\n';
            for (int c=0; c<n; ++c) {
                ss << "[" << c << "]=>" << v[c];
                if (l) {
                    ss << ". Máximo: " << l[c];
                }
                ss << '\n';
            }
            return ss.str().c_str();
        } else {
            return "Se introdujo una posición inválida";
        }
    };
};

#endif	/* FUERARANGO_H */