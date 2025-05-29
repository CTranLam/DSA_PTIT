#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool valid(char x,char y){
    return ((x=='(' && y==')') || (x=='[' && y==']') || (x=='{' && y=='}'));
}
bool check(string s){
    stack<char> st;
    for(char x : s){
        if(x=='(' || x=='[' || x=='{'){
            st.push(x);
        }
        else{
            if(st.empty()) return false;
            if(!valid(st.top(),x)) return false;
            st.pop();
        }
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(check(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}