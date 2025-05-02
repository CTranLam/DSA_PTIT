#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k;
int x[100005];

void init() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x[i];
    }
}

void solve() {
    int i = k - 1;
    while (i >= 0 && x[i] == x[i - 1] + 1) {
        i--;
    }
    if (i < 0) {
        if(x[0]==1){
            for (int j = 0; j < k; j++) {
                x[j] = n - k + j + 1;
            }
        }
        else{
            x[0]--;
            for(int j= 1 ; j<k ; j++){
                x[j]=n-k+j+1;
            }
        }
    } 
    else {
        x[i]--;
        for(int j= i+1 ; j<k ; j++){
            x[j]=n-k+j+1;
        }
    }

    for (int i = 0; i < k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
