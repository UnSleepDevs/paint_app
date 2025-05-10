#ifndef PIXEL_H
#define PIXEL_H
#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif
#include <stdlib.h>
typedef struct{
    attr_t color;
    int x;
    int y;
} Pixel;

Pixel* create_pixel(int color, int x, int y);
void free_pixel(Pixel* pixel);
#endif
