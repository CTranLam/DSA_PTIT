#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        deg[i]=c;
        for(int j=1 ; j<=c ; j++){
            int u;cin >> u;
            if(i < u){
                dsc.push_back({i,u});
            }
        }
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg[i] <<" ";
        }
    }
    if(t==2){
        cout << n <<" "<<dsc.size() << endl;
        for(auto x : dsc){
            cout << x.first <<" "<<x.second << endl;
        }
    }
}