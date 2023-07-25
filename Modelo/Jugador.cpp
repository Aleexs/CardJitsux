// jugador.cpp
#include "jugador.h"

Jugador::Jugador(const std::string& nombre, const Mazo& mazoOriginal)
    : nombre_(nombre), mazoOriginal_(mazoOriginal.obtenerMazoOriginal()) {
    mezclarCartas();
}

std::string Jugador::getNombre() const {
    return nombre_;
}

void Jugador::mostrarMazoOriginal() const {
    std::cout << "Mazo Original de " << nombre_ << ":" << std::endl;
    std::cout << "[";
    for (const auto& carta : mazoOriginal_) {
        std::cout << carta.tipoToString()<< carta.colorToString()<< carta.getNumero() << " ";
    }
    std::cout << "] \n";
}

void Jugador::mostrarMazoAleatorio() const {
    std::cout << "\n Mazo Aleatorio de " << nombre_ << ":" << std::endl;
    std::cout << "[";
    for (const auto& carta : mazoAleatorio_) {
        std::cout << carta.tipoToString()<< carta.colorToString() << carta.getNumero() << " ";
    }
    std::cout << "] \n";
}

std::vector<Carta> Jugador::obtenerMazoAleatorio() const {
    return mazoAleatorio_;
}

void Jugador::mezclarCartas() {
    mazoAleatorio_ = mazoOriginal_;

    // Generar una semilla aleatoria para el generador de n�meros aleatorios
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());

    // Mezclar las cartas de forma aleatoria usando el generador
    std::shuffle(mazoAleatorio_.begin(), mazoAleatorio_.end(), std::default_random_engine(seed));
}


/// Mano
void Jugador::generarMano() {
    if (mazoAleatorio_.empty()) {
        std::cout << "No hay suficientes cartas para generar una mano.\n";
        return;
    }

    mano_.clear();
    int cartasEnMano = std::min(5, static_cast<int>(mazoAleatorio_.size()));
    for (int i = 0; i < cartasEnMano; i++) {
        mano_.push_back(mazoAleatorio_.front());
        mazoAleatorio_.erase(mazoAleatorio_.begin());
    }
}

std::vector<Carta> Jugador::obtenerMano() const {
    return mano_;
}

void Jugador::mostrarMano() const {
    std::cout << "\n" << nombre_ << ", tu mano actual es:\n";
    int i = 1;
    for (const auto& carta : mano_) {
        std::cout <<i<<") " << carta.tipoToString() << " " << carta.colorToString() << " " << carta.getNumero() << "\n";
        i++;
    }
}
/*
Carta Jugador::elegirCarta() {
    int opcion;
    std::cout << "\n" << nombre_ << ", elige una carta de tu mano:\n";
    mostrarMano();

    do {
        std::cout << "Ingresa el numero de la carta que deseas jugar (1-5): ";
        std::cin >> opcion;
    } while (opcion < 1 || opcion > static_cast<int>(mano_.size())); // Conversi�n expl�cita a int

    // Obtener la carta elegida
    Carta cartaElegida = mano_[static_cast<size_t>(opcion) - 1]; // Conversi�n expl�cita a size_t

    // Eliminar la carta elegida de la mano
    mano_.erase(mano_.begin() + static_cast<size_t>(opcion) - 1); // Conversi�n expl�cita a size_t

    // Rellenar la mano con la primera carta del mazoAleatorio
    if (!mazoAleatorio_.empty()) {
        mano_.push_back(mazoAleatorio_.front());
        mazoAleatorio_.erase(mazoAleatorio_.begin());
    }

    return cartaElegida; // Devolver una copia de la carta, no una referencia
}*/


