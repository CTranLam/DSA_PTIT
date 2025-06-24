#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[505][505];
int visited[505][505];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
void dfs(int i,int j){
    visited[i][j]=1;
    for(int k=0 ; k<8 ; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]==1){
            a[i1][j1]=0;
            dfs(i1,j1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        cin >> n >> m;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cin >> a[i][j];
            }
        }
        ll cnt=0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(a[i][j]==1){
                    ++cnt;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << endl;
    }
}