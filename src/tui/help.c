#include "help.h"
#include <ncurses.h>

void help() {
  int sizeX = 25, sizeY = 15;
  int posX = (COLS / 2) - (sizeX / 2), posY = (LINES / 2) - (sizeY / 2);
  WINDOW *win = newwin(sizeY, sizeX, posY, posX);

  box(win, 0, 0);
  wprintw(win, "Ayuda");
  mvwprintw(win, 1, X_OFSSET, "夢Pixel - v0.1");
  mvwprintw(win, 2, X_OFSSET, "W/A/S/D\tMoverse");
  mvwprintw(win, 3, X_OFSSET, "I\tInsertar pixel");
  mvwprintw(win, 4, X_OFSSET, "R\tQuitar pixel");
  mvwprintw(win, 5, X_OFSSET, "F/J\tCambiar color");
  mvwprintw(win, 6, X_OFSSET, "E\tModo edición");
  mvwprintw(win, 7, X_OFSSET, "L\tModo linea");
  mvwprintw(win, 8, X_OFSSET, "N\tModo normal");
  mvwprintw(win, 9, X_OFSSET, "H\tAyuda");
  mvwprintw(win, 10, X_OFSSET, "G\t Ir a linea");
  mvwprintw(win, 11, X_OFSSET, "Q\t Salir");
  wattron(win, A_REVERSE);
  mvwprintw(win, sizeY - 1, 14, " Salir ");
  wattroff(win, A_REVERSE);

  wrefresh(win);
  getch();

}
