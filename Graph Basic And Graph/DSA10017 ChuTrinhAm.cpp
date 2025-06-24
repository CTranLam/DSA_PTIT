#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int V, E;
vector<Edge> edges;

bool hasNegativeCycle() {
    // Thêm 1 đỉnh ảo là 0 nối với tất cả các đỉnh thật
    vector<int> dist(V + 1, 1e9);
    dist[0] = 0;
    
    // Nối đỉnh ảo 0 với các đỉnh từ 1 đến V trọng số 0
    for (int i = 1; i <= V; i++) {
        edges.push_back({0, i, 0});
    }

    // Bellman-Ford từ đỉnh 0
    for (int i = 0; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] < 1e9 && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    for (auto e : edges) {
        if (dist[e.u] < 1e9 && dist[e.v] > dist[e.u] + e.w) {
            return true;
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        edges.clear();

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        cout << (hasNegativeCycle() ? 1 : 0) << endl;
    }

    return 0;
}
