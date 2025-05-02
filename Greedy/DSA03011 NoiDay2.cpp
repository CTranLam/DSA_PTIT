#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            pq.push(a[i]);
        }
        ll ans=0;
        while(pq.size() > 1){
            ll x=pq.top()%MOD;
            pq.pop();
            ll y=pq.top()%MOD;
            pq.pop();
            ans+=(x+y)%MOD; // cost
            ans%=MOD; 
            pq.push((x+y)%MOD);
        }
        cout << ans << endl;
    }
}