#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, q;
int h[N];
int exp_max;
int dp[N][22];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void init() {
    for (int i = 1; i <= n; i++)
        dp[i][0] = h[i];
    for (int exp = 1; exp <= exp_max; exp++) {
        for (int i = 1; i + (1 << exp) - 1 <= n; i++) {
            dp[i][exp] = max(dp[i][exp - 1], dp[i + (1 << (exp - 1))][exp - 1]);
        }
    }
}

int solve(int l, int r) {
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() {
    n = read();
    q = read();
    exp_max = log2(n);
    for (int i = 1; i <= n; i++)
        h[i] = read();
    init();
    for (int i = 0; i < q; i++) {
        int a = read(), b = read();
        cout << solve(a, b) << '\n';
    }
    return 0;
}
