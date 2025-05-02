#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> n >> m;
        int cnt[10000];
        memset(cnt,0,sizeof(cnt));
        int p[n];
        for(int i=0 ; i<n ; i++) cin >> p[i];
        int q[m];
        for(int j=0 ; j<m ; j++) cin >> q[j];
        int max_pos=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cnt[i+j]+=p[i]*q[j];
                max_pos=max(max_pos,i+j);
            }
        }
        for(int i=0 ; i<= max_pos ; i++){
            cout << cnt[i] <<" ";
        }
        cout << endl;
    }
}