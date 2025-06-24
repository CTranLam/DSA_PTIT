#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int parent[10005];
int visited[10005];
vector<int> ke[10005];
vector<int> ans;
bool dfs(int u){
    visited[u]=1;
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v]=u;
            if(dfs(v)) return true;
        }
        else if(v != parent[u] && v == 1 ){
            ans.push_back(v);
            int tmp=u;
            while(tmp != v){
                ans.push_back(tmp);
                tmp=parent[tmp];
            }
            ans.push_back(v);
            reverse(ans.begin(),ans.end());
            return true;
        }
    }
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=1 ; i<=n ; i++){
            parent[i]=0;
            visited[i]=0;
            ke[i].clear();
        }
        for(int i=1 ; i<=m ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for(int i=1; i<=n; i++){
            sort(ke[i].begin(), ke[i].end());
        }
        ans.clear();
        if(dfs(1)){
            for(int x : ans){
                cout << x <<" ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}