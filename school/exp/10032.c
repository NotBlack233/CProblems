#include <stdint.h>
#include <stdio.h>

int main() {
    double x = 1, y = 2;
    double sum = 0;
    int n;
    scanf("%d", &n);
    while (n--) {
        // printf("%d %d\n", x, y);
        sum += y / x;
        double c = x + y;
        x = y;
        y = c;
    }
    printf("%.2lf\n", sum);
    return 0;
}