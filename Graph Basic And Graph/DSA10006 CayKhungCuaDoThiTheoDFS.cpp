#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1001];
bool check[1001];
vector<pair<int, int>> ans;
void DFS(int u) {
	check[u] = true;
	for (int x : ke[u]) {
		if (!check[x]) {
			ans.push_back({ u,x });
			DFS(x);
		}
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            ke[i].clear();
        }
        memset(check, false, sizeof(check));
        ans.clear();
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			ke[a].push_back(b);
			ke[b].push_back(a);
		}
		DFS(k);
		if (ans.size() == n - 1) {
			for(auto x : ans){
                cout << x.first <<" "<<x.second <<endl;
            }
		}
		else cout << -1 << endl;
	}
}