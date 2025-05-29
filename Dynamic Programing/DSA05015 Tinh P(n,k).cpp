#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll P[1005][1005];
void Solve() {
    for(int n=1 ; n<=1000 ; n++){
        P[n][0]=1;  // p(n,0)=1;
        for(int k=1 ; k<=n ; k++){
            P[n][k]=P[n][k-1] * (n-k+1);
            P[n][k]%=MOD;
        }
    }
}

int main() {
    int t;
    cin >> t;
    Solve();
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << P[n][k] << endl;
    }
}
