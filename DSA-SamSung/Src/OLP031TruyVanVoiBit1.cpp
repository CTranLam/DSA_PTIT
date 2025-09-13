#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
ll BIT[maxn];
void update(int u,int v){
    int idx = u;
    while(idx < maxn){
        BIT[idx]+=v;
        idx += (idx&(-idx));
    }
}
// tong tu 1->p
ll getSum(int p){
    ll idx = p, sum =0;
    while(idx > 0){
        sum+=BIT[idx];
        idx -=(idx & (-idx));
    }
    return sum;
}
int main(){
    int n; cin >> n;
    int a[n+5];
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    for(int i=1 ; i<=n ; i++){
        update(i,a[i]);
    }
    int q ; cin >> q;
    while(q--){
        int type,u,v,k;
        cin >> type;
        if(type == 1){
            cin >> u >> k;
            update(u,k);
        }
        else{
            cin >> u >> v;
            cout << getSum(v)-getSum(u-1) << endl;
        }
    }
}