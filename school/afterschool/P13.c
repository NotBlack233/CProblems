#include <stdio.h>

double fact[2010];

void fact_init(int n) {
    fact[2] = 2;
    for (int i = 4; i <= n; i++) {
        fact[i] = fact[i - 2] * i * (i - 1);
    }
}

int main() {
    int n;
    double x, ans = 1;
    scanf("%lf %d", &x, &n);
    fact_init(n * 2);
    int sym = -1;
    double power = x * x;
    for (int i = 1; i <= n; i++) {
        ans += power / fact[i * 2] * sym;
        power *= x * x;
        sym = -sym;
    }
    printf("%.8lf", ans);
    return 0;
}