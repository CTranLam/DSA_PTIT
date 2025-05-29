#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string solve(string s) {
    stack<char> st;
    for (char x : s) {
        if (x == ']') {
            //lay phan ky tu trong ngoac
            string tmp = "";
            while (!st.empty() && st.top() != '[') {
                tmp = st.top() + tmp;
                st.pop();
            }
            // bo dau [
            if (!st.empty()) st.pop();
            //lay so lan lap lai
            string num = "";
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int n = 1;
            if (!num.empty()) {
                n = stoi(num);
            }
            string res = "";
            for (int i = 0; i < n; i++) {
                res += tmp;
            }
            for (char c : res) {
                st.push(c);
            }
        } else {
            st.push(x);
        }
    }
    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}
