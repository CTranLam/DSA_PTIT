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
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        ll f[n];
        f[0]=a[0];
        for(int i=1 ; i<n ; i++){
            f[i]=f[i-1]+a[i];
        }
        bool check=false;
        // for(int i=0 ; i<n ; i++){
        //     cout << f[i] <<" ";
        // }
        cout << endl;
        for(int i=1 ; i<n ; i++){
            if(f[i]==f[n-1]-f[i-1]){
                cout << i+1 << endl;
                check=true;
                break;
            }
        }
        if(!check){
            cout << -1 << endl;
        }
    }
}