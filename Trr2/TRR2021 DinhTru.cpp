#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,timer;
vector<int> dsk[105];
int visited[105];
int AP[105]; // danh dau dinh tru
int dis[105],low[105];
int cnt=0; // dem so luong dinh tru
void DFS(int u,int parent){
    visited[u]=1;
    dis[u]=low[u]=++timer;
    int child=0;
    for(int v : dsk[u]){
        if(v==parent) continue;
        if(!visited[v]){
            DFS(v,u);
            ++child;
            low[u]=min(low[u],low[v]);
            if(parent != -1 && low[v] >= dis[u]){
                if(!AP[u]){
                    ++cnt;
                    AP[u]=1;
                }
            }
        }
        else{
            low[u]=min(low[u],dis[v]);
        }
    }
    if(parent == -1 && child >=2){
        if(!AP[u]){
            ++cnt;
            AP[u]=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ifstream cin ("TK.INP");
    ofstream cout ("TK.OUT");
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x==1){
                dsk[i].push_back(j);
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        sort(dsk[i].begin(),dsk[i].end());
    }
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            DFS(i,-1);
        }
    }
    cout << cnt << endl;
    for(int i=1 ; i<=n ; i++){
        if(AP[i]){
            cout << i << " ";
        }
    }
    cin.close();
    cout.close();
}