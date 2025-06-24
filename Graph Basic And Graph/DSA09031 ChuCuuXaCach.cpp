#include<bits/stdc++.h>
using namespace std;
int n, m, k;
bool check[1001][1001];
vector<int> A[1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
set<pair<pair<int, int>, pair<int, int>>> S;
vector<pair<int, int>> X;
void DFS(pair<int, int> u) {
    check[u.first][u.second] = true;
    for (int i = 0; i < 4; i++) {
        int x = u.first + dx[i];
        int y = u.second + dy[i];
        if (x >=1 && x<=n && y >=1 && y<=n && !check[x][y] && S.count({ u,{x,y} }) == 0){
            DFS({ x,y });
        }
    }
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        S.insert({ {a,b},{c,d} });
        S.insert({ {c,d},{a,b} });
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        X.push_back({ a,b });
    }

    int count = 0;
    for (auto x : X) {
        // cho cuu di het truoc
        memset(check, false, sizeof(check));
        DFS(x);
        for (auto y : X) {
            if (!check[y.first][y.second]) count++;
        }
    }

    cout << count / 2 << endl;
}
