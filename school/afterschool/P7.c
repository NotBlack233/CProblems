#include <stdio.h>

int gcd(int a, int b) {
    if (a % b == 0) return b;
    if (a < b) return gcd(b, a);
    return gcd(b, a % b);
}

int main() {
    int nume, denom;
    scanf("%d %d", &nume, &denom);
    int g = gcd(nume, denom);
    printf("%d %d\n", nume / g, denom / g);
    return 0;
}