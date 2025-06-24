#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int parent[100005];
int sz[100005];
int max_size=1;
void init(){
    for(int i=1 ; i<= n ; i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u]= find(parent[u]);
}
void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        // cung 1 tap hon
        return;
    }
    else if(sz[x] < sz[y]){
        parent[x]=y;
        sz[y]+=sz[x];
        max_size = max(max_size,sz[y]);
    }
    else{
        parent[y]=x;
        sz[x]+=sz[y];
        max_size = max(max_size,sz[x]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        max_size=1;
        init();
        for(int i=0 ; i<m ; i++){
            int x,y; cin >> x >> y;
            Union(x,y);
        }
        cout << max_size << endl;
    }
}