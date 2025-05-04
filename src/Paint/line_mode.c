#include "paint.h"

int _max(int a, int b) { return a > b ? a : b; }
void draw_line(Coord *a, Coord *b, struct PixelContainer *grid,
               Cursor *cursor) {
  int dx = abs(b->x - a->x), dy = abs(b->y - a->y);

  int sx = a->x < b->x ? 1 : -1, sy = a->y < b->y ? 1 : -1;
  int err = dx - dy;

  while(1){
    if (a->x >= 0 && a->x < COLS && a->y >= 0 && a->y < LINES){
        Pixel* pix = create_pixel(cursor->color->color, a->x, a->y);
        append_pixelcontainer(grid, pix);
    }
    if (a->x == b->x && a->y == b->y) break; 
    int e2 = 2 * err;
    if (e2 > -dy) {
        err -= dy;
        a->x += sx;
    }

    if (e2 < dx) {
        err += dx;
        a->y += sy;
    }

  }
}