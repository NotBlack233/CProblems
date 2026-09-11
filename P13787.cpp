#include <cstdint>
#include <iostream>
using namespace std;

const int N = 5010;
int a[N][N];
int diff[N][N];
int n, m;

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

int main() {
    n = read(), m = read();
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        x1 = read(), y1 = read(), x2 = read(), y2 = read();
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }
    uint64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + diff[i][j];
            ans += (i + j) ^ a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
