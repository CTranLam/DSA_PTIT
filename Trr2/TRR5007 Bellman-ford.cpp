#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,s,t;
int visited[105];
vector<ii> dsk[105];
int parent[105];
struct canh{
    int u,v,w;
};
int d[105];
vector<canh> dscanh;
bool BellmanFord(int s){
    for(int i=1; i<=n; i++) d[i]=1e9;
    d[s]=0;
    for(int i=1 ; i<=n-1 ; i++){
        for(auto it : dscanh){
            int u=it.u,v=it.v,w=it.w;
            if(d[v] > d[u] + w){
                d[v]=d[u]+w;
                parent[v]=u;
            }
        }
    }
    for(auto it : dscanh){
        int u=it.u,v=it.v,w=it.w;
        if(d[v] > d[u] + w){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BN.INP","r",stdin);
    freopen("BN.OUT","w",stdout);
    cin >> n >> s >> t;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x != 0 && x != 10000){
                dscanh.push_back({i,j,x});
            }
        }
    }
    if(!BellmanFord(s)){
        cout << -1 << endl;
    }
    else{
        if(d[t]==1e9){
            cout << 0 << endl;
        }
        else{
            cout << d[t] << endl;
            int tmp=t;
            vector<int> ans;
            while(true){
                ans.push_back(tmp);
                if(tmp == s) break;
                tmp=parent[tmp];
            }
            reverse(ans.begin(),ans.end());
            for(int x : ans) cout << x << " ";
        }
    }
}