#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,s;
int cnt;
void Try(int st,int sum,int dem){
    if(dem==k){
        if(sum==s){
            ++cnt;
            return;
        }
    }
    else if(dem < k){
        for(int i=st ; i<=n ; i++){
            Try(i+1,sum+i,dem+1);
        }
    }
}
int main(){
    while(true){
        cin >> n >> k >> s;
        if(n==0 && k==0 && s==0){
            break;
        }
        cnt=0;
        Try(1,0,0);
        cout << cnt << endl;
    }
}