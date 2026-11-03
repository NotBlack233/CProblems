#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}
inline void write(int x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) putchar('-');
    unsigned int u = x < 0 ? 0u - (unsigned int)x : (unsigned int)x;
    char s[12];
    int n = 0;
    while (u) {
        s[n++] = char('0' + u % 10);
        u /= 10;
    }
    while (n) putchar(s[--n]);
}
int main() {
    int n = read(), m = read();
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    while (m--) {
        int q = read();
        auto it = upper_bound(a.begin() + 1, a.end(), q);
        if (*(it - 1) == q) {
            write(it - a.begin() - 1);
            putchar('\n');
        } else {
            puts("-1");
        }
    }
}