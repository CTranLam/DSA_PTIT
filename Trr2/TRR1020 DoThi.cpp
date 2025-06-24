#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int reva[105][105];
int deg_in[105],deg_out[105];
int main(){
    int t,n;
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    cin >> t >> n;
    vector<pair<int,int>> dsc;
    int idx=1;
    for(int i=1 ; i<=n ; i++){
        int c; cin >> c;
        for(int j=1 ; j<=c ; j++){
            int u;cin >> u;
            dsc.push_back({i,u});
            deg_out[i]++;
            deg_in[u]++;
            reva[i][idx]=1;
            reva[u][idx]=-1;
            ++idx;
        }
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg_in[i] <<" "<<deg_out[i] << endl;
        }
    }
    if(t==2){
        cout << n <<" "<<idx-1<<endl;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<idx ; j++){
                cout << reva[i][j] <<" ";
            }
            cout << endl;
        }
    }
}