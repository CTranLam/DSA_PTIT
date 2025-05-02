#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check=false;
void init(int a[],int n){
    for(int i=1 ; i<=n ; i++){
        a[i]=0;
    }
}
void sinh(int a[],int n){
    int i=n;
    while(i >= 1 && a[i]==1){
        a[i]=0;
        --i;
    }
    if(i==0) check=true;
    else a[i]=1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n+5];
        init(a,n);
        check=false;
        while(!check){
            for(int i=1 ; i<=n ; i++){
                if(a[i]==1) cout << 'B';
                else cout << 'A';
            }
            cout <<" ";
            sinh(a,n);
        }
        cout << endl;
    }
}