#include <stdio.h>

const float PI = 3.14f;

int main() {
    float r;
    scanf("%f", &r);
    printf("%.2f\n%.2f\n%.2f\n", PI * 2 * r, PI * r * r, PI * r * r * r * 4 / 3);
    return 0;
}