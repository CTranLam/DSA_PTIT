#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int uutien(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    return 0; // voi mo ngoac
}
string solve(string s){
    stack<char> st; // luu + - * : (
    string res="";
    for(char x : s){
        if(isalpha(x)) res += x;
        else if(x=='(') st.push(x);
        else if(x==')'){
            while(st.top() != '('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && uutien(x) <= uutien(st.top())){
                // uu tien cao hon se luon dung truoc uu tien thap hon
                res+=st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}