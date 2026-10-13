#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

uint64_t cube(uint64_t x) {
    return x * x * x;
}

bool is_narc(uint64_t x) {
    uint64_t t = 0, xm = x;
    while (xm) {
        t += cube(xm % 10);
        xm /= 10;
        if (t > x) return false;
    }
    return t == x;
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (is_narc(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}