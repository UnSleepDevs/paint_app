#ifndef PIXEL_COLORS_H
#define PIXEL_COLORS_H

#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif
#include <string.h>
#include <stdlib.h>
// ==[COLORS]==
#define PIXEL_RED 3
#define PIXEL_BLUE 4
#define PIXEL_GREEN 5
#define PIXEL_YELLOW 6
#define PIXEL_MAGENTA 7
#define PIXEL_CYAN 8
#define PIXEL_BLACK 9
#define PIXEL_DEFAULT 10

#define _MAX_PIXEL_COLOR 10
#define _MIN_PIXEL_COLOR 3
#define _PIXEL_COUNT 8

typedef struct {
  attr_t color;
  char str[16];
} Color;

// ==[FUNCTIONS]==
char *toString_color(Color *color);
void change_color(Color *color, attr_t newColor);
void free_color(Color* color);
Color* create_color();
void next_color(Color *color);
void previus_color(Color *color);
#endif
