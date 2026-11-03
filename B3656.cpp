#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 10;

list<int> l[N];
int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        int a, x;
        cin >> s >> a;
        if (s == "push_back") {
            cin >> x;
            l[a].push_back(x);
        } else if (s == "pop_back" && !l[a].empty()) {
            l[a].pop_back();
        } else if (s == "push_front") {
            cin >> x;
            l[a].push_front(x);
        } else if (s == "pop_front" && !l[a].empty()) {
            l[a].pop_front();
        } else if (s == "size") {
            printf("%d\n", l[a].size());
        } else if (s == "front" && !l[a].empty()) {
            printf("%d\n", l[a].front());
        } else if (s == "back" && !l[a].empty()) {
            printf("%d\n", l[a].back());
        }
    }
    return 0;
}
