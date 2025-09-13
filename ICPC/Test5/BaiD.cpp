#include <bits/stdc++.h>
using namespace std;
bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), cmp);
    vector<string> topK;
    for (int i = 0; i < min(N, 6); i++) {
        topK.push_back(A[i]);
    }

    string best = "0";
    int K = topK.size();
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (j == i) continue;
            for (int k = 0; k < K; k++) {
                if (k == i || k == j) continue;
                string cur = topK[i] + topK[j] + topK[k];
                if (cur.size() > best.size() || (cur.size() == best.size() && cur > best)) {
                    best = cur;
                }
            }
        }
    }

    cout << best << "\n";
    return 0;
}
