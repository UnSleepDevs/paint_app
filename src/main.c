#include "Cursor/cursor.h"
#include "Paint/color.h"
#include "Paint/paint.h"
#include "Pixel/pixel_list.h"
#include "tui/ncurses_utils.h"
#include "tui/statusbar.h"
#include "utils.h"
#include <ncurses.h>

void freeit(StatusBar *bar, Cursor *cursor, struct PixelContainer *container) {
  free_statusbar(bar);
  free_cursor(cursor);
  free_pixelcontainer(container);
}

int main() {
  char pos[10];
  ncurses_start();
  StatusBar *bar = create_statusbar(3);
  Cursor *cursor = create_cursor('#');
  struct PixelContainer *pixels = create_pixelcontainer();
  if (bar == NULL || cursor == NULL || pixels == NULL)
    freeit(bar, cursor, pixels);
  int x = 0, y = 0, shouldStop = 0;
  statusbar_setText(bar, 0, toString_cursorMode(cursor), COLOR_PAIR(1));
  statusbar_setText(bar, 1, " 0x0 ", COLOR_PAIR(2));
  statusbar_setText(bar, 2, toString_color(cursor->color),
                    COLOR_PAIR(cursor->color->color));

  while (!shouldStop) {
    clear();
    grid_draw(pixels);
    statusbar_draw(bar);
    draw_cursor(cursor);
    refresh();
    int c = getch();
    handleKey(c, &shouldStop);
    update_cursor(cursor, c);
    grid_update(pixels, c, cursor);
    toString_cursorPosition(cursor, pos);
    statusbar_setText(bar, 0, toString_cursorMode(cursor), COLOR_PAIR(1));
    statusbar_setText(bar, 1, pos, COLOR_PAIR(2));
    statusbar_setText(bar, 2, toString_color(cursor->color),
                      COLOR_PAIR(cursor->color->color));
  }
  freeit(bar, cursor, pixels);
  ncurses_end();
  return 0;
}
