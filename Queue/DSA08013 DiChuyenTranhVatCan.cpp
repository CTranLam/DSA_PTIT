#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x1,int y1,int x2,int y2,vector<vector<char>> &v,int n){
    queue<pair<pair<int,int>,int>> q;
    q.push({{x1,y1},0});
    bool visited[105][105] = {};
    visited[x1][y1] = true;

    while(!q.empty()){
        auto [x, y] = q.front().first;
        int step = q.front().second;
        q.pop();
        if(x == x2 && y == y2) return step;
        for(int dir = 0; dir < 4; ++dir){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            while(nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '.'){
                if (!visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, step + 1});
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<char>> v(n, vector<char>(n));
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                cin >> v[i][j];
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << bfs(x1, y1, x2, y2, v, n) << endl;
    }
}
