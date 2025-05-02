#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll binpow(ll a,ll b){
    if(b==0) return 1;
    ll x=binpow(a,b/2);
    if(b%2==0) return (x%MOD*x%MOD)%MOD;
    else return ((x%MOD*x%MOD)%MOD*a%MOD)%MOD;
}
ll reverse(ll n){
    ll tmp=0;
    while(n > 0){
        tmp=tmp*10 + n%10;
        n/=10;
    }
    return tmp;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll r=reverse(n);
        cout << binpow(n,r) << endl;
    }
}