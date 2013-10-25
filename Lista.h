/* 
 * @file   Lista.h
 * @title  Implementación de lista doblemente enlazada como estructura de datos para C++
 * @author José Ángel Pastrana Padilla
 * @email  japp0005@red.ujaen.es
 */

#ifndef LISTA_H
#define	LISTA_H

#include "IteradorInvalido.h"

/**
 * @brief Estructura de datos. Lista doblemente enlazada.
 */
template<typename T>
class Lista {
private:
    class Nodo; /* Predeclaración de clase anidada Nodo. */
    Nodo* cabecera, /**< Nodo cabecera de la lista. */
        * cola; /**< Nodo cola de la lista. */
    unsigned int nL; /**< Número de elementos en la lista. */
    
public:
    class Iterador; /* Predeclaración de la clase anidada Iterador. */
    Lista():cabecera(0),cola(0),nL(0) {}; /**< Constructor por defecto. La lista está vacía. */
    Lista(const Lista& orig); /**< Constructor por copia. Los elementos de la lista original serán duplicados en la lista construída. */
    virtual ~Lista(); /**< Destructor de la lista. */
    
    /**
     * @brief Operador de asignación.
     * @param orig Lista original.
     * @post Modifica los miembros cabecera y cola. Sobreescribe la lista actual con los elementos procedentes de la lista dada por parámetro.
     * @return La propia lista, ya modificada.
     */
    Lista& operator=(const Lista& orig);
    
    const unsigned int& tam() const; /**< Cantidad de elementos en la lista */
    
    /**
     * @brief Insertar un elemento en la lista empleando un iterador.
     * @param it Iterador de la lista.
     * @param dato Elemento a añadir.
     * @post En determinados casos, modifica los miembros cabecera y dato. Modifica iterador apuntando al dato insertado.
     * @throw Excepción IteradorInvalido, si no se puede introducir un elemento con el iterador dado.
     * @return Dato introducido.
     */
    T& insertar(Iterador& it, const T& dato) throw (IteradorInvalido);
    
    /**
     * @brief Insertar un elemento al principio de la lista.
     * @param dato Elemento a añadir.
     * @post Modifica el miembro cabecera y en determinados casos, cola.
     * @return Dato introducido.
     */
    T& insertarIni(const T& dato);
    
    /**
     * @brief Insertar un elemento al final de la lista.
     * @param dato Elemento a añadir.
     * @post Modifica el miembro cola y en determinados casos, cabecera.
     * @return Dato introducido.
     */
    T& insertarFin(const T& dato);
    
    /**
     * @brief Borrar un elemento en la lista empleando un iterador.
     * @param it Iterador de la lista.
     * @param dato Elemento a añadir.
     * @post En determinados casos, modifica los miembros cabecera y dato. Modifica iterador.
     * @throw Excepción IteradorInvalido, si no se puede borrar un elemento con el iterador dado.
     */
    void borrar(Iterador& it) throw (IteradorInvalido);
    
    /**
     * @brief Borrar un elemento del principio de la lista.
     * @post Modifica el miembro cabecera y en determinados casos, cola.
     */
    void borrarIni();
    
    /**
     * @brief Borrar un elemento del final de la lista.
     * @post Modifica el miembro cola y en determinados casos, cabecera.
     */
    void borrarFin();

    Iterador iteradorIni() { return Iterador(cabecera); }; /**<  Iterador de lista, iniciado desde el primer elemento de la lista. */
    Iterador iteradorFin() { return Iterador(cola); }; /**<  Iterador de lista, iniciado desde el último elemento de la lista. */
};

/**
 * @brief Composición de lista. Nodo.
 */
template<typename T>
class Lista<T>::Nodo {
    friend class Lista; /* Lista puede acceder a los miembros privados de Nodo. */
private:
    T dato; /**< Dato en particular que almacena un nodo. */
    Nodo* anterior; /**< Nodo precedente a éste. */
    Nodo* siguiente; /**< Nodo posterior a éste. */
public:
    Nodo(const T& _dato, Nodo* _anterior=0, Nodo* _siguiente=0):dato(_dato),anterior(_anterior),siguiente(_siguiente) {}; /**< Constructor por defecto de Nodo. */
    virtual ~Nodo() {}; /**< Destructor de Nodo. */
}; 

/**
 * @brief Consulta, acceso y modificación a los datos de una lista. Iterador.
 * @throw Emplea la excepción IteradorInvalido en sus métodos.
 */
template<typename T>
class Lista<T>::Iterador {
    friend class Lista; /* Lista puede acceder a los miembros privados de Iterador. */
private:
    Nodo* actual; /**< Nodo perteneciente a la lista que se desea trabajar. */
public:
    Iterador(Nodo* _nodo=0):actual(_nodo) {}; /**< Constructor por defector de Iterador. */
    Iterador(const Iterador& orig):actual(orig.actual) {}; /**< Constructor por copia de Iterador. */
    Iterador& operator=(const Iterador& orig) { if (this!=&orig) { actual=orig.actual; } return *this; }; /**< Operador de asignación. El iterador adquiere el nodo con el que trabaja el iterador dado por parámetro. */
    virtual ~Iterador() {}; /**< Destructor de Iterador. */
    
