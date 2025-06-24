#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t,n,m;
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    cin >> t >> n >> m;
    int a[105][105];
    int ans[n+5][m+5];
    int deg[105];
    memset(deg,0,sizeof(deg));
    memset(ans,0,sizeof(ans));
    for(int i=1 ; i<=m ; i++){
        int x,y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        ans[x][i]=1;
        ans[y][i]=1;
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg[i] <<" ";
        }
    }
    else{
        cout << n << " " << m << endl;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cout << ans[i][j] <<" ";
            }
            cout << endl;
        }
    }
}