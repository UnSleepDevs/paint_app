#ifndef STATUS_BAR_H
#define STATUS_BAR_H
#include <ncurses.h>
#include <stdlib.h>
typedef struct {
    char _text[15];
    attr_t _attributes;
} StatusBarPart;
typedef struct {
  WINDOW *_parent;
  StatusBarPart* parts;
  int size;
} StatusBar;

StatusBar* create_statusbar( int parts);
void statusbar_setText(StatusBar *bar, int part, char *text, attr_t attr);
void statusbar_draw(StatusBar *bar);
void free_statusbar(StatusBar *bar);
#endif
