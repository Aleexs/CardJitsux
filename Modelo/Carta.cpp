// carta.cpp
#include "carta.h"

Carta::Carta(Tipo tipo, Color color, int numero)
    : tipo_(tipo), color_(color), numero_(numero) {}


Carta::Tipo Carta::getTipo() const {
    return tipo_;
}

Carta::Color Carta::getColor() const {
    return color_;
}

int Carta::getNumero() const {
    return numero_;
}

std::string Carta::tipoToString() const {
    switch (tipo_) {
    case Tipo::FUEGO_: return "Fuego_";
    case Tipo::HIELO_: return "Hielo_";
    case Tipo::AGUA_: return "Agua_";
    case Tipo::DESCONOCIDO: return "Desconocido";
    default: return "Desconocido";
    }
}

std::string Carta::colorToString() const {
    switch (color_) {
    case Color::ROJO_: return "Rojo_";
    case Color::AZUL_: return "Azul_";
    case Color::VERDE_: return "Verde_";
    case Color::DESCONOCIDO: return "Desconocido";
    default: return "Desconocido";
    }
}

int Carta::comparar(const Carta& otraCarta) const {
    // Si las cartas son del mismo tipo, el ganador es aquel con el n�mero mayor
    if (tipo_ == otraCarta.tipo_) {
        if (numero_ > otraCarta.numero_) {
            return -1; // Carta actual gana
        }
        else if (numero_ < otraCarta.numero_) {
            return 1; // Otra carta gana
        }
        else {
            return 0; // Empate
        }
    }

    // Si las cartas son de tipos diferentes, se aplica la l�gica original
    if ((tipo_ == Tipo::FUEGO_ && otraCarta.tipo_ == Tipo::HIELO_) ||
        (tipo_ == Tipo::HIELO_ && otraCarta.tipo_ == Tipo::AGUA_) ||
        (tipo_ == Tipo::AGUA_ && otraCarta.tipo_ == Tipo::FUEGO_)) {
        return -1; // Carta actual gana
    }
    else {
        return 1; // Otra carta gana
    }
}

