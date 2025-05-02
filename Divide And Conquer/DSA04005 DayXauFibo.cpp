#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100];
// xau f[n]=f[n-2]+f[n-1]
char Find(ll n,ll k){
    if(n==1) return 'A';
    else if(n==2) return 'B';
    else if(k <= f[n-2]){ // k can tim nam o xau thu n-2
        return Find(n-2,k);
    }
    else return Find(n-1,k-f[n-2]); // k can tim nam o xau thu n-1
}
int main(){
    int t;
    cin >> t;
    f[1]=1;
    f[2]=1;
    for(int i=3 ; i<=92 ; i++){
        f[i]=f[i-1]+f[i-2];
    }
    while(t--){
        ll n,k;
        cin >> n >> k;
        cout << Find(n,k) << endl;
    }
}