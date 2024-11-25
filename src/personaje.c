// personaje.c
#include <string.h>
#include "personaje.h"

Personaje crear_personaje(int opcion) {
    Personaje personaje;

    if (opcion == 1) {
        strcpy(personaje.nombre, "Guerrero");
        personaje.vida = 120;
        personaje.fuerza = 15;
        personaje.velocidad = 7;
    } else if (opcion == 2) {
        strcpy(personaje.nombre, "Mago");
        personaje.vida = 80;
        personaje.fuerza = 8;
        personaje.velocidad = 10;
    }
    
    return personaje;
}