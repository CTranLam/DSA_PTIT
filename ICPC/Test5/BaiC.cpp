#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, P;
    cin >> N >> P;

    long long ans = 1;
    long long tmp = P;

    for (long long p = 2; p * p <= tmp; p++) {
        if (tmp % p == 0) {
            int cnt = 0;
            while (tmp % p == 0) {
                tmp /= p;
                cnt++;
            }
            for (int i = 0; i < cnt / N; i++) ans *= p;
        }
    }
    if (tmp > 1) {
        if (N <= 1) ans *= tmp; 
    }

    cout << ans << "\n";
    return 0;
}
