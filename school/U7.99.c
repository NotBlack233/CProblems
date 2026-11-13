#include <stdio.h>
#include <stdint.h>

uint64_t fact(uint64_t x) {
    if (!(x & ~1)) return 1;
    return x * fact(x - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", fact(n));
    return 0;
}