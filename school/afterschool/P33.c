#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int m, n;
bool vis[20001];

int factor_sum(int x) {
    int sum = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) sum += i + x / i;
        if (sum > n) return -1;
    }
    return sum >= m ? sum : -1;
}

int main() {
    scanf("%d %d", &m, &n);
    bool flag = false;
    for (int i = m; i <= n; i++) {
        int sum = factor_sum(i);
        if (sum != -1 && sum != i && !(vis[sum] && vis[i]) && factor_sum(sum) == i) {
            vis[sum] = vis[i] = true;
            flag = true;
            if (i < sum) printf("%d %d\n", i, sum);
            else printf("%d %d\n", sum, i);
        }
    }
    if (!flag) {
        puts("NONE");
    }
    return 0;
}