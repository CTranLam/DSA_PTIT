#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[25];
vector<vector<int>> ans;
void Try(int i,int sum,vector<int> v){
    if(sum%2==1){
        sort(v.begin(),v.end(),greater<int>());
        ans.push_back(v);
    }
    for(int j=i ; j<n ; j++){
        sum+=a[j];
        v.push_back(a[j]);
        Try(j+1,sum,v);
        sum-=a[j];
        v.pop_back();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        vector<int> v;
        Try(0,0,v);
        sort(ans.begin(),ans.end());
        for(auto x : ans){
            for(int i : x){
                cout << i <<" ";
            }
            cout << endl;
        }
        cout << endl;
        ans.clear();
        
    }
}