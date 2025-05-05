#ifndef CURSOR_GOTO_H
#define CURSOR_GOTO_H

#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif

#include "../Cursor/cursor.h"
#include "../Paint/paint.h"

void open_gotocursor(Cursor* cursor);

#endif
