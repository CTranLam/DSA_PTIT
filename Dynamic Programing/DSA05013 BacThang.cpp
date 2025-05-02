#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int ans=0;
        ll f[100005];// luu so buoc nhay den i
        f[0]=1;
        f[1]=1;
        for(int i=2 ; i<= n ; i++){
            f[i]=0;
            for(int j=1 ; j<=min(i,k) ; j++){
                f[i]+=f[i-j];
                f[i] %=MOD;
            }
        }
        cout << f[n] << endl;
    }
}
