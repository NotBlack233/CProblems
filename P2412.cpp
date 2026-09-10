#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int n, q;
string h[N];
int exp_max;
string dp[N][22];

char lower(char c) {
    if (c >= 'A' && c <= 'Z') return c - ('A' - 'a');
    return c;
}

string &str_max(string &a, string &b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        char ca = lower(a[i]), cb = lower(b[i]);
        if (ca < cb) return b;
        if (ca > cb) return a;
    }
    if (a.size() < b.size()) return a;
    return b;
}

void init() {
    for (int i = 1; i <= n; i++)
        dp[i][0] = h[i];
    for (int exp = 1; exp <= exp_max; exp++) {
        for (int i = 1; i + (1 << exp) - 1 <= n; i++) {
            dp[i][exp] = str_max(dp[i][exp - 1], dp[i + (1 << (exp - 1))][exp - 1]);
        }
    }
}

string &solve(int l, int r) {
    int k = log2(r - l + 1);
    return str_max(dp[l][k], dp[r - (1 << k) + 1][k]);
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
