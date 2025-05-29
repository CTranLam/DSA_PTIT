#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int tplt[10005];
int visited[10005];
void bfs(int u,int cnt){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        tplt[tmp]=cnt;
        for(int v : ke[tmp]){
            if(!visited[v]){
                q.push(v);
                visited[v]=1;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e;
        cin >> v >> e ;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
        }
        memset(visited,0,sizeof(visited));
        memset(tplt,0,sizeof(tplt));
        for(int i=0 ; i<e ; i++){
            int u,v;
            cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        int cnt=1;
        for(int i=1 ; i<=v ; i++){
            if(!visited[i]){
                bfs(i,cnt);
                cnt++;
            }
        }
        int test; cin >> test;
        while(test--){
            int u,v;
            cin >> u >> v;
            if(tplt[u]==tplt[v]){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
}