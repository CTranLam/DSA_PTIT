#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d,c;
bool visited[10005];
void bfs(int u,vector<int> dsk[]){
    visited[u]=true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v=q.front();
        cout << v <<" ";
        q.pop();
        for(int x : dsk[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int u;
        cin >> d >> c >> u;
        vector<int> dsk[10005];
        for(int i=0 ; i<c ; i++){
            int u,v;
            cin >> u >> v;
            dsk[u].push_back(v);
        }
        memset(visited,0,sizeof(visited));
        bfs(u,dsk);
    }
}