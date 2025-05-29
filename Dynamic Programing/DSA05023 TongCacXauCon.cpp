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
        string s;
        cin >> s;
        ll ans=0;
        // 1234
        for(int i=0 ; i<s.length() ; i++){
            for(int j=i ; j<s.length() ; j++){
                string tmp="";
                for(int k=i ; k<= j ; k++){
                    tmp+=s[k];
                }
                ans+=stoll(tmp);
            }
        }
        cout << ans << endl;
    }
}