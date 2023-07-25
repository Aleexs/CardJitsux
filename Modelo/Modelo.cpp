// modelo.cpp
#include "modelo.h"

Modelo::Modelo() {}

void Modelo::iniciarJuego() {
    std::string nombreJugador1;
    std::string nombreJugador2;

    std::cout << "Ingrese el nombre del Jugador 1: ";
    std::cin >> nombreJugador1;

    std::cout << "Ingrese el nombre del Jugador 2: ";
    std::cin >> nombreJugador2;

    partida_ = Partida(nombreJugador1, nombreJugador2);
    partida_.iniciarPartida();
}
