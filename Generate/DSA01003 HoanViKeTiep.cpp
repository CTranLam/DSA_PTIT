#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check=false;
void sinh(int a[],int n){
    int i=n-1;
    while(i >= 1 && a[i] > a[i+1]){
        --i;
    }
    if(i==0) check=true;
    else{
        int j=n;
        while(a[i] > a[j]){
            --j;// tim thang dau tien > a[i]
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
        int a[n+5];
        for(int i=1 ; i<=n ; i++){
            cin >> a[i];
        }
        sinh(a,n);
        if(!check){
            for(int i=1 ; i<=n ; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else{
            for(int i=1 ; i<=n ; i++){
                cout << i <<" ";
            }
            cout << endl;
            check=false;
        }
    }
}