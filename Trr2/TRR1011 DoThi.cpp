#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;  // u: đỉnh đầu, v: đỉnh cuối, w: trọng số
};

int c[105][105];

int main() {
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t, n, m;
    cin >> t >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                c[i][j] = 0;
            } else {
                c[i][j] = 10000;
            }
        }
    }

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        c[u][v] = w;
        c[v][u] = w;

        edges.push_back({u, v, w});
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int degree = 0;
            for (int j = 1; j <= n; j++) {
                if (c[i][j] != 10000 && i != j && c[i][j] !=0) {
                    degree++;
                }
            }
            cout << degree << " ";
        }
        cout << endl;
    } 
    else if (t == 2) {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }

}