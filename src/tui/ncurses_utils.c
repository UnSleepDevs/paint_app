#include "ncurses_utils.h"
void ncurses_end() {
  curs_set(1);
  crmode();
  echo();
  endwin();
}

void ncurses_colors() {
  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_BLUE);
  // Pixel colors
  init_pair(PIXEL_RED, COLOR_BLACK, COLOR_RED);
  init_pair(PIXEL_BLUE, COLOR_BLACK, COLOR_BLUE);
  init_pair(PIXEL_GREEN, COLOR_BLACK, COLOR_GREEN);
  init_pair(PIXEL_YELLOW, COLOR_BLACK, COLOR_YELLOW);
  init_pair(PIXEL_MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(PIXEL_CYAN, COLOR_BLACK, COLOR_CYAN);
  init_pair(PIXEL_BLACK, COLOR_WHITE, COLOR_BLACK);
  init_pair(PIXEL_DEFAULT, COLOR_BLACK, COLOR_WHITE);
}

void ncurses_start() {
  initscr();
  clear();
  refresh();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  noecho();

  if (!has_colors()) {
    printw("La terminal no soporta colores...");
    ncurses_end();
    exit(-1);
  }
  start_color();
  use_default_colors();
  ncurses_colors();
}
