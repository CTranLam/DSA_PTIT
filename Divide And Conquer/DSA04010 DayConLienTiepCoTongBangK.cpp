#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		int max_sum=0,sum=0;
		for(int i=0 ; i<n ; i++){
			sum+=a[i];
			max_sum=max(max_sum,sum);
			if(sum < 0) sum=0;
		}
		cout << max_sum << endl;
	}
}