#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(string s){
    stack<char> st;
    int cnt=0;
    for(char x : s){
        if(x =='('){
            st.push(x);
        }
        else{
            if(!st.empty()){
                cnt+=2;
                st.pop();
            }
        }
    }
    return cnt;
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