#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin >> t;
    deque<int> dq;
    while(t--){
        string s; cin >> s;
        if(s=="PUSHFRONT"){
            int x; cin >> x;
            dq.push_front(x);
        } 
        else if(s=="PUSHBACK"){
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(s=="PRINTFRONT"){
            if(!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }
        else if(s=="PRINTBACK"){
            if(!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }
        else if(s=="POPBACK"){
            if(!dq.empty()){
                dq.pop_back();
            }
        }
        else{
           if(!dq.empty()){
                dq.pop_front();
            } 
        }
    }
}