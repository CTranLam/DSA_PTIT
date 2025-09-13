#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void phanTich(ll n){
    map<ll,ll> mp;
    for(int i=2 ; i<= sqrt(n) ; i++){
        if(n%i == 0){
            while(n%i == 0){
                mp[i]++;
                n/= i;
            }
        }
    }
    if(n > 1){
        mp[n]++;
    }
    for(auto x : mp){
        cout << x.first <<" "<<x.second << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        phanTich(n);
        cout << endl;
    }
}