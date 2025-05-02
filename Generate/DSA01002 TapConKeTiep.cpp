#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check=false;
void Sinh(int a[],int n,int k){
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
        for(int i=1 ; i<=k ; i++){
            cin >> a[i];
        }
        Sinh(a,n,k);
        if(!check){
            for(int i=1 ; i<=k ; i++){
                cout << a[i] <<" ";
            }
            cout << endl;
        }
        else{
            for(int i=1 ; i<=k ; i++){
                cout << i <<" ";
            }
            cout << endl;
            check=false;
        }
    }
}