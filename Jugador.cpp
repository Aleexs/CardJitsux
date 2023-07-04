#include "Jugador.h"

Jugador::Jugador(const std::string& nombre) : nombre(nombre), puntuacion(0), cinturonesGanados(0), progresoBarra(2) {}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getPuntuacion() const {
    return puntuacion;
}

int Jugador::getCinturonesGanados() const {
    return cinturonesGanados;
}

int Jugador::getProgresoBarra() const {
    return progresoBarra;
}

std::vector<Carta> Jugador::getCartasGanadas() const {
    return cartasGanadas;
}

void Jugador::agregarCartaGanada(const Carta& carta) {
    cartasGanadas.push_back(carta);
}

int Jugador::contarCartasGanadas() const {
    return cartasGanadas.size();
}

void Jugador::reiniciarCartasGanadas() {
    cartasGanadas.clear();
}

void Jugador::incrementarPuntuacion(int puntos) {
    puntuacion += puntos;
}

void Jugador::incrementarCinturones() {
    cinturonesGanados++;
}

void Jugador::incrementarProgresoBarra() {
    progresoBarra++;
}

void Jugador::reiniciarProgresoBarra() {
    progresoBarra = 2;
}
