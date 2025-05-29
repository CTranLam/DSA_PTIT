#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(string s){
    stack<int> st;
    st.push(-1); // khoi tao moc
    int max_len = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else {
            st.pop();
            if (st.empty()) {
                st.push(i); // danh dau moc moi
            }
            else {
                max_len = max(max_len, i - st.top());
            }
        }
    }

    cout << max_len << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        solve(s);
    }
}
