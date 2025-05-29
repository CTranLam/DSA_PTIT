#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t; cin >> t;
    queue<int> q;
    while(t--){
        string tt;
        cin >> tt;
        if(tt== "PUSH"){
            int x; cin >> x;
            q.push(x);
        }
        else if(tt=="PRINTFRONT"){
            if(!q.empty()){
                cout << q.front() << endl;
            }
            else cout << "NONE" << endl;
        }
        else{
            if(!q.empty()) q.pop();
        }
    }
}