#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(string s){
    stack<int> st;
    ll sum=0;
    for(int i=0 ; i<s.length() ; i++){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int n1=st.top();st.pop();
            int n2=st.top();st.pop();
            if(s[i]=='+') st.push(n1+n2);
            else if(s[i]=='-') st.push(n2-n1);
            else if(s[i]=='*') st.push(n1*n2);
            else st.push(n2/n1);
        }
    }
    return st.top();
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