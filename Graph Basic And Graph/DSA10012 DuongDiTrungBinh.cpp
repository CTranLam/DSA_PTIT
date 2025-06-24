#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m;
bool check[1001];
vector<int> A[1001];

int BFS(int u, int v) {
	check[u] = true;
	queue<pii> Q;
	Q.push({u, 0});
	while (!Q.empty()) {
		pii tmp = Q.front(); Q.pop();
		if (tmp.first == v) return tmp.second;
		for (int x : A[tmp.first]) {
			if (!check[x]) {
				Q.push({x, tmp.second + 1});
				check[x] = true;
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		// reset
		for (int i = 0; i < 1001; i++) {
			A[i].clear();
			check[i] = false;
		}

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			A[a].push_back(b);
		}

		int res = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				memset(check, false, sizeof(check));
				if (i != j) {
					int f = BFS(i, j);
					if (f != -1) {
						res += f;
						cnt++;
					}
				}
			}
		}
		cout << setprecision(2) << fixed << (res * 1.0 / cnt) << endl;
	}
}
