#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        ll ans=0;
        for(int i=0 ; i<n ; i++){
            auto st=lower_bound(a+i+1,a+n,k-a[i]);
            auto ed=upper_bound(a+i+1,a+n,k-a[i]);
            if(st != a+n){
                ans+=ed-st;
            }
        }
        cout << ans << endl;
    }
}