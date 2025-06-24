#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,timer;
vector<int> dsk[105];
int dis[105],low[105];
int visited[105];
set<pair<int,int>> se;
void DFS(int u,int parent){
    visited[u]=1;
    dis[u]=low[u]=++timer;
    for(int v : dsk[u]){
        if(v== parent) continue;
        if(!visited[v]){
            DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v] > dis[u]){
                se.insert({u,v});
            }
        }
        else{
            low[u]=min(low[u],dis[v]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("TK.INP");
    ofstream cout("TK.OUT");
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x==1){
                dsk[i].push_back(j);
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            DFS(i,-1);
        }
    }
    cout << se.size() << endl;
    for(auto x : se){
        cout << x.first <<" "<<x.second << endl;
    }
    cin.close();
    cout.close();
}