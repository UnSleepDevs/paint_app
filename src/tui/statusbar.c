#include "statusbar.h"
#include <ncurses.h>
#include <string.h>

//===[ StatusBarPart ]===
StatusBarPart _create_statusbarpart(){
    StatusBarPart part = {
        ._text="",
        ._attributes=0
    };
    return part;
}

StatusBar* create_statusbar(int parts) {
  StatusBar* bar = malloc(sizeof(StatusBar));
  if (bar == NULL) {
    printw("No se pudo reservar memoria para la barra de estado!\n");
    getch();
    exit(1);
  }

  bar->parts = calloc(parts, sizeof(StatusBarPart));
  if(bar->parts == NULL){
      free(bar);
      printw("No se pudo reservar memoria para una parte de la barra de estado!\n");
      getch();
      exit(1);
  }
  bar->size = parts;
  for(int i = 0; i < parts; i++)
      bar->parts[i] = _create_statusbarpart();
  return bar;
}

void free_statusbar(StatusBar *bar){
    free(bar->parts);
}

void statusbar_draw(StatusBar *bar) {
    move(LINES-1, 0);
    for(int i = 0; i < bar->size; i++){
        attron(bar->parts[i]._attributes);
        printw("%s", bar->parts[i]._text);
        attroff(bar->parts[i]._attributes);
    }
}


void statusbar_setText(StatusBar *bar, int part, char *text, attr_t attr){
    if(part > bar->size)
        return;
    strcpy(bar->parts[part]._text, text);
    if(attr != 0){
        bar->parts[part]._attributes = attr;
    }
}
