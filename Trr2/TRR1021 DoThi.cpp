#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int c[105][105];

int main() {
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");

    int t, n;
    cin >> t >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int deg_in = 0, deg_out = 0;
            for (int j = 1; j <= n; j++) {
                if (c[i][j] != 10000 && i != j) {
                    deg_out++;
                }
                if (c[j][i] != 10000 && i != j) {
                    deg_in++;
                }
            }
            cout << deg_in << " " << deg_out << endl;
        }
    } 
    else if (t == 2) {
        vector<Edge> edges;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] != 10000 && i != j) {
                    edges.push_back({i, j, c[i][j]});
                }
            }
        }

        cout << n << " " << edges.size() << endl;

        for (auto& edge : edges) {
            cout << edge.u << " " << edge.v << " " << edge.w << endl;
        }
    }

    return 0;
}
