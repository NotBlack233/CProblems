#include <cstdint>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

struct Node {
    uint64_t data;
    uint64_t lazy;
};

int n, m;
Node nodes[5 * N];
uint64_t a[N];

void make_tree(int id, int s, int t) {
    if (s == t) {
        nodes[id].data = a[s];
        return;
    }
    int mid = (s + t) >> 1;
    make_tree(id * 2, s, mid);
    make_tree(id * 2 + 1, mid + 1, t);
    nodes[id].data = nodes[id * 2].data + nodes[id * 2 + 1].data;
}

uint64_t get_sum(int id, int l, int r, int s, int t) {
    if (l <= s && r >= t)
        return nodes[id].data;
    int mid = (s + t) >> 1;
    if (nodes[id].lazy) {
        nodes[id * 2].data += nodes[id].lazy * (mid - s + 1);
        nodes[id * 2 + 1].data += nodes[id].lazy * (t - mid);
        nodes[id * 2].lazy += nodes[id].lazy;
        nodes[id * 2 + 1].lazy += nodes[id].lazy;
        nodes[id].lazy = 0;
    }
    uint64_t sum = 0;
    if (l <= mid)
        sum += get_sum(id * 2, l, r, s, mid);
    if (r > mid)
        sum += get_sum(id * 2 + 1, l, r, mid + 1, t);
    return sum;
}

void update_add(int id, int l, int r, int s, int t, uint64_t k) {
    if (l <= s && r >= t) {
        nodes[id].data += (uint64_t)(t - s + 1) * k;
        nodes[id].lazy += k;
        return;
    }
    int mid = (s + t) >> 1;
    if (nodes[id].lazy && s != t) {
        nodes[id * 2].data += nodes[id].lazy * (mid - s + 1);
        nodes[id * 2 + 1].data += nodes[id].lazy * (t - mid);
        nodes[id * 2].lazy += nodes[id].lazy;
        nodes[id * 2 + 1].lazy += nodes[id].lazy;
        nodes[id].lazy = 0;
    }

    if (l <= mid)
        update_add(id * 2, l, r, s, mid, k);
    if (r > mid)
        update_add(id * 2 + 1, l, r, mid + 1, t, k);
    nodes[id].data = nodes[id * 2].data + nodes[id * 2 + 1].data;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    make_tree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            uint64_t k;
            cin >> k;
            update_add(1, x, y, 1, n, k);
        } else {
            cout << get_sum(1, x, y, 1, n) << '\n';
        }
    }
    return 0;
}
