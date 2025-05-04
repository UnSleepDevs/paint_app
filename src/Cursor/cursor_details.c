#include "cursor.h"
#include <stdio.h>
char *toString_cursorMode(Cursor *cursor) {
    Modes mode = cursor->mode;
    if(mode == NORMAL) return " 👀 NORMAL ";
    if(mode == EDIT) return " 🎨 EDITAR ";
    if(mode == LINE) return " 📏 LINEA ";
    return " DESCONOCIDO ";
}

void toString_cursorPosition(Cursor* cursor, char* dest){
    sprintf(dest, " %ix%i ", cursor->x + 1, cursor->y + 1);
}
