#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

#define int int64_t

using namespace std;

const int N = 4e5 + 1, log2N = log2(N);

struct Warrior {
    int id, l, r;
    bool operator<(const Warrior &other) const { return l < other.l; }
};

Warrior w[2 * N];

int n, m, n2;
int go[N][20];
int res[N];

void init() {
    int next = 1;
    for (int i = 1; i <= n; i++) {
        while (next <= n2 && w[next].l <= w[i].r) next++;
        go[i][0] = next - 1;
    }
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 1; j <= n2; j++) {
            go[j][i] = go[go[j][i - 1]][i - 1];
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        int len = w[i].l + m, cur = i, ans = 1;
        for (int i = log2N; i >= 0; i--) {
            int next = go[cur][i];
            if (next && w[next].r < len) {
                ans += 1 << i;
                cur = next;
            }
        }
        res[w[i].id] = ans + 1;
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        w[i].id = i;
        cin >> w[i].l >> w[i].r;
        if (w[i].r < w[i].l) w[i].r += m;
    }
    sort(w + 1, w + n + 1);
    n2 = n;
    for (int i = 1; i <= n; i++) {
        n2++;
        w[n2] = w[i];
        w[n2].l = w[i].l + m;
        w[n2].r = w[i].r + m;
    }
    init();
    solve();
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}
