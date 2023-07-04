#include "Vista.h"

Vista::Vista() {
    // Crear la ventana
    window.create(sf::VideoMode(800, 600), "CardJitsu");

    // Cargar la fuente de texto
    if (!font.loadFromFile("Code8x8.ttf")) {       
        std::cout << "No cargo la fuente";
    }

    // Cargar las texturas de las cartas
    void mostrarMenu();
    void mostrarPartida(const Jugador & jugador1, const Jugador & jugador2);
    cargarTexturasCartas();
}

void Vista::mostrarMenu() {
    sf::Text titulo;
    titulo.setFont(font);
    titulo.setString("Card Jitsu");
    titulo.setCharacterSize(48);
    titulo.setPosition(200, 50);
    titulo.setFillColor(sf::Color::White);

    sf::Text opcionJugar;
    opcionJugar.setFont(font);
    opcionJugar.setString("JUGAR");
    opcionJugar.setCharacterSize(32);
    opcionJugar.setPosition(350, 200);
    opcionJugar.setFillColor(sf::Color::White);

    sf::Text opcionSkins;
    opcionSkins.setFont(font);
    opcionSkins.setString("SKINS");
    opcionSkins.setCharacterSize(32);
    opcionSkins.setPosition(350, 250);
    opcionSkins.setFillColor(sf::Color::White);

    sf::Text opcionVolumen;
    opcionVolumen.setFont(font);
    opcionVolumen.setString("VOLUMEN");
    opcionVolumen.setCharacterSize(32);
    opcionVolumen.setPosition(350, 300);
    opcionVolumen.setFillColor(sf::Color::White);

    sf::Text opcionSalir;
    opcionSalir.setFont(font);
    opcionSalir.setString("SALIR");
    opcionSalir.setCharacterSize(32);
    opcionSalir.setPosition(350, 350);
    opcionSalir.setFillColor(sf::Color::White);

    bool mostrar = true;
    while (mostrar) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (opcionJugar.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {                    
                    mostrar = false;
                }
                else if (opcionSkins.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                ////
                }
                else if (opcionVolumen.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    ///
                }
                else if (opcionSalir.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    window.close();
                    mostrar = false;
                }
            }
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar 
        window.draw(titulo);
        window.draw(opcionJugar);
        window.draw(opcionSkins);
        window.draw(opcionVolumen);
        window.draw(opcionSalir);

        // Mostrar los cambios en la ventana
        window.display();
    }
}


void Vista::mostrarPartida(const Jugador& jugador1, const Jugador& jugador2) {
    

    sf::Texture textureFondo;
    if (!textureFondo.loadFromFile("fondo.png")) {
        
        return; // Falta: Manejo de error en caso de no poder cargar la textura del fondo
    }

    sf::Sprite spriteFondo;
    spriteFondo.setTexture(textureFondo);

    sf::Texture textureJugador1;
    if (!textureJugador1.loadFromFile("jugador1.png")) {
        
        return; // Falta: Manejo de error en caso de no poder cargar la textura del jugador 1
    }

    sf::Sprite spriteJugador1;
    spriteJugador1.setTexture(textureJugador1);
    spriteJugador1.setPosition(sf::Vector2f(-200, 300)); // Posici�n inicial del jugador 1 fuera de la pantalla

    sf::Texture textureJugador2;
    if (!textureJugador2.loadFromFile("jugador2.png")) {
        
        return; // Falta: Manejo de error en caso de no poder cargar la textura del jugador 2
    }

    sf::Sprite spriteJugador2;
    spriteJugador2.setTexture(textureJugador2);
    spriteJugador2.setPosition(sf::Vector2f(800, 300)); // Posici�n inicial del jugador 2 fuera de la pantalla

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
        }

        // posiciones de los jugadores, estado de las cartas, etc.

        // Animaci�n de movimiento del jugador 1 hacia el centro de la pantalla
        if (spriteJugador1.getPosition().x < 300) {
            spriteJugador1.move(1, 0);
        }

        // Animaci�n de movimiento 
        if (spriteJugador2.getPosition().x > 400) {
            spriteJugador2.move(-1, 0);
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el fondo de la partida
        window.draw(spriteFondo);

        // Dibujar los jugadores
        window.draw(spriteJugador1);
        window.draw(spriteJugador2);

        // L�gica para dibujar los elementos de la partida, como cartas, animaciones, etc.

        // Mostrar los cambios en la ventana
        window.display();
    }

    // Completo: Implementaci�n de la funci�n mostrarPartida()
}



void Vista::mostrarGanador(const Jugador& jugador) {
    // L�gica para mostrar al ganador de la partida en la ventana
    
}

void Vista::mostrarProgreso(const Jugador& jugador1, const Jugador& jugador2) {
    // L�gica para mostrar el progreso de los jugadores en la ventana
    
}

void Vista::cargarTexturasCartas() {
    // L�gica para cargar las texturas de las cartas desde archivos de imagen
    
}

void Vista::dibujarCarta(const Carta& carta, int posicionX, int posicionY) {
    // L�gica para dibujar una carta en la ventana en la posici�n especificada
    
}
