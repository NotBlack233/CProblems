#include <stdio.h>

int main() {
    int a, n;
    scanf("%d%d", &a, &n);
    unsigned long long cur = a, ans = 0;
    while (n--) {
        ans += cur;
        cur = cur * 10 + a;
    }
    printf("%llu\n", ans);
    return 0;
}