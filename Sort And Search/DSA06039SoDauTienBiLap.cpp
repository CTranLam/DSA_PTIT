#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        bool check=false;
        for(int x : a){
            if(mp[x] > 1){
                cout << x << endl;
                check=true;
                break;
            }
        }
        if(!check){
            cout << "NO" << endl;
        }
    }
}