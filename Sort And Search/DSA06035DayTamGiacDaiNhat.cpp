#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        vector<int> Tang(n,1);// do dai day con tang tu trai sang tai i
        for(int i=1 ; i<n ; i++){
            if(a[i] > a[i-1]){
                Tang[i]=Tang[i-1]+1;
            }
        }
        vector<int> Giam(n,1);// do dai day con tang dan tu phai sang tai i
        for(int i=n-2 ; i>=0 ; i--){
            if(a[i] > a[i+1]){
                Giam[i]=Giam[i+1]+1;
            }
        }
        
        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans=max(ans,Tang[i]+Giam[i]-1);// nua trai + nua phai
        }
        cout << ans << endl;
    }
}