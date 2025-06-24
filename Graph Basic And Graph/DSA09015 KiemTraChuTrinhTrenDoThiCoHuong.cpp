#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int deg_in[10005];
int visited[10005];
vector<int> topo;
int v,e;
void dfs(int u){
    visited[u]=1;
    queue<int> q;
    for(int i=1 ; i<=v ; i++){
        if(deg_in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int tmp=q.front(); q.pop();
        topo.push_back(tmp);
        for(int v : ke[tmp]){
            deg_in[v]--;
            if(deg_in[v]==0){
                q.push(v);
            }
        }
    }
    if(topo.size() < v) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            visited[i]=0;
            deg_in[i]=0;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            deg_in[y]++;
        }
        topo.clear();
        dfs(1);
    }   
}