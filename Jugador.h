#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Carta.h"

class Jugador {
private:
    std::string nombre;
    int puntuacion;
    std::vector<Carta> cartasGanadas;
    int cinturonesGanados;
    int progresoBarra;

public:
    Jugador(const std::string& nombre);

    std::string getNombre() const;
    int getPuntuacion() const;
    int getCinturonesGanados() const;
    int getProgresoBarra() const;
    std::vector<Carta> getCartasGanadas() const;

    void agregarCartaGanada(const Carta& carta);
    int contarCartasGanadas() const;
    void reiniciarCartasGanadas();

    void incrementarPuntuacion(int puntos);

    void incrementarCinturones();

    void incrementarProgresoBarra();
    void reiniciarProgresoBarra();
};

#endif // JUGADOR_H
