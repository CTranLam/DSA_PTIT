#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> k >> s;
        map<char,int> mp;
        for(char x : s){
            mp[x]++;
        }
        priority_queue<ll> pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        while(k--){
            int x=pq.top();
            pq.pop();
            x--;
            pq.push(x);
        }
        ll ans=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            ans+=(ll)x*x;
        }
        cout << ans << endl;
    }
}