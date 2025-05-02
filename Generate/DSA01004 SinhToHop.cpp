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
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n+5];
        init(a,n,k);
        check=false;
        while(!check){
            for(int i=1 ; i<=k ; i++){
                cout << a[i];
            }
            cout <<" ";
            sinh(a,n,k);
        }
        cout << endl;
    }
}