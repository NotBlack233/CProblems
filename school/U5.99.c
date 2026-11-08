#include <stdio.h>
#include <math.h>

#define EPS (1e-6)

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int flag = 1;
    for (int i = m; i <= n; i++) {
        double sqrt1 = sqrt(i + 100), sqrt2 = sqrt(i + 268);
        if (fabs(sqrt1 - (int)sqrt1) < EPS && fabs(sqrt2 - (int)sqrt2) < EPS) {
            printf("%d ", i);
            flag = 0;
        }
    }
    if (flag) puts("no");
    return 0;
}