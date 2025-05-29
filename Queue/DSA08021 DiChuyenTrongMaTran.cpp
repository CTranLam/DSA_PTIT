#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int a[n+5][m+5];
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin >> a[i][j];
            }
        }
        vector<vector<bool>> visited (n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        int cnt=-1;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dem=q.front().second;
            q.pop();
            if(x==n-1 && y==m-1){
                cnt=dem;
                break;
            }
            if(x+a[x][y] < n && !visited[x+a[x][y]][y]){
                q.push({{x+a[x][y],y},dem+1});
                visited[x+a[x][y]][y]=true;
            }
            if(y+a[x][y] <m && !visited[x][y+a[x][y]]){
                q.push({{x,y+a[x][y]},dem+1});
                visited[x][y+a[x][y]]=true;
            }
        }
        cout << cnt << endl;
    }
}