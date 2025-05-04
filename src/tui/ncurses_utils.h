#ifndef NCURSES_UTILS
#define NCURSES_UTILS
#include "../Paint/color.h"
#include <ncurses.h>
#include <stdlib.h>
// ==[FUNCTIONS]==
void ncurses_end();
void ncurses_colors();
void ncurses_start();

char *colorToString(int color);
#endif
