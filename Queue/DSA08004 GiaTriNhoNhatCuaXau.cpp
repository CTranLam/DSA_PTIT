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
        int k; cin >> k;
        string s; cin >> s;
        map<char,int> mp;
        for(char x : s) mp[x]++;
        priority_queue<int> pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        while(k--){
            int maxv=pq.top();
            pq.pop();
            maxv--;
            pq.push(maxv);
        }
        ll ans=0;
        while(!pq.empty()){
            ans+=(ll)pq.top()*pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}