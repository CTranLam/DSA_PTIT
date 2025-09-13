#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, base;
struct fibo{
    ll a[5][5];
    friend fibo operator *(fibo x, fibo y){
        fibo res;
        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<2 ; j++){
                __int128 sum = 0;
                for(int k = 0 ; k<2 ; k++){
                    sum += (__int128)x.a[i][k]*y.a[k][j];
                    sum%= base;
                }
                res.a[i][j]=(ll)sum;
            }
        }
        return res;
    }
};
fibo binPow(fibo x, ll k){
    if(k==1) return x;
    fibo t = binPow(x,k/2);
    if(k%2==0) return t*t;
    else return t*t*x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> base;
        fibo res;
        res.a[0][0]=1;res.a[0][1]=1;
        res.a[1][0]=1;res.a[1][1]=0;
        res = binPow(res,n-1);
        cout << (res.a[0][0]%base + res.a[0][1]%base)%base << endl;
    }
}