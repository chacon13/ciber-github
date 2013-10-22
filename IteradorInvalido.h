/* 
 * @author José Ángel Pastrana Padilla
 * @email japp0005@red.ujaen.es
 */

#ifndef ITERADORINVALIDO_H
#define	ITERADORINVALIDO_H

#include <exception>

class IteradorInvalido: public std::exception {
public:
    virtual const char* what() const throw() {
        return "No se puede realizar la operación con este iterador.";
    }
};

#endif	/* ITERADORINVALIDO_H */