    /**
     * @brief Mover el iterador al siguiente elemento de la lista.
     * @post Modifica miembro actual.
     * @throw Excepción IteradorInvalido, si este iterador no puede completar la operación.
     */
    void anterior() throw (IteradorInvalido) { if (actual) { actual=actual->anterior; } else { throw IteradorInvalido(); } };
    
    /**
     * @brief Mover el iterador al anterior elemento de la lista.
     * @post Modifica miembro actual.
     * @throw Excepción IteradorInvalido, si este iterador no puede completar la operación.
     */
    void siguiente() throw (IteradorInvalido) { if (actual) { actual=actual->siguiente; } else { throw IteradorInvalido(); } }; 
    
    /**
     * @brief Acceder al dato que apunta el iterador.
     * @throw Excepción IteradorInvalido, si no se está apuntando a ningún nodo actualmente.
     * @return Dato contenido en el nodo que apunta el iterador en estos momentos. 
     */
    T& dato() { if (actual) { return actual->dato; } else { throw IteradorInvalido(); } };
    
    bool operator==(const Iterador& it) { return actual==it.actual; }; /**< Compara si dos iteradores apuntan al mismo nodo. */
    bool operator!=(const Iterador& it) { return actual!=it.actual; }; /**< Compara si dos iteradores apuntan a un nodo distinto. */
    bool fin() { return actual==0; }; /**< Indica si el iterador ha llegado a su final o principio. */
};

template<typename T>
Lista<T>::Lista(const Lista& orig):cabecera(0),cola(0),nL(0) {
    operator=(orig);
}

template<typename T>
Lista<T>::~Lista() {
    if (cabecera) {
        while(cabecera->siguiente) {
            Nodo* borrame=cabecera;
            cabecera=cabecera->siguiente;
            delete borrame;
        }
        delete cabecera;
    }
}

template<typename T>
Lista<T>& Lista<T>::operator=(const Lista& orig) {
    if (this!=&orig) {
        while(cabecera) {
            borrarIni();
        }
        Nodo* anadir=orig.cabecera;
        while(anadir) {
            insertarFin(anadir->dato);
            anadir=anadir->siguiente;
        }
    }
    return *this;
}

template<typename T>
const unsigned int& Lista<T>::tam() const {
    return nL;
}

template<typename T>
T& Lista<T>::insertar(Iterador& it, const T& dato) throw (IteradorInvalido) {
    if (it.actual) {
        Nodo* nuevo=new Nodo(dato,it.actual,it.actual->siguiente);
        if (it.actual->siguiente) {
            it.actual->siguiente->anterior=nuevo;
        } else {
            cola=nuevo;
        }
        it.actual->siguiente=nuevo;
        it.siguiente();
        ++nL;
        return it.actual->dato;
    } else {
        throw IteradorInvalido();
    }
}

template<typename T>
T& Lista<T>::insertarIni(const T& dato) {
    Nodo* nuevo=new Nodo(dato,0,cabecera);
    if (!cola) {
        cola=nuevo;
    }
    if (cabecera) {
        cabecera->anterior=nuevo;
    }
    cabecera=nuevo;
    ++nL;
    return cabecera->dato;
}

template<typename T>
T& Lista<T>::insertarFin(const T& dato) {
    Nodo* nuevo=new Nodo(dato,cola,0);
    if (!cabecera) {
        cabecera=nuevo;
    }
    if (cola) {
        cola->siguiente=nuevo;
    }
    cola=nuevo;
    ++nL;
    return cola->dato;
}

template<typename T>
void Lista<T>::borrar(Iterador& it) throw (IteradorInvalido) {
    if (it.actual) {
        if (it.actual->anterior) {
            it.actual->anterior->siguiente=it.actual->siguiente;
        } else {
            cabecera=it.actual->siguiente;
        }
        if (it.actual->siguiente) {
            it.actual->siguiente->anterior=it.actual->anterior;
        } else {
            cola=it.actual->anterior;
        }
        Nodo* borrame=it.actual;
        it.siguiente();
        --nL;
        delete borrame;
    } else {
        throw IteradorInvalido();
    }
}

template<typename T>
void Lista<T>::borrarIni() {
    if (cabecera) {
        Nodo* borrame=cabecera;
        cabecera=cabecera->siguiente;
        delete borrame;
        --nL;
    }
    if (cabecera) {
        cabecera->anterior=0;
    } else {
        cola=0;
    }
}

template<typename T>
void Lista<T>::borrarFin() {
    if (cola) {
        Nodo* borrame=cola;
        cola=cola->anterior;
        delete borrame;
        --nL;
    }
    if (cola) {
        cola->siguiente=0;
    } else {
        cabecera=0;
    }
}

#endif	/* LISTA_H */
