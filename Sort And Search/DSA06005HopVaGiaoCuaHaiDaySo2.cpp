#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n],b[m];
        set<int> hop;
        map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            hop.insert(a[i]);
            mp[a[i]]=1;
        }
        for(int i=0 ; i<m ; i++){
            cin >> b[i];
            hop.insert(b[i]);
            if(mp[b[i]]==1){
                mp[b[i]]=2;
            }
        }
        for(int x : hop){
            cout << x <<" ";
        }
        cout << endl;
        for(auto x : mp){
            if(x.second==2){
                cout << x.first <<" ";
            }
        }
        cout << endl;
    }
}