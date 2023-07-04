#ifndef VISTA_H
#define VISTA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.h" 

class Vista {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<sf::Texture> texturasCartas;
    std::vector<sf::Sprite> spritesCartas;

public:
    Vista();

    void mostrarMenu();
    void mostrarPartida(const Jugador& jugador1, const Jugador& jugador2);
    void mostrarGanador(const Jugador& jugador);
    void mostrarProgreso(const Jugador& jugador1, const Jugador& jugador2);

    void cargarTexturasCartas();
    void dibujarCarta(const Carta& carta, int posicionX, int posicionY);
};

#endif // VISTA_H
