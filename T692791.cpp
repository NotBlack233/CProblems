#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

using int128_t = __int128;

struct Rule {
    int type;
    int x, y;

    bool operator<(const Rule &other) const {
        return y < other.y;
    }
};

int128_t in() {
    int128_t k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        k = k * 10 + c - '0', c = getchar();
    return k * f;
}

void out(int128_t x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x < 10)
        putchar(x + '0');
    else
        out(x / 10), putchar(x % 10 + '0');
}

const int N = 5e5 + 10;

int n, k, m;
int maxlen;
int64_t sum[N];
deque<Rule> rules[N];
pair<int, int> range[N];

int64_t sum_cur[N];
int128_t sum_cur_sq[N];
int128_t ans = -1;

void solve(int d, int s) {
    if (d > maxlen) return;
    int64_t minx = INT64_MIN, maxx = INT64_MAX;
    for (auto r : rules[d]) {
        if (!r.type) minx = max(minx, sum_cur[r.x]);
        else maxx = min(maxx, sum_cur[r.x]);
    }
    
    for (int i = s; i <= n; i++) {
        sum_cur[d] = sum[i] - sum[s - 1];
        // TODO check rule
        if (!(minx < sum_cur[d] && sum_cur[d] < maxx)) continue;
        sum_cur_sq[d] = sum_cur_sq[d - 1] + sum_cur[d] * sum_cur[d];
        if (i == n) {
            ans = max(ans, sum_cur_sq[d]);
        }
        
        solve(d + 1, i + 1);
    }
}

int main() {
    cin >> n >> k >> m;
    maxlen = n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        sum[i] = sum[i - 1] + t;
    }
    for (int i = 1; i <= m; i++) {
        Rule tr;
        cin >> tr.x >> tr.y >> tr.type;
        if (tr.x == tr.y) {
            maxlen = min(maxlen, tr.x - 1);
        } else if (tr.x > tr.y) {
            tr.type ^= 1;
            int tmp = tr.x;
            tr.x = tr.y;
            tr.y = tmp;
        }
        if (tr.y <= n) {
            if (tr.type)
                rules[tr.y].push_front(tr);
            else
                rules[tr.y].push_back(tr);
        }
    }
    solve(1, 1);

    out(ans);
    return 0;
}
