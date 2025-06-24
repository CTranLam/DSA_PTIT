#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t, n;
    // ifstream cin("DT.INP");
    // ofstream cout("DT.OUT");
    cin >> t >> n;

    int deg[105];
    memset(deg, 0, sizeof(deg));

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        deg[i] = c;
        for (int j = 0; j < c; j++) {
            int u; cin >> u;
            adj[i].push_back(u);
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << deg[i] << " ";
        }
    } 
    else if (t == 2) {
        vector<pair<int, int>> edges;
        for (int i = 1; i <= n; i++) {
            for (int u : adj[i]) {
                if (i < u) { 
                    edges.push_back({i, u});
                }
            }
        }

        int m = edges.size();
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++) {
            vector<int> line(m, 0);
            for (int j = 0; j < m; j++) {
                if (edges[j].first == i || edges[j].second == i) {
                    line[j] = 1;
                }
            }
            for (int x : line) cout << x << " ";
            cout << endl;
        }
    }
}