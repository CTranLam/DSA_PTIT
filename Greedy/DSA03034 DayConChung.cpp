#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int a[n],b[m],c[k];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<m ; i++){
            cin >> b[i];
        }
        for(int i=0 ; i<k ; i++){
            cin >> c[i];
        }
        int l1=0,l2=0,l3=0;
        vector<int> v;
        while(l1 < n && l2 < m && l3 < k){
            if(a[l1]==b[l2] && b[l2]==c[l3]){
                v.push_back(a[l1]);
                ++l1;++l2;++l3;
            }
            else if(a[l1] < b[l2]){
                ++l1;
            }
            else if(b[l2] < c[l3]){
                ++l2;
            }
            else ++l3;
        }
        if(v.size()==0){
            cout << "NO" << endl;
        }
        else{
            for(int x : v){
                cout << x <<" ";
            }
            cout << endl;
        }
    }
}