#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int s,n; cin >>s >> n ;
	int a[n];
	for(int i=0 ; i<n ; i++){
		cin >> a[i];
	}
	ll f[s+1]={0};
	f[0]=1; // tap rong
	for(int i=0 ; i<n ; i++){
		for(int j=s ; j>=a[i] ; j--){
			if(f[j-a[i]]==1){
				f[j]=1;
			}
		}
	}
	for(int i=s ; i>=0 ; i--){
		if(f[i]==1){
			cout << i << endl;
			return 0;
		}
	}
}
