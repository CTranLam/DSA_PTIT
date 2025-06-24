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
    int t,n; cin >> t >>n;
    int idx=1;
    for(int i=1 ; i<=n;i++){
        int c; cin >> c;
        while(c--){
            int x; cin >> x;
            dsk[i].push_back(x);
            deg_in[x]++;
            deg_out[i]++;
            a[i][x]=1;
        }
    }
    if(t==1){
        for(int i=1 ; i<=n ; i++){
            cout << deg_in[i] <<" "<<deg_out[i] << endl;
        }
    }
    else{
        cout << n << endl;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}