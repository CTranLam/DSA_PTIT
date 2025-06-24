#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n;
    cin >> k >> n;
    
    vector<string> S(k);
    for (int i = 0; i < k; ++i) {
        cin >> S[i];
    }

    vector<int> M(n);
    iota(M.begin(), M.end(), 0); // M = {0, 1, ..., n-1}

    int res = INT_MAX;
    do {
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (const auto& s : S) {
            string x;
            for (int i = 0; i < n; ++i) {
                x += s[M[i]];
            }
            int val = stoi(x);
            min_val = min(min_val, val);
            max_val = max(max_val, val);
        }

        res = min(res, max_val - min_val);
    } while (next_permutation(M.begin(), M.end()));

    cout << res << '\n';
    return 0;
}
