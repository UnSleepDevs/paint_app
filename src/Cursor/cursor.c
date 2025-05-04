#include "cursor.h"
#include <ncurses.h>
Cursor *create_cursor(char t) {
  Cursor *cursor = malloc(sizeof(Cursor));
  if (cursor == NULL)
    return NULL;
  Color *color = create_color();
  if (color == NULL) {
    free_cursor(cursor);
    return NULL;
  }
  cursor->color = color;
  cursor->show = t;
  cursor->x = 0;
  cursor->mode = NORMAL;
  cursor->y = 0;
  return cursor;
}


void draw_cursor(Cursor *cursor) {
  attron(COLOR_PAIR(cursor->color->color));
  mvaddch(cursor->y, cursor->x, cursor->show);
  attroff(COLOR_PAIR(cursor->color->color));
}



void update_cursor(Cursor *cursor, int k) {
  __cursor_handle_keyboard(cursor, k);
  int maxX = COLS;
  int maxY = LINES - 2;
  if (cursor->x > maxX)
    cursor->x = maxX;
  if (cursor->x < 0)
    cursor->x = 0;
  if (cursor->y < 0)
    cursor->y = 0;
  if (cursor->y > maxY)
    cursor->y = maxY;
}

void free_cursor(Cursor *cursor) {
  free_color(cursor->color);
  free(cursor);
}
