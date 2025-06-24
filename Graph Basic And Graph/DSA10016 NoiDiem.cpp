#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<double, double>;
double dis[1000][1000];
bool check[1001];
vector<int> A[1001];
int n;

double distance(pii A, pii B) {
    return sqrt((A.first - B.first) * (A.first - B.first) +
                (A.second - B.second) * (A.second - B.second));
}

struct Edge {
    int u, v;
    double w;
};

vector<Edge> edges;

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void DFS(int u) {
    check[u] = true;
    for (int x : A[u]) {
        if (!check[x]) DFS(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        // Reset
        for (int i = 0; i < 1001; i++) {
            A[i].clear();
            check[i] = false;
        }
        edges.clear();

        cin >> n;
        vector<pii> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = distance(points[i - 1], points[j - 1]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                edges.push_back({i, j, dis[i][j]});
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        double res = 0;
        for (Edge x : edges) {
            memset(check, false, sizeof(check));
            DFS(x.u);
            if (!check[x.v]) {
                res += x.w;
                A[x.u].push_back(x.v);
                A[x.v].push_back(x.u);
            }
        }

        cout << fixed << setprecision(6) << res << endl;
    }

    return 0;
}
