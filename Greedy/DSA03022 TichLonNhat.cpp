#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int ans=INT_MIN;
    ans=max({ans,a[0]*a[1],a[0]*a[1]*a[n-1],a[n-1]*a[n-2],a[n-1]*a[n-2]*a[n-3]});
    cout << ans << endl;
}