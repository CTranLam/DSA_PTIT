#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
const int MOD = 1e9+7;
struct maTran{
    ll a[2][2];
    friend maTran operator *(maTran x, maTran y){
        maTran res;
        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<2 ; j++){
                res.a[i][j]=0;
                for(int k = 0 ; k<2 ; k++){
                    res.a[i][j] += x.a[i][k]*y.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};
maTran binPow(maTran x, ll k){
    if(k==1) return x;
    maTran t = binPow(x,k/2);
    if(k%2==0) return t*t;
    else return t*t*x;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        if(n == 0){
            cout << 0 << endl;
            continue;
        }
        maTran res;
        res.a[0][0]=1;res.a[0][1]=1;
        res.a[1][0]=1;res.a[1][1]=0;
        res = binPow(res,n);
        cout << res.a[0][1] << endl;
    }
}