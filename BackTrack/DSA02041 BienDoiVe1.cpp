#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
void Try(int n,int cnt){
    if(n==1){
        ans=min(ans,cnt);
        return;
    }
    if(cnt > ans) return;
    if(n%3==0)  Try(n/3,cnt+1);
    if(n%2==0)  Try(n/2,cnt+1);
    if(n > 1)   Try(n-1,cnt+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans=INT_MAX;
        Try(n,0);
        cout << ans << endl;
    }
}