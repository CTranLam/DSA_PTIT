#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[100005];
int visited[100005];
int cnt;
void dfs(int u){
    visited[u]=1;
    for(int v : ke[u]){
        if(!visited[v]){
            ++cnt;
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=1 ; i<=n ; i++){
            ke[i].clear();
            visited[i]=0;
        }
        for(int i=0 ; i<m ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        // kiem tra xem phai do thi day du khong
        int ans=0;
        for(int i=1 ; i<=n ; i++){
            cnt=1; // dem so dinh trong 1 tplt
            if(!visited[i]){
                dfs(i);
                ans += cnt*(cnt-1)/2;
            }
        }
        if(ans==m){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}