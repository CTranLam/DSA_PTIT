#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+5];
        ll dp[n+5]; //gia tri max tai phan tu thu i
        a[0]=0;
        for(int i=1 ; i<=n ; i++){
            cin >> a[i];
            dp[i]=a[i];
        }
        dp[0]=0;
        ll ans=0;
        for(int i=2 ; i<=n ; i++){
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
            ans=max(ans,dp[i]);
        }
        cout << ans << endl;
    }
}