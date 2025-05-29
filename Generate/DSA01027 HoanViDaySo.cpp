#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void init(int a[],int n){
    for(int i=1 ; i<=n ; i++){
        a[i]=i;
    }
}
bool check=false;
void sinh(int a[],int n){
    int i=n-1;
    while( i>= 1 && a[i] > a[i+1]){
        --i;
    }
    if(i==0){
        check=true;
    }
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
    int n;
    cin >> n;
    int a[n+5],b[n+5];
    for(int i=1 ; i<=n ; i++){
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    init(a,n);
    while(!check){
        for(int i=1 ; i<=n ; i++){
            cout << b[a[i]] <<" ";
        }
        cout << endl;
        sinh(a,n);
    }
}