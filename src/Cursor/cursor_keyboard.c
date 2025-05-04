#include "../tui/goto.h"
#include "cursor.h"

void __cursor_handle_keyboard(Cursor *cursor, int k) {
  k = toLowerCase(k);
  if (k == 'w') {
    cursor->y -= 1;
    return;
  }

  if(k == 'g'){
    open_gotocursor(cursor);
    return;
  }
  if (k == 'd') {
    cursor->x += 1;
    return;
  }

  if (k == 'a') {
    cursor->x -= 1;
    return;
  }
  if (k == 's') {
    cursor->y += 1;
    return;
  }
  if (k == 'e') {
    cursor->mode = EDIT;
    return;
  }
  if (k == 'n') {
    cursor->mode = NORMAL;
    return;
  }
  if (k == 'l') {
    cursor->mode = LINE;
    return;
  }
  if (k == 'f') {
    previus_color(cursor->color);
    return;
  }

  if (k == 'j') {
    next_color(cursor->color);
    return;
  }
}