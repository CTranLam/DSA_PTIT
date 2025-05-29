#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n ; cin >> n;
        queue<string> q;
        q.push("6");
        q.push("8");
        vector<string> v;
        while(true){
            string x=q.front();
            q.pop();
            if(x.size()>n) break;
            v.push_back(x);
            q.push(x+"6");
            q.push(x+"8");
        }
        cout << v.size() << endl;
        for(int i=v.size()-1 ; i>=0 ; i--){
            cout << v[i] <<" ";
        }
        cout << endl;
    }
}