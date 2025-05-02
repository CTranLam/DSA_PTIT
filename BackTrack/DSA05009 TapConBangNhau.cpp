#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105];
int tar;
bool check=false;
void Try(int i,int sum){
    if(sum==tar && !check){
        cout <<"YES" << endl;
        check=true;
        return;
    }
    if(check || sum > tar) return;
    for(int j=i ; j<n ; j++){
        sum+=a[j];
        Try(j+1,sum);
        sum-=a[j];
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(a,0,sizeof(a));
        tar=0;
        check=false;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            tar+=a[i];
        }
        if(tar % 2==1) cout << "NO" << endl;
        else{
            tar/=2;
            Try(0,0);
            if(!check) cout << "NO" << endl;
        }
    }
}