#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<string> st;
        for(int i=0 ; i<s.length() ; i++){
            if(isalpha(s[i])){
                string tmp="";
                tmp+=s[i];
                st.push(tmp);
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push("(" + s2 + s[i] + s1 +")");
            }
        }
        cout << st.top() << endl;
    }
}