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
        ll n; cin >> n;
        queue<ll> q;
        q.push(1);
        while(true){
            ll x=q.front();
            q.pop();
            if(x%n==0){
                cout << x << endl;
                break;
            }
            q.push(x*10 + 0);
            q.push(x*10 + 1);
        }
    }
}