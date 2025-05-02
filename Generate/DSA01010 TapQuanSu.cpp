#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[k+5];
        set<int> se;
        for(int i=1 ; i<=k ; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        int i=k;
        while(i >= 1 && a[i]==n-k+i){
            --i;
        }
        if(i==0){
            cout << k << endl;
        }
        else{
            a[i]++;
            for(int j=i+1 ; j<n ; j++){
                a[j]=a[j-1]+1;
            }
            int cnt=0;
            for(int i=1 ; i<=k ; i++){
                if(se.count(a[i])==0) ++cnt;
            }
            cout << cnt << endl;
        }
    }
}