#include <stdint.h>
#include <stdio.h>

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calc_days(int m1, int d1, int m2, int d2) {
    int res = 0;
    for (int m = m1; m < m2; m++) {
        res += days[m];
    }
    res -= d1;
    res += d2;
    return res;
}

int main() {
    int m1, d1, n, m2, d2;
    scanf("%d%d%d%d%d", &m1, &d1, &n, &m2, &d2);
    printf("%lld\n", n * (1ull << calc_days(m1, d1, m2, d2)));
    return 0;
}