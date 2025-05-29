#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s; 
        getline(cin,s);
        stringstream ss(s);
        string t;
        stack<string> st;
        while(ss >> t){
            st.push(t);
        }
        while(!st.empty()){
            cout << st.top() <<" ";
            st.pop();
        }
        cout << endl;
    }
}