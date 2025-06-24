#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ke[1005];
int visited[1005];
void dfs(int u){
    visited[u]=1;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        // do thi n dinh va n-1 canh
        // chi can check lien thong, chu trinh duoc loai gian tiep
        int n; cin >> n;
        for(int i=1 ; i<=n ; i++){
            ke[i].clear();
            visited[i]=0;
        }
        for(int i=1 ; i<n ; i++){
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int cnt=0;
        for(int i=1 ; i<=n ; i++){
            if(!visited[i]){
                ++cnt;
                dfs(i);
            }
        }
        if(cnt > 1){
            cout <<"NO" << endl;
        }
        else cout << "YES" << endl;
    }
}