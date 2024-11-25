// enemigo .c

#include "enemigo.h"
#include <string.h>

Enemigo crear_enemigo(const char* nombre, int vida, int fuerza, int velocidad){
    Enemigo enemigo;
    strcpy(enemigo.nombre, nombre);
    enemigo.vida = vida;
    enemigo.fuerza = fuerza;
    enemigo.velocidad = velocidad;
    return enemigo;
}