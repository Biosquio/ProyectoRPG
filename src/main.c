#include <stdio.h>
#include <ncurses.h>
#include "menu.h"
#include "personaje.h"
#include "guardar.h"
#include "combate.h"
#include "mapa.h"  // Incluir el archivo del mapa

int main() {
    int opcion;
    int eleccion_personaje;
    Personaje jugador = {0};  // Inicializar el personaje vacío

    // Inicializar ncurses
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    do {
        mostrar_menu();
        opcion = obtener_opcion_menu();

        switch (opcion) {
            case 1:
                // Iniciar un nuevo juego
                printf("\nIniciando un nuevo juego...\n");
                printf("Seleccione su personaje:\n");
                printf("1. Guerrero (Vida: 120, Fuerza: 15, Velocidad: 7)\n");
                printf("2. Mago (Vida: 80, Fuerza: 8, Velocidad: 10)\n");
                printf("Ingrese el número de su elección: ");
                scanf("%d", &eleccion_personaje);

                if (eleccion_personaje == 1 || eleccion_personaje == 2) {
                    jugador = crear_personaje(eleccion_personaje);
                    printf("\nHas elegido a %s con las siguientes características:\n", jugador.nombre);
                    printf("Vida: %d\n", jugador.vida);
                    printf("Fuerza: %d\n", jugador.fuerza);
                    printf("Velocidad: %d\n\n", jugador.velocidad);

                    // Inicializar y mostrar el mundo
                    inicializar_mundo();
                    int posX = 1, posY = 1;  // Posición inicial del personaje
                    int tecla;

                    mostrar_mapa(posX, posY);
                    while ((tecla = getch()) != 'q') {  // Presiona 'q' para salir al menú principal
                        mover_personaje(&posX, &posY, tecla, jugador);

                        // Actualizar el mapa después del movimiento o combate
                        mostrar_mapa(posX, posY);
                    }
                } else {
                    printf("Opción inválida. Volviendo al menú principal.\n");
                }
                break;

            case 2:
                // Cargar partida
                jugador = cargar_partida();
                if (jugador.vida > 0) {
                    printf("Tu personaje %s está listo para continuar:\n", jugador.nombre);
                    printf("Vida: %d\n", jugador.vida);
                    printf("Fuerza: %d\n", jugador.fuerza);
                    printf("Velocidad: %d\n\n", jugador.velocidad);
                }
                break;

            case 3:
                // Guardar y salir
                if (jugador.vida > 0) {
                    guardar_partida(jugador);
                } else {
                    printf("No hay partida para guardar.\n");
                }
                printf("Saliendo del juego...\n");
                break;

            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    // Finalizar ncurses
    endwin();

    return 0;
}
