#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int a = 1; a <= 9; a++) {
        for (int b = a; b <= 9; b++) {
            if ((a * 10 + b) * (b * 10 + a) == n) {
                printf("A=%d,B=%d", a, b);
                return 0;
            }
        }
    }
    printf("No Answer\n");
    return 0;
}