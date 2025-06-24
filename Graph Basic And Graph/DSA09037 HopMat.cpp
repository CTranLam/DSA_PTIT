#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[10005];
int visited[10005];
int cnt[10005];
void dfs(int u){
    cnt[u]++;
    visited[u]=true;
    for(int x : ke[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    int k,n,m; // k nguoi, n dia diem, m duong 1 chieu
    cin >> k >>n >> m;
    vector<int> people;
    for(int i=0 ; i<k ; i++){
        int x; cin >> x;
        people.push_back(x);
    }
    for(int i=0 ; i<m ; i++){
        int x,y; cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int x : people){
        memset(visited,0,sizeof(visited));
        dfs(x);
    }
    int ans=0;
    for(int i=1 ; i<=n ; i++){
        if(cnt[i]==k){
            ++ans;
        }
    }
    cout << ans << endl;
}