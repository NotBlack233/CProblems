#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    bool printed = false;
    for (int i = n; i >= 0; i--) {
        int t;
        cin >> t;
        if (t == 0) continue;
        else if (t > 0 && i != n && printed) cout << '+';
        
        printed = true;
        if (t == -1 && i != 0) cout << '-';
        else if (t != 1 || i == 0) cout << t;

        if (i == 1) cout << 'x';
        else if (i != 0) cout << "x^" << i;
    }
    if (!printed) cout << 0;
    return 0;
}