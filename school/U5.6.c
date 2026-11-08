#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    unsigned long long sum = 0, fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        sum += fact;
    }
    printf("%llu\n", sum);
    return 0;
}