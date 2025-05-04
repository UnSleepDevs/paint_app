#include "paint.h"
#include <stdio.h>
void *dummy(void *dumm) { return dumm; }
int _draw(Pixel *pixel, int i, struct PixelNode *current,
          struct PixelContainer *container) {

  dummy(&i);
  dummy(current);
  dummy(container);
  attron(pixel->color);
  mvaddch(pixel->y, pixel->x, '*');
  attroff(pixel->color);
  return 0;
}
void grid_draw(struct PixelContainer *grid) {
  iterate_pixelcontainer(grid, _draw, TO_END);
};

Coord last = {.x = -1, .y = -1};

void grid_update(struct PixelContainer *grid, int k, Cursor *cursor) {
  Coord *coords = cursor->coords;
  if (k == 'i' && cursor->mode == EDIT) {
    int x = coords->x, y = coords->y;
    Pixel *pixel = create_pixel(cursor->color->color, x, y);
    append_pixelcontainer(grid, pixel);
  }
  if (k == 'i' && cursor->mode == LINE) {
    if (last.x == -1 && last.y == -1) {
      last.x = coords->x;
      last.y = coords->y;
      return;
    }
    draw_line(&last, cursor->coords, grid, cursor);
    last.x = -1;
    last.y = -1;
  }
  if (k == 'r' && cursor->mode == EDIT) {
    int x = coords->x, y = coords->y;
    remove_pixelcontainer(grid, x, y);
  }
}

void grid_toString(char *res) { sprintf(res, "%i %i", COLS, LINES - 1); }