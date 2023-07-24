// mazo.cpp
#include "mazo.h"
#include <algorithm>
#include <iostream>
#include <random>

Mazo::Mazo() {
    generarMazo();
}

void Mazo::generarMazo() {
    for (int tipo = 0; tipo < 3; tipo++) {
        for (int color = 0; color < 3; color++) {
            for (int numero = 1; numero <= 5; numero++) {
                Carta::Tipo tipoEnum = static_cast<Carta::Tipo>(tipo);
                Carta::Color colorEnum = static_cast<Carta::Color>(color);
                mazoOriginal_.emplace_back(tipoEnum, colorEnum, numero);
            }
        }
    }
}

std::vector<Carta> Mazo::obtenerMazoOriginal() const {
    return mazoOriginal_;
}

void Mazo::mostrarMazoOriginal() const {
    std::cout << "Mazo Original:\n";
    for (const auto& carta : mazoOriginal_) {
        std::cout << carta.tipoToString() << carta.colorToString() << carta.getNumero() << ", ";
    }
    std::cout << "]\n";
}
