#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<string> v){
    stack<string> st;
    for(string x : v){
        if(x != "+" && x != "-" && x != "*" && x != "/"){
            st.push(x);
        }
        else{
            ll n1=stoll(st.top());
            st.pop();
            ll n2=stoll(st.top());
            st.pop();
            // cout << n1 <<" "<< n2 << endl;
            if(x=="+"){
                ll tmp=n1+n2;
                st.push(to_string(tmp));
            }
            else if(x=="-"){
                ll tmp=n2-n1;
                st.push(to_string(tmp));
            }
            else if(x=="*"){
                ll tmp=n1*n2;
                st.push(to_string(tmp));
            }
            else{
                ll tmp=n2/n1;
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