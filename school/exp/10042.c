#include <stdio.h>

int a_buf[11][11], b_buf[11][11];

void mat_input(int m[11][11], int x, int y) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

int main() {
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    mat_input(a_buf, m, n);
    mat_input(b_buf, n, p);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            int sum = 0;
            for (int k = 1; k <= n; k++) {
                sum += a_buf[i][k] * b_buf[k][j];
            }
            printf("%d ", sum);
        }
        putchar('\n');
    }
    return 0;
}