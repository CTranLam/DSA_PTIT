#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int> dsk[n+5];
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                dsk[i].push_back(j);
                //dsk[j].push_back(i);
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        for(int x : dsk[i]){
            cout << x <<" ";
        }
        cout << endl;
    }
}