// partida.h
#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugador.h"
#include "mazo.h"

class Partida {
public:
    Partida() : jugador1_("Jugador1", Mazo()), jugador2_("Jugador2", Mazo()), ronda_(1) {} // Constructor predeterminado con inicializaci�n de los jugadores
    // sin esto no se logra ejecutar partida y modelo de la forma correcta. Verificar constructor predeterminado

    Partida(const std::string& nombreJugador1, const std::string& nombreJugador2);

    void iniciarPartida();

private:
    Jugador jugador1_;
    Jugador jugador2_;
    Mazo mazo;
    
    int ronda_ = 1;
};

#endif // PARTIDA_H
