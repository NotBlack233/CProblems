#include <stdio.h>

const double ratio[] = {0.1, 0.075, 0.05, 0.03, 0.015};
const double full[] = {10000, 7500, 10000, 6000, 6000};
const int threshold[] = {1e5, 2e5, 4e5, 6e5, 1e6};
const int N = 5;

int main() {
    int profit;
    double ans = 0;
    scanf("%d", &profit);
    for (int i = 0; i < N; i++) {
        if (profit > threshold[i]) {
            ans += full[i];
            // printf("ans = %lf\n", ans);
        } else {
            ans += (profit - (i > 0 ? threshold[i - 1] : 0)) * ratio[i];
            break;
        }
    }
    if (profit > threshold[N - 1]) {
        ans += (profit - threshold[N - 1]) * 0.01;
    }
    printf("%.2lf\n", ans);
    return 0;
}