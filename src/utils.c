#include "utils.h"
char toLowerCase(char c){
    if(c >= 65 && c <= 90)
        return c+32;
    return c;
}


void handleKey(int k, int *flag) {
  if (k == 'Q' || k == 'q') {
    *flag = 1;
    return;
  }
}
