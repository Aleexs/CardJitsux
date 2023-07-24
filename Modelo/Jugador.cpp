// jugador.cpp
#include "jugador.h"
#include <iostream>
#include <random>

Jugador::Jugador(const std::string& nombre, const std::vector<Carta>& mazoOriginal)
    : nombre_(nombre), mazoOriginal_(mazoOriginal) {
    // Generar 
    mazoMezclado_ = mazoOriginal_;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(mazoMezclado_.begin(), mazoMezclado_.end(), g);
}

Jugador::Jugador(const Jugador& otroJugador) {
    nombre_ = otroJugador.nombre_;
    mazoOriginal_ = otroJugador.mazoOriginal_;
    mazoMezclado_ = otroJugador.mazoMezclado_;
    mano_ = otroJugador.mano_;
    cartaElegida_ = otroJugador.cartaElegida_;
    // Copiar el vector cartasGanadasPropias_ 
    cartasGanadasPropias_ = otroJugador.cartasGanadasPropias_;
}

std::string Jugador::obtenerNombre() const {
    return nombre_;
}

void Jugador::generarMazoAleatorio() {
    mazoMezclado_ = mazoOriginal_; 
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(mazoMezclado_.begin(), mazoMezclado_.end(), g);
}

std::vector<Carta> Jugador::obtenerMazoMezclado() const {
    return mazoMezclado_;
}

void Jugador::generarMano() {
    while (mano_.size() < 5 && !mazoMezclado_.empty()) {
        mano_.push_back(mazoMezclado_.back());
        mazoMezclado_.pop_back();
    }
}

void Jugador::eliminarCartaDeMano(const Carta& carta) {
    auto it = std::find(mano_.begin(), mano_.end(), carta);
    if (it != mano_.end()) {
        mano_.erase(it);
    }
}

Carta Jugador::elegirCarta() {
    std::cout << "Mano de " << nombre_ << ":\n";
    int i = 1;
    for (const auto& carta : mano_) {
        std::cout << i << ". " << carta.tipoToString() << carta.colorToString() << carta.getNumero() << "\n";
        i++;
    }

    size_t eleccion; // Cambia el tipo de eleccion a size_t
    do {
        std::cout << "Elige una carta (1-" << i - 1 << "): ";
        std::cin >> eleccion;
    } while (eleccion < 1 || eleccion >= static_cast<size_t>(i));

    cartaElegida_ = mano_[eleccion - 1]; 

    eliminarCartaDeMano(cartaElegida_);
    generarMano(); // Actualizar la mano con una nueva carta si es necesario
    return cartaElegida_;
}

Carta Jugador::obtenerCartaElegida() const {
    return cartaElegida_;
}

void Jugador::guardarCartaGanadaPropia(const Carta& cartaGanada) {
    cartasGanadasPropias_.push_back(cartaGanada);

    
    auto it = std::find(mazoOriginal_.begin(), mazoOriginal_.end(), cartaGanada);
    if (it != mazoOriginal_.end()) {
        mazoOriginal_.erase(it);
    }
}

const std::vector<Carta>& Jugador::obtenerCartasGanadasPropias() const {
    return cartasGanadasPropias_;
}

void Jugador::guardarCartaGanada(const Carta& cartaGanada) {
    auto it = std::find(cartasGanadas_.begin(), cartasGanadas_.end(), cartaGanada);
    if (it == cartasGanadas_.end()) {
        
        cartasGanadas_.push_back(cartaGanada);
    }

    it = std::find(mazoOriginal_.begin(), mazoOriginal_.end(), cartaGanada);
    if (it != mazoOriginal_.end()) {
        mazoOriginal_.erase(it);
    }
}

int Jugador::enfrentarCartas(Jugador& jugadorContrario, const Carta& cartaJugador1, const Carta& cartaJugador2) {
    std::cout << "Jugador " << nombre_ << " eligi� la carta: " << cartaJugador1.tipoToString() << cartaJugador1.colorToString() << cartaJugador1.getNumero() << std::endl;
    std::cout << "Jugador " << jugadorContrario.obtenerNombre() << " eligi� la carta: " << cartaJugador2.tipoToString() << cartaJugador2.colorToString() << cartaJugador2.getNumero() << std::endl;

    
    if (cartaJugador1.getTipo() == cartaJugador2.getTipo()) {
        // Si las cartas tienen el mismo tipo, gana la que tiene el n�mero m�s alto
        if (cartaJugador1.getNumero() > cartaJugador2.getNumero()) {
            // Gana la cartaJugador1
            guardarCartaGanada(cartaJugador1);
            std::cout << "Jugador " << nombre_ << " gana la ronda." << std::endl;
            return 1; // Jugador 1 gana la ronda
        }
        else if (cartaJugador1.getNumero() < cartaJugador2.getNumero()) {
            // Gana la cartaJugador2
            jugadorContrario.guardarCartaGanada(cartaJugador2);
            std::cout << "Jugador " << jugadorContrario.obtenerNombre() << " gana la ronda." << std::endl;
            return 2; // Jugador 2 gana la ronda
        }
        else {
            std::cout << "Empate en la ronda." << std::endl;
            return 0; // Empate
        }
    }
    else {
        // Si las cartas tienen tipos diferentes, aplicamos las reglas de tipo: Fuego > Hielo > Agua > Fuego
        if ((cartaJugador1.getTipo() == Carta::Tipo::FUEGO_ && cartaJugador2.getTipo() == Carta::Tipo::HIELO_) ||
            (cartaJugador1.getTipo() == Carta::Tipo::HIELO_ && cartaJugador2.getTipo() == Carta::Tipo::AGUA_) ||
            (cartaJugador1.getTipo() == Carta::Tipo::AGUA_ && cartaJugador2.getTipo() == Carta::Tipo::FUEGO_)) {
            // Gana la cartaJugador1
            guardarCartaGanada(cartaJugador1);
            std::cout << "Jugador " << nombre_ << " gana la ronda." << std::endl;

            return 1; // Jugador 1 gana la ronda
        }
        else {
            // Gana la cartaJugador2
            jugadorContrario.guardarCartaGanada(cartaJugador2);
            std::cout << "Jugador " << jugadorContrario.obtenerNombre() << " gana la ronda." << std::endl;

            return 2; // Jugador 2 gana la ronda
        }
    }
}

void Jugador::mostrarMano() const {
    std::cout << "Mano de " << nombre_ << ":\n";
    for (const auto& carta : mano_) {
        std::cout << carta.tipoToString() << carta.colorToString() << carta.getNumero() << ", ";
    }
    std::cout << "\n";
}

void Jugador::mostrarCartasGanadasPropias() const {
    std::cout << "Cartas ganadas por " << nombre_ << ":\n";
    for (const auto& carta : cartasGanadasPropias_) {
        std::cout << carta.tipoToString() << carta.colorToString() << carta.getNumero() << ", ";
    }
    std::cout << std::endl;
}

void Jugador::mostrarCartasGanadas() const {
    std::cout << "Cartas ganadas por " << nombre_ << ":\n";
    for (const auto& carta : cartasGanadas_) {
        std::cout << carta.tipoToString() << carta.colorToString() << carta.getNumero() << ", ";
    }
    std::cout << std::endl;
}