#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n,k;
        cin >> m >> n >> k;
        int a[m],b[n];
        for(int i=0 ; i<m ; i++) cin >> a[i];
        for(int j=0 ; j<n ; j++) cin >> b[j];
        int i=0,j=0;
        int cnt=0;
        bool check=false;
        while(i <m && j <n){
            ++cnt;
            if(a[i]<b[j]){
                if(cnt==k){
                    cout << a[i] <<endl;
                    check=true;
                    break;
                }
                ++i;
            }
            else{
                if(cnt==k){
                    cout << b[j] <<endl;
                    check=true;
                    break;
                }
                ++j;
            }
        }
        if(!check){
            while(i < m){
                ++cnt;
                if(cnt==k){
                    cout << a[i] <<endl;
                    check=true;
                    break;
                }
                ++i;
            }
            while(j <n){
                ++cnt;
                if(cnt==k){
                    cout << b[j] << endl;
                    break;
                }
                ++j;
            }
        }
    }
}