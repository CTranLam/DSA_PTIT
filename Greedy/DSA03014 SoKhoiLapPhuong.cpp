#include <bits/stdc++.h> 
using namespace std; 
using ll = long long; 
#define el endl 
string s; 
int X[20]; 
int ok = 0; 
ll res; 
void fix(int n){ 
    ll sum = 0; 
    for (int i = 0; i < n; i++){ 
        if(X[i] != 0){ 
            sum = sum * 10 + (s[i] - '0'); 
        } 
    } 
    ll root = round(cbrt(sum)); 
    if (sum > 0 && root * root * root == sum){ 
        ok = 1; res = max(res,sum); 
    } 
} 
void Try(int i){ 
    for (int j = 0; j <= 1; j++){ 
        X[i] = j; 
        if (i == s.size() - 1){ 
            fix(s.size()); 
        } 
        else { 
            Try(i + 1); 
        } 
    } 
} 
int main() { 
    int t; cin >> t; 
    while (t--) { 
        res = 0; 
        ok = 0; 
        memset(X, 0, sizeof(X)); 
        cin >> s; 
        Try(0); 
        if (s == "0"){ 
            ok = 1; 
        } 
        if (!ok){ 
            cout << -1; 
        } 
        else { 
            cout << res; 
        } 
        cout << el; 
    } 
    return 0; 
}