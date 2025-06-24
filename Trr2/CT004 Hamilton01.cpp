#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ul;
vector<int> dsk[105];
vector<vector<int>> ans;
int visited[105];

void Hamilton(int u, vector<int>& res) {
    for(int v : dsk[u]){
        if(!visited[v]){
            res.push_back(v);
            visited[v]=1;
            Hamilton(v,res);
            visited[v]=0;
            res.pop_back();
        }
        else if(v == ul && res.size() == n){
            res.push_back(v);
            ans.push_back(res);
            res.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> ul;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            int x; cin >> x;
            if (x == 1) {
                dsk[i].push_back(j);
            }
        }
    }

    vector<int> res;
    res.push_back(ul);
    visited[ul] = 1;
    Hamilton(ul, res);
    cout << ans.size() << "\n";
    for (auto v : ans) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
}