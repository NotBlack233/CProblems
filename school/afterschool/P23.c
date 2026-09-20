#include <stdio.h>
#include <stdbool.h>

bool check(const int x) {
    if (x == 1) return false;
    int t = 0;
    for (int i = 2; i * i <= x; i++) {
        if (t + 1 > x) return false;
        if (x % i == 0) t += i + x / i;
    }
    return t + 1 == x;
}

int main() {
    bool flag = false;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; i++) {
        if (check(i)) {
            printf("%d ", i);
            flag = true;
        }
    }
    if (!flag) puts("No Answer\n");
    return 0;
}