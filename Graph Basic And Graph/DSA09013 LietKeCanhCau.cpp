#include <bits/stdc++.h>
using namespace std;

vector<int> ke[10005];
int visited[10005];
int dis[10005], low[10005];
int timer = 0;
vector<pair<int, int>> canhcau;

void dfs(int u, int parent) {
    visited[u] = 1;
    dis[u] = low[u] = ++timer;
    for (int v : ke[u]) {
        if (v == parent) continue;
        if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (dis[u] < low[v]) {
                if (u < v) canhcau.push_back({u, v});
                else canhcau.push_back({v, u});
            }
        } else {
            low[u] = min(low[u], dis[v]);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; i++) {
            ke[i].clear();
            visited[i] = 0;
            dis[i] = low[i] = 0;
        }
        for (int i = 0; i < e; i++) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        timer = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
        sort(canhcau.begin(), canhcau.end());
        for (auto x : canhcau) {
            cout << x.first << " " << x.second << " ";
        }
        cout << endl;
        canhcau.clear();
    }
}