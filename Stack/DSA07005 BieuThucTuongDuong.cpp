#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(string s){
    stack<char> st;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]==')'){
            string tmp="";
            while(!st.empty() && st.top() != '('){
                tmp=st.top()+tmp;
                st.pop();
            }
            st.pop();
            char sign;
            if(!st.empty()) sign=st.top();
            // cout << st.top() << endl;
            for(int j=0 ; j < tmp.length() ; j++){
                if(sign=='-' && !isalpha(tmp[j]) ){
                    if(tmp[j]=='+') st.push('-');
                    else if(tmp[j]=='-') st.push('+');
                    else st.push(tmp[j]);
                }
                else{
                    st.push(tmp[j]);
                }
            }
        }
        else{
            st.push(s[i]);
        }
    }
    string ans="";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    cout << ans << endl;
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