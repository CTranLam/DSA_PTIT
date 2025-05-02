#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int x[100][100],cot[100],xuoi[100],nguoc[100];
void Try(int i,int sum){
    if(i==9){
        ans=max(ans,sum);
    }
    for(int j=1 ; j<=8 ; j++){
        if(cot[j]==0 && xuoi[i-j+8]==0 && nguoc[i+j-1]==0){
            sum+=x[i][j];
            cot[j]=1;
            xuoi[i-j+8]=1;nguoc[i+j-1]=1;
            Try(i+1,sum);
            sum-=x[i][j];cot[j]=0;
            xuoi[i-j+8]=0;nguoc[i+j-1]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++){
        memset(x,0,sizeof(x));
        memset(cot,0,sizeof(cot));
        memset(xuoi,0,sizeof(xuoi));
        memset(nguoc,0,sizeof(nguoc));
        ans=INT_MIN;
        for(int p=1 ; p<= 8 ; p++){
            for(int q=1 ; q<=8 ; q++){
                cin >> x[p][q];
            }
        }
        Try(1,0);// bat dau tu hang 1
        cout <<ans << endl;
    }
}