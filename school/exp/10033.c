#include <stdio.h>

int square(int x) {
    return x * x;
}

char check(int x) {
    if (x % 7 == 0) return 1;
    while (x) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (check(i)) continue;
        sum += square(i);
    }
    printf("%lld\n", sum);
    return 0;
}