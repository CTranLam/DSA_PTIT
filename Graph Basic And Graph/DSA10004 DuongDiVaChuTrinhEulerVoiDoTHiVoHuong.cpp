#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
vector<int> dsk[10005];
int visited[10005];
void dfs(int u){
    visited[u]=1;
    for(int v : dsk[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int check_bacle(int v){
    int cnt=0;
    for(int i=1 ; i<=v ; i++){
        if(dsk[i].size() % 2==1) ++cnt;
    }
    return cnt;
}
bool check_lt(int v){
    int cnt=0;
    for(int i=1 ; i<=v ; i++){
        if(!visited[i]){
            ++cnt;
            dfs(i);
        }
    }
    if(cnt > 1) return false;
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,u; cin >> v >> u; // v dinh, u canh
        for(int i=1 ; i<=v ; i++){
            dsk[i].clear();
            visited[i]=0;
        }
        for(int i=0 ; i<u ; i++){
            int x,y; cin >> x >> y;
            dsk[x].push_back(y);
            dsk[y].push_back(x);
        }
        dfs(v);
        if(!check_lt(v)){
            cout << 0 << endl;
        }
        else{
            if(check_bacle(v)==0) cout << 2 << endl;
            else if(check_bacle(v) == 2) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}