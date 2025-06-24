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
            dsk[v].push_back(u);
        }
        memset(visited,0,sizeof(visited));
        for(int i=1 ; i<=d ; i++){
            sort(dsk[i].begin(),dsk[i].end());
        }
        dfs(u,dsk);
        cout << endl;
    }
}