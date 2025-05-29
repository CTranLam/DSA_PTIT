#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<string> v,int n){
    stack<ll> st;
    for(int i=v.size()-1 ; i>=0 ; i--){
        if(v[i] != "+" && v[i] !="-" && v[i] !="*" && v[i] != "/"){
            st.push(stoll(v[i]));
        }
        else{
            ll a=st.top();
            st.pop();
            ll b=st.top();
            st.pop();
            if(v[i]=="+") st.push(a+b);
            else if(v[i]=="-") st.push(a-b);
            else if(v[i] == "*") st.push(a*b);
            else st.push(a/b);
        }
    }
    cout << st.top() << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v;
        for(int i=0 ; i<n ; i++){
            string s; cin >> s;
            v.push_back(s);
        }
        solve(v,n);
    }
}