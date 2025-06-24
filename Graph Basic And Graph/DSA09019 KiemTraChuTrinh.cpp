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
        return u;
    }
    return parent[u]=find(parent[u]);
}
bool Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    else if(sz[x] < sz[y]){
        sz[y] += sz[x];
        parent[x]=y;
    }
    else{
        sz[x] +=sz[y];
        parent[y]=x;
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e;
        bool check=false;
        init();
        for(int i=0 ; i<e ; i++){
            int x,y;
            cin >> x >> y;
            if(!Union(x,y)){
                check=true;
            }
        }
        if(check){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}