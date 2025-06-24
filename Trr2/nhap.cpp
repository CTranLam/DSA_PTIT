#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<ii> dsk[105];
int visited[105];
int n,s;
void Prim(int s){
    int d=0;
    visited[s]=1;
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    for(ii it : dsk[s]){
        if(!visited[it.first]){
            pq.push({{it.second,it.first},s});
        }
    }
    vector<iii> ans;
    while(!pq.empty()){
        auto p= pq.top();
        pq.pop();
        int u=p.second,v=p.first.second,w=p.first.first;
        if(visited[v]) continue;
        d+=w;
        visited[v]=1;
        ans.push_back({{u,v},w});
        for(auto x : dsk[v]){
            if(!visited[x.first]){
                pq.push({{x.second,x.first},v});
            }
        }
    }
    cout << d << endl;
    for(auto x : ans){
        cout << min(x.first.first,x.first.second) <<" "<<max(x.first.first,x.first.second) <<" "<<x.second << endl;
    }
}
int main(){
    // freopen("CK.INP","r",stdin);
    // freopen("CK.OUT","w",stdout);
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