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
    int n,m; cin >> n >> m;
    for(int i=1 ; i<=m ; i++){
        int x,y; cin >> x >> y;
        deg[x]++;
        deg[y]++;
        a[x][y]=1; a[y][x]=1;
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
            for(int j=1 ; j<=n ; j++){
                cout << a[i][j] <<" ";
            }
            cout << endl;
        }
    }
    cin.close();
    cout.close();
}