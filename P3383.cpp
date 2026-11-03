#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (auto prime : primes) {
            if ((long long)i * prime > n) break;
            is_prime[i * prime] = false;
            if (i % prime == 0) break;
        }
    }
    while (q--) {
        int k;
        cin >> k;
        cout << primes[k - 1] << '\n';
    }
    return 0;
}