#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int deg_in[105],deg_out[105];
int main(){
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t,n;
    cin >> t >> n;
    int a[n+5][n+5];
    vector<pair<int,int>> dsc;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                deg_in[j]++;
                deg_out[i]++;
                dsc.push_back({i,j});
            }
        }
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg_in[i] <<" "<<deg_out[i] << endl;
        }
    }
    else{
        cout << n <<" "<<dsc.size() <<endl;
        for(auto x : dsc){
            cout << x.first <<" "<<x.second << endl;
        }
        cout << endl;
    }
}