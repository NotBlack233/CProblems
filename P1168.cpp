#include <bits/stdc++.h>
using namespace std;

void balance(priority_queue<int> &h1, priority_queue<int, vector<int>, greater<int>> &h2, int &mid) {
    while (h1.size() != h2.size()) {
        if (h1.size() < h2.size()) {
            int t = h2.top();
            h2.pop();
            h1.push(mid);
            mid = t;
        } else {
            int t = h1.top();
            h1.pop();
            h2.push(mid);
            mid = t;
        }
    }
}

int main() {
    int n;
    cin >> n;
    priority_queue<int> h1;
    priority_queue<int, vector<int>, greater<int>> h2;
    if (!n) return 0;
    int t, mid;
    cin >> t;
    cout << t << '\n';
    mid = t;
    for (int i = 3; i <= n; i += 2) {
        int a, b;
        cin >> a >> b;
        if (a < mid) {
            h1.push(a);
        } else {
            h2.push(a);
        }
        if (b < mid) {
            h1.push(b);
        } else {
            h2.push(b);
        }
        balance(h1, h2, mid);
        cout << mid << '\n';
    }
    return 0;
}