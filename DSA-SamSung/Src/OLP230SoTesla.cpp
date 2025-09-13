#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, base;
struct tesla{
    ll a[5][5];
    friend tesla operator * (tesla x, tesla y){
        tesla res;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                __int128 sum = 0;
                for(int k = 0 ; k<3 ; k++){
                    sum += (__int128)x.a[i][k] * y.a[k][j];
                    sum%= base;
                }
                res.a[i][j] = (ll)sum;
            }
        }
        return res;
    }
};
tesla binPow(tesla x, ll k){
    if(k == 1) return x;
    tesla t = binPow(x,k/2);
    if(k%2==0) return t*t;
    else return t*t*x;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> base;
        if(n == 1 || n == 2 || n == 3){
            cout << n%base << endl;
            continue;
        }
        tesla res;
        res.a[0][0]=1,res.a[0][1]=2,res.a[0][2]=3;
        res.a[1][0]=1,res.a[1][1]=0,res.a[1][2]=0;
        res.a[2][0]=0,res.a[2][1]=1,res.a[2][2]=0;
        res = binPow(res,n-3);
        cout << (res.a[0][0]*(3%base) + res.a[0][1]*(2%base) + res.a[0][2]*(1%base))%base << endl;
    }
}