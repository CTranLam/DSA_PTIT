#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int sz[1005],parent[1005];
struct canh{
    int a,b;
    int value;
};
vector<canh> dscanh;
void init(){
    for(int i=1 ; i<=n ; i++){
        sz[i]=1;
        parent[i]=i;
    }
}
int find(int u){
    if(u==parent[u]) return u;
    else{
        return parent[u]=find(parent[u]);
    }
}
bool Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    else{
        if(sz[x] <= sz[y]){
            sz[y]+=sz[x];
            parent[x]=y;
        }
        else{
            sz[x]+=sz[y];
            parent[y]=x;
        }
    }
    return true;
}
bool cmp(canh x,canh y){
    if(x.value != y.value) return x.value < y.value;
    else{
        if(x.a != y.a) return x.a < y.a;
        else return x.b < y.b;
    }
}
void Kruskal(){
    ll ans=0;
    vector<canh> res;
    for(canh x : dscanh){
        int a=x.a,b=x.b,c=x.value;
        if(Union(a,b)){
            res.push_back(x);
            ans+=c;
        }
        if(res.size() == n-1) break;
    }
    if(res.size()==n-1){
        cout << ans << endl;
        for(canh x : res){
            cout << min(x.a,x.b) <<" "<<max(x.a,x.b) <<" "<<x.value << endl;
        }
    }
    else cout << 0 << endl;
}
int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int a,b,c;
        cin >> a >> b >> c;
        dscanh.push_back({a,b,c});
    }
    sort(dscanh.begin(),dscanh.end(),cmp);
    init();
    Kruskal();
}