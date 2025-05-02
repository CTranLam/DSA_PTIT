#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int x[25];
bool check=false;
void init(int len){
    for(int i=1 ; i<=len ; i++){
        x[i]=0;
    }
}
void sinh(int len){
    int i=len;
    while(i >= 1 && x[i]==1){
        x[i]=0;
        --i;
    }
    if(i==0) check=true;
    else x[i]=1;
}
int main(){
    cin >> n;
    int len=(n+1)/2;
    init(len);
    cout << endl;
    while(!check){
        for(int i=1 ; i<=len  ; i++){
            cout << x[i] <<" ";
        }
        for(int i=len-n%2 ; i>=1 ; i--){
            cout << x[i] <<" ";
        }
        cout << endl;
        sinh(len);
    }
}