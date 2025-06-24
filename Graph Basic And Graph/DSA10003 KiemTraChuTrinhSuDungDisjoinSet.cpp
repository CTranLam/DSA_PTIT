#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int parent[10005];
int sz[10005];
int v,e;
void init(){
    for(int i=1 ; i<=v ; i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int u){
    if(u==parent[u]){
        return parent[u];
    }
    return parent[u] = find(parent[u]);
}
bool Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return false; // lam xh chu trinh
    else if(sz[x] < sz[y]){
        parent[x]=y;
        sz[y]+=sz[x];
    }
    else{
        parent[y]=x;
        sz[x]+=sz[y];
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> v >> e;
        init();
        bool check=false;
        for(int i=1; i<=e ; i++){
            int x,y; cin >> x >> y;
            if(!Union(x,y)){
                check=true;
            }
        }
        if(check){
            cout <<"YES" << endl;
        }
        else{
            cout <<"NO" << endl;
        }
    }
}