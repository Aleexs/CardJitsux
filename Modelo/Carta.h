// carta.h
#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    enum class Tipo { FUEGO_, HIELO_, AGUA_, DESCONOCIDO };
    enum class Color { ROJO_, AZUL_, VERDE_, DESCONOCIDO };

    Carta(Tipo tipo = Tipo::DESCONOCIDO, Color color = Color::DESCONOCIDO, int numero = 0);


    Tipo getTipo() const;
    Color getColor() const;
    std::string tipoToString() const; 
    std::string colorToString() const; 
    int getNumero() const; 

    
    int comparar(const Carta& otraCarta) const; // Funcion para comparar dos cartas
    bool operator==(const Carta& otra) const {
        return tipo_ == otra.tipo_ && color_ == otra.color_ && numero_ == otra.numero_;
    }

private:
    Tipo tipo_;
    Color color_;
    int numero_;
};

#endif // CARTA_H

