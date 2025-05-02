#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1), b(k + 1);
    set<int> se;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }

    int index = k;
    while (index >= 1 && a[index] == n - k + index) {
        index--;
    }

    if (index == 0) { 
        cout << k << endl;
        return;
    }

    a[index]++;
    for (int i = index + 1; i <= k; i++) {
        a[i] = a[i - 1] + 1;
    }

    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        if(!se.count(a[i])){
            ++cnt;
        }
    }
    
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
