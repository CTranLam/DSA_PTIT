#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
string s;
int m;
struct it{
    int open,close;
    int match;
};
it IT[4*maxn];
it merge(it left, it right){
    it res;
    int t = min(left.open,right.close);
    res.match = left.match + right.match + t;
    res.open = left.open + right.open - t;
    res.close = left.close + right.close - t;
    return res;
}
void build(int node,int start,int end){
    if(start == end){
        if(s[start-1] == '(') IT[node] = {1,0,0};
        else IT[node] = {0,1,0};
    }
    else{
        int mid = (start + end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        IT[node] = merge(IT[2*node],IT[2*node+1]);
    }
}
it query(int node,int start , int end , int l,int r){
    if(start > r || end < l) return {0,0,0};
    if(start >= l && end <= r) return IT[node];
    else{
        int mid = (start+end)/2;
        return merge(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> m;
    build(1,1,s.length());
    while(m--){
        int l,r;
        cin >> l >> r;
        it res = query(1,1,s.length(),l,r);
        cout << res.match*2 << endl;
    }
}