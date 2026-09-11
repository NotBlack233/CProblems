#include <cstdint>
#include <cstdio>
#include <iostream>
using namespace std;

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

const int N = 8e4 + 10;

int64_t a[N], d[N], sum_ans[N];
int n, opt, mod, minx, maxx;

int main() {
    n = read();
    opt = read();
    mod = read();
    minx = read();
    maxx = read();
    for (int _ = 0; _ < opt; _++) {
#ifndef __WIN64__
        getchar();
#endif
        char op = getchar();
        int l = read(), r = read();
        if (op == 'A') {
            int x = read();
            d[l] += x;
            d[r + 1] -= x;
        } else {
            int64_t cur = 0, ans = 0;
            for (int i = 1; i < l; i++) cur += d[i];
            for (int i = l; i <= r; i++) {
                cur += d[i];
                int64_t tmp = cur * i % mod;
                if (minx <= tmp && tmp <= maxx) ans++;
            }
            cout << ans << endl;
        }
    }

    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + d[i];
    int64_t sum = 0;
    for (int i = 1; i <= n; i++) {
        int64_t tmp = a[i] * i % mod;
        if (minx <= tmp && tmp <= maxx) sum++;
        sum_ans[i] = sum;
    }

    int final = read();
    for (int _ = 0; _ < final; _++) {
        int l = read(), r = read();
        cout << sum_ans[r] - sum_ans[l - 1] << endl;
    }
    return 0;
}