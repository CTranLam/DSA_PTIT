#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        int sum=0;
        int max_sum=0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            sum+=a[i];
            if(sum < 0) sum=0;
            max_sum=max(max_sum,sum);
        }
        cout << max_sum << endl;
    }
}