#ifndef PAINT_H
#define PAINT_H
#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif
#include "../Pixel/pixel_list.h"
#include "../Cursor/cursor.h"
#include <stdlib.h>
#include <math.h>
void grid_draw(struct PixelContainer* grid);
void grid_update(struct PixelContainer* grid, int k, Cursor* cursor);
void grid_toString(char* res);
void draw_line(Coord* a, Coord* b, struct PixelContainer* grid, Cursor* cursor);
#endif
