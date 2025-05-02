#include <bits/stdc++.h>
using namespace std;

void Gray(int n) {
    int total = 1 << n; // 2^n so Gray

    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1); // Ct Gray code
        cout << bitset<32>(gray).to_string().substr(32 - n) <<" ";
    }
    cout << endl;
}

int main() {
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;
        Gray(n);
    }
    return 0;
}
