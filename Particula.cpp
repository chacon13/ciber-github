/* 
 * @author José Ángel Pastrana Padilla
 * @email japp0005@red.ujaen.es
 */

#include "Particula.h"

Particula::Particula(const unsigned int _x, const unsigned int _y, const unsigned int _z, const unsigned int _masa):x(_x),y(_y),z(_z),masa(_masa) {
}

Particula::Particula(const Particula& orig) {
    x=orig.x, y=orig.y, z=orig.z;
    masa=orig.masa;
}

Particula::~Particula() {
}

unsigned int Particula::getMasa() const {
    return masa;
}

void Particula::aumentaMasa(const unsigned int _masa) {
    masa+=_masa;
}

void Particula::actualizaPosicion(const unsigned int _x, const unsigned int _y, const unsigned int _z) {
    x=_x, y=_y, z=_z;
}

unsigned int Particula::getZ() const {
    return z;
}

unsigned int Particula::getY() const {
    return y;
}

unsigned int Particula::getX() const {
    return x;
}
