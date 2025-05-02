#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll f[55]; // luu so cach nhay
        f[1]=1;
        f[2]=2;
        f[3]=4;
        for(int i=4 ; i<55 ; i++){
            f[i]=f[i-1]+f[i-2]+f[i-3];
        }
        cout << f[n] << endl;
    }
}
