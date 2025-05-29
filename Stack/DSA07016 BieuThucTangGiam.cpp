#include<bits/stdc++.h>
using namespace std;
void solve(string s){
    stack<int> st;
    int n = s.size();
    int num = 1;
    string res = "";
    for(int i = 0; i <= n; ++i){
        st.push(num++);
        if(i == n || s[i] == 'I'){
            while(!st.empty()){
                res += to_string(st.top());
                st.pop();
            }
        }
    }
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        solve(s);
    }
}
