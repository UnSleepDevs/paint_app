#include "color.h"

char *toString_color(Color *color) {
  if (color->color > _MAX_PIXEL_COLOR || color->color < _MIN_PIXEL_COLOR) {
    return " INVALID ";
  }

  char* colors[_PIXEL_COUNT] = {" Rojo ", " Azul ", " Verde ", " Amarillo ",
                                " Magenta "," Cyan ", " Negro " ," Blanco "};
  return colors[color->color - _MIN_PIXEL_COLOR];
}

void change_color(Color *color, attr_t newColor) {
  if (newColor > _MAX_PIXEL_COLOR || newColor < _MIN_PIXEL_COLOR) {
    return;
  }
  if (newColor == 0)
    newColor = 7;

  color->color = newColor;
  strcpy(color->str, toString_color(color));
}

Color *create_color() {
  Color *color = malloc(sizeof(Color));
  if (color == NULL)
    return NULL;
  change_color(color, PIXEL_DEFAULT);
  return color;
}

void free_color(Color *color) { free(color); }
void next_color(Color *color) {
  if (color->color == _MAX_PIXEL_COLOR) {
    change_color(color, _MIN_PIXEL_COLOR);
    return;
  }
  change_color(color, color->color + 1);
}

void previus_color(Color *color) {
  if (color->color == _MIN_PIXEL_COLOR) {
    change_color(color, _MAX_PIXEL_COLOR);
    return;
  }
  change_color(color, color->color - 1);
}
