#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,ul;
vector<int> adj[1005];
bool visited[1005];
vector<int> res;
void dfs(int u){
    visited[u]=true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
bool checkConnect(){
    dfs(1);
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]) return false;
    }
    return true;
}
void Euler(int u){
    while(adj[u].size()){
        int v=adj[u].back();
        adj[u].pop_back();
        auto it=find(adj[v].begin(),adj[v].end(),u);
        if(it != adj[v].end()){
            adj[v].erase(it);
        }
        Euler(v);
    }
    res.push_back(u);
}
int main(){
    ifstream cin ("CT.INP");
    ofstream cout ("CT.OUT");
    cin >> t >> n;
    if(t==2){
        cin >> ul;
    }
    int a[505][505];
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        sort(adj[i].begin(),adj[i].end(),greater<int>());
    }
    if(!checkConnect()){
        cout << 0;
        return 0;
    }
    if(t==1){
        int cntl=0;
        for(int i=1 ; i<=n ; i++){
            if(adj[i].size() %2==1){
                ++cntl;
            }
        }
        if(cntl==0) cout << 1;
        else if(cntl==2) cout << 2;
        else cout << 0 ;
    }
    else{
        Euler(ul);
        reverse(res.begin(),res.end());
        for(int x : res){
            cout << x <<" ";
        }
    }
    cin.close();
    cout.close();
}