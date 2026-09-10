#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> a;

int main() {
    int n;
    cin >> n;
    a.push_back(false);
    getchar();
    for (int _ = 0; _ < n; _++) {
        char c = getchar();
        a.push_back(c - '0');
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            cnt++;
            for (int j = i; j <= n; j += i) {
                a[j] = a[j] ^ 1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
