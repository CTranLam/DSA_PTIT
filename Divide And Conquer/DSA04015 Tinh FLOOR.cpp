#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,x;
        cin >> n >> x;
        ll a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        auto it=upper_bound(a,a+n,x);
        if(it-a==0){
            cout << -1 << endl;
        }
        else{
            --it;
            cout << (it-a)+1 << endl;
        }
    }
}