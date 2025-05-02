#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m[10]={1,2,5,10,20,50,100,200,500,1000};
int solve(int n){
    int cnt=0;
    for(int i=9 ; i>=0 ; i--){
        if(n>=m[i]){
            cnt+=n/m[i];
            n-=(n/m[i])*m[i];
        }
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}