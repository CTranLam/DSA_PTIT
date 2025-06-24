#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1005];
int color[1005];
bool solve(int start,int v){
    queue<int> q;
    q.push(start);
    color[start]=1;
    while(!q.empty()){
        int tmp=q.front(); q.pop();
        for(int x : ke[tmp]){
            if(color[x]==0){
                color[x]=3-color[tmp]; // to mau nguoc lai
                q.push(x);
            }
            else{
                if(color[x]==color[tmp]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; i++) {
            ke[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < e; i++) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }

        bool ok = true;
        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                if (!solve(i, v)) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
