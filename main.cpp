#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Vista.h"
#include "Jugador.h"

int main()
{
    
    Jugador jugador1("Jugador 1");
    Jugador jugador2("Jugador 2");

    Vista vista;
    vista.mostrarMenu();

    vista.mostrarPartida(jugador1, jugador2);

    return 0;
}
