#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int reva[105][105];
int deg_in[105],deg_out[105];
vector<int> dsk[105];
int main(){
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t,n,m; cin >> t >> n >>m;
    int idx=1;
    for(int i=1 ; i<=m ;i++){
        int u,v;
        cin >> u >> v;
        deg_in[v]++;
        deg_out[u]++;
        reva[u][idx]=1;
        reva[v][idx]=-1;
        ++idx;
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg_in[i] <<" "<<deg_out[i] << endl;
        }
    }
    else{
        
        cout << n << " " <<idx-1 << endl;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<idx ;j++){
                cout << reva[i][j] <<" ";
            }
            cout << endl;
        }
    }
}