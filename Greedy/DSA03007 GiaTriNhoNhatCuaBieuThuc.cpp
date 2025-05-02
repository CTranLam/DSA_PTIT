#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n],b[n];
        for(int i=0 ; i<n ; i++) cin >> a[i];
        for(int i=0 ; i<n ; i++) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n,greater<ll>());
        ll ans=0;
        for(int i=0 ; i<n ; i++){
            ans+=a[i]*b[i];
        }
        cout << ans << endl;
    }
}