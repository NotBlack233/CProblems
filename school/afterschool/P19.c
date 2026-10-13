#include <stdio.h>
#include <stdlib.h>

int a[101], b[101], s[202];

int comp(const void *a, const void *b) {
    return (*(int *)a > *(int *)b);
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", b + i);
    }
    qsort(a, n, sizeof(int), comp);
    qsort(b, m, sizeof(int), comp);

    int *pa = a, *pb = b, *ps = s;
    while (pa < a + n && pb < b + m) {
        if (*pa == *pb) {
            pa++;
            pb++;
            continue;
        }
        int v;
        if (*pa < *pb) {
            v = *pa++;
        } else {
            v = *pb++;
        }
        *ps++ = v;
    }
    while (pa < a + n) {
        if (ps == s || *pa != *(ps - 1)) *ps++ = *pa;
        pa++;
    }

    while (pb < b + m) {
        if (ps == s || *pb != *(ps - 1)) *ps++ = *pb;
        pb++;
    }
    for (ps--; ps + 1 != s; ps--) {
        printf("%d ", *ps);
    }
    return 0;
}