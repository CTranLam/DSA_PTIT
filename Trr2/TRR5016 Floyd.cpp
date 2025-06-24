#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105][105],nxt[105][105];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			cin >> a[i][j];
			if(i==j) a[i][j]=10000;
			if(a[i][j] != 10000){
				nxt[i][j]=j;
			}
		}
	}
	for(int k=1 ; k<=n ; k++){
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				if(a[i][j] > a[i][k] + a[k][j]){
					a[i][j]=a[i][k]+a[k][j];
					nxt[i][j]=nxt[i][k];
				}
			}
		}
	}
	int p,q,res=INT_MIN;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(a[i][j] != 10000 && a[i][j] > res){
				res=a[i][j];
				p=i,q=j;
			}
		}
	}
	if(res==INT_MIN){
		cout << 0 << endl;
	}
	else{
		cout << p <<" "<<q <<" "<<res << endl;
		vector<int> ans;
		int tmp=p;
		while(true){
			ans.push_back(tmp);
			if(tmp == q) break;
			tmp=nxt[tmp][q];
		}
		for(int x : ans){
			cout << x <<" ";
		}
	}
}