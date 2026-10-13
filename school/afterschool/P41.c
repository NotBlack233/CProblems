#include <stdio.h>
#include <stdlib.h>

int a[50];

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n + m, sizeof(int), comp);
    for (int i = 0; i < n + m; i++) {
        if (i != 0 && a[i] == a[i - 1]) continue;
        printf("%d ", a[i]);
    }
    return 0;
}