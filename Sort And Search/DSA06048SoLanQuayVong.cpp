#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        for(int i=0 ; i<n ; i++) cin >> a[i];
        ll minn=LONG_LONG_MAX;
        int step=0;
        for(int i=0 ; i<n ; i++){
            if(a[i] <= minn){
                minn=a[i];
                step=i;
            }
        }
        cout << step << endl;
    }
}