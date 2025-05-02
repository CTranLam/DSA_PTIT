#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool solve(){
    int n;cin >> n;
        int a[n],b[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0 ; i<n ; i++){
            if(b[i] != a[i] && b[i] != a[n-1-i]){// do khi doi cho no van chi qua lai 2 vi tri nay
                return false;
            }
        }
        return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout <<"Yes" << endl;
        }
        else cout <<"No" << endl; 
    }
}