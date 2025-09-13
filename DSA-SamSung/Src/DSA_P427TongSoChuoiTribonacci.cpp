#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e15 + 7;
struct matran{
    ll a[5][5];
    friend matran operator *(matran x,matran y){
        matran res;
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                __int128 sum = 0;
                for(int k=0 ; k<4 ; k++){
                    sum +=(__int128)x.a[i][k]*y.a[k][j];
                    sum %= MOD;
                }
                res.a[i][j] = (ll)sum;
            }
        }
        return res;
    }
};
matran binPow(matran x, ll k){
    if(k==1) return x;
    matran t = binPow(x,k/2);
    if(k%2==0) return t*t;
    else return t*t*x;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 2){
            cout << 3 << endl;
            continue;
        }
        if(n == 3){
            cout << 6 << endl;
            continue;
        }
        matran res;
        res.a[0][0]=1;res.a[0][1]=1;res.a[0][2]=1;res.a[0][3]=0;
        res.a[1][0]=1;res.a[1][1]=0;res.a[1][2]=0;res.a[1][3]=0;
        res.a[2][0]=0;res.a[2][1]=1;res.a[2][2]=0;res.a[2][3]=0;
        res.a[3][0]=1;res.a[3][1]=1;res.a[3][2]=1;res.a[3][3]=1;
        res = binPow(res,n-3);
        vector<__int128> s = {3,2,1,6}; // T3 T2 T1 F3
        vector<__int128> ans(4,0);
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                ans[i] += (__int128)res.a[i][j]*s[j];
                ans[i] %= MOD;
            }
        }
        cout << (ll)ans[3] << endl;
    }
}