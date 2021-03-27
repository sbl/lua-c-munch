#include <stdio.h>

#include "munch.h"

int main() {
  for (int i = 2; i < 1e7; ++i) {
    if (is_munch(i)) {
      printf("yep: %d\n", i);
    }
  }

  return 0;
}
