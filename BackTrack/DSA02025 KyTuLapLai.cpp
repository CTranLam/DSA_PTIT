#include <bits/stdc++.h> 
using namespace std; 
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
int n, used[100], cnt[256], ans = 1e9, res = 0; 
string a[100], x[100]; 
void Try(int i){ 
    for (int j = 1; j <= n; j++){ 
        if (!used[j]){ 
            x[i] = a[j]; 
            used[j] = 1; 
            if (i == 1) Try(i + 1); 
            else { 
                memset(cnt, 0, sizeof(cnt)); 
                int tmp = 0; 
                for (char c : x[i - 1]) cnt[c]++; 
                for (char c : x[i]){ 
                    cnt[c]++; 
                    if (cnt[c] == 2) tmp++; 
                } 
                res += tmp; 
                if (i == n){ 
                    //cout << res << endl; 
                    ans = min(ans, res); 
                } 
                else if (res < ans) Try(i + 1); 
                res -= tmp; 
            } 
            used[j] = 0; 
        } 
    } 
} 
int main() { 
    faster(); 
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    Try(1); 
    cout << ans << endl; 
}