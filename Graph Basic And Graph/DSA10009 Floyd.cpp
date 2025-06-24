#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int d[105][105];
void floyd(){
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0 ; i<=100; i++){
        for(int j=0 ; j<=100 ; j++){
            if(i==j){
                d[i][j]=0;
            }
            else d[i][j]=1e9;
        }
    }
    for(int i=0 ; i<m ; i++){
        int x,y,w; cin >> x >> y >> w;
        d[x][y]=d[y][x]=w;
    }
    floyd();
    int q; cin >> q;
    while(q--){
        int u,v ; cin >> u >> v;
        cout << d[u][v] << endl;
    }
}