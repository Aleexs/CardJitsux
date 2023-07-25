// modelo.h
#ifndef MODELO_H
#define MODELO_H

#include "partida.h"

class Modelo {
public:
    Modelo();

    void iniciarJuego();

private:
    Partida partida_;
};

#endif // MODELO_H
