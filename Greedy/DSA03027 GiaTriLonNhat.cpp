#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    // do neu cong thi 2 mang doi xung nhau nen am duong tu triet tieu
    ll res=0;
    for(int i=0 ; i<n ; i++){
        if(a[i] > 0){
            res+=(ll)a[i]*2;
        }
    }
    cout << res << endl;
}