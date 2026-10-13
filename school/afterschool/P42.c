#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool array_eq(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[30], b[30];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), comp);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    qsort(b, m, sizeof(int), comp);

    int left = 0, right = 0;
    while (right < n) {
        if (right == 0 || a[right] != a[right - 1]) {
            a[left++] = a[right++];
        } else
            right++;
    }
    n = left;

    left = 0, right = 0;
    while (right < m) {
        if (right == 0 || b[right] != b[right - 1]) {
            b[left++] = b[right++];
        } else {
            right++;
        }
    }
    m = left;

    if (n == m && array_eq(a, b, n)) {
        puts("1");
    } else {
        puts("0");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}