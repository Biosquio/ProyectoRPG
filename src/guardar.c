//guardar .c

#include <stdio.h>
#include <stdlib.h>
#include "guardar.h"

void guardar_partida(Personaje jugador){
    FILE *archivo = fopen("partida.txt", "w");
    if (archivo == NULL){
        printf("Error en abrir el archivo para guardar\n");
        return;
    }

    fprintf(archivo, "%s\n%d\n%d\n%d\n", jugador.nombre, jugador.vida, jugador.fuerza, jugador.velocidad);
    fclose(archivo);
    printf("Partida guardada con èxito\n");
}

Personaje cargar_partida(){
    Personaje jugador;
    FILE *archivo = fopen("partida.txt", "r");
    if (archivo == NULL){
        printf("No hay partida guardada\n");
        jugador.vida = 0; //indica que no hay partida
        return jugador;
    }

    fprintf(archivo, "%s %d %d %d", jugador.nombre, jugador.vida, jugador.fuerza, jugador.velocidad);
    fclose(archivo);
    printf("Partida cargada con èxito. Bienvenido de  nuevo , %s!\n", jugador.nombre);
    return jugador;
}

