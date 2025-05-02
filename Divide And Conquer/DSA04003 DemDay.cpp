#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=123456789;
ll binpow(ll a,ll b){
    if(b==0) return 1;
    ll x=binpow(a,b/2);
    if(b%2==0) return (x%MOD*x%MOD)%MOD;
    else return ((x%MOD*x%MOD)%MOD*a%MOD)%MOD;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        // so day = 2^(n-1)
        // co n-1 khoang trong, moi khoang trong co 2 lua chon dat hoac khong dat
        cout << binpow(2,n-1) << endl;
    }
}