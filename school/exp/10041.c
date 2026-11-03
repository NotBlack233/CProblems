#include <stdio.h>

int a_buf[2][30] = {0};

int main() {
    a_buf[0][1] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a_buf[i & 1][j] = a_buf[!(i & 1)][j - 1] + a_buf[!(i & 1)][j];
            printf("%d ", a_buf[i & 1][j]);
        }
        putchar('\n');
    }
    return 0;
}