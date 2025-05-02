#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int BinarySearch(int a[],int n,int k){
    int l=0,r=n-1;
    while(l <= r){
        int m=(l+r)/2;
        if(a[m] == k) return m;
        else if(a[m] < k) l=m+1;
        else r=m-1;
    }
    return n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0 ; i<n ; i++) cin >> a[i];
        if(BinarySearch(a,n,k)==n){
            cout << "NO" << endl;
        }
        else cout <<BinarySearch(a,n,k)+1 << endl;
    }
}