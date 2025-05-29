#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        vector<string> v;
        q.push("6");
        q.push("8");
        while(!q.empty()){
            string s=q.front();
            q.pop();
            if(s.size() <= n){
                v.push_back(s);
                q.push(s+"6");
                q.push(s+"8");
            }
        }
        reverse(v.begin(),v.end());
        cout << v.size() <<endl;

        for(string x : v){
            cout << x <<" ";
        }
        cout << endl;
    }
}