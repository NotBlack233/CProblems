#include <stdio.h>
#include <stdint.h>

void count(int a[], int n, int *pmax, int *pmin, float *pave, int *psum) {
    *pmax = INT32_MIN;
    *pmin = INT32_MAX;
    *psum = 0;
    for (int i = 0; i < n; i++) {
        *pmax = a[i] > *pmax ? a[i] : *pmax;
        *pmin = a[i] < *pmin ? a[i] : *pmin;
        *psum += a[i];
    }
    *pave = (float) *psum / n;
}

int main() {
    int a[30];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int pmax, pmin, psum;
    float pave;
    count(a, n, &pmax, &pmin, &pave, &psum);
    printf("%d %d %.2f %d\n", pmax, pmin, pave, psum);
    return 0;
}
