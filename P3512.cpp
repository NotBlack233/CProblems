#include <bits/stdc++.h>
using namespace std;

list<int> maxidx, minidx;
int a[3000010];

int main() {
    int n, k;
    int ans = -1;
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int l = 0, r = 0; r < n; r++) {
        while (!maxidx.empty() && a[maxidx.back()] <= a[r]) {
            maxidx.pop_back();
        }
        maxidx.push_back(r);
        while (!minidx.empty() && a[minidx.back()] >= a[r]) {
            minidx.pop_back();
        }
        minidx.push_back(r);
        
        while (!maxidx.empty() && !minidx.empty() && a[maxidx.front()] - a[minidx.front()] > k) {
            if (maxidx.front() == l) {
                maxidx.pop_front();
            }
            if (minidx.front() == l) {
                minidx.pop_front();
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
