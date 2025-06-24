#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> dsk[105],dsk_vh[105];
int degIN[105],degOut[105];
int visited[105];
int t,n,u;
vector<int> ans;
void dfs(int u){
    visited[u]=1;
    for(int v : dsk_vh[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
bool checkConnect(){
    dfs(1);
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
void Euler(int x){
    while(dsk[x].size()){
        int y=dsk[x].back();
        dsk[x].pop_back();
        auto it = find(dsk[y].begin(),dsk[y].end(),x);
        if(it != dsk[y].end()){
            dsk[y].erase(it);
        }
        Euler(y);
    }
    ans.push_back(x);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("CT.INP");
    ofstream cout("CT.OUT");
    cin >> t >> n;
    if(t==2){
        cin >> u;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            int x; cin >> x;
            if(x==1){
                dsk_vh[i].push_back(j);
                dsk_vh[j].push_back(i);

                dsk[i].push_back(j);

                degIN[j]++;
                degOut[i]++;
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        sort(dsk[i].begin(),dsk[i].end());
    }
    if(!checkConnect()){
        cout << 0 << endl;
        return 0;
    }
    if(t==1){
        int cnt=0;
        for(int i=1 ; i<=n ; i++){
            if(degIN[i] != degOut[i]){
                int x=abs(degIN[i]-degOut[i]);
                if(x >= 2){
                    cout << 0 << endl;
                    return 0;
                }
                else if(x==1){
                    ++cnt;
                }
            }
        }
        if(cnt==0) cout << 1 << endl;
        else if(cnt==2) cout << 2 << endl;
        else cout << 0 << endl;
    }
    else{
        if(dsk_vh[u].size()==0){
            cout << 0 << endl;
            return 0;
        }
        Euler(u);
        reverse(ans.begin(),ans.end());
        for(int x : ans){
            cout << x <<" ";
        }
        cout << endl;
    }
    cin.close();
    cout.close();
}