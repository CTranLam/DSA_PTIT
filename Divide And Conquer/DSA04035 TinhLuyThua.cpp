#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll binPow(ll a,ll b){
    if(b==0) return 1;
    ll x=binPow(a,b/2);
    if(b%2==0) return (x%MOD*x%MOD)%MOD;
    else return ((x%MOD*x%MOD)%MOD*a%MOD)%MOD;
}
int main(){
    ll a,b;
    while(cin >> a >> b){
        if(a==0  && b==0) return 0;
        else{
            cout << binPow(a,b) << endl;
        }
    }
}