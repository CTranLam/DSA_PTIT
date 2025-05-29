#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1005];
int parent[1005];
int visited[1005];
void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        for (int v : ke[tmp]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = tmp;
                q.push(v);
            }
        }
    }
}
vector<int> path_to_root(int u) {
    vector<int> path;
    while (u != 0) {
        path.push_back(u);
        u = parent[u];
    }
    return path;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
            parent[i] = 0;
            ke[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }

        bfs(1); 
        int q; cin >> q;
        while (q--) {
            int u, v; cin >> u >> v;
            vector<int> path_u = path_to_root(u);
            vector<int> path_v = path_to_root(v);

            reverse(path_u.begin(), path_u.end());
            reverse(path_v.begin(), path_v.end());
			// tim diem chung gan nhat
            int i = 0;
            while (i < path_u.size() && i < path_v.size() && path_u[i] == path_v[i]) {
                i++;
            }
            int len = (path_u.size() - i) + (path_v.size() - i);
            cout << len << endl;
        }
    }
}
