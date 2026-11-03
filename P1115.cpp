#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

constexpr int N = 2e5 + 10;

int a[N];

int main() {
    int n, ans = INT_MIN, cur = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (cur < 0) cur = a[i];
        else cur += a[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}