#include <bits/stdc++.h>
using namespace std;
int n, u, v;
int a[105][105];
vector<int> dsk[105];
int parent[105];
int visited[105];
bool found = false;
vector<int> ans;
void dfs(int x) {
    if(found) return;
    visited[x] = 1;
    if (x == v) {
        found = true;
        return;
    }
    for (int y : dsk[x]) {
        if (!visited[y]) {
            ans.push_back(y);
            dfs(y);
            if(found) return; // khong quay lui nua
            ans.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    cin >> n >> u >> v;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                dsk[i].push_back(j);
            }
        }
    }
    int cnt=0;
    if (t == 1) {
        for(int x : dsk[u]){
            for(int y : dsk[x]){
                if(y==v){
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    } 
    else {
        ans.push_back(u);
        dfs(u);
        if(!visited[v]){
            cout << 0 << endl;
        }
        else{
            for(int x : ans){
                cout << x << " ";
            }
        }
    }
    return 0;
}
