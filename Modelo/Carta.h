// carta.h
#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    enum class Tipo { FUEGO_, HIELO_, AGUA_, DESCONOCIDO };
    enum class Color { ROJO_, AZUL_, VERDE_, DESCONOCIDO };

    Carta(Tipo tipo, Color color, int numero);

    Tipo getTipo() const;
    Color getColor() const;
    std::string tipoToString() const; 
    std::string colorToString() const; 
    int getNumero() const; 

    
    bool operator==(const Carta& otraCarta) const;

private:
    Tipo tipo_;
    Color color_;
    int numero_;
};

#endif // CARTA_H

