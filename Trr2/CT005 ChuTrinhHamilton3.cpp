#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ul;
int a[105][105];
vector<int> dsk[105];
vector<vector<int>> ans;
int visited[105];
void Hamilton(int u,vector<int>& res){
    for(int v : dsk[u]){
        if(!visited[v]){
            visited[v]=1;
            res.push_back(v);
            if(v==ul && res.size() == n+1){
                ans.push_back(res);
            }
            else Hamilton(v,res);
            visited[v]=0;
            res.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n>> m >> ul;
    for(int i=1 ; i<=m ; i++){
        int x,y; cin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(a[i][j]==1){
                dsk[i].push_back(j);
            }
        }
    }
    vector<int> res;
    res.push_back(ul);
    Hamilton(ul,res);
    cout << ans.size() << endl;
    if(ans.size() > 0){
        for(auto v : ans){
            for(int x : v) cout << x << " ";
            cout << endl;
        }
    }
}