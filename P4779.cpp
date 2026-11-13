#include <bits/stdc++.h>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int to, w;
};
struct point {
    int dist, id;

    bool operator<(const point &other) const {
        return dist > other.dist;
    }
};

constexpr int N = 1e5 + 10;

bool vis[N];
int dist[N];
list<edge> edges[N];
priority_queue<point> q;
int n, m, s;

void dijkstra() {
    q.push({0, s});
    while (!q.empty()) {
        int point = q.top().id;
        q.pop();
        if (vis[point]) continue;
        vis[point] = true;
        for (auto e: edges[point]) {
            if (vis[e.to]) continue;
            if (dist[e.to] > dist[point] + e.w) {
                dist[e.to] = dist[point] + e.w;
                q.push({dist[e.to], e.to});
            }
        }
    }
}

int main() {
    memset(dist, 0x7f, sizeof(dist));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    dist[s] = 0;
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}