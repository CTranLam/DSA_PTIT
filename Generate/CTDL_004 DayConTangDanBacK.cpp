#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void init(int a[],int n,int k){
    for(int i=1 ; i<=k ; i++){
        a[i]=i;
    }
}
bool check=false;
void sinh(int a[],int n,int k){
    int i=k;
    while(i >= 1 && a[i]==n-k+i){
        --i;
    }
    if(i==0) check=true;
    else{
        a[i]++;
        for(int j=i+1 ; j<=k ; j++){
            a[j]=a[j-1]+1;
        }
    }
}
bool solve(int b[],int a[],int k){
    for(int i=2 ; i<=k ; i++){
        if(a[b[i]] <= a[b[i-1]]) return false;
    }
    return true;
}
int main(){
    int n,k;
    cin >> n >> k;
    int a[n+5];
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    int b[n+5];
    init(b,n,k);
    int cntk=0;
    while(!check){
        if(solve(b,a,k)){
            ++cntk;
        }
        sinh(b,n,k);
    }
    cout << cntk <<endl;
}