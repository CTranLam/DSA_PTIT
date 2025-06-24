#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,s,t;
int visited[105];
vector<ii> dsk[105];
int parent[105];
void Dijkstra(int s){
    vector<int> d(n+5,1e9);
    d[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        ii p=pq.top();
        pq.pop();
        int u=p.second,dis=p.first;
        if(dis > d[u]) continue;
        d[u]=dis;
        for(ii it : dsk[u]){
            int v=it.first, w=it.second;
            if(d[v] > d[u] + w){
                d[v]=d[u]+w;
                parent[v]=u;
                pq.push({d[v],v});
            }
        }
    }
    if(d[t]==1e9){
        cout << 0 << endl;
        return;
    }
    cout << d[t] << endl;
    int tmp=t;
    vector<int> ans;
    while(tmp != s){
        ans.push_back(tmp);
        tmp=parent[tmp];
    }
    ans.push_back(s);
    reverse(ans.begin(),ans.end());
    for(int x : ans) cout << x <<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
    cin >> n >> s >> t;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x != 0 && x != 10000){
                dsk[i].push_back({j,x});
            }
        }
    }
    Dijkstra(s);
}