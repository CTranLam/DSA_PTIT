#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int bfs(int xa,int ya,int xb,int yb,set<pair<int,int>> valid){
    map<pair<int,int>,int> mp; // check su dung
    queue<pair<int,int>> q;
    q.push({xa,ya});
    mp[{xa,ya}]=0;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        int dis=mp[{i,j}];
        if(i==xb && j==yb){
            return dis;
        }
        q.pop();
        for(int k=0 ; k<8 ; k++){
            int i1=i+dx[k];
            int j1=j+dy[k];
            if(valid.count({i1,j1}) && !mp.count({i1,j1})){
                mp[{i1,j1}]=dis+1;
                q.push({i1,j1});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int xa,ya,xb,yb;
        cin >> xa >> ya >> xb >> yb;
        int n; cin >> n;
        set<pair<int,int>> valid; // danh dau nhung o hop le tren duong vach
        while(n--){
            int x,y1,y2;
            cin >> x >> y1 >> y2;
            for(int i=y1 ; i<= y2 ; i++){
                valid.insert({x,i}); 
            }
        }
        cout << bfs(xa,ya,xb,yb,valid) << endl;
    }
}