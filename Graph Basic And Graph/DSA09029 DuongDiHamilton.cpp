#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[15];
int visited[15];
bool check(int u,int cnt,int v){
    if(cnt==v){
        return true; // duyet du v dinh
    }
    for(int x : ke[u]){
        if(!visited[x]){
            visited[x]=1;
            if(check(x,cnt+1,v)) return true;
            visited[x]=0;
        }
    }
    return false;
}
bool duong_Di_Hamilton(int v){
    for(int i=1 ; i<=v ; i++){
        memset(visited,0,sizeof(visited));
        visited[i]=true;
        if(check(i,1,v)){
            return true;
        }
    }
    return false;
}
int main(){
    int t; cin >> t;
    while(t--){
        int v,e; cin >> v >> e;
        for(int i=1 ; i<=v ; i++){
            ke[i].clear();
            visited[i]=0;
        }
        for(int i=0 ; i<e ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        if(duong_Di_Hamilton(v)){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
}