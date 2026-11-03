#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (auto x : a) {
        auto lb = lower_bound(f.begin(), f.end(), x);
        if (lb == f.end()) f.push_back(x);
        else *lb = x;
    }
    cout << f.size() << endl;
    return 0;
}