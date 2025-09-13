#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
char a[1005][1005];
int step[1005][1005];
int result;
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
void bfs(){
    deque<pair<int,int>> dq;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(a[i][j]=='*'){
                step[i][j]=0;
                dq.push_back({i,j});
            }
        }
    }
    while(!dq.empty()){
        int i = dq.front().first;
        int j = dq.front().second;
        dq.pop_front();
        for(int k = 0 ;k < 4; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >=1 && i1<=n && j1>=1 && j1<=m){
                int w = (a[i1][j1] != a[i][j]);
                if(step[i1][j1] > step[i][j] + w){
                    step[i1][j1] = step[i][j] + w;
                    if(w==0) dq.push_front({i1,j1});
                    else dq.push_back({i1,j1});
                }
            }
        }
    }
}
int main(){
    cin >> n >> m >> q;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin >> a[i][j];
            step[i][j] = INT_MAX;
        }
    }
    bfs();
    while(q--){
        int x,y ; cin >> x >> y;
        result = 0;
        cout << step[x][y] << endl;
    }
}