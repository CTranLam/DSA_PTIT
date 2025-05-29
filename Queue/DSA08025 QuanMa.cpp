#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
bool visited[10][10];
void bfs(string s,string t){
    queue<pair<pair<int,int>,int>> q;
    q.push({{s[0]-'a',s[1]-'1'},0});
    visited[s[0]-'a'][s[1]-'1']=true;
    while(!q.empty()){
        int i=q.front().first.first; // ky tu
        int j=q.front().first.second; // so
        int step=q.front().second;
        q.pop();
        if(i==t[0]-'a' && j==t[1]-'1'){
            cout << step << endl;
            return;
        }
        for(int k=0 ; k<8 ; k++){
            int i1=i+dx[k];
            int j1=j+dy[k];
            if(i1 >= 0 && i1 <8 && j1 >= 0 && j1<8 && visited[i1][j1]==false){
                visited[i1][j1]=true;
                q.push({{i1,j1},step+1});
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string xy,uv;
        cin >> xy >> uv;
        memset(visited,false,sizeof(visited));
        bfs(xy,uv);
    }
}