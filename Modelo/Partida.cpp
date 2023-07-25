// partida.cpp
#include "partida.h"


Partida::Partida(const std::string& nombreJugador1, const std::string& nombreJugador2)
    : jugador1_(nombreJugador1, Mazo()), jugador2_(nombreJugador2, Mazo()), ronda_(1) {
    jugador1_.mezclarCartas();
    jugador2_.mezclarCartas();

    jugador1_.generarMano();
    jugador2_.generarMano();
}

void Partida::iniciarPartida() {
    bool partidaTerminada = false;
    

    while (!partidaTerminada) {
        std::cout << "\n----- Ronda " << ronda_ << " -----\n";
        
        Carta cartaJugador1 = jugador1_.obtenerCartaElegida();
        Carta cartaJugador2 = jugador2_.obtenerCartaElegida();

        
        if (jugador1_.verificarGanadorPartida()) {
            partidaTerminada = true;
        }
        else if (jugador2_.verificarGanadorPartida()) {
            partidaTerminada = true;
        }

        jugador1_.enfrentarCartas(cartaJugador1, cartaJugador2, jugador2_);

        ronda_++;
    }

    std::cout << "\n----- Resultado de la ronda -----\n";
    if (jugador1_.verificarGanadorPartida()) {
        std::cout << jugador1_.getNombre() << " ha ganado la partida!\n";
    }
    else if (jugador2_.verificarGanadorPartida()) {
        std::cout << jugador2_.getNombre() << " ha ganado la partida!\n";
    }

    jugador1_.mostrarCartasGanadoras();
    jugador2_.mostrarCartasGanadoras();
}
