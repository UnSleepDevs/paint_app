#include "pixel.h"
#include <ncurses.h>
Pixel* create_pixel(int color, int x, int y){
    Pixel* pixel = malloc(sizeof(Pixel));
    if(pixel == NULL) return NULL;
    pixel->color = COLOR_PAIR(color);
    pixel->x = x;
    pixel->y = y;
    return pixel;
};
void free_pixel(Pixel *pixel){
    free(pixel);
}
