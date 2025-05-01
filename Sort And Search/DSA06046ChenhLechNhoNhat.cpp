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
        sort(a,a+n);
        int min_step=INT_MAX;
        for(int i=1 ; i<n ; i++){
            min_step=min(min_step,a[i]-a[i-1]);
        }
        cout << min_step << endl;
    }
}