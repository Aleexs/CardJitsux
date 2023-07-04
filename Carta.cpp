#include "Carta.h"

Carta::Carta(int numero, const std::string& color, const std::string& tipo)
    : numero(numero), color(color), tipo(tipo) {}

int Carta::getNumero() const {
    return numero;
}

std::string Carta::getColor() const {
    return color;
}

std::string Carta::getTipo() const {
    return tipo;
}
