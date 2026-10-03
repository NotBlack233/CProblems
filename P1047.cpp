#include <iostream>
using namespace std;

const int N = 1e4 + 10;

int rem[N];

int main() {
    int l, m;
    cin >> l >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        rem[u]++;
        rem[v + 1]--;
    }
    int remc = 0, ans = 0;
    for (int i = 0; i <= l; i++) {
        remc += rem[i];
        if (remc <= 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
