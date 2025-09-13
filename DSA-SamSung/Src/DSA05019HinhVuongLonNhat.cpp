#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505;
int a[maxn][maxn];
int dp[maxn][maxn];
int main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cin >> a[i][j];
                dp[i][j]=a[i][j];
            }
        }
        int maxArea = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(a[i][j]==0) dp[i][j]=0;
                else{
                    dp[i][j]= min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                    maxArea = max(maxArea,dp[i][j]);
                }
            }
        }
        cout << maxArea << endl;
    }
}