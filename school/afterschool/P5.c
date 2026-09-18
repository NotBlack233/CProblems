#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int m, n;
    bool flag = false;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            flag = true;
        }
    }
    
    if (!flag) printf("no\n");
    return 0;
}