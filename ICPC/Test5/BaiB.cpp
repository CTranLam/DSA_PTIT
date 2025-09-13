#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra dãy ngoặc đúng (không chứa '*')
bool isValid(const string &s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else if (c == ')') {
            bal--;
            if (bal < 0) return false;
        }
    }
    return bal == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int n = S.size();
        int pos = -1;
        for (int i = 0; i < n; i++) if (S[i] == '*') pos = i;

        int ans = 0;
        for (int i = 0; i < pos; i++) {
            if (S[i] != '(') continue;
            for (int j = pos + 1; j < n; j++) {
                if (S[j] != ')') continue;

                // Tạo chuỗi con từ i..j bỏ '*'
                string sub;
                for (int k = i; k <= j; k++) {
                    if (S[k] != '*') sub.push_back(S[k]);
                }
                if (isValid(sub)) ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
