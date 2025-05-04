#include "pixel_list.h"
struct PixelContainer *create_pixelcontainer() {
  struct PixelContainer *container = malloc(sizeof(struct PixelContainer));
  if (container == NULL)
    return NULL;
  container->size = 0;
  container->start = NULL;
  container->end = NULL;
  return container;
}

struct PixelNode *_create_node(Pixel *pixel) {
  struct PixelNode *node = malloc(sizeof(struct PixelNode));
  if (node == NULL)
    return NULL;
  node->pixel = pixel;
  return node;
}

void _free_node(struct PixelNode *node) {
  if (node->pixel != NULL)
    free_pixel(node->pixel);
  free(node);
}

struct PixelNode *
_determinate_start_iterated_node(struct PixelContainer *container,
                                 enum Direction direction) {
  return direction == TO_END ? container->start : container->end;
}
int _determinate_start_iterated_index(struct PixelContainer *container,
                                      enum Direction direction) {
  return direction == TO_END ? 0 : container->size;
}
struct PixelNode *_determinate_next_iterated_node(struct PixelNode *current,
                                                  enum Direction direction) {
  return direction == TO_END ? current->next : current->back;
}

int _determinate_next_iterated_index(int index, enum Direction direction) {
  return direction == TO_END ? index + 1 : index - 1;
}

void free_pixelcontainer(struct PixelContainer *container) {
  struct PixelNode *current = container->start;
  while (current != NULL) {
    struct PixelNode *next = current->next;
    _free_node(current);
    current = next;
  }
  free(container);
}

void iterate_pixelcontainer(struct PixelContainer *container,
                            PixelIteratorCallback fn,
                            enum Direction direction) {
  int i;
  struct PixelNode *current;
  for (current = _determinate_start_iterated_node(container, direction), i = 0;
       current != NULL;
       current = _determinate_next_iterated_node(current, direction),
      i = _determinate_next_iterated_index(i, direction)) {
    if (fn(current->pixel, i, current, container) != 0)
      break;
  }
}
void remove_pixelcontainer(struct PixelContainer *container, int x, int y) {
  int c;
  struct PixelNode *current;
  for (current = container->start, c = 0; current != NULL;
       current = current->next, c++) {
    Pixel *pixel = current->pixel;
    if (pixel->x == x && pixel->y == y) {
      struct PixelNode *next = current->next, *back = current->back;
      // En caso de que sea el único pixel
      if (next == NULL && back == NULL) {
        container->start = NULL;
        container->end = NULL;
      }
      // Estamos en el último elemento
      if (next == NULL) {
        // Decimos que el final es el nodo anterior
        container->end = back;
        // Si hay un nodo siguiente lo quitamos de la lista
        if (back != NULL)
          back->next = NULL;
      }
      // Estamos en el nodo inicial
      else if (back == NULL) {
        // Decimos que el primero será el siguiente
        container->start = next;
        // Si hay un nodo siguiente le decimos que no tiene nada detrás
        if (next != NULL)
          next->back = NULL;
      }
      // Nodo intermedio
      else {
        next->back = back;
        back->next = next;
      }
      _free_node(current);
      container->size--;
      break;
    }
  }
}
int _find_and_update(struct PixelContainer *container, Pixel *pixel) {
  struct PixelNode *current = container->start;
  while (current != NULL) {
    Pixel *currentPixel = current->pixel;
    struct PixelNode *next = current->next;
    if (currentPixel->x == pixel->x && currentPixel->y == pixel->y) {
      current->pixel->color = pixel->color;
      return 1;
    }

    current = next;
  }
  return 0;
}
void append_pixelcontainer(struct PixelContainer *container, Pixel *pixel) {
  struct PixelNode *node = _create_node(pixel);
  if (_find_and_update(container, pixel))
    return;
  // Find if we have pixel
  if (node == NULL) {
    free_pixelcontainer(container);
    ncurses_end();
    exit(-1);
  }
  if (container->start == NULL && container->end == NULL) {
    container->start = node;
    container->end = node;
  } else {

    container->end->next = node;
    node->back = container->end;
    container->end = node;
  }
  container->size++;
}
