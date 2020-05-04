#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// https://chsasank.github.io/lua-c-wrapping.html

bool is_munch(int i) {
  int sum = 0;
  for (int n = i; n > 0; n /= 10) {
    int dig = n % 10;
    sum += pow(dig, dig);
  }

  if (sum == i) {
    return true;
  }

  return false;
}

int main() {
  for (int i = 1; i <= 1e7; ++i) {
    if (is_munch(i)) {
      printf("%d\n", i);
    }
  }
}
