#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int visited[10005];
void dfs(int u){
    for(int v : ke[u]){
        if(!visited[v]){
            visited[v]=1;
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e;
        cin >> v >> e;
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
        for(int i=1 ; i<=v ; i++){
            if(!visited[i]){
                ++cnt;
                visited[i]=1;
                dfs(i);
            }
        }
        cout << cnt << endl;
    }
}