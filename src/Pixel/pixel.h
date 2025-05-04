#ifndef PIXEL_H
#define PIXEL_H
#include <ncurses.h>
#include <stdlib.h>
typedef struct{
    attr_t color;
    int x;
    int y;
} Pixel;

Pixel* create_pixel(int color, int x, int y);
void free_pixel(Pixel* pixel);
#endif
