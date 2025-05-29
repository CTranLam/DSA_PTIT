#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t ; cin >> t;
    while(t--){
        int n; cin >>n;
        queue<int> q;
        while(n--){
            int tt; cin >> tt;
            if(tt==1) cout << q.size() << endl;
            else if(tt==2){
                if(q.empty()) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else if(tt==3){
                int x; cin >> x;
                q.push(x);
            }
            else if(tt==4){
                if(!q.empty()) q.pop();
            }
            else if(tt==5){
                if(q.empty()) cout << -1 << endl;
                else cout << q.front() << endl;
            }
            else{
                if(q.empty()) cout << -1 << endl;
                else cout << q.back() << endl;
            }
        }
    }
}