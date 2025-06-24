#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[10005];// f[i] luu so luong binh phuong min de tao ra i
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1 ; i<=n ; i++){
            f[i]=i;// TH te nhat la tong cua i so 1^2
            for(int j=1 ; j<=sqrt(i) ; j++){
                // giong cac bai coin 
                // vd f[101]=f[101-1*1]+1 || f[101-2*2]+1
                f[i]=min(f[i],f[i-j*j]+1);
            }
        }
        cout << f[n] << endl;
    }
}