#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <vector>

class Carta {
private:
    int numero;
    std::string color;
    std::string tipo;

public:
    Carta(int numero, const std::string& color, const std::string& tipo);

    int getNumero() const;
    std::string getColor() const;
    std::string getTipo() const;
};

#endif // CARTA_H
