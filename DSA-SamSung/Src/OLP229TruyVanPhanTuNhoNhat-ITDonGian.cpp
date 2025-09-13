#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200005;
typedef pair<int,int> pii;
int n,m;
int a[maxn];
pii IT[4*maxn];
void build(int node,int start,int end){
    if(start == end){
        IT[node]={a[start],start};
    }
    else{
        int mid = (start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        IT[node]=min(IT[2*node],IT[2*node+1]);
    }
}
void update(int node,int start,int end,int idx,int val){
    if(start == end){
        a[idx] = val;
        IT[node] = {val,idx};
    }
    else{
        int mid = (start+end)/2;
        if(start <= idx && idx <= mid){
            update(node*2,start,mid,idx,val);
        }
        else{
            update(node*2+1,mid+1,end,idx,val);
        }
        IT[node] = min(IT[node*2],IT[node*2+1]);
    }
}
pii query(int node,int start,int end,int l,int r){
    if(l > end || r < start) return{INT_MAX,INT_MAX};
    if(l <= start && end <= r) return IT[node];
    else{
        int mid = (start+end)/2;
        return min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
    }
}
int main(){
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    build(1,1,n);
    while(m--){
        int type,u,v,val;
        cin >> type;
        if(type == 1){
            cin >> u >> val;
            update(1,1,n,u,val);
        }
        else{
            cin >> u >> v;
            cout << query(1,1,n,u,v).second << endl;
        }
    }
}