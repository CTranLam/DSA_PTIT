#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
vec xoayTrai(vec s){
    vec tmp(6);
    tmp[0]=s[3];
    tmp[1]=s[0];
    tmp[2]=s[2];
    tmp[3]=s[4];
    tmp[4]=s[1];
    tmp[5]=s[5];
    return tmp;
}
vec xoayPhai(vec s){
    vec tmp(6);
    tmp[0] = s[0];
    tmp[1] = s[4];
    tmp[2] = s[1];
    tmp[3] = s[3];
    tmp[4] = s[5];
    tmp[5] = s[2];
    return tmp;
}
int bfs(vec s, vec t){
    queue<pair<vec,int>> q;
    q.push({s,0});
    set<vec> se;
    se.insert(s);
    while(!q.empty()){
        vec tmp = q.front().first;
        int step = q.front().second;
        q.pop();
        if(tmp == t){
            return step;
        }
        vec left = xoayTrai(tmp);
        if(!se.count(left)){
            se.insert(left);
            q.push({left,step+1});
        }
        vec right = xoayPhai(tmp);
        if(!se.count(right)){
            se.insert(right);
            q.push({right,step+1});
        }
    }
    return -1;
}
int main(){
    vector<int> s(6);
    vector<int> t(6);
    for(int i=0 ; i<6 ; i++){
        cin >> s[i];
    }
    for(int i=0 ; i<6 ; i++){
        cin >> t[i];
    }
    cout << bfs(s,t) << endl;
}