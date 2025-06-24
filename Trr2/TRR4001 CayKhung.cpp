#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,s;
vector<int> dsk[105];
int visited[105];
vector<pair<int,int>> d,b;
void DFS(int u){
    visited[u]=1;
    for(int v : dsk[u]){
        if(!visited[v]){
            visited[v]=1;
            d.push_back({u,v});
            DFS(v);
        }
    }
}
void BFS(int u){
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : dsk[tmp]){
            if(!visited[v]){
                b.push_back({tmp,v});
                visited[v]=1;
                q.push(v);
            }
        }
    }
}
int main(){
    ifstream cin ("CK.INP");
    ofstream cout ("CK.OUT");
    cin >> t >> n >> s;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x==1){
                dsk[i].push_back(j);
            }
        }
    }
    if(t==1){
        DFS(s);
        cout << n-1 << endl;
        for(auto x : d){
            cout << min(x.first,x.second) <<" "<<max(x.first,x.second) << endl;
        }
    }
    else{
        BFS(s);
        cout << n-1 << endl;
        for(auto x : b){
             cout << min(x.first,x.second) <<" "<<max(x.first,x.second) << endl;
        }
    }
    cin.close();
    cout.close();
}