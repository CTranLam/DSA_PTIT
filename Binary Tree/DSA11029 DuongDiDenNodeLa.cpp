#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1005];
int parent[1005];
int visited[1005];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : ke[tmp]){
            if(!visited[v]){
                visited[v]=1;
                parent[v]=tmp;
                q.push(v);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1 ; i<=n ; i++){
            visited[i]=0;
            parent[i]=0;
            ke[i].clear();
        }
        for(int i=0 ; i<n-1 ; i++){
            int u,v; cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        bfs(1);
        for(int i=1 ; i<=n ; i++){
            if(ke[i].size()==1 && i != 1){
                int tmp = i;
                vector<int> v;
                while(tmp != 1){
                    v.push_back(tmp);
                    tmp=parent[tmp];
                }
                cout << endl;
                v.push_back(1);
                reverse(v.begin(),v.end());
                for(int x : v){
                    cout << x <<" ";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}