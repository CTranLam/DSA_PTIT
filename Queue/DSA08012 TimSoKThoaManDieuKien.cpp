#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check_num(string s){
    set<int> se;
    for(char x : s){
        if(x > '5'){
            return false;
        }
        se.insert(x);
    }
    return s.length()==se.size();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        int cnt=0;
        for(int i=l ; i<=r ; i++){
            if(check_num(to_string(i))){
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}