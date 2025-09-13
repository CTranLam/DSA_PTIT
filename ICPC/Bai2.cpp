#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n+5], b[m+5];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    ll minn = INT_MAX;
    pair<ll,ll> ans;
    int i = 0, j = 0;
    while( i < n && j < m ) {
        ll diff = abs(a[i] - b[j]);
        if(diff < minn) {
            minn = diff;
            ans = {a[i], b[j]};
        }
        if(a[i] < b[j]) {
            i++;
        }
        else{
            ++j;
        }
    }
    cout << minn << "\n";
}
