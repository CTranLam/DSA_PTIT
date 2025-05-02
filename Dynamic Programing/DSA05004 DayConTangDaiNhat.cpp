#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    int f[n]; //do dai day con tang dan den vi tri thu i
    for(int i=0 ; i<n ; i++){
        f[i] = 1;
        for(int j=0 ; j<i ; j++){
            if(a[i] > a[j]){
                f[i]=max(f[i],f[j]+1);
            } 
        }
    }
    cout << *max_element(f,f+n) << endl;
}