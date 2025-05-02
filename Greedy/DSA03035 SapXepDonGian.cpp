#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];// gom day du cac so tu 1->n
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    // day con tang lan luot dai nhat
    int dp[100005];
    int max_cnt=0;
    for(int i=1 ; i<=n ; i++){
        dp[a[i]]=dp[a[i]-1]+1;
        max_cnt=max(max_cnt,dp[a[i]]);
    }
    cout << n-max_cnt << endl;
}