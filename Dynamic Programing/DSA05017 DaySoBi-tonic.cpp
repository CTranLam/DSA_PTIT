#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        int L[n],R[n]; //tong day con tang trai va tang phai
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            L[i]=a[i];
            R[i]=a[i];
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(a[i] > a[j]){    
                    L[i]=max(L[i],L[j]+a[i]);
                }
            }
        }
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>i ; j--){
                if(a[i] > a[j]){
                    R[i]=max(R[i],R[j]+a[i]);
                }
            }
        }
        ll ans=0;
        for(int i=0 ; i<n ; i++){
            ans=max(ans,(ll)R[i]+L[i]-a[i]);
        }
        cout << ans << endl;
    }
}