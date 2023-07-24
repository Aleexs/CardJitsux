// jugador.cpp
#include "jugador.h"
#include <iostream>
#include <random>

Jugador::Jugador(const std::string& nombre, const std::vector<Carta>& mazoOriginal, int puntuacion)
    : nombre_(nombre), puntuacion_(puntuacion), mazoOriginal_(mazoOriginal) {
    importarPuntuacion();
    mazoMezclado_ = mazoOriginal_;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(mazoMezclado_.begin(), mazoMezclado_.end(), g);
}

void Jugador::importarPuntuacion() {
    std::ifstream archivoRanking("Ranking.txt");
    if (!archivoRanking.is_open()) {
        // Si no se puede abrir el archivo, se considera que el jugador no tiene puntuaci�n y se inicializa en 0
        puntuacion_ = 0;
        return;
    }

    std::string linea;
    while (std::getline(archivoRanking, linea)) {
        std::istringstream iss(linea);
        std::string nombre;
        int puntuacion;
        iss >> nombre >> puntuacion;
        if (nombre == nombre_) {
            puntuacion_ = puntuacion;
            break;
        }
    }
    archivoRanking.close();
}

void Jugador::exportarPuntuacion() const {
    std::ofstream archivoRanking("Ranking.txt", std::ios_base::app); // Se abre en modo append para agregar sin sobrescribir
    if (archivoRanking.is_open()) {
        archivoRanking << nombre_ << " " << puntuacion_ << "\n";
        archivoRanking.close();
    }
}

int Jugador::getPuntuacion() const {
    return puntuacion_;
}

void Jugador::actualizarPuntuacion(int puntos) {
    puntuacion_ += puntos;
}

std::vector<Carta> Jugador::obtenerMazoMezclado() const {
    return mazoMezclado_;
}

void Jugador::generarMano() {
    mano_.clear();
    while (mano_.size() < 5 && !mazoMezclado_.empty()) {
        mano_.push_back(mazoMezclado_.back());
        mazoMezclado_.pop_back();
    }
}

void Jugador::mostrarMano() const {
    std::cout << "Mano de " << nombre_ << ":\n";
    for (const auto& carta : mano_) {
        std::cout << carta.tipoToString() << carta.colorToString() << carta.getNumero() << ", ";
    }
    std::cout << "\n";
}

Carta Jugador::elegirCarta() {
    std::cout << "Mano de " << nombre_ << ":\n";
    int i = 1;
    for (const auto& carta : mano_) {
        std::cout << i << ". " << carta.tipoToString() << carta.colorToString() << carta.getNumero() << "\n";
        i++;
    }

    size_t eleccion; 
    do {
        std::cout << "Elige una carta (1-" << i - 1 << "): ";
        std::cin >> eleccion;
    } while (eleccion < 1 || eleccion >= static_cast<size_t>(i));

    cartaElegida_ = mano_[eleccion - 1]; // Copia la carta seleccionada a cartaElegida_

    eliminarCartaDeMano(cartaElegida_);
    generarMano(); // Actualizar la mano con una nueva carta si es necesario
    return cartaElegida_;
}

const Carta& Jugador::obtenerCartaElegida() const {
    return cartaElegida_;
}

const std::string& Jugador::obtenerNombre() const {
    return nombre_;
}

void Jugador::eliminarCartaDeMano(const Carta& carta) {
    auto it = std::find(mano_.begin(), mano_.end(), carta);
    if (it != mano_.end()) {
        mano_.erase(it);
    }
}

int Jugador::enfrentarCartas(Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) {
    cartasGanadasRonda_.clear();

    std::cout << "Jugador " << nombre_ << " eligi� la carta: " << cartaJugador1.tipoToString() << cartaJugador1.colorToString() << cartaJugador1.getNumero() << std::endl;
    std::cout << "Jugador " << jugadorContrincante.obtenerNombre() << " eligi� la carta: " << cartaJugador2.tipoToString() << cartaJugador2.colorToString() << cartaJugador2.getNumero() << std::endl;

    int resultado = cartaJugador1.comparar(cartaJugador2);

    if (resultado == -1) {
        // Jugador 1 gana la ronda
        guardarCartaGanadaPropia(cartaJugador1);
        jugadorContrincante.eliminarCartaDeMano(cartaJugador2);
    }
    else if (resultado == 1) {
        // Jugador 2 gana la ronda
        jugadorContrincante.guardarCartaGanadaPropia(cartaJugador2);
        eliminarCartaDeMano(cartaJugador1);
    }
    else {
        // Empate, no se guarda ninguna carta
        eliminarCartaDeMano(cartaJugador1);
        jugadorContrincante.eliminarCartaDeMano(cartaJugador2);
    }

    return resultado;
}

