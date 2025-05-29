#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    stack<int> st;
    string s;
    while(cin >> s){
        if(s=="push"){
            int n; cin >> n;
            st.push(n);
        }
        else if(s=="pop"){
            st.pop();
        }
        else{
            if(st.empty()){
                cout <<"empty" << endl;
            }
            else{
                stack<int> tmp;
                tmp=st;
                vector<int> v;
                while(!tmp.empty()){
                    v.push_back(tmp.top());
                    tmp.pop();
                }
                for(int i=v.size()-1 ; i>=0 ; i--){
                    cout << v[i] <<" ";
                }
                cout << endl;
            }
        }
    }
}