#include<bits/stdc++.h>
using namespace std;
string chuyen(int k, int n) {
	string res = "";
	while (n) {
		res = to_string(n % k)+res;
		n /= k;
	}
	return res;
}
int chuyen1(int k, string n) {
	int mu=pow(k,n.size()-1);
	int res = 0;
	for (int i = 0; i < n.length(); i++) {
		res += (n[i]-'0')*mu;
		mu=pow(k,n.size()-2-i);
	}
	return res;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		string a, b; cin >> a >> b;
		int x = chuyen1(k,a);
		int y = chuyen1(k,b);
		int res = x + y;
		cout << chuyen(k, res) << endl;
	}
}