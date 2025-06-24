#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ul;
int a[105][105];
vector<int> dsk[105];
vector<vector<int>> ans;
int visited[105];
int min_value=INT_MAX;
void Hamilton(int u,int sum, vector<int>& res){
    for(int v : dsk[u]){
        if(!visited[v]){
            visited[v]=1;
            res.push_back(v);
            sum+=a[u][v];
            Hamilton(v,sum,res);
            sum-=a[u][v];
            visited[v]=0;
            res.pop_back();
        }
        else if(v==ul && res.size() == n){
            sum+=a[u][v];
            res.push_back(v);
            if(min_value > sum){
                ans.clear();
                ans.push_back(res);
                min_value=sum;
            }
            sum-=a[u][v];
            res.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> ul;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 10000){
                dsk[i].push_back(j);
            }
        }
    }
    vector<int> res;
    res.push_back(ul);
    visited[ul]=1;
    Hamilton(ul,0,res);
    if(ans.size() > 0){
        cout << min_value << endl;
        for(auto v : ans){
            for(int x : v) cout << x << " ";
            cout << endl;
        }
    }
    else cout << 0 << endl;
}