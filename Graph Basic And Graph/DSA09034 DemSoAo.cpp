#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[505][505];
int n,m;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int visited[505][505];
void dfs(int i,int j){
    visited[i][j]=1;
    for(int k=0 ; k<8 ; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1 >= 1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='W' && visited[i1][j1]==0){
            dfs(i1,j1);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin >> a[i][j];
        }
    }
    int cnt=0;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(!visited[i][j] && a[i][j]=='W'){
                ++cnt;
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
}