#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 1e6 + 10;

struct Order {
    int s;
    int t;
    int64_t d;
};

int n, m;
int64_t diff_orig[MX]; // `a[i] + diff[i + 1] == a[i + 1]`
Order orders[MX];

bool check(int maxx) {
    auto diff = new int64_t[MX]; // stack overflow
    memcpy(diff + 1, diff_orig + 1, n * sizeof(int64_t));
    for (int i = 1; i <= maxx; i++) {
        diff[orders[i].s] -= orders[i].d;
        diff[orders[i].t + 1] += orders[i].d;
    }
    int64_t cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        if (cur < 0)
            return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("P1083_8.in", "r", stdin);
#endif

    cin >> n >> m;
    int64_t prev = 0, cur;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        diff_orig[i] = cur - prev;
        prev = cur;
    }
    for (int i = 1; i <= m; i++) {
        cin >> orders[i].d >> orders[i].s >> orders[i].t;
    }
    if (check(n)) {
        cout << 0 << endl;
        return 0;
    }
    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid))
            left = mid + 1;
        else
            right = mid;
    }
    cout << -1 << '\n' << left << endl;
    return 0;
}
