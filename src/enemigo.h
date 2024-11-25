// enemigo.h
#ifndef ENEMIGO_H
#define ENEMIGO_H

typedef struct
{
    char nombre[50];
    int vida;
    int fuerza;
    int velocidad;
    /* data */
} Enemigo;

Enemigo crear_enemigo(const char* nombre, int vida, int fuerza, int velocidad);

#endif