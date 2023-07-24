// jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "mazo.h"
#include <vector>
#include <string>

class Jugador {
public:
    Jugador(const std::string& nombre, const std::vector<Carta>& mazoOriginal);
    Jugador(const Jugador& otroJugador);

    void generarMazoAleatorio();
    std::vector<Carta> obtenerMazoMezclado() const;
    void generarMano();
    Carta elegirCarta();
    Carta obtenerCartaElegida() const;
    int enfrentarCartas(Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2);

    const std::vector<Carta>& obtenerCartasGanadasPropias() const;
    std::string obtenerNombre() const;
    
    void mostrarMano() const;
    void mostrarCartasGanadasPropias() const;
    
    void guardarCartaGanada(const Carta& cartaGanada);
    void mostrarCartasGanadas() const;
private:
    std::string nombre_;
    std::vector<Carta> mazoOriginal_;
    std::vector<Carta> mazoMezclado_;
    std::vector<Carta> mano_;
    Carta cartaElegida_ = Carta(Carta::Tipo::DESCONOCIDO, Carta::Color::DESCONOCIDO, 0); // Valor predeterminado

    std::vector<Carta> cartasGanadasPropias_;

    void eliminarCartaDeMano(const Carta& carta);
    void guardarCartaGanadaPropia(const Carta& cartaGanada);

    std::vector<Carta> cartasGanadas_;
};

#endif // JUGADOR_H
