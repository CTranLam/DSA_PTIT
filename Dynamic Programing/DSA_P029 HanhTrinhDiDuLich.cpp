#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100][100];
int x[100]; // x[i] luu so thu tu thanh pho nguoi do den
int ans=INT_MAX,cmin=INT_MAX;
int cur_sum=0;
int used[100];
void nhap(){
    memset(a,0,sizeof(a));
    memset(used,0,sizeof(used));
    memset(x,0,sizeof(x));
    ans = INT_MAX;
    cmin = INT_MAX;
    cur_sum = 0;

	cin >> n;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			cin >> a[i][j];
			if(a[i][j] != 0) cmin=min(cmin,a[i][j]);
		}
	}
}
void Try(int i){
	for(int j=1 ; j<=n ; j++){
		if(used[j]==0){
			used[j]=1;
			x[i]=j; // danh dau lai vi tri thanh pho
			cur_sum+=a[x[i]][x[i-1]];
			if(i==n-1){
				ans=min(ans,cur_sum);
			}
			else if(cur_sum+(n-i+1)*cmin < ans){ // nho hon ki luc thi tim kiem ket qua tot hon
				Try(i+1);
			}
			used[j]=0;
			cur_sum-=a[x[i]][x[i-1]];
		}
	}
}
int main(){
    int t;
    cin >> t;
    while(t--){
        // khong tinh duong ve
        nhap();
        x[1]=1;
        used[1]=1;
        Try(2);
        cout << ans << endl;
    }
}
