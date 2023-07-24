// jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "mazo.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Jugador {
public:
    Jugador(const std::string& nombre, const std::vector<Carta>& mazoOriginal, int puntuacion = 0);

    void importarPuntuacion();
    void exportarPuntuacion() const;
    int getPuntuacion() const;
    void actualizarPuntuacion(int puntos);

    std::vector<Carta> obtenerMazoMezclado() const;
    void generarMano();
    void mostrarMano() const;
    Carta elegirCarta();
    const Carta& obtenerCartaElegida() const;
    const std::string& obtenerNombre() const;

    int enfrentarCartas(Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2);

    const std::vector<Carta>& obtenerCartasGanadas() const;
    const std::vector<Carta>& obtenerCartasGanadasRonda() const;

    std::string obtenerGanadorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const;
    std::string obtenerPerdedorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const;
    void mostrarGanadorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const;
    void mostrarPerdedorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const;


    bool esGanadorPartida() const;
    const std::string& obtenerNombreGanadorPartida() const;
    const std::string& obtenerNombrePerdedorPartida() const;
    void actualizarPuntuacionPartida();

    void aumentarPuntuacion();
    void reducirPuntuacion();

private:
    std::string nombre_;
    int puntuacion_;
    std::vector<Carta> mazoOriginal_;
    std::vector<Carta> mazoMezclado_;
    std::vector<Carta> mano_;
    Carta cartaElegida_ = Carta(Carta::Tipo::DESCONOCIDO, Carta::Color::DESCONOCIDO, 0); // Valor predeterminado

    std::vector<Carta> cartasGanadasPropias_;
    std::vector<Carta> cartasGanadasRonda_;

    void eliminarCartaDeMano(const Carta& carta);
    void guardarCartaGanadaPropia(const Carta& cartaGanada);

    int importarPuntuacion(const std::string& nombreJugador);
    void exportarPuntuacion(const std::string& nombreJugador, int puntuacion);



};

#endif // JUGADOR_H
