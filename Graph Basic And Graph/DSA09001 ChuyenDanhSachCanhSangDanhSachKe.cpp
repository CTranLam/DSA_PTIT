#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int d,c;
        cin >> d >> c;
        vector<int> dsk[d+5];
        for(int i=0 ; i<c ; i++){
            int u,v;
            cin >> u >> v;
            dsk[u].push_back(v);
            dsk[v].push_back(u);
        }
        for(int i=1 ; i<=d ; i++){
            sort(dsk[i].begin(),dsk[i].end());
            cout << i <<": ";
            for(int x : dsk[i]){
                cout << x <<" ";
            }
            cout << endl;
        }
    }
}