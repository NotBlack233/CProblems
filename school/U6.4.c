#include <stddef.h>
#include <stdio.h>

int a[20], n = 0;

int main() {
    for (;;) {
        int t;
        scanf("%d", &t);
        if (!t) break;
        a[n++] = t;
    }
    int x;
    scanf("%d", &x);
    char flag = 1;
    for (int i = 0; i < n; i++) {
        if (flag && a[i] >= x) {
            printf("%d ", x);
            flag = 0;
        }
        printf("%d ", a[i]);
    }
    return 0;
}