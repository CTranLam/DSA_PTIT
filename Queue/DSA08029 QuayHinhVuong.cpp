#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
vec xoaytrai(vec a){
	vec b(6);
	b[2]=a[2];
	b[5]=a[5];
	b[0]=a[3];
	b[1]=a[0];
	b[4]=a[1];
	b[3]=a[4];
	return b;
}
vec xoayphai(vec a){
	vec b(6);
	b[0]=a[0];
	b[3]=a[3];
	b[1]=a[4];
	b[2]=a[1];
	b[5]=a[2];
	b[4]=a[5];
	return b;
}
int bfs(vec s,vec t){
    queue<pair<vec,int>> q;
    q.push({s,0});
    set<vec> se;
    se.insert(s);
    while(!q.empty()){
        vec tmp=q.front().first;
        int step=q.front().second;
        q.pop();
        if(tmp==t){
            return step;
        }
        vec a1=xoaytrai(tmp);
        if(!se.count(a1)){
            se.insert(a1);
            q.push({a1,step+1});
        }
        vec a2=xoayphai(tmp);
        if(!se.count(a2)){
            se.insert(a2);
            q.push({a2,step+1});
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
}