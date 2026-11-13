#include <stdio.h>

typedef struct {
    int a, b;
} res;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

res gcd_lcm(int a, int b) {
    int g = gcd(a, b);
    return (res){g, a * b / g};
}

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    res x = gcd_lcm(a, b), y = gcd_lcm(c, d);
    printf("%d\n%d\n", x.a + y.a, x.b + y.b);
    return 0;
}