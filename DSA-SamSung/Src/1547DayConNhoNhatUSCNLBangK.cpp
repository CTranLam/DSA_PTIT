#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    while(b != 0){
        ll tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[n+5];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }

        int b[n+5];
        for(int i=0 ; i<n ; i++){
            if(a[i]%k != 0){
                b[i]=-1;
            }
            else{
                b[i]=a[i]/k;
            }
        }

        map<ll,int> gcds; // gcd hien tai va vi tri bd
        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++){
            map<ll,int> new_gcds;
            if(b[i] != -1){
                new_gcds[b[i]]=i;
                for(auto p : gcds){
                    ll g = gcd(p.first,b[i]);
                    int l = p.second;
                    if(new_gcds.count(g)) new_gcds[g]=min(new_gcds[g],l);
                    else new_gcds[g] = l;
                }
                gcds = new_gcds;
                if(gcds.count(1)){
                    ans = min(ans,i-gcds[1]+1);
                }
            }
            else{
                gcds.clear();
            }
        }
        if(ans == INT_MAX) cout << -1 << endl;
        else{
            cout << ans << endl;
        }
    }
}