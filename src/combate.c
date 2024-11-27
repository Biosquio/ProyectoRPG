// combate.c
#include <stdio.h>
#include "combate.h"

void iniciar_combate(Personaje jugador, Enemigo enemigo) {
    int opcion;

    while (jugador.vida > 0 && enemigo.vida > 0) {
        clear();
        printw("¡COMBATE INICIADO!\n");
        printw("Jugador: %s\n", jugador.nombre);
        printw("Vida: %d\n\n", jugador.vida);
        printw("Enemigo: Goblin Salvaje\n");
        printw("Vida: %d\n\n", enemigo.vida);

        printw("Elige tu acción:\n");
        printw("1. Atacar\n");
        printw("2. Defender\n");
        refresh();

        opcion = getch();

        if (opcion == '1') { // Atacar
            enemigo.vida -= jugador.fuerza;
            printw("¡Atacaste al enemigo! Vida del enemigo: %d\n", enemigo.vida);
        } else if (opcion == '2') { // Defender
            printw("¡Te defendiste del próximo ataque!\n");
        } else {
            printw("Opción no válida. Pierdes el turno.\n");
        }

        // Turno del enemigo
        if (enemigo.vida > 0) {
            int accion_enemigo = rand() % 2; // 0: atacar, 1: defender
            if (accion_enemigo == 0) {
                if (opcion == '2') {
                    printw("¡Bloqueaste el ataque del enemigo!\n");
                } else {
                    jugador.vida -= enemigo.fuerza;
                    printw("El enemigo te atacó. Tu vida: %d\n", jugador.vida);
                }
            } else {
                printw("El enemigo se defendió.\n");
            }
        }

        napms(500); // Pausa para la animación
    }

    if (jugador.vida <= 0) {
        printw("¡Has sido derrotado! Fin del juego.\n");
    } else if (enemigo.vida <= 0) {
        printw("¡Has derrotado al enemigo!\n");
    }

    getch(); // Pausa para que el jugador lea el resultado
}