#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        int dp[105][105][105];
        s1="@"+s1,s2="@"+s2,s3="@"+s3;
        for(int i=0 ; i<=x ; i++){
            for(int j=0 ; j<=y ; j++){
                for(int k=0 ; k<=z ; k++){
                    if(i==0 || j==0 || k==0) dp[i][j][k]=0;
                    else{
                        if(s1[i]==s2[j] && s2[j]==s3[k]){
                            dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                        }
                        else{
                            dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                        }
                    }
                }
            }
        }
        cout << dp[x][y][z] << endl;
    }
}