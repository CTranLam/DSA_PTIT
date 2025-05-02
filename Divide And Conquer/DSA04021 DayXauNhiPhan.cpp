#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[93];
int solve(ll n,ll k){
    if(n==1) return 0;
    if(n==2) return 1;
    else if(k <= f[n-2]) return solve(n-2,k);
    else return solve(n-1,k-f[n-2]);
}
int main(){
    int t;
    cin >> t;
    f[1]=1;
    f[2]=1;
    for(int i=3 ; i<93 ; i++){
        f[i]=f[i-2]+f[i-1];
    }
    while(t--){
        ll n,k;
        cin >> n >> k;
        cout << solve(n,k) << endl;
    }
}