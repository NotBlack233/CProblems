#include <iostream>
#include <deque>
using namespace std;

const int N = 1e6 + 1;

int n, k;
int a[N];

// stores indices
deque<int> q;

void solve(bool ascending) {
    q.clear();
    for (int right = 1; right <= n; right++) {
        while (!q.empty() && ((a[right] > a[q.back()]) ^ ascending)) q.pop_back();
        q.push_back(right);
        if (right >= k) {
            int left = right - k;
            while (!q.empty() && q.front() <= left) q.pop_front();
            cout << a[q.front()] << ' ';
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(true);
    solve(false);
    return 0;
}