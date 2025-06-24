#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        set<int> se;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        if(se.size()==1){
            cout << -1 << endl;
        }
        else{
            cout << *se.begin() <<" ";
            se.erase(*se.begin());
            cout << *se.begin() << endl;
        }
    }
}