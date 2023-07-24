#include <iostream>
#include "carta.h"
#include "mazo.h"
#include "jugador.h"

void mostrarCartasGanadas(const std::vector<Carta>& cartasGanadas) {
    for (const auto& carta : cartasGanadas) {
        std::cout << carta.tipoToString() << carta.colorToString() << carta.getNumero() << ", ";
    }
    std::cout << "\n";
}

int main() {
    // Crear el mazo y mezclar las cartas
    Mazo mazo;
    mazo.generarMazo();
    std::cout << "El mazo se ha generado y mezclado.\n";

    // Crear los jugadores
    Jugador jugador1("Jugador 1", mazo.obtenerMazoOriginal());
    Jugador jugador2("Jugador 2", mazo.obtenerMazoOriginal());

    jugador1.obtenerMazoMezclado();
    jugador2.obtenerMazoMezclado();
    jugador1.generarMano();
    jugador2.generarMano();
    // Mostrar mazos mezclados de cada jugador
    std::cout << "\nMazo de " << jugador1.obtenerNombre() << ":\n";
    jugador1.mostrarMano();

    std::cout << "\nMazo de " << jugador2.obtenerNombre() << ":\n";
    jugador2.mostrarMano();

    // Iniciar el juego
    int ronda = 1;
    while (ronda <= 5) {
        std::cout << "\n=== RONDA " << ronda << " ===\n";
        std::cout << "Turno de " << jugador1.obtenerNombre() << ":\n";
        Carta cartaJugador1 = jugador1.elegirCarta();

        std::cout << "Turno de " << jugador2.obtenerNombre() << ":\n";
        Carta cartaJugador2 = jugador2.elegirCarta();

        int resultado = jugador1.enfrentarCartas(jugador2, cartaJugador1, cartaJugador2);

        if (resultado == 1) {
            jugador1.mostrarGanadorRonda(jugador2, cartaJugador1, cartaJugador2);
        }
        else if (resultado == -1) {
            jugador2.mostrarGanadorRonda(jugador1, cartaJugador2, cartaJugador1);
        }
        else {
            std::cout << "Empate en la ronda.\n";
        }

        ronda++;
    }

    // Determinar el ganador de la partida
    const std::string& perdedorPartida = (jugador1.esGanadorPartida()) ? jugador1.obtenerNombre() : jugador2.obtenerNombre();
    const std::string& ganadorPartida = (perdedorPartida == jugador1.obtenerNombre()) ? jugador2.obtenerNombre() : jugador1.obtenerNombre();
    
    std::cout << "\n=== FIN DE LA PARTIDA ===\n";
    std::cout << "El perdedor de la partida es: " << ganadorPartida << "\n";
    std::cout << "Cartas ganadas por " << ganadorPartida << ":\n";
    mostrarCartasGanadas((ganadorPartida == jugador1.obtenerNombre()) ? jugador1.obtenerCartasGanadas() : jugador2.obtenerCartasGanadas());

    std::cout << "El ganador de la partida es: " << perdedorPartida << "\n";
    std::cout << "Cartas ganadas por " << perdedorPartida << ":\n";
    mostrarCartasGanadas((perdedorPartida == jugador1.obtenerNombre()) ? jugador1.obtenerCartasGanadas() : jugador2.obtenerCartasGanadas());
    
    

    
    // Actualizar puntuaciones
    jugador1.actualizarPuntuacionPartida();
    jugador2.actualizarPuntuacionPartida();

    // Exportar puntuaciones al archivo
    jugador1.exportarPuntuacion();
    jugador2.exportarPuntuacion();

    return 0;
}
