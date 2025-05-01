#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;cin >> n >> k;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        ll ans=0;
        for(int i=0 ; i<n ; i++){
            // vi tri dau tien >= a[i] + k
            int it=lower_bound(a+i+1,a+n,k+a[i])-a;
            // vi tri cuoi cung < a[i]+k
            it--;
            ans+=it-i; // tu i-> it la nhuong vi tri thoa man
        }
        cout << ans << endl;
    }
}