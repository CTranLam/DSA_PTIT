#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int c[105][105];

int main() {
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");

    int t, n, m;
    cin >> t >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 10000;
        }
    }

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        c[u][v] = w;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int deg_in = 0, deg_out = 0;
            for (int j = 1; j <= n; j++) {
                if (c[i][j] != 10000 && i != j) deg_out++;
                if (c[j][i] != 10000 && i != j) deg_in++;
            }
            cout << deg_in << " " << deg_out << endl;
        }
    } 
    else if (t == 2) {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) c[i][j] = 0;
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
