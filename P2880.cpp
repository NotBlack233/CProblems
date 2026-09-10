#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

using ipair = pair<int, int>;

const int N = 5e4 + 10;

int n, q;
int h[N];
int exp_max;
ipair dp[N][22];

void init() {
    for (int i = 1; i <= n; i++) dp[i][0].first = dp[i][0].second = h[i];
    for (int exp = 1; exp <= exp_max; exp++) {
        for (int i = 1; i + (1 << exp) - 1 <= n; i++) {
            dp[i][exp].first = min(dp[i][exp - 1].first,
                                    dp[i + (1 << (exp - 1))][exp - 1].first);
            dp[i][exp].second = max(dp[i][exp - 1].second,
                                    dp[i + (1 << (exp - 1))][exp - 1].second);
        }
    }
}

int solve(int l, int r) {
    int k = log2(r - l + 1);
    int minx = min(dp[l][k].first, dp[r - (1 << k) + 1][k].first);
    int maxx = max(dp[l][k].second, dp[r - (1 << k) + 1][k].second);
    return maxx - minx;
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
        cout << solve(a, b) << '\n';
    }
    return 0;
}
