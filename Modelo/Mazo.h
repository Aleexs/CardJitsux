// mazo.h
#ifndef MAZO_H
#define MAZO_H

#include "carta.h"
#include <vector>

class Mazo {
public:
    Mazo();
    void generarMazo();
    
    void mostrarMazoOriginal() const;
    std::vector<Carta> obtenerMazoOriginal() const;

private:
    std::vector<Carta> mazoOriginal_;
    
};

#endif // MAZO_H

