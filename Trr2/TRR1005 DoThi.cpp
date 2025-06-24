#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int deg[105];
vector<int> ke[1005];
int main(){
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t; cin >> t;
    int n,m; cin >> n >> m;
    for(int i=1 ; i<=m ; i++){
        int x,y; cin >> x >> y;
        deg[x]++;
        deg[y]++;
        ke[y].push_back(x);
        ke[x].push_back(y);
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
    cin.close();
    cout.close();
}