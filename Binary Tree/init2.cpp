#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
vector<int> adj[MAX];
int depth[MAX];

void bfs(int start, int &maxDepth) {
    queue<int> q;
    q.push(start);
    depth[start] = 0;
    maxDepth = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                maxDepth = max(maxDepth, depth[v]);
                q.push(v);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            depth[i] = -1;
        }

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = 0;
        bfs(1, maxDepth);
        cout << maxDepth << '\n';
    }

    return 0;
}
