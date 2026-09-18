#include <assert.h>
#include <stdio.h>

int main() {
    int a, type;
    scanf("%d %d", &a, &type);
    double rate, duration;
    switch (type) {
        case 1: rate = 0.031; duration = 0.25; break;
        case 2: rate = 0.033; duration = 0.5; break;
        case 3: rate = 0.035; duration = 1; break;
        case 4: rate = 0.044; duration = 2; break;
        case 5: rate = 0.05; duration = 3; break;
        case 6: rate = 0.055; duration = 5; break;
        default: assert(0);
    }
    double profit = a * rate * duration;
    printf("%.2lf\n%.2lf\n", profit, profit + a);
    return 0;
}