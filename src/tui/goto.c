#include "goto.h"

void open_gotocursor(Cursor *cursor) {
  int sizeX = 30, sizeY = 4, posX = (COLS / 2) - (sizeX / 2),
      posY = (LINES / 2) - (sizeY / 2);
  char posStr[15];
  grid_toString(posStr);
  WINDOW *win = newwin(sizeY, sizeX, posY, posX);
  nodelay(stdscr, FALSE);
  box(win, 0, 0);
  wprintw(win, "Ir a");
  mvwprintw(win, 1, 2, "Tamaño: %s", posStr);
  wrefresh(win);
  echo();
  int tmpX = -1, tmpY = -1;
  mvwscanw(win, 2, 2, "%i %i", &tmpX, &tmpY);
  noecho();
  if (tmpX > COLS || tmpY > LINES - 1 || tmpX < 0 || tmpY < 0) {
    mvwprintw(win, 2, 2, "Se salío");
    getch();
  } else {
    cursor->x = tmpX - 1;
    cursor->y = tmpY - 1;
  }

  delwin(win);
}