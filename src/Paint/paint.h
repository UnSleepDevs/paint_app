#ifndef PAINT_H
#define PAINT_H
#include <ncurses.h>
#include "../Pixel/pixel_list.h"
#include "../Cursor/cursor.h"
void grid_draw(struct PixelContainer* grid);
void grid_update(struct PixelContainer* grid, int k, Cursor* cursor);
#endif
