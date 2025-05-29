#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int parent[10005];
int visited[10005];
void dfs(int u){
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v]=u;
            visited[v]=1;
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e,s,t;
        cin >> v >> e >> s >> t;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
        }
        memset(visited,0,sizeof(visited));
        memset(parent,0,sizeof(parent));
        for(int i=0 ; i<e ; i++){
            int u,v;
            cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        dfs(s);
        if(visited[t]==0){
            cout << -1 << endl;
        }
        else{
            vector<int> ans;
            int cur = t;
            while(cur != s){
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(s);

            for(int i=ans.size()-1 ; i>=0 ; i--){
                cout << ans[i] <<" ";
            }
            cout << endl;
        }
    }
}