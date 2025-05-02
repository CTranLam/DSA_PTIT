#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt=0;
int x[100],cot[100],xuoi[100],nguoc[100];
void Try(int i){
    if(i==n+1){
        ++cnt;
        return;
    }
    for(int j=1 ; j<=n ; j++){
        if(cot[j]==0 && xuoi[i-j+n]==0 && nguoc[i+j-1]==0){
            x[i]=j;
            cot[j]=1;
            xuoi[i-j+n]=1;nguoc[i+j-1]=1;
            Try(i+1);// hang i+1
            // luon quay lui 
            cot[j]=0;
            xuoi[i-j+n]=0;
            nguoc[i+j-1]=0;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(x,0,sizeof(x));
        memset(cot,0,sizeof(cot));
        memset(xuoi,0,sizeof(xuoi));
        memset(nguoc,0,sizeof(nguoc));
        cnt=0;
        Try(1);// bat dau tu hang 1
        cout << cnt << endl;
    }
}