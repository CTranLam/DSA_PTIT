#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int search(int Ino[],int n,int x){
    for(int i=0 ; i<n ; i++){
        if(Ino[i]==x) return i;
    }
    return -1;
}
// xay dung cay nhi phan gia dinh
void Duyet(int Ino[],int Preo[],int n){
    // tim vi tri cua node goc
    int pos=search(Ino,n,Preo[0]);// preo[0] la node goc
    // kiem tra pos xem co cay ben trai va phai khong
    if(pos >0 ) Duyet(Ino,Preo+1,pos); // cay con trai co pos phan tu
    if(pos < n-1) Duyet(Ino+pos+1,Preo+pos+1,n-1-pos);// cay con phai co n-1-pos phan tu
    cout << Preo[0] <<" "; // in ra goc
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int Ino[n],Preo[n];
        for(int i=0 ; i<n ; i++) cin >> Ino[i];
        for(int i=0 ; i<n ; i++) cin >> Preo[i];
        Duyet(Ino,Preo,n);
        cout << endl;
    }
}