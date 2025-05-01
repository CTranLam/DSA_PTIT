#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int findValue(int a[],int l,int r,int x){
    while(l <= r){
        int m=(l+r)/2;
        if(a[m]==x){
            return m;
        }
        else if(a[m] < x){
            l=m+1;
        }
        else r=m-1;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        int pos=0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            if(i != 0 && a[i] < a[i-1]){
                pos=i;
            }
        }
        if(x > a[n-1]){
            cout << findValue(a,0,pos-1,x)+1 << endl;
        }
        else {
            cout << findValue(a,pos,n-1,x)+1 << endl;
        }
    }
}