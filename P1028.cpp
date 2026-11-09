#include <bits/stdc++.h>
using namespace std;

int dp[510] = {1, 2};

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * 2 <= n; i++) {
        dp[i] = dp[i - 1] + dp[i >> 1];
    }
    cout << dp[n >> 1] << endl;
    return 0;
}
