#include <limits.h>
#include <stdio.h>

int m, n;
int a[11][11];

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int check(int x, int y) {
    for (int i = 0; i < m; i++) {
        if (a[i][y] < a[x][y]) return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[x][i] > a[x][y]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                printf("%d %d %d\n", i, j, a[i][j]);
                return 0;
            }
        }
    }

    puts("no");
    return 0;
}
