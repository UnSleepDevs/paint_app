#ifndef CURSOR_H
#define CURSOR_H
/**
* @file: cursor.h
* El cursor se encarga de guardar sus coordenadas,
* el color actual a dibujar, y el modo del programa
*/
#include "../Paint/color.h"
#include "../utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
/**
* Este enum es usado para definir el comportamiento del
* programa, en el modo normal, se usa para visualizar el arte
* el modo edit es para agregar o quitar pixeles
* el modo line es para dibujar lineas rectas en el lienzo
*/
typedef enum { NORMAL, EDIT, LINE } Modes;

typedef struct {
  // @TODO: Implementar la funcionalidad para ocultar el cursor
  char show;
  int x;
  int y;
  Modes mode;
  Color *color;
} Cursor;

Cursor *create_cursor(char cursor);
void update_cursor(Cursor *cursor, int k);
void draw_cursor(Cursor *cursor);
void free_cursor(Cursor *cursor);

char *toString_cursorMode(Cursor *cursor);
void toString_cursorPosition(Cursor* cursor, char* restrict);
void __cursor_handle_keyboard(Cursor* cursor, int k);
#endif
