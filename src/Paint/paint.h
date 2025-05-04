#ifndef PAINT_H
#define PAINT_H
#include <ncurses.h>
#include "../Pixel/pixel_list.h"
#include "../Cursor/cursor.h"
#include <stdlib.h>
#include <math.h>
void grid_draw(struct PixelContainer* grid);
void grid_update(struct PixelContainer* grid, int k, Cursor* cursor);
void grid_toString(char* res);
void draw_line(Coord* a, Coord* b, struct PixelContainer* grid, Cursor* cursor);
#endif
