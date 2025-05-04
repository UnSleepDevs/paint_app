#include "Cursor/cursor.h"
#include "Paint/color.h"
#include "Paint/paint.h"
#include "Pixel/pixel_list.h"
#include "tui/help.h"
#include "tui/ncurses_utils.h"
#include "tui/statusbar.h"
#include "utils.h"
// ==[OS Libs]==
#include <locale.h>
#include <ncurses.h>

// ==[Free memory]==
void freeit(StatusBar *bar, Cursor *cursor, struct PixelContainer *container) {
  free_statusbar(bar);
  free_cursor(cursor);
  free_pixelcontainer(container);
}

int main() {
  setlocale(LC_ALL, "");
  ncurses_start();

  // ==[Splash screen]==|
  help();

  // ==[State variables]==
  char pos[10];
  StatusBar *bar = create_statusbar(3);
  Cursor *cursor = create_cursor('#');
  struct PixelContainer *pixels = create_pixelcontainer();
  int shouldStop = 0;

  if (bar == NULL || cursor == NULL || pixels == NULL) {
    freeit(bar, cursor, pixels);
    ncurses_end();
    return -1;
  }

  // ==[Setup status bar]==
  statusbar_setText(bar, 0, toString_cursorMode(cursor), COLOR_PAIR(1));
  statusbar_setText(bar, 1, " 0x0 ", COLOR_PAIR(2));
  statusbar_setText(bar, 2, toString_color(cursor->color),
                    COLOR_PAIR(cursor->color->color));

  while (!shouldStop) {
    clear();
    // ==[Draw loop]==
    grid_draw(pixels);
    statusbar_draw(bar);
    draw_cursor(cursor);
    refresh();

    // ==[Update events]==
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

  // ==[Clean memory]==
  freeit(bar, cursor, pixels);
  ncurses_end();
  return 0;
}
