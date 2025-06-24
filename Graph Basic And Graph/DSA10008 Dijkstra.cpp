#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<ii> ke[10005];
int v,e,u;
void dijkstra(int u){
    vector<int> d(v+5,1e9);
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    d[u]=0;
    pq.push({0,u});
    while(!pq.empty()){
        ii tmp=pq.top();
        pq.pop();
        int u=tmp.second,dis=tmp.first;
        if(dis > d[u]) continue; // duong di lay ra khong > duong di san co
        else{
            d[u]=dis;
            // cap nhat lien ke
            for(auto x : ke[u]){
                int v=x.first,w=x.second;
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pq.push({d[v],v}); // thang nao bi thay doi thi push vao
                }
            }
        }
    }
    for(int i=1 ; i<=v ; i++){
        cout << d[i] <<" ";
    }
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e >> u;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
        }
        for(int i=0 ; i< e ; i++){
            int x,y,w;
            cin >> x >> y >> w;
            ke[x].push_back({y,w});
            ke[y].push_back({x,w});
        }
        dijkstra(u);
    }
}