Carta Jugador::obtenerCartaElegida() {
    int opcion;
    std::cout << "\n" << nombre_ << ", elige una carta de tu mano:\n";
    mostrarMano();

    do {
        std::cout << "Ingresa el numero de la carta que deseas jugar (1-5): ";
        std::cin >> opcion;
    } while (opcion < 1 || opcion > static_cast<int>(mano_.size())); // Conversi�n expl�cita a int

    // Obtener la carta elegida
    Carta cartaElegida = mano_[static_cast<size_t>(opcion) - 1]; // Conversi�n expl�cita a size_t

    // Eliminar la carta elegida de la mano
    mano_.erase(mano_.begin() + static_cast<size_t>(opcion) - 1); // Conversi�n expl�cita a size_t

    // Rellenar la mano con la primera carta del mazoAleatorio
    if (!mazoAleatorio_.empty()) {
        mano_.push_back(mazoAleatorio_.front());
        mazoAleatorio_.erase(mazoAleatorio_.begin());
    }

    return cartaElegida; // Devolver una copia de la carta, no una referencia
}

void Jugador::enfrentarCartas(const Carta& cartaJugador1, const Carta& cartaJugador2, Jugador& jugadorContrario) {
    int resultado = cartaJugador1.comparar(cartaJugador2);

    if (resultado == -1) {
        std::cout << "\n" << nombre_ << " gana la ronda con la carta: " << cartaJugador1.tipoToString()
            << " " << cartaJugador1.colorToString() << " " << cartaJugador1.getNumero() << "\n";
        cartasGanadoras_.push_back(cartaJugador1);
        jugadorContrario.mostrarEstadoRondaContrario(cartaJugador1); // Llamamos a la funci�n del jugador contrario
    }
    else if (resultado == 1) {
        std::cout << "\n" << jugadorContrario.nombre_ << " gana la ronda con la carta: " << cartaJugador2.tipoToString()
            << " " << cartaJugador2.colorToString() << " " << cartaJugador2.getNumero() << "\n";
        jugadorContrario.cartasGanadoras_.push_back(cartaJugador2);
        mostrarEstadoRondaContrario(cartaJugador2); // Llamamos a la funci�n para mostrar el mensaje del jugador contrario
    }
    else {
        std::cout << "\nEs un empate en la ronda.\n";
    }
}

void Jugador::mostrarEstadoRondaContrario(const Carta& cartaGanadoraContrario) {
    std::string tipoGanadorContrario;
    switch (cartaGanadoraContrario.getTipo()) {
    case Carta::Tipo::FUEGO_: tipoGanadorContrario = "incendi�ndose"; break;
    case Carta::Tipo::HIELO_: tipoGanadorContrario = "congel�ndose"; break;
    case Carta::Tipo::AGUA_: tipoGanadorContrario = "moj�ndose"; break;
    default: tipoGanadorContrario = "desconocido"; break;
    }
    std::cout << nombre_ << " se est� " << tipoGanadorContrario << ".\n";
}

bool Jugador::verificarGanadorPartida() {
    // Verificar si hay 3 cartas del mismo tipo pero diferente color
    for (size_t i = 0; i < cartasGanadoras_.size(); i++) {
        int contadorTipo = 1;
        for (size_t j = i + 1; j < cartasGanadoras_.size(); j++) {
            if (cartasGanadoras_[i].getTipo() == cartasGanadoras_[j].getTipo() &&
                cartasGanadoras_[i].getColor() != cartasGanadoras_[j].getColor()) {
                contadorTipo++;
                if (contadorTipo == 3) {
                    return true;
                }
            }
        }
    }

    // Verificar si hay 3 cartas del mismo color pero diferente tipo
    for (size_t i = 0; i < cartasGanadoras_.size(); i++) {
        int contadorColor = 1;
        for (size_t j = i + 1; j < cartasGanadoras_.size(); j++) {
            if (cartasGanadoras_[i].getColor() == cartasGanadoras_[j].getColor()) {
                contadorColor++;
                if (contadorColor == 3) {
                    return true;
                }
            }
        }
    }

    return false;
}

const std::vector<Carta>& Jugador::obtenerCartasGanadoras() const {
    return cartasGanadoras_;
}

void Jugador::mostrarCartasGanadoras() const {
    std::cout << "\nCartas ganadoras de " << nombre_ << ":\n";
    for (const auto& carta : cartasGanadoras_) {
        std::cout << carta.tipoToString() << carta.colorToString()<< carta.getNumero() << " ";
    }
}



