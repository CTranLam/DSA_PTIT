#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,v;
        cin >> n >> v;
        int a[n+5]; // the tich
        for(int i=1 ; i<=n ; i++) cin >> a[i];
        int c[n+5]; // gia tri 
        for(int i=1 ; i<=n ; i++) cin >> c[i];
        int dp[n+5][v+5]; // gia tri lon nhat cua balo chua i vat va j khoi luong
        memset(dp,0,sizeof(dp));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=v ; j++){
                // khong lua chon do vat thu i vao tui
                dp[i][j]=dp[i-1][j];

                // neu lua chon them do vat thu i vao tui
                if(j >= a[i]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+c[i]);
                }
            }
        }
        cout << dp[n][v] << endl;
    }
}