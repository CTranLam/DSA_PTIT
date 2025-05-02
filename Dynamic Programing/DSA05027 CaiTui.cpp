#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];// dp[i][j] luu gia tri max tai i co khoi luong toi da la j
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n,v;
        cin >> n >> v;
        int W[1005],V[1005];
        for(int i=1 ; i<=n ; i++){
            cin >> W[i];// the tich
        }
        for(int i=1 ; i<=n ; i++){
            cin >> V[i];// gia tri
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=v ; j++){
                //lay hay khong lay vat pham nay
                if(j >= W[i]){
                    dp[i][j]= max(dp[i-1][j-W[i]] + V[i],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout << dp[n][v] << endl;
    }
}