#include <iostream>
using namespace std;

#define int long long

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

const int N = 1e5 + 10;

struct Info {
    int a, b, c;
};

Info info[N];
int a[N], d[N];
int n, m;

signed main() {
    int ans = 0;
    n = read(), m = read();
    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }
    int prev = read();
    for (int i = 2; i <= m; i++) {
        int cur = read();
        d[min(prev, cur)]++;
        d[max(prev, cur)]--;
        // cout << i << ' ' << min(prev, cur) << ' ' << max(prev, cur) << '\n';
        prev = cur;
    }
    for (int i = 1; i < n; i++)
        info[i].a = read(), info[i].b = read(), info[i].c = read();
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + d[i];
        ans += min(a[i] * info[i].a, a[i] * info[i].b + info[i].c);
    }
    cout << ans << endl;
    return 0;
}
