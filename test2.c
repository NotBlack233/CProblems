#include <stdio.h>

double mypow(double a, unsigned int b) {
    double res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    printf("1^365 = %lf\n", mypow(1.0, 365));
    printf("1.01^365 = %lf, 0.99^365 = %lf\n", mypow(1.01, 365), mypow(0.99, 365));
    printf("1.02^365 = %lf, 0.98^365 = %lf\n", mypow(1.02, 365), mypow(0.98, 365));
    printf("(1.01^3 * 0.99^2)^73 = %lf\n", mypow(mypow(1.01, 3) * mypow(0.99, 2), 73));
    putchar('\n');
    printf("-1.01^366 = %lf\n", mypow(-1.01, 366));
    return 0;
}
