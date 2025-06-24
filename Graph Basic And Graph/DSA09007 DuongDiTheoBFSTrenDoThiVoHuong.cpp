#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int parent[10005];
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
                parent[v]=tmp;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e; cin >> v >> e;
        int s,t; cin >> s >> t;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            parent[i]=0;
            visited[i]=0;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        bfs(s);
        if(!visited[t]){
            cout << -1 << endl;
        }
        else{
            int tmp=t;
            vector<int> v;
            while(tmp != s){
                v.push_back(tmp);
                tmp=parent[tmp];
            }
            v.push_back(s);
            for(int i=v.size()-1 ; i>=0 ; i--){
                cout << v[i] <<" ";
            }
            cout << endl;
        }
    }
}