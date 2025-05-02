#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll dp[10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n;// so bac
        cin >> k;// so bac moi buoc co the di
        dp[0]=1;
        dp[1]=1;
        for(int i=2 ; i<=n ; i++){
            dp[i]=0;
            for(int j=1 ; j<=min(k,i) ; j++){
                dp[i]+=dp[i-j];
                dp[i]%=MOD;
            }
        }
        cout << dp[n] << endl;
    }
}