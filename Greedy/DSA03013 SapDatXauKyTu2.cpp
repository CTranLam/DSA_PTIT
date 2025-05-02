#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string s,int d){
    map<char,int> mp;
    int max_cnt=0;
    for(char x : s){
        mp[x]++;
        max_cnt=max(max_cnt,mp[x]);
    }
    int len=s.size()-max_cnt;
    if(len >= (d-1)*(max_cnt-1)) return true;
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int d;cin >> d;
        string s;
        cin >> s;
        if(check(s,d)){
            cout << 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}