#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> ans;
void Try(int i,int sum,vector<int> v){
    if(sum==n){
        sort(v.begin(),v.end(),greater<int>());
        ans.push_back(v);
        return;
    }
    if(sum > n) return;
    for(int j=i ; j<=n ; j++){
        v.push_back(j);
        sum+=j;
        Try(j,sum,v);
        sum-=j;
        v.pop_back();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v;
        Try(1,0,v);
        cout << ans.size() << endl;
        sort(ans.begin(),ans.end(),greater<vector<int>>());
        for(auto x : ans){
            cout <<"(";
            for(int i=0 ; i<x.size()-1 ; i++){
                cout << x[i] <<" ";
            }
            cout <<x.back() <<")";
            cout <<" ";
        }
        cout << endl;
        ans.clear();
    }
}