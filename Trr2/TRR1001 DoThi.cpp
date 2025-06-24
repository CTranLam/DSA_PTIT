#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int deg[105];
set<pair<int,int>> dsc;
int main(){
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t; cin >> t;
    int n; cin >> n;
    for(int i=1 ; i<=n ; i++){
        int cnt=0;
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1) ++cnt;
            if(a[i][j]==1 && i<j && dsc.count({i,j})==0){
                dsc.insert({i,j});
            }
        }
        deg[i]=cnt;
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg[i] <<" ";
        }
        cout << endl;
    }
    else{
        cout << n <<" "<<dsc.size() << endl;
        for(auto x : dsc){
            cout << x.first <<" "<<x.second <<endl;
        }
    }
    cin.close();
    cout.close();
}