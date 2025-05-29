#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
bool isPrime[MAX];

// Đánh dấu các số nguyên tố bằng Sieve
void sieve() {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
}

// Kiểm tra nếu hai số khác nhau đúng 1 chữ số
bool oneDigitDiff(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int diff = 0;
    for (int i = 0; i < 4; ++i)
        if (sa[i] != sb[i]) diff++;
    return diff == 1;
}

int bfs(int S, int T) {
    queue<pair<int, int>> q;
    vector<bool> visited(MAX, false);

    q.push({S, 0});
    visited[S] = true;

    while (!q.empty()) {
        int num = q.front().first;
        int step = q.front().second;
        q.pop();

        if (num == T) return step;

        string s = to_string(num);
        for (int i = 0; i < 4; ++i) {
            for (char d = '0'; d <= '9'; ++d) {
                if (s[i] == d) continue;

                string ns = s;
                ns[i] = d;
                int newNum = stoi(ns);
                if (newNum >= 1000 && isPrime[newNum] && !visited[newNum]) {
                    visited[newNum] = true;
                    q.push({newNum, step + 1});
                }
            }
        }
    }
    return -1; // Không thể chuyển đổi
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int S, T;
        cin >> S >> T;
        int result = bfs(S, T);
        if (result != -1)
            cout << result << '\n';
        else
            cout << "Impossible\n";
    }
    return 0;
}
