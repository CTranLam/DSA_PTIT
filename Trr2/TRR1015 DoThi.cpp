#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int reva[105][105];
int deg_in[105],deg_out[105];
int main(){
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t,n,m; cin >> t >> n >>m;
    for(int i=1 ; i<=m ;i++){
        int u,v;
        cin >> u >> v;
        a[u][v] = 1;
        deg_in[v]++;
        deg_out[u]++;
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg_in[i] <<" "<<deg_out[i] << endl;
        }
    }
    else{
        int idx=1;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(a[i][j]==1){
                    reva[i][idx]=1;
                    reva[j][idx]=-1;
                    idx++;
                }
            }
        }
        cout << n << endl;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ;j++){
                cout << a[i][j] <<" ";
            }
            cout << endl;
        }
    }
}