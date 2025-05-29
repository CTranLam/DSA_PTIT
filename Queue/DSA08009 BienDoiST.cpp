#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(int s,int t,int step){
    queue<pair<int,int>> q;
    q.push({s,0});
    set<int> se;
    se.insert(s);
    while(!q.empty()){
        int tmp=q.front().first;
        int stp=q.front().second;
        q.pop();
        if(tmp==t){
            cout << stp << endl;
            return;
        }
        if(tmp*2 < t*2 && se.count(tmp*2)==0){
            q.push({tmp*2,stp+1});
            se.insert(tmp*2);
        }
        if(tmp-1 > 0 && se.count(tmp-1) ==0){
            q.push({tmp-1,stp+1});
            se.insert(tmp-1);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int s,t; cin >> s >> t;
        bfs(s,t,0);
    }
}