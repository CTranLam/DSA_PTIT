#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n],b[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(a,a+n);
        int st=0,ed=n-1;
        for(int i=0 ; i<n ; i++){
            if(a[i] != b[i]){
                st=i+1;
                break;
            }
        }
        for(int i=n-1 ; i>=0 ; i--){
            if(a[i] != b[i]){
                ed=i+1;
                break;
            }
        }
        cout << st <<" "<<ed << endl;
    }
}