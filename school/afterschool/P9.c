#include <stdio.h>

double abs_d(double x) {
    if (x > 0) return x;
    return -x;
}

int main() {
    double e, pih_prev, pih = 4.0 / 3;
    int n = 1;
    scanf("%lf", &e);
    while (pih * 2 < e) {
        pih_prev = pih;
        n++;
        pih *= 4.0 * n * n / (2 * n + 1) / (2 * n - 1);
    }
    if (abs_d(pih * 2 - e) < abs_d(pih_prev * 2 - e)) {
        printf("%.9lf %d", pih * 2, n);
    } else {
        printf("%.9lf %d", pih_prev * 2, n - 1);
    }
    return 0;
}
