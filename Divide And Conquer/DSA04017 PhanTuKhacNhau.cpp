#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
vector<ll> b;
int solve(int n){
    int i=0,j=0;
    while(i <n && j<n-1){
        if(a[i]==b[j]){
            ++i;
            ++j;
        }
        else return i;
    }
    return n-1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.clear();b.clear();
        for(int i=0 ;i <n ; i++){
            ll x;
            cin >> x;
            a.push_back(x);
        }
        for(int j=0 ;j <n-1 ; j++){
            ll x;
            cin >> x;
            b.push_back(x);
        }
        cout << solve(n)+1 << endl;
    }
}