#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phanTich(ll n , ll p){
    ll cnt = 0;
    for(ll i= p ; i<= n ; i*=p){
        cnt += n/i;
    }
    return cnt;
}
ll solve(ll n, ll k){
    map<ll,ll> fac;
    for(ll i = 2 ; i<=sqrt(k) ; i++){
        while(k%i == 0){
            fac[i]++;
            k/=i;
        }
    }
    if(k > 1) fac[k]++;
    ll res = LLONG_MAX;
    for(auto x : fac){
        ll cnt = phanTich(n,x.first)/x.second;
        res = min(res,cnt);
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        cout << solve(n,k) << endl;
    }
}