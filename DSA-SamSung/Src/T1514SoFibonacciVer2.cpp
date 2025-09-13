#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll base,n;
struct maTran{
    ll a[2][2];
    friend maTran operator *(maTran x,maTran y){
        maTran res;
        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<2 ; j++){
                __int128 sum = 0;
                for(int k = 0 ; k<2 ; k++){
                    sum +=(__int128)x.a[i][k]*y.a[k][j];
                }
                res.a[i][j]=sum%base;
            }
        }
        return res;
    }
};
maTran binPow(maTran x , ll k){
    if(k == 1) return x;
    maTran t = binPow(x,k/2);
    if(k%2==0) return t*t;
    else return t*t*x;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> base;
        if(n== 0 || n == 1){
            cout << 1%base << endl;
            continue;
        }
        maTran res;
        res.a[0][0]=1;
        res.a[0][1]=1;
        res.a[1][0]=1;
        res.a[1][1]=0;
        res = binPow(res,n);
        cout << res.a[0][0] << endl; // do de bai F[0]=1,F[1]=1
    }
}