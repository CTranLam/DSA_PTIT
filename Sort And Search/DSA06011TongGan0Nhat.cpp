#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++) cin >> a[i];
        int ans=INT_MAX;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int sum=a[i]+a[j];
                if(abs(sum) < abs(ans)){
                    ans=sum;
                }
            }
        }
        cout << ans << endl;
    }
}