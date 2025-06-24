#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v,e,m;
vector<int> ke[105];
int color[105];
bool check(int u,int c){
    for(int v : ke[u]){
        if(color[v]==c) return false;
    }
    return true;
}
bool solve(int u){
    if(u > v) return true; // duyet het
    for(int i=1 ; i<=m ; i++){
        if(check(u,i)){
            color[u]=i;
            if(solve(u+1)) return true;
            color[u]=0;
        }
    }
    return false;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e >> m;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            color[i]=0;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        if(solve(1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}