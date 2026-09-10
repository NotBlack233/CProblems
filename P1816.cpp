#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, q;
int h[N];
int exp_max;
int dp[N][22];

void init() {
    for (int i = 1; i <= n; i++)
        dp[i][0] = h[i];
    for (int exp = 1; exp <= exp_max; exp++) {
        for (int i = 1; i + (1 << exp) - 1 <= n; i++) {
            dp[i][exp] = min(dp[i][exp - 1], dp[i + (1 << (exp - 1))][exp - 1]);
        }
    }
}

int solve(int l, int r) {
    int k = log2(r - l + 1);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n >> q;
    exp_max = log2(n);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    init();
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << ' ';
    }
    return 0;
}
