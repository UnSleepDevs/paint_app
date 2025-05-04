#include "utils.h"
#include "tui/help.h"

char toLowerCase(char c) {
  if (c >= 65 && c <= 90)
    return c + 32;
  return c;
}

void handleKey(int k, int *flag) {
  k = toLowerCase(k);
  if (k == 'q') {
    *flag = 1;
    return;
  }

  if (k == 'h') {
    help();
    return;
  };
  
}
