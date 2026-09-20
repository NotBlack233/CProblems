#include <stdio.h>
#include <stdbool.h>

bool check(int a) {
    int b = a * a;
    int t = a;
    int p = 1;
    while (t) {
        t /= 10;
        p *= 10;
    }
    return ((b - a) % p == 0);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}