# ProyectoRPG
Proyecto final del curso de Programación Bajo Plataformas Abiertas
# Resumen de Scripts del Proyecto RPG

## **Archivo: `main.c`**
### Funcionalidad:
- Controla el flujo principal del programa.
- Presenta el menú principal al jugador con opciones:
  1. Nuevo Juego.
  2. Continuar.
  3. Salir.
- Inicializa el mapa y gestiona la interacción del jugador con el mundo.
- Verifica si el jugador encuentra enemigos en el mapa, iniciando combates cuando las posiciones coinciden.
- Guarda y carga partidas entre sesiones.

---

## **Archivo: `menu.c`**
### Funcionalidad:
- Define y muestra el menú principal del juego utilizando colores ANSI.
- Permite al jugador seleccionar opciones del menú.

### Funciones principales:
1. **`mostrar_menu`**: Imprime el menú en pantalla.
2. **`obtener_opcion_menu`**: Captura la entrada del jugador para seleccionar una opción.

---

## **Archivo: `personaje.c`**
### Funcionalidad:
- Gestiona la creación y configuración del personaje principal.

### Funciones principales:
1. **`crear_personaje`**: Genera un personaje basado en la selección del jugador (Guerrero o Mago).

---

## **Archivo: `guardar.c`**
### Funcionalidad:
- Maneja el guardado y la carga de partidas del jugador en un archivo.

### Funciones principales:
1. **`guardar_partida`**: Almacena los datos del personaje en un archivo.
2. **`cargar_partida`**: Recupera los datos del personaje desde un archivo previamente guardado.

---

## **Archivo: `combate.c`**
### Funcionalidad:
- Implementa el sistema de combate por turnos entre el jugador y los enemigos.
- El jugador puede atacar o defender.
- Las acciones del enemigo se eligen aleatoriamente.
- Finaliza el combate cuando la vida del jugador o del enemigo llega a 0.

### Funciones principales:
1. **`iniciar_combate`**: Realiza el combate entre el jugador y un enemigo, mostrando animaciones simples.
2. **`mostrar_animacion_ataque`**: Anima un ataque en el mapa.
3. **`mostrar_animacion_defensa`**: Anima una acción defensiva en el mapa.

---

## **Archivo: `mapa.c`**
### Funcionalidad:
- Administra la generación y visualización del mapa del mundo.
- Gestiona el movimiento del jugador y la interacción con los enemigos.

### Funciones principales:
1. **`inicializar_mundo`**: Genera el mapa inicial.
2. **`mostrar_mapa`**: Imprime el mapa en pantalla.
3. **`mover_personaje`**: Permite al jugador moverse por el mapa y verifica encuentros con enemigos.
4. **`generar_enemigo`**: Crea enemigos en posiciones aleatorias del mapa.

---

## **Archivo: `menu.h`**
### Funcionalidad:
- Contiene las declaraciones de las funciones del menú.

---

## **Archivo: `personaje.h`**
### Funcionalidad:
- Declara la estructura `Personaje` y la función para crear personajes.

---

## **Archivo: `guardar.h`**
### Funcionalidad:
- Declara las funciones para guardar y cargar partidas.

---

## **Archivo: `combate.h`**
### Funcionalidad:
- Declara la estructura `Enemigo` y las funciones relacionadas con el combate.

---

## **Archivo: `mapa.h`**
### Funcionalidad:
- Declara las funciones y variables globales relacionadas con el mapa y los enemigos.
- Declara la estructura global `Enemigo`.

---

## **Organización del Proyecto**
1. **`src/`**: Contiene todos los archivos fuente `.c` del proyecto.
2. **`include/`**: (Opcional) Puedes colocar aquí los archivos `.h` para mantener una estructura más limpia.
3. **`data/`**: (Opcional) Directorio para almacenar archivos de guardado.
4. **`README.md`**: Contendrá este resumen y las instrucciones para ejecutar el proyecto.

---
