#include <cstdint>
#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    map<uint64_t, int> s;
    while (q--) {
        int t, i, j;
        cin >> t >> i >> j;
        if (t == 1) {
            int k;
            cin >> k;
            s[i * 100000ull + j] = k;
        } else {
            cout << s[i * 100000ull + j] << '\n';
        }
    }
    return 0;
}