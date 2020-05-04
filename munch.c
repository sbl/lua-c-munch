#include <math.h>
#include <stdio.h>

// https://chsasank.github.io/lua-c-wrapping.html

int main()
{
    short pwr[10];

    // precomputed power table
    for (int i = 0; i < 10; ++i) {
        pwr[i] = pow(i, i);
    }

    for (int i = 1; i <= 1e7; ++i) {
        int sum = 0;
        for (int n = i; n > 0; n /= 10) {
            int dig = n % 10;
            sum += pwr[dig];
        }

        if (sum == i) {
            printf("%d\n", i);
        }
    }
}
