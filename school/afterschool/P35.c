#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    bool flag = false;
    for (int i = 2; i <= n * 2; i++) {
        if (n * 2 % i == 0) {
            if (n * 2 / i == 1) continue;
            if (i & 1) {
                if ((n * 2 / i) & 1) continue;
                int mid = i >> 1;
                int half = (n * 2 / i) >> 1;
                if (mid - half + 1 < 1) continue;
                flag = true;
                for (int t = mid - half + 1; t <= mid + half; t++) {
                    printf("%d ", t);
                }
                putchar('\n');
            } else {
                if (~(n * 2 / i) & 1) continue;
                int mid = i >> 1;
                int half = (n * 2 / i) >> 1;
                if (mid - half < 1) continue;
                flag = true;
                for (int t = mid - half; t <= mid + half; t++) {
                    printf("%d ", t);
                }
                putchar('\n');
            }
        }
    }
    if (!flag) {
        puts("NONE");
    }
    return 0;
}