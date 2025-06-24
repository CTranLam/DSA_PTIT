#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int visited[10005];
int parent[10005];
bool dfs(int u){
    visited[u]=true;
    for(int v : ke[u]){
        if(visited[v] && v != parent[u]){
            return true;
        }
        else if(!visited[v]){
            parent[v]=u;
            if(dfs(v)) return true;
        }
    }
    return false;
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e; cin >> v >> e;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            visited[i]=0;
            parent[i]=0;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        bool check=true;
        for(int i=1 ; i<=v ; i++){
            if(!visited[i]){
                if(dfs(i)){
                    check=false;
                    cout << "YES" << endl;
                    break;
                }
            }
        }
        if(check) cout << "NO" << endl;
    }
}