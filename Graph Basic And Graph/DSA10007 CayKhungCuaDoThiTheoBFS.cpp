#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1001];
bool visited[1001];
vector<pair<int, int>> ans;
void BFS(int u) {
	visited[u] = true;
    queue<int> q;
    q.push(u);
	while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : ke[tmp]){
            if(!visited[v]){
                visited[v]=true;
                ans.push_back({tmp,v});
                q.push(v);
            }
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
        memset(visited, false, sizeof(visited));
        ans.clear();
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			ke[a].push_back(b);
			ke[b].push_back(a);
		}
		BFS(k);
		if (ans.size() == n - 1) {
			for(auto x : ans){
                cout << x.first <<" "<<x.second <<endl;
            }
		}
		else cout << -1 << endl;
	}
}