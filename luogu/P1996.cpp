#include <iostream>
using namespace std;

int nxt[101];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        nxt[i] = i + 1;
    }
    nxt[n] = 1;
    int cur = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        for (int i = 1; i < m; i++) {
            cur = nxt[cur];
        }
        int out = nxt[cur];
        nxt[cur] = nxt[out];
        cout << out << ' ';
    }
    return 0;
}
