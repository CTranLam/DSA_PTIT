#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
ll BIT[maxn];
void update(int u,int v){
    int idx = u;
    while(idx < maxn){
        BIT[idx] += v;
        idx += (idx&(-idx));
    }
}
ll getSum(int p){
    ll idx = p,sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -=(idx&(-idx));
    }
    return sum;
}
int main(){
    int n; cin >> n;
    int a[n+5],diff[n+5];
    a[0]=0;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    for(int i=1 ; i<=n ; i++){
        diff[i]=a[i]-a[i-1];
    }
    for(int i=1 ; i<=n ; i++){
        update(i,diff[i]);
    }
    int q ; cin >> q;
    while(q--){
        int type,u,v,k;
        cin >> type;
        if(type == 1){
            cin >> u >> v >> k;
            update(u,k);
            update(v+1,-k);
        }
        else{
            cin >> u;
            cout << getSum(u) << endl;
        }
    }
}