#include <iostream>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    int avg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - avg != 0) {
            a[i + 1] += a[i] - avg;
            a[i] = avg;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}