#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

struct Node {
    int id, data;
    bool operator<(const Node &other) const {
        return data < other.data;
    }
};

int n, q;
int h[N];
int exp_max;
Node dp[N][22];

void init() {
    for (int i = 1; i <= n; i++)
        dp[i][0] = {i, h[i]};
    for (int exp = 1; exp <= exp_max; exp++) {
        for (int i = 1; i + (1 << exp) - 1 <= n; i++) {
            dp[i][exp] = max(dp[i][exp - 1], dp[i + (1 << (exp - 1))][exp - 1]);
        }
    }
}

Node solve(int l, int r) {
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n;
    exp_max = log2(n);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    init();
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b).id << '\n';
    }
    return 0;
}
