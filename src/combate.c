// combate.c
#include <stdio.h>
#include "combate.h"

void iniciar_combate(Personaje *jugador, Enemigo *enemigo) {
    printf("¡El combate ha comenzado entre %s y %s!\n", jugador->nombre, enemigo->nombre);

    while (jugador->vida > 0 && enemigo->vida > 0) {
        // Turno del jugador
        printf("%s ataca a %s.\n", jugador->nombre, enemigo->nombre);
        enemigo->vida -= jugador->fuerza;
        printf("La vida de %s ahora es: %d\n", enemigo->nombre, enemigo->vida);

        if (enemigo->vida <= 0) {
            printf("¡%s ha derrotado a %s!\n", jugador->nombre, enemigo->nombre);
            break;
        }

        // Turno del enemigo
        printf("%s ataca a %s.\n", enemigo->nombre, jugador->nombre);
        jugador->vida -= enemigo->fuerza;
        printf("La vida de %s ahora es: %d\n", jugador->nombre, jugador->vida);

        if (jugador->vida <= 0) {
            printf("¡%s ha sido derrotado por %s!\n", jugador->nombre, enemigo->nombre);
            break;
        }
    }
}