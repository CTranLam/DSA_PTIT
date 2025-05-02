#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int l=0,r=n/2;
        int cnt=0;
        while(l < n/2 && r < n){
            if(a[r] >= 2*a[l]){
                ++cnt;
                ++l;
                ++r;
            }
            else{
                ++r;
            }
        }
        cout << n-cnt << endl;
    }
}