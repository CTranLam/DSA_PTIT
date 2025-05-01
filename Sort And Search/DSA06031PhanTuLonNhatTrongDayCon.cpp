#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0 ; i<n ; i++) cin >> a[i];
        multiset<int> se;
        for(int i=0 ; i<=k-2 ; i++) se.insert(a[i]);
        for(int i=k-1 ; i<n ; i++){
            se.insert(a[i]);
            cout << *se.rbegin() <<" ";
            auto it=se.find(a[i-(k-1)]);
            se.erase(it);
        }
        cout << endl;
    }
}