#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int deg_in[105],deg_out[105];
int main(){
    int t,n;
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    cin >> t >> n;
    int a[105][105];
    int deg[105];
    memset(deg,0,sizeof(deg));
    vector<pair<int,int>> dsc;
    for(int i=1 ; i<=n ; i++){
        int c; cin >> c;
        for(int j=1 ; j<=c ; j++){
            int u;cin >> u;
            dsc.push_back({i,u});
            deg_out[i]++;
            deg_in[u]++;
        }
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg_in[i] <<" "<<deg_out[i] << endl;
        }
    }
    if(t==2){
        cout << n <<" "<<dsc.size() << endl;
        for(auto x : dsc){
            cout << x.first <<" "<<x.second << endl;
        }
    }
}