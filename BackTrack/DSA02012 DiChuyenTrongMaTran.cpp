#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n;
int a[20][20];
int cnt=0;
void Try(int i,int j){
    if(i==m && j==n){
        ++cnt;
        return;
    }
    if(i + 1<= m) Try(i+1,j);
    if(j + 1<=n) Try(i,j+1);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                cin >> a[i][j];
            }
        }
        cnt=0;
        Try(1,1);
        cout << cnt << endl;
    }
}