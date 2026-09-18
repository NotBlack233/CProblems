#include <stdio.h>

int main() {
    double denom = 1, sum = 1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        denom *= i;
        sum += 1.0 / denom;
    }
    printf("%.10lf", sum);
    return 0;
}