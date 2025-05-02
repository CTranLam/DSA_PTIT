#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void init(int b[],int n,int k){
    for(int i=1 ; i<=k ; i++){
        b[i]=i;
    }
}
bool check=false;
void sinh(int b[],int n,int k){
    int i=k;
    while(i >= 1 && b[i] == n-k+i){
        --i;
    }
    if(i==0) check=true;
    else{
        b[i]++;
        for(int j=i+1 ; j<=k ; j++){
            b[j]=b[j-1]+1;
        }
    }
}
int main(){
    int n,k;cin >> n >> k;
    set<int> se;
    for(int i=0 ; i<n ; i++){
        int x;cin >> x;
        se.insert(x);
    }
    int a[n+5],i=0;
    for(int x : se){
        a[i]=x;
        ++i;
    }
    n=se.size();
    int b[n+5];
    init(b,n,k);
    while(!check ){
        for(int i=1 ; i<=k ; i++){
            cout << a[b[i]-1] <<" ";
        }
        cout << endl;
        sinh(b,n,k);
    }
}