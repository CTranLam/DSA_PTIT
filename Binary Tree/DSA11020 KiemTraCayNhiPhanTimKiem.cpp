#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int a[],int n){
    for(int i=1 ; i<n ; i++){
        if(a[i]-a[i-1] <= 0) return false;
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        if(check(a,n)){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
}