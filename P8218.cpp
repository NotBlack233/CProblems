#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[i] = a[i - 1] + t;
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << (a[r] - a[l - 1]) << '\n';
    }
    return 0;
}