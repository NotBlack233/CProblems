#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 10;

struct Node {
    int id, prev, next;
} a[N];

int main() {
    int n, m;
    cin >> n >> m;
    int head = 1;
    a[1] = {1, 0, n > 1 ? 2 : 0};
    for (int i = 2; i <= n - 1; i++) {
        a[i] = {i, i - 1, i + 1};
    }
    a[n] = {n, n > 1 ? n - 1 : 0, 0};
    while (m--) {
        int t, x, y;
        cin >> t >> x;
        const int prev = a[x].prev, next = a[x].next;
        a[prev].next = next;
        a[next].prev = prev;
        if (x == head) {
            head = next;
        }

        if (t != 3) {
            cin >> y;
            if (x == y) continue;
            const int yprev = a[y].prev, ynext = a[y].next;
            if (t == 1) {
                a[yprev].next = x;
                a[y].prev = x;
                a[x].prev = yprev;
                a[x].next = y;
                if (y == head) {
                    head = x;
                }
            } else {
                a[ynext].prev = x;
                a[y].next = x;
                a[x].prev = y;
                a[x].next = ynext;
            }
        }
    }
    if (!head) puts("Empty!");
    else {
        for (int cur = head; cur; cur = a[cur].next) {
            printf("%d ", a[cur].id);
        }
    }
    return 0;
}