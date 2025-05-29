#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<string> v){
    stack<string> st;
    for(int i=v.size()-1 ; i >= 0 ; i--){
        if(v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/"){
            st.push(v[i]);
        }
        else{
            ll n1=stoll(st.top());
            st.pop();
            ll n2=stoll(st.top());
            st.pop();
            // cout << n1 <<" "<< n2 << endl;
            if(v[i]=="+"){
                ll tmp=n1+n2;
                st.push(to_string(tmp));
            }
            else if(v[i]=="-"){
                ll tmp=n1-n2;
                st.push(to_string(tmp));
            }
            else if(v[i]=="*"){
                ll tmp=n1*n2;
                st.push(to_string(tmp));
            }
            else{
                ll tmp=n1/n2;
                st.push(to_string(tmp));
            }
        }
    }
    cout << st.top() << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v(n);
        for(int i=0 ; i<n ; i++){
            cin >> v[i];
        }
        solve(v);
    }
}