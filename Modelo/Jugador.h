// jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include "mazo.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

class Jugador {
public:
    Jugador(const std::string& nombre, const Mazo& mazoOriginal);
    std::string getNombre() const;

    void mezclarCartas();

    void mostrarMazoOriginal() const;
    void mostrarMazoAleatorio() const;
    std::vector<Carta> obtenerMazoAleatorio() const;

    void generarMano();
    void mostrarMano() const;
    std::vector<Carta> obtenerMano() const;

    Carta elegirCarta();

    Carta obtenerCartaElegida();
    void enfrentarCartas(const Carta& cartaJugador1, const Carta& cartaJugador2, Jugador& jugadorContrario);
    void mostrarEstadoRondaContrario(const Carta& cartaGanadoraContrario);

    bool verificarGanadorPartida();

    
    const std::vector<Carta>& obtenerCartasGanadoras() const;
    void mostrarCartasGanadoras() const;
private:
    std::string nombre_;
    std::vector<Carta> mazoOriginal_;
    std::vector<Carta> mazoAleatorio_;
        
    std::vector<Carta> mano_;

    std::vector<Carta> cartasGanadoras_;
};

#endif // JUGADOR_H
