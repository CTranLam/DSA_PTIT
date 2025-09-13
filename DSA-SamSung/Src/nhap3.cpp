#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
typedef pair<int,int> pii;
ll a[maxn];
pii IT[4*maxn];
int n;
void Build(int node, int start,int end){
    if(start == end){
        IT[node] = {a[start],start};
    }
    else{
        int mid = (start + end)/2;
        Build(node*2 , start,mid);
        Build(node*2+1, mid + 1,end);
        IT[node] = min(IT[node*2],IT[node*2+1]);
    }
}
void Update(int node,int start, int end,int idx,int val){
    if(start == end){
        a[idx] += val;
        IT[node] = {val,idx};
    }
    else{
        int mid = (start + end)/2;
        if(idx >= start && idx <= mid){
            Update(node*2 , start, mid, idx, val);
        }
        else Update(node*2 + 1, mid+1, end, idx, val);
        IT[node] = min(IT[node*2],IT[node*2+1]);
    }
}
pii Query(int node,int start,int end,int l,int r){
    if(start > r || end < l) return {INT_MAX,INT_MAX};
    if(start >= l && end <= r) return IT[node];
    else{
        int mid = (start + end)/2;
        return min(Query(node*2,start,mid,l,r),Query(node*2+1,mid+1,end,l,r));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    Build(1,1,n);
    while(q--){
        int type; cin >> type;
        int u,v,val;
        if(type == 1){
            cin >> u >> val;
            Update(1,1,n,u,val);
        }
        else{
            cin >> u >> v;
            cout << Query(1,1,n,u,v).second << endl;
        }
    }
}
