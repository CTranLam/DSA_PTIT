#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check=false;
void init(int a[],int n){
    for(int i=1 ; i<=n ; i++){
        a[i]=i;
    }
}
void sinh(int a[],int n){
    int i=n-1;
    while(i >=1 && a[i] > a[i+1]){
        --i;
    }
    if(i==0) check=true;
    else{
        int j=n;
        while(a[i] > a[j]){
            --j;
        }
        swap(a[i],a[j]);
        reverse(a+i+1,a+n+1);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        init(a,n);
        check=false;
        while(!check){
            for(int i=1 ; i<=n ; i++){
                cout << a[i];
            }
            cout <<" ";
            sinh(a,n);
        }
        cout << endl;
    }
}