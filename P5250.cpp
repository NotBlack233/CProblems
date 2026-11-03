#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int> l;
    int m;
    cin >> m;
    while (m--) {
        int t, a;
        cin >> t >> a;
        if (t == 1) {
            auto it = l.empty() ? l.end() : lower_bound(l.begin(), l.end(), a);
            if (!l.empty() && *it == a) {
                puts("Already Exist");
            } else {
                l.insert(it, a);
            }
        } else {
            if (l.empty()) {
                puts("Empty");
            } else {
                auto nxt = lower_bound(l.begin(), l.end(), a);
                if (*nxt == a || nxt == l.begin()) {
                    cout << *nxt << '\n';
                    l.erase(nxt);
                } else {
                    auto prv = prev(nxt);
                    auto nearest = abs(*prv - a) <= abs(*nxt - a) ? prv : nxt;
                    cout << *nearest << '\n';
                    l.erase(nearest);
                }
            }
        }
    }
    return 0;
}