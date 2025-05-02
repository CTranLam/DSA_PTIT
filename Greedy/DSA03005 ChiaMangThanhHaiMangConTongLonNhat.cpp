#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        int sum=0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        int cur_sum=0;
        k=min(k,n-k);
        for(int i=0 ; i<k ; i++){
            cur_sum+=a[i];
        }
        cout << sum-2*cur_sum << endl;
    }
}