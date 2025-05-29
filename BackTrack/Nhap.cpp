#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[100];
vector<vector<int>> ans;
void Try(int i,vector<int> v){
    if(v.size()==k){
        sort(v.begin(),v.end());
        ans.push_back(v);
        return;
    }
    for(int j=i ; j<n ; j++){
        v.push_back(a[j]);
        Try(j+1,v);
        v.pop_back();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        vector<int> v;
        Try(0,v);
        for(auto v : ans){
            for(int x : v){
                cout << x <<" ";
            }
            cout << endl;
        }
        ans.clear();
    }
}