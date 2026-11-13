#include <stdio.h>
#include <stdlib.h>

const int N = 10;

static int _comp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

void sort(int *arr, int n) {
    qsort(arr, n, sizeof(int), _comp);
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, N);
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}