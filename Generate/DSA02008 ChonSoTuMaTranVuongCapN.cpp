#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define pb push_back 
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
#define endl "\n" 
int n, k, sum = 0; 
int c[20][20], x[20], used[20]; 
vector<vector<int>> ans; 
void Try(int i){ 
    for (int j = 1; j <= n; j++){
         if (!used[j]){ 
            x[i] = j; 
            sum += c[i][j]; 
            used[j] = 1; 
            if (i == n && sum == k){ 
                vector<int> res(x + 1, x + n + 1); 
                ans.pb(res); 
            } 
            else if (i < n && sum < k) Try(i + 1); 
            sum -= c[i][j]; used[j] = 0; 
        } 
    } 
} 
int main() { 
    faster(); 
    cin >> n >> k; 
    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= n; j++){ 
            cin >> c[i][j]; 
        } 
    } 
    Try(1); 
    if (ans.empty()) cout << 0; 
    else { 
        cout << ans.size() << endl; 
        for (auto it : ans){ 
            for (int x : it) 
                cout << x << ' '; 
            cout << endl; 
        } 
    } 
}