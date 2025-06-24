#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,m;
int visited[200005];
vector<iii> ke[200005];
int a[505][505],d[505][505];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void dijkstra(int i,int j){
    d[i][j]=a[i][j]; // chi phi den cac dinh
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    pq.push({a[i][j],{i,j}});
    while(!pq.empty()){
        iii tmp=pq.top();
        pq.pop();
        int u=tmp.second.first,v=tmp.second.second;
        int dis=tmp.first;
        if(dis > d[u][v]){
            continue;
        }
        else{
            d[u][v]=dis;
            for(int k=0 ; k<4 ; k++){
                int u1=u+dx[k],v1=v+dy[k];
                if(u1 >=1 && u1<=n && v1>=1 && v1<=m){
                    if(d[u1][v1] > d[u][v] + a[u1][v1]){
                        d[u1][v1]=d[u][v] + a[u1][v1];
                        pq.push({d[u1][v1],{u1,v1}});
                    }
                }
            }
        }
    }
    cout << d[n][m] << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1; i<=n ; i++){
            visited[i]=0;
            ke[i].clear();
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cin >> a[i][j];
                d[i][j]=1e9;
            }
        }
        dijkstra(1,1);
    }
}