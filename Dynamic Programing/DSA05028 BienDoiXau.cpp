#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        int dp[105][105]; // so cach bien doi tu s1[1->i] thanh s2[1->j]
        memset(dp,0,sizeof(dp));
        int n=s1.size(),m=s2.size();
        s1="0"+s1;
        s2="0"+s2;
        for(int i=1 ; i<=n ; i++){
            dp[i][0]=i; // chuyen 1 xau i ky tu thanh 1 xau rong
        }
        for(int i=1 ; i<=m ; i++){
            dp[0][i]=i;
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min({
                        dp[i-1][j-1]+1,
                        dp[i-1][j]+1,
                        dp[i][j-1]+1
                    });      
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}