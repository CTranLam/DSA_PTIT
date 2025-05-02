#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++) cin >> a[i];
        sort(a,a+n);
        ll x=0,y=0;
        for(int i=0 ; i<n ; i++){
            if(i%2==0) x=x*10+a[i];
            else y=y*10+a[i];
        }
        cout << (ll)x+y << endl;
    }
}