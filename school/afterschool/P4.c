#include <stdint.h>
#include <stdio.h>

int main() {
    uint8_t buf[10];
    int a, len = 0;
    scanf("%d", &a);
    while (a) {
        buf[len++] = a % 10;
        a /= 10;
    }

    printf("%d\n", len);
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", buf[i]);
    }
    putchar('\n');
    for (int i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }
    putchar('\n');
    return 0;
}