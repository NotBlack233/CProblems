#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstring>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

using pii = pair<int64_t, int>;

const int N = 1e4 + 1;
// const int64_t INF = 0x7f7f7f7f7f7f7f7f;

struct Edge {
    int to;
    int dist;
};

list<Edge> edges[N];
int cities[N];
int n, m, b;

bool check(int fi_max) {
    if (cities[1] > fi_max) return false;
    int64_t dist[N];
    bool vis[N] = {};
    priority_queue<pii> q;
    memset(dist, 0x7f, sizeof(dist));
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int point = q.top().second;
        q.pop();
        if (vis[point]) continue;
        vis[point] = true;
        for (auto edge : edges[point]) {
            if (vis[edge.to] || cities[edge.to] > fi_max) continue;
            if (dist[edge.to] > dist[point] + edge.dist) {
                dist[edge.to] = dist[point] + edge.dist;
                q.push({-dist[edge.to], edge.to});
            }
        }
    }
    return dist[n] <= b;
}

int main() {
    // freopen("P1462_6.in", "r", stdin);
    // freopen("P1462_2.out", "w", stdout);

    int left = INT_MAX, right = -1;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> cities[i];
        left = min(left, cities[i]);
        right = max(right, cities[i]);
    }
    for (int _ = 1; _ <= m; _++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    // sort(fi + 1, fi + n + 1);
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    if (check(left)) cout << left << endl;
    else cout << "AFK" << endl;
    return 0;
}
