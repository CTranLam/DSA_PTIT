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
        queue<ll> q;
        int n; cin >> n;
        q.push(9);
        bool check=false;
        while(!check){
            ll res=q.front();
            q.pop();
            if(res % n==0){
                cout << res << endl;
                check=true;
            }
            else{
                q.push(res*10 + 0);
                q.push(res*10 + 9);
            }
        }
    }
}