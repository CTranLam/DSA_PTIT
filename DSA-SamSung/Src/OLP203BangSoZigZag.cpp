#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll x, y, z; 
    cin >> x >> y >> z;
    ll val = (x + y - 2) * (x + y - 1) / 2 + x;
    cout << val << "\n";
    ll d = (ll)( (sqrt(8.0*z+1) - 1) / 2 );
    while (d*(d+1)/2 < z) d++; 
    ll start = (d-1)*d/2;
    ll xx = z - start;
    ll yy = d - xx + 1;
    cout << xx << " " << yy << "\n";
}
