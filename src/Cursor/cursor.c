#include "cursor.h"

Coord *create_coord(int x, int y) {
  Coord *coord = malloc(sizeof(Coord));
  if (coord == NULL)
    return NULL;
  coord->x = x;
  coord->y = y;

  return coord;
}

Cursor *create_cursor(char t) {
  // ==[Basic cursor  config] ==
  Cursor *cursor = malloc(sizeof(Cursor));
  if (cursor == NULL)
    return NULL;
  cursor->show = t;
  cursor->mode = NORMAL;

  Color *color = create_color();
  if (color == NULL) {
    free_cursor(cursor);
    return NULL;
  }
  cursor->color = color;

  Coord *coord = create_coord(0, 0);
  if (coord == NULL) {
    free_cursor(cursor);
    return NULL;
  }
  cursor->coords = coord;
  return cursor;
}

void draw_cursor(Cursor *cursor) {
  Coord *coords = cursor->coords;
  attron(COLOR_PAIR(cursor->color->color));
  mvaddch(coords->y, coords->x, cursor->show);
  attroff(COLOR_PAIR(cursor->color->color));
}

void update_cursor(Cursor *cursor, int k) {
  __cursor_handle_keyboard(cursor, k);
  Coord *coords = cursor->coords;
  int maxX = COLS - 1;
  int maxY = LINES - 2;
  if (coords->x > maxX)
    coords->x = maxX;
  if (coords->x < 0)
    coords->x = 0;
  if (coords->y < 0)
    coords->y = 0;
  if (coords->y > maxY)
    coords->y = maxY;
}

void free_cursor(Cursor *cursor) {
  free_color(cursor->color);
  free(cursor->coords);
  free(cursor);
}
