#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check1(string s, int l,int r){
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        ++l;
        --r;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        char tt;
        cin >> tt;
        if(tt=='q'){
            int l,r;
            cin >> l >> r;
            if(check1(s,l-1,r-1)){
                cout <<"YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else{
            int u,x;
            cin >> u >> x;
            s[u-1] = x+'0';
        }
    }
}