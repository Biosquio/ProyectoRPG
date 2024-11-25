// personaje.h

#ifndef PERSONAJE_H
#define PERSONAJE_H

typedef struct {
    char nombre[20];
    int vida;
    int fuerza;
    int velocidad;
} Personaje;

// funciòn para inicializar los personajes preestablecidos

Personaje crear_personaje(int opcion);
#endif
