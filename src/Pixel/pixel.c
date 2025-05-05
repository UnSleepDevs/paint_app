#include "pixel.h"
#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif
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
