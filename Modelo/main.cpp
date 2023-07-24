#include "Modelo/Partida.h"
#include <iostream>

int main() {
    // Crea una partida con los nombres de los jugadores
    Partida partida("NombreJugador1", "NombreJugador2");

    // Lógica del juego: ejecuta las rondas hasta que la partida haya terminado
    while (!partida.haTerminado()) {
        partida.jugarRonda();
    }

    // Obtén el ganador y muestra el resultado
    const Jugador* ganador = partida.obtenerGanador();
    if (ganador) {
        std::cout << "El ganador es: " << ganador->getNombre() << std::endl;
    }
    else {
        std::cout << "No hay ganador." << std::endl;
    }

    return 0;
}
