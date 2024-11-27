#ifndef COMBATE_H
#define COMBATE_H

#include "personaje.h"

typedef struct {
    int x;
    int y;
    int vida;
    int fuerza;
    int activo;
    char nombre[20];
} Enemigo;

void iniciar_combate(Personaje jugador, Enemigo enemigo);

#endif
