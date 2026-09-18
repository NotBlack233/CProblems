#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    float sum = 100, cur = 100;
    for (int i = 2; i <= n; i++) {
        sum += cur;
        cur /= 2;
    }
    printf("%.2f %.2f", sum, cur / 2);
    return 0;
}