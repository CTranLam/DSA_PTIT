#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int visited[10005];
void bfs(int u){
    visited[u]=1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : ke[tmp]){
            if(!visited[v]){
                visited[v]=1;
                q.push(v);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e; cin >> v >> e;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            visited[i]=0;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int cnt=0;
        for(int i=1 ; i<=v; i++){
            if(!visited[i]){
                ++cnt;
                bfs(i);
            }
        }
        cout << cnt << endl;
    }
}