#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C[105];
void Catalan(){
    C[0]=1;
    C[1]=1;
    for(int i=2 ; i<=100; i++){
        for(int j=0 ; j<i ; j++){
            int k=i-j-1;
            C[i]+=C[j]*C[k];
        }
    }
}
int main(){
    int t;
    cin >> t;
    Catalan();
    while(t--){
        int n; cin >> n;
        cout << C[n] << endl;
    }
}