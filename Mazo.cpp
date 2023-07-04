#include <algorithm>
#include <random>
#include <chrono>
#include "Mazo.h"

Mazo::Mazo() {
    for (int numero = 1; numero <= 6; numero++) {
        for (const std::string& color : { "rojo", "amarillo", "azul" }) {
            for (const std::string& tipo : { "fuego", "hielo", "agua" }) {
                cartas.emplace_back(numero, color, tipo);
            }
        }
    }
}

void Mazo::mezclar() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cartas.begin(), cartas.end(), std::default_random_engine(seed));
}

Carta Mazo::sacarCarta() {
    if (cartas.empty()) {
       
    }

    
    Carta carta = cartas.back();
    cartas.pop_back();

    return carta;
}
