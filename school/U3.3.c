#include <stdio.h>
#include <math.h>

int main() {
    float r;
    int n;
    scanf("%f %d", &r, &n);
    printf("%.2f", powf(1.0 + r, n));
    return 0;
}