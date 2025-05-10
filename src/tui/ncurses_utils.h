#ifndef NCURSES_UTILS
#define NCURSES_UTILS
#include "../Paint/color.h"
#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif
#include <stdlib.h>
// ==[FUNCTIONS]==
void ncurses_end();
void ncurses_colors();
void ncurses_start();

char *colorToString(int color);
#endif
