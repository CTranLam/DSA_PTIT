#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string s){
    stack<int> st;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            int j=st.top();
            st.pop();
            if(s[j+1]=='(' && s[i-1]==')') return true;
            if(i-j==2) return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        if(check(s)) cout <<"Yes" << endl; // co thua dau ngoac
        else cout <<"No" << endl;
    }
}