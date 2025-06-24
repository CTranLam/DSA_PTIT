#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1005];
int deg[1005];
int a[105][105];
int main(){
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t; cin >> t;
    int n; cin >> n;
    for(int i=1 ; i<=n ; i++){
        int cnt=0;
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                ++cnt;
                ke[i].push_back(j);
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
        cout << n << endl;
        for(int i=1 ; i<=n ; i++){
            cout << ke[i].size() <<" ";
            for(int x : ke[i]){
                cout << x <<" ";
            }
            cout << endl;
        }
    }
}