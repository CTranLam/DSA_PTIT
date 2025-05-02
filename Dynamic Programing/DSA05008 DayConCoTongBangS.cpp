#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        int a[n+5];
        int f[n+5];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        bool dp[s+5]={0};
        for(int i=0 ; i<n ; i++){
            dp[a[i]]=1;
        }
        for(int i=1 ; i<n ; i++){
            for(int j=s ; j>=a[i]; j--){
                if(dp[j-a[i]] == 1){
                    dp[j]=1;
                }
            }
        }
        if(dp[s]==1) cout << "YES" << endl;
        else cout <<"NO" << endl;
    }
}