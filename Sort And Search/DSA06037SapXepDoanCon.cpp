#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        int Max[n];
        int Min[n];
        Max[0]=a[0];
        for(int i=1 ; i<n ; i++){
            Max[i]=max(Max[i-1],a[i]);
        }
        Min[n-1]=a[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            Min[i]=min(Min[i+1],a[i]);
        }
        vector<int> v;
        for(int i=0 ; i<=n-2 ; i++){
            if(Max[i] <= Min[i+1]){
                v.push_back(i+1);
            }
        }
        if(v.size()==0) cout << 0 << endl;
        else{
            cout << v.size() << endl;
            for(int x : v){
                cout << x << " ";
            }
            cout << endl;
        }
    }
}