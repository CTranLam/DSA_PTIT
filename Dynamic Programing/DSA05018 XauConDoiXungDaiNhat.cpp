#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dp[1005][1005]; // kiem tra 1 xau con bat dau tai i ket thuc tai j
int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        memset(dp,0,sizeof(dp));
        int n=s.size();
        s=" "+s;
        int max_len=1;
        for(int i=1 ; i<=n ; i++){
            dp[i][i]=1;
        }
        // tao ra cac xau con co do dai n 
        //abcdadd
        for(int len=2 ; len <= n ; len++){
            for(int i=1 ; i <=n-len+1 ; i++){
                int j=i+len-1;
                if(len == 2){
                    // len = 2 thi khong co xau o giua
                    if(s[i]==s[j]) dp[i][j]=true;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=true;
                }
                if(dp[i][j]) max_len=max(max_len,len);
            }
        }
        cout << max_len << endl;
    }
}