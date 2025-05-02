#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005],b[1005];
int n;
bool solve(){
    bool check=false;
    for(int i=1 ; i<n ; i++){
        if(a[i-1]/b[i-1] != a[i]/b[i]){
            check=1;// can thay doi tiep
            while(a[i-1]/b[i-1] != a[i]/b[i]){
                if(a[i-1]/b[i-1] > a[i]/b[i]){
                    b[i-1]++;
                }
                else{
                    b[i]++;
                }
            }
        }
    }
    return check;
}
int main(){
    cin >> n;
    int min_n=INT_MAX,max_n=INT_MIN;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        b[i]=1;
    }
    while(solve());
    int ans=0;
    for(int x : b){
        ans+=x;
    }
    cout << ans << endl;
}