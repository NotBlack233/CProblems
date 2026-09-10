#include <iostream>
#include <vector>
using namespace std;

vector<bool> a(1001, false);

int main() {
    int n, n1 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (!a[t]) {
            a[t] = true;
            n1++;
        }
    }
    cout << n1 << '\n';
    for (int i = 1; i <= 1000; i++) {
        if (a[i]) cout << i << ' ';
    }
    cout << endl;
    return 0;
}