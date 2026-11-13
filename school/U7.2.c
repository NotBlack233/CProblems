#include <math.h>
#include <stdio.h>

void delta_gt(double a, double b, double d) {
    printf("%.2lf %.2lf\n", (-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
}

void delta_eq(double a, double b, double d) {
    printf("%.2lf\n", -b / (2 * a));
}

void delta_lt(double a, double b, double d) {
    double real = -b / (2 * a);
    double imag = sqrt(-d) / (2 * a);
    imag = fabs(imag);
    printf("%.2lf%.2lfi %.2lf+%.2lfi\n", real, -imag, real, imag);
}

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double delta = b * b - 4 * a * c;
    if (fabs(delta) < 1e-6) {
        delta_eq(a, b, delta);
    } else if (delta > 0) {
        delta_gt(a, b, delta);
    } else {
        delta_lt(a, b, delta);
    }
    return 0;
}