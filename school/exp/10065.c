#include <stdio.h>
#include <stdlib.h>

int droot(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res < 10 ? res : droot(res);
}

int main() {
    int t;
    while (1) {
        scanf("%d", &t);
        if (!t) return 0;
        printf("%d\n", droot(t));
    }
    return 0;
}