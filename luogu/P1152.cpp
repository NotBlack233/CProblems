#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 1e4 + 1;

bool diff[N] = {};

int main() {
    int n, prev, now, cnt = 0;
    cin >> n;
    if (n == 1) {
        cout << "Not jolly" << endl;
        return 0;
    }
    cin >> prev;
    for (int i = 1; i < n; i++) {
        cin >> now;
        int df = abs(now - prev);
        if (df < 1 || df > n - 1) {
            cout << "Not jolly" << endl;
            return 0;
        }
        if (!diff[df]) {
            diff[df] = true;
            cnt++;
        }
        prev = now;
    }
    cout << (cnt == n - 1 ? "Jolly" : "Not jolly") << endl;
    return 0;
}
