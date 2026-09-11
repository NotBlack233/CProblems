#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;

int main() {
    cin >> n;
    int64_t prev;
    cin >> prev;
    int64_t pos = 0, neg = 0;
    for (int i = 2; i <= n; i++) {
        int64_t t;
        cin >> t;
        int64_t d = t - prev;
        if (d > 0) pos += d;
        else neg -= d;
        prev = t;
    }
    cout << max(pos, neg) << '\n' << abs(pos - neg) + 1 << endl;
    return 0;
}