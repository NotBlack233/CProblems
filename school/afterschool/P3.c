#include <stdio.h>

int main() {
    char buf[10];
    int a, len = 0;
    scanf("%d", &a);
    while (a) {
        buf[len++] = a % 10;
        a /= 10;
    }

    if (len != 5) {
        printf("error\n");
        return 0;
    }
    for (int i = 0; i < (len - 1) >> 1; i++) {
        if (buf[i] != buf[len - 1 - i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}