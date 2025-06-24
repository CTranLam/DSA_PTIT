#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<ii> dsk[105];
int visited[105];
int n,s;
struct canh{
    int u,v,w;
};
void Prim(int u){
    int d=0;
    vector<canh> mst;
    visited[u]=1;
    while(mst.size() < n-1){
        int a,b,minw=INT_MAX;
        for(int i=1 ; i<=n ; i++){
            if(visited[i]){
                for(auto it : dsk[i]){
                    int v=it.first,w=it.second;
                    if(!visited[v] && w < minw){
                        minw=w;
                        b=v;
                        a=i;
                    }
                }
            }
        }
        visited[b]=1;
        d+=minw;
        mst.push_back({min(a,b),max(a,b),minw});
    }
    cout << d << endl;
    for(auto x : mst){
        cout << x.u <<" "<<x.v <<" "<<x.w << endl;
    }
}
int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
    cin >> n >> s;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x != 0 && x != 10000){
                dsk[i].push_back({j,x});
            }
        }
    }
    Prim(s);
}