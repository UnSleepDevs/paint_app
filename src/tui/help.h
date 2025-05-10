#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H
#ifdef _WIN32
    #include <curses.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Sistema operativo no soportado"
#endif
#define X_OFSSET 2
void help();


#endif
