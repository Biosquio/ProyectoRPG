

// menu.c
#include <stdio.h>
//#include  "menu.h"

// código de color ANSI
#define RESET "\x1b[0m"
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define AZUL "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CIAN "\x1b[36m"
#define BLANCO "\x1b[37m"



void mostrar_menu(){
	printf("%s****************************************%s\n", AZUL, RESET);
	printf("*                        *\n");
	printf("*    %s*** Bienvenido a mi Juego RPG ***%s   *\n", MAGENTA, RESET);
	printf("*                        *\n");
	printf("*****************************************\n\n");

	printf("%sSeleccione una opciòn:%s\n", CIAN, RESET);
	printf("%s1. Nuevo Juego%s\n", VERDE, RESET);
	printf("%s2. Continuar%s\n", AMARILLO, RESET);
	printf("%s3. Salir%s\n", ROJO, RESET);
	printf("\n%s Ingrese un Nùmero: %s", BLANCO, RESET);
}

int obtener_opcion_menu(){
	int opcion;
	scanf("%d", &opcion);
	return opcion;
}
