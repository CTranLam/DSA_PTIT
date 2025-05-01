#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int f[maxn];
void sang(){
    f[0]=1;
    f[1]=1;
    for(int i=2 ; i<=sqrt(maxn) ; i++){
        if(f[i]==0){
            for(int j=i*i ; j<=maxn ; j+=i){
                f[j]=1;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    sang();
    while(t--){
        int n;
        cin >> n;
        int ok=1;
        for(int i=2 ; i<=n ; i++){
            if(f[i]==0 && f[n-i]==0){
                cout << i <<" "<<n-i <<endl;
                ok=0;
                break;
            }
        }
        if(ok) cout << -1 << endl;
    }
}