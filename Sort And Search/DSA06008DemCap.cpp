#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
map<int,int> mp;
int n,m;
int solve(int b[],int x){
    if(x==0) return 0;
    if(x==1) return mp[0];
    int cnt=m-(upper_bound(b,b+m,x)-b);
    cnt+=mp[0]+mp[1]; // luon lon hon
    if(x==2) cnt-=(mp[3]+mp[4]);
    if(x==3) cnt+=mp[2];
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int a[n],b[m];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<m ;i++){
            cin >> b[i];
            mp[b[i]]++;
        }
        sort(b,b+m);
        ll ans=0;
        for(int i=0 ; i<n ; i++){
            ans+=solve(b,a[i]);
        }
        cout << ans << endl;
        mp.clear();
    }
}