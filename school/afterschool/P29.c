#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    bool flag = false;
    for (int i = 11; i <= n; i += 10) {
        if (is_prime(i)) {
            printf("%d ", i);
            flag = true;
        }
    }
    if (!flag) {
        puts("-1");
    }
    return 0;
}