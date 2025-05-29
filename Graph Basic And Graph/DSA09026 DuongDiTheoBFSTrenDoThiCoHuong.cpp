#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int parent[10005];
int visited[10005];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u];
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : ke[tmp]){
            if(!visited[v]){
                q.push(v);
                visited[v]=1;
                parent[v]=tmp;
            }
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
        }
        bfs(s);
        if(visited[t]==0){
            cout << -1 << endl;
        }
        else{
            vector<int> ans;
            while(t != s){
                ans.push_back(t);
                t=parent[t];
            }
            ans.push_back(s);
            for(int i=ans.size()-1 ; i>=0 ; i--){
                cout << ans[i] <<" ";
            }
            cout << endl;
        }
    }
}