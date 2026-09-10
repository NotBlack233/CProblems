#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

uint64_t da, db, dc;
int n, m;
int t[N], b[N];

uint64_t adjust(int d) {
    uint64_t spare = 0, over = 0;
    for (int i = 1; i <= m; i++) {
        if (b[i] < d) spare += d - b[i];
        else over += b[i] - d;
    }
    if (da < db) return min(spare, over) * da + (over - min(spare, over)) * db;
    else return over * db;
}

uint64_t getsum(int d) {
    uint64_t sum = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] < d) sum += (d - t[i]) * dc;
    }
    return sum;
}

int main() {
    cin >> da >> db >> dc >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(t + 1, t + n + 1);
    sort(b + 1, b + m + 1);
    if (dc >= 1e16) {
        cout << adjust(t[1]) << endl;
        return 0;
    }
    uint64_t ans = UINT64_MAX;
    int left = 1, right = N;
    while (right - left > 2) {
        int d = (right - left) / 3;
        int mid1 = left + d;
        int mid2 = right - d;
        uint64_t res1 = adjust(mid1) + getsum(mid1);
        uint64_t res2 = adjust(mid2) + getsum(mid2);
        if (res1 <= res2) right = mid2;
        else left = mid1;
    }
    for (int i = left; i <= right; i++) {
        ans = min(ans, adjust(i) + getsum(i));
    }
    cout << ans << endl;
    return 0;
}
