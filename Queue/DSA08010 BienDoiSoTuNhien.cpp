#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bfs(int n){
    queue<pair<int,int>> q;
    set<int> se;
    q.push({n,0});
    se.insert(n);
    while(!q.empty()){
        int x=q.front().first;
        int step=q.front().second;
        q.pop();
        if(x==1){
            return step;
        }
        if(x-1 > 0 && !se.count(x-1)){
            se.insert(x-1);
            q.push({x-1,step+1});
        }
        for(int i=2 ; i<=sqrt(x) ;i++){
            if(x%i==0 && se.count(max(i,x/i))==0){
                q.push({max(x/i,i),step+1});
                se.insert(max(i,x/i));
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << bfs(n) << endl;
    }
}