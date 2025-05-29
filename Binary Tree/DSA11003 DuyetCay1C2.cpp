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
    int L[10001], R[10001], l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (search(Ino, n, Preo[i]) < pos) L[l++] = Preo[i];
        else R[r++] = Preo[i];
    }
    if (l > 0) Duyet(Ino, L, l);
    if (r > 0) Duyet(Ino + pos + 1, R, r);
    cout << Preo[0] <<" ";
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