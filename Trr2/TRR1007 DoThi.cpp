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
    for(int i=1 ; i<=n ; i++){
        int c; cin >> c;
        deg[i]=c;
        for(int j=1 ; j<=c ; j++){
            int u;cin >> u;
            a[i][u]=1;
            a[u][i]=1;
        }
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg[i] <<" ";
        }
    }
    if(t==2){
        cout << n << endl;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                cout << a[i][j] <<" ";
            }
            cout << endl;
        }
    }
}