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
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<m ; i++){
            cin >> b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        ll res=(ll)b[0]*a[m-1];
        cout << res << endl;
    }
}