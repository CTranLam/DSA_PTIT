#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d,c;
int visited[10005];
void dfs(int u,vector<int> dsk[]){
    cout << u <<" ";
    visited[u]=1;
    for(int x : dsk[u]){
        if(visited[x]==0){
            dfs(x,dsk);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int u;
        cin >> d >> c >> u;
        vector<int> dsk[10005];
        for(int i=0 ; i<c ; i++){
            int u,v;
            cin >> u >> v;
            dsk[u].push_back(v);
        }
        memset(visited,0,sizeof(visited));
        dfs(u,dsk);
        cout << endl;
    }
}