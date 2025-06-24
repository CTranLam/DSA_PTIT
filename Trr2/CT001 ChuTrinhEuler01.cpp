#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,ul;
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

void findEuler(int x){
    while(!adj[x].empty()){
        int y=adj[x].back();
        adj[x].pop_back(); // xoa canh xy
        auto it=find(adj[y].begin(),adj[y].end(),x);
        if(it != adj[y].end()){
            // xoa yx
            adj[y].erase(it);
        }
        findEuler(y);
    }
    res.push_back(x);
}
int main(){
    cin >> t >> n >> m;
    if(t==2){
        cin >> ul;
    }
    int a[505][505];
    memset(a, 0, sizeof(a));
    for(int i=0 ; i<m ; i++){
        int x,y;
        cin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
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
        if(cntl==0){
            cout << 1;
            return 0;
        }
        else if(cntl==2){
            cout << 2;
            return 0;
        }
        else{
            cout << 0 ;
            return 0;
        }
    }
    else{
        findEuler(ul);
        reverse(res.begin(),res.end());
        for(int x : res){
            cout << x <<" ";
        }
    }
}