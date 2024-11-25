#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"




char mapa[MAPA_ALTO][MAPA_ANCHO];  // Mapa global
int movimientos = 0;               // Contador de movimientos

typedef struct {
    int x;
    int y;
    int activo;  // 1 si el enemigo está activo, 0 si no
} Enemigo;

Enemigo enemigos[MAX_ENEMIGOS];

// Inicializar el mapa y posiciones de los enemigos
void inicializar_mundo() {
    // Mapa predefinido
    char mapa_creado[MAPA_ALTO][MAPA_ANCHO] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '#', '#', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Copia de mapa_creado a mapa
    for (int i = 0; i < MAPA_ALTO; i++) {
        for (int j = 0; j < MAPA_ANCHO; j++) {
            mapa[i][j] = mapa_creado[i][j];
        }
    }

    // Inicializar los enemigos como inactivos
    for (int i = 0; i < MAX_ENEMIGOS; i++) {
        enemigos[i].activo = 0;
    }
}

void mostrar_mapa(int x_personaje, int y_personaje) {
    clear();  // Limpia la pantalla antes de dibujar el mapa
    for (int i = 0; i < MAPA_ALTO; i++) {
        for (int j = 0; j < MAPA_ANCHO; j++) {
            if (i == y_personaje && j == x_personaje) {
                mvaddch(i, j, '@');  // Dibuja el personaje
            } else {
                int es_enemigo = 0;
                for (int k = 0; k < MAX_ENEMIGOS; k++) {
                    if (enemigos[k].activo && enemigos[k].x == j && enemigos[k].y == i) {
                        mvaddch(i, j, '$');  // Dibuja al enemigo
                        es_enemigo = 1;
                        break;
                    }
                }
                if (!es_enemigo) {
                    mvaddch(i, j, mapa[i][j]);  // Dibuja el mapa
                }
            }
        }
    }
    refresh();
}

void generar_enemigo() {
    for (int i = 0; i < MAX_ENEMIGOS; i++) {
        if (!enemigos[i].activo) {  // Encuentra una posición libre para un nuevo enemigo
            int x, y;
            do {
                x = rand() % MAPA_ANCHO;
                y = rand() % MAPA_ALTO;
            } while (mapa[y][x] != '.');  // Coloca enemigo solo en espacios libres
            enemigos[i].x = x;
            enemigos[i].y = y;
            enemigos[i].activo = 1;
            break;
        }
    }
}

void mover_enemigos(int x_personaje, int y_personaje) {
    for (int i = 0; i < MAX_ENEMIGOS; i++) {
        if (enemigos[i].activo) {
            int dir = rand() % 4;
            int nuevo_x = enemigos[i].x;
            int nuevo_y = enemigos[i].y;

            // Movimiento aleatorio
            switch (dir) {
                case 0: nuevo_y--; break;  // Arriba
                case 1: nuevo_y++; break;  // Abajo
                case 2: nuevo_x--; break;  // Izquierda
                case 3: nuevo_x++; break;  // Derecha
            }

            // Validación de movimiento (no pasar paredes ni sobre el personaje)
            if (nuevo_x >= 0 && nuevo_x < MAPA_ANCHO &&
                nuevo_y >= 0 && nuevo_y < MAPA_ALTO &&
                mapa[nuevo_y][nuevo_x] != '#' &&
                //mapa[nuevo_y][nuevo_x] != '_' &&
                //mapa[nuevo_y][nuevo_x] != '|' &&
                !(nuevo_x == x_personaje && nuevo_y == y_personaje)) {
                enemigos[i].x = nuevo_x;
                enemigos[i].y = nuevo_y;
            }
        }
    }
}

void comprobar_enemigos_cercanos(int x, int y) {
    for (int i = 0; i < MAX_ENEMIGOS; i++) {
        if (enemigos[i].activo &&
            ((enemigos[i].x == x - 1 && enemigos[i].y == y) ||
             (enemigos[i].x == x + 1 && enemigos[i].y == y) ||
             (enemigos[i].x == x && enemigos[i].y == y - 1) ||
             (enemigos[i].x == x && enemigos[i].y == y + 1))) {
            // Menú de combate si hay enemigo adyacente
            printw("¡Enemigo cercano! Menú de combate.\n");
            refresh();
            getch();  // Pausa antes de continuar
        }
    }
}

void mover_personaje(int *x, int *y, int tecla) {
    int nuevo_x = *x, nuevo_y = *y;

    switch (tecla) {
        case KEY_UP:    nuevo_y--; break;
        case KEY_DOWN:  nuevo_y++; break;
        case KEY_LEFT:  nuevo_x--; break;
        case KEY_RIGHT: nuevo_x++; break;
    }

    // Verifica que el nuevo movimiento no sea hacia una pared
    if (mapa[nuevo_y][nuevo_x] != '#') {
        *x = nuevo_x;
        *y = nuevo_y;
        movimientos++;
    }

    // Generar enemigo cada ciertos movimientos
    if (movimientos % 5 == 0) {
        generar_enemigo();
    }

    // Mueve enemigos después del movimiento del personaje
    mover_enemigos(*x, *y);

    // Comprobar si hay enemigos cercanos
    comprobar_enemigos_cercanos(*x, *y);
}

