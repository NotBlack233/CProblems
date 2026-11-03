#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1010;
list<int> edges[N];
int levels[N], in[N];
bool graph[N][N];
int max_level = 0;

void traverse(list<int> &s) {
    while (!s.empty()) {
        int sta = s.front();
        s.pop_front();
        for (int a: edges[sta]) {
            in[a]--;
            if (in[a] == 0) {
                levels[a] = levels[sta] + 1;
                s.push_back(a);
                max_level = max(max_level, levels[a]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int s;
        cin >> s;
        vector<int> sta(s);
        for (int i = 0; i < s; i++) {
            cin >> sta[i];
        }
        for (int i = sta.front() + 1; i < sta.back(); i++) {
            auto it = lower_bound(sta.begin(), sta.end(), i);
            if (it == sta.end() || *it == i) continue;
            for (int st: sta) {
                
                // cout << i << ' ' << st << '\n';
                if (!graph[i][st]) in[st]++;
                graph[i][st] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j]) {
                edges[i].push_back(j);
                // cout << i << ' ' << j << '\n';
            }
        }
    }
    
    list<int> nodes;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            levels[i] = 1;
            nodes.push_back(i);
        }
    }
    traverse(nodes);
    cout << max_level << endl;
    return 0;
}