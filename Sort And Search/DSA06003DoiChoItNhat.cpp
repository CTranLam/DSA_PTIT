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
        for(int i= 0 ; i<n ; i++){
            cin >> a[i];
        }
        int cnt=0;
        for(int i=0 ; i<n-1 ; i++){
            int min_pos=i;
            for(int j=i+1 ; j<n ; j++){
                if(a[min_pos] > a[j]){
                    min_pos=j;
                }
            }
            if(min_pos != i){
                swap(a[min_pos],a[i]);
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}