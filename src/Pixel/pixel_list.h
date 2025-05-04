#ifndef PIXEL_LIST_H
#define PIXEL_LIST_H
#include "../tui/ncurses_utils.h"
#include "pixel.h"
#include <stdlib.h>

enum Direction { TO_END, TO_START };

struct PixelNode {
  Pixel *pixel;
  struct PixelNode *next;
  struct PixelNode *back;
};

struct PixelContainer {
  struct PixelNode *start;
  struct PixelNode *end;
  size_t size;
};

typedef int (*PixelIteratorCallback)(Pixel *current, int i,
                                     struct PixelNode *node,
                                     struct PixelContainer *container);

struct PixelContainer *create_pixelcontainer();
void free_pixelcontainer(struct PixelContainer *container);
void iterate_pixelcontainer(struct PixelContainer *container,
                            PixelIteratorCallback fn, enum Direction direction);
void append_pixelcontainer(struct PixelContainer *container, Pixel *pixel);
void remove_pixelcontainer(struct PixelContainer *container, int x, int y);

#endif
