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

bool Carta::operator==(const Carta& otraCarta) const {
    return (tipo_ == otraCarta.tipo_ && color_ == otraCarta.color_ && numero_ == otraCarta.numero_);
}

