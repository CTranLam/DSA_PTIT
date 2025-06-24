#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
set<int> dsk[105];
vector<pair<int,int>> dsc;
int visited[105];
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int v : dsk[tmp]){
            if(!visited[v]){
                visited[v]=1;
                q.push(v);
            }
        }
    }
}
int tplt(){
    int cnt=0;
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            ++cnt;
            BFS(i);
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("TK.INP");
    ofstream cout("TK.OUT");
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x==1){
                dsk[i].insert(j);
                if(i<j){
                    dsc.push_back({i,j});
                }
            }
        }
    }
    int cnt=tplt();
    set<pair<int,int>> se;
    for(auto it : dsc){
        int x=it.first,y=it.second;
        memset(visited,0,sizeof(visited));
        dsk[x].erase(y);
        dsk[y].erase(x);
        if(tplt() > cnt){
            se.insert({x,y});
        }
        dsk[x].insert(y);
        dsk[y].insert(x);
    }
    cout << se.size() << endl;
    for(auto x : se){
        cout << x.first <<" "<<x.second << endl;
    }
    cin.close();
    cout.close();
}