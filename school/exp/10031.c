#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint64_t cube(uint64_t x) {
    return x * x * x;
}

int main() {
    int n;
    scanf("%d", &n);
    uint64_t sum = 0;
    for (int i = 1; i <= n; i++)
        sum += cube(i);
    printf("%lld\n", sum);
    return 0;
}