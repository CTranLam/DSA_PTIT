#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string s){
    map<char,int> mp;
    int len=s.size();
    int max_cnt=0;
    for(char x : s){
        mp[x]++;
    }
    for(auto x : mp){
        max_cnt=max(max_cnt,x.second);
    }
    len-=max_cnt;
    if(max_cnt > (len+1)) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(check(s)){
            cout << 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}