const std::vector<Carta>& Jugador::obtenerCartasGanadas() const {
    return cartasGanadasPropias_;
}

const std::vector<Carta>& Jugador::obtenerCartasGanadasRonda() const {
    return cartasGanadasRonda_;
}

bool Jugador::esGanadorPartida() const {
    return cartasGanadasPropias_.size() > 3;
}

const std::string& Jugador::obtenerNombreGanadorPartida() const {
    if (esGanadorPartida()) {
        return nombre_;
    }
    
}

const std::string& Jugador::obtenerNombrePerdedorPartida() const {
    if (!esGanadorPartida()) {
        return nombre_;
    }
    
}

void Jugador::actualizarPuntuacionPartida() {
    if (esGanadorPartida()) {
        puntuacion_ += 2;
    }
    else {
        puntuacion_ -= 1;
    }
}

void Jugador::guardarCartaGanadaPropia(const Carta& cartaGanada) {
    cartasGanadasPropias_.push_back(cartaGanada);
}


std::string Jugador::obtenerGanadorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const {
    if (cartaJugador1 == cartaJugador2) {
        return "Empate";
    }
    else if ((cartaJugador1.getTipo() == Carta::Tipo::FUEGO_ && cartaJugador2.getTipo() == Carta::Tipo::HIELO_) ||
        (cartaJugador1.getTipo() == Carta::Tipo::HIELO_ && cartaJugador2.getTipo() == Carta::Tipo::AGUA_) ||
        (cartaJugador1.getTipo() == Carta::Tipo::AGUA_ && cartaJugador2.getTipo() == Carta::Tipo::FUEGO_)) {
        return nombre_;
    }
    else {
        return jugadorContrincante.obtenerNombre();
    }
}

std::string Jugador::obtenerPerdedorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const {
    std::string ganador = obtenerGanadorRonda(jugadorContrincante, cartaJugador1, cartaJugador2);
    return (ganador == nombre_) ? jugadorContrincante.obtenerNombre() : nombre_;
}

void Jugador::mostrarGanadorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const {
    std::string ganador = obtenerGanadorRonda(jugadorContrincante, cartaJugador1, cartaJugador2);
    std::cout << "El ganador de la ronda es: " << ganador << std::endl;
}

void Jugador::mostrarPerdedorRonda(const Jugador& jugadorContrincante, const Carta& cartaJugador1, const Carta& cartaJugador2) const {
    std::string perdedor = obtenerPerdedorRonda(jugadorContrincante, cartaJugador1, cartaJugador2);
    std::cout << "El perdedor de la ronda es: " << perdedor << std::endl;
}

void Jugador::aumentarPuntuacion() {
    puntuacion_ += 2;
}

void Jugador::reducirPuntuacion() {
    if (puntuacion_ > 0) {
        puntuacion_ -= 1;
    }
}

int Jugador::importarPuntuacion(const std::string& nombreJugador) {
    std::ifstream archivo("Ranking.txt");
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string nombre;
        int puntuacion;
        if (iss >> nombre >> puntuacion) {
            if (nombre == nombreJugador) {
                return puntuacion;
            }
        }
    }
    return 0; 
}

void Jugador::exportarPuntuacion(const std::string& nombreJugador, int puntuacion) {
    std::ifstream archivoEntrada("Ranking.txt");
    std::vector<std::string> lineas;
    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        lineas.push_back(linea);
    }

    archivoEntrada.close();

    std::ofstream archivoSalida("Ranking.txt");
    bool jugadorEncontrado = false;
    for (const std::string& linea : lineas) {
        std::istringstream iss(linea);
        std::string nombre;
        int puntuacionExistente;
        if (iss >> nombre >> puntuacionExistente) {
            if (nombre == nombreJugador) {
                archivoSalida << nombreJugador << " " << puntuacion << std::endl;
                jugadorEncontrado = true;
            }
            else {
                archivoSalida << linea << std::endl;
            }
        }
    }

    if (!jugadorEncontrado) {
        archivoSalida << nombreJugador << " " << puntuacion << std::endl;
    }
}

