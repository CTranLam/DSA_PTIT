#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int n,m;
int a[maxn];
struct it{
    int max1;
    int max2;
};
it IT[4*maxn];
it merge(it X1, it X2){
    vector<int> v = {X1.max1,X1.max2,X2.max1,X2.max2};
    sort(v.begin(),v.end(),greater<int>());
    return {v[0],v[1]};
}
void build(int node,int start,int end){
    if(start == end){
        IT[node]={a[start],INT_MIN}; // node la chi co 1 phan tu
    }
    else{
        int mid = (start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        IT[node] = merge(IT[node*2],IT[node*2+1]);
    }
}
void update(int node,int start,int end,int idx,int val){
    if(start == end){
        a[idx] =val;
        IT[node] = {val,INT_MIN};
    }
    else{
        int mid = (start+end)/2;
        if(idx >= start && idx <= mid){
            update(node*2, start,mid,idx,val);
        }
        else update(node*2+1,mid+1,end,idx,val);
        IT[node] = merge(IT[node*2],IT[node*2+1]);
    }
}
it query(int node,int start,int end,int l,int r){
    if(start > r || end < l) return {INT_MIN,INT_MIN};
    if(l <= start && end <= r) return IT[node];
    else{
        int mid = (start+end)/2;
        return merge(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
    }
}
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    build(1,1,n);
    for(int i=0 ; i<m ; i++){
        char type;
        int u,v,val;
        cin >> type;
        if(type == 'U'){
            cin >> u >> val;
            update(1,1,n,u,val);
        }
        else{
            cin >> u >> v;
            it res = query(1,1,n,u,v);
            cout << res.max1 + res.max2 << endl;
        }
    }
}