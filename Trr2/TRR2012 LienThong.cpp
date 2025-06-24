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
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        v.push_back(tmp);
        for(int x : dsk[tmp]){
            if(!visited[x]){
                visited[x]=1;
                q.push(x);
            }
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
            bfs(i);
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