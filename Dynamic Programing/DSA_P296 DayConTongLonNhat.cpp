#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    int a[n+5];
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    int f[n+5];
    // tinh ca day con rong
    int sum=0;
    for(int i=1 ; i<=n ; i++){
        if(a[i] > 0) sum+=a[i];
        f[i]=sum;
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << f[r]-f[l-1] << endl;
    }
}