#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        switch (t) {
        case 1:
            int x;
            cin >> x;
            q.push(x);
            break;
        case 2:
            if (!q.empty()) q.pop();
            else puts("ERR_CANNOT_POP");
            break;
        case 3:
            if (!q.empty()) cout << q.front() << '\n';
            else puts("ERR_CANNOT_QUERY");
            break;
        case 4:
            cout << q.size() << '\n';
            break;
        }
    }
    return 0;
}
