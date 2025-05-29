#include<bits/stdc++.h>
using namespace std;
struct job {
	int a, b, c;
};
bool cmp(job A, job B) {
	return A.c > B.c;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<job> v(n);
		bool used[100000]={false};
		for (int i = 0; i < n; i++)cin >> v[i].a >> v[i].b >> v[i].c;
		sort(v.begin(), v.end(), cmp);
        int pro=0,cnt=0;
        for(int i=0 ; i<n ; i++){
            // nhung cong viec co deadline dai thi uu tien hoan thanh sau
            // de nhung cong viec co deadline som hon hoan thanh truoc
            for(int j=v[i].b ; j>0 ; j--){
                if(!used[j]){
                    used[j]=true;
                    ++cnt;
                    pro+=v[i].c;
                    break;
                }
            }
        }
        cout << cnt <<" "<<pro << endl;
	}
}