#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// LCS day con chung dai nhat
int main(){
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        int n=s1.length(),m=s2.length();
        s1="@"+s1;
        s2="@"+s2;
        int dp[n+5][m+5]; // do dai day con chung tai vi tri thu i va j
        for(int i=0 ; i<=s1.length() ; i++){
            for(int j=0 ; j<=s2.length() ; j++){
                if(i==0 || j==0) dp[i][j]=0;
                else{
                    if(s1[i] == s2[j]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}