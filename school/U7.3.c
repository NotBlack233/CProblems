#include <stdio.h>
#include <stdbool.h>

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}


int main() {
    int x;
    scanf("%d", &x);
    if (x <= 1) puts("error");
    else puts(is_prime(x) ? "YES" : "NO");
    return 0;
}