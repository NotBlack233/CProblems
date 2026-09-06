#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

const int N = 1e4 + 10;
const uint64_t base = 109;

uint64_t hsh[N];

uint64_t get_hash(string s) {
    uint64_t res;
    for (auto c : s) {
        res = res * base + c;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hsh[i] = get_hash(s);
    }
    sort(hsh, hsh + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && hsh[i] == hsh[i - 1]) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}