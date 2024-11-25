#ifndef MAPA_H
#define MAPA_H

#define MAPA_ANCHO 10
#define MAPA_ALTO 10
#define MAX_ENEMIGOS 3  // Número máximo de enemigos en el mapa
extern char mapa[MAPA_ALTO][MAPA_ANCHO];  // Declarar el mapa global

void inicializar_mundo();
void mostrar_mapa();
void mover_personaje(int *x, int *y, int tecla);
void limpiar_mapa();

#endif