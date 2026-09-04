#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
using namespace std;

using pii = pair<int, int>;

const int N = 1e5 + 1;

struct Edge {
    int to;
    int dist;
};

int n, m, s;
int dist[N];
list<Edge> edges[N];

void dijkstra() {
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
            if (vis[edge.to]) continue;
            if (dist[edge.to] > dist[point] + edge.dist) {
                dist[edge.to] = dist[point] + edge.dist;
                q.push({-dist[edge.to], edge.to});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int _ = 0; _ < m; _++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}