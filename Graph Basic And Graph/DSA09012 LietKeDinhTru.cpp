#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
bool visited[10005];
void dfs(int u){
    visited[u]=true;
    for(int v : ke[u]){
        if(!visited[v]){
            visited[v]=true;
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e; cin >> v >> e;
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        vector<int> ans;
        for(int i=1 ; i<=v ; i++){
            memset(visited,false,sizeof(visited));
            visited[i]=true;
            int cnt=0;
            for(int j=1 ; j<=v ; j++){
                if(i != j && !visited[j]){
                    ++cnt;
                    dfs(j);
                }
            }
            if(cnt > 1) ans.push_back(i);
        }
        for(int x : ans){
            cout << x <<" ";
        }
        cout << endl;
    }
}