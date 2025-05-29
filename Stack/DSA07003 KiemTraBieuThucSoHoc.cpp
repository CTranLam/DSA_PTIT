#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string s){
    stack<char> st;
    for(char x : s){
        if(x==')'){
            bool hasop = false;
            // pop het 1 cum ra
            while(!st.empty() && st.top() != '('){
                if(st.top() =='+' || st.top()=='-' || st.top()=='/' || st.top()=='*'){
                    hasop = true;
                }
                st.pop();
            }
            if(!hasop) return true; // co thua dau ngoac
            if(!st.empty()) st.pop();
        }
        else{
            st.push(x);
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
        if(check(s)){
            cout << "Yes" << endl;
        }
        else{
            cout <<"No" << endl;
        }
    }
}