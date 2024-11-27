#include <ncurses.h>
#include <stdlib.h>
#include "combate.h"

// Combate por turnos entre el jugador y un enemigo

Enemigo crear_enemigo(const char* nombre, int vida, int fuerza, int x, int y){
    Enemigo enemigo;
    strcpy(enemigo.nombre, nombre);
    enemigo.vida = vida;
    enemigo.fuerza = fuerza;
    return enemigo;
}