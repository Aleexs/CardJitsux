cmake_minimum_required(VERSION 3.12)

project(Jutsu)

# Agrega todos los archivos fuente de tu proyecto, incluyendo las clases
set(SOURCES
    src/main.cpp
    src/Carta.cpp
    src/Mazo.cpp
    src/Jugador.cpp
    src/Partida.cpp
)

# Configura la compilación y las opciones del ejecutable
add_executable(Jutsu ${SOURCES})
