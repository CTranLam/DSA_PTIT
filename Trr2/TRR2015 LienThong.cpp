#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105][105];
vector<int> dsk_ch[105],dsk_vh[105];
int visited[105];
int cnt=0;
vector<vector<int>> ans;
vector<int> v;
void dfs_ch(int u){
    v.push_back(u);
    visited[u]=1;
    for(int x : dsk_ch[u]){
        if(!visited[x]){
            dfs_ch(x);
        }
    }
}
void dfs_vh(int u){
    v.push_back(u);
    visited[u]=1;
    for(int x : dsk_vh[u]){
        if(!visited[x]){
            dfs_vh(x);
        }
    }
}
bool lienThongManh(){
    for(int i=1 ; i<=n ; i++){
        dfs_ch(i);
        for(int j=1 ; j<=n ; j++){
            if(!visited[j]){
                return false;
            }
        }
        memset(visited,0,sizeof(visited));
    }
    return true;
}
bool lienThongYeu(){
    memset(visited,0,sizeof(visited));
    dfs_vh(1);
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int main(){
    ifstream cin("TK.INP");
    ofstream cout("TK.OUT");
    cin >> n;
    for(int i=1 ;i <= n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                dsk_ch[i].push_back(j);

                dsk_vh[i].push_back(j);
                dsk_vh[j].push_back(i);
            }
        }
    }
    if(lienThongManh()){
        cout << 1 << endl;
    }
    else if(lienThongYeu()){
        cout << 2 << endl;
    }
    else cout << 0 << endl;
    cin.close();
    cout.close();
}