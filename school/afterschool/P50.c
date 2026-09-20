#include <stdio.h>

int solve(int sum, int n) {
    if (n == 1) {
        return (sum + 1) * 2;
    }
    return solve((sum + 1) * 2, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(1, n - 1));
    return 0;
}