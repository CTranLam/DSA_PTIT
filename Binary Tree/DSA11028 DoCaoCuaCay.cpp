#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[100005];
int d[100005];
int visited[100005];
void bfs(int root,int& depth){
    queue<int> q;
    q.push(root);
    d[root]=0;
    visited[root]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : ke[tmp]){
            if(!visited[v]){
                visited[v]=1;
                d[v] = d[tmp]+1;
                depth=max(depth,d[v]);
                q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1 ; i<=n ; i++){
            ke[i].clear();
            d[i]=0;
            visited[i]=0;
        }
        for(int i=0 ; i<n-1 ; i++){
            int u,v; cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        int depth=0;
        bfs(1,depth);
        cout << depth << endl;
    }
}