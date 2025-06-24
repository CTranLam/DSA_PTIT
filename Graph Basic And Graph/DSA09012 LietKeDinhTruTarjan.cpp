#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int visited[10005];
int dis[10005],low[10005];
int timer=0;
bool check[10005];
void dfs(int u,int parent){
    visited[u]=1;
    dis[u]=low[u] = ++timer;
    int child=0;
    for(int v : ke[u]){
        if(v == parent){
            continue; // v chinh la cha cua u
        }
        else if(!visited[v]){
            dfs(v,u);
            ++child;
            low[u] = min(low[u],low[v]); // backtrack
            if(parent != -1 && dis[u] <= low[v]){ // khong phai goc va tm yc
                check[u]=true;
            }
        }
        else{
            low[u] = min(low[u],dis[v]);
        }
    }
    if(parent == -1 && child > 1){
        check[u]=true;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e; cin >> v >> e;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            visited[i]=0;
            dis[i]=low[i]=0;
            check[i]=false;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        timer=0;
        for(int i=1 ; i<=v ; i++){
            if(!visited[i]){
                dfs(i,-1);
            }
        }
        for(int i=1 ; i<=v ; i++){
            if(check[i]){
                cout << i <<" ";
            }
        }
        cout << endl;
    }
}