#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin >> n;
    int a[n+5],dp[n+5];
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        dp[i]=1;
    }
    for(int i=2 ; i<=n ; i++){
        for(int j=1 ; j<i ; j++){
            if(a[j] < a[i]){
                dp[i]= max(dp[i],dp[j]+1);
            }
        }
    }
    cout << *max_element(dp+1,dp+n+1) << endl;
}