#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int t, n;
int A[MAX], BIT[MAX];
int cntLeft[MAX], cntRight[MAX];
void update(int i, int val) {
    while (i < MAX) {
        BIT[i] += val;
        i += i & -i;
    }
}
int get(int i) {
    int res = 0;
    while (i > 0) {
        res += BIT[i];
        i -= i & -i;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        memset(BIT, 0, sizeof(BIT));
        memset(cntLeft, 0, sizeof(cntLeft));
        memset(cntRight, 0, sizeof(cntRight));
        for (int i = 1; i <= n; i++) {
            cntLeft[i] = get(MAX - 1) - get(A[i]);
            update(A[i], 1);
        }
        memset(BIT, 0, sizeof(BIT));
        for (int i = n; i >= 1; i--) {
            cntRight[i] = get(A[i] - 1);
            update(A[i], 1);
        }
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            res += 1LL * cntLeft[i] * cntRight[i];
        }

        cout << res << '\n';
    }

    return 0;
}
