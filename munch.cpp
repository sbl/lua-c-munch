#include <array>
#include <cmath>
#include <iostream>

int main() {
  std::array<short, 10> pwr{};

  // precomputed power table
  for (auto i = 0; i < 10; i++) {
    pwr[i] = std::pow<short>(i, i);
  }

  for (int i = 1; i <= 1e7; ++i) {
    int sum = 0;
    for (int n = i; n > 0; n /= 10) {
      int dig = n % 10;
      sum += pwr[dig];
    }

    if (sum == i) {
      std::cout << sum << std::endl;
    }
  }
}
