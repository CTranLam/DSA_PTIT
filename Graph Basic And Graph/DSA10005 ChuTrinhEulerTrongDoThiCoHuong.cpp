#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
vector<int> dsk_vh[10005];
int visited[10005];
int deg_in[10005];
int deg_out[10005];
void dfs(int u){
    visited[u]=1;
    for(int v : dsk_vh[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
// kiem tra lien thong yeu
bool check_lt(int v){
    int cnt=0;
    for(int i=1 ; i<=v ; i++){
        if(!visited[i]){
            ++cnt;
            dfs(i);
        }
    }
    if(cnt > 1) return false;
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int v,u; cin >> v >> u; // v dinh, u canh
        for(int i=1 ; i<=v ; i++){
            dsk_vh[i].clear();
            visited[i]=0;
            deg_in[i]=0;
            deg_out[i]=0;
        }
        for(int i=0 ; i<u ; i++){
            int x,y; cin >> x >> y;
            deg_in[y]++; 
            deg_out[x]++;
            dsk_vh[x].push_back(y);
            //dsk_vh[y].push_back(x);
        }
        dfs(v);
        int cnt=0;
        for(int i=1 ; i<=v ; i++){
            if(deg_out[i] != deg_in[i]) ++cnt;
        }
        if(!check_lt(v)){
            cout << 0 << endl;
        }
        else{
            if(cnt != 0) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
}