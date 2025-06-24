#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v,e;
int parent[10005];
int sz[10005];
struct canh{
    int dau,cuoi;
    int trongso;
};
void init(){
    for(int i=1 ; i<=v ; i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}
bool Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return false;
    }
    if(sz[x] < sz[y]){
        parent[x]=y;
        sz[y]+=sz[x];
    }
    else{
        parent[y]=x;
        sz[x]+=sz[y];
    }
    return true;
}
vector<canh> dsc;
vector<canh> ans;
bool cmp(canh x,canh y){
    return x.trongso < y.trongso;
}
void kruskal(){
    sort(dsc.begin(),dsc.end(),cmp);
    ll d=0;
    for(auto x : dsc){
        int a=x.dau,b=x.cuoi,c=x.trongso;
        if(Union(a,b)){
            d+=c;
            ans.push_back(x);
        }
        if(ans.size() == v-1){
            break;
        }
    }
    if(ans.size() == v-1){
        cout << d << endl;
    }
    else cout << -1 << endl;
} 
int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e;
        dsc.clear();
        ans.clear();
        init();
        for(int i=0 ; i<e ; i++){
            int a,b,c;
            cin >> a >> b >> c;
            dsc.push_back({a,b,c});
        }
        if(e==1){
            cout << dsc[0].trongso << endl;
        }
        else kruskal();
    }
}