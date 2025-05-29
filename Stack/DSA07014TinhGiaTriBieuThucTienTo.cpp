#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<int> st;
        for(int i=s.size()-1 ; i>=0 ; i--){
            if(isdigit(s[i])){
                st.push(s[i]-'0');
            }
            else{
                int n1=st.top(); st.pop();
                int n2=st.top(); st.pop();
                if(s[i]=='+') st.push(n1+n2);
                else if(s[i]=='-') st.push(n1-n2);
                else if(s[i]=='*') st.push(n1*n2);
                else st.push(n1/n2);
            }
        }
        cout << st.top() << endl;
    }
}