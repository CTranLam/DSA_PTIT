#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105][105];
vector<int> dsk[105];
int visited[105];
int cnt=0;
vector<vector<int>> ans;
vector<int> v;
void dfs(int u){
    v.push_back(u);
    visited[u]=1;
    for(int x : dsk[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    ifstream cin("TK.INP");
    ofstream cout("TK.OUT");
    cin >> n;
    for(int i=1 ;i <= n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                dsk[i].push_back(j);
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            dfs(i);
            ans.push_back(v);
            v.clear();
        }
    }
    cout << ans.size() <<  endl;
    for(auto v : ans){
        sort(v.begin(),v.end());
        for(int x : v){
            cout << x <<" ";
        }
        cout << endl;
    }
    cin.close();
    cout.close();
}