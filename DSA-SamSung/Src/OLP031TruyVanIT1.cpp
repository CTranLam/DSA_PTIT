#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll IT[4*maxn],a[maxn];
void Build(int node,int start, int end){
    if(start == end){
        IT[node]=a[start];
    }
    else{
        int mid = (start+end)/2;
        Build(2*node,start,mid);
        Build(2*node + 1, mid + 1, end);
        IT[node] = IT[node*2] + IT[node*2+1];
    }
}
void update(int node,int start, int end, int idx, int val){
    if(start == end){
        a[idx]+=val;
        IT[node]+=val;
    }
    else{
        int mid = (start+end)/2;
        if(start <= idx && idx <= mid){
            update(2*node, start,mid,idx,val);
        }
        else{
            update(2*node+1,mid+1,end,idx,val);
        }
        IT[node]= IT[2*node] + IT[2*node+1];
    }
}
ll query(int node,int start,int end,int l, int r){
    if(r < start || l > end) return 0;
    if(l <= start && end <= r) return IT[node];
    else{
        ll mid = (start+end)/2;
        ll p1 = query(2*node,start,mid,l,r);
        ll p2 = query(2*node+1 , mid+1,end,l,r);
        return (p1+p2);
    }
}
int main(){
    int n; cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    Build(1,1,n);
    int q; cin >> q;
    while(q--){
        int type,u,v,k;
        cin >> type;
        if(type == 1){
            cin >> u >> k;
            update(1,1,n,u,k);
        }
        else{
            cin >> u >> v;
            cout << query(1,1,n,u,v) << endl;
        }
    }
}