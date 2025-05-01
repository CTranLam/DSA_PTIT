#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        map<int,int> mp;
        int maxl=0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            mp[a[i]]++;
            maxl=max(maxl,mp[a[i]]);
        }
        if(maxl <= n/2){
            cout << "NO" << endl;
        }
        else{
            for(auto x : mp){
                if(x.second==maxl){
                    cout << x.first << endl;
                    break;
                }
            }
        }
    }
}