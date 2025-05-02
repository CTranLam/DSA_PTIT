#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char solve(ll n,ll k){
    if(k==pow(2,n-1)) return (char)('A' + n-1);
    if(k < pow(2,n-1)){
        return solve(n-1,k);
    }
    else{
        return solve(n-1,k-pow(2,n-1));
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        cout << solve(n,k) << endl;
    }
}