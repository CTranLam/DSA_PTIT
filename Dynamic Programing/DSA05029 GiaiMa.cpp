#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(){
    string s;
    cin >> s;
    if(s.empty() || s[0]=='0') return 0;
    ll dp[105];//dp[i] so cach giai ma toi da tai i
    memset(dp,0,sizeof(dp));
    int n=s.length();
    dp[0]=1;
    dp[1]=1;
    for(int i=2 ; i<=s.length() ; i++){
        int oneDigit=s[i-1]-'0';
        int twoDigit=(s[i-2]-'0')*10 + oneDigit;
        if(oneDigit >=1 && oneDigit <=9){
            dp[i]+=dp[i-1];
        }
        if(twoDigit >= 10 && twoDigit <= 26){
            dp[i]+=dp[i-2];
        }
        }
    return dp[n];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}