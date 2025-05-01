#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll a[],int n,int k){
    for(int i=0 ; i<n ; i++){
        int l=i+1,r=n-1;
        while(l < r){
            ll sum=(ll)a[i]+a[l]+a[r];
            if(sum == k) return true;
            else if(sum > k){
                --r;
            }
            else ++l;
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        ll a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        if(check(a,n,k)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}