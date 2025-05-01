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
        for(int i=0 ; i<n ; i++) cin >> a[i];
        sort(a,a+n);
        ll res=0;
        for(int i=0 ; i<n ; i++){
            int l=i+1,r=n-1;
            int cnt=0;
            while(l < r){
                ll sum=(long)a[i] + a[l] + a[r];
                if(sum < k){
                    res+=r-l;
                    ++l;
                }
                else {
                    --r;
                }
            }
        }
        cout << res << endl;
    }
}