#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	queue<ll> q; q.push(1);
	vector<ll> v;
	while(true){
		ll x=q.front();
		q.pop();
		if(x > 1e18) break;
		v.push_back(x);
		q.push(x*10 + 0);
		q.push(x*10 + 1);
	}
	while(t--){
		ll n; cin >> n;
		int cnt=0;
		for(ll x : v){
			if(x <= n) ++cnt;
		}
		cout << cnt <<endl;
	}
}