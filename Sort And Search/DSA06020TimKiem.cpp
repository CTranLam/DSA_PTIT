#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        bool check=false;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            if(a[i]==x){
                check=true;
            }
        }
        if(check) cout << 1 << endl;
        else cout << -1 << endl;
    }
}