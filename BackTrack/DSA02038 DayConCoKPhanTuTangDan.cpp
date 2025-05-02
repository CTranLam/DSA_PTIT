#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
int n,k;
void Try(int i,vector<int> v){
    if(v.size()==k){
        sort(v.begin(),v.end());
        for(int j=0 ; j<v.size(); j++){
            cout << v[j] << " ";
        }
        cout << endl;
        return;
    }
    for(int j=i ; j<n ; j++){
        v.push_back(a[j]);
        Try(j+1,v);
        v.pop_back();
    }
}
int main(){
    int t;cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        vector<int> v;
        Try(0,v);
    }
}