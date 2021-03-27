#include <math.h>
#include <stdbool.h>

static int pwr[10] = {1,    1,     4,      27,       256,
                      3125, 46656, 823543, 16777216, 387420489};

static bool is_munch(int i) {
  bool result = false;
  int sum = 0;
  for (int n = i; n > 0; n /= 10) {
    int dig = n % 10;
    sum += pwr[dig];
  }
  if (sum == i) {
    result = true;
  }

  return result;
}


