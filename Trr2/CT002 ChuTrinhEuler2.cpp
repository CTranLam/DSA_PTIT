#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,ul;
int a[105][105];
vector<int> dsk[105];
int visited[105];
void dfs(int u){
    visited[u]=1;
    for(int v : dsk[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
bool checkConnect(){
    dfs(1);
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]) return false;
    }
    return true;
}
vector<int> ans; // luu thu tu nguoc cua chu trinh euler
void Euler(int x){
    while(!dsk[x].empty()){
        int y=dsk[x].back();
        dsk[x].pop_back();
        auto it = find(dsk[y].begin(),dsk[y].end(),x);
        if(it != dsk[y].end()){
            dsk[y].erase(it);
        }
        Euler(y);
    }
    ans.push_back(x);
}
int main(){
    cin >> t >> n;
    if(t==2) cin >> ul;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                dsk[i].push_back(j);
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        sort(dsk[i].begin(),dsk[i].end(),greater<int>());
    }
    if(!checkConnect()){
        cout << 0 << endl;
        return 0;
    }
    if(t==1){
        int cntDegree=0;
        for(int i=1 ; i<=n ; i++){
            if(dsk[i].size() % 2==1){
                ++cntDegree;
            }
        }
        if(cntDegree == 0) cout << 1 << endl;
        else if(cntDegree ==2) cout << 2 << endl;
        else cout << 0 << endl;
    }
    else{
        Euler(ul);
        reverse(ans.begin(),ans.end());
        for(int x : ans){
            cout << x <<" ";
        }
        cout << endl;
        return 0;
    }
}   