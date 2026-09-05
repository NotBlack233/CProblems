#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 1;

int n, m, x[N];

bool check(int minx) {
    int cnt = 1, prev = 1;
    for (int i = 2; i <= n; i++) {
        if (x[i] - x[prev] >= minx) {
            cnt++;
            prev = i; 
        }
    }
    return cnt >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + n + 1);
    int left = 0, right = x[n] - x[1];
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) left = mid + 1;
        else right = mid;
    }
    cout << left - 1 << endl;
    return 0;
}