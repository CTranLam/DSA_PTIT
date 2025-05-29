#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string prefix_to_infix(string s){
    stack<string> st;
    for(int i=s.size()-1 ; i>=0 ; i--){
        if(isalpha(s[i])){
            string tmp="";
            tmp += s[i];
            st.push(tmp);
        }
        else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string tmp="";
            tmp+="(" + s1 + s[i] +s2 +")";
            st.push(tmp);
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
        cout << prefix_to_infix(s) << endl;
    }   
}