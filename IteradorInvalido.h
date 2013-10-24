/* 
 * @file   IteradorInvalido.h
 * @title  Excepción para controlar el mal uso de un iterador 
 * @author José Ángel Pastrana Padilla
 * @email  japp0005@red.ujaen.es
 */

#ifndef ITERADORINVALIDO_H
#define	ITERADORINVALIDO_H

#include <exception>

/**
 * @brief Excepción de uso de un iterador incorrecto.
 */
class IteradorInvalido: public std::exception {
public:
    /**
     * @brief Mensaje informativo sobre la excepción producida.
     */
    virtual const char* what() const throw() {
        return "No se puede realizar la operación con este iterador.";
    }
};

#endif	/* ITERADORINVALIDO_H */

