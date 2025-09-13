#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+5,0);
    vector<ll> prefix(n+5,0);
    for(int i=1 ; i <=n; i++){
        cin >> a[i];
        prefix[i] = prefix[i-1]+a[i];
    }

    vector<ll> minElement(n+5,1e18);
    minElement[n] = a[n];
    for(int i = n-1; i >= 1; i--) {
        minElement[i] = min(a[i], minElement[i+1]);
    }
    vector<int> ans;
    double maxAvg=0;
    for(int k=1 ; k<=n-2 ; k++){
        // mat k bai dau
        ll total = prefix[n]-prefix[k];
        ll minn = minElement[k+1];
        ll lenn = n-k;

        // mat 1 bai diem thap nhat 
        ll num = total - minn;
        ll sizeNum = lenn -1;

        if((double)num/sizeNum == maxAvg){
            ans.push_back(k);
        }
        else if((double)num/sizeNum > maxAvg){
            ans.clear();
            ans.push_back(k);
            maxAvg = (double)num/sizeNum;
        }
        else{
            continue;
        }
    }
    for(int x : ans){
        cout << x <<" ";
    }
    cout << endl;
}