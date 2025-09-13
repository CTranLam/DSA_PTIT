#include <bits/stdc++.h>
using namespace std;

bool blocked(int ax, int ay, int bx, int by, int x1, int y1, int x2, int y2){
    // Hàng rào đứng
    if(x1 == x2){
        int x = x1;
        if((ax < x && bx > x) || (ax > x && bx < x)){
            int ylow = min(y1,y2), yhigh = max(y1,y2);
            if(ay >= ylow && ay <= yhigh && by >= ylow && by <= yhigh) return true;
        }
    }
    // Hàng rào ngang
    else if(y1 == y2){
        int y = y1;
        if((ay < y && by > y) || (ay > y && by < y)){
            int xlow = min(x1,x2), xhigh = max(x1,x2);
            if(ax >= xlow && ax <= xhigh && bx >= xlow && bx <= xhigh) return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<tuple<int,int,int,int>> fences(N);
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fences[i] = make_tuple(x1,y1,x2,y2);
    }

    vector<pair<int,int>> cows(M);
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        cows[i] = {x,y};
    }

    // Tạo đồ thị: bò i kết nối bò j nếu không có hàng rào chắn
    vector<vector<int>> adj(M);
    for(int i=0;i<M;i++){
        for(int j=i+1;j<M;j++){
            bool blocked_flag = false;
            for(int f=0; f<N; f++){
                int x1,y1,x2,y2;
                tie(x1,y1,x2,y2) = fences[f];
                if(blocked(cows[i].first, cows[i].second, cows[j].first, cows[j].second, x1,y1,x2,y2)){
                    blocked_flag = true;
                    break;
                }
            }
            if(!blocked_flag){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // BFS phân vùng
    vector<bool> visited(M,false);
    int maxCows = 0;
    for(int i=0;i<M;i++){
        if(!visited[i]){
            int cnt = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int u = q.front(); q.pop();
                cnt++;
                for(int v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            maxCows = max(maxCows, cnt);
        }
    }

    cout << maxCows << "\n";
    return 0;
}
