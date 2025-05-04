#include "paint.h"
#include <stdio.h>
int _draw(Pixel *pixel, int i, struct PixelNode *current,
          struct PixelContainer *container) {
  attron(pixel->color);
  mvaddch(pixel->y, pixel->x, '*');
  attroff(pixel->color);
  return 0;
}
void grid_draw(struct PixelContainer *grid) {
  iterate_pixelcontainer(grid, _draw, TO_END);
};

void grid_update(struct PixelContainer *grid, int k, Cursor *cursor) {
  if (k == 'i' && cursor->mode == EDIT) {
    printw("Appending on %i, %i", cursor->x, cursor->y);
    getch();
    int x = cursor->x, y = cursor->y;
    Pixel *pixel = create_pixel(cursor->color->color, x, y);
    append_pixelcontainer(grid, pixel);
  }
  if (k == 'r' && cursor->mode == EDIT) {
      int x = cursor->x, y = cursor->y;
      remove_pixelcontainer(grid, x, y);
  }
}


void grid_toString(char *res){
  sprintf(res,"%i %i", COLS, LINES - 1);
}