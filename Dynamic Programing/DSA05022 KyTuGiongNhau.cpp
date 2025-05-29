#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, x, y, z; 
        cin >> n >> x >> y >> z;
        // x: insert, y: delete, z: nhan doi
		int dp[1000]={0}; //thoi gian toi thieu de tao ra i ky tu
		dp[1]=x; 
		for (int i = 2; i <= n; i++) {
			if(i%2==0){
                // neu i la so chan
                dp[i]=min(dp[i-1]+x , dp[i/2] + z);
            }
            else{
                dp[i]=min(dp[i-1]+x , dp[(i+1)/2] + z + y); //nhan doi nen thua 1
            }
		}
		cout << dp[n] << endl;
	};
}