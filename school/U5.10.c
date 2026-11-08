#include <stdio.h>

int main() {
    int a = 1, b = 2;
    double sum = 0;
    int n;
    scanf("%d", &n);
    while (n--) {
        sum += (double)b / a;
        int c = a + b;
        a = b;
        b = c;
    }
    printf("%.6lf\n", sum);
    return 0;